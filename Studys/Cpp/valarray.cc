
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : valarray.cc
#   Last Modified : 2018-11-03 22:16
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <valarray>
using namespace std;

int main(int argc, char *argv[])
{
        valarray<double> v1 = {1,2,3,4,1};
        valarray<double> v2 = {3,4,5,6,7};

        valarray<double>  v3 = v1 * v2;
        //auto  v3 = v1 * v2;

        for(const auto &v : v3) {
                std::cout <<v <<"\n";
        }

        //for (auto it = begin(v3); it != end(v3); ++it) {
        //        std::cout << *it << "\n";
        //}
        return 0;
}
