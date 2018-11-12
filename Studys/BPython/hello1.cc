
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hello1.cc
#   Last Modified : 2018-11-12 13:27
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <boost/python.hpp>


using namespace std;
using namespace boost::python;

struct  World
{
  World(string msg):msg(msg) {};
  World(double a, double b):a(a),b(b) {};
  void set(string msg) {this->msg = msg;}
  string greet() {return msg;}
  double sum_s() {return a + b;}
  string msg;
  double a;
  double b;
};

BOOST_PYTHON_MODULE(hello1)
{
  class_<World>("World",init<string>())
    .def(init<double,double>())
    .def("greet",&World::greet)
    .def("set",&World::set)
    .def("sum_s",&World::sum_s);
}


// int main() {

