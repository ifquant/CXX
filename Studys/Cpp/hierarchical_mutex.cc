
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hierarchical_mutex.cc
#   Last Modified : 2018-11-05 13:58
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <mutex>
//#include <hierarchical_mutex>
using namespace std;


void test(){
        hierarchial_mutex low_mutex(100);
        hierarchial_mutex high_mutex(1000);
        std::lock_guard<hierarchical_mutex> lk_l(low_mutex);
        std::lock_guard<hierarchical_mutex> lk_h(high_mutex);
}

int main(int argc, char *argv[])
{
        test();
        return 0;
}



