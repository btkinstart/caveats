
TARGETS := deprecated

.PHONY: all

all: $(TARGETS)

deprecated: deprecated.cpp
	g++ -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGETS)
