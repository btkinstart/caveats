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
  virtual

.PHONY: all

all: $(TARGETS)

copy_and_assign: copy_and_assign.cpp
	$(CXX) -o $@ $^

deprecated: deprecated.cpp
	$(CXX) -o $@ $^

str: str.cpp
	$(CXX) -o $@ $^

const: const.cpp
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGETS)
