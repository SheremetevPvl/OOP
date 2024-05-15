#pragma once
#include "../Shapes/CBody.h"

class CCone final : public CBody
{
public:
	CCone(double density, double radius, double height);

	double GetBaseRadius() const;
	double GetVolume() const override;
	double GetHeight() const;
	double GetDensity() const override;
	double GetMass() const override;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius, m_height;
};