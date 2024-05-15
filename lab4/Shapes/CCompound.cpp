#include "../Shapes/CCompound.h"

CCompound::CCompound(std::vector<std::shared_ptr<CBody>> children)
	: CBody("Compound", GetDensity())
	, m_childs(children)
{
}

bool CCompound::AddChildBody(std::shared_ptr<CBody> child) {
	m_childs.push_back(child);
	return true;
}

double CCompound::GetVolume() const
{
	double totalVolume = 0;
	for (const auto& child : m_childs) 
	{
		totalVolume += child->GetVolume();
	}
	return totalVolume;
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

double CCompound::GetMass() const
{
	double totalMass = 0;
	for (const auto& part : m_childs)
	{
		totalMass += part->GetMass();
	}
	return totalMass;
}

double CCompound::GetDensity() const
{
	double totalMass = 0;
	for (const auto& part : m_childs)
	{
		totalMass += part->GetMass();
	};
	double totalVolume = 0;
	for (const auto& child : m_childs) {
		totalVolume += child->GetVolume();
	};
	return totalMass / totalVolume;
}

void CCompound::AppendProperties(std::ostream& strm) const
{
	return;
}