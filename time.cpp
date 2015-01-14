
// Getting time on linux

#include <stdio.h>
#include <time.h>

// link against librt

void res(clockid_t id, const char* name) {
  timespec t;
  int ret = clock_getres(id, &t);

  if (ret != 0) {
    printf("Failed: %s\n", name);
    return;
  }

  printf("%s: %li %li\n", name, t.tv_sec, t.tv_nsec);
}

#define RES(x) res(x, #x)

int main() {
  RES(CLOCK_REALTIME);
  RES(CLOCK_MONOTONIC);
  RES(CLOCK_PROCESS_CPUTIME_ID);
  RES(CLOCK_THREAD_CPUTIME_ID);

  timespec t1, t2;

  if (clock_gettime(CLOCK_REALTIME, &t1) != 0) {
    printf("clock_gettime error\n");
    return 1;
  }

  size_t count = 0;
  while (true) {
    count++;
    clock_gettime(CLOCK_REALTIME, &t2);
    if (t2.tv_nsec != t1.tv_nsec) {
      break;
    }
  }
  printf("count: %zu\n", count);
  printf("delta: %li\n", (t2.tv_nsec - t1.tv_nsec));

  return 0;
}
