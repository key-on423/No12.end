
//8.����make_array��show_array����,make_array��������������������һ��������int���������Ԫ�ظ������ڶ���������Ҫ����ÿ��Ԫ�ص�ֵ
//�ú�������malloc��������һ����С���ʵ����飬����ÿ��Ԫ������Ϊָ����ֵ��������һ��ָ������ֵ�ָ�롣
//show_array������ʾ��������ݣ�һ����ʾ8����


//#include <stdio.h>
//#include <stdlib.h>//�ṩmalloc��free
//int* make_array(int elem, int val);
//void show_array(const int ar[], int n);
//int main()
//{
//	int* pa;
//	int size;
//	int value;
//	printf("Enter the number of elements: ");
//	while (scanf("%d", &size) == 1 && size > 0)
//	{
//		printf("Enter the initialization value: ");
//		scanf("%d", &value);
//		pa = make_array(size, value);
//		if (pa)
//		{
//			show_array(pa, size);
//			free(pa);
//		}
//		printf("\nEnter the number of elements (<1 to quit): ");
//	}
//	printf("Done.\n");
//	return 0;
//}
//int* make_array(int elem, int val)
//{
//	int i = 0;
//	int* pb;
//	pb= (int *)malloc (elem * sizeof(int));
//	for (i = 0;i < elem;i++)
//	{
//		pb[i] = val;
//	}
//	return pb;
//}
//
//void show_array(const int ar[], int n)
//{
//	int i;
//	for (i = 0;i < n;i++)
//	{
//		printf("%d ", ar[i]);
//		if ((i + 1) % 8 == 0 && i != 0)
//			printf("\n");
//	}
//
//}

//9.��дһ���������������ĺ��������ȣ�ѯ���û���Ҫ������ٸ����ʡ�Ȼ�󣬽����û�����ĵ��ʣ�����ʾ����
//ʹ��malloc�������ش��һ�����⣨��Ҫ������ٸ����ʣ�������һ����̬���飬�������ں����ǵ�ָ��char��ָ��
//ע�⣬���������ÿ��Ԫ�ض���ָ��char��ָ�룬�������ڴ洢malloc��������ֵ��ָ��Ӧ����һ��ָ��ָ���ָ��
//������ָ���ָ��ָ��char�� �ڶ�ȡ�ַ���ʱ���ó���Ӧ�ðѵ��ʶ���һ����ʱ��char���飬ʹ��malloc��������
//�㹻�Ĵ洢�ռ����洢���ʣ����ѵ�ַ�����ָ�����飨��������ÿ��Ԫ�ض���ָ��char��ָ�룩��Ȼ�󣬴���ʱ�����а�
//���ʿ�������̬����Ĵ洢�ռ��С� ��ˣ���һ���ַ�ָ�����飬ÿ��ָ�붼ָ��һ�����󣬸ö���Ĵ�С����������
//���洢���ض����ʡ�

#include <stdio.h>
#include <stdlib.h>//�ṩmalloc��free
#include <string.h>
char* s_gets(char* st, int n);
int main()
{
	int i;
	int n;
	printf("How many words do you wish to enter? ");
	scanf("%d", &n);
	char** pa;
	pa = (char * *)malloc(n * sizeof(char*));//��pa������*pa
	printf("Enter %d words now:\n",n);
	for (i = 0;i < n;i++)
	{
		char arr[100];//���������Զ���ʼ
		scanf("%s", arr);//������scanf����Ϊ���Զ���Ծ ���ַ�
		int lenth = strlen(arr);
		char* str = (char*)malloc(lenth * sizeof(char));
		strcpy(str, arr);
		pa[i] = str;//��*(pa+i); ��дpa[i][0]��Ϊֻ������ָ��ָ���ָ��Ŀռ䣬û�÷���ָ����Ǹ�ָ��Ŀռ�
	}
	for (i = 0;i < n;i++)
	{
		printf("%s\n", pa[i]);
	}
	//printf("%s 1 %c", pa[1], *pa[1]);
	//printf("%p 6 %p", pa[1], &pa[1][0]);//��ַ��ͬ
	free(pa);
	printf("����.\n");
	//printf("%s 1 %c", pa[1], *pa[1]);
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret;
	ret = fgets(st, n, stdin);
	if (ret)
	{
		while (*st != '\n' && *st != '\0'&&*st!=' ')
			st++;
		if (*st == '\n'||*st==' ')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
}