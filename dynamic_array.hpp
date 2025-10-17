#pragma once
#include "dynamic_array.h"

template <typename T>
dynamic_array<T>::dynamic_array() {
	size = 0;
	capacity = 4;
	data = new T[capacity];
}


template <typename T>
dynamic_array<T>::~dynamic_array() {
	delete[] data;
}

template <typename T>
void dynamic_array<T>::resize(unsigned new_capacity) {
	T* new_data = new T[new_capacity];
	for (unsigned i = 0; i < size; ++i)
		new_data[i] = data[i];
	delete[] data;
	data = new_data;
	capacity = new_capacity;
}

template <typename T>
void dynamic_array<T>::push_back(const T& value) {
	if (size >= capacity)
		resize(capacity * 2);
	data[size++] = value;
}

template <typename T>
void dynamic_array<T>::pop_back() {
	if (size == 0)
		throw std::out_of_range("Dinamic array is empty!");
	size--;
}

template <typename T>
T& dynamic_array<T>::operator[](unsigned index) {
	if (index >= size)
		throw std::out_of_range("Index out of range!");
	return data[index];
}

template <typename T>
unsigned dynamic_array<T>::get_size() {
	return size;
}

template <typename T>
bool dynamic_array<T>::empty() {
		return size == 0;
}

template <typename T>
void dynamic_array<T>::clear() {
	size = 0;
}