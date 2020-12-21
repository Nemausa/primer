/**
* @file application.hpp
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2020-12-17-10-38
* @author Nemausa
* @contact: tappanmorris@outlook.com
*
*/
#ifndef APPLICATION
#define APPLICATION

#include "alloctor.hpp"
#include "cell_object.hpp"

namespace memory{

class ClassA: public object_pool_base<ClassA, 10> {
public:
    ClassA(){
        printf("ClassA\n");
    }
    
    ~ClassA(){
        printf("~ClassA\n");
    }

public:
    int num_;

};

    int main () {
        int *a = new int;
        *a = 11;

        ClassA *a1 = new ClassA();
        ClassA *a2 = ClassA::create_object();

        return 0;
    }
   
} // namespace memory


#endif // APPLICATION