//Quick sort w last ele as pivot

#include<stdio.h>

int n = 5;
int arr[5]= {3,65,23,45,10};
int low=0;
int high=5;

void QS(int list[], int low, int high){
    int pivot, i, j, temp;
    pivot=high;
    i=low;
    j=high;
    while(i<j){
        while(list[i]<=list[pivot]&&i<=high){
            i++;
        }
        while(list[j]<=list[pivot]&&j>=low){
            j--;
        }
        if(i<j){
            int temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }
    }
}

int main(){
    

    QS(arr, low, high);

    printf("\n final array is: ");
    for(int x=0; x<=n; x++)
    {
        printf("%d\t", arr[x]);
    }
    
}