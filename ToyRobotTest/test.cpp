#include "pch.h"
#include "Position.cpp"
#include "ToyRobot.cpp"

class ToyRobotFixture : public ::testing::Test
{
public:
	ToyRobotFixture() : x(-2), y(-2), dir("dir")
	{
		sut = std::make_shared<ToyRobot>();
	}
	~ToyRobotFixture() {}

	std::shared_ptr<ToyRobot> sut;
	int x, y;
	std::string dir;
};
TEST_F(ToyRobotFixture, ShouldPlaceRobot)
{
	ASSERT_FALSE(sut->isPlaced());
	sut->place(1, 1, "north");
	std::tie(x, y, dir) = sut->report();
	ASSERT_EQ(x, 1);
	ASSERT_EQ(y, 1);
	ASSERT_EQ(dir, "north");
	ASSERT_TRUE(sut->isPlaced());
}

TEST_F(ToyRobotFixture, ShouldMoveRobot)
{
	ASSERT_FALSE(sut->isPlaced());
	sut->place(1, 1, "north");
	sut->move();
	std::tie(x, y, dir) = sut->report();
	ASSERT_EQ(x, 1);
	ASSERT_EQ(y, 2);
	ASSERT_EQ(dir, "north");
	ASSERT_TRUE(sut->isPlaced());
}

TEST_F(ToyRobotFixture, ShouldRotateRightRobot)
{
	ASSERT_FALSE(sut->isPlaced());
	sut->place(1, 1, "north");
	sut->rotate(ERotation::right);
	std::tie(x, y, dir) = sut->report();
	ASSERT_EQ(x, 1);
	ASSERT_EQ(y, 1);
	ASSERT_EQ(dir, "east");
	ASSERT_TRUE(sut->isPlaced());
}

TEST_F(ToyRobotFixture, ShouldRotateLeftRobot)
{
	ASSERT_FALSE(sut->isPlaced());
	sut->place(1, 1, "north");
	sut->rotate(ERotation::left);
	std::tie(x, y, dir) = sut->report();
	ASSERT_EQ(x, 1);
	ASSERT_EQ(y, 1);
	ASSERT_EQ(dir, "west");
	ASSERT_TRUE(sut->isPlaced());
}