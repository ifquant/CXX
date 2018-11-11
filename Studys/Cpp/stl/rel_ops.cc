
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : rel_ops.cc
#   Last Modified : 2018-11-09 12:46
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <utility>
using namespace std;


class A
{
  public:
    int a;
    int b;
    A(const int c, const int d)
    {
      a = c;b = d;
    }
    bool operator<(const A& m) const 
    {
      return a < m.a;
    }
    bool operator==(const A&m) const
    {
      return a == m.a;
    }
};


int main(int argc, char *argv[])
{
  using namespace std::rel_ops;
  A a(10,10);
  A b(15,15);
  std::cout<< (a<b) <<std::endl;
  std::cout<< (a>b) <<std::endl;
  std::cout<< (a==b) <<std::endl;
  std::cout<< (a!=b) <<std::endl;
  return 0;
}
