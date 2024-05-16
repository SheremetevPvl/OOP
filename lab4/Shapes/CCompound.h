#pragma once
#include "../Shapes/CBody.h"
#include <vector>
class CCompound: public CBody
{
public:
	//CCompound() = default;
	CCompound(std::vector<std::shared_ptr<CBody>>);
	bool AddChildBody(std::shared_ptr<CBody> child);
	double GetVolume() const override;
	double GetDensity() const override;
	double GetMass() const override;
private:
	std::vector<std::shared_ptr<CBody>> m_childs;
	void AppendProperties(std::ostream& strm) const override;
};