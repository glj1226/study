/***********************************************************************
	>File Name: qSort.c
	>Author: .xian.
	>Mail: .xian@hotmail.com
	>Created Time: 2015年11月26日 星期四 16时04分16秒
***********************************************************************/
 
#include<stdio.h>
#include"insertSort.h"

#define cutoff  (3)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median(int arr[], int left, int right)
{

    int center = (left+right)/2;

    if(arr[left] > arr[center]) swap(&arr[left], &arr[center]);

    if(arr[left] > arr[right]) swap(&arr[left], &arr[right]);

    if(arr[center] > arr[right]) swap(&arr[center], &arr[right]);

    swap(&arr[center], &arr[right-1]);

    return  arr[right-1];

}
void qSort(int arr[], int left, int right)
{

    int i, j;
    int pivot;

    if(left+cutoff <=  right)
    {

        pivot = median(arr, left, right);
        i = left;
        j = right - 1;

        for( ; ; )
        {

            while(arr[++i] < pivot){}

            while(arr[--j] > pivot){}

            if(i < j){

                swap(&arr[i], &arr[j]);

            }
            else
                break;

        }

        swap(&arr[i], &arr[right-1]);
        qSort(arr, left, i-1);
        qSort(arr, i+1, right);

    }
    else
        insertSort(arr+left,right-left+1);

}

int main()
{
    int arr[] = {2,6,3,4,5,9,7,8,1};
    qSort(arr,0,8);
    int i=0;
    for(i=0; i<9; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
