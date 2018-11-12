
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hello.cc
#   Last Modified : 2018-11-12 13:18
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <boost/python.hpp>

using namespace std;
using namespace boost::python;

struct World
{
  void set(string msg) {this->msg = msg;}
  string greet() { return msg; }
  string msg;
};

BOOST_PYTHON_MODULE(hello)
{
  class_<World>("World")
    .def("greet",&World::greet)
    .def("set",&World::set);
}

// int main() {
