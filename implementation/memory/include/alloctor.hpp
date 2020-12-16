/**
* @file alloctor.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2020-12-16-15-00
* @author Nemausa
* @contact: tappanmorris@outlook.com
*
*/

#ifndef ALLOCTOR
#define ALLOCTOR

void *operator new(size_t _size);
void  operator delete(void *_delete);
void *operator new[](size_t _size);
void  operator delete[](void *_delete);
void *mem_alloc(size_t size);
void  mem_free(void *_free);

#endif // ALLOCTOR