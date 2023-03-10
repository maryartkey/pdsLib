#pragma once

#include <iostream>

namespace pdsLib
{
	/*doubly persistent linked list*/
	template<class T>
	class List
	{
	private:
		/*element of List*/
		struct Element
		{
			Element(T, std::shared_ptr<Element>, std::shared_ptr<Element>);
			T data;
			std::shared_ptr<Element> prev;
			std::shared_ptr<Element> next;
		};

		int count;

		std::shared_ptr<Element> head;

		std::shared_ptr<Element> tail;

		/*correct index flag*/
		bool CorrectIndex(int) const;

		/*return head of the list*/
		T Front() const;

		/*return rest of the list*/
		List<T> PoppedFront() const;

	public:
		/*default constructor*/
		List();

		/*list-constructor used to pop front*/
		List(std::shared_ptr<Element>, List const&);

		/*list-constructor used to Insert head element*/
		List(T, List const&);

		/*list-constructor used to Insert tail element*/
		List(List const&, T);

		/*is empty flag*/
		bool IsEmpty() const;

		/*get num of elements in List*/
		int Count() const;

		/*return new List with added head element*/
		List<T> AddHead(T) const;

		/*return new List with added tail element*/
		List<T> AddTail(T) const;

		/*get element of List by index*/
		T Get(int) const;

		/*set element of List by index*/
		List<T> Set(int, T) const;

		/*insert element in List by index*/
		List<T> Insert(T, int index = 0) const;

		/*delete element in List by index*/
		List Remove(int) const;

		/*print all List*/
		void PrintAll() const;
	};

	/*element of List*/
	template<class T>
	List<T>::Element::Element(T _data, std::shared_ptr<Element> _prev, std::shared_ptr<Element> _next)
	{
		data = _data;
		prev = _prev;
		next = _next;
	}

	/*default constructor*/
	template<class T>
	List<T>::List()
	{
		count = 0;
	}

	/*list-constructor used to pop front*/
	template<class T>
	List<T>::List(std::shared_ptr<Element> element, List const& rest)
	{
		head = element;
		tail = rest.tail;
		count = rest.count - 1;
	}

	/*list-constructor used to Insert head element*/
	template<class T>
	List<T>::List(T element, List const& rest)
	{
		if (rest.count > 0)
		{
			head = std::make_shared<Element>(element, nullptr, rest.head);
			head->next->prev = head;
			tail = rest.tail;
		}
		else
		{
			head = tail = std::make_shared<Element>(element, nullptr, rest.head);
		}

		count = rest.count + 1;
	}

	/*list-constructor used to Insert tail element*/
	template<class T>
	List<T>::List(List const& initial, T element)
	{
		if (initial.count > 0)
		{
			head = initial.head;
			tail = std::make_shared<Element>(element, initial.tail, nullptr);
			tail->prev->next = tail;
		}
		else
		{
			head = tail = std::make_shared<Element>(element, initial.tail, nullptr);
		}

		count = initial.count + 1;
	}

	/*is empty flag*/
	template<class T>
	bool List<T>::IsEmpty() const
	{
		return !head;
	}

	/*correct index flag*/
	template<class T>
	bool List<T>::CorrectIndex(int index) const
	{
		return (index >= 0) && (index < count);
	}

	/*get num of elements in List*/
	template<class T>
	int List<T>::Count() const
	{
		return count;
	}

	/*return head of the list*/
	template<class T>
	T List<T>::Front() const
	{
		assert(!IsEmpty());
		return head->data;
	}

	/*return rest of the list*/
	template<class T>
	List<T> List<T>::PoppedFront() const
	{
		assert(!IsEmpty());
		return List(head->next, *this);
	}

	/*return new List with added head element*/
	template<class T>
	List<T> List<T>::AddHead(T element) const
	{
		try
		{
			return List(element, *this);
		}
		catch (std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	/*return new List with added tail element*/
	template<class T>
	List<T> List<T>::AddTail(T element) const
	{
		try
		{
			return List(*this, element);
		}
		catch (std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	/*get element of List by index*/
	template<class T>
	T List<T>::Get(int index) const
	{
		assert(!IsEmpty());

		try
		{
			if (!CorrectIndex(index))
				throw std::out_of_range("\nIncorrect index: ");

			std::shared_ptr<Element> temp = head;
			for (int i = 0; i < index; i++)
				temp = temp->next;

			return temp->data;
		}
		catch (std::out_of_range e)
		{
			std::cout << e.what() << index << std::endl;
			return NULL;
		}
	}

	/*set element of List by index*/
	template<class T>
	List<T> List<T>::Set(int index, T _data) const
	{
		assert(!IsEmpty());

		try
		{
			if (!CorrectIndex(index))
				throw std::out_of_range("\nIncorrect index: ");

			if (index == 0)
				return Remove(index).AddHead(_data);

			return List(Front(), PoppedFront().Set(index - 1, _data));
		}
		catch (std::out_of_range e)
		{
			std::cout << e.what() << index << std::endl;

			return *this;
		}
	}

	/*insert element in List by index*/
	template<class T>
	List<T> List<T>::Insert(T _data, int index) const
	{
		if (index == 0)
			return AddHead(_data);

		else if (index == count)
			return AddTail(_data);

		else
		{
			assert(!IsEmpty());
			return List<T>(Front(), PoppedFront().Insert(_data, index - 1));
		}
	}

	/*delete element in List by index*/
	template<class T>
	List<T> List<T>::Remove(int index) const
	{
		try
		{
			if (!CorrectIndex(index))
				throw std::out_of_range("\nIncorrect index: ");

			if (IsEmpty())
				return List();

			if (index == 0)
				return PoppedFront();

			else
			{
				return List(Front(), PoppedFront().Remove(index - 1));
			}
		}
		catch (std::out_of_range e)
		{
			std::cout << e.what() << index << std::endl;
		}
	}

	/*print all List*/
	template<class T>
	void List<T>::PrintAll() const
	{
		try
		{
			std::shared_ptr<Element> temp = head;
			for (int i = 0; i < count; i++)
			{
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

	}
}
