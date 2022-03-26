#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int a,i=0;
	float sum_1=0;
	float sum_2=0;
	const int size=10;
	int array[size];
	vector<int>lie(size); 
	while(i<10&&cin>>a)
	{
		array[i]=a;
		sum_1 +=array[i];
		lie[i]=a;
		sum_2 +=lie[i];
		i++;
	}
	cout<<sum_1<<' '<<sum_1/10.0<<"\n";
	cout<<sum_2<<' '<<sum_2/10.0;
	return 0;	
} 
