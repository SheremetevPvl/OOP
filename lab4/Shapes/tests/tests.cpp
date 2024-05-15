#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "..\..\Shapes\CBody.h"
#include "..\..\Shapes\CSphere.h"
#include "..\..\Shapes\CCone.h"
#include "..\..\Shapes\CParallelepiped.h"
#include "..\..\Shapes\CCylinder.h"
#include "..\..\Shapes\CBodyControl.h"
#include <iostream>

SCENARIO("check sphere")
{
	CSphere sphere(2.0, 10.0);
	REQUIRE(sphere.GetRadius() == 10.0);
	REQUIRE(sphere.GetDensity() == 2.0);
	REQUIRE(sphere.GetVolume() >= 4186.5);
	REQUIRE(sphere.GetVolume() <= 4189.0);
	REQUIRE(sphere.GetMass() >= 8373.3);
	REQUIRE(sphere.GetMass() <= 8379.34);
}

SCENARIO("check cone")
{
	CCone cone(10, 2, 4);
	REQUIRE(cone.GetBaseRadius() == 2);
	REQUIRE(cone.GetVolume() >= 16.7551);
	REQUIRE(cone.GetVolume() <= 16.7553);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetHeight() == 4);
	REQUIRE(cone.GetMass() >= 167.551);
	REQUIRE(cone.GetMass() <= 167.553);
}

SCENARIO("check parallelepiped")
{
	CParallelepiped cone(10, 2, 2, 2);
	REQUIRE(cone.GetVolume() == 8);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetHeight() == 2);
	REQUIRE(cone.GetWidth() == 2);
	REQUIRE(cone.GetDepth() == 2);
	REQUIRE(cone.GetMass() == 80);
}

SCENARIO("check cylinder")
{
	CCylinder cone(10, 2, 4);
	REQUIRE(cone.GetRadius() == 2);
	REQUIRE(cone.GetVolume() >= 50.2654);
	REQUIRE(cone.GetVolume() <= 50.2656);
	REQUIRE(cone.GetDensity() == 10);
	REQUIRE(cone.GetRadius() == 2);
	REQUIRE(cone.GetHeight() == 4);
	REQUIRE(cone.GetMass() >= 502.654);
	REQUIRE(cone.GetMass() <= 502.656);
}
