
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : variadic.cc
#   Last Modified : 2018-11-03 15:35
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <chrono>
using namespace std;

using namespace std::chrono;



int main(int argc, char *argv[])
{
auto t0 = high_resolution_clock::now();
auto t1 = high_resolution_clock::now();
for(int i=0;i < 100;)i++;
//std::cout << 
std::cout<<(        duration_cast<milliseconds>(t1-t0)).count();
//std::cout<<t0;
return 0;
}
