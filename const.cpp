
#include <stdlib.h>
#include <vector>

struct Container {
  Container() : a(0) {}
  int a;
};

typedef std::vector<Container*> Containers;
void mod_container(const Containers& containers) {
  // will fail
  // containers.push_back(NULL);
  // containers[0] = NULL;

  // ok!
  Container* cont = containers[0];
  cont->a = 2;

  // works, pointer is const, but structure is not
  containers[0]->a = 1;
}

int
main(int argc, char** argv)
{
  Container cont;
  Containers conts;
  conts.push_back(&cont);
  mod_container(conts);
  return 0;
}

