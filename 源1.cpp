#include"list.h"

struct hhh
{
	hhh()
		:_n(10)
	{ }

	static int iii(int a, int b)
	{
		return a + b;
	}

	int ooo(double a, double b)
	{
		return a + b;
	}
	int _n = 10;
};

int kkk(int a, int b)
{
	return a - b;
}
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

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

	//包装器
	std::function<int(int, int)> ddd = [](int a, int b){return a + b; };
	std::function<int(int, int)> bbb = hhh::iii;
	std::function<int(hhh, int, int)> ccc = &hhh::ooo;
	std::cout << ccc(hhh(), 100, 1) << std::endl;

	//逆波兰表达式

	//bind
	auto sub1 = std::bind(kkk, _2, _1);
	std::cout<<sub1(10, 2)<<std::endl;
	std::function<int(int, int)> ppp = std::bind(&hhh::ooo, hhh(), _1, _2);
	std::cout<<ppp(1, 2);
	return 0;
}