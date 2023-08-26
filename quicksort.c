#include<stdio.h>

//pivot as 1st ele

int n = 5;
int arr[5]= {3,65,23,45,10};


void QS(int list[], int low, int high){
    int pivot, i, j, temp;
    pivot=low;
    i=low;
    j=high;

    if(i<j){
        while(list[i]<=list[pivot]&&i<=high){
            i++;
        }
        while(list[j]>=list[pivot]&&j>=low){
            j--;
        }
        if(i<j){
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }
    }
    temp = list[j];
    list[j] = list[pivot];
    list[pivot] = temp;

    QS(arr, low, j-1);
    QS(arr, j+1, high);
}

int main(){
    

    QS(arr, 0, n-1);

    printf("\n final array is: ");
    for(int x=0; x<n; x++)
    {
        printf("%d\t", arr[x]);
    }
    printf("\n");
    
}