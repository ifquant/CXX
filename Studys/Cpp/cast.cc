
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : cast.cc
#   Last Modified : 2018-11-04 15:22
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;



int main(int argc, char *argv[]) {
        const int a =0;
        int *b = const_cast<int*>(&a);
        *b = 3;
        std::cout << a << " p is " <<&a << "\n";
        std::cout << *b<< " p is " <<b<< "\n";
        if ((void*)&a == (void*)b) {
                std::cout << "equal point" <<a << " " << *b ;
        } else {
                std::cout << "not equal";
        }
        //static_cast
        //reinterpret_cast
        //dynamic_cast
        return 0;
}
