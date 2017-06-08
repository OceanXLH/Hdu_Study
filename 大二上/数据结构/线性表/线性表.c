#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int element;
    struct Node *next;
}Node;

/*�½�һ��������*/
Node * creatList(Node *pHead)
{
    Node *p1,*p2;
    p1=p2=(Node *)malloc(sizeof(Node));                 //�����½ڵ�
    if(p1 == NULL || p2 ==NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    printf("������һ����һ�����0������:");
    scanf("%d",&p1->element);                           //�����½ڵ�
    pHead = NULL;                                    //ͷ�ڵ��ָ����Ϊ��
    while(p1->element !=0)                              //�����ֵb������?�������ֱ�������ֵΪ?
    {
        if(pHead == NULL)                              //�ձ������ͷ
        {
            pHead = p1;
        }
        else
        {
            p2->next = p1;                             //�ǿձ������β
        }
        p2 = p1;
        p1=(Node *)malloc(sizeof(Node));    //��������һ���ڵ�
        if(p1 == NULL || p2 ==NULL)
        {
        printf("�ڴ����ʧ��\n");
        exit(0);
        }
        scanf("%d",&p1->element);
        p2->next = NULL;
    }
    printf("creatList����ִ�У��������ɹ�\n");
    return pHead;                          //���������ͷָ��
}

/*��������е�����*/
void printList(Node *pHead)
{
    if(pHead == NULL)   //����Ϊ��
    {
        printf("PrintList����ִ�У�����Ϊ��\n���������0���������ݣ�\n");
    }
    else
    {
        printf("�����������£�");
        while(pHead != NULL)
        {
            printf("%d ",pHead->element);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

/*ɾ����������*/
void clearList(Node *pHead)
{
    Node *pNext;            //����һ����pHead���ڽڵ�

    if(pHead == NULL)
    {
        printf("clearList����ִ�У�����Ϊ��\n");
        return;
    }
    while(pHead->next != NULL)
    {
        pNext = pHead->next;//������һ����ָ��
        free(pHead);
        pHead = pNext;      //��ͷ����
    }
    printf("clearList����ִ�У������Ѿ����\n");
}

/*���ص������е�Ԫ�ظ��� */
int sizeList(Node *pHead)
{
    int size = 0;
    while(pHead != NULL)
    {
        size++;                     //��������size��С�������ʵ�ʳ���С1
        pHead = pHead->next;
    }
    printf("sizeList����ִ��,������Ϊ %d \n",size);
    return size;    //�����ʵ�ʳ���
}

/*���ص������е�pos������е�Ԫ�أ���pos������Χ����ֹͣ��������*/
int getElement(Node *pHead, int pos)
{
    int i=0;
    if(pos < 1)
    {
        printf("getElement����ִ��,posֵ�Ƿ�\n");
        return 0;
    }
    if(pHead == NULL)
    {
        printf("getElement����ִ��,����Ϊ��\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //�Ƶ���һ���
    }
    if(i < pos)                  //�����Ȳ������˳�
    {
        printf("getElement����ִ�У�posֵ����������\n");
        return 0;
    }
    return pHead->element;
}

/*�ѵ������е�pos������ֵ�޸�Ϊx��ֵ,���޸ĳɹ����أ�,���򷵻أ�*/
int modifyElem(Node *pNode,int pos,int x)
{
    Node *pHead;
    pHead = pNode;
    int i = 0;

    if(NULL == pHead)
    {
        printf("modifyElem����ִ�У�����Ϊ��\n");
    }
    if(pos < 1)
    {
        printf("modifyElem����ִ�У�posֵ�Ƿ�\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //�Ƶ���һ���
    }
    if(i < pos)                  //�����Ȳ������˳�
    {
        printf("modifyElem����ִ�У�posֵ����������\n");
        return 0;
    }
    pNode = pHead;
    pNode->element = x;
    printf("modifyElem����ִ��\n");

    return 1;
}
/*ɾ�������е�ĳ�����*/
Node *deleteElem(Node *pNode,int pos)
{
    Node *pHead;
  //  pHead = pNode;
    int i = 0;
    if(NULL == pNode)
    {
        printf("deleteElem����ִ�У�����Ϊ��\n");
    }
    if(pos < 1)
    {
        printf("delete����ִ�У�posֵ�Ƿ�\n");
        return 0;
    }
    while(pNode !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pNode = pNode->next; //�Ƶ���һ���
    }
    if(i < pos)                  //�����Ȳ������˳�
    {
        printf("deleteElem����ִ�У�posֵ����������\n");
        return 0;
    }
    pHead = pNode->next;
    free(pNode);
    printf("deleteElem����ִ��\n");

    return pHead;
}
/*�鲢��������*/
void MergeList(Node *a,Node *b, Node *c){
    //��֪������a��b��Ԫ�ذ�ֵ�ǵݼ�����
    //�鲢������a��b�õ��µĵ�����c,c��Ԫ��Ҳ���ǵݼ�����
    Node *pa=a->next,*pb=b->next;
    Node *pc=a;
    c=pc=a;  //��a��ͷ�ڵ���Ϊc��ͷ���
    while(pa&&pb){
        if(pa->element<=pb->element){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;    //����ʣ���
    free(b);       //�ͷ�b��ͷ���
}
int main()
{
    Node *pt=NULL,*pb=NULL,*pc=NULL;
    pt=creatList(pt);
    pb=creatList(pb);
    MergeList(pt,pb,pc);
    printList(pc);
    sizeList(pt);
    printf("��Ҫ���صڼ����������֣�");
    int n,i;
    scanf("%d",&n);
    i=getElement(pt,n);
    printf("%d\n",i);
    printf("����Ҫ���ڼ�������Ϊʲô:");
    int p,q;
    scanf("%d%d",&p,&q);
    modifyElem(pt,p,q);
    printList(pt);
    printf("����Ҫ���ڼ������ɾ��:");
    int m;
    scanf("%d",&m);
    pt=deleteElem(pt,m);
    printList(pt);
    clearList(pt);
    return 0;
}
