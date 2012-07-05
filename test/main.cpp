
#include <stdio.h>
#include <memDetector.h>


class A
{
public:
  A(){
    printf("Here is Big A\n");
  }
};

int main(int argc, char* argv[])
{
  char* ptr1 = (char*)malloc(10);
  char* ptr2 = (char*)malloc(10);
  free(ptr1);
  free(ptr2);

  A* p = new A();
   delete (p);
  return 0;
}




