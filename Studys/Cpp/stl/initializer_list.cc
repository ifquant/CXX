
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : initializer_list.cc
#   Last Modified : 2018-11-09 10:47
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <initializer_list>
using namespace std;


int main(int argc, char *argv[])
{
  std::initializer_list<int> lst = {1,2,3,4,5};
  const int *p = lst.begin();
  for(int i = 0; i < lst.size(); ++i) {
    // cout<<lst[i]; now allow
    cout<<p[i];
  }
}
