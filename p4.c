#include<stdio.h>

int main(){
  int arr[12]={4,2,56,8,6,2,0,5,7,34,7};
  int choice;
  printf("press 0 for insertion and 1 for deletion");
  scanf("%d", &choice);
  if(choice==0){
    int new_element , temp;
    printf("\nenter the new element");
    scanf("%d",&new_element);
    
    for(int  i=0 ; i<=11 ; i++){
        arr[11-i]=arr[11-i-1];
        
    }
    arr[0]=new_element;
    }
  else if(choice==1){
    int new_element;
    printf("\nenter the new element");
    scanf("%d",&new_element);
    arr[11]=new_element;
  }
  else{
    printf("wrong choice");
    return 0;
  }




  for(int i=0; i<=11;i++){
    printf("the %d element is %d \n",i, arr[i]);
  }
  
  }