// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "CameraSplineExampleFactory.h"
#include "CameraSplineExample.h"
#include "EegeoWorld.h"
#include "GlobeCameraController.h"
#include "ResourceCeilingProvider.h"

#include "MapModule.h"

using namespace Examples;

CameraSplineExampleFactory::CameraSplineExampleFactory(Eegeo::EegeoWorld& world,
                                                       DefaultCameraControllerFactory& defaultCameraControllerFactory)
: m_world(world)
, m_defaultCameraControllerFactory(defaultCameraControllerFactory)
{
    
}

IExample* CameraSplineExampleFactory::CreateExample() const
{
    Eegeo::Modules::Map::MapModule& mapModule = m_world.GetMapModule();
    
	return new Examples::CameraSplineExample(m_world,
                                             m_defaultCameraControllerFactory.Create(),
                                             mapModule.GetResourceCeilingProvider());
}

std::string CameraSplineExampleFactory::ExampleName() const
{
	return Examples::CameraSplineExample::GetName();
}
