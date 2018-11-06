
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : class.cc
#   Last Modified : 2018-11-04 17:17
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


class A {
        public:
                int a;
};

class B : public A {
        public:
                int a;
                int b;
                void test(){
                        A::a = 1;
  a = 3;
  std::cout<<A::a << a<<" end \n";
                };
};
struct C {
        int a;
        int b;

};

void test() {
        C c {1,2};
        // B b {(1,2)}; bad
}

int main(int argc, char *argv[])
{
        B *b = new B();
        A *a = b;
        a->a = 1;
        //std::cout <<b->a;
        //std::cout <<a->a;
        b->test();
        return 0;
}

