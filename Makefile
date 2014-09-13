

TARGETS := copy_and_assign deprecated

.PHONY: all

all: $(TARGETS)

copy_and_assign: copy_and_assign.cpp
	g++ -o $@ $^

deprecated: deprecated.cpp
	g++ -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGETS)
