
#include <stdio.h>
#include <stdlib.h>

struct Base {
  virtual void fcn() const {
    printf("Base::fcn()\n");
  }
  int x;
};

struct Derived : public Base {
  virtual void fcn() const {
    printf("Derived::fcn()\n");
  }
  int y;
};

void takes_base_by_value(Base b) {
  printf("takes_base_by_value\n");
  b.fcn();
}

void takes_base_by_reference(const Base& b) {
  printf("takes_base_by_reference\n");
  b.fcn();
}


int main(int argc, char** argv) {
  Derived d;

  const Base& b = d;
  b.fcn();
  printf("d: %p\n", &d);
  printf("d.x: %p\n", &d.x);
  printf("d.y: %p\n", &d.y);

  // By value, copy constructor is invoked to create Base
  takes_base_by_value(d);
  // By reference, uses original object
  takes_base_by_reference(d);

  return 0;
}
