// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef __ExampleApp__Pick3DObjectExampleFactory__
#define __ExampleApp__Pick3DObjectExampleFactory__

#include "IExampleFactory.h"
#include "IExample.h"
#include "EegeoWorld.h"

namespace Examples
{
class Pick3DObjectExampleFactory : public IExampleFactory
{
	Eegeo::EegeoWorld& m_world;
	DefaultCameraControllerFactory& m_defaultCameraControllerFactory;

public:
	Pick3DObjectExampleFactory(Eegeo::EegeoWorld& world,
	                           DefaultCameraControllerFactory& defaultCameraControllerFactory);

	std::string ExampleName() const;

	IExample* CreateExample() const;
};
}


#endif /* defined(__ExampleApp__Pick3DObjectExampleFactory__) */
