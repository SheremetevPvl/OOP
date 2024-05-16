#define CATCH_CONFIG_MAIN
#include "../../../../../OOP/catch/catch.hpp";
#include "../CCar.h";

Car car;

SCENARIO("engine is turned off by deafault")
{
	CHECK(!car.IsTurnedOn());
}

SCENARIO("engine can be turned off when it`s already turned off")
{
	bool res = car.TurnOffEngine();
	REQUIRE(res);
	CHECK(!car.IsTurnedOn());
}

SCENARIO("engine can be turned on")
{
	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());
}

SCENARIO("engine can be turned on when it`s already turned on")
{
	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());
}

//если движение не было начато у машины изначально правильные условия для выключения двигателя
SCENARIO("engine can be turned off with right conditions")
{
	bool res = car.TurnOffEngine();
	REQUIRE(res);
	CHECK(!car.IsTurnedOn());
}

SCENARIO("when engine is off we can switch only on neutral")
{
	car.TurnOffEngine();
	bool res = car.SetGear(Gear::neutral);
	REQUIRE(res);
	res = car.SetGear(Gear::fifth);
	REQUIRE(!res);
	res = car.SetGear(Gear::backMove);
	CHECK(!res);
}

SCENARIO("when engine is on and speed = 0 we can switch only on back gear, neutral or first gear")
{
	bool engine = car.TurnOnEngine();
	REQUIRE(engine);
	bool res = car.SetGear(Gear::backMove);
	CHECK(res);
	res = car.SetGear(Gear::neutral);
	CHECK(res);
	res = car.SetGear(Gear::first);
	CHECK(res);
	res = car.SetGear(Gear::fourth);
	CHECK(!res);
	res = car.SetGear(Gear::neutral);
	CHECK(res);
}

SCENARIO("engine can`t be turned off not on neutral gear")
{
	car.TurnOnEngine();
	car.SetGear(Gear::first);
	bool res = car.TurnOffEngine();
	CHECK(!res);
	CHECK(car.IsTurnedOn());
	car.SetGear(Gear::neutral);
	car.TurnOffEngine();
	CHECK(!car.IsTurnedOn());
}

SCENARIO("when engine is off speed can`t be changed")
{
	bool res = car.SetSpeed(10);
	CHECK(!res);
	res = car.SetSpeed(0);
	CHECK(!res);
}

SCENARIO("backmove gear can only be used with speed = 0")
{
	car.TurnOnEngine();
	car.SetGear(Gear::first);
	REQUIRE(car.GetGear() == Gear::first);
	car.SetSpeed(10);
	REQUIRE(car.GetSpeed() == 10);
	bool res = car.SetGear(Gear::backMove);
	CHECK(!res);
	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);
	res = car.SetGear(Gear::backMove);
	CHECK(res);
	car.SetGear(Gear::neutral);
	car.TurnOffEngine();
}

SCENARIO("backmove gear can`t be used on neutral gear and back move direction")
{
	car.TurnOnEngine();
	car.SetGear(Gear::backMove);
	car.SetSpeed(10);
	REQUIRE(car.GetDirection() == MoveDirection::backward);
	car.SetGear(Gear::neutral);
	REQUIRE(car.GetGear() == Gear::neutral);
	bool res = car.SetGear(Gear::backMove);
	CHECK(!res);
	car.SetSpeed(0);
	car.TurnOffEngine();
}

SCENARIO("forward move gear can`t be used on backmove gear with speed <> 0")
{
	car.TurnOnEngine();
	car.SetGear(Gear::backMove);
	car.SetSpeed(10);
	REQUIRE(car.GetGear() == Gear::backMove);
	bool res = car.SetGear(Gear::first);
	CHECK(!res);
	car.SetSpeed(0);
	res = car.SetGear(Gear::first);
	CHECK(res);
	car.TurnOffEngine();
}

SCENARIO("forward move gear can`t be used on neutral gear with back move direction")
{
	car.TurnOnEngine();
	car.SetGear(Gear::backMove);
	car.SetSpeed(10);
	REQUIRE(car.GetGear() == Gear::backMove);
	bool res = car.SetGear(Gear::neutral);
	REQUIRE(car.GetDirection() == MoveDirection::backward);
	res = car.SetGear(Gear::first);
	CHECK(!res);
	car.SetSpeed(0);
	res = car.SetGear(Gear::first);
	REQUIRE(car.GetDirection() == MoveDirection::standing_still);
	CHECK(res);
	car.TurnOffEngine();
}

SCENARIO("gears can`t be set with wrong speed diapazon")
{
	car.TurnOnEngine();
	car.SetGear(Gear::first);
	car.SetSpeed(10);
	REQUIRE(car.GetGear() == Gear::first);
	
	bool res = car.SetGear(Gear::second);
	CHECK(!res);
	res = car.SetGear(Gear::third);
	CHECK(!res);
	res = car.SetGear(Gear::fourth);
	CHECK(!res);
	res = car.SetGear(Gear::fifth);
	CHECK(!res);

	car.SetSpeed(20);
	REQUIRE(car.GetSpeed() == 20);
	res = car.SetGear(Gear::second);
	CHECK(res);

	car.SetSpeed(50);
	REQUIRE(car.GetSpeed() == 50);
	res = car.SetGear(Gear::third);
	CHECK(res);
	res = car.SetGear(Gear::fourth);
	CHECK(res);
	res = car.SetGear(Gear::fifth);
	CHECK(res);

	car.SetGear(Gear::neutral);
	car.SetSpeed(0);
	car.TurnOffEngine();
}

SCENARIO("speed can be changed only in gear speed diapazon")
{
	car.TurnOnEngine();
	car.SetGear(Gear::backMove);
	bool res = car.SetSpeed(10);
	CHECK(res);
	REQUIRE(car.GetSpeed() == 10);
	res = car.SetSpeed(20);
	CHECK(res);
	REQUIRE(car.GetSpeed() == 20);
	res = car.SetSpeed(30);
	CHECK(!res);
	car.SetSpeed(0);
	car.SetGear(Gear::first);
	res = car.SetSpeed(50);
	CHECK(!res);
	car.SetGear(Gear::neutral);
	car.TurnOffEngine();
}

SCENARIO("negative speed can`t be used")
{
	car.TurnOnEngine();
	car.SetGear(Gear::first);
	bool res = car.SetSpeed(-20);
	CHECK(!res);
	car.SetGear(Gear::neutral);
	car.TurnOffEngine();
}

SCENARIO("on neutral gear speed can be only reduced")
{
	car.TurnOnEngine();
	car.SetGear(Gear::first);
	car.SetSpeed(20);
	car.SetGear(Gear::neutral);
	REQUIRE(car.GetGear() == Gear::neutral);
	bool res = car.SetSpeed(30);
	CHECK(!res);
	res = car.SetSpeed(10);
	CHECK(res);
	car.SetSpeed(0);
	car.SetGear(Gear::neutral);
	car.TurnOffEngine();
}