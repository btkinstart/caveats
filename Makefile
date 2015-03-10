#
#
#

CC ?= g++ --std=c++11

TARGETS := \
  abort \
  const \
  constexpr \
  copy_and_assign \
  deprecated \
  inheritance \
  overload_new_delete \
  sizes \
  stat_mtime_granularity \
  str \
  templated_superclass \
  time \
  virtual

.PHONY: all

all: $(TARGETS)

constexpr: constexpr.cpp
	$(CC) -o $@ $^

time: time.cpp
	$(CC) -o $@ $^ -lrt

.PHONY: clean
clean:
	rm -f $(TARGETS)
