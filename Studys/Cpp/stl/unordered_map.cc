
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
#include <unordered_map>

using namespace std;

void test_unordered_map()
{
  unordered_map<string,int, std::hash<string>, std::equal_to<string> > um;
  um["dddd"] = 1;
}

int main(int argc, char *argv[])
{
  test_unordered_map();
  return 0;
}



