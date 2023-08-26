#include<stdio.h>




int main(){
    int n;
    int rounds=0;
    int x;
    int i; 
    int j;
    int temp;
    
    //array input
    n= 5;

    int arr[50]= {2,5,3,1,7};

    printf("Original array is: ");
    for(x=0;x<n;x++){
        printf("%d  ", arr[x]);
    }

    //optimized bubble sort
    int flag;

    for(j=0; j<n-1;j++)
    {
        flag=0;
        rounds++;
        for(i=0;i<n-j-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag++;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        if (flag==0){
            break;
        }
    }

    //output
    printf("\nArray after implementing bubble sort: ");
    for (int i=0;i<n;i++){
        printf("%d  ", arr[i]);
    }
    printf("\nNumber of rounds: %d",rounds);


}