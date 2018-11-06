
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : f_s3.cc
#   Last Modified : 2018-11-06 18:12
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>
using namespace std;

std::atomic<int> data[5];
std::atomic<bool> sync1(false),sync2(false);

void thread_1()
{
        data[0].store(42,std::memory_order_relaxed);
        data[1].store(97,std::memory_order_relaxed);
        data[2].store(17,std::memory_order_relaxed);
        data[3].store(-141,std::memory_order_relaxed);
        data[4].store(2003,std::memory_order_relaxed);
        sync1.store(true, std::memory_order_release);
}

void thread_2()
{
        while(!sync1.load(std::memory_order_acquire));
        sync2.store(true,std::memory_order_release);
}

void thread_3()
{
        while(!sync2.load(std::memory_order_acquire));
        assert(data[0].load(std::memory_order_relaxed)==42);
        assert(data[1].load(std::memory_order_relaxed)==97);
        assert(data[2].load(std::memory_order_relaxed)==17);
        assert(data[3].load(std::memory_order_relaxed)==-141);
        assert(data[4].load(std::memory_order_relaxed)==2003);
}

int main(int argc, char *argv[]){
        return 0;
}








