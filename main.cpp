#include <iostream>
#include "linked_list.hpp"

int main()
{
	ds::List<int> list;

	list.addBack(78);

	ds::ListIterator<int> it = list.begin();

	while (it.next())
	{

	}

	return 0;
}