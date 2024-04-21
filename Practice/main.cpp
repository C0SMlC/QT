#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
    // return a.exec();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
