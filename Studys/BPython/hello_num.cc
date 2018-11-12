
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hello_num.cc
#   Last Modified : 2018-11-12 14:04
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <boost/python.hpp>
using namespace std;
using namespace boost::python;

struct Num
{
  Num() {}
  float get() const {return val;}
  void set(float val) {this->val = val;}
  float val;
};


BOOST_PYTHON_MODULE(hello_num)
{
  class_<Num>("Num")
    .add_property("rovalue", &Num::get) //对外只读
    .add_property("value", &Num::get, &Num::set);
}



// int main() {



