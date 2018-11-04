
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : move.cc
#   Last Modified : 2018-11-04 16:44
#   Describe      :
#
# ====================================================*/

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
        while(true) {
                string *s1 =new string("dddd");
                string s2 = std::move(*s1);  //memleak
                // delete s1; must delete,or memleakl
        }
        return 0;
}
