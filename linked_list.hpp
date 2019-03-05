#pragma once

namespace ds
{
	template<typename T>
	struct ListNode
	{
		ListNode() :
			prev(nullptr),
			next(nullptr)
		{}

		ListNode(const T& obj) :
			object(obj)
		{}

		template<typename... Args>
		ListNode(Args&&... args) :
			object(std::forward(args))
		{}

		T object;
		ListNode<T>* prev;
		ListNode<T>* next;
	};


}
