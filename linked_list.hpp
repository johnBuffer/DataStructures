#pragma once


namespace ds
{
	template<typename T> class List;
	template<typename T> class ListIterator;

	template<typename T>
	class ListNode
	{
	public:
		friend class List<T>;
		friend class ListIterator<T>;

		ListNode() :
			T(),
			m_prev(nullptr),
			m_next(nullptr)
		{}

		ListNode(const T& obj) :
			m_object(obj),
			m_prev(nullptr),
			m_next(nullptr)
		{}

		// Emplace_back like ctor
		template<typename... Args>
		ListNode(Args&&... args) :
			m_object(std::forward(args)),
			m_prev(nullptr),
			m_next(nullptr)
		{}

		~ListNode()
		{

		}

		// Get ref to the node's object
		T& operator*()
		{
			return m_object;
		}

	private:
		T m_object;
		ListNode<T>* m_prev;
		ListNode<T>* m_next;
	};


	template<typename T>
	class ListIterator
	{
	public:
		friend class List<T>;

		ListIterator() :
			m_current_node(nullptr),
			m_head(nullptr)
		{}

		ListIterator(ListNode<T>* head) :
			m_current_node(nullptr),
			m_head(head)
		{}

		ListNode<T>* next()
		{
			if (m_current_node)
				m_current_node = m_current_node->m_next;
			else
				m_current_node = m_head;

			return m_current_node;
		}

		ListNode<T>* prev()
		{
			if (m_current_node)
				m_current_node = m_current_node->m_prev;
			else
				m_current_node = m_head;

			return m_current_node;
		}

		T& operator*()
		{
			return *(*m_current_node);
		}

	private:
		ListNode<T>* m_current_node;
		ListNode<T>* m_head;
	};

	template<typename T>
	class List
	{
	public:
		friend ListIterator<T>;

		List() :
			m_head(nullptr),
			m_tail(nullptr)
		{}

		void addAfter(ListNode<T>* node, ListNode<T>* nodeToAdd)
		{
			std::cout << "add" << std::endl;
			// If node exists
			if (node)
			{
				// Update chain
				if (node->m_next)
				{
					node->m_next->m_prev = nodeToAdd;
				}
				nodeToAdd->m_next = node->m_next;

				// Link nodes together
				node->m_next = nodeToAdd;
				nodeToAdd->m_prev = node;

				// Update head if necessary
				if (node == m_tail)
				{
					std::cout << "up" << std::endl;
					m_tail = nodeToAdd;
				}
			}
			// If not, we consider the list is empty
			else
			{
				std::cout << "no node" << std::endl;
				// Update tail and head
				m_tail = nodeToAdd;
				m_head = nodeToAdd;

				// Reset prev and next
				nodeToAdd->m_next = nullptr;
				nodeToAdd->m_prev = nullptr;
			}
		}

		void addBefore(ListNode<T>* node, ListNode<T>* nodeToAdd)
		{
			// If node exists
			if (node)
			{
				// Update chain
				if (node->m_prev)
				{
					node->m_prev->m_next = nodeToAdd;
				}
				nodeToAdd->m_prev = node->m_prev;

				// Link nodes together
				node->m_prev = nodeToAdd;
				nodeToAdd->m_next = node;

				// Update head if necessary
				if (node == m_head)
				{
					m_head = nodeToAdd;
				}
			}
			// The list is empty
			else
			{
				// Update tail and head
				m_tail = nodeToAdd;
				m_head = nodeToAdd;

				// Reset prev and next
				nodeToAdd->m_next = nullptr;
				nodeToAdd->m_prev = nullptr;
			}
		}


		// Adds a new element at the end of the list
		void addBack(const T& object)
		{
			// Create new node
			ListNode<T>* node = new ListNode<T>(object);
			
			// Add new node after tail
			addAfter(m_tail, node);
		}

		void addFront(const T& object)
		{
			// Create new node
			ListNode<T>* node = new ListNode(object);

			// Add the new node before head
			addBefore(m_head, node);
		}

		void remove(ListNode<T>* node)
		{
			if (!node)
				return;

			if (node == m_head)
			{
				m_head = node->m_next;
				if (m_head)
					m_head->m_next = nullptr;
			}
			else if (node == m_tail)
			{
				m_tail = node->m_prev;
				if (m_tail)
					m_tail->m_prev;
			}
			else
			{
				node->m_next->m_prev = node->m_prev;
				node->m_prev->m_next = node->m_next;
			}

			delete(node);
		}

		void remove(ListIterator<T>& it)
		{
			ListNode<T>* node = it.m_current_node;
			it.prev();
			remove(node);
			it.m_head = m_head;
		}

		ListNode<T>* getNext(ListNode<T>* node)
		{
			if (!node)
				return m_head;

			return node->m_next;
		}

		ListIterator<T> begin()
		{
			return ListIterator<T>(m_head);
		}

	private:
		ListNode<T>* m_head;
		ListNode<T>* m_tail;
	};
}
