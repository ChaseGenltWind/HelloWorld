#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int sum=0;
	char ch;
	printf("������һ���������������Ŀո�\n");
	while(scanf("%d",&i)==1)
	{
		 sum += i;
		 while((ch=getchar())==' ')
		 		;
		if(ch=='\n')
		break;
		ungetc(ch,stdin);
	}
	printf("����ǣ�%d\n",sum);
	system("pause");
}
