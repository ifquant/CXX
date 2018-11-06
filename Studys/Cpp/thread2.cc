
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : thread2.cc
#   Last Modified : 2018-11-05 13:03
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <thread>
using namespace std;


int main(int argc, char *argv[])
{
        std::cout << "Thread Num:" <<std::thread::hardware_concurrency();
        return 0;
}
