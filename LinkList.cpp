#include "lb.h"
#include<stdio.h>
#include<stdlib.h>
/*
在main函数中，已将除了创建链表之外的函数全部注释。若需使用则自行取消注释
*/
typedef struct node {
	int x;
	int index;
	struct node* next;
	struct node* prior;
}node;
int len;
/*
尾插法创建链表
*/
node* create_tail(struct node*& first) {
	first = (node*)malloc(sizeof(node));
	int a;
	struct node* p, * q;
	if (first == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	first->next = NULL;
	first->prior = NULL;
	q = first;
	len = 0;
	printf("\n请输入链表数据(不要以空格结尾，否则需要多输入一个数据)：\n");
	do {
		scanf_s("%d", &a);
		p = (node*)malloc(sizeof(node));
		p->x = a;
		p->prior = q;
		q->next = p;
		q = p;
		p->index = len + 1;
		len++;
	} while (getchar() != '\n');
	q->next = NULL;
	return first;
}
/*
头插法创建链表
*/
node* create_head(struct node*& first) {
	first = (node*)malloc(sizeof(node));
	int a;
	struct node* p, * q;
	if (first == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	first->next = NULL;
	first->prior = NULL;
	q = first;
	len = 0;
	printf("\n请输入链表数据(不要以空格结尾，否则需要多输入一个数据)：\n");
	do {
		scanf_s("%d", &a);
		p = (node*)malloc(sizeof(node));
		p->x = a;
		p->next = q->next;
		if (q->next != NULL) {
			q->next->prior = p;
		}
		q->next = p;
		p->prior = q;
		p->index = len + 1;
		len++;
	} while (getchar() != '\n');
	return first;
}
/*
实现正向打印链表
*/
void print(struct node*& first) {
	printf("打印链表：\n");
	struct node* p;
	p = first->next;
	while (p != NULL) {
		printf("%d  ", p->x);
		p = p->next;
	}
	printf("\n");
}
/*
实现查找第某个节点的数据
*/
void find(struct node*& first, int n) {
	int i;
	struct node* p = first;
	if (n == 0 || p == NULL || n > len) {
		printf("\n无数据\n");
	}
	else {

		for (i = 1; i <= n; i++) {
			p = p->next;
		}
		n = p->x;
		printf("你想查找的数据为：%d  \n", n);
	}

}

/*
实现插入操作
*/
void insert(struct node*& first, int n) {
	struct node* p, * new1;
	int i;
	p = first;
	new1 = (node*)malloc(sizeof(node));
	new1->next = NULL;
	new1->prior = NULL;
	if (n == 0 || p == NULL || n > len) {
		printf("\n插入失败\n");
	}
	else {

		for (i = 1; i <= n; i++) {
			p = p->next;
		}
		printf("\n请输入新节点的数据：\n");
		scanf_s("%d", &(new1->x));
		new1->next = p;
		new1->prior = p->prior;
		p->prior->next = new1;
		p->prior = new1;
		len++;
	}
}
/*
实现删除指定节点
*/
void delet(struct node*& first, int n) {
	struct node* p;
	p = first;
	int i;
	if (n == 0 || p == NULL || n > len) {
		printf("\n删除失败\n");
	}
	else {

		for (i = 1; i <= n; i++) {
			p = p->next;
		}
		p->prior->next = p->next;
		p->next->prior = p->prior;
		len--;
	}
}

/*
实现链表的反转，支持部分反转
*/
void reversal(struct node*& first, int a, int b) {
	int i = 0;
	int j = 0;
	struct node* p, * q;
	p = first;
	q = first;
	if (a<0 || b>len || a > b) {
		printf("你的输入有误");
		exit(1);
	}
	else {
		for (int i = 0; i < a; i++) {
			//p->x = a所在的节点
			p = p->next;
		}
		printf("p->x = %d\n", p->x);
		for (int i = 0; i < b; i++) {
			//q->x = b所在的节点
			q = q->next;
		}

		for (i = 0, j = b - a; i < j; i++, j--) {
			int tmp = p->x;
			p->x = q->x;
			q->x = tmp;
			p = p->next;
			q = q->prior;
		}
		print(first);
	}
}
/*
输出倒数第k个数据
*/
void printlast(struct node*& first, int a) {
	struct node* p;
	p = first;
	if (a > len) {
		printf("你的输入有误");
	}
	else {
		for (int i = 0; i < len - a; i++) {
			p = p->next;
		}
		print(p);
	}
}
/*
一次遍历查找中间数据
*/
void FindMiddleOneTime(struct node*& first) {
	struct node* p;
	p = first->next;

	while (p->index <= len / 2) {
		p = p->next;
	}
	if (len % 2 == 0) {
		printf("(链表长度为偶数中间数据有两个)\n链表中间的数据为：%d %d", p->prior->x, p->x);
	}
	else {
		printf("\n链表中间的数据为：%d", p->x);
	}
}

int main() {

	////创建以及打印链表 
	char ch;
	int n;
	struct node* first;
	create_tail(first);
	print(first);
	printf("\n链表长度为：%d", len);


	////查找以及打印 
	//scanf("%c",&ch);
	//
	//printf("\n输入你想查找的数据的序号：");
	//scanf("%d",&n);
	//find(first,n) ;


	////插入以及打印
	/*printf("\n请输入第i号数据，我将在它之前插入一个新数据：");
	scanf_s("%d", &n);
	insert(first, n);
	print(first);
	printf("\n链表长度为：%d\n", len);*/



	////删除以及打印
	//printf("\n请输入要删除的第i号数据：");
	//scanf("%d",&n);
	//delet(first,n);
	//print(first);
	//printf("\n链表长度为：%d\n",len);



   ////链表的反转
	/*int a = 0;
	int b = 0;
	printf("请输入你想要反转的范围");
	scanf_s("%d %d", &a, &b);
	reversal(first, a, b);*/


	////输出倒数前k个
	//int b = 0;
	//printf("请输入你想要的倒数第k个数据\n");
	//scanf_s("%d", &b);
	//printlast(first, b);


	////查找中间的数据
	//FindMiddleOneTime(first);



	return 0;

}
