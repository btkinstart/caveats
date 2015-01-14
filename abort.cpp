//
// Adding a hook for abort
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

void abort_handler(int num) {
  printf("backtrace would go here\n");
}

int main(int argc, char** argv) {
  sighandler_t old_val = signal(SIGABRT, &abort_handler);
  assert(old_val != SIG_ERR);
  ::abort();
  printf("Unreachable code...\n");
  return 0;
}
