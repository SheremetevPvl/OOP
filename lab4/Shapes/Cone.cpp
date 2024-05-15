#define _USE_MATH_DEFINES
#include "../Shapes/CCone.h";

double tempDensity;

CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density)
	, m_radius(radius)
	, m_height(height)
{
	tempDensity = density;
}
double CCone::GetBaseRadius()const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (1.0 / 3.0) * M_PI * pow(m_radius, 2) * m_height;
}

void CCone::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}

double CCone::GetDensity()const
{
	return tempDensity;
}

double CCone::GetMass()const
{
	return GetVolume() * GetDensity();
}