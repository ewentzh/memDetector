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

int formatLog(const char* file,int line,void* addr,int action)
{
  char buf[200] = {0};
  sprintf(buf,"File:%s,Line:%d,has %s Addr 0x%08X\n",file,line,action==1?"free":"malloc",addr);
  printf(buf);
  return 0;
}

void* debug_malloc(const char* file,int line,int size)
{
  char buf[200] = {0} ;
  void* ptr = NULL;
  ptr = malloc(size);
  formatLog(file,line,ptr,0);
  
  return malloc(size);
}


void debug_free(const char* file,int line,void* addr)
{
  formatLog(file,line,addr,1);
  free(addr);
}

void* operator new[](size_t size,const char* file,const char* fun,int line)
{
  void* ptr = NULL;
  printf("File:%s,Fun:%s,Line:%d\n",file,fun,line);
//  ptr = ::operator new[] (size);
  ptr=malloc(size);
  return ptr;
}
void* operator new(size_t size,const char* file,const char* fun,int line)
{
  void* ptr = NULL;
  printf("File:%s,Fun:%s,Line:%d\n",file,fun,line);
//  ptr = ::operator new(size);
  ptr= malloc(size);
  return ptr;
}


void operator delete(void* ptr)
{
//  ::operator delete(ptr);
  free(ptr);
}

void operator delete[] (void* ptr)
{
  free(ptr);
//  ::operator delete[] (ptr);
}


