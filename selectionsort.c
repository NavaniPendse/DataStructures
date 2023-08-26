#include<stdio.h>
void selectionsort(int arr, int n);

int imin;
int arr[5]= {3,65,23,45,10};
int n=5;
int temp;

int main(){

    for(int i=0;i<(n-1);i++)
    {
        int imin=i;
        for(int j=i+1; j<n;j++)
        {
            if (arr[imin]>arr[j])
            imin=j;
        }
        if(imin!=i){
        temp=arr[i];
        arr[i]=arr[imin];
        arr[imin]=temp;
        }
    }


    printf("\n The final array is: ");
    for(int i=0;i<5;i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
