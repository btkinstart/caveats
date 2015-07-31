#
#
#

CC = g++ --std=c++11

TARGETS := \
  abort \
  const \
  constexpr \
  copy_and_assign \
  cxx11 \
  deprecated \
  inheritance \
  overload_new_delete \
  sizes \
  stat_mtime_granularity \
  str \
  templated_superclass \
  time \
  unique_ptr \
  virtual

.PHONY: all

all: $(TARGETS)

%: %.cpp
	$(CC) -o $@ $^

time: time.cpp
	$(CC) -o $@ $^ -lrt

.PHONY: clean
clean:
	rm -f $(TARGETS)
