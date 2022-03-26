#include <iostream>
int main()
{
	const unsigned short IESZ=10;
	int num[IESZ];
	int i;
	std::cout<<"请输入"<<IESZ<<"个整型数据！\n\n";
	for(i=0;i<IESZ;i++)
	{
		std::cout<<"请输入第"<<i+1<<"个数据";
		while(!(std::cin>>num[i]))
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout<<"请输入一个合法值";
		 } 
	 } 
	 int total=0;
	 for(i=0;i<IESZ;i++)
	 {
	 	total+=num[i];
	 }
	 std::cout<<"总和是："<<total<<"\n";
	 std::cout<<"平均值是："<<(float)total/IESZ<<"\n";
	  
}
 
