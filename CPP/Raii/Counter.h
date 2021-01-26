
#ifndef RAII_COUNTER_H
#define RAII_COUNTER_H


class Counter
{
public:

    Counter(): m_counter(0){};

    Counter(const Counter&) ;
    Counter& operator=(const Counter&) ;

    ~Counter() {}

    void reset()
    {
        m_counter = 0;
    }

    unsigned int get()
    {
        return m_counter;
    }

    void operator++()
    {
        m_counter++;
    }

    void operator++(int)
    {
        m_counter++;
    }

    void operator--()
    {
        m_counter--;
    }
    void operator--(int)
    {
        m_counter--;
    }

private:
    unsigned int m_counter;
};



#endif //RAII_COUNTER_H
