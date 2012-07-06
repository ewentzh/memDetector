
#include <stdio.h>
#include <memDetector.h>


class A
{
public:
  A(){
//    printf("Here is Big A\n");
  }
  A(int x){
//    printf("Here is Big A with parameter!!\n");
  }
};


int testBiTree()
{
  return 0;
}


int testMem_malloc()
{
  printf("Test malloc=====>\n");
  char*           p1 = (char*)malloc(10);
  int*            p2 = (int*) malloc(10*sizeof(10));
  unsigned short* p3 = (unsigned short*)malloc(1*sizeof(unsigned short));
  long *          p4 = (long*) malloc(2* sizeof(long));

  free( p2 );
  return 0;
}
int testMem_new()
{
  printf("\n Test New=========> \n");
  char* p   = new char('a');
  char* p1  = new char[10];
  int*  p2  = new int(1);
  long* p3  = new long[10];

  delete p;
  delete[] p3;
  return 0;
}

int testMem_class()
{
  printf("\n Test Class ===>\n");
  A* p   = new A();
  A* p1  = new A(10);
  A* p2  = new A[10]();
  A* p3  = new A[20];

  delete p;
  delete p3;
  return 0;
}

int testMem()
{
  testMem_malloc();
  testMem_new();
  testMem_class();

  printf("\n\n=====  dump the biTree  =====\nn");
  extern void dumpMem();
  dumpMem();
  return 0;
}

int main(int argc, char* argv[])
{

  testBiTree();
  testMem();
  return 0;
}




