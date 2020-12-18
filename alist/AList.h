#pragma once
#include <iostream>
using namespace std;

template<class T>
class AList;

template<class T>
class AListIterator
{
private:
	AList<T>& list;
	int index;
public:
	AListIterator(AList<T>& _list, int _index) : list(_list), index(_index) {}
	AListIterator(AListIterator<T>& _v) : list(_v.list), index(_v.index) {}
	~AListIterator() {}

	bool CanGoForward()
	{
		return (list.links[index] != -1);
	}
	void GoForward()
	{
		if (!CanGoForward())
			throw logic_error("end");
		index = list.links[index];
	}

	bool operator==(const AListIterator<T>& _v)
	{
		return (list == _v.list && index == _v.index);
	}
	AListIterator<T> operator++(int)
	{
		GoForward();
		return (*this);
	}

	AListIterator<T>& operator=(const AListIterator<T>& _v)
	{
		list = _v.list;
		index = _v.index;
		return (*this);
	}

	T GetData()
	{
		return list.data[index];
	}
};

template<class T>
class AList
{
private:
	int Size;
	int Count;
	int* links;
	T* data;
	int head;
public:
	AList(int s = 1)
	{
		Size = s;
		Count = 0;
		links = new int[s];
		data = new T[s];
		for (int i = 0; i < s; i++)
		{
			links[i] = -2; //-2 means empty
			data[i] = 0;
		}
		head = -1;
	}

	AList(AList<T>& _l)
	{
		Size = _l.Size;
		Count = _l.Count;
		links = new int[Size];
		data = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			links[i] = _l.links[i];
			data[i] = _l.data[i];
		}
		head = _l.head;
	}

	~AList()
	{
		clear();
		delete[] links;
		delete[] data;
		Size = 0;
	}

	int GetSize() { return Size; }
	int GetCount() { return Count; }

	bool IsEmpty() { return (head == -1); }
	bool IsFull() { return (Count == Size); }

	void clear()
	{
		for (int i = 0; i < Count; i++)
		{
			links[i] = -2;
			data[i] = 0;
		}
		head = -1;
		Count = 0;
	}

	T& operator[](const int index)
	{
		if (index < 0 || index >= Count)
			throw length_error("incorrect index");

		int counter = 0;
		int current = head;
		while (current != -1)
		{
			if (counter == index)
				return data[current];
			current = links[current];
			counter++;
		}
	}

	AListIterator<T> begin()
	{
		return AListIterator<T>(*this, head);
	}

	void push_back(T data)
	{
		if (IsFull())
			throw logic_error("container is full");

		if (IsEmpty())
		{
			head = 0;
			this->data[0] = data;
			links[0] = -1; //-1 means last
		}
		else
		{
			int last = head;
			for (int i = 0; i < Count; i++)
				if (links[last] != -1)
					last = links[last];
				else
					break;
			int current = 0;
			for (int i = 0; i < Size; i++)
				if (links[i] == -2)
				{
					current = i;
					break;
				}
			this->data[current] = data;
			links[last] = current;
			links[current] = -1;
		};

		Count++;
	}

	void pop_back()
	{
		if (IsEmpty())
			throw logic_error("container is empty");
		
		if (links[head] == -1)
		{
			links[head] = -2;
			head = -1;
		}
		else
		{
			int last = head;
			int previous = 0;
			for (int i = 0; i < Count; i++)
				if (links[last] != -1)
				{
					previous = last;
					last = links[last];
				}
				else
				{
					links[last] = -2;
					links[previous] = -1;
				}
		}
		Count--;
	}

	void pop_front()
	{
		if (IsEmpty())
			throw logic_error("container is empty");

		if (links[head] == -1)
		{
			links[head] = -2;
			head = -1;
		}
		else
		{
			int first = links[head];
			links[head] = -2;
			head = first;
		}
		Count--;
	}

	void push_front(T data)
	{
		if (IsFull())
			throw logic_error("container is full");
		
		if (IsEmpty())
		{
			head = 0;
			this->data[0] = data;
			links[0] = -1; //-1 means last
		}
		else
		{
			int current = 0;
			while (links[current] != -2)
				current++;

			this->data[current] = data;
			links[current] = head;
			head = current;
		}
		Count++;
	}

	void insert(T data, int index)
	{
		if (IsFull())
			throw logic_error("container is full");

		if (index < 0 || index > Count)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else
		{
			int current = 0;
			while (links[current] != -2)
				current++;

			int previous = head;
			int counter = 0;

			while (counter != index - 1)
			{
				if (links[previous] == -1)
					break;
				previous = links[previous];
				counter++;
			}

			this->data[current] = data;
			links[current] = links[previous];
			links[previous] = current;
			Count++;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index >= Count)
			throw logic_error("incorrect index");

		if (index == 0)
			pop_front();
		else
		{
			int toDelete = head;
			int previous = 0;
			int counter = 0;

			while (counter != index)
			{
				if (counter == index - 1)
					previous = toDelete;
				toDelete = links[toDelete];
				counter++;
			}

			links[previous] = links[toDelete];
			links[toDelete] = -2;
			Count--;
		}
	}

	friend ostream& operator << (ostream& ostr, AList<T>& _l)
	{
		ostr << "{";
		for (int i = 0; i < _l.GetCount() - 1; i++)
			ostr << _l[i] << ", ";
		ostr << _l[_l.GetCount() - 1] << "}";

		return ostr;
	}

	template<class T>
	friend class AListIterator;
};