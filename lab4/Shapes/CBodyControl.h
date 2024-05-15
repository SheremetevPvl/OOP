#pragma once

#include <vector>
#include <memory>
#include "../Shapes/CBody.h"

class CBodyControl
{
public:
	CBodyControl(std::vector<std::shared_ptr<CBody>>& bodies
		, std::istream& input
		, std::ostream& output);
	void ReadBodies();
	void WriteBodies();
	void WriteHaviestBody() const;
	void WriteLightestBodyInWater() const;
private:
	std::shared_ptr<CBody> ReadSimpleBody() const;
	std::vector<std::shared_ptr<CBody>> ReadCompoundBody() const;
	std::shared_ptr<CBody> FindHeaviestBody() const;
	std::shared_ptr<CBody> FindLightestInWaterBody() const;
	std::vector<std::shared_ptr<CBody>>& m_bodies;
	std::istream& m_input;
	std::ostream& m_output;

};