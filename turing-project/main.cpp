#include <iostream>
#include <string>
#include <fstream>

#include "simulator.h"
#include "parser.h"

using namespace std;

string TM, input;
bool arg_v;
bool arg_s;

int main(int argc, char* argv[])
{
	//parse arg
    if(argc == 1)
	{
        return 1;
    }
	arg_v=false;
	for(int i=1;i<argc;i++)
	{
		string temp=argv[i];
		if(temp[0]=='-')
		{
			if(temp=="-v"||temp=="--verbose")
			{
				arg_v=true;
			}
			else if(temp=="-s"||temp=="--slow")
			{
				arg_s=true;
			}
			else if(temp=="-h"||temp=="--help")
			{
				cout<<"usage: turing [-v|--verbose] [-h|--help] <tm> <input>"<<endl;
				return 0;
			}
			else
			{
				//cerr<<"syntax error"<<endl;
				cerr<<"optional arg: "<<temp<<" is not correct"<<endl;
				exit(1);
			}
		}
		else if(temp.find(".tm")!=-1)
		{
			TM=temp;
		}
		else
		{
			input=temp;
		}
	}


	parser(TM);
	simulate(input);

    return 0;
}
