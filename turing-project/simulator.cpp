#include "simulator.h"
#include "parser.h"





extern vector<string> Q;//状态集
extern vector<char> S;//输入符号集
extern vector<char> G;//纸带符号集
extern string q0;//初始状态
extern char B;//空格符号
extern vector<string> F;//终结状态集
extern int N;//纸带数
extern vector<transfer> delta;//
extern bool arg_v;
extern bool arg_s;

int step=0;
string cur_state;
vector<map<int,char>> tapes;
vector<int> heads(N,0);
vector<int> lefts(N,0);
vector<int> rights(N,0);


void simulate(string input)
{
    check_input(input);
    cur_state=q0;
    tapes.resize(N);
    heads.resize(N);
    lefts.resize(N);
    rights.resize(N);

    if(input.size()==0)
    {
        tapes[0][0]='_';
    }
    for(int i=0;i<input.size();i++)
    {
        tapes[0][i]=input[i];
    }


    rights[0]=(input.size()==0?0:input.size()-1);
    for(int i=1;i<N;i++)
    {
        tapes[i][0]='_';
    }
    while(1)
    {
        if(arg_s) sleep(1);
        if(arg_v) print_TM();
        string cur_symbols;
        for(int i=0;i<N;i++)
        {
            cur_symbols+=tapes[i][heads[i]];
        }
        vector<transfer> ::iterator it = delta.begin();
        for(;it!=delta.end();it++)
        {
            // cout<<it->old_symbols<<endl;
            // cout<<cur_symbols<<endl;
            // cout<<it->old_state<<endl;
            // cout<<cur_state<<endl;
            // cout<<endl;
            if(symbols_cmp(it->old_symbols,cur_symbols)==true && it->old_state==cur_state)
            {
                //cout<<"hello"<<endl;
                break;
            }
        }
        if(it==delta.end()) break;
        cur_state=it->new_state;
        for(int i=0;i<N;i++)
        {
            if(it->old_symbols[i]=='*' && it->new_symbols[i]=='*')
            {
                
            }
            else
            {
                tapes[i][heads[i]]=it->new_symbols[i];
            }
            
            if(it->direction[i]=='l')
            {
                heads[i]--;
                if(heads[i]<lefts[i])
                {
                    tapes[i][heads[i]]='_';
                    lefts[i]=heads[i];
                }
                for(int j=rights[i];j>heads[i];j--)
                {
                    if(tapes[i][j]=='_')
                    {
                        rights[i]--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if(it->direction[i]=='r')
            {
                heads[i]++;
                if(heads[i]>rights[i])
                {
                    tapes[i][heads[i]]='_';
                    rights[i]=heads[i];
                }

                for(int j=lefts[i];j<heads[i];j++)
                {
                    if(tapes[i][j]=='_')
                    {
                        lefts[i]++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {

            }
        }

        step++;
    }

    string res;
    for(int i=lefts[0];i<=rights[0];i++)
    {
        res+=tapes[0][i];
    }
    for(int i=res.size()-1;i>=0;i--)
    {
        if(res[i]=='_')
        {
            res.erase(i,1);
        }
        else
            break;
    }
    for(int i=0;i<res.size();i++)
    {
        if(res[i]=='_')
        {
            res.erase(i,1);
            i--;
        }
        else
            break;
    }
    if(arg_v) cout<<"Result: "<<res<<endl;
    else cout<<res<<endl;

    if(arg_v) cout<<"==================== END ===================="<<endl;
}

bool symbols_cmp(string pattern,string cur)
{
    for(int i=0;i<pattern.size();i++)
    {
        if(pattern[i]=='*'&&cur[i]!='_')//该符号用于匹配除空格符号'_'外的任意符号
        {
            continue;
        }
        else if(pattern[i]!=cur[i])
        {
            return false;
        }
    }
    return true;
}

void check_input(string input)
{
    for(int i=0;i<input.size();i++)
    {
        if(find(S.begin(),S.end(),input[i])==S.end())
        {
            cerr<<"illegal input"<<endl;
            if(arg_v)
            {
                cerr<<"Input: "<<input<<endl;
                cerr<<"==================== ERR ===================="<<endl;
                cerr<<"error: '"<<input[i]<<"' was not declared in the set of input symbols"<<endl;
                cerr<<"Input: "<<input<<endl;
                for(int j=0;j<i+7;j++) cerr<<" ";
                cerr<<"^"<<endl;
                cerr<<"==================== END ===================="<<endl;
            }
            exit(10);
        }
    }
    if(arg_v)
    {
        cout<<"Input: "<<input<<endl;
        cout<<"==================== RUN ===================="<<endl;
    }
}

void print_TM()
{
    cout<<"Step   : "<<step<<endl;
    cout<<"State  : "<<cur_state<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<"Index"<<i<<" :";
        for(int j=lefts[i];j<=rights[i];j++)
        {
            cout<<" "<<(j>0?j:-j);
        }
        cout<<endl;
        cout<<"Tape"<<i<<"  :";
        for(int j=lefts[i];j<=rights[i];j++)
        {
            cout<<" "<<tapes[i][j];
            for(int k=0;k<count_space(j)-1;k++)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        cout<<"Head"<<i<<"  :";
        for(int j=lefts[i];j<=rights[i];j++)
        {
            if(j==heads[i])
            {
                cout<<" ^"<<endl;
                break;
            }
            for(int k=0;k<count_space(j)+1;k++)
            {
                cout<<" ";
            }
        }
    }
    cout<<"---------------------------------------------"<<endl;
}

int count_space(int d)
{
    int count=0;
    if(d==0)
        return 1;
    if(d<0)
    {
        d=-d;
    }
    while(d!=0)
    {
        count++;
        d/=10;
    }
    return count;
}
