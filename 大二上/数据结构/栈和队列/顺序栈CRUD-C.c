#include <stdio.h>
#include <stdlib.h>
#define SElemType int
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//����p46 
//http://blog.csdn.net/sszgg2006/article/details/7555974 

/************************ջ��˳��洢��ʾ**************************/

/********************** �ṹ�嶨�岿�� **********************/
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
/************************ �����鲿�� ************************/

/**********************����һ���յ�ջ **********************/
int InitStack(SqStack *S)
{
    S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S->base)
       exit(0);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return 1;
}
/**********************����ջ************************/
void DestroyStack(SqStack *S)
{
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
}
/**********************���ջ************************/
int ClearStack(SqStack *S)
{
	S->top=S->base;
	S->stacksize=0;
	return 1;	
} 
/**********************ջ�Ƿ�Ϊ��************************/
int StackEmpty(SqStack S)
{
	if (S.top==S.base) 
	return 1;	          //��
	else return 0;       
} 
/**************��e����ջ��Ԫ��**************/
int GetTop(SqStack S,SElemType *e)
{
    if (S.top==NULL)
      return 0;
    *e=*(S.top-1);
    return 1;
}
/**************�õ�ջ�ĳ���**************/
int StackLength(SqStack S)
{
    if (S.top==S.base)
      return 0;
   else
    return (S.top-S.base);
}
/************����Ԫ��eΪ�µ�ջ��Ԫ��************/
int Push(SqStack *S,SElemType e)
{
    if(S->top-S->base >=S->stacksize)   //ջ����׷�Ӵ洢�ռ� 
  {
    S->base=(SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
    if(!S->base)
      exit(0);    //�洢����ʧ�� 
     
    S->top = S->base + S->stacksize;
    S->stacksize +=STACKINCREMENT;
  }
  *(S->top)++=e;
  return 1;
}
/********************** ��S���գ�ɾ��ջ��Ԫ�أ���e������ֵ **********************/
int Pop(SqStack *S,SElemType *e)
{
    if(S->top == S->base)
    return 0;
  *e = *--S->top;
  return 1;
}
/********************** ��ʾջ�ڵ�Ԫ��  **********************/
void DisplayStack(SqStack S)
{
     if(StackEmpty(S)==1)
     exit(-1);
     while(S.top!=S.base)
     printf("%d ",*(--S.top));
}
/********** ��ջ�׵�ջ�����ζ�*****************************
 ***********ջ��ÿ��Ԫ�ص��ú���visit����*****************/
int StackTraverse(SqStack S,int(*visit)(SElemType))
{
   SElemType *p;
   p=S.base;
   int i,result;
   for(i=1;i<=S.top-S.base;i++)
   {
   	 result=visit(*p++);   //visit��1���й��ԣ�0û����  
		if (result==0)
	     return 0; 
   }
   return 1;    //l�������Ԫ�ؾ���visit�й��� 
}
/*************************������*********************/ 
int main()
{
	SqStack q1;
	InitStack(&q1);
	int a,b,c;
	while(~scanf("%d",&a))
	{
		Push(&q1,a);
	}
	printf("\n");
	printf("my stack is:");
	while(!StackEmpty(q1))
	{
		GetTop(q1,&b);
		printf("%d ",b);
		Pop(&q1,&c);	
	}
	DestroyStack(&q1);
}








