
#ifndef ZOO_TEST_H
#define ZOO_TEST_H
#include "zoo.h"
#include "gtest/gtest.h"

class UnitTest: public::testing::Test
{
public:
    virtual void SetUp()
    {
        std::cerr<<"setting up";
    }

    virtual void TearDown()
    {
        std::cerr<<"Closing down";
    }
};



#endif //ZOO_TEST_H
