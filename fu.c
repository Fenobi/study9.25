#define _CRT_SECURE_NO_WARNINGS

#include "fu.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
}

//�����¿ռ�
SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fil\n");
		exit(-1);
	}

	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBuck(SLTNode** pphead, SLTDateType x)//ע���Ƕ���ָ�룡
{
	assert(pphead != NULL);

	//����
	/*SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

	newnode->date = x;
	newnode->next = NULL;*/

	SLTNode* newnode = BuyListNode(x);


	//��һ���ڵ㲻��β
	if (*pphead == NULL)
	{
		*pphead = newnode;
		newnode = *pphead;
	}
	else
	{
		SLTNode* tail = *pphead;
		//�ҵ�β�ڵ�
		while (tail->next != *pphead)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		newnode->next = *pphead;
	}
}

void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(*pphead);

	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;

}

void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);

	if ((*pphead)->next == *pphead)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != *pphead)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = *pphead;

		/*	SLTNode* tail = *pphead;
			while (tail->next->next)
			{
				tail = tail->next;
			}
			free(tail->next);
			tail->next = NULL;*/
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);

	SLTNode* next = *pphead;
	(*pphead) = (*pphead)->next;
	free(next);

}

SLTNode* SlistFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}

void SListRevise(SLTNode** pphead, int pos, SLTDateType x)
{
	SLTNode* cur = SlistFind(*pphead, pos);
	if (cur)
	{
		cur->date = x;
	}
}

//��pos֮�����һ���ڵ㣨�򵥣�
void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);

	if (*pphead == pos)
	{
		/**pphead = pos->next;
		free(pos);*/
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEaseAfter(SLTNode* pos)
{
	assert(pos->next != NULL);

	SLTNode* next = pos;
	pos->next = next->next;
	free(next);
	//next = NULL;
}

void SListDestory(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

void SListInsert(SLTNode** pphead, int pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	SLTNode* cur = SlistFind(*pphead, pos);
	if (*pphead == cur)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLTNode* posPrev = *pphead;
		while (posPrev->next != cur)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = cur;

	}
}

int main()
{
	int n = 5;
	int m = 2;
	SLTNode* p = NULL;
	for (int i = 1; i <= n; i++)
	{
		SListPushBuck(&p, i);
	}
	while (p != p->next)
	{
		for (int i = 0; i < m; i++)
		{
			p = p->next;
		}
		SListPopFront(&p);

	}
}