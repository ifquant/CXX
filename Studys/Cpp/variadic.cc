
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
using namespace std;


void Sum() {
}


template<typename T, typename...Tail>
void Sum(T head, Tail... tail)
{
        std::cout << head;
        Sum(tail...);
}

int main(int argc, char *argv[])
{
        Sum(1,2,3,4);
        return 0;
}
