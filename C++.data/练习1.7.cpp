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
	cout<<"抱歉，不存在该文件！！！\n";
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
	cout<<"抱歉，不存在该文件2！！！\n";
	
	for(i=0;i<a.size();i++)
	{
		outfile<<a[i]<<' ';
	}
	outfile<<endl;
	return 0;
}  
