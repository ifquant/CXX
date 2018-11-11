
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

void test_queue_stack_priority_queue()
{
  queue<int, deque<int>> i;
  stack<int, vector<int>> s;
  priority_queue<int, vector<int>, std::less<int>> pq;
}


int main(int argc, char *argv[])
{
  test_queue_stack_priority_queue();
  return 0;
}



