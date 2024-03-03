//Take input 2d array : marks in 5 subjects calculate total of every student and average of every subject
#include<stdio.h>

int main(){
    int row ;
    printf("enter the no of students ");
    scanf("%d",&row);
    int arr[row][6];
    int total[row];      //creating array to store the total of subject
    for(int i=0;i<row;i++){
        int sum=0;
        printf("enter the marks of %d student\n",i+1);
        arr[i][0]=i;  //student number
        for(int j=0;j<5;j++){
            printf("enter the marks of %d subject",j+1);
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
        total[i]=sum;   //we can find avg by just dividing by5
    }
    for(int i=0;i<row;i++){
        printf("\nthe total of student %d is %d and avg is %d\n",i+1,total[i],total[i]/5);
    }
    
    return 0;
}