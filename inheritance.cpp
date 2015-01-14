
#include <stdio.h>
#include <stdlib.h>
#include <vector>


struct A {
  virtual void vf() {
    printf("A:vf()\n");
  }
};

struct B {
  virtual void vf() {
    printf("B:vf()\n");
  }
};

struct AB : public A, public B {
};


int
main(int argc, char** argv)
{
  AB ab;
  // error: request for member ‘vf’ is ambiguous
  // ab.vf();

  return 0;
}

