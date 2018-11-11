
/* ====================================================
#   Copyright (C)2018 All rights reserved.
#
#   Author        : IfQuant
#   Email         : ifquant@163.com
#   File Name     : shm_server.cc
#   Last Modified : 2018-11-12 01:48
#   Describe      :
#
# ====================================================*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class A {
  public:
    void Init(){
        p = new int(1);
        *p = 1;
    };
    int Get() {
      return *p;
    }
    int * GetP() {
      return p;
    }
  private:
    int *p;
};

int main()
{
  pid_t pid;
  int shmid;
  void *shm_addr = NULL;
  if ((shmid = shmget(0x123456,1024,0666|IPC_CREAT)) < 0) {
      perror("shmget");
  }
  if ((shm_addr = shmat(shmid,0,0)) == (void*)-1) {
    perror("shmat fail");
  }
  A *pa = (A*)shm_addr;
  A *a = new (&pa)A();
  a->Init();
  while(1) {
    ;
  }
  return 0;

}



