#include <iostream>
#include <vector>
#include <algorithm>
#include "../Shapes/CBody.h"
#include "../Shapes/CCone.h"
#include "../Shapes/CCylinder.h"
#include "../Shapes/CParallelepiped.h"
#include "../Shapes/CSphere.h"
#include "../Shapes/CBodyControl.h"



//std::shared_ptr<CBody> FindLightestInWaterBody(const std::vector<std::shared_ptr<CBody>>& bodies)
//{
//    if (bodies.empty()) {
//        return nullptr;
//    }
//
//    auto compareMassInWater = [](const std::shared_ptr<CBody>& body1, const std::shared_ptr<CBody>& body2)
//        {
//            return ((body1->GetDensity() - WATER_DENSITY) * body1->GetVolume()) 
//                   < ((body2->GetDensity() - WATER_DENSITY) * body2->GetVolume());
//        };
//
//    auto heaviestBodyIterator = std::min_element(bodies.begin(), bodies.end(), compareMassInWater);
//
//    return *heaviestBodyIterator;
//}

int main()
{
    std::vector<std::shared_ptr<CBody>> bodies;


    CBodyControl bodiesControl(bodies, std::cin, std::cout);
    bodiesControl.ReadBodies();
    bodiesControl.WriteBodies();
    bodiesControl.WriteHaviestBody();
    bodiesControl.WriteLightestBodyInWater();

    return 0;
}