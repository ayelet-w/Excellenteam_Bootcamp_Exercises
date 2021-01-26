

#ifndef SMART_POINTERS_UNIQUEPTR_H
#define SMART_POINTERS_UNIQUEPTR_H
#include <cstddef>

template <typename Type>
class UniquePtr {
public:
    explicit UniquePtr(Type * ptr = NULL) : m_ptr(ptr) {};
    virtual ~UniquePtr(){
        delete m_ptr;
    };
    Type& operator*();
    Type* operator->();
private:
    UniquePtr(UniquePtr<Type>  &other)
    {
        this->m_ptr = other.m_ptr;
        other.m_ptr = NULL;
    }
    UniquePtr& operator = (UniquePtr<Type> &other)
    {
        if (this != other) {
            this->m_ptr = other.m_ptr;
            other.m_ptr = NULL;
        }
        return *this;
    }
    Type * m_ptr;
};
template <typename Type>
Type& UniquePtr<Type>::operator*()
{
    return *m_ptr;
}

template <typename Type>
Type* UniquePtr<Type>::operator->()
{
    return m_ptr;
}


#endif //SMART_POINTERS_UNIQUEPTR_H
