#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define MAX 20
# define INFINITY 65535
typedef int VexType;
typedef  VexType Mgraph[MAX][MAX]; /* Mgraph�Ƕ�ά�������ͱ�ʶ�� */
enum BOOL {
	FALSE, TRUE
};
/* ����ԭ������ */
void creat_mg(Mgraph G);
void out_mg(Mgraph G);
Mgraph G1;                         /*  G1���ڽӾ���Ķ�ά������  */
int n, e, v0;

void ShortestPath_FLOYD(Mgraph G, BOOL P[][MAX][MAX], VexType D[][MAX]) {
	for(int v=0;v<n;v++)
		for (int w = 0; w < n; w++) {
			D[v][w] = G[v][w];
			for (int u = 0; u < n; u++)P[v][w][u] = FALSE;
			if (D[v][w] < INFINITY) {
				P[v][w][v] = TRUE; P[v][w][w] = TRUE;
			}
		}
	for(int u=0;u<n;u++)
		for(int v=0;v<n;v++)
			for (int w = 0; w < n; w++)
			{
				if (D[v][u] + D[u][w] < D[v][w]) {
					D[v][w] = D[v][u] + D[u][w];
					for (int i = 0; i < n; i++) {
						if (P[v][u][i] == TRUE || P[u][w][i] == TRUE)P[v][w][i] = TRUE;
						else P[v][w][i] = FALSE;
					}
				}
			}
}
/*  ������ */
int main()
{
	creat_mg(G1);
	BOOL P[MAX][MAX][MAX];
	VexType D[MAX][MAX];
	out_mg(G1);
	ShortestPath_FLOYD(G1, P,D);
	printf("\n");
	printf("��������·��������Ϊ����ţ���\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				if (i == j)printf(" ");
				else if(P[i][j][k]!=0)printf("%d", k+1);
			}
			printf("  ");
		}printf("\n");
	}
	printf("��������·������Ϊ��\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			printf("%d ", D[i][j]);
		}printf("\n");
	}
	printf("\n\n   ��س�����������");char ch = getch();
	return 0;
}
/*  �����ڽӾ���  */
void creat_mg(Mgraph G)
{
	int i, j, k, w;
	printf("\n  n,e = ? ");
	scanf("%d,%d", &n, &e);  /* ���붥����n������e */
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			G[i][j] = INFINITY;
			if (i == j)G[i][j] = 0;
		}
	/* ���������G[i][j]=0��ΪG[i][j]=32767�����*/
	for (k = 0; k < e; k++)                                /* ��֯������ѭ��  */
	{
		printf("\n  vi,vj,W= ? ");
		scanf("%d,%d,%d", &i, &j, &w);          /* ����һ���ߵ�����������i,j */
		G[i - 1][j - 1] = w; //G[j][i] = w;            /* ����ͼ���ڽӾ����ǷǶԳƾ��� */
							 /* �����������Ҫ����ߵ�Ȩֵw������G[i][j]=w */
	}
} /* creat_mg */
  /* �ڽӾ���������Ϊ�˼�������Ƿ���ȷ */
void out_mg(Mgraph G)
{
	int i, j, k;  char ch;
	for (i = 0; i < n; i++)        /*  ����ԭ����� */
	{
		printf("\n ");
		for (j = 0; j < n; j++) {
			if (G[i][j] == INFINITY) {
				printf("�� ");
			}
			else printf("%d ", G[i][j]);
		}
	}
	/*  ��������ڵı� */
	for (i = 0; i <n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] <65535 && G[i][j]>0)printf("\n ���ڱ�< %d, %d >", i + 1, j + 1);
	printf("\n\n   ��س�����������"); ch = getch();
}
