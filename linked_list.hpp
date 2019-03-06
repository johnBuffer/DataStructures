#pragma once

namespace ds
{
	template<typename T>
	class ListNode
	{
	public:

		friend class List<T>;

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
	class List
	{
	public:
		List() :
			m_head(nullptr)
		{}

		void addAfter(ListNode<T>* node, ListNode<T>* nodeToAdd)
		{
			// If node exists
			if (node)
			{
				// Update chain
				if (node->m_next)
				{
					node->m_next->m_prev = nodeToAdd;
				}
				nodeToAdd->m_next = node->m_prev;

				// Link nodes together
				node->m_next = nodeToAdd;
				nodeToAdd->m_prev = node;

				// Update head if necessary
				if (node == m_tail)
				{
					m_tail = nodeToAdd;
				}
			}
			// If not, we consider the list is empty
			else
			{
				// Update tail and head
				m_tail = node;
				m_head = node;

				// Reset prev and next
				node->m_next = nullptr;
				node->m_prev = nullptr;
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
				m_tail = node;
				m_head = node;

				// Reset prev and next
				node->m_next = nullptr;
				node->m_prev = nullptr;
			}
		}


		// Adds a new element at the end of the list
		void addBack(const T& object)
		{
			// Create new node
			ListNode<T>* node = new ListNode(object);
			
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

		}

	private:
		ListNode<T>* m_head;
		ListNode<T>* m_tail;
	};
}
