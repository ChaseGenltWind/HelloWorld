#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int min_size = 4;
	string name;
	cout<<"������������֣������ĸ��ַ���\n"; 
	while(cin>>name)
	{
		if(name.size()<=min_size)
		{
			printf("error!\n����������\n"); 
			continue;
		}
		printf("��ϲ�㣡������ִ洢�ɹ�������");
		cout<<name<<"\n";
	}
}
