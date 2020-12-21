/**
* @file cell_object.hpp
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2020-12-17-09-09
* @author Nemausa
* @contact: tappanmorris@outlook.com
*
*/
#ifndef CELL_OBJECT
#define CELL_OBJECT



#include <stdlib.h>
#include <mutex>
#include <assert.h>

#ifdef _DEBUG
#include <stdio.h>
	#ifndef xprintf
	#define xprintf(...) printf(__VA_ARGS__)
	#endif
#else
	#ifndef xprintf
	#define xprintf(...) 
	#endif	
#endif


template<typename T, size_t pool_num>
class cell_object_pool {
public:
    cell_object_pool() {
        init_pool();
    }

    virtual ~cell_object_pool() {
        if (address_)
            delete[] address_;
    }

    void free_memory(void *_free) {
        node_header *pool = (node_header*)((char*)_free - sizeof(node_header));
        assert(1 == pool->ref_);
        if (pool->in_pool_) {
            std::lock_guard<std::mutex> its_lock(mutex_);
            if (--pool->ref_ != 0)
                return;
            pool->next_ = header_;
            header_ = pool;
            xprintf("freeObjmem:%p, id=%d \n", pool, pool->id_);
        } else {
            if (--pool->ref_ != 0)
                return;
            delete[] pool;
            xprintf("freeObjmem:%p, id=%d \n", pool, pool->id_);
        }
    }

    void* alloc_memory(size_t _size) {
        std::lock_guard<std::mutex> its_lock(mutex_);
        node_header *pool = nullptr;
        if (nullptr == header_) {
            pool = (node_header*)new char[sizeof(T) + sizeof(node_header)];
            pool->id_ = 1;
            pool->ref_ = 1;
            pool->in_pool_ = false;
            pool->next_ = nullptr;
        } else {
            pool = header_;
            header_ = header_->next_;
            assert(0 ==  pool->ref_);
            pool->ref_ = 1;
        }
        xprintf("allocObjmem:%p, id=%5d, size=%5d \n", pool, pool->id_, _size);
		return ((char*)pool + sizeof(node_header));
    }

    void init_pool() {
        if (address_)
            return;
        size_t real_size = sizeof(T) +sizeof(node_header);
        size_t sum_size = pool_num * real_size;
        address_ = new char[sum_size];

        header_ = (node_header*)address_;
        header_->id_ = 0;
        header_->ref_ = 0;
        header_->in_pool_ = true;
        header_->next_ = nullptr;

        node_header *pre = header_;
        for (size_t n = 1; n < pool_num; n++) {
            node_header *temp = (node_header*)(address_ +n * real_size);
            temp->id_ = static_cast<int>(n);
            temp->ref_ = 0;
            temp->in_pool_ = true;
            pre->next_ = temp;
            pre = temp;
        }
    }

private:
    struct node_header {
        int id_;
        int ref_;
        bool in_pool_;
        node_header *next_;
        char c1;
        char c2;
    };
    char *address_;
    node_header *header_;
    std::mutex mutex_;
    
};

template<typename T, size_t pool_num>
class object_pool_base {
public:
    object_pool_base() {}
    ~object_pool_base() {}

    void *operator new(size_t _size) {
        return objec_pool().alloc_memory(_size);
    }

    void operator delete(void *_delete) {
        objec_pool().free_memory(_delete);
    }

    template<typename ...Args>
    static T *create_object(Args ... args) {
        T *obj = new T(args...);
        return obj;
    }

    static void destory_object(T *_destory) {
        delete _destory;
    }

private:
    typedef cell_object_pool<T, pool_num> class_type_pool;
    static class_type_pool &objec_pool() {
        static class_type_pool pool;
        return pool;
    }
};

#endif // CELL_OBJECT