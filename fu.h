#pragma once

typedef int SLTDateType;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;

}SLTNode;

//打印
void SListPrint(SLTNode* phead);

//尾插
void SListPushBuck(SLTNode** pphead,SLTDateType x);
//头插
void SListPushFront(SLTNode** pphead, SLTDateType x);

//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);

//查找一个值为x的地址
SLTNode* SlistFind(SLTNode* phead, SLTDateType x);

//修改
//void SListRevise(SLTNode** pphead, SLTNode* pos, SLTDateType x)
//或者;
void SListRevise(SLTNode** pphead,int pos, SLTDateType x);

//在pos位置之前插入一个节点
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//或者
void SListInsert(SLTNode** pphead, int pos, SLTDateType x);

//在pos位置之后插入一个节点（简单）
void SListInsertAfter(SLTNode* pos, SLTDateType x);


//在pos位置删除一个节点
void SListEase(SLTNode** pphead, SLTNode* pos);

//在pos位置之后删除一个节点
void SListEaseAfter(SLTNode* pos);

//销毁链表
void SListDestory(SLTNode** pphead);

//单链表的缺陷还是很多的，单纯单链表增删查改的意义不大
//1、很多OJ题考察的都是单链表
//2、单链表更多的是去更复杂度数据结构的子结构。哈希表、邻接表
