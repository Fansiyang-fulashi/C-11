#include"头.h"

struct point
{
	point(int x = 0, int y = 1)
		:_x(x)
		, _y(y)
	{
	}

	void F(int& a)
	{
		std::cout << "T&" << std::endl;
	}

	void F(const int& a)
	{
		std::cout << "const T&" << std::endl;
	}

	void F(int&& a)
	{
		std::cout << "T&&" << std::endl;
	}

	std::string s(std::string a,std::string b)//返回值不能为右值、左值引用 因为函数栈帧销毁与生命周期无关
	{
		std::string c = a + b;
		return c;
	}
	int _x;
	int _y;
};

struct str
{
	
	str(std::string&& a)
	{
		_a.std::string::swap(a);
	}

	std::string s(std::string a, std::string b)//返回值不能为右值、左值引用 因为函数栈帧销毁与生命周期无关
	{
		std::string c = a + b;
		return c;
	}

	std::string _a;
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

	//左值引用
	int j = 0;
	int& jy = j;

	//右值引用
	int&& lll = 10;
	std::string&& kkk = std::string("1111");

	//左值const下引用右值
	const int& jjjj = 10;

	//右值引用move下的左值
	int aaaa = 10;
	int&& aaao = std::move(aaaa);
	int&& aaah = (int&&)aaaa;

	//右值引用的属性为左值
	int&& qaaah = (int&&)aaaa;
	int& aaaaa = qaaah;

	//左右值的参数匹配
	point ooo;
	int all = 1;
	const int alll = 1;
	ooo.F(all);
	ooo.F(alll);
	ooo.F(1);
	int&& okok = 2;
	ooo.F(okok);
	ooo.F(std::move(all));

	//右值引用与移动语义
	std::cout<<ooo.s("11", "22")<<std::endl;
	return 0;
}