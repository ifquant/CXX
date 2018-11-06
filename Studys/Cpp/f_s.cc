
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : f_s.cc
#   Last Modified : 2018-11-06 12:58
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


void foo(int a, int b)
{
        std::cout << a << ", " << b << std::endl;
}

int get_num()
{
        static int i = 0;
        return ++i;
}

int main(int argc, char *argv[])
{
        while(1) {
            foo(get_num(), get_num());
        }
        return 0;
}
