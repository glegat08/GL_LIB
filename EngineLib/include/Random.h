#pragma once
#include <random>

namespace Glib
{
	class Random
	{
	public:
		Random() : m_eng(m_rd()) {}

        template<typename T>
        T get(T min, T max)
        {
            if constexpr (std::is_integral_v<T>)
            {
                std::uniform_int_distribution<T> dist(min, max);
                return dist(m_eng);
            }
            else
            {
                std::uniform_real_distribution<T> dist(min, max);
                return dist(m_eng);
            }
        }
	
	private:
		std::random_device m_rd;
		std::mt19937 m_eng;
	};
}
