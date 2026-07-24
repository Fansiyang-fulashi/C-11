#pragma once
#pragma once
#include<iostream>
#include<string>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<functional>

namespace all
{
	template<class T>
	class list
	{
	private:
		class list_node
		{
		public:
			T data;
			list_node* next;
			list_node* prev;

			//template<class Y>
			/*list_node(Y&& data)
				:data(std::forward<Y>(data))
				, next(nullptr)
				, prev(nullptr)
			{
			}

			list_node(const T& data = T())
				:data(data)
				, next(nullptr)
				, prev(nullptr)
			{
			}*/

			template<class ...Args>
			list_node(Args&& ...data)
				:data(std::forward<Args>(data)...)
				, next(nullptr)
				, prev(nullptr)
			{
			}
		};

		typedef list_node Node;
		Node* _head;
		size_t _size;

	public:

		template<class Ref, class Ptr>
		class list_iterator
		{
		private:
			typedef list_node Node;
			typedef list_iterator<Ref, Ptr> Self;
			Node* _node;
		public:
			friend class list<T>;
			list_iterator(Node* node)
				:_node(node)
			{
			}
			Ref operator*()
			{
				return _node->data;
			}
			Ref operator*()const
			{
				return _node->data;
			}
			Self& operator++()
			{
				_node = _node->next;
				return *this;
			}
			bool operator!=(const Self& it)const
			{
				return _node != it._node;
			}
			bool operator==(const Self& it)const
			{
				return !(*this != it);
			}
			Self& operator--()
			{
				_node = _node->prev;
				return *this;
			}
			Self operator++(int)
			{
				Self tem(*this);
				_node = _node->next;
				return tem;
			}
			Self operator--(int)
			{
				Self tem(*this);
				_node = _node->prev;
				return tem;
			}
			Ptr operator->()
			{
				return &_node->data;
			}
			Ptr operator->()const
			{
				return &_node->data;
			}
		};

		typedef list_iterator<T&, T*> iterator;
		typedef list_iterator<const T&, const T*> const_iterator;
		typedef list_node Node;

		list()
		{
			std::cout << "构造" << std::endl;
			empty_init();
		}
		~list()
		{
			if(_head!=nullptr)
			clear();
			delete _head;
			_head = nullptr;
		}
		list(const list<T>& copy_l)
		{
			std::cout<< "拷贝构造" << std::endl;
			empty_init();
			const_iterator it = copy_l.begin();
			while (it != copy_l.end())
			{
				push_back(*it);
				++it;
			}
		}
		list(list<T>&& copy_l)
		{
			std::cout << "移动构造" << std::endl;
			swap(copy_l);
		}
		list(std::initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}
		list<T>& operator=(list<T> tem)
		{
			std::cout << "拷贝赋值" << std::endl;
			swap(tem);
			return *this;
		}
		list<T>& operator=(list<T>&& tem)
		{
			std::cout << "移动赋值" << std::endl;
			swap(tem);
			return *this;
		}
		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
			std::swap(_size, l._size);
		}
		void empty_init()
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
			_size = 0;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		/*void push_back(const T&x)
		{
			Node* temp = new Node;
			temp->data = x;
			Node* prevp = _head->prev;
			prevp->next = temp;
			temp->prev = prevp;
			_head->prev = temp;
			temp->next = _head;
			_size++;
		}*/
		iterator begin()
		{
			/*iterator it(_head->next);
			return it;*/
			return _head->next;
		}
		iterator end()
		{
			/*iterator it(_head);
			return it;*/
			return _head;
		}
		const_iterator begin()const
		{
			return _head->next;
		}
		const_iterator end()const
		{
			return _head;
		}
		template<class ...Args>
		iterator insert(iterator it, Args&& ...x)
		{
			Node* prevp = it._node->prev;
			Node* now = it._node;
			Node* tem = new Node(std::forward<Args>(x)...);
			tem->prev = prevp;
			prevp->next = tem;
			tem->next = now;
			now->prev = tem;
			_size++;
			return tem;
		}
		/*template<class T>
		iterator insert(iterator it, T&& x)
		{
			Node* prevp = it._node->prev;
			Node* now = it._node;
			Node* tem = new Node;
			tem->data = std::forward<T>(x);
			tem->prev = prevp;
			prevp->next = tem;
			tem->next = now;
			now->prev = tem;
			_size++;
			return tem;
		}*/
		void push_front(const T& x = T())
		{
			insert(begin(), x);
		}
		/*void push_back(const T& x = T())
		{
			insert(end(), x);
		}*/
		void push_back(const T& x)
		{
			insert(end(),x);
		}
		void push_back(T&& x)
		{
			insert(end(), std::forward<T>(x));
		}
		size_t size()const
		{
			return _size;
		}
		iterator erase(iterator pos)
		{
			assert(_size > 0);
			assert(pos != end());
			Node* tem = pos._node;
			Node* prevp = tem->prev;
			Node* nextp = tem->next;
			prevp->next = nextp;
			nextp->prev = prevp;
			delete tem;
			tem = nullptr;
			--_size;
			return nextp;
		}
		void pop_front()
		{
			erase(begin());
		}
		void pop_back()
		{
			erase(--end());
		}
		bool empty()const
		{
			return _size == 0;
		}
		void resize(size_t n, const T& val = T())
		{
			if (_size < n)
			{
				for (size_t i = _size; i < n; i++)
				{
					push_back(val);
				}
			}
			else
			{
				iterator it = begin();
				for (size_t i = 0; i < n; i++)
				{
					++it;
				}
				while (it != end())
				{
					it = erase(it);
				}
			}
		}
		template<class ...Args>
		void emplace_back(Args&& ...args)
		{
			insert(end(), std::forward<Args>(args)...);
		}
		T& front()
		{
			return *begin();
		}

		const T& front()const
		{
			return *begin();
		}

		T& back()
		{
			return *(--end());
		}

		const T& back()const
		{
			return *(--end());
		}
	};
	namespace tool
	{
		template <class Container>
		void printf_container(const Container& con)
		{
			typename Container::const_iterator it = con.begin();
			while (it != con.end())
			{
				std::cout << *it << std::endl;
				++it;
			}
		}
	}

	class AA
	{
	public:

		int a;
		int b;
	};
}