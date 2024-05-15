#pragma once
#include "../Shapes/CBody.h"

class CSphere final : public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	double GetVolume() const override;
	double GetDensity() const override;
	double GetMass() const override;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius, m_density;
};