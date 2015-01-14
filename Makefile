#
#
#

CXX ?= g++

TARGETS := \
  const \
  copy_and_assign \
  deprecated \
  inheritance \
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
