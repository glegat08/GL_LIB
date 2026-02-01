#pragma once
#include <chrono>
#include <thread>

namespace Glib
{
	constexpr float FPS = 60.0f;
	constexpr float DT = 1.0f / FPS;

	class DeltaTime
	{
	public:
		DeltaTime();

		void Start() const;
		void End() const;

		float GetDT() const;
		float GetFPS() const;

	private:
		mutable std::chrono::high_resolution_clock::time_point m_lastFrameTime;
		mutable float m_delta;
		mutable float m_fps;
	};
}