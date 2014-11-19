
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>

#define BINSTR(x) \
  std::string(x, sizeof(x) - 1)

int
main(int argc, char** argv)
{
  const char kConstant[] = "foo\0bar\0baz";
  const char* kConstantPtr = "foo\0bar\0baz";
  printf("%s\n", kConstant);
  printf("%zu\n", sizeof(kConstant));

  std::string fromconst(kConstant);
  std::string fromconst2(kConstant, sizeof(kConstant) - 1);

  std::string macro(BINSTR("foo\0bar\0baz"));
  std::string macro_const(BINSTR(kConstant));
  std::string macro_const_ptr(BINSTR(kConstantPtr));

  std::cout << "base: " << fromconst << "\n"
    << "next: " << fromconst2 << "\n"
    << "binstr: " << macro << "\n"
    << "binstr const: " << macro_const << "\n"
    << "binstr const ptr: " << macro_const_ptr << "\n"
    << "\n";
  return 0;
}
