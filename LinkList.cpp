#include "lb.h"
#include<stdio.h>
#include<stdlib.h>
/*
��main�����У��ѽ����˴�������֮��ĺ���ȫ��ע�͡�����ʹ��������ȡ��ע��
*/
typedef struct node {
	int x;
	int index;
	struct node* next;
	struct node* prior;
}node;
int len;
/*
β�巨��������
*/
node* create_tail(struct node*& first) {
	first = (node*)malloc(sizeof(node));
	int a;
	struct node* p, * q;
	if (first == NULL) {
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	first->next = NULL;
	first->prior = NULL;
	q = first;
	len = 0;
	printf("\n��������������(��Ҫ�Կո��β��������Ҫ������һ������)��\n");
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
ͷ�巨��������
*/
node* create_head(struct node*& first) {
	first = (node*)malloc(sizeof(node));
	int a;
	struct node* p, * q;
	if (first == NULL) {
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	first->next = NULL;
	first->prior = NULL;
	q = first;
	len = 0;
	printf("\n��������������(��Ҫ�Կո��β��������Ҫ������һ������)��\n");
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
ʵ�������ӡ����
*/
void print(struct node*& first) {
	printf("��ӡ����\n");
	struct node* p;
	p = first->next;
	while (p != NULL) {
		printf("%d  ", p->x);
		p = p->next;
	}
	printf("\n");
}
/*
ʵ�ֲ��ҵ�ĳ���ڵ������
*/
void find(struct node*& first, int n) {
	int i;
	struct node* p = first;
	if (n == 0 || p == NULL || n > len) {
		printf("\n������\n");
	}
	else {

		for (i = 1; i <= n; i++) {
			p = p->next;
		}
		n = p->x;
		printf("������ҵ�����Ϊ��%d  \n", n);
	}

}

/*
ʵ�ֲ������
*/
void insert(struct node*& first, int n) {
	struct node* p, * new1;
	int i;
	p = first;
	new1 = (node*)malloc(sizeof(node));
	new1->next = NULL;
	new1->prior = NULL;
	if (n == 0 || p == NULL || n > len) {
		printf("\n����ʧ��\n");
	}
	else {

		for (i = 1; i <= n; i++) {
			p = p->next;
		}
		printf("\n�������½ڵ�����ݣ�\n");
		scanf_s("%d", &(new1->x));
		new1->next = p;
		new1->prior = p->prior;
		p->prior->next = new1;
		p->prior = new1;
		len++;
	}
}
/*
ʵ��ɾ��ָ���ڵ�
*/
void delet(struct node*& first, int n) {
	struct node* p;
	p = first;
	int i;
	if (n == 0 || p == NULL || n > len) {
		printf("\nɾ��ʧ��\n");
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
ʵ������ķ�ת��֧�ֲ��ַ�ת
*/
void reversal(struct node*& first, int a, int b) {
	int i = 0;
	int j = 0;
	struct node* p, * q;
	p = first;
	q = first;
	if (a<0 || b>len || a > b) {
		printf("�����������");
		exit(1);
	}
	else {
		for (int i = 0; i < a; i++) {
			//p->x = a���ڵĽڵ�
			p = p->next;
		}
		printf("p->x = %d\n", p->x);
		for (int i = 0; i < b; i++) {
			//q->x = b���ڵĽڵ�
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
���������k������
*/
void printlast(struct node*& first, int a) {
	struct node* p;
	p = first;
	if (a > len) {
		printf("�����������");
	}
	else {
		for (int i = 0; i < len - a; i++) {
			p = p->next;
		}
		print(p);
	}
}
/*
һ�α��������м�����
*/
void FindMiddleOneTime(struct node*& first) {
	struct node* p;
	p = first->next;

	while (p->index <= len / 2) {
		p = p->next;
	}
	if (len % 2 == 0) {
		printf("(������Ϊż���м�����������)\n�����м������Ϊ��%d %d", p->prior->x, p->x);
	}
	else {
		printf("\n�����м������Ϊ��%d", p->x);
	}
}

int main() {

	////�����Լ���ӡ���� 
	char ch;
	int n;
	struct node* first;
	create_tail(first);
	print(first);
	printf("\n������Ϊ��%d", len);


	////�����Լ���ӡ 
	//scanf("%c",&ch);
	//
	//printf("\n����������ҵ����ݵ���ţ�");
	//scanf("%d",&n);
	//find(first,n) ;


	////�����Լ���ӡ
	/*printf("\n�������i�����ݣ��ҽ�����֮ǰ����һ�������ݣ�");
	scanf_s("%d", &n);
	insert(first, n);
	print(first);
	printf("\n������Ϊ��%d\n", len);*/



	////ɾ���Լ���ӡ
	//printf("\n������Ҫɾ���ĵ�i�����ݣ�");
	//scanf("%d",&n);
	//delet(first,n);
	//print(first);
	//printf("\n������Ϊ��%d\n",len);



   ////����ķ�ת
	/*int a = 0;
	int b = 0;
	printf("����������Ҫ��ת�ķ�Χ");
	scanf_s("%d %d", &a, &b);
	reversal(first, a, b);*/


	////�������ǰk��
	//int b = 0;
	//printf("����������Ҫ�ĵ�����k������\n");
	//scanf_s("%d", &b);
	//printlast(first, b);


	////�����м������
	//FindMiddleOneTime(first);



	return 0;

}
