#pragma once
#include "List.h"
#include <exception>

template <typename T>
class Stack : private List<T> {
public:
	void push(const T& value) {
		T copy = value;
		this->add_to_list(copy);
	}
	void pop() {
		if (this->empty()) return;
		Node<T>* current = this->head;
		unsigned count = 0;
		while (current) {
			current = current->next;
			++count;
		}
		this->remove_from_list(count - 1);
	}
	T top() {
		if (this->empty())
			throw std::out_of_range("Стек пустой!");
		return this->tail->data;
	}
	bool empty() {
		return List<T>::empty();
	}
};