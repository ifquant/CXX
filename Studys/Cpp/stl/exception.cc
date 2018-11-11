
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : exception.cc
#   Last Modified : 2018-11-09 11:07
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;

void test_exception() {
  try {
  }
  catch (system_error &se) {
  }
  catch (logic_error &le) {
  }
  catch (runtime_error &re) {
  }
  catch (exception &e) {
  }
  catch (...) {
  }
}


int main(int argc, char *argv[])
{
  test_exception();
  return 0;
}
