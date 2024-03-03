#include<stdio.h>

int main(){
    char str[10];
    int end=0;
    gets(str);
    printf("%s",str);
    
    //loop for finding where the word end
    for(int i=0;i<10;i++){
        if (str[i]!='\0')
        {
            end+=1;
        }
        else
        break;
        
    }
    printf("\nthe number of letters in string is %d", end);
        int num=1;
    for(int i=0;i<end/2;i++){
        if(str[i]!=str[end-i-1]){
            num=0;
            printf("\nthis is not a pallindrome");
            break;
        }
    }
    if(num==1)
    printf("\nthis is a pallimdrome");
}