
#include <stdio.h>
#include <memDetector.h>


class A
{
public:
  A(){
    printf("Here is Big A\n");
  }
};


extern int initMemDetector(char* logFile);
int main(int argc, char* argv[])
{
  initMemDetector(NULL);
  char* ptr1 = (char*)malloc(10);
  char* ptr2 = (char*)malloc(10);

  extern void testMem(void*);
  testMem(ptr2);
  free(ptr1);
  free(ptr2);

  A* p = new A();
   delete (p);
   int* x = new int[10];
   delete[] x;
  return 0;
}




