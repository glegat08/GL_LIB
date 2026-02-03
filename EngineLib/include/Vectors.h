#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Random.h"

namespace Glib
{
	struct Vec2
	{
		float x, y;
	};

	struct Vec3
	{
		Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
		float x, y, z;
	};

	class Matrix
	{
	public:
		Matrix() = default;

		Matrix(int row, int col)
			: m_row(row) , m_col(col)
		{
			m_data.resize(row, std::vector<int>(col, 0));
		}

		Matrix(std::initializer_list<std::initializer_list<int>> list)
		{
			m_row = list.size();
			m_col = list.begin()->size();

			for (const auto& row : list)
			{
				if (row.size() != m_col)
					throw std::invalid_argument("Rows must have the same size");
			}

			m_data.resize(m_row);
			int i = 0;
			for (const auto& row : list)
				m_data[i++] = std::vector<int>(row);
		}

		void Dimension()
		{
			m_row = m_data.size();
			m_col = m_data[0].size();
		}

		void Coefficient(int row, int col, int& value) const
		{
			if (row < 0 || row >= m_data.size() || col < 0 || col >= m_data[0].size())
				throw std::out_of_range("Index out of range");

			value = m_data[row][col];
		}

		void MatrixAddition(const Matrix& other)
		{
			if (m_row != other.m_row || m_col != other.m_col)
				throw std::invalid_argument("Matrices must have the same dimensions for addition");

			for (int i = 0; i < m_row; ++i)
				for (int j = 0; j < m_col; ++j)
					m_data[i][j] += other.m_data[i][j];
		}

		void ScalarMultiply(int scalar)
		{
			for (auto& row : m_data)
				for (auto& elem : row)
					elem *= scalar;
		}

		void Print() const
		{
			for (const auto& row : m_data)
			{
				for (const auto& elem : row)
					std::cout << elem << " ";

				std::cout << std::endl;
			}
		}
		 
		void MultiplyMatrix(const Matrix& other)
		{
			if (m_col != other.m_row)
				throw std::invalid_argument("Incompatible dimensions for matrix multiplication");

			Matrix result(m_row, other.m_col);
			for (int i = 0; i < m_row; ++i)
			{
				for (int j = 0; j < other.m_col; ++j)
				{
					result.m_data[i][j] = 0;
					for (int k = 0; k < m_col; ++k)
					{
						result.m_data[i][j] += m_data[i][k] * other.m_data[k][j];
					}
				}
			}

			*this = result;
		}

		void Idenity()
		{
			for (int i = 0; i < m_row; ++i)
			{
				for (int j = 0; j < m_col; ++j)
				{
					if (i == j)
						m_data[i][j] = 1;
					else
						m_data[i][j] = 0;
				}
			}
		}

		void RandomMatrix(Random& rng, int min, int max)
		{
			for (auto& row : m_data)
				for (auto& elem : row)
					elem = rng.get(min, max);
		}


		int GetRow()
		{
			return m_row;
		}

		int GetCol()
		{
			return m_col;
		}

	private:
		std::vector<std::vector<int>> m_data;
		int m_row, m_col;
	};

	//template<typename T>
	//class Matrix
	//{
	//public:
	//	Matrix(int row, int col) : m_row(row), m_col(col)
	//	{
	//		m_data = new  T[row * col];

	//		for (int i = 0; i < row * col; ++i)
	//			m_data[i] = T();
	//	}

	//	void Size() const
	//	{
	//		return m_data.size();
	//	}



	//private:
	//	int m_row, m_col;
	//	std::vector<std::vector<T>> m_data;
	//};
}