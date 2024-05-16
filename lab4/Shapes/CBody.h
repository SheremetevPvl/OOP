#pragma once
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#define _USE_MATH_DEFINES

class CBody
{
public:
	CBody(const std::string& type, double density);
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	virtual double GetDensity() const = 0;
	std::string ToString() const;
	virtual ~CBody() = default;
private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
    double m_density;
	std::string m_type;
};