
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : forward.cc
#   Last Modified : 2018-11-07 12:23
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;

/*
C++11 提出了新的模板匹配规则，即引用折叠规则：
T& & –> T&.

T&& & –> T&.

T& && –>T&.

T&& && –> T&&. 

*/



void RunCode(int && m) { cout << "rvalue ref" << endl;}
void RunCode(int &  m) { cout << "lvalue ref" << endl;}
void RunCode(const int &&  m) { cout << "const rvalue ref" << endl;}
void RunCode(const int  &  m) { cout << "const lvalue ref" << endl;}


template<typename T>
void PerfectForward(T &&t) { RunCode(forward<T>(t)); };

int main(int argc, char *argv[])
{
  int a;
  int b;
  const int c = 1;
  const int d = 0;
  PerfectForward(a);
  PerfectForward(move(b));
  PerfectForward(c);
  PerfectForward(move(d));
  return 0;
}









