

#ifndef SMART_POINTERS_SAFEPTR_H
#define SMART_POINTERS_SAFEPTR_H
#include <cstddef>

template <typename Type>
class SafePtr {
public:
    explicit SafePtr(Type * ptr = NULL) : m_ptr(ptr) {};
    virtual ~SafePtr(){
        delete m_ptr;
    };
    Type& operator*();
    Type* operator->();
private:
    Type * m_ptr;
};

template <typename Type>
Type& SafePtr<Type>::operator*()
{
    return *m_ptr;
}

template <typename Type>
Type* SafePtr<Type>::operator->()
{
    return m_ptr;
}

#endif
