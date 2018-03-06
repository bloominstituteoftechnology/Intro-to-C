#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "Some String";
    str[0] = 'r';
    printf("The pointes is %c\n",*str);
    printf("The pointes is %s\n",str);
    return 0;
}
