#include "alloctor.h"
#include "memory_mg.hpp"

void *operator new(size_t _size) {
    return memory_manage::instance().alloc_memory(_size);
}

void operator delete(void *_delete) {
    memory_manage::instance().free_memory(_delete);
}

void *operator new[](size_t _size) {
    return memory_manage::instance().alloc_memory(_size);
}

void operator delete[](void *_delete) {
    memory_manage::instance().free_memory(_delete);
}

void *mem_alloc(size_t _size) {
    return malloc(_size);
}

void mem_free(void *_free) {
    free(_free);
}

