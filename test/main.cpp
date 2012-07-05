
#include <stdio.h>
#include <memDetector.h>

int main(int argc, char* argv[])
{
  void* ptr1 = malloc(10);
  void* ptr2 = malloc(10);
  free(ptr1);
  free(ptr2);
  return 0;
}




