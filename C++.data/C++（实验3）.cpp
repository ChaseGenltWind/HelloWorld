#include <iostream>

using namespace std;

int main()
{
	const int size=50;
	char buf[size];
	
	cout <<"������һ���ı�";
	cin.read(buf,20);
	
	cout <<"�ַ����ռ������ַ���Ϊ��"
	<<cin.gcount() <<endl;
	
	cout <<"������ı���Ϣ�ǣ�";
	
	cout.write(buf,20);
	cout <<endl;
	  
}
