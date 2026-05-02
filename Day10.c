/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.
*/
#include <stdio.h>
#include <string.h>

int main(){
    int left,right,palindrome=1;
    char str[30];

    printf("Enter the string: \n");
    scanf("%s",str);

    left=0;
    right = strlen(str) - 1;

    while(left<right){
        if(str[left]!=str[right]){
        palindrome=0;    
        break;
        }
        left++;
        right--;
    }
    if(palindrome==1)
    printf("string is palindrome");
    else
    printf("not palindrome");
    return 0;

    

}