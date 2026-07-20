#include<stdio.h>
#include<stdlib.h>

void ascii(unsigned short x){
    printf("%c \n",x); 
}

void ascii_inv(char c){
    printf("%u \n",c);
}

int main()
{
    for(unsigned short i = 0; i < 128; i++){
        ascii(i);
    }

    printf("ascii inverse \n");
    ascii_inv('a');
    return 0;
}