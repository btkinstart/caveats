
#include <sstream>
#include <stdio.h>

class Logger {
 public:
  Logger(const char* fn, int line) { stream_ << fn << ":" << line << "] "; }
  ~Logger() { printf("%s\n", stream_.str().c_str()); }
  std::ostream& stream() { return stream_; }
  std::ostringstream stream_;
};

// fake glog compatibility layer
#define INFO 0
#define LOG(x) Logger(__FILE__, __LINE__).stream()

template <typename T>
class Base {
 public:
  Base() : t_(NULL), base_member_(42) {}

  T* t_;
  int base_member_;
};

template <typename T>
class Derived : public Base<T> {
 public:

  void foo() {
    LOG(INFO) << this->base_member_;
    LOG(INFO) << Base<T>::base_member_;

    // does not work which is super annoying
    // LOG(INFO) << base_member_;
  }

  int derived_member_;
};

int main() {
  Derived<int> d;
  d.foo();
  LOG(INFO) << d.base_member_;
  return 0;
}
