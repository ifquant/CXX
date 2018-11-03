
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
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
        vector<int> a = {1,2,1,3,4};
        vector<int> b = {7,8,9};
        sort(a.begin(),a.end());

        //unique_copy(a.begin(),a.end(), b.end()-1);
        unique_copy(a.begin(),a.end(), back_inserter(b));

        for(auto& x:b){
                std::cout << x ;
        }
        return 0;
}
