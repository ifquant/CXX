
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : constexpr.cc
#   Last Modified : 2018-11-04 11:45
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


constexpr int comp(int x)
{
        return x*x;
}
int main(int argc, char *argv[])
{
        int i = 4;
        const j = 4;
        constexpr int v = comp(3);
        constexpr int v = comp(j);

        //constexpr int z = comp(i); //bad
        return 0;
}
