#include <iostream>
#include <vector>
#include <fstream> 
#include <windows.h> 
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	SetConsoleOutputCP(65001);
	int i=0;
	const int size = 200;
	vector<string>a(size);
	ifstream infile("my file.txt");
	if(!infile)
	cout<<"��Ǹ�������ڸ��ļ�������\n";
	while(infile)
	{
		infile>>a[i];
		i++;
	}
	i=0;
	cout<<a.size()<<"\n";
	while(i<a.size())
	{
		cout<<a[i];
	
		i++;
	}
	cout<<"\n";
	
	sort(a.begin(),a.end());
	
	ofstream  outfile("my_file_3.txt"); 
	
	if(!outfile)
	cout<<"��Ǹ�������ڸ��ļ�2������\n";
	
	for(i=0;i<a.size();i++)
	{
		outfile<<a[i]<<' ';
	}
	outfile<<endl;
	return 0;
}  
