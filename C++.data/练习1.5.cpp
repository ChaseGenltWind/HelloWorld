/*C���Է��*/
#include <iostream>
#include <cstring>
 
int main(void)
{
	char a[2];
	printf("������������\n");
	scanf("%s",a);
	while(strlen(a)<=2)
	{
		printf("���󣡣���\n����������������\n");
		scanf("%s",a);
	}
	printf("��ϲ�㣡����������ɹ���\n");
	printf("��������ǣ�%s",a);
	return 0;
	
}
