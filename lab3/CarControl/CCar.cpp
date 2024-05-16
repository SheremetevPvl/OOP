#include "../CarControl/CCar.h";

bool Car::IsTurnedOn()const
{
	return m_isOn;
}

Gear Car::GetGear()const
{
	return m_gear;
}

unsigned int Car::GetSpeed()const
{
	return m_speed;
}

MoveDirection Car::GetDirection()const
{
	return m_direction;
}

bool Car::TurnOnEngine()
{
	if (!m_isOn)
	{
		m_isOn = true;
	}
	return true;
};

bool Car::TurnOffEngine()
{
	if (!m_isOn)
	{
		return true;
	}
	else
	{
		if (m_gear == Gear::neutral && m_speed == 0)
		{
			m_isOn = false;
			return true;
		}
		return false;
	}
}

bool Car::CheckCorrectSwitch(Gear gear)                         
{
	if (m_gear == Gear::backMove && m_speed != 0)
	{
		return false;
	}
	if (m_gear == Gear::neutral && m_direction == MoveDirection::backward)
	{
		return false;
	}
	std::pair<unsigned int, unsigned int> limits(SpeedLim[gear]);
	unsigned int min(limits.first), max(limits.second);
	switch (gear)
	{
	case Gear::first:
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		break;
	case Gear::second:
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		break;
	case Gear::third:
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		break;
	case Gear::fourth:
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		break;
	case Gear::fifth:
		if (m_speed >= min && m_speed <= max)
		{
			m_gear = gear;
			return true;
		}
		break;
	}
	return false;
	/*if (m_gear == Gear::neutral)
	{
		if (m_direction != MoveDirection::backward)
		{
			m_gear = gear;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		switch (gear)
		{ 
		case Gear::first:
			if (m_speed >= SpeedLimits.firstMin && m_speed <= SpeedLimits.firstMax && m_gear != Gear::backMove)
			{
				m_gear = gear;
				return true;
			}
			else
			{
				return false;
			}
		case Gear::second:
			if (m_speed >= SpeedLimits.secondMin && m_speed <= SpeedLimits.secondMax && m_gear != Gear::backMove)
			{
				m_gear = gear;
				return true;
			}
			else
			{
				return false;
			}
		case Gear::third:
			if (m_speed >= SpeedLimits.thirdMin && m_speed <= SpeedLimits.thirdMax && m_gear != Gear::backMove)
			{
				m_gear = gear;
				return true;
			}
			else
			{
				return false;
			}
		case Gear::fourth:
			if (m_speed >= SpeedLimits.fourthMin && m_speed <= SpeedLimits.fourthMax && m_gear != Gear::backMove)
			{
				m_gear = gear;
				return true;
			}
			else
			{
				return false;
			}
		case Gear::fifth:
			if (m_speed >= SpeedLimits.fifthMin && m_speed <= SpeedLimits.fifthMax && m_gear != Gear::backMove)
			{
				m_gear = gear;
				return true;
			}
			else
			{
				return false;
			}
		}
	}*/
}

bool Car::SetGear(Gear gear)
{
	if (m_isOn)
	{
		if (gear == m_gear)
		{
			return true;
		}
		else
		{
			switch (gear)
			{
			case Gear::backMove:
				if (m_speed == 0)
				{
					m_gear = gear;
					return true;
				}
				break;
			case Gear::neutral:
				m_gear = gear;
				return true;
			case Gear::first:
				return CheckCorrectSwitch(gear);
			case Gear::second:
				return CheckCorrectSwitch(gear);
			case Gear::third:
				return CheckCorrectSwitch(gear);
			case Gear::fourth:
				return CheckCorrectSwitch(gear);
			case Gear::fifth:
				return CheckCorrectSwitch(gear);
			}
			return false;
		}
	}
	else
	{
		if (gear == Gear::neutral)
		{
			m_gear = Gear::neutral;
			return true;
		}
		return false;
	}
}

bool Car::SetSpeed(unsigned int speed)
{
	if (m_isOn)
	{
		if (m_gear == Gear::neutral)
		{
			if (speed < m_speed)
			{
				m_speed = speed;
				if (speed == 0)
				{
					m_direction = MoveDirection::standing_still;
				}
				return true;
			}
			return false;
		}
		else
		{
			std::pair<unsigned int, unsigned int> limits(SpeedLim[m_gear]);
			unsigned int min(limits.first), max(limits.second);
			switch (m_gear)
			{
			case Gear::backMove:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					if (speed == 0)
					{
						m_direction = MoveDirection::standing_still;
					}
					else
					{
						m_direction = MoveDirection::backward;
					}
					return true;
				}
				break;
			case Gear::first:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					if (speed == 0)
					{
						m_direction = MoveDirection::standing_still;
					}
					else
					{
						m_direction = MoveDirection::forward;
					}
					return true;
				}
				break;
			case Gear::second:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					m_direction = MoveDirection::forward;
					return true;
				}
				break;
			case Gear::third:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					m_direction = MoveDirection::forward;
					return true;
				}
				break;
			case Gear::fourth:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					m_direction = MoveDirection::forward;
					return true;
				}
				break;
			case Gear::fifth:
				if (speed >= min && speed <= max)
				{
					m_speed = speed;
					m_direction = MoveDirection::forward;
					return true;
				}
				break;
			}
			return false;
		}
	}
	return false;
}