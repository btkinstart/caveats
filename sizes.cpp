
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define size(x) \
  printf(#x ": %zu\n", sizeof(x));

int
main(int argc, char** argv)
{
  size(int32_t);
  size(long);
  return 0;
}

