#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class dynamic_array
{
private:
	T* data;
	unsigned size;
	unsigned capacity;

	void resize(unsigned new_capacity);

public:
	dynamic_array();
	~dynamic_array();

	void push_back(const T& value);
	void pop_back();
	T& operator[](unsigned index);

	unsigned get_size();
	bool empty();
	void clear();

};
#include "dynamic_array.hpp"
