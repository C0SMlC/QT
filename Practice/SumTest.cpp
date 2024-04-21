#include "gtest/gtest.h"
#include "SumService/sum.h"
#include "SumMock.h"

using namespace::testing;

class SumProvider:public ::testing::Test{
protected:
    void SetUp() override {
        dsptr = new DisplayMockClass;
        newObj = new Sum(dsptr);
    }

    void TearDown() override {
        delete newObj;
        delete dsptr;
    }

    Sum* newObj;
    DisplayMockClass *dsptr;

};

TEST_F(SumProvider, WhenTwoValuesArePassedToGetSumThenReturnSum){
    EXPECT_CALL(*dsptr,display(10)).Times(1);
    EXPECT_EQ(30, newObj->getSum(10, 20));
}
