#include "Deltatime.h"

namespace Glib
{
	DeltaTime::DeltaTime()
		: m_lastFrameTime(std::chrono::high_resolution_clock::now())
		, m_delta(0.0f)
		, m_fps(0.0f)
	{
	}

	void DeltaTime::Start() const
	{
		m_lastFrameTime = std::chrono::high_resolution_clock::now();
	}

	void DeltaTime::End() const
	{
		auto endFrame = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> deltaDuration = endFrame - m_lastFrameTime;

		if (deltaDuration.count() < DT)
		{
			std::chrono::duration<float> sleepDuration(DT - deltaDuration.count());
			std::this_thread::sleep_for(sleepDuration);

			endFrame = std::chrono::high_resolution_clock::now();
			deltaDuration = endFrame - m_lastFrameTime;
		}

		m_delta = deltaDuration.count();
		m_fps = 1.0f / m_delta;
	}

	float DeltaTime::GetDT() const
	{
		return m_delta;
	}

	float DeltaTime::GetFPS() const
	{
		return m_fps;
	}

}