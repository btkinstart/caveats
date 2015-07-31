
#include <iostream>
#include <memory>
#include <vector>

#define LOG std::cout
#define V(x) std::cout << #x ": " << x << "\n";

class A {
 public:
  int x;
};

class B {
  public:
  constexpr B() noexcept : y(0) {}
  ~B() noexcept {}

  B(B&& b) = default;
  B& operator=(B&& b) = default;


  int y;
  std::unique_ptr<A> a;

  B(const B& b) = delete;
  B& operator=(const B& b) = delete;
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

int main(int argc, char** argv) {
  // can't convert directly to unique ptr
  // foo(new A);
  // ok
  foo(std::unique_ptr<A>(new A));

  foo(bar());

  foo(baz());

  std::vector<std::unique_ptr<A>> as;
  as.push_back(bar());

  std::vector<B> bs;
  B b;
  bs.push_back(std::move(b));
  return 0;
}

