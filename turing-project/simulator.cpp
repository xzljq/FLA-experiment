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

void simulate(string input)
{
    check_input(input);

    
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
        cerr<<"Input: "<<input<<endl;
        cerr<<"==================== RUN ===================="<<endl;
    }
}