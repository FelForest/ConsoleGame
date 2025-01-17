#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class Buffer
{
public:
	Buffer()
	{
	}
	Buffer(int row, int column, T defaultalue)
		: row(row), column(column)
	{
		buffer = new T[(row + 1) * column + 1];
		Set(defaultalue);
	}

	~Buffer()
	{
		delete[] buffer
	}

	const T& operator[](int index) const
	{
			return buffer[index];
	}

	T& operator[](int index)
	{
		return buffer[index];
	}

	void Set(T t)
	{
		memset(buffer, t, (row + 1) * column + 1);
		buffer[(row + 1) * column] = 0;
	}

	void Allocate(int row, int column, T defaultalue)
	{

		if (buffer != nullptr)
		{
			delete[] buffer;
		}

		buffer = new T[(row + 1) * column + 1];

		Set(defaultalue);
	}
private:
	// 가로 세로 크기
	int row;
	int column;
	T* buffer = nullptr;
};