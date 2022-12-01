#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <regex>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct transfer
{
    string old_state;
    string old_symbols;
    string new_symbols;
    string direction;
    string new_state;
};

void remove_comment(string& buf);
void parser(string tm);
void Q_parse(string buf);
void S_parse(string buf);
void G_parse(string buf);
void F_parse(string buf);
void delta_parse(string buf);