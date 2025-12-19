#pragma once
#include <vector>

namespace GLG
{
	template<typename T>
	auto dot_product2D(const T& t1, const T& t2)
	{
		return t1.a * t2.a + t1.b * t2.b;
	}

	template<typename T>
	auto dot_product3D(const T& t1, const T& t2)
	{
		return t1.a * t2.a + t1.b * t2.b + t1.c * t2.c;
	}

	template<typename T, typename P>
	auto cross_product2D(const T& t1, const T& t2)
	{
		P result;

		result.x = t1.b * t2.c - t1.c * t2.b;
		result.y = -(t1.a * t2.c - t1.c * t2.a);

		return result;
	}

	template<typename T, typename P>
	auto cross_product3D(const T& t1, const T& t2)
	{
		P result;

		result.x = t1.b * t2.c - t1.c * t2.b;
		result.y = -(t1.a * t2.c - t1.c * t2.a);
		result.z = t1.a * t2.b - t1.b * t2.a;

		return result;
	}

	template<typename T>
	auto matrixAdd(const T& m1, const T& m2)
	{
		size_t row = m1.size();
		size_t col = m2[0].size();

		T result = m1;

		for (size_t i = 0; i < row; ++i)
			for (size_t j = 0; j < col; ++j)
				result[i][j] = m1[i][j] + m2[i][j];

		return result;
	}
}