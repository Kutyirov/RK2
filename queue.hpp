#pragma once
#include <iostream>
template <typename T>
struct Node {
	T data;
	Node<int>* next;
};

template <typename T>

class Queue {
private:
	Node<int>* front;
	Node<int>* back;
public:
	Queue();

	Queue(std::initializer_list<T>);

	Queue(const Queue&);

	auto swap(Queue&) -> void;

	auto operator=(const Queue&) -> Queue&;

	auto empty() const -> bool;

	auto size() const->size_t;

	auto push(T) -> void;

	auto pop() -> void;

	auto front_()->T&;

	auto back_() const->T&;

	bool operator==(const Queue&);

	
	friend auto operator<<(std::ostream& output, Queue<T>& q)->std::ostream&
   	{
        	for (Node<T> * p = q.list->first; p != nullptr; p = p->next) {
            		output << p->data;
            		if (p->next != nullptr) {
                		output << " ";
            		}
            	}
            	return output;
        }
        
	friend auto operator >> (std::istream& input, Queue<T>& q)->std::istream& {
        	T value;
                input >> value;
                q.push(value);
                return input;
        }

	~Queue();

	
};

template<typename T>
Queue<T>::Queue()
{
	front = nullptr;
	back = nullptr;
}

template<typename T>
Queue<T>::Queue(std::initializer_list<T> list)
{
	for (auto &item : list) {
		this->push(item);
	}
}

template<typename T>
Queue<T>::Queue(const Queue & q)
{
	Node<int>* p = q.front;
	while (p != nullptr) {
		this->push(p->data);
		p = p->next;
	}
}

template<typename T>
auto Queue<T>::swap(Queue & q) -> void
{
	Queue<T> t{ *this };
	*this = q;
	q = t;
}

template<typename T>
auto Queue<T>::operator=(const Queue & q) -> Queue&
{
	while (front != nullptr) {
		Node<int>* p = front;
		front = front->next;
		delete p;
	}
	Node<int>* p = q.front;
	while (p != nullptr) {
		this->push(p->data);
		p = p->next;
	}
}

template<typename T>
auto Queue<T>::empty() const -> bool
{
	if (front == nullptr)
		return true;
	else 
		return false;
}


template<typename T>
auto Queue<T>::size() const -> size_t
{
	size_t number = 1;
	Node<int>* p = front;
	while (p != back) {
		number++;
		p = p->next;
	}
	return number;
}

template<typename T>
auto Queue<T>::push(T value) -> void
{
	if (front == nullptr) {
		front = new Node<int>{ value, nullptr };
		back = front;
	}
	else {
		Node<int>* p = back;
		back = new Node<int>{ value, nullptr };
		p->next = back;
	}

}

template<typename T>
auto Queue<T>::pop() -> void
{
	Node<int>* p = front;
	front = front->next;
}

template<typename T>
auto Queue<T>::front_() -> T &
{
	return front->data;
}

template<typename T>
auto Queue<T>::back_() const -> T &
{
	return back->data;
}

template<typename T>
bool Queue<T>::operator==(const Queue & q)
{
	if (this->size() == q.size()) {
		Node<int>* p1 = this->front;
		Node<int>* p2 = q.front;
		while (p1 != nullptr) {
			if (p1->data != p2->data)
				return false;
			else {
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		return true;
	}
	return false;
}

template<typename T>
Queue<T>::~Queue()
{
	while (front != nullptr) {
		Node<int>* p = front;
		front = front->next;
		delete p;
	}
}

