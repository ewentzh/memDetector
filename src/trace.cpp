
/*
*
*
*
*
*
* */

#include <stdio.h>
#include <stdlib.h>

int formatLog(char* buf,int size,char* file,char* line,int addr,int action)
{
  sprintf(buf,"File[%s] line:[%d] addr[0x%08X]: has %s",file,line,addr);
  printf();
}

