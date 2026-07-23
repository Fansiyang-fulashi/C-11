#include"list.h"

int main()
{
	all::list<int> l;	
	all::list<int> l1=l;
	all::list<int> l2(std::move(l));
	all::list<std::pair<int, int>> l3;
	l3.emplace_back(1, 2);
	return 0;
}