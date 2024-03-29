#ifndef NODESEQUENCE_H
#define NODESEQUENCE_H

#include "Sequence.h"
#include <utility>

template <typename T>
struct Node
{
	T data;
	struct Node<T>* next;
	Node<T>(Node<T>* B);
	Node<T>();
};

template <typename T>
class NodeSequence : public Sequence<T>
{
private:
	Node<T>* head;
public:
	void addelem(T number);
	void deletelem(int ind);
	void swap(Node<T>& x, Node<T>& y);

	void swapto();


};

#endif

template<typename T>
inline void NodeSequence<T>::addelem(T number)
{
	Node<T>* nd = new Node<T>;
	nd->data = number;
	nd->next = nullptr;
	if (this->head == nullptr)
		this->head = nd;
	else
	{
		Node<T>* current = head;
		while (current->next != nullptr)
			current = current->next;
		current->next = nd;
	}
	Sequence<T>::setLength(Sequence<T>::getLength() + 1);

}

template<typename T>
inline void NodeSequence<T>::deletelem(int ind)
{
	if (ind < 0 || ind >= Sequence<T>::getLength())
		throw std::exception("Illegal index");
	int sizeS = Sequence<T>::getLength();
	if (sizeS == 0)
		throw std::exception("Nothing to delete");
	if (ind == 0)
	{
		Node<T>* temp = this->head;
		head = head->next;
		delete temp;
		Sequence<T>::setLength(Sequence<T>::getLength() - 1);
		return;
	}

	else
	{
		Node<T>* temp = this->head;
		Node<T>* prev = nullptr;
		int i = 0;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
			i++;
			if (i == ind)
			{
				prev->next = temp->next;
				delete temp;
				break;
			}

		}
		Sequence<T>::setLength(Sequence<T>::getLength() - 1);
	}

}

template<typename T>
inline void NodeSequence<T>::swap(Node<T>& x, Node<T>& y)
{
	Node<T> tmp{ std::move(x) }; // �������� ����������� �����������
	x = std::move(y); // �������� �������� ������������ ������������
	y = std::move(tmp);
}




template<typename T>
inline Node<T>::Node(Node<T>* B)
{
	this->data = B->data;
	this->next = B->next;
	return this;
}

template<typename T>
inline Node<T>::Node()
{
}

template<typename T>
inline void NodeSequence<T>::swapto()
{
	swap(*head, *(head->next));
}
