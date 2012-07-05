/**********************************************************************
 **********************************************************************
 *  File:    memDetector.c
 *  Description:
 *       Source file which implement the operator new/delete malloc and
 *       free. Here we will create a binary searching tree to record the
 *       memory usage.
 *  
 *       it provide the data of all the memory which Malloc by the process.
 *       and the dealloc logs.
 *
 *  Author:  ewentzh
 *  Date:    2012-7-3
 *
 *  Change List:
 *      1.   2012-7-3  First Revion!!
 *
 **********************************************************************
 **********************************************************************
 * */

/**********************************************************************/
/***********************   INCLUDE  ***********************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************/
/**********************************************************************/


/**********************************************************************/
/***********************   Macros   ***********************************/

/**********************************************************************/
/***********************   Struct   ***********************************/

/**********************************************************************/
/***********************  Variables ***********************************/
typedef struct AllocInfo{
    char file[50];
    char func[20];
    int line;
}memInfo_t;

typedef struct BiMemNode{
    unsigned long addr;
    memInfo_t allocator;
    memInfo_t dellocator;
};



int initMemDetector(char* logFile)
{
   
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
int formatLog(const char* file,int line,void* addr,int action)
{
  char buf[200] = {0};
  sprintf(buf,"File:%s,Line:%d,has %s Addr 0x%08X\n",file,line,action==1?"free":"malloc",addr);
  printf(buf);
  return 0;
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void* debug_malloc(const char* file,int line,int size)
{
  char buf[200] = {0} ;
  void* ptr = NULL;
  ptr = malloc(size);
  formatLog(file,line,ptr,0);
  
  return malloc(size);
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void debug_free(const char* file,int line,void* addr)
{
  formatLog(file,line,addr,1);
  free(addr);
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void* operator new[](size_t size,const char* file,const char* fun,int line)
{
  void* ptr = NULL;
  printf("File:%s,Fun:%s,Line:%d\n",file,fun,line);
//  ptr = ::operator new[] (size);
  ptr=malloc(size);
  return ptr;
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void* operator new(size_t size,const char* file,const char* fun,int line)
{
  void* ptr = NULL;
  printf("File:%s,Fun:%s,Line:%d\n",file,fun,line);
//  ptr = ::operator new(size);
  ptr= malloc(size);
  return ptr;
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void operator delete(void* ptr)
{
//  ::operator delete(ptr);
  free(ptr);
}

/* *
 **********************************************************************
 * 
 * Function:
 * Uasage: 
 * Return Value:
 *
 **********************************************************************/
void operator delete[] (void* ptr)
{
  free(ptr);
//  ::operator delete[] (ptr);
}


