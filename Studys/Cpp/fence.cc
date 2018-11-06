
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : fence.cc
#   Last Modified : 2018-11-06 19:30
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <atomic>
#include <thread>
#include <cassert>
using namespace std;

std::atomic<bool> x,y;
std::atomic<int>  z;

void write_x_then_y()
{
        x.store(true, std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_release);
        y.store(true,std::memory_order_relaxed);
}

void read_y_then_x()
{
        while(!y.load(std::memory_order_relaxed));
        std::atomic_thread_fence(std::memory_order_acquire);
        if (x.load(std::memory_order_relaxed))++z;
}

int main(int argc, char *argv[])
{
        x = false;
        y = false;
        z = 0;
        std::thread a(write_x_then_y);
        std::thread b(read_y_then_x);
        a.join();
        b.join();
        assert(z.load()!=0);
        return 0;
}
