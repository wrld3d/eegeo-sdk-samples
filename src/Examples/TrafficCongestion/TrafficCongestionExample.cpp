// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "EegeoWorld.h"
#include "TrafficCongestionExample.h"
#include <string>

namespace
{
const std::string congestionLevelNames[] = {"Light", "Normal", "Heavy", "GridLock"};
const int RoadId = 0;
const float NumSecondsEachCongestion = 5.f;
}

namespace Examples
{
TrafficCongestionExample::TrafficCongestionExample(Eegeo::TrafficCongestion::ITrafficCongestionService& trafficCongestionService,
        Eegeo::Camera::GlobeCamera::GlobeCameraController* pCameraController)
	: m_trafficCongestionService(trafficCongestionService)
	, m_timeAccumulator(5.f)
	, m_congestionValue(static_cast<int>(Eegeo::TrafficCongestion::CongestionLevel::Light))
	, m_key(Eegeo::Streaming::MortonKey::CreateFromString("01131232132001"))
    , m_pCameraController(pCameraController)
	, m_globeCameraStateRestorer(*pCameraController)
{

}

void TrafficCongestionExample::Suspend()
{
	m_trafficCongestionService.SetCongestionFor(
            m_key,
	        RoadId,
	        Eegeo::TrafficCongestion::CongestionLevel::Normal);
    
    delete m_pCameraController;
    m_pCameraController = NULL;
}

void TrafficCongestionExample::Update(float dt)
{
	if(m_timeAccumulator > NumSecondsEachCongestion)
	{
		Eegeo::TrafficCongestion::CongestionLevel::CongestionLevelValues congestionLevel =
		    static_cast<Eegeo::TrafficCongestion::CongestionLevel::CongestionLevelValues>(m_congestionValue);

		m_trafficCongestionService.SetCongestionFor(
                m_key,
                RoadId,
                congestionLevel);

		Eegeo_TTY(
                "Congestion level %s set on road id %d for morton key %s\n",
                congestionLevelNames[m_congestionValue].c_str(),
                RoadId,
                m_key.ToString().c_str());

		if(++m_congestionValue > Eegeo::TrafficCongestion::CongestionLevel::Gridlock)
		{
			m_congestionValue = 0;
		}

		m_timeAccumulator -= NumSecondsEachCongestion;
	}

	m_timeAccumulator += dt;
}
    
const Eegeo::Camera::RenderCamera& TrafficCongestionExample::GetRenderCamera() const
{
    return *m_pCameraController->GetCamera();
}

Eegeo::dv3 TrafficCongestionExample::GetInterestPoint() const
{
    return m_pCameraController->GetEcefInterestPoint();
}
}
