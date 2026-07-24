#include"list.h"

int main()
{
	/*all::list<int> l;	
	all::list<int> l1=l;
	all::list<int> l2(std::move(l));
	all::list<std::pair<int, int>> l3;
	l3.emplace_back(1, 2);*/

	//lambda表达式
	auto add1 = [](int x, int y) {return x + y; };
	std::cout << add1(1, 2) << std::endl;
	auto add2 = []
		{
			std::cout << "啦啦啦" << std::endl;
		};
	add2();

	std::vector<std::pair<std::string, int>> aaa = { {"苹果",1},{"西瓜",2},{"梨花",1} };
	sort(aaa.begin(), aaa.end(), [](const std::pair<std::string, int>& v1, const std::pair<std::string, int>& v2)
		{
			if (v1.second != v2.second)
				return v1.second < v2.second;
			return v1.first > v2.first;
		});
	for (auto& it : aaa)
	{
		std::cout << it.first << std::endl;
	}

	//lambda表达式--捕捉列表
	int a = 0;
	int b = 1;
	auto F = [a, &b] {
		return a + (b++); 
		};
	std::cout << F() << std::endl;
	std::cout << F() << std::endl;
	auto F1 = [&] {
		return (++a) + (b++);
		};
	std::cout << F1() << std::endl;

	//逆波兰表达式
	return 0;
}