#include "../Shapes/CBody.h"
#include <vector>
#include <iomanip> 
#include <math.h>
#define _USE_MATH_DEFINES
const double GAIN = 9.8;


CBody::CBody(const std::string& type, double density)
	: m_density(density)
	, m_type(type)
{
}

//double CBody::GetDensity()const
//{
//	return m_density;
//}
//
//double CBody::GetMass()const
//{
//	return GetVolume() * GetDensity();
//}


std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}