
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : ratio.cc
#   Last Modified : 2018-11-09 10:24
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <ratio>
using namespace std;

int main(int argc, char *argv[])
{
  std::ratio<1,3> r1;
  std::ratio<2,4> r2;
  std::ratio_add<decltype(r1),decltype(r2)> sum;
  std::cout <<decltype(sum)::num << "/" <<  decltype(sum)::den;
  return 0;
}



