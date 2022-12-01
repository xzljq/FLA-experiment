#include "parser.h"


vector<string> Q;//状态集
vector<char> S;//输入符号集
vector<char> G;//纸带符号集
string q0;//初始状态
char B;//空格符号
vector<string> F;//终结状态集
int N;//纸带数
vector<transfer> delta;//

extern bool arg_v;

void parser(string tm)
{
    if(tm=="")
	{ 
        cerr<<"syntax error"<<endl;
		if(arg_v) cerr<<"turing machine program's name error"<<endl;
		exit(1);
	}

    ifstream ifs;
    ifs.open("../turing-project/"+tm, ios::in);
    if (!ifs.is_open())
    {
        cerr << "TM file open failed" << endl;
        exit(2);
    }

    string buf;
	while (getline(ifs, buf))
	{
        remove_comment(buf);
        //cout<<buf<<endl;
        if(buf=="")
        {
            continue;
        }
        else if(buf[0]=='#'&&buf[1]=='Q')
        {
            Q_parse(buf);
        }
        else if(buf[0]=='#'&&buf[1]=='S')
        {
            S_parse(buf);
        }
        else if(buf[0]=='#'&&buf[1]=='G')
        {
            G_parse(buf);
        }
        else if(buf[0]=='#'&&buf[1]=='q'&&buf[2]=='0')
        {
            buf.erase(0,5);
            q0=buf;
        }
        else if(buf[0]=='#'&&buf[1]=='B')
        {
            buf.erase(0,5);
            B=buf[0];
            if(B!='_')
            {
                cerr<<"syntax error"<<endl;
                if(arg_v)cerr<<"BLANK symbol is not _"<<endl;
                exit(3);
            }
            if(find(G.begin(),G.end(),B)==G.end())
            {
                cerr<<"syntax error"<<endl;
                if(arg_v)cerr<<"B is not in G"<<endl;
                exit(5);
            }
        }
        else if(buf[0]=='#'&&buf[1]=='F')
        {
            F_parse(buf);
        }
        else if(buf[0]=='#'&&buf[1]=='N')
        {
            buf.erase(0,5);
            N=atoi(buf.c_str());
            //cout<<"N:"<<N<<endl;
        }
        else if(count(buf.begin(),buf.end(),' ')==4)
        {
            //cout<<buf<<endl;
            delta_parse(buf);
        }
        else
        {
            cerr<<"syntax error"<<endl;
            if(arg_v) cerr<<"TM program uncorrect format"<<endl;
            exit(6);
        }
	}

    ifs.close();
}

void remove_comment(string& buf)
{
    regex regexStr("(\\s)*(;(.*))?$");
    buf=regex_replace(buf, regexStr, "");
}

void Q_parse(string buf)
{
    buf.erase(0,5);
    regex regexStr("(\\w+)");
    auto words_begin = sregex_iterator(buf.begin(), buf.end(), regexStr);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) 
    {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        Q.push_back(match_str);
    } 
    
}

void S_parse(string buf)
{
    buf.erase(0,5);
    regex regexStr("[^\\s,;\\{\\}\\*_]");
    auto words_begin = sregex_iterator(buf.begin(), buf.end(), regexStr);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) 
    {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        //cout<<match_str<<endl;
        S.push_back(match_str[0]);
    } 
}

void G_parse(string buf)
{
    buf.erase(0,5);
    regex regexStr("[^\\s,;\\{\\}\\*]");
    auto words_begin = sregex_iterator(buf.begin(), buf.end(), regexStr);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) 
    {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        //cout<<match_str<<endl;
        G.push_back(match_str[0]);
    } 
}

void F_parse(string buf)
{
    buf.erase(0,5);
    regex regexStr("(\\w+)");
    auto words_begin = sregex_iterator(buf.begin(), buf.end(), regexStr);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) 
    {
        smatch match = *i;                                                 
        string match_str = match.str(); 
        if(find(Q.begin(),Q.end(),match_str)==Q.end())
        {
            cerr<<"syntax error"<<endl;
            if(arg_v) cerr<<"Final state not in Q"<<endl;
            exit(4);
        }
        F.push_back(match_str);
    } 
}

void delta_parse(string buf)
{
    //cout<<buf<<endl;
    string row=buf;
    int pos=buf.find(' ');
    string old_state=buf.substr(0,pos);
    buf.erase(0,pos+1);

    pos=buf.find(' ');
    string old_symbols=buf.substr(0,pos);
    buf.erase(0,pos+1);

    pos=buf.find(' ');
    string new_symbols=buf.substr(0,pos);
    buf.erase(0,pos+1);

    pos=buf.find(' ');
    string direction=buf.substr(0,pos);
    buf.erase(0,pos+1);

    string new_state=buf;

    // cout<<old_state<<endl;
    // cout<<old_symbols<<endl;
    // cout<<new_symbols<<endl;
    // cout<<direction<<endl;
    // cout<<new_state<<endl;
    if(find(Q.begin(),Q.end(),old_state)==Q.end() || find(Q.begin(),Q.end(),new_state)==Q.end())
    {
        cerr<<"syntax error"<<endl;
        if(arg_v) cerr<<row<<": delta state is not in Q"<<endl;
        exit(6);
    }

    if(old_symbols.size()!=N || new_symbols.size()!=N || direction.size()!=N)
    {
        cerr<<"syntax error"<<endl;
        if(arg_v) cerr<<row<<": delta length is not matched with N"<<endl;
        exit(7);
    }
    for(int i=0;i<N;i++)
    {
        if(direction[i]!='l'&&direction[i]!='r'&&direction[i]!='*')
        {
            cerr<<"syntax error"<<endl;
            if(arg_v) cerr<<row<<": illegal character in dirction"<<endl;
            exit(9);
        }
        if(old_symbols[i]=='*'&&(new_symbols[i]=='*'||find(G.begin(),G.end(),new_symbols[i])!=G.end()))
        {
            continue;
        }
        if(find(G.begin(),G.end(),old_symbols[i])==G.end()
        ||find(G.begin(),G.end(),new_symbols[i])==G.end()
        )
        {
            cerr<<"syntax error"<<endl;
            if(arg_v) cerr<<row<<": symbol do not exist in G"<<endl;
            exit(8);
        }
    }

    transfer temp;
    temp.old_state=old_state;
    temp.new_state=new_state;
    temp.old_symbols=old_symbols;
    temp.new_symbols=new_symbols;
    temp.direction=direction;
    delta.push_back(temp);
}