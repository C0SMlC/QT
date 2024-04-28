#include <gtest/gtest.h>
#include "filtermodel.h"

class FilterModelTest : public ::testing::Test {
protected:
    void SetUp() override {
        FilterModel::filterList.clear();
    }

    void TearDown() override {
        FilterModel::filterList.clear();
    }
};

TEST_F(FilterModelTest, GivenDefaultConstructorWhenCreatingFilterModelThenPropertiesAreInitialized) {
    QString name = "Test Filter";
    int healthLevel = 100;
    FilterModel filter(name, healthLevel);

    EXPECT_EQ(filter.getFilterName(), name);
    EXPECT_EQ(filter.getFilterHealth(), healthLevel);
}

TEST_F(FilterModelTest, GivenEmptyFilterListWhenGettingFilterListThenReturnsEmptyList) {
    QList<FilterModel> filterList = FilterModel::getFilterList();
    EXPECT_TRUE(filterList.isEmpty());
}

TEST_F(FilterModelTest, GivenFilterModelWhenAddingToListThenListContainsFilter) {
    FilterModel filter("Test Filter", 100);
    QList<FilterModel> filterList = FilterModel::addFilterToList(filter);

    EXPECT_EQ(filterList.size(), 1);
    EXPECT_EQ(filterList.first().getFilterName(), "Test Filter");
    EXPECT_EQ(filterList.first().getFilterHealth(), 100);
}

TEST_F(FilterModelTest, GivenDuplicateFilterNameWhenAddingToListThenListDoesNotContainDuplicate) {
    FilterModel filter1("Test Filter", 100);
    FilterModel filter2("Test Filter", 80);
    FilterModel::addFilterToList(filter1);
    QList<FilterModel> filterList = FilterModel::addFilterToList(filter2);

    EXPECT_EQ(filterList.size(), 1);
    EXPECT_EQ(filterList.first().getFilterName(), "Test Filter");
    EXPECT_EQ(filterList.first().getFilterHealth(), 100);
}

TEST_F(FilterModelTest, GivenFilterModelWhenSettingFilterHealthThenHealthLevelIsUpdated) {
    FilterModel filter("Test Filter", 100);
    int newHealthLevel = 80;
    FilterModel updatedFilter = filter.setFilterHealth(20);

    EXPECT_EQ(updatedFilter.getFilterHealth(), newHealthLevel);
}

TEST_F(FilterModelTest, GivenFilterHealthLessThanDecrementWhenSettingFilterHealthThenHealthLevelIsZero) {
    FilterModel filter("Test Filter", 10);
    FilterModel updatedFilter = filter.setFilterHealth(20);

    EXPECT_EQ(updatedFilter.getFilterHealth(), 0);
}

TEST_F(FilterModelTest, GivenFilterModelWhenCopyingThenPropertiesArePreserved) {
    FilterModel filter("Test Filter", 100);
    FilterModel copiedFilter(filter);

    EXPECT_EQ(copiedFilter.getFilterName(), "Test Filter");
    EXPECT_EQ(copiedFilter.getFilterHealth(), 100);
}

TEST_F(FilterModelTest, GivenFilterModelWhenAssigningThenPropertiesArePreserved) {
    FilterModel filter("Test Filter", 100);
    FilterModel assignedFilter("Another Filter", 80);
    assignedFilter = filter;

    EXPECT_EQ(assignedFilter.getFilterName(), "Test Filter");
    EXPECT_EQ(assignedFilter.getFilterHealth(), 100);
}
