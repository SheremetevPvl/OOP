#include <math.h>
#define _USE_MATH_DEFINES
#include "../Shapes/CSphere.h";

CSphere::CSphere(double density, double radius)
	: CBody("Sphere", density)
	, m_radius(radius)
	, m_density(density)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

void CSphere::AppendProperties(std::ostream& strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl;
}

double CSphere::GetDensity()const
{
	return m_density;
}

double CSphere::GetMass()const
{
	return GetVolume() * GetDensity();
}