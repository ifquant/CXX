
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : unordered_map.cc
#   Last Modified : 2018-11-09 11:23
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <deque>
#include <queue>
#include <stack>
//#include <priority_queue>

#include <unordered_map>

using namespace std;

void test_container()
{
  vector<int> a= {1,2,3};
  std::cout << "vec size: " << a.size() << "\n";
  std::cout << "vec cap : " << a.capacity() << "\n";
  std::cout << "vec msiz: " << a.max_size() << "\n";
}


int main(int argc, char *argv[])
{
  test_container();
  return 0;
}



