#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
   char name[20];
   char sex[10];
   int num;
   float CN;       //����
   float MT;       //��ѧ
   float EN;       //Ӣ��
   float SC;       //��ѧ

}stu[40];
int NUM=0;
/*******************************************����*****************************************/  
 int F3_seek()
 {
 	void exitSy();
 	char a[10]; 
	 int i,j=-2,d,num; 
	 	int h=0,k;
	float s;
	float sum[40],ave[40],sum2[3][40];
  	system("cls");
    printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
         if (NUM==0)
            {
            	printf("��ǰ����0��ѧ�����ݣ��޷����в��Ҳ�����\n");
            	printf("�밴������������˵�...\n");
            	getchar();
            	return;
			}
			printf("1.���밴������ѯѧ��������\n"); 
		    printf("2.���밴ѧ�Ų�ѯѧ��������\n");
		    printf("3.�������˵�\n");
            printf("0.�˳�ϵͳ\n");
             printf("Tips:�������Ӧ���ֽ����Ӧ����\n\n");		
loop18:    num=getNum();
          if (num>3)
            {
      	      printf("��������ȷ��ָ�\n"); 
      	      goto loop18;
	        }
         switch (num)
           {
            	case 0:exitSy();break;
      	        case 1:  system("cls");
                         printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                         	printf("������ѧ��������\n");
                           printf("Tips������\"exit\"�˳�ϵͳ������\"back\"�ص����˵�...\n");
 loop3:                for(i=0;i<10;i++)
		                 a[i]='\0';      
                         gets(a);
                      if (strcmp(a,"exit")==0) 
                        	exitSy();
                        if (strcmp(a,"back")==0) 
                        	return -1; 
                       for (i=0;i<NUM;i++)
                          {
                       	      if (strcmp(a,stu[i].name)==0)
             	                  {
							          j=i; 
							          break;
								  } 
             	           }
			            if (j==-2) 
			                  { 
			   	               printf("���޴��ˣ����������룺\n");
			   	               goto loop3;
			                  }
		                 
				        break;
		        case 2:  system("cls");
                         printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                         	printf("������ѧ��ѧ�ţ�\n");
                           printf("Tips������\"exit\"�˳�ϵͳ������\"back\"�ص����˵�...\n");
 loop19:                for(i=0;i<10;i++)
		                 a[i]='\0';      
                         gets(a);
                      if (strcmp(a,"exit")==0) 
                        	exitSy();
                        if (strcmp(a,"back")==0) 
                        	return -1; 
                       for (i=0;i<NUM;i++)
                          { 
                       	      if ((strlen(a)==1&&atoi(a)==stu[i].num)||(strlen(a)==2&&atoi(a)==stu[i].num))
             	                  {
							          j=i; 
							          break;
								  } 
             	           }
			            if (j==-2) 
			                  { 
			   	                printf("���޴��ˣ����������룺\n");
			   	                goto loop19;
			                  }
		                 
				
				         break;
	        	case 3:return -1; 
	        }

		    
			system("cls");
           printf("\n*******************************************��ӭʹ�óɼ�����ϵͳ��*******************************************\n");
    printf("\n   ����    �Ա�   ѧ��   ���ĳɼ�(CN)   ��ѧ�ɼ�(MT)  Ӣ��ɼ�(EN)   ��ѧ�ɼ�(SC)   �ܷ�      ƽ����    ����\n");
        for (h=0;h<NUM;h++)
        {
           sum[h]=stu[h].CN+stu[h].MT+stu[h].EN+stu[h].SC; 
		   ave[h]=sum[h]/4.0;
		   sum2[0][h]=stu[h].CN+stu[h].MT+stu[h].EN+stu[h].SC; 
		}
	for(h=0;h<NUM;h++)
	 sum2[1][h]=h+1;
    for(h=0;h<NUM-1;h++)
    for(k=0;k<NUM-h-1;k++)
     {
     	if (sum2[0][k]<sum2[0][k+1])
     	  {
     	  	
		   	 s=sum2[0][k];
			 sum2[0][k]=sum2[0][k+1];
			 sum2[0][k+1]=s;
			 s=sum2[1][k];
			 sum2[1][k]=sum2[1][k+1];
			 sum2[1][k+1]=s;	 	
		  	 	
		  }
	 } 

	for(h=0;h<NUM;h++)
	  sum2[2][h]=h+1;   
	
	for(h=0;h<NUM-1;h++)
	for(k=0;k<NUM-h-1;k++)
     {
     	if (sum2[1][k]>sum2[1][k+1])
     	  {
     	  	
		   	 s=sum2[1][k];
			 sum2[1][k]=sum2[1][k+1];
			 sum2[1][k+1]=s;
			 s=sum2[2][k];
			 sum2[2][k]=sum2[2][k+1];
			 sum2[2][k+1]=s;	 	
		  	 	
		  }
	 }  

  	
	     printf(" %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f  |  %-6.2f  |  %-6.2f  |  %.0f \n",stu[j].name,stu[j].sex,stu[j].num,stu[j].CN,stu[j].MT,stu[j].EN,stu[j].SC,sum[j],ave[j],sum2[2][j]);
    	getchar(); 
		return j;    
		    
		

} 	
/***************************************�˳�ϵͳ***************************************************/ 
void exitSy()
{
	 printf("ϵͳ����  3  ���ر�..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ���ر�...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ���ر�...",1); 
		Sleep(1000);
	exit(0);
	
 } 

/***************************************�������-˵��***************************************************/ 
void saveAll()
{
	system("cls");
	printf("\n*****************************��ӭ����ɼ�����ϵͳ��*****************************\n");
  
	 printf("ϵͳ����  3  ��󱣴����..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ��󱣴����...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ��󱣴����...\n",1); 
		Sleep(1000); 
		printf("\n���ݱ�����ϣ��밴������ص����˵���\n");
		getchar(); 
 } 
 /*******************************************����*****************************************/  
 int key()
 {
 	
 	char a[10];
    int i;
    for (i=0;i<10;i++)
    {
    	a[i]=getch();
    	if (a[i]=='\b'&&i==0)
    {
		 	 a[i]='\0';
			  i--;
		    continue;
	}
	else if (a[i]=='\b'&&i>0)
	  {
	  	 printf("\b \b");
	  	 a[i]='\0';
	     i-=2;	 
	  }
	else if(a[i]==13)
	  {
	  	 a[i]='\0';
		 break;        
	  }
	else 		
	  	printf("*");   
    }
	if(strcmp(a,"0000")==0)
		    return 1;
	else return  0;
	
}
/*****************************************��¼*****************************************************/ 
void login()
{
	void menu();
	char a[10];  
	int  b=0;
	int i;
    printf("\n*****************************��ӭ����ɼ�����ϵͳ��*****************************\n");
    printf("����������");
	printf("��Tips������Ϊ�ĸ����֣��ܹ�3�λ��ᣩ:\n\n");
    for (i=4;i>0;i--)
	   {
	   	  b=key();
	   	  if (b==1)
	   	    break;
	   	  else if (i==2)
			   {
				 printf("\n�Բ��������������\n\n");
				 exitSy();
			   }
		  else
			 printf("\n�Բ����������������%d�λ��᣺\n\n",i-2);
	   	  	   
		
	   }
     
	 menu();  
	// if (b==2) exit(0);	
	
	
} 

/*****************************************��ʾ�˵�*****************************************************/ 
 void menu()
{
	void F1_get();
	void F8_save();
	void getData();
   void F2_change();
	void A_txtPrint();
	void F4_deletAll();
	 void F7_show();
	char a[50];
	char b[10];
	int  num,q;
	system("CLS");
	getData();                       //������� 
    printf("\n*****************************��ӭ����ɼ�����ϵͳ��*****************************\n");
	printf("¼��(1)\\�޸�(2)\\����(3)\\ɾ��(4)\\����(5)\\��ʾ(6)\\ͳ��(7)\\��ӡ(8)\\�˳�ϵͳ(0)\n");
    printf("(Tips:������˵��Աߵ����ֽ����Ӧ���ܣ�)\n\n");
	num=getNum();                   //�õ�һ����ȷ��ָ�� 
  switch (num)
	{
	    case 1:F1_get();break;
	    case 2:F2_change();break;
		case 3:q=F3_seek();
		       break;
		case 4:F4_deletAll();break;
		case 5:F5_sort();break;
    	case 6:F7_show();break;
		case 7:F7_statistics();break;
    	case 8:A_txtPrint();break;
	    case 0:exitSy();break;
	}
}
/*******************************¼��ÿ��ͬѧ��ѧ�š��������Ա�͸��ƵĿ��Գɼ�**************************/
  void F1_get()
  {
    void F8_save();
    int i,j,num;
    char a[10];
    char sub[][4]={"CN:","MT:","EN:","SC:"}; 
    float grades[4];
	system("CLS");
  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
  	printf("��ǰ��%d��ѧ�������ϣ�",NUM);
  	printf("�������뼸��ѧ������Ϣ��\n");
  
  	scanf("%d",&num);
  	getchar();
  
  	for(i=0;i<num;i++)
  	{
loop1: system("CLS");  	  
       printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
  	   printf("�������%dλѧ��������+�Ա�(��/Ů)+ѧ�ţ�\n",i+1);             
       printf("Tips���м����Իس��ֿ�\n"); 
       scanf("%s%*c%s%*c%d%*c",stu[NUM+i].name,stu[NUM+i].sex,&stu[i+NUM].num);
       printf("�������%dλѧ���ĳɼ���\n",i+1);
       printf("Tips�����ģ�CN������ѧ��MT����Ӣ�EN������ѧ��SC��\n"); 
       for (j=0;j<4;j++)
       {
       	  printf("%s",sub[j]);
       	  scanf("%f",&grades[j]);
	   }
	   getchar();
	  if (num==1||i==num-1)
	     printf("��ȷ��������ȷ�𣿣�Y/N/B/E��\n");
	  else
	    printf("��ȷ����ȷ��������һ���𣿣�Y/N/B/E��\n");
loop2:	   scanf("%s%*c",a);
	   if (a[0]=='Y')
	    {
	   	 stu[i+NUM].CN=grades[0];
	     stu[i+NUM].MT=grades[1];
	     stu[i+NUM].EN=grades[2];
	     stu[i+NUM].SC=grades[3];
	    
	     continue;
	    }
	   else if(a[0]=='N')
	    {
	      	system("CLS");
			goto loop1;	
		}
		 else if(a[0]=='B')
	    {
	        printf("\n�밴������������˵�������δ���棩...\n\n") ;
			getchar();
			return; 
		}
		else if(a[0]=='E')
	    {
	       
			exitSy();
		}
	  else
	    {
	   	   printf("��������ȷָ�Y/N��\n");
	   	   goto loop2; 
	    }
	   }
    NUM+=num;
   if (num!=0) F8_save();
    	// printf("%s  %s  %s   yuwen:%f    shuxue:%f    yingyu:%f   kexue:%f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC); 
}
/*******************************************���һ����ȷ��ָ��*****************************************/ 
int getNum()
{
	int num;
	char b[50];
	scanf("%s",b);
	getchar();
	if ((strlen(b)==1)&&b[0]>='0'&&b[0]<='9')
		num=b[0]-48;
		else 
		 {
		 	printf("��������ȷ��ָ�\n"); 
            num=getNum();
         }
     return num;
}

/*******************************************�������*****************************************/
void getData()
{
	FILE *p;
	int i=0,size;
	p=fopen("Student Grades.dat","rb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
	
   fseek(p,0L,2);
   size=ftell(p);
   if (size==0) NUM=0;
    else
	  {
	  	rewind(p);
	  	fread(&NUM,sizeof(int),1,p);
	   } 
  for(i=0;i<NUM;i++)
	 {
	 	rewind(p);
	 	fseek(p,sizeof(int)+i*sizeof(struct Student),0);
	 	fread(&stu[i],sizeof(struct Student),1,p);
       
	 }
   fclose(p);		

} 
/*******************************************�����޸�---�������ļ�(�л�)*****************************************/ 
void F8_save()
{
	
	int i=0;
	FILE *p;
	p=fopen("Student Grades.dat","wb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
  	fwrite(&NUM,sizeof(int),1,p);
	for (i=0;i<NUM;i++)
	  fwrite(&stu[i],sizeof(struct Student),1,p);
	fclose(p);
	saveAll(); 
}
/*******************************************�����޸�---�������ļ�(û��)*****************************************/ 
void F8_save1()
{
	
	int i=0;
	FILE *p;
	p=fopen("Student Grades.dat","wb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
  	fwrite(&NUM,sizeof(int),1,p);
	for (i=0;i<NUM;i++)
	  fwrite(&stu[i],sizeof(struct Student),1,p);
	fclose(p);
//	saveAll(); 
}
/*******************************************��ӡ---�ı��ĵ�*****************************************/ 
void A_txtPrint()
{
	int i=0;
	char head1[100]="*****************************��ӭʹ�óɼ�����ϵͳ��******************************\n"; 
	char head2[100]="\n   ����    �Ա�   ѧ��   ���ĳɼ�(CN)   ��ѧ�ɼ�(MT)   Ӣ��ɼ�(EN)   ��ѧ�ɼ�(SC)\n\n";
	FILE *p;
	p=fopen("ѧ���ɼ�.txt","w");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
	fputs(head1,p);
    fputs(head1,p);
    fputs(head1,p);
    fputs(head2,p);
    if (NUM!=0)
  	  for(i=0;i<NUM;i++)
	     fprintf(p," %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
        
			fclose(p);
}
/*******************************************�ɼ��޸�*****************************************/ 
void F2_change()
{
	int num,i,k,h,j=-2;
	char a[10];
	 char sub[][4]={"CN:","MT:","EN:","SC:"}; 
   
	 struct Student example;
	system("cls");
	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
   if (NUM==0)
     {
	  	printf("��ǰ����0λѧ��,�޷������޸� \n");
	  	printf("�밴������ص����˵�... \n");
	  	getchar();
		return;
	 }
	 system("cls");
	      j=F3_seek();
       if (j==-1) return; 
loop4:	      printf("\n1.�����޸�����\n");	
          printf("2.�����޸��Ա�\n");
          printf("3.�����޸�ѧ��\n");
          printf("4.�����޸����ĳɼ���CN��\n");
          printf("5.�����޸���ѧ�ɼ���MT��\n");
		  printf("6.�����޸�Ӣ��ɼ���EN��\n");
          printf("7.�����޸Ŀ�ѧ�ɼ���SC��\n");
          printf("8.�����޸�ȫ��\n"); 
		  printf("9.�������˵�\n");
		  printf("0.�˳�ϵͳ\n");	   	
          printf("Tips:������ָ�����ֽ����޸�\n");	   	
       num=getNum();
    switch (num)
	{
	    case 1:  system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                 printf("������������");
	             gets(example.name);
	        
	             printf("��ȷ����  %s  �޸�Ϊ  %s  �𣿣�Y\\N��",stu[j].name,example.name);
loop5:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     strcpy(stu[j].name,example.name);
				  	 break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop5;
				   }	 
	    case 2: system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("�������Ա�");
	             gets(example.sex);
	             printf("��ȷ����  %s  �޸�Ϊ  %s  �𣿣�Y\\N��",stu[j].sex,example.sex);
loop6:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     strcpy(stu[j].sex,example.sex);
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop6;
				   }	 
	    case 3: system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("������ѧ�ţ�");
	             scanf("%d",&example.num);
	             printf("��ȷ����  %d  �޸�Ϊ  %d  �𣿣�Y\\N��",stu[j].num,example.num);
loop7:	             for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].num=example.num;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop7;
				   }	 
		case 4: system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("���������ĳɼ���CN����");
	             scanf("%f",&example.CN);
	             getchar();
	             printf("��ȷ����  %.2f  �޸�Ϊ  %.2f  �𣿣�Y\\N��",stu[j].CN,example.CN);
loop8:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].CN=example.CN;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop8;
				   }
			
		case 5:system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("��������ѧ�ɼ���MT����");
	             scanf("%f",&example.MT);
	             getchar();
	             printf("��ȷ����  %.2f  �޸�Ϊ  %.2f  �𣿣�Y\\N��",stu[j].MT,example.MT);
loop9:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].MT=example.MT;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop9;
				   }
		case 6:system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("������Ӣ��ɼ���EN����");
	             scanf("%f",&example.EN);
	             getchar();
	             printf("��ȷ����  %.2f  �޸�Ϊ  %.2f  �𣿣�Y\\N��",stu[j].EN,example.EN);
loop10:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].EN=example.EN;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop10;
				   }
		case 7:system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("�������ѧ�ɼ���SC����");
	             scanf("%f",&example.SC);
	             getchar();
	             printf("��ȷ����  %.2f  �޸�Ϊ  %.2f  �𣿣�Y\\N��",stu[j].SC,example.SC);
loop11:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].SC=example.SC;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop11;
				   }
	    case 8: system("cls");
              	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                printf("������ѧ��������+�Ա�(��/Ů)+ѧ�ţ�\n");
                printf("Tips���м����Իس��ֿ�\n");
 				scanf("%s%*c%s%*c%d%*c",example.name,example.sex,&example.num);
 				printf("������ѧ���ĳɼ���\n");
 				printf("Tips�����ģ�CN������ѧ��MT����Ӣ�EN������ѧ��SC��\n"); 
      		    printf("%s",sub[0]);
       	 		scanf("%f",&example.CN);
	            printf("%s",sub[1]);
       	        scanf("%f",&example.MT);  
                printf("%s",sub[2]);
       	       scanf("%f",&example.EN); 
               printf("%s",sub[3]);
       	       scanf("%f",&example.SC);
               printf("��ȷ��������ȷ���޸��𣿣�Y\\N��");
loop12:	         for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j]=example;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop12;
				   }
	    case 9:return;
	    case 0:exitSy();
}
           printf("\n�޸ĺ��ѧ������Ϊ ��\n");
		   printf("%s  %s  %d   CN:%.2f    MT:%.2f    EN:%.2f   SC:%.2f\n",stu[j].name,stu[j].sex,stu[j].num,stu[j].CN,stu[j].MT,stu[j].EN,stu[j].SC); 
           printf("���ٴ�ȷ�ϣ�ȷ�������޸���(Y\\N)\n");
           printf("��Warning������һ���޸ģ����޷��ָ�����\n");
loop13:		   for(h=0;h<10;h++)
		      a[h]='\0';   
			gets(a);
			 if (a[0]=='Y'&&strlen(a)==1)
	          F8_save();
               else if (a[0]=='N'&&strlen(a)==1)
                {
                	printf("���ݱ���ʧ�ܣ��밴������ص����˵���\n");
				    getchar();
				    return;
			    }
			    else 
				  {
				  	 printf("��������ȷָ�\n");
				  	 goto loop13;
				   }
}
/*******************************************�ɼ�ɾ��*****************************************/  
void F4_delet()
{
	int i,h,j=-2;
	char a[10];
	struct Student example;
	system("cls");
	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
   if (NUM==0)
     {
	  	printf("��ǰ����0λѧ��,�޷�����ɾ������ \n");
	  	printf("�밴������ص����˵�... \n");
	  	getchar();
		return;
	 }
	
	      j=F3_seek();
          if (j==-1) return; 
          printf("ȷ��ɾ����ѧ������Ϣ��(Y\\N)\n");
	      printf("(Warning������һ���޸ģ����޷��ָ�����\n");
loop14:   for(h=0;h<10;h++)
		      a[h]='\0';   
		  gets(a);
		  if (a[0]=='Y'&&strlen(a)==1)
	        {
	    	   if (j==NUM)  goto loop15;
	    	   else 
			     {
			           for(i=j+1;i<=NUM;i++)
					     {
					        stu[i-1]=stu[i];	 
						 }   	 	
				 }  
loop15:	       NUM-=1;
	    	   F8_save();
	    	}
         else if (a[0]=='N'&&strlen(a)==1)
            {
                printf("����ɾ��ʧ�ܣ��밴������ص����˵���\n");
				getchar();
				return;
			}
		 else 
			{
				printf("��������ȷָ�\n");
				goto loop14;
			}
}
/*******************************************��ÿ��ѧ�����ֽܷ�������*****************************************/  
void sort1()
{
	struct Student example1;
	int i,j;
	float sum[40];
	float a;
     for (i=0;i<NUM;i++)
        sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
   
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (sum[j]<sum[j+1])
     	  {
     	  	 example1=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example1;	 
			 a=sum[j];
			 sum[j]=sum[j+1];
			 sum[j+1]=a;	 	
		  }
	 }
}	
/*******************************************��ѧ���ų��ɼ���*****************************************/  
void sort2()
{
	struct Student example;
	int i,j;

    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (stu[j].num>stu[j+1].num)
     	  {
     	  	 example=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example;	 	
		  }
	 }
	
}	
/*******************************************���������ֵ�˳���ų��ɼ���*****************************************/  
void sort3()
{
	struct Student example;
	int i,j;
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (strcmp(stu[j].name,stu[j+1].name)==1)
     	  {
     	  	 example=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example;	 	
		  }
	 }
}	
/*****************************************����*****************************************************/ 
F5_sort()
{
	int num,j;
	system("cls");
	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
     if (NUM==0)
            {
            	printf("��ǰ����0��ѧ�����ݣ��޷��������������\n");
            	printf("�밴������������˵�...\n");
            	getchar();
            	return;
			}
	printf("\n1.��ÿ��ѧ�����ֽܷ�������\n");
  	printf("2.��ѧ���ų��ɼ���\n");
  	printf("3.���������ֵ�˳���ų��ɼ���");
    printf("\n4.�������˵�\n");
    printf("0.�˳�ϵͳ\n");
    printf("Tips:�������Ӧ���ֽ����Ӧ����\n\n");		
loop17:    num=getNum();
    if (num>4)
      {
      	 printf("��������ȷ��ָ�\n"); 
      	 goto loop17;
	  }
    switch (num)
      {
      	case 0:exitSy();break;
      	case 1:sort1();break;
		case 2:sort2();break;
		case 3:sort3();break;
	    case 4:return;break;
	  }

	system("cls");
	printf("\n*****************************��ӭ����ɼ�����ϵͳ��*****************************\n");
  
	 printf("ϵͳ����  3  ��󱣴����..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ��󱣴����...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  ��󱣴����...\n",1); 
		Sleep(1000); 
	
	 printf("\n�����������,������������ص����˵���\n");
	 printf("Tips:�ɽ��롾��ʾ�����ܲ鿴���������ݣ�\n\n");
	 F8_save1();
	 getchar(); 
} 		
/*******************************************ͳ�Ƽ���*****************************************/  
F7_statistics()
{
	int num,i,j; 
	void statistics1();
	void statistics2();
	void statistics3() ;
	void statistics4() ;
	system("cls");
	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
    if (NUM==0)
            {
            	printf("��ǰ����0��ѧ�����ݣ��޷����м��������\n");
            	printf("�밴������������˵�...\n");
            	getchar();
            	return;
			}
  	printf("\n1.����ÿ�ſγ̵��ֺܷ�ƽ����\n");
  	printf("2.����ÿ��ѧ�����пγ̵��ֺܷ�ƽ����\n");
  	printf("3.��ÿ�ſγ̰��ţ�90~100��������80~89�����У�70~79����\n  ����60~69����������0~59��ͳ������������ռ�İٷֱ�\n");
   	printf("4.����༶ÿ�ſγ̵�ͳ������");
    printf("\n5.�������˵�\n");
    printf("0.�˳�ϵͳ\n");
    printf("Tips:�������Ӧ���ֽ����Ӧ����\n");
loop15:    num=getNum();
    if (num>5)
      {
      	 printf("��������ȷ��ָ�\n"); 
      	 goto loop15;
	  }
    switch (num)
      {
      	case 0:exitSy();
      	
      	case 1:statistics1();break;
		case 2:statistics2();break;
		case 3:statistics3() ;break;
		case 4:statistics4() ;break;
		case 5:return;
	  }

	printf("\n\n�밴������������˵�...\n");
	getchar();	
}
/*******************************************����ÿ�ſγ̵��ֺܷ�ƽ����*****************************************/  
void statistics1()
{
  	system("cls");
  	float ave[4],sum[4];
  	int i,j;
  	for (i=0;i<NUM;i++)
  	{
  		sum[0]+=stu[i].CN;
  		sum[1]+=stu[i].MT;
  		sum[2]+=stu[i].EN;
  		sum[3]+=stu[i].SC;
    }
    for (i=0;i<4;i++)
      ave[i]=sum[i]/NUM;
	printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
    printf("ÿ�ſγ̵��ֺܷ�ƽ����Ϊ��\n\n");
    printf("              |  ����(CN)  |  ��ѧ(MT)  | Ӣ��(EN)  | ��ѧ(SC)             \n") ;
    printf("       �ܷ֣� |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",sum[0],sum[1],sum[2],sum[3]) ;
    printf("      ƽ����: |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",ave[0],ave[1],ave[2],ave[3]) ;
  
}	
/*******************************************����ÿ��ѧ�����пγ̵��ֺܷ�ƽ����*****************************************/  
void statistics2()
{
  	float ave[40],sum[40];
    system("cls");
	int i,j;
	for (i=0;i<NUM;i++)
  	{
  		sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
  	    ave[i]=sum[i]/4;
    }
    printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
    printf("ÿ��ѧ�����пγ̵��ֺܷ�ƽ����Ϊ��\n\n");
    printf("             |           �ܷ�           |              ƽ����\n");
    for (j=0;j<NUM;j++)
       printf("     %-8s|          %6.2f          |              %6.2f\n",stu[j].name,sum[j],ave[j]);	
}
/********��ÿ�ſγ̰��ţ�90~100��������80~89�����У�70~79����\n  ����60~69����������0~59��ͳ������������ռ�İٷֱ�******/  
void statistics3() 
{
	 system("cls");
	 int i,j;
	int sum[4][5]={0};

	for (i=0;i<NUM;i++)
    	{
    		if (stu[i].CN>=90&&stu[i].CN<=100) sum[0][0]++;
			if (stu[i].CN>=80&&stu[i].CN<=89)  sum[0][1]++;
			if (stu[i].CN>=70&&stu[i].CN<=79) sum[0][2]++;
			if (stu[i].CN>=60&&stu[i].CN<=69) sum[0][3]++;
			if (stu[i].CN >=0&&stu[i].CN<=59) sum[0][4]++;
			
			if (stu[i].MT>=90&&stu[i].MT<=100) sum[1][0]++;
			if (stu[i].MT>=80&&stu[i].MT<=89)  sum[1][1]++;
			if (stu[i].MT>=70&&stu[i].MT<=79)  sum[1][2]++;
			if (stu[i].MT>=60&&stu[i].MT<=69)  sum[1][3]++;
			if (stu[i].MT >=0&&stu[i].MT<=59)  sum[1][4]++;
			
			if (stu[i].EN>=90&&stu[i].EN<=100) sum[2][0]++;
			if (stu[i].EN>=80&&stu[i].EN<=89)  sum[2][1]++;
			if (stu[i].EN>=70&&stu[i].EN<=79)  sum[2][2]++;
			if (stu[i].EN>=60&&stu[i].EN<=69)  sum[2][3]++;
			if (stu[i].EN >=0&&stu[i].EN<=59)  sum[2][4]++;
			
			if (stu[i].SC>=90&&stu[i].SC<=100) sum[3][0]++;
			if (stu[i].SC>=80&&stu[i].SC<=89)  sum[3][1]++;
			if (stu[i].SC>=70&&stu[i].SC<=79)  sum[3][2]++;
			if (stu[i].SC>=60&&stu[i].SC<=69)  sum[3][3]++;
			if (stu[i].SC >=0&&stu[i].SC<=59)  sum[3][4]++;
		}
    printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
    printf("ÿ�ſγ̷ֵȼ�ͳ������������ռ�İٷֱȣ�\n");
    printf("Tips:�ţ�90~100��������80~89�����У�70~79��������60~69����������0~59��\n");
    printf("Tips:��ǰ����%d��\n\n",NUM); 
    printf("1.������\n\n") ;
   printf(" \t| ����(CN)  |  ��ѧ(MT)  |   Ӣ��(EN)  |   ��ѧ(SC)   \n");
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][0],sum[1][0],sum[2][0],sum[3][0]);	
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][1],sum[1][1],sum[2][1],sum[3][1]);    
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][2],sum[1][2],sum[2][2],sum[3][2]);	
    printf("  ����  |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][3],sum[1][3],sum[2][3],sum[3][3]);	
    printf(" ������ |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][4],sum[1][4],sum[2][4],sum[3][4]);
    printf("\n\n2.�ٷֱȣ�\n\n");
    printf(" \t|  ����(CN)  |   ��ѧ(MT)  |   Ӣ��(EN)  |   ��ѧ(SC)   \n");
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][0]*100.0/NUM,sum[1][0]*100.0/NUM,sum[2][0]*100.0/NUM,sum[3][0]*100.0/NUM);	
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][1]*100.0/NUM,sum[1][1]*100.0/NUM,sum[2][1]*100.0/NUM,sum[3][1]*100.0/NUM);    
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][2]*100.0/NUM,sum[1][2]*100.0/NUM,sum[2][2]*100.0/NUM,sum[3][2]*100.0/NUM);	
    printf("  ����  |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][3]*100.0/NUM,sum[1][3]*100.0/NUM,sum[2][3]*100.0/NUM,sum[3][3]*100.0/NUM);	
    printf(" ������ |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][4]*100.0/NUM,sum[1][4]*100.0/NUM,sum[2][4]*100.0/NUM,sum[3][4]*100.0/NUM);
  
}
/********����༶ÿ�ſγ̵�ͳ�����ݣ�����ÿ�ſγ̵�ƽ���֡�ÿ�ſγ��š������С����񡢲��������������ռ�ٷֱ�********/  
void statistics4() 
{
    system("cls");
	 int i,j;
	int sum[4][5]={0};

	for (i=0;i<NUM;i++)
    	{
    		if (stu[i].CN>=90&&stu[i].CN<=100) sum[0][0]++;
			if (stu[i].CN>=80&&stu[i].CN<=89)  sum[0][1]++;
			if (stu[i].CN>=70&&stu[i].CN<=79) sum[0][2]++;
			if (stu[i].CN>=60&&stu[i].CN<=69) sum[0][3]++;
			if (stu[i].CN >=0&&stu[i].CN<=59) sum[0][4]++;
			
			if (stu[i].MT>=90&&stu[i].MT<=100) sum[1][0]++;
			if (stu[i].MT>=80&&stu[i].MT<=89)  sum[1][1]++;
			if (stu[i].MT>=70&&stu[i].MT<=79)  sum[1][2]++;
			if (stu[i].MT>=60&&stu[i].MT<=69)  sum[1][3]++;
			if (stu[i].MT >=0&&stu[i].MT<=59)  sum[1][4]++;
			
			if (stu[i].EN>=90&&stu[i].EN<=100) sum[2][0]++;
			if (stu[i].EN>=80&&stu[i].EN<=89)  sum[2][1]++;
			if (stu[i].EN>=70&&stu[i].EN<=79)  sum[2][2]++;
			if (stu[i].EN>=60&&stu[i].EN<=69)  sum[2][3]++;
			if (stu[i].EN >=0&&stu[i].EN<=59)  sum[2][4]++;
			
			if (stu[i].SC>=90&&stu[i].SC<=100) sum[3][0]++;
			if (stu[i].SC>=80&&stu[i].SC<=89)  sum[3][1]++;
			if (stu[i].SC>=70&&stu[i].SC<=79)  sum[3][2]++;
			if (stu[i].SC>=60&&stu[i].SC<=69)  sum[3][3]++;
			if (stu[i].SC >=0&&stu[i].SC<=59)  sum[3][4]++;
		}
    printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
    printf("ÿ�ſγ̷ֵȼ�ͳ������������ռ�İٷֱȣ�\n");
    printf("Tips:�ţ�90~100��������80~89�����У�70~79��������60~69����������0~59��\n");
    printf("Tips:��ǰ����%d��\n\n",NUM); 
    printf("1.������\n\n") ;
   printf(" \t| ����(CN)  |  ��ѧ(MT)  |   Ӣ��(EN)  |   ��ѧ(SC)   \n");
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][0],sum[1][0],sum[2][0],sum[3][0]);	
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][1],sum[1][1],sum[2][1],sum[3][1]);    
    printf("   ��   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][2],sum[1][2],sum[2][2],sum[3][2]);	
    printf("  ����  |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][3],sum[1][3],sum[2][3],sum[3][3]);	
    printf(" ������ |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][4],sum[1][4],sum[2][4],sum[3][4]);
    printf("\n\n2.�ٷֱȣ�\n\n");
    printf(" \t|  ����(CN)  |   ��ѧ(MT)  |   Ӣ��(EN)  |   ��ѧ(SC)   \n");
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][0]*100.0/NUM,sum[1][0]*100.0/NUM,sum[2][0]*100.0/NUM,sum[3][0]*100.0/NUM);	
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][1]*100.0/NUM,sum[1][1]*100.0/NUM,sum[2][1]*100.0/NUM,sum[3][1]*100.0/NUM);    
    printf("   ��   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][2]*100.0/NUM,sum[1][2]*100.0/NUM,sum[2][2]*100.0/NUM,sum[3][2]*100.0/NUM);	
    printf("  ����  |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][3]*100.0/NUM,sum[1][3]*100.0/NUM,sum[2][3]*100.0/NUM,sum[3][3]*100.0/NUM);	
    printf(" ������ |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][4]*100.0/NUM,sum[1][4]*100.0/NUM,sum[2][4]*100.0/NUM,sum[3][4]*100.0/NUM);
   float ave[4],sum1[4];
  	
  	for (i=0;i<NUM;i++)
  	{
  		sum1[0]+=stu[i].CN;
  		sum1[1]+=stu[i].MT;
  		sum1[2]+=stu[i].EN;
  		sum1[3]+=stu[i].SC;
    }
    for (i=0;i<4;i++)
      ave[i]=sum1[i]/NUM;
 printf("\n\n3.ƽ����&�ܷ֣�\n\n");
   
    printf("              |  ����(CN)  |  ��ѧ(MT)  | Ӣ��(EN)  | ��ѧ(SC)             \n") ;
    printf("       �ܷ֣� |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",sum1[0],sum1[1],sum1[2],sum1[3]) ;
    printf("      ƽ����: |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",ave[0],ave[1],ave[2],ave[3]) ;
} 
 /*******************************************�ɼ�ɾ��-����*****************************************/  
void F4_deletAll()
{ 
     char a[10];
     FILE *p;
     
	 int i,j,num,h; 
     system("cls");
	 printf("\n*****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
	 
	 printf("1.����ɾ����������\n2.����ɾ����������\n");
	 printf("3.�������˵�\n0.�˳�ϵͳ\n"); 
	 printf("(Tips:������˵��Աߵ����ֽ����Ӧ���ܣ�)\n\n");
loop17:	 num=getNum();
	 if(num==1) F4_delet();
	  else if (num==0)
	    exitSy();
	   else if (num==3)
	     return;
	  else if (num==2)
	   {
	   	  system("cls");
	      printf("\n****************************��ӭʹ�óɼ�����ϵͳ��*****************************\n\n");
	      if (NUM==0)
		     {
			   printf("��ǰ����0��ѧ�����ݣ��޷�����ɾ��������\n�밴������������˵�...\n");
			   getchar();
			   return;
		     }

		  printf("��ǰ����%dλѧ����ȷ��ȫ��ɾ����(Y\\N)\n",NUM);
		   printf("(Warning������һ���޸ģ����޷��ָ�����\n");
loop16:   for(h=0;h<10;h++)
		      a[h]='\0';   
		  gets(a);
		  if (a[0]=='Y'&&strlen(a)==1)
	        {
	                p=fopen("Student Grades.dat","wb");
	                if (!p)
	                   {
		                    printf("File is wrong!");
                    		exit(0);
	                   }
  	              
  	               NUM=0;
  	               fwrite(&NUM,sizeof(int),1,p);
  	                fclose(p);
                   saveAll();    	   
			}
         else if (a[0]=='N'&&strlen(a)==1)
            {
                printf("����ɾ��ʧ�ܣ��밴������ص����˵���\n");
				getchar();
				return;
			}
		 else 
			{
				printf("��������ȷָ�\n");
				goto loop16;
			}
	   }
	   else 
	     {
	     	printf("��������ȷ��ָ�\n");
	        goto loop17;
		 }

} 
/*******************************************��ʾ*****************************************/  
void F7_show()
{
	system("cls"); 
	int i=0,j;
	float a;
	float sum[40],ave[40],sum2[3][40];
    printf("\n*******************************************��ӭʹ�óɼ�����ϵͳ��*******************************************\n");
    printf("\n   ����    �Ա�   ѧ��   ���ĳɼ�(CN)   ��ѧ�ɼ�(MT)  Ӣ��ɼ�(EN)   ��ѧ�ɼ�(SC)   �ܷ�      ƽ����    ����\n");
    for (i=0;i<NUM;i++)
        {
           sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC; 
		   ave[i]=sum[i]/4.0;
		   sum2[0][i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC; 
		}
	for(i=0;i<NUM;i++)
	 sum2[1][i]=i+1;
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (sum2[0][j]<sum2[0][j+1])
     	  {
     	  	
		   	 a=sum2[0][j];
			 sum2[0][j]=sum2[0][j+1];
			 sum2[0][j+1]=a;
			 a=sum2[1][j];
			 sum2[1][j]=sum2[1][j+1];
			 sum2[1][j+1]=a;	 	
		  	 	
		  }
	 } 

	for(i=0;i<NUM;i++)
	  sum2[2][i]=i+1;   
	
	for(i=0;i<NUM-1;i++)
	for(j=0;j<NUM-i-1;j++)
     {
     	if (sum2[1][j]>sum2[1][j+1])
     	  {
     	  	
		   	 a=sum2[1][j];
			 sum2[1][j]=sum2[1][j+1];
			 sum2[1][j+1]=a;
			 a=sum2[2][j];
			 sum2[2][j]=sum2[2][j+1];
			 sum2[2][j+1]=a;	 	
		  	 	
		  }
	 }  
	if (NUM!=0)
  	  for(i=0;i<NUM;i++)
	     printf(" %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f  |  %-6.2f  |  %-6.2f  |  %.0f \n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i],ave[i],sum2[2][i]);
    
		printf("\n\n������������������˵�...\n");
		getchar();


}
 
