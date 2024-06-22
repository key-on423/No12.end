
//8.创建make_array和show_array函数,make_array函数接受两个参数，第一个参数是int类型数组的元素个数，第二个参数是要赋给每个元素的值
//该函数调用malloc（）创建一个大小合适的数组，将其每个元素设置为指定的值，并返回一个指向该数字的指针。
//show_array函数显示数组的内容，一行显示8个数


//#include <stdio.h>
//#include <stdlib.h>//提供malloc和free
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

//9.编写一个符合以下描述的函数。首先，询问用户需要输入多少个单词。然后，接受用户输入的单词，并显示出来
//使用malloc（）并回答第一个问题（即要输入多少个单词），创建一个动态数组，该数组内涵像是的指向char的指针
//注意，由于数组的每个元素都是指向char的指针，所以用于存储malloc（）返回值的指针应该是一个指向指针的指针
//且它所指向的指针指向char。 在读取字符串时，该程序应该把单词读入一个临时的char数组，使用malloc（）分配
//足够的存储空间来存储单词，并把地址存入该指针数组（该数组中每个元素都是指向char的指针）。然后，从临时数组中把
//单词拷贝到动态分配的存储空间中。 因此，有一个字符指针数组，每个指针都指向一个对象，该对象的大小正好能容纳
//被存储的特定单词。

#include <stdio.h>
#include <stdlib.h>//提供malloc和free
#include <string.h>
char* s_gets(char* st, int n);
int main()
{
	int i;
	int n;
	printf("How many words do you wish to enter? ");
	scanf("%d", &n);
	char** pa;
	pa = (char * *)malloc(n * sizeof(char*));//以pa而不是*pa
	printf("Enter %d words now:\n",n);
	for (i = 0;i < n;i++)
	{
		char arr[100];//放在里面自动初始
		scanf("%s", arr);//这里用scanf好因为其自动跳跃 空字符
		int lenth = strlen(arr);
		char* str = (char*)malloc(lenth * sizeof(char));
		strcpy(str, arr);
		pa[i] = str;//或*(pa+i); 不写pa[i][0]因为只分配了指向指针的指针的空间，没用分配指向的那个指针的空间
	}
	for (i = 0;i < n;i++)
	{
		printf("%s\n", pa[i]);
	}
	//printf("%s 1 %c", pa[1], *pa[1]);
	//printf("%p 6 %p", pa[1], &pa[1][0]);//地址相同
	free(pa);
	printf("结束.\n");
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