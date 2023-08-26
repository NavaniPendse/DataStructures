#include<stdio.h>
#include<math.h>

int len;
int key;
void linearsearch(int arr[], int key);


int main(){
	
	//input of array & key
	int arr[len];
	int i;
	int a;
	int check=0;

	
	printf("Enter the length of the array");
	scanf("%d", &len);
	
	printf("Enter the elements of the array");
	for(i=0;i<len;i++){
		scanf("%d", &arr[i]);
		
	}
	
	printf("Enter the key");
	scanf("%d", &key);
	
	linearsearch(arr,key);
}
	
	void linearsearch(int arr[], int key){
		int j;
		int check=0;
		//for loop linear search
		for(j=0;j<len;j++){
			if(arr[j]==key){
	 				 check++;
	 				 printf("The key was found at %d position", j+1);
	 				 break;
	 				 }
					 }
	    if(check==0){
				printf("key not found");
			}
}
