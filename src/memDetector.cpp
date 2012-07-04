/*
*
*
*
*
*
*
*
*
*
*
* */

#include <stdio.h>
#include <stdlib.h>

int formatLog(char* file,int line,int addr,int action)
{
  char buf[200] = {0};
  sprintf(buf,"File:%s,Line:%d,has %s Addr 0x%08X\n",file,line,action==1?"free":"malloc",addr);
  printf(buf);
  return 0;
}

void* debug_malloc(char* file,int line,int size)
{
  char buf[200] = {0} ;
  void* ptr = NULL;
  ptr = malloc(size);
  formatLog(file,line,(int)ptr,0);
  
  return malloc(size);
}


void debug_free(char* file,int line,void* addr)
{
  formatLog(file,line,(int)addr,1);
  free(addr);
}
