
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
#include <forward_list>
using namespace std;



int main(int argc, char *argv[])
{
  forward_list<int> flst = {0,1,2,3,4,5,6,7};
  auto prev = flst.before_begin();
  auto curr = flst.begin();
  for(auto it = curr ; it != flst.end(); ++it) {
    //std::cout << 1;
    std::cout << *it << "\n";
  }

  curr = flst.erase_after(prev);
  //curr = flst.erase_after(curr);
  for(auto it = curr ; it != flst.end(); ++it) {
    //std::cout << *it << "\n";
  }
  return 0;
}
