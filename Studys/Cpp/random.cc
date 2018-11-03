
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : random.cc
#   Last Modified : 2018-11-03 22:02
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <random>
#include <functional>
using namespace std;

using my_engine       = default_random_engine;
using my_distribution = uniform_int_distribution<>; 

int main(int argc, char * argv[])
{
        my_engine re {};
        my_distribution one_to_six{1,100}; 
        auto die = bind(one_to_six,re);

        //auto die = bind(uniform_int_distribution<>{1,6},default_random_engine{});
        //std::cout <<die() <<die() << die()<<die();
        for(int i=1;i < 100;++i) {
                std::cout<<die();
        }
        return 0;
}



