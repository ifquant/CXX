
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : construct.cc
#   Last Modified : 2018-11-04 17:33
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct X {
        X(std::initializer_list<int> v){};
        X(){};
        X(int i){};
};

class XX {
        public:
                XX(int x) {};
                XX():XX(0){};
};

class A {
public:
        int a {7};
        int b = 77;
};

class B {
public:
        int a ;
        int b ;
        B(): a {7},b{7}{};
};
class C {
public:
        int a = 7;
        int b = 7 ;
        C(){ a = 8, b = 8;};
};



int main(int argc, char * argv[])
{
        vector<string> v1 {77};
        vector<string> v2(77);
        std::cout<< v1.size() << " " << v2.size() << "\n";
        vector<int*> v6 {nullptr, nullptr};
        vector<int*> v8;


        X x0 {}; //call X()
        X x1 {1}; //call X(list)

        C c;
        std::cout << c.a << "  " << c.b << std::endl;

        return 0;
}
