#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int QElemenType;

typedef struct QNode
{
	QElemenType data;
	struct QNode *next;
 } QNode;
 
 typedef struct 
 {
 	QNode *front;  //��ͷָ�� 
 	QNode *rear;   //��βָ�� 
 }LinkQueue;
 
 int InitQueue(LinkQueue q)
 {  //����һ���յĶ���Q 
 	q.front=(QNode*)malloc(sizeof(QNode));
 	if(!q.front) 
 	{
 		printf("overflow");
 		return 0;
	  } 
	 q.rear=q.front;
	 q.front->next=NULL;
	 return 1; 
 }
 
 int DestroyQueue (LinkQueue *q)
 {   //���ٶ���Q 
 	while(q->front)
 	{
 		q->rear=q->front->next;
 		free(q->front);
 		q->front=q->rear;
	 }
	 return 1;
 }
 
 int EnQueue(LinkQueue *q,QElemenType e)
 {    //����Ԫ��eΪQ���µĶ�βԪ�� 
 	QNode *p;
 	p=(QNode*)malloc(sizeof(QNode));   //�洢����ʧ�� 
 	if(!p) return 0;
 	p->data=e;
 	p->next=NULL;
 	q->rear->next=p;
 	q->rear=p;
 	return 1;
 }
 
 int DeQueue(LinkQueue *q,QElemenType *e)
 {      //�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������1 
 	QNode *p;
 	if(q->front==q->rear) return 0;
 	p=q->front->next;
 	*e=p->data;
 	q->front->next=p->next;
 	if(q->rear==p) q->rear=q->front;
 	free(p);
 	return 1;
 }

