#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*Linklist;

void delx(Linklist &L,int x) {
	LNode* p = L->next, * pre = L;
	while (p->next) {
		if (p->data == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//尾插法
Linklist CreateList(Linklist& L) {
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	LNode* s, * r = L; 
	printf("请输入插入链表的值:\n");
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return L;
}
void ShowList(Linklist& L) {
	LNode* p = L->next;
	while (p) {
		printf("%d\t", p->data);
		p = p->next;
	}
}
void ReverseShow(Linklist L) {
	LNode* p = L->next, * r;
	L->next = nullptr;
	while (p) {
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}

	LNode* s = L->next;
	printf("反向输出的结果为：\n");
	while (s) {
		printf("%d", s->data);
		s = s->next;
	}
}
void SortList(Linklist& L) {
	LNode* p = L->next, * pre;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while (p) {
		r = p->next;
		pre = L;
		while (pre->next && pre->next->data < p->data)pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//删除指定的区间数
void DeleteAtoB(Linklist& L, int a, int b)
{
	LNode* p = L->next,*pre=L;
	while (p!=nullptr) {
		if (p->data >= a && p->data <= b) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//将链表分为奇数列和偶数列
Linklist DivideA(Linklist& A) {
	LNode* B = (LNode*)malloc(sizeof(LNode));
	LNode* p = A->next,*pre=A,*pb;
	B->next = nullptr;
	pb = B;
	while (p) {
		if (p->data % 2 == 0) {
			pre->next = p->next;
			p->next = pb->next;
			pb->next = p;
			p = pre->next;
			pb = pb->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	return B;
}
//将链表分为两列
Linklist DivideB(Linklist& L) {
	LNode* B = new LNode;
	LNode* p = L->next,*pre=L,*pb=B;
	int k = 1;
	B->next = nullptr;
	while (p) {
		if (k % 2 == 0) {
			pre->next = p->next;
			p->next = pb->next;
			pb->next = p;
			p = pre->next;
			k++;
		}
		else {
			pre = p;
			p = p->next;
			k++;
		}
	}
	return B;
}
//删除有序表重复值
void DeleteRipite(Linklist& L) {
	LNode* p = L->next->next,*pre=L->next;
	while (p) {
		if (p->data == pre->data) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//合并两个有序链表
Linklist MergeList(Linklist L1, Linklist L2) {
	LNode* B = new LNode;
	LNode* p1=L1->next, * p2=L2->next, * pb = B, * pre1=L1, * pre2=L2;
	B->next = nullptr;
	while (p1 && p2) {
		if (p1->data <= p2->data) {
			pre1->next = p1->next;
			p1->next = pb->next;
			pb->next = p1;
			p1 = pre1->next;
		}
		else {
			pre2->next = p2->next;
			p2->next = pb->next;
			pb->next = p2;
			p2 = pre2->next;
		}
	}
	while(p1) {
		pre1->next = p1->next;
		p1->next = pb->next;
		pb->next = p1;
		p1 = pre1->next;
	}
	while (p2) {
		pre2->next = p2->next;
		p2->next = pb->next;
		pb->next = p2;
		p2 = pre2->next;
	}
	return B;
}
//两链表的公共元素
Linklist CommonElem(Linklist A, Linklist B) {
	LNode* C = new LNode;
	C->next = nullptr;
	LNode* pa = A->next, * pb = B->next, * pc = C;
	while (pa && pb) {
		if (pa->data == pb->data) {
			LNode* s = new LNode;
			s->data = pa->data;
			s->next = pc->next;
			pc->next = s;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			pa = pa->next;
		}
		else {
			pb = pb->next;
		}
	}
	return C;
}
//两个链表的交集
void CrossElem(Linklist& A, Linklist B) {
	LNode* pa = A->next, * pb = B->next,*prea=A,*r=A;
	while (pa && pb) {
		if (pa->data == pb->data) {
			prea->next = pa->next;
			pa->next = r->next;
			r->next = pa;
			r = r->next;
			pa = prea->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			prea = pa;
			pa = pa->next;
		}
		else {
			pb = pb->next;
		}
	}
	r->next = nullptr;
}
//子列判断
bool IsSub(Linklist A, Linklist B) {
	LNode* pa = A->next, * pb = B->next;
	while (pa&&pb){
		while (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
			if (pb == nullptr)break;
		}
		if(pa)pa = pa->next;
		
	}
	return pb==nullptr;
}
void main() {
	Linklist L,L1; int x,a, b;
	LNode* B;
	printf("1.删除指定值\n2.反向输出链表\n3.排序\n4.删除指定区间数\n"
		"5.奇偶分离\n6.分离\n7.删除有序表重复值\n8.合并两个有序表\n"
		"9.两链表的公共元素\n10.两个链表的交集\n11.子列判断");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		CreateList(L);
		printf("请输入要删除的值:\n");
		scanf_s("%d", &x);
		delx(L, x);
		ShowList(L);
		break;
	case 2:
		CreateList(L);
		ReverseShow(L);
		break;
	case 3:
		CreateList(L);
		SortList(L);
		ShowList(L);
		break;
	case 4:
		CreateList(L);
		printf("请输入要删除区间:\n");
		scanf_s("%d", &a);
		scanf_s("%d", &b);
		DeleteAtoB(L,a,b);
		ShowList(L);
	case 5:
		CreateList(L);
		B = DivideA(L);
		printf("奇数列：\t");
		ShowList(L);
		printf("偶数列：\t");
		ShowList(B);
		break;
	case 6:
		CreateList(L);
		B = DivideB(L);
		printf("A列：\t");
		ShowList(L);
		printf("B列：\t");
		ShowList(B);
		break;
	case 7:
		printf("!(请输入有序表)\n");
		CreateList(L);
		DeleteRipite(L);
		ShowList(L); 
		break;
	case 8:
		printf("!(请输入有序表)\n");
		printf("请输入表1：\n");
		CreateList(L);
		printf("请输入表2：\n");
		CreateList(L1);
		B=MergeList(L, L1);
		ShowList(B);
		break;
	case 9:
		printf("!(请输入有序表)\n");
		printf("请输入表1：\n");
		CreateList(L);
		printf("请输入表2：\n");
		CreateList(L1);
		B = CommonElem(L, L1);
		ShowList(B);
		break;
	case 10:
		printf("!(请输入有序表)\n");
		printf("请输入表1：\n");
		CreateList(L);
		printf("请输入表2：\n");
		CreateList(L1);
		CrossElem(L, L1);
		ShowList(L);
		break;
	case 11:
		printf("请输入表1：\n");
		CreateList(L);
		printf("请输入表2：\n");
		CreateList(L1);
		a=IsSub(L, L1);
		printf("%d", a);
	}

}