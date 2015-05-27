
#include <functional>
#include <iostream>
#include <string>

class LambdaFactory {
 public:
  explicit LambdaFactory(int a) : a(a) {}

  std::function<int(int)> add() {
    auto that = this;
    return [that](int b) {
      std::cout << "a: " << &that->a << "\n";
      that->a = 50;
      return that->a + b;
    };
  }

  int aa() { return a; }

 private:
  int a;
};

class CtorPrinter {
 public:
  CtorPrinter() {
    count_ = count++;
    std::cout << count_ << " CtorPrinter()" << std::endl;
  }
  CtorPrinter(const CtorPrinter& other) {
    std::cout << count_ <<
      " CtorPrinter(const CtorPrinter& other)" << std::endl;
  }
  CtorPrinter& operator=(const CtorPrinter& other) {
    std::cout << count_ << " CtorPrinter::operator=" << std::endl;
    return *this;
  }
  ~CtorPrinter() {
    std::cout << count_ << " ~CtorPrinter()" << std::endl;
  }

  CtorPrinter(CtorPrinter&& other) = delete;
  CtorPrinter& operator=(CtorPrinter&& other) = delete;

  int count_;

  static int count;
};

int CtorPrinter::count = 0;

template <class T>
void forward_str(T&& foo) {
  std::cout << "foo count: " << foo.count_ << std::endl;
  const std::type_info& info = typeid(foo);
  std::cout << "foo type: " << info.name() << std::endl;
  std::cout << "T type: " << typeid(T).name() << std::endl;
  std::cout << "&foo: << " << &foo << std::endl;
}

#define V(x) std::cout << #x ": " << x << "\n";
int main(int argc, char** argv) {
  LambdaFactory* c = new LambdaFactory(1);
  std::function<int(int)> fcn = c->add();

  delete c;
  c = new LambdaFactory(100);
  std::cout << "value: " << fcn(1) << "\n";
  std::cout << "c->a: " << c->aa() << "\n";

  CtorPrinter printer;
  std::cout << "&printer: " << &printer << std::endl;
  forward_str(printer);

  return 0;
}

