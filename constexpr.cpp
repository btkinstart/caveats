
#include <stdlib.h>
#include <vector>
#include <string>

// not allowed
// constexpr std::string lols() { return "lols"; }

// C++11 Limited to only a return statement in constexpr funcions, 14 will
// remove restriction (infinite looping compilations?)
constexpr int64_t fib(int64_t n) {
  return n <= 1 ? 1 : fib(n - 1) + fib(n - 2);
}

const int64_t fib_5 = fib(5);

int
main(int argc, char** argv)
{
  return 0;
}

