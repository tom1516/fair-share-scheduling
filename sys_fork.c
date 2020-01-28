#include "syslib.h"

PUBLIC int sys_fork(parent, child, procgrp)
int parent;			/* process doing the fork */
int child;			/* which proc has been created by the fork */
int procgrp;
{
/* A process has forked.  Tell the kernel. */

  message m;

  m.PR_PPROC_NR = parent;
  m.PR_PROC_NR = child;
  m.m1_i3 = procgrp;
  return(_taskcall(SYSTASK, SYS_FORK, &m));
}
