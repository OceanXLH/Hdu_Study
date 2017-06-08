#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char *ch;
    int length;
}HString;
int StrAssign(HString *T, char *chars)   //����һ����ֵ����chars�Ĵ�
{
    if(T->ch)
    	{
    	//	free(T->ch);
    		T->ch=NULL;
    		T->length=0;
    	}
    if(!chars) return 0;
    if (!(T->ch=(char*)malloc((strlen(chars)+1)*sizeof(char)))) return 0;
    strcpy(T->ch,chars);
    T->length=strlen(chars);
    return 1;
}
int StrLength(HString S)    //����S��Ԫ�ظ�������Ϊ���ĳ���
{
    return S.length;
}
int StrCompare(HString S, HString T)
//��s>t,�򷵻�ֵ>0;����ȣ�=0����s<t,����<0
{
    int i;
    for(i = 0; i < S.length && i < T.length; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;

}
int ClearString(HString *S)
{
    //��s��Ϊ�մ�
    if (S->ch)
    {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;
    return 1;
}
int Concat(HString *T, HString s1, HString s2)
{
    //��T����s1��s2������ɵ��´�
    if (T->ch!=NULL)
        free(T->ch);  //�ͷžɿռ�
    if (!(T->ch = (char *)malloc((s1.length + s2.length) * sizeof(char))))
        exit (0);
    T->length = s1.length + s2.length;
    int i = 0;
    for(i = 0; i < s1.length; i++)
        *(T->ch + i) = s1.ch[i];
    for(i; i - s1.length < s2.length; i++)
        *(T->ch + i) = s2.ch[i - s1.length];
    return 1;

}


int SubString(HString *sub, HString s, int pos, int len)
{
    //��sub���ش�s�ĵ�pos���ַ��𳤶�Ϊlen���ִ�
    // ���У�1<=pos<=StrLength(s)��0<=len<=StrLength(s)-pos+1
    if (pos < 1 || StrLength(s) < pos || len < 0 || StrLength(s) - pos + 1 < len)
        return 0;
    if(sub->ch)
        free(sub->ch);
    if(!len)
    {
        sub->ch = NULL;
        sub->length = 0;
    }
    sub->ch=(char*)malloc(sizeof(char)*(len+1));
    for (int i = 0; i < len; ++i)
    {
        /* code */
       sub->ch[i] = s.ch[pos - 1 + i];
    }
    sub->ch[len]='\0';
    sub->length = len;
    return 1;
}
void printStr(HString s)
{
  printf("%s\n",s.ch );
}
int main()
{
    HString s1,s2,s3;
    char s[]="12345";
    StrAssign(&s1, s);
    SubString(&s2,s1,2,2);
    printStr(s1);printStr(s2);
    printf("%d\n", StrLength(s2) );
}

