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

//��ӡ
void SListPrint(SLTNode* phead);

//β��
void SListPushBuck(SLTNode** pphead,SLTDateType x);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDateType x);

//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);

//����һ��ֵΪx�ĵ�ַ
SLTNode* SlistFind(SLTNode* phead, SLTDateType x);

//�޸�
//void SListRevise(SLTNode** pphead, SLTNode* pos, SLTDateType x)
//����;
void SListRevise(SLTNode** pphead,int pos, SLTDateType x);

//��posλ��֮ǰ����һ���ڵ�
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//����
void SListInsert(SLTNode** pphead, int pos, SLTDateType x);

//��posλ��֮�����һ���ڵ㣨�򵥣�
void SListInsertAfter(SLTNode* pos, SLTDateType x);


//��posλ��ɾ��һ���ڵ�
void SListEase(SLTNode** pphead, SLTNode* pos);

//��posλ��֮��ɾ��һ���ڵ�
void SListEaseAfter(SLTNode* pos);

//��������
void SListDestory(SLTNode** pphead);

//�������ȱ�ݻ��Ǻܶ�ģ�������������ɾ��ĵ����岻��
//1���ܶ�OJ�⿼��Ķ��ǵ�����
//2��������������ȥ�����Ӷ����ݽṹ���ӽṹ����ϣ���ڽӱ�
