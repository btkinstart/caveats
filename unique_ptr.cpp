
#include <iostream>
#include <memory>
#include <vector>

#define LOG std::cout

class A {
  public:
  int x;
};

void foo(std::unique_ptr<A> a) {
  LOG << "foo() a=" << a.get() << std::endl;
}

std::unique_ptr<A> bar() {
  LOG << "bar" << std::endl;
  return std::unique_ptr<A>(new A);
}

std::unique_ptr<A> baz() {
  std::unique_ptr<A> a(new A);
  LOG << "baz() a=" << a.get() << std::endl;
  return a;
}

#define V(x) std::cout << #x ": " << x << "\n";
int main(int argc, char** argv) {
  // can't convert directly to unique ptr
  // foo(new A);
  // ok
  foo(std::unique_ptr<A>(new A));

  foo(bar());

  foo(baz());
  return 0;
}

