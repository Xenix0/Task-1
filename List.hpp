#pragma once
#include "List.h"
#include <stdexcept>

template <typename T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
List<T>::~List() {
	clear();
}

template <typename T>
void List<T>::clear() {
	Node<T>* current = this->head;

	while (current) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
	this->head = nullptr;
	this->tail = nullptr;
}

template <typename T>
void List<T>::create_list(unsigned size) {
	clear();

	if (size == 0) return;


	head = new Node<T>();
	Node<T>* cabanchik = head;

	for (unsigned i = 1; i < size; i++) {
		Node<T>* new_node = new Node<T>();
		cabanchik->next = new_node;
		new_node->prev = cabanchik;
		cabanchik = new_node;
	}
	tail = cabanchik;
}

template <typename T>
void List<T>::add_to_list(const T& data) {
	Node<T>* new_node = new Node<T>(data);

	if (!head) {
		head = tail = new_node;
		return;
	}

	tail->next = new_node;
	new_node->prev = tail;
	tail = new_node;
}

template <typename T>
void List<T>::remove_from_list(unsigned index) {
	if (!head) return;

	Node<T>* current = head;
	for (unsigned i = 0; current && i < index; ++i)
		current = current->next;

	if (!current) return;

	if (current->prev)
		current->prev->next = current->next;
	else {
		head = current->next;
	}
		
	if (current->next)
		current->next->prev = current->prev;
	else {
		tail = current->prev;
	}

	delete current;
}

template <typename T>
Node<T>* List<T>::get_element(unsigned index) {
	Node<T>* current = head;
	for (unsigned i = 0; current && i < index; ++i)
		current = current->next;
	return current;
}

template <typename T>
bool List<T>::empty() {
	return this->head == nullptr;
}