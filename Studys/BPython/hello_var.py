#!/usr/bin/env python
# encoding: utf-8
# coding style: pep8
# ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : hello_var.py
#   Last Modified : 2018-11-12 14:02
#   Describe      :
#
# ====================================================

import sys
import hello_var

# import os

var = hello_var.Var("hello_var")
var.value = 3.14
print(var.name)


