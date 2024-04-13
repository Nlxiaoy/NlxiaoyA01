#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define INIT_SIZE 10
#define INCREMENT 5

typedef struct {
	int* data;
	int Length;
	int capacity;
}SeqlList;

SeqlList* InitList(int initSize) {
	SeqlList* L = (SeqlList*)malloc(sizeof(SeqlList));

	if (!L)
		exit(EXIT_FAILURE);

	L->data = (int*)malloc(initSize * sizeof(int));

	if (!L->data) {
		free(L);
		exit(EXIT_FAILURE);
	}

	L->Length = 0;
	L->capacity = initSize;
	return L;
}


bool ListInsert(SeqlList* L, int i, int e) {
	if (i<1 || i>L->Length + 1) {
		printf("Error\n");
		return false;
	}

	if (L->Length == L->capacity) {
		int* newdata = (int*)realloc(L->data,(L->capacity + INCREMENT)*sizeof(int));
		if (!newdata)
			return false;
		L->data = newdata;
		L->capacity += INCREMENT;
	}

	for (int j = L->Length; j >= i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->Length++;
	return true;
}



void PrintfList(SeqlList* L) {
	for (int i = 0; i < L->Length; ++i)
		printf("L[%d]=%d\n", i+1, L->data[i]);
}

bool DeleteListdata(SeqlList* L, int i) {
	if (i<1 || i>L->Length) {
		printf("Error\n");
		return false;
	}
	for (int j = i; j < L->Length; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->Length--;
	printf("Hsa been delete [%d]\n", i);
	return true;
}

bool DEL_min(SeqlList* L) { //删除最小值
	if (L->Length == 0)
		return false;

	int k = L->data[0];
	int pos = 0;
	for (int i = 0; i < L->Length; ++i) {
		if (L->data[i] < k) {
			k = L->data[i];
			pos = i;
		}
	}
		
	DeleteListdata(L, pos+1);
	return true;
}




int main(void) {
	SeqlList* L = InitList(INIT_SIZE);

	ListInsert(L, 1, 100);
	ListInsert(L, 2, 96);
	ListInsert(L, 3, 10);
	ListInsert(L, 4, 480);
	PrintfList(L);

	DEL_min(L);
	PrintfList(L);


	return 0;
}