#include <gtest/gtest.h>

using namespace::testing;

#include <gtest/gtest.h>
#include "dataprovider.h"


// UserModel createTestUserModel(const QString& userName, int vehicleId, int totalKms, int batteryLevel, int engineHours, int fuelLeft) {
//     UserModel userModel;
//     userModel.userName = userName;
//     userModel.vehicleId = vehicleId;
//     userModel.totalKms = totalKms;
//     userModel.batteryLevel = batteryLevel;
//     userModel.engineHours = engineHours;
//     userModel.fuelLeft = fuelLeft;
//     return userModel;
// }

class DataProviderTest : public ::testing::Test {
protected:
    void SetUp() override {
        provider = new dataprovider();
    }

    void TearDown() override {
        delete provider;
    }

    dataprovider* provider;
};

TEST_F(DataProviderTest, AddUserTest) {
    QString newUserName = "testuser";
    bool result = !provider->addUser(newUserName);
    EXPECT_TRUE(result);
}

TEST_F(DataProviderTest, AddDuplicateUserTest) {
    QString newUserName = "testuser";
    bool result = provider->addUser(newUserName);
    EXPECT_FALSE(result);
}

TEST_F(DataProviderTest, GetUserTest) {
    QString userName = "testuser";
    provider->addUser(userName);
    UserModel userModel = provider->getUser(userName);
    EXPECT_EQ(userModel.userName, userName);

    // userModel = provider->getUser("nonexistinguser");
    // EXPECT_TRUE(userModel.userName.isEmpty());
}

// TEST_F(DataProviderTest, UpdateVehicleInfoTest) {
//     QString userName = "testuser";
//     provider->addUser(userName);
//     bool result = provider->updateVehicleInfo(userName, 1000, 80, 100, 50);
//     EXPECT_TRUE(result);

//     result = provider->updateVehicleInfo("nonexistinguser", 1000, 80, 100, 50);
//     EXPECT_FALSE(result);
// }

// TEST_F(DataProviderTest, GetVehicleInfoTest) {
//     QString userName = "testuser";
//     provider->addUser(userName);
//     provider->updateVehicleInfo(userName, 1000, 80, 100, 50);
//     VehicleInfo vehicleInfo = provider->getVehicleInfo();
//     EXPECT_EQ(vehicleInfo.totalKms, 1000);
//     EXPECT_EQ(vehicleInfo.batteryLevel, 80);
//     EXPECT_EQ(vehicleInfo.engineHours, 100);
//     EXPECT_EQ(vehicleInfo.fuelLeft, 50);
// }

// TEST_F(DataProviderTest, GetAllUsersTest) {
//     QVector<UserModel> users = provider->getAllUsers();
//     EXPECT_TRUE(users.isEmpty());

//     provider->addUser("user1");
//     provider->addUser("user2");
//     provider->addUser("user3");
//     users = provider->getAllUsers();
//     EXPECT_EQ(users.size(), 3);
// }

// TEST_F(DataProviderTest, UpdateUserTest) {
//     QString userName = "testuser";
//     provider->addUser(userName);
//     UserModel userModel = createTestUserModel(userName, 1, 1000, 80, 100, 50);
//     bool result = provider->updateUser(userModel);
//     EXPECT_TRUE(result);

//     userModel = createTestUserModel("nonexistinguser", 2, 2000, 70, 200, 30);
//     result = provider->updateUser(userModel);
//     EXPECT_FALSE(result);
// }

// TEST_F(DataProviderTest, UpdateLastUserWithoutStartTest) {
//     QString userName = "testuser";
//     provider->addUser(userName);
//     bool result = provider->updateLastUserWithoutStart(userName);
//     EXPECT_TRUE(result);

//     result = provider->updateLastUserWithoutStart("nonexistinguser");
//     EXPECT_FALSE(result);
// }
