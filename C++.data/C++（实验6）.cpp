#include <iostream>
int main()
{
	const unsigned short IESZ=10;
	int num[IESZ];
	int i;
	std::cout<<"������"<<IESZ<<"���������ݣ�\n\n";
	for(i=0;i<IESZ;i++)
	{
		std::cout<<"�������"<<i+1<<"������";
		while(!(std::cin>>num[i]))
		{
			std::cin.clear();
			std::cin.ignore(100,'\n');
			std::cout<<"������һ���Ϸ�ֵ";
		 } 
	 } 
	 int total=0;
	 for(i=0;i<IESZ;i++)
	 {
	 	total+=num[i];
	 }
	 std::cout<<"�ܺ��ǣ�"<<total<<"\n";
	 std::cout<<"ƽ��ֵ�ǣ�"<<(float)total/IESZ<<"\n";
	  
}
 
