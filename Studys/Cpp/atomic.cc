
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : atomic.cc
#   Last Modified : 2018-11-06 11:17
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <atomic>
#include <memory>
using namespace std;


int main(int argc, char *argv[]) {
        std::shared_ptr<int> p;

        std::atomic_load(&p);
        std::atomic_store(&p, p);
        return 0;
}


