/**
* @file memory_mg.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2020-12-16-15-05
* @author Nemausa
* @contact: tappanmorris@outlook.com
*
*/
#ifndef MEMORY_MG
#define MEMORY_MG

#include <stdlib.h>
#include <assert.h>
#include <mutex>

#ifdef _DEBUG
#include <stdio.h>
    #define xprintf(...) printf(__VA_ARGS__)
#else
    #define xprintf(...)
#endif

#define MAX_MEMORY_SIZE 1024

class memory_alloc;
// memroyt block
class memory_block{
public:
    memory_block(){};
    ~memory_block(){};

public:
    int id_;
    int ref_;
    memory_alloc *alloc_;
    memory_block *next_;
    bool in_pool_;

private:
    char c1;
    char c2;
    char c3;

};

// const int memory_block_size = sizeof(memory_block);
// memroy pool
class memory_alloc {
public:
    memory_alloc():address_(nullptr),header_(nullptr),block_size_(0), block_num_(0) {
        xprintf("memory_alloc\n");
    }

    ~memory_alloc() {
        if (address_)
            free(address_);
    }

    void init_memory() {
        xprintf("MemoryAlloc:size=%d, block_num=%d \n", block_size_, block_num_);
	    assert(nullptr==address_);
		if (address_)
			return;
        int info_size = sizeof(memory_block);
        size_t real_size = block_size_ + info_size;
        size_t sum_size = block_num_ * real_size;
        address_ = (char*)malloc(sum_size);

        header_ = (memory_block*)address_;
        header_->id_ = 0;
        header_->ref_ = 0;
        header_->in_pool_ = true;
        header_->alloc_ = this;
        header_->next_ = nullptr;

        memory_block *pre = header_;
        for (size_t n = 1; n <block_num_; n++) {
            memory_block *temp = (memory_block*)(address_ + n * real_size);
            temp->id_ = n;
            temp->ref_ = 0;
            temp->in_pool_ = true;
            temp->alloc_ = this;
            temp->next_ = nullptr;
            pre->next_ = temp;
            pre = temp;
        }
    }

    void *alloc_memory(size_t size) {
        std::lock_guard<std::mutex> its_lock(mutex_);
        if (!address_)
            init_memory();
        
        memory_block *block = nullptr;
        if (nullptr == header_) {// no more memory block 
            block = (memory_block*)malloc(size + sizeof(memory_block));
            block->id_ = -1;
            block->ref_ = -1;
            block->in_pool_ = false;
            block->alloc_ = this;
            block->next_ = nullptr;
        } else {
            block = header_;
            header_ = header_->next_;
            assert(0 == block->ref_);
            block->ref_ = 1;
        }
        xprintf("allocmem:%x, id=%d, size=%d \n", block, block->id_, size);
		return ((char*)block+sizeof(memory_block));
    }

    void free_memory(void *_free) {
        memory_block *block = (memory_block*)((char*)_free - sizeof(memory_block));
        assert(1 == block->ref_);

        if (block->in_pool_) {
            std::lock_guard<std::mutex> its_lock(mutex_);
            if (--block->ref_ != 0)
                return;
            block->next_ = header_;
            header_ = block;
        } else {
            if (--block->ref_ != 0)
                return;
            free(block);
        }
    }



protected:
    char *address_;
    memory_block *header_;
    size_t block_size_;
    size_t block_num_;
    std::mutex mutex_;
};

template<size_t block_num, size_t block_size>
class memory_alloctor : public memory_alloc{
public:
    memory_alloctor() {
        const size_t n = sizeof(void*);
        block_size_ = (block_size / n)*n + (block_size % n ? n : 0);
        block_num_ = block_num;
    }
};

class memory_manage {
private:
    memory_manage() {
        init_map(0, 64, &mem64_);
        init_map(65, 128, &mem64_);
        init_map(129, 256, &mem64_);
        init_map(257, 512, &mem64_);
        init_map(513, 1024, &mem64_);

        mem64_.alloc_memory(64);
		mem128_.alloc_memory(128);
		mem256_.alloc_memory(256);
		mem512_.alloc_memory(512);
		mem1024_.alloc_memory(1024);
    }

    ~memory_manage() {

    }

    void init_map(int begin, int end, memory_alloc *mem) {
        for (int n = begin; n <= end; n++)
            sz_alloc[n] = mem;
    }

public:
    static memory_manage &instance() {
        static memory_manage mg;
        return mg;
    }

    void *alloc_memory(size_t _size) {
        if (_size < MAX_MEMORY_SIZE) {
            return sz_alloc[_size]->alloc_memory(_size);
        }
        else {
            memory_block *block = (memory_block*)malloc(_size + sizeof(memory_block));
            block->id_ = -1;
            block->ref_ = -1;
            block->in_pool_ = false;
            block->alloc_ = nullptr;
            block->next_ = nullptr;
            xprintf("allocmem:%x, id=%5d, size=%5d \n", block, block->id_, _size);
			return (char*)block+sizeof(memory_block);
        }
    }

    void free_memory(void *_free) {
        memory_block *block = (memory_block*)((char*)_free - sizeof(memory_block));
        xprintf("freemem: %x, id=%5d \n", block, block->id_);
        if (block->in_pool_)
            block->alloc_->free_memory(_free);
        else
            if (--block->ref_ == 0)
                free(block);
    }

private:
    memory_alloctor<100, 64> mem64_;
    memory_alloctor<100, 128> mem128_;
    memory_alloctor<100, 256> mem256_;
    memory_alloctor<100, 512> mem512_;
    memory_alloctor<100, 1024> mem1024_;
    memory_alloc *sz_alloc[MAX_MEMORY_SIZE+1];
};



#endif // MEMORY_MG