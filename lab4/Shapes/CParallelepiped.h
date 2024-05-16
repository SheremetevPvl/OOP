#pragma once
#include "../Shapes/CBody.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double length, double width, double height, double density);
	double GetVolume() const override;
	double GetDepth() const;
	double GetWidth() const;
	double GetHeight() const;
	double GetDensity() const override;
	double GetMass() const override;
private:
	void AppendProperties(std::ostream& strm) const override;
	double m_depth, m_width, m_height, m_density;
};