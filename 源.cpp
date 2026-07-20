#include"头.h"

struct point
{
	point(int x = 0, int y = 1)
		:_x(x)
		, _y(y)
	{

	}
	int _x;
	int _y;
};


int main()
{
	//列表初始化
	int x = { 2 };
	point aaa = { 1,2 };

	//去掉=的列表初始化
	int x2{ 1 };
	point bbb{ 1,2 };
	point ccc{ 1 };//缺省构造

	//initializer_list类构造
	std::vector<int> ddd = { 1,2,3,4,5,6 };
	std::vector<int> eee{ 1,2,3,4,5,6 };
	std::vector<int> fff({ 1,2,3,4,5,6 });
	std::map<int, int> ggg{ {1,2},{1,2},{1,5},{2,3},{4,5} };

	//常见左值
	int y = 1000;
	int* b = nullptr;
	std::string hhh("pppppp");
	hhh[0] = '1';
	std::cout << (void*)&hhh[0] << std::endl;

	//常见右值
	10;//字面常量
	std::min(x, y);//传值返回的临时对象
	std::string("1111");//匿名对象

	return 0;
}