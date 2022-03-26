/*关于引用和指针*/ 
#include <iostream>

int main(void)
{
	int a = 12;
	int *p = &a;
	int &b = a;
	std::cout <<*p<<"\n"
		<<p<<"\n"
		<<&b<<"\n"
		<<b<<"\n\n";	
	int c = 15;
	b = c;
	std::cout <<*p<<"\n"
		<<p<<"\n"
		<<&b<<"\n"
		<<b;
}
