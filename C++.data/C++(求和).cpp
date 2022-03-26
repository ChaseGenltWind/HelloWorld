#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int sum=0;
	char ch;
	printf("请输入一串整数和任意数的空格：\n");
	while(scanf("%d",&i)==1)
	{
		 sum += i;
		 while((ch=getchar())==' ')
		 		;
		if(ch=='\n')
		break;
		ungetc(ch,stdin);
	}
	printf("结果是：%d\n",sum);
	system("pause");
}
