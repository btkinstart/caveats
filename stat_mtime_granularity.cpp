//
// Test out the mtime quanta for the filesystem.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

#include <string>

#define PCHECK(x) \
  do { \
    if (! (x) ) { \
      perror(#x); \
      ::exit(1); \
    } \
  } while (false)

void write_file(
  const char* fn,
  const std::string& data)
{
  FILE* f = fopen(fn, "w");
  PCHECK(f != NULL);

  PCHECK(fwrite(data.data(), 1, data.size(), f) == data.size());

  PCHECK(fclose(f) == 0);
}

int64_t mtime_usecs(
  const char* fn)
{
  struct stat stat_struct;
  PCHECK(::stat(fn, &stat_struct) == 0);

  int64_t mtime_secs = stat_struct.st_mtim.tv_sec;
  int64_t mtime_nsecs = stat_struct.st_mtim.tv_nsec;
  return mtime_secs * 1000000 + mtime_nsecs / 1000;
}

int64_t update_file_mtime(
  const char* fn,
  const std::string& data)
{
  write_file(fn, data);
  return mtime_usecs(fn);
}

void check_mtime_quanta(
  const char* test_fn)
{
  int64_t orig_mtime = update_file_mtime(test_fn, "a");
  int64_t next_mtime = orig_mtime;

  size_t count;
  for (count = 0; next_mtime == orig_mtime; ++count) {
    char txt[16];
    int len = snprintf(txt, sizeof(txt), "%zu", count);
    next_mtime = update_file_mtime(test_fn, txt);
  }

  printf("filename: %s\n", test_fn);
  printf("iterations: %zu\n", count);
  printf("orig_mtime: %li\n", orig_mtime);
  printf("next_mtime: %li\n", next_mtime);
  printf("delta: %li\n", (next_mtime - orig_mtime));
  printf("\n");

  unlink(test_fn);
}

int main() {

  for (int i  = 0; i < 10; ++i) {
    char fn[32];
    snprintf(fn, sizeof(fn), "test.%i.txt", i);
    check_mtime_quanta(fn);
  }
  return 0;
}

