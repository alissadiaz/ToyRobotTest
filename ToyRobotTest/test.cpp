#ifndef _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#endif // !_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include "pch.h"
#include "ToyRobot.cpp"
#include <gtest/gtest.h>

class ToyRobotFixture : public ::testing::Test
{
public:
	ToyRobotFixture() {}
	~ToyRobotFixture() {}

	std::shared_ptr<ToyRobot> sut = std::make_shared<ToyRobot>();
};

TEST_F(ToyRobotFixture, ShouldPlaceNorth)
{
	sut->runCommand("place,", 0, 0, "north");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "north");
}

TEST_F(ToyRobotFixture, ShouldPlaceEast)
{
	sut->runCommand("place,", 0, 0, "east");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "east");
}

TEST_F(ToyRobotFixture, ShouldPlaceSouth)
{
	sut->runCommand("place,", 0, 0, "south");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "south");
}

TEST_F(ToyRobotFixture, ShouldPlaceWest)
{
	sut->runCommand("place,", 0, 0, "west");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "west");
}

TEST_F(ToyRobotFixture, ShouldNotFallOffTheTable)
{
	sut->runCommand("place,", 0, 0, "west");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "west");
}

TEST_F(ToyRobotFixture, ShouldNotAcceptInvalidPosition)
{
	sut->runCommand("place,", -4, -6, "west");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, -1);
	ASSERT_EQ(pos.y_, -1);
	ASSERT_EQ(pos.dir_, "");
}

TEST_F(ToyRobotFixture, ShouldNotAcceptInvalidDirection)
{
	sut->runCommand("place,", 0, 0, "northeast");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, -1);
	ASSERT_EQ(pos.y_, -1);
	ASSERT_EQ(pos.dir_, "");
}

TEST_F(ToyRobotFixture, ShouldAcceptUppercaseDirection)
{
	sut->runCommand("place,", 0, 0, "WEST");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
	ASSERT_EQ(pos.dir_, "west");
}

TEST_F(ToyRobotFixture, ShouldChangeDirectionWithLeftCommand)
{
	sut->runCommand("place,", 0, 0, "west");
	sut->runCommand("left");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "south");
	sut->runCommand("left");
	pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "east");
	sut->runCommand("left");
	pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "north");
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
}

TEST_F(ToyRobotFixture, ShouldChangeDirectionWithRightCommand)
{
	sut->runCommand("place,", 0, 0, "west");
	sut->runCommand("right");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "north");
	sut->runCommand("right");
	pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "east");
	sut->runCommand("right");
	pos = sut->getPosition();
	ASSERT_EQ(pos.dir_, "south");
	ASSERT_EQ(pos.x_, 0);
	ASSERT_EQ(pos.y_, 0);
}

TEST_F(ToyRobotFixture, ShouldMoveOneStepNorth)
{
	sut->runCommand("place,", 5, 5, "north");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 5);
	ASSERT_EQ(pos.y_, 6);
	ASSERT_EQ(pos.dir_, "north");
}

TEST_F(ToyRobotFixture, ShouldMoveOneStepWest)
{
	sut->runCommand("place,", 5, 5, "west");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 4);
	ASSERT_EQ(pos.y_, 5);
	ASSERT_EQ(pos.dir_, "west");
}

TEST_F(ToyRobotFixture, ShouldMoveOneStepSouth)
{
	sut->runCommand("place,", 5, 5, "south");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 5);
	ASSERT_EQ(pos.y_, 4);
	ASSERT_EQ(pos.dir_, "south");
}

TEST_F(ToyRobotFixture, ShouldMoveOneStepEast)
{
	sut->runCommand("place,", 5, 5, "east");
	sut->runCommand("move");
	auto pos = sut->getPosition();
	ASSERT_EQ(pos.x_, 6);
	ASSERT_EQ(pos.y_, 5);
	ASSERT_EQ(pos.dir_, "east");
}