
#pragma once
#include <sys/time.h>

#define TIME 1000
#define SIZE 4
struct Data1;
struct Data2;
struct Data4;
struct Data8;
struct Data16;
struct Data32;
struct Data64;
struct Data128;
typedef struct Data1 Data1;
typedef struct Data2 Data2;
typedef struct Data4 Data4;
typedef struct Data8 Data8;
typedef struct Data16 Data16;
typedef struct Data32 Data32;
typedef struct Data64 Data64;
typedef struct Data128 Data128;

struct Data1
{
	int size;
	int data[SIZE*1];
};


struct Data2
{
	int size;
	int data[SIZE*2];
};


struct Data4
{
	int size;
	int data[SIZE*4];
};


struct Data8
{
	int size;
	int data[SIZE*8];
};


struct Data16
{
	int size;
	int data[SIZE*16];
};


struct Data32
{
	int size;
	int data[SIZE*32];
};


struct Data64
{
	int size;
	int data[SIZE*64];
};


struct Data128
{
	int size;
	int data[SIZE*128];
};


void bubble_sort(Data1 *input)
{
	int temp;
	for(int i=0; i<input->size-1; i++)
		for(int j=0; j<input->size-1-i; j++)
			if(input->data[j] > input->data[j+1])
			{
				temp = input->data[j];
				input->data[j] = input->data[j+1];
				input->data[j+1] = temp;
			}
}

void merge(int input1[], int input2[], int output[], int input1_size, int input2_size, int output_size)
{
	int i=0, j=0;
	for(int k=0; k<output_size; k++)
	{
		if(i<input1_size && j<input2_size)
		{
			if(input1[i]<input2[j])
				output[k] = input1[i++];
			else
				output[k] = input2[j++];
		}
		else if(i<input1_size)
			output[k] = input1[i++];
		else
			output[k] = input2[j++];
	}
}

void wait()
{
	for(int i = 0; i<TIME; i++);
}
