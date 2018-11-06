
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : mutex.cc
#   Last Modified : 2018-11-05 13:53
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <mutex>
using namespace std;

int main(int argc, char *argv[])
{
        std::mutex lock1;
        lock1.lock();
        std::mutex lock2 = std::move(lock1);
        lock2.lock();
        std::cout << "lock success" ;

        return 0;
}



