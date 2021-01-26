#include <iostream>
#include "SafePtr.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
class test{
public:
    int i;
    void my_test(){ std::cout<< i<< "\n";};
};
void check_copy_ctor(UniquePtr<test> &uniptr)
{
    std::cout<<"good its by ref"<<"\n";
}
int main() {
//    SafePtr<test> intptr(new test());
//    intptr->i = 8;
//    (*intptr).my_test();
//
//    UniquePtr<test> uniptr(new test());
//    uniptr->i = 8;
//    (*uniptr).my_test();
//    check_copy_ctor(uniptr);

   // test * share_test = new test();
    Shared_ptr<test> share_test1(new test());
    Shared_ptr<test> share_test2(share_test1);
    Shared_ptr<test> share_test3(share_test1);
    Shared_ptr<test> share_test4(share_test1);
    return 0;
}
