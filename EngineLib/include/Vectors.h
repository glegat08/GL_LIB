#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

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
			m_data.push_back({ row, col });
		}

		Matrix(std::initializer_list<int> list)
		{
			int totalElements = list.size();
			int dimension = static_cast<int>(std::sqrt(totalElements));

			if (dimension * dimension != totalElements)
				throw std::invalid_argument("Initializer list size must be a perfect square");

			m_row = dimension;
			m_col = dimension;
			m_data.resize(m_row, std::vector<int>(m_col, 0));
			auto it = list.begin();

			for (int i = 0; i < m_row; ++i)
			{
				for (int j = 0; j < m_col; ++j)
				{
					m_data[i][j] = *it++;
				}
			}
		}

		~Matrix()
		{
			m_data.clear();
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

		int GetRow(const Matrix& m)
		{
			return m.m_row;
		}

		int GetCol(const Matrix& m)
		{
			return m.m_col;
		}

	private:
		std::vector<std::vector<int>> m_data;
		mutable int m_row, m_col;
	};
}