//insertion and deletion in array at user defined location
#include<stdio.h>

int main(){
    int arr[11]={1,4,5,3,6,3,43,45,3,2434,4};
    int choice , pos;
    printf("press 0 for deletion and 1 for insertion");
    scanf("%d",&choice);

    //deletion
    if(choice==0){
        printf("enter the position you want to delete REMEMBER IT SHOULD BE BELOW 11");
        scanf("%d",&pos);
        for(int i=pos;i<11;i++){
            arr[i]=arr[i+1];
        }
        arr[10]='\0';   //garbage value
    }
    //insertion
    else if(choice==1){
        printf("\nenter the position you want to insert REMEMBER IT SHOULD BE BELOW 11");
        scanf("%d",&pos);
        for(int i=10;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        printf("\nenter the new value");
            scanf("%d",&arr[pos]);
        }

     else
    printf("you lost your chance by deliberately inputing wrong choice");

    //printing the array
    for(int i=0;i<11;i++){
        printf("\n %d",arr[i]);
        }

    return 0;
    }

   
