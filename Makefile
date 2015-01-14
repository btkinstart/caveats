#
#
#

CXX ?= g++

TARGETS := \
  abort \
  const \
  copy_and_assign \
  deprecated \
  inheritance \
  stat_mtime_granularity \
  str \
  templated_superclass \
  time \
  virtual

.PHONY: all

all: $(TARGETS)

time: time.cpp
	$(CXX) -o $@ $^ -lrt

.PHONY: clean
clean:
	rm -f $(TARGETS)
