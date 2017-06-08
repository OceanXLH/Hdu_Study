# include <stdio.h>
# include <stdlib.h>
#include <conio.h>
# define MAX 20
#define NULL 0
typedef int QElemType;
//�ڵ�
typedef struct Queue
{
	QElemType data;
	struct Queue *next;
}QNode, *QueuePtr;
//����(ͷβָ��)
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
enum Status
{
	OK, ERROR, OVERFLOW
};
enum BOOL		
{
	FALSE, TRUE
};
//����ն��� OK
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);//�ڴ�����
	Q->front->next = NULL;
	return OK;
}
//���ٶ���Q OK
Status DestoryQueue(LinkQueue *Q)
{
	while (Q->front)//����nextָ��ָ��ΪNULL
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//��� OK
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;//�ڶ�β��ӽڵ�
	Q->rear = p;
}
//���� OK
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)return ERROR;//��Ϊ�գ���ɾ��
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}
//���Ϊ�ն��� OK
Status ClearQueue(LinkQueue *Q)
{
	if (DestoryQueue(Q) == ERROR)return ERROR;
	if (InitQueue(Q) == ERROR)return ERROR;
	return OK;
}
//�ж϶����Ƿ�Ϊ�� OK
BOOL QueueEmpty(LinkQueue *Q)
{
	if (Q->front == Q->rear&&Q->front != NULL)return TRUE;
	else return FALSE;
}
//��ȡ����ͷԪ�� OK
Status GetHead(LinkQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q) == FALSE)
	{
		*e = Q->front->next->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}
//���г��� OK
int QueueLength(LinkQueue *Q)
{
	QueuePtr p = Q->front;
	int result = 0;
	while (p != NULL&&p->next != NULL)
	{
		result++;
		p = p->next;
	}
	return result;
}
typedef int VexType;
typedef  struct Vnode
{
	VexType data;
	struct Vnode *next;
}Vnode;                           /* Vnode�Ƕ���Ľ��ṹ */
typedef Vnode Lgraph[MAX];      /* Lgraph��һά�������ͱ�ʶ�� */
								/* ����ԭ������ */
void creat_L(Lgraph G);
void out_L(Lgraph G);
void dfsL(Lgraph G, int v);
void bfsL(Lgraph g, int v);
Lgraph Ga;                      /*  Ga���ڽ�����ı�ͷ������  */
int n, e, vis[MAX];
/*  ������ */
int main()
{
	int v1, i;
	char ch;
	for (i = 0; i<MAX; i++) vis[i] = 0;     /*  ������ʵı�־����   */
	creat_L(Ga);                     /*   ����ͼ�ڽ�����Ga    */
	out_L(Ga);                             /*  ����ڽ�����Ga */
	printf("\n "); scanf("%d", &v1);
	dfsL(Ga, v1);     /* �Ӷ���v1��ʼ����ͼGa����������ȱ��� */
	for (i = 0; i<MAX; i++) vis[i] = 0;     /*  ������ʵı�־����   */
	printf("\n������ȱ�����");
	bfsL(Ga, v1);
	printf("\n\n   ��س�����������"); ch=getch();

	return 0;
}/* main */
 /* �����ڽ�����  */
void creat_L(Lgraph G)
{
	Vnode *p, *q;  int i, j, k;
	printf("���� n,e=?"); scanf("%d,%d", &n, &e);
	for (i = 1; i <= n; i++) { G[i].data = i; G[i].next = NULL; }
	for (k = 1; k <= e; k++)
	{
		printf("���� vi,vj=?"); scanf("%d,%d", &i, &j);
		p = (Vnode *)malloc(sizeof(Vnode));
		p->data = i;
		p->next = G[j].next; G[j].next = p;   /* p������ӵ���j���� */
		q = (Vnode *)malloc(sizeof(Vnode));
		q->data = j;
		q->next = G[i].next; G[i].next = q;  /* q������ӵ���i����  */
	}
}/*  creat_L */
 /*  �ڽ�����ļ������Ϊ�˼�������Ƿ���ȷ  */
void out_L(Lgraph G)
{
	int i; Vnode *p; char ch;
	for (i = 1; i <= n; i++)
	{
		printf("\n i=%d", i);
		p = G[i].next;
		while (p != NULL) { printf("%5d", p->data); p = p->next; }
	}
	printf("\n\n   ��س�����������"); ch=getch();
} /* out_L */
  /* ������ȱ���ͼ */
void dfsL(Lgraph G, int v)
{
	Vnode *p;
	printf("%3d", G[v].data);  vis[v] = 1; /*  ����v�����ʣ���־��1 */
	p = G[v].next;
	while (p)
	{
		v = p->data;
		if (vis[v] == 0)dfsL(G, v);  /* ����vδ������ʱ�������� */
		p = p->next;
	}
}/* dfs  */
 /* ������ȱ���ͼ  */
void bfsL(Lgraph g, int v)
{
	char ch;
	LinkQueue Q;
	InitQueue(&Q);
	printf("\n %d", g[v].data); vis[v] = 1;  EnQueue(&Q, v);
	while (!QueueEmpty(&Q))
	{
		QElemType X;
		DeQueue(&Q,&X);
		Vnode *p = g[X].next;
		while (p!=NULL)
		{
			v = p->data;
			if (vis[v] == 0)
			{
				printf("\n %d", g[v].data);
				vis[v] = 1;  EnQueue(&Q, v);
			}
			p = p->next;
		}
	}
	printf("\n\n   ��س�����������"); ch=getch();
} /* bfsL  */