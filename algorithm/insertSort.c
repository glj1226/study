/***********************************************************************
	>File Name: insertSort.c
	>Author: .xian.
	>Mail: .xian@hotmail.com
	>Created Time: 2015年11月26日 星期四 15时14分53秒
***********************************************************************/
 
#include<stdio.h>

void    insertSort(int  arr[],int   length)
{

    int i   =   0,  j =   0;
    int temp    =   0;
    for(i   =   1;  i   <   length; i++)
    {
        
        if(arr[i-1] >   arr[i]){
            j   =   i;
            temp    =   arr[i];
            while(j >   0   &&arr[j-1]    >   temp)  {
                arr[j]  =   arr[j-1];
                j--;
            }
            arr[j]  =   temp;
        }
    }
    
}

/*  test

int main()
{
    int arr[]={2,3,1,8,4,6,5,7};
    int i,len;
    insertSort(arr,8);
    for(i=0;i<8;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
    return  0;
}

*/
