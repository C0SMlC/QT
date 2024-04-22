#include "gtest/gtest.h"
#include "SumService/sum.h"
#include "SumMock.h"
#include <QSignalSpy>

using namespace::testing;

class interfaceClass:public ::testing::Test{
protected:
    interfaceClass(){
        displayPtr = new DisplayMockClass;
        sumPtr = new Sum(displayPtr);
    }
    ~interfaceClass(){
        delete sumPtr;
    }

    DisplayMockClass* displayPtr;
    Sum* sumPtr;
};

TEST_F(interfaceClass, whenejwkjthennjksjdks){
    EXPECT_CALL(*displayPtr, display(10)).Times(1);
    EXPECT_EQ(30, sumPtr->getSum(10, 20));
}
