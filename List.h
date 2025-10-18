#pragma once
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* prev;
	Node<T>* next;

	Node(const T& value = T()) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List
{
protected:
 
	Node<T>* head;
	Node<T>* tail;

public:
	List();
	~List();

	void create_list(unsigned size);
	void add_to_list(const T& data);
	void remove_from_list(unsigned index);
	Node<T>* get_element(unsigned index);
	void clear();
	bool empty();
};
#include "List.hpp"