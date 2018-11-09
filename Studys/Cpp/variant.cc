
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : variant.cc
#   Last Modified : 2018-11-08 18:13
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <variant>
using namespace std;


int main(int argc, char * argv[])
{
  std::variant<int64_t,float,double> z(1.2);
  auto p = std::get_if<float>(&z);
  std::cout << *p;
  return 0;
}




