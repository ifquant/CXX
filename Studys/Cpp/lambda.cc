
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : valarray.cc
#   Last Modified : 2018-11-03 22:16
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <valarray>
#include <vector>

using namespace std;

void algo(vector<int> &v)
{
        int count = v.size();
        std::generate(v.begin(),v.end(),[&count]()  {return --count;});
}

int main(int argc, char *argv[])
{
        return 0;
}
