#pragma once
#include "../Shapes/CBody.h"

class CCylinder final : public CBody
{
public:
	CCylinder(double radius, double density, double height);
	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;
	double GetDensity() const override;
	double GetMass() const override;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius, m_height, m_density;
};