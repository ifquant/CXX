
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : spinlock.cc
#   Last Modified : 2018-11-06 20:18
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <atomic>
using namespace std;

class spinlock_mutex {
        std::atomic_flag flag;
        public:
        spinlock_mutex():flag(ATOMIC_FLAG_INIT) {
        }
        void lock()
        {
                while(flag.test_and_set(std::memory_order_acquire));
        }
        void unlock()
        {
                flag.clear(std::memory_order_release);
        }
};


int main(int argc, char *argv[])
{
        return 0;
}


