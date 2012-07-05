
#include <stdio.h>
#include <memDetector.h>

int main(int argc, char* argv[])
{
  char* ptr1 = (char*)malloc(10);
  char* ptr2 = (char*)malloc(10);
  free(ptr1);
  free(ptr2);

  int* p = new int;
  delete p;
  return 0;
}




