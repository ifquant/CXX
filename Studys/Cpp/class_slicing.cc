
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : class_slicing.cc
#   Last Modified : 2018-11-04 18:59
#   Describe      :
#
# ====================================================*/

#include <iostream>
using namespace std;


class Base {
        Base(const Base &b) = delete;
};
class derite : private Base {

};

class deriteB : protected Base {

};

int main(int argc, char *argv[]) {
        return 0;
}
