/*C语言风格*/
#include <iostream>
#include <cstring>
 
int main(void)
{
	char a[2];
	printf("请输入姓名：\n");
	scanf("%s",a);
	while(strlen(a)<=2)
	{
		printf("错误！！！\n请重新输入姓名：\n");
		scanf("%s",a);
	}
	printf("恭喜你！！姓名输入成功！\n");
	printf("你的姓名是：%s",a);
	return 0;
	
}
