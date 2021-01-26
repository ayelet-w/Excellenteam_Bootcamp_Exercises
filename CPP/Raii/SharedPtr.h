//
// Created by ayelet on 11/30/20.
//

#ifndef RAII_SHAREDPTR_H
#define RAII_SHAREDPTR_H

#include <cstddef>
#include "Counter.h"

template <typename T>
class Shared_ptr
{
public:

    explicit Shared_ptr(T* ptr = NULL)
    {
        m_ptr = ptr;
        m_counter = new Counter();
        if (ptr)
        {
            (*m_counter)++;
        }
    }


    Shared_ptr(Shared_ptr<T>& sp)
    {
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
    }

    unsigned int use_count()
    {
        return m_counter->get();
    }

    T* get()
    {
        return m_ptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    ~Shared_ptr()
    {
        (*m_counter)--;
        if (m_counter->get() == 0)
        {
            delete m_counter;
            delete m_ptr;
        }
    }

private:

    Counter* m_counter;
    T* m_ptr;
};

#endif //RAII_SHAREDPTR_H
