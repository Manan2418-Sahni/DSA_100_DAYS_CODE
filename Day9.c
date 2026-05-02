/*
Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
*/
#include <stdio.h>
int main()
{
    char str[20];
    printf("Enter the string you want to reverse: \n");
    scanf("%s", &str);

    for(int i=20;i>=0;i--){
        if(str !='\0')
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
} 