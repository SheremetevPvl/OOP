#pragma once
#include <map>

enum class Gear
{
	backMove = -1,
	neutral = 0,
	first = 1,
	second = 2,
	third = 3,
	fourth = 4,
	fifth = 5
};

enum class MoveDirection {forward, backward, standing_still};

class Car
{
public:
	    bool IsTurnedOn()const;
		Gear GetGear()const;
		unsigned int GetSpeed()const;
		MoveDirection GetDirection()const;
	    bool TurnOnEngine();
		bool TurnOffEngine();
		bool SetGear(Gear gear);
		bool SetSpeed(unsigned int speed);
private:
	    Gear m_gear = Gear::neutral;
		unsigned int m_speed = 0;
		bool m_isOn = false;
		MoveDirection m_direction = MoveDirection::standing_still;
		bool CheckCorrectSwitch(Gear gear);
		std::map<Gear, std::pair<unsigned int, unsigned int>> SpeedLim
		{
			{Gear::backMove, {0, 20}},
			{Gear::first, {0, 30}},
			{Gear::second, {20, 50}},
			{Gear::third, {30, 60}},
			{Gear::fourth, {40, 90}},
			{Gear::fifth, {50, 150}}
		};
};