#include "CBodyControl.h"
#include "../Shapes/CSphere.h"
#include "../Shapes/CCone.h"
#include "../Shapes/CCylinder.h"
#include "../Shapes/CParallelepiped.h"
#include "../Shapes/CCompound.h"
#include <map>

const double WATER_DENSITY = 1000.0;

enum BodieType
{
    wrongType = -1,
    sphere = 0,
    parallelepiped = 1,
    cone = 2,
    cylinder = 3,
    compound = 4
};

CBodyControl::CBodyControl(std::vector<std::shared_ptr<CBody>>& bodies
    , std::istream& input
    , std::ostream& output)
    : m_bodies(bodies)
    , m_input(input)
    , m_output(output)
{
}

void CBodyControl::ReadBodies()
{
    char choise = 'y';
    while (!m_input.eof())
    {
        m_bodies.push_back(std::move(ReadSimpleBody()));
        m_output << "Continue? ('y' for continue): ";
        m_input >> choise;
        if (choise != 'y')
        {
            break;
        }
    };
}

void CBodyControl::WriteBodies()
{
    m_output << "Information about bodies:" << std::endl;
    for (const auto& body : m_bodies)
    {
        if (body != nullptr)
        {
            m_output << body->ToString() << std::endl;
        }
    }
}

std::vector<std::shared_ptr<CBody>> CBodyControl::ReadCompoundBody() const
{
    m_output << "You started entering compound body\n";
    char choise = 'y';
    std::vector<std::shared_ptr<CBody>> children;
    while (!m_input.eof())
    {
        children.push_back(std::move(ReadSimpleBody()));
        m_output << "Continue? ('y' for continue): ";
        m_input >> choise;
        if (choise != 'y')
        {
            m_output << "You ended entering last compound body\n";
            break;
        }
    };
    return children;
}

std::shared_ptr<CBody> CBodyControl::ReadSimpleBody() const
{
    std::string type;
    m_output << "Enter the type of body (sphere, parallelepiped, cone, cylinder): ";
    m_input >> type;
    std::map<std::string, BodieType> types{ {"sphere", BodieType::sphere }, {"parallelepiped", BodieType::parallelepiped}, {"cone", BodieType::cone}, 
                                            {"cylinder", BodieType::cylinder}, {"compound", BodieType::compound} };
    BodieType bodieType = BodieType::wrongType;
    if (types.count(type) > 0)
    {
        bodieType = types[type];
    }
    switch (bodieType)
    {
        double density, radius, length, width, height;
        case BodieType::sphere:
            m_output << "Enter the density: ";
            m_input >> density;
            m_output << "Enter the radius of the sphere: ";
            m_input >> radius;
            return std::make_shared<CSphere>(density, radius);
        case BodieType::parallelepiped:
            m_output << "Enter the density: ";
            m_input >> density;
            m_output << "Enter the length, width, and height of the parallelepiped: ";
            m_input >> length >> width >> height;
            return std::make_shared<CParallelepiped>(density, length, width, height);
        case BodieType::cone:
            m_output << "Enter the density: ";
            m_input >> density;
            m_output << "Enter the radius and height of the cone: ";
            m_input >> radius >> height;
            return std::make_shared<CCone>(density, radius, height);
        case BodieType::cylinder:
            m_output << "Enter the density: ";
            m_input >> density;
            m_output << "Enter the radius and height of the cone: ";
            m_input >> radius >> height;
            return std::make_shared<CCylinder>(density, radius, height);
        case BodieType::compound:
            return std::make_shared<CCompound>(ReadCompoundBody());
        default:
            m_output << "Invalid body type." << std::endl;
            return nullptr;
    }
}

void CBodyControl::WriteHaviestBody() const
{
    std::shared_ptr<CBody> heaviestBody = FindHeaviestBody();

    if (heaviestBody != nullptr)
    {
        m_output << "Heaviest body: " << heaviestBody->ToString() << std::endl;
    }
    else {
        m_output << "No bodies found." << std::endl;
    }
}

std::shared_ptr<CBody> CBodyControl::FindHeaviestBody() const
{
    if (m_bodies.empty()) {
        return nullptr;
    }

    auto compareMass = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
        {
            return body1->GetMass() < body2->GetMass();
        };

    auto heaviestBodyIterator = std::max_element(m_bodies.begin(), m_bodies.end(), compareMass);

    return *heaviestBodyIterator;
}

void CBodyControl::WriteLightestBodyInWater() const
{
    std::shared_ptr<CBody> lightestInWaterBody = FindLightestInWaterBody();

    if (lightestInWaterBody != nullptr)
    {
        m_output << "Lightest body in water: " << lightestInWaterBody->ToString() << std::endl;
    }
    else {
        m_output << "No bodies found." << std::endl;
    }
}

std::shared_ptr<CBody> CBodyControl::FindLightestInWaterBody() const
{
    if (m_bodies.empty()) {
        return nullptr;
    }

    auto compareMassInWater = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
        {
            return ((body1->GetMass() - body1->GetVolume() * WATER_DENSITY) 
                   < (body2->GetMass() - body2->GetVolume() * WATER_DENSITY));
        };

    auto lighestBodyIterator = std::min_element(m_bodies.begin(), m_bodies.end(), compareMassInWater);

    return *lighestBodyIterator;
}