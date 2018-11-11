
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
#include <map>
#include <deque>
#include <queue>
#include <stack>
//#include <priority_queue>

#include <unordered_map>

using namespace std;

void test_map()
{
  map<string,int> a;
  a["dd"]=1;
  std::cout << "vec msiz: " << a.max_size() << "\n";
  a.at("zz");
}


int main(int argc, char *argv[])
{
  test_map();
  return 0;
}



