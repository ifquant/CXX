
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : thread.cc
#   Last Modified : 2018-11-05 11:34
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <thread>
using namespace std;

void hello() 
{
        while(1)
        std::cout<< "hello Current World\n";
}

void hello_test(){
        std::thread t1 (hello);
        std::thread t2 (hello);
        t1.join();
        t2.join();
}

struct B {
        public:
        B() {
                std::cout << "default "; //1
        }
        B(const B&b) {
                std::cout << "copy struct";
        };
        B& operator=( B&b) {
                std::cout << "copy = "; //2
                //return *this;
        };


        //B(B &&b) = delete; //error,, forward
        B( B&&b) {
                std::cout << "move con"; //2
                //return *this;
        };
        B& operator=( B&&b) {
                std::cout << "move = ";
                return *this;
        };

        void operator()() {
        };

};

void B_test() {
        B b;
        std::thread t1 (b);
        t1.join();
}
void b_test(B b) {
}

void B1_test() {
        B b;
        std::thread t1 (b_test,b);
        t1.join();
}

void c_function(string &s) {
}
void d_function(string s) {
}


void C_test() {
        string val = "cccc";
        std::thread t(c_function, std::ref(val));
        t.join();
        std::cout << "ctest " << val << "\n";
}

void D_test() {
        string val = "gggg";
        std::thread t(d_function, val);
        t.join();
        std::cout << "gtest " << val << "\n";
}

class E {
        public:
                void work(){};
};


void E_test() {
    E e;
    std::thread t(&E::work, &e);
};



int main(int argc, char *argv[]){
        B_test();
        C_test();
        D_test();
        B1_test();
        E_test();
        return 0;
}


