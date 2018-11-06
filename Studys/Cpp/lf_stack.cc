
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : lf_stack.cc
#   Last Modified : 2018-11-07 01:08
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <atomic>
using namespace std;


template<typename T>
class lock_free_stack
{
    private:
            struct node
            {
                    T data;
                    node *next;
                    node(T const& data_): data(data_)
                    {
                    }
            };
    std::atomic<node*> head;

    public:
    void push(T const& data)
    {
            node * const new_node = new node(data);
            new_node->next = head.load();
            while(!head.compare_exchange_weak(new_node->next,new_node));
    }
};


int main(int argc, char * argv[])
{
        return 0;
}

