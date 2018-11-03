
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : numeric.cc
#   Last Modified : 2018-11-03 21:58
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char * argv[])
{
        int a[3] = {1,2,3};
        auto s = accumulate(&a[0],&a[3],0.0);
        std::cout <<s;
        return 0;
}



