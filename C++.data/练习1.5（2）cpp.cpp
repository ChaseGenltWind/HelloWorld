#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	const int min_size = 4;
	string name;
	cout<<"请输入你的名字（大于四个字符）\n"; 
	while(cin>>name)
	{
		if(name.size()<=min_size)
		{
			printf("error!\n请重新输入\n"); 
			continue;
		}
		printf("恭喜你！你的名字存储成功！！！");
		cout<<name<<"\n";
	}
}
