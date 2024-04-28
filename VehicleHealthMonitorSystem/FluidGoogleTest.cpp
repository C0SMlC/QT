#include <gtest/gtest.h>
#include "fluidmodel.h"

class FluidModelTest : public ::testing::Test {
protected:
    void SetUp() override {
        FluidModel::fluidList.clear();
    }

    void TearDown() override {
        FluidModel::fluidList.clear();
    }
};

TEST_F(FluidModelTest, GivenDefaultConstructorWhenCreatingFluidModelThenPropertiesAreInitialized) {
    QString name = "Test Fluid";
    int healthLevel = 100;
    FluidModel fluid(name, healthLevel);

    EXPECT_EQ(fluid.getFluidName(), name);
    EXPECT_EQ(fluid.getFluidHealth(), healthLevel);
}

TEST_F(FluidModelTest, GivenEmptyFluidListWhenGettingFluidListThenReturnsEmptyList) {
    QList<FluidModel> fluidList = FluidModel::getFluidList();
    EXPECT_TRUE(fluidList.isEmpty());
}

TEST_F(FluidModelTest, GivenFluidModelWhenAddingToListThenListContainsFluid) {
    FluidModel fluid("Test Fluid", 100);
    QList<FluidModel> fluidList = FluidModel::addFluidToList(fluid);

    EXPECT_EQ(fluidList.size(), 1);
    EXPECT_EQ(fluidList.first().getFluidName(), "Test Fluid");
    EXPECT_EQ(fluidList.first().getFluidHealth(), 100);
}

TEST_F(FluidModelTest, GivenDuplicateFluidNameWhenAddingToListThenListDoesNotContainDuplicate) {
    FluidModel fluid1("Test Fluid", 100);
    FluidModel fluid2("Test Fluid", 80);
    FluidModel::addFluidToList(fluid1);
    QList<FluidModel> fluidList = FluidModel::addFluidToList(fluid2);

    EXPECT_EQ(fluidList.size(), 1);
    EXPECT_EQ(fluidList.first().getFluidName(), "Test Fluid");
    EXPECT_EQ(fluidList.first().getFluidHealth(), 100);
}

TEST_F(FluidModelTest, GivenFluidModelWhenSettingFluidHealthLessThanCurrentHealthThenHealthLevelIsUpdated) {
    FluidModel fluid("Test Fluid", 100);
    int newHealthLevel = 80;
    FluidModel updatedFluid = fluid.setFluidHealth(20);

    EXPECT_EQ(updatedFluid.getFluidHealth(), newHealthLevel);
}

TEST_F(FluidModelTest, GivenFluidModelWhenSettingFluidHealthGreaterThanCurrentHealthThenHealthLevelIsZero) {
    FluidModel fluid("Test Fluid", 80);
    FluidModel updatedFluid = fluid.setFluidHealth(100);

    EXPECT_EQ(updatedFluid.getFluidHealth(), 0);
}

TEST_F(FluidModelTest, GivenFluidModelWhenCopyingThenPropertiesArePreserved) {
    FluidModel fluid("Test Fluid", 100);
    FluidModel copiedFluid(fluid);

    EXPECT_EQ(copiedFluid.getFluidName(), "Test Fluid");
    EXPECT_EQ(copiedFluid.getFluidHealth(), 100);
}

TEST_F(FluidModelTest, GivenFluidModelWhenAssigningThenPropertiesArePreserved) {
    FluidModel fluid("Test Fluid", 100);
    FluidModel assignedFluid("Another Fluid", 80);
    assignedFluid = fluid;

    EXPECT_EQ(assignedFluid.getFluidName(), "Test Fluid");
    EXPECT_EQ(assignedFluid.getFluidHealth(), 100);
}
