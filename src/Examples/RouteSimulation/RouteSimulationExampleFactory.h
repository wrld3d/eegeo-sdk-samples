// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef __ExampleApp__RouteSimulationExampleFactory__
#define __ExampleApp__RouteSimulationExampleFactory__

#include "IExampleFactory.h"
#include "IExample.h"
#include "EegeoWorld.h"
#include "IRouteSimulationExampleViewFactory.h"

namespace Examples
{
class RouteSimulationExampleFactory : public IExampleFactory
{
	Eegeo::EegeoWorld& m_world;
	const IRouteSimulationExampleViewFactory& m_routeSimulationViewFactory;
	DefaultCameraControllerFactory& m_defaultCameraControllerFactory;
	Eegeo::Routes::Simulation::Camera::RouteSimulationGlobeCameraControllerFactory* m_pRouteSimulationGlobeCameraControllerFactory;

public:
	RouteSimulationExampleFactory(Eegeo::EegeoWorld& world,
	                              DefaultCameraControllerFactory& defaultCameraControllerFactory,
	                              const IRouteSimulationExampleViewFactory& routeSimulationViewFactory);

	~RouteSimulationExampleFactory();

	std::string ExampleName() const;

	IExample* CreateExample() const;
};
}


#endif /* defined(__ExampleApp__RouteSimulationExampleFactory__) */
