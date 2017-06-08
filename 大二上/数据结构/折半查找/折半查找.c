#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#define N 10



typedef int DataType;//����Ƚϵ�Ԫ������?



					 //��̬���ұ��˳��洢�ṹ

typedef struct {

	DataType * data;//����Ԫ�ش洢�ռ��ַ����ʵ�ʳ��ȷ��䣬0�ŵ�Ԫ����?

					//����ʱ��ʵ�ʳ��ȷ��䣬0 �ŵ�Ԫ����?

	int length;//����?

}SSTable;





//����һ����̬������Ϊ20���ڵ������

void createST(SSTable* ST, int n) {

	int i;

	time_t t;

	if (ST != NULL) {

		ST->data = (DataType*)calloc(n + 1, sizeof(DataType));

		if (ST->data != NULL) {

			srand((unsigned)time(&t));

			for (i = 1; i <= n; i++) {

				ST->data[i] = rand();//����20���ڵ������?

			}

			ST->length = n;

		}

	}

}



//����һ����̬�����ݰ���С�������У��Ա��۰����?

void createST_binary(SSTable* ST, int n) {

	int i, j = 0;

	time_t t;

	if (ST != NULL) {

		ST->data = (DataType*)calloc(n + 1, sizeof(DataType));

		if (ST->data != NULL) {

			for (i = 1; i <= n; i++) {

				ST->data[i] = j;

				j += 4;

			}

			ST->length = n;

		}

	}

}



//��ӡ����̬�������?

void print_SSTable(SSTable* ST) {

	int i, n = ST->length;

	if (ST != NULL) {

		for (i = 1; i <= n; i++) {

			printf("%d ", ST->data[i]);

		}

		printf("\n");

	}

}







int search_seq(SSTable ST, DataType key) {

	int i;

	if (ST.data == NULL)return 0;

	ST.data[0] = key;

	for (i = ST.length; ST.data[i] != key; i--);

	return i;

}



//�۰����(Binary Search)?

int search_binary(SSTable ST, DataType key) {

	int low, high, mid;

	low = 1;

	high = ST.length;

	while (low <= high) {//����ռ����ʱ

		mid = (low + high) / 2;

		if (ST.data[mid] == key) {

			return mid;//���ҳɹ�������mid?

		}

		if (key<ST.data[mid]) {

			high = mid - 1;//������ǰ���������?

		}

		else {

			low = mid + 1;//�����ں���������?

		}

	}

	return 0;//����ʧ��?

}







int main() {

	int n = 20;

	SSTable ST, ST_binary;?

	createST(&ST, n);//����һ�������̬��?

	createST_binary(&ST_binary, n);//����һ����С����˳�����еľ�̬��?

	//����˳�����?

	printf("ԭʼ����:");

	print_SSTable(&ST);

	printf("˳�����5�Ľ��:%d\n", search_seq(ST, 5));

	printf("˳�����10�Ľ��:%d\n", search_seq(ST, 10));

	printf("˳�����12�Ľ��:%d\n", search_seq(ST, 12));

	printf("˳�����15�Ľ��:%d\n", search_seq(ST, 15));

	printf("˳�����20�Ľ��:%d\n", search_seq(ST, 20));



	printf("--------------------------------------------\n");

	//�����۰����?

	printf("ԭʼ����:");

	print_SSTable(&ST_binary);

	printf("�۰����5�Ľ��:%d\n", search_binary(ST_binary, 5));

	printf("�۰����10�Ľ��:%d\n", search_binary(ST_binary, 10));

	printf("�۰����12�Ľ��:%d\n", search_binary(ST_binary, 12));

	printf("�۰����15�Ľ��:%d\n", search_binary(ST_binary, 15));

	printf("�۰����20�Ľ��:%d\n", search_binary(ST_binary, 20));



	system("pause");

	free(ST.data);

	return 0;

}