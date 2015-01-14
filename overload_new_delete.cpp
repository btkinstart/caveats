
#include <stdio.h>
#include <stdlib.h>
#include <vector>

void* operator new(size_t size) {
  void* ptr = malloc(size);
  printf("new %zu at %p\n", size, ptr);
  return ptr;
}

void operator delete(void* ptr) {
  printf("free: %p\n", ptr);
  free(ptr);
}

class MyAlloc {
 public:
  void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    printf("my_malloc %zu at %p\n", size, ptr);
    return ptr;
  }

  void my_free(void* ptr) {
    printf("my free: %p\n", ptr);
    free(ptr);
  }
};

void* operator new(size_t size, MyAlloc* alloc) {
  return alloc->my_malloc(size);
}

void operator delete(void* ptr, MyAlloc* alloc) {
  alloc->my_free(ptr);
}


template <typename T>
class MyStlAlloc {
 public:
  // These are required, serious
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef size_t size_type;
  typedef std::ptrdiff_t difference_type;
  template<class U>
  struct rebind {
    typedef MyStlAlloc<U> other;
  };
  // other stuff needed for 14 and beyond

  MyStlAlloc() {
    printf("MyStlAlloc::MyStlAlloc\n");
  }
  ~MyStlAlloc() {
    printf("MyStlAlloc::~MyStlAlloc\n");
  }

  pointer address( reference x ) const {
    printf("MyStlAlloc::address\n");
    return &x;
  }
  const_pointer address( const_reference x ) const {
    printf("MyStlAlloc::address const\n");
    return &x;
  }

  pointer allocate( size_type n, std::allocator<void>::const_pointer hint = 0 ) {
    size_t b = n * sizeof(T);
    pointer ptr = (pointer) ::operator new(b);
    printf("MyStlAlloc::allocate %p %zu\n", ptr, n);
    return ptr;
  }

  void deallocate( pointer p, size_type n ) {
    printf("MyStlAlloc::deallocate %p %zu\n", p, n);
    ::operator delete(p);
  }

  size_type max_size() const {
    printf("MyStlAlloc::max_size\n");
    return 0xFFFFFFFFFFFFFFFFLLU;
  }

  /// until C++ 11
  void construct( pointer p, const_reference val ) {
    printf("MyStlAlloc::construct %p\n", p);
    // for classes
    new ((void*)(p)) T(val);
  }
  void destroy( pointer p ) {
    printf("MyStlAlloc::destroy %p\n", p);
    // for classes
    ((T*)p)->~T();
  }

  // TODO: construct/destroy for c++11 and beyond
};


template< class T1, class T2 >
bool operator==( const MyStlAlloc<T1>& lhs, const MyStlAlloc<T2>& rhs ) {
  printf("MyStlAlloc ==\n");
  return (&lhs) == (&rhs);
}

template< class T1, class T2 >
bool operator!=( const MyStlAlloc<T1>& lhs, const MyStlAlloc<T2>& rhs ) {
  printf("MyStlAlloc !=\n");
  return lhs != rhs;
}

int main(int argc, char** argv) {
  int* foo = new int;
  delete foo;

  MyAlloc my_alloc;
  MyAlloc* alloc_ptr = &my_alloc;
  foo = new (alloc_ptr) int;
  delete (alloc_ptr, foo);

  std::vector<int, MyStlAlloc<int> > vec;
  vec.push_back(1);
  vec.resize(2);
  return 0;
}
