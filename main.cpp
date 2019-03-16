#include <iostream>
#include "linked_list.hpp"

int main()
{
	ds::List<int> list;

	for (uint32_t i(0); i < 10; ++i)
		list.addBack(i);

	ds::ListIterator<int> it = list.begin();

	while (it.next())
	{
		if (*it == 5)
			list.remove(it);
	}

	while (it.next())
	{
		std::cout << *it << std::endl;
	}

	return 0;
}