
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : variadic.cc
#   Last Modified : 2018-11-03 15:35
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
//#include <pair>
using namespace std;


int main(int argc, char *argv[])
{
        map<string , int > data = { {"aaa",1},{"bbb",1},{"ccc",1}};
        map<string, int> &m = data;

        //count_if(data.begin(),data.end(), [](map<string,int>::iterator it){return true;});
        count_if(m.begin(),m.end(), [](auto &d){
                        std::cout <<d.first<<std::endl;
                        return true;});
        return 0;
}
