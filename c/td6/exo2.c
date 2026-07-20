#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int ackermann(int m,int n){
    if(m == 0){
        return n+1;
    }
    else if (m>0 && n == 0)
    {
        return ackermann(m-1,1);
    }
    else{
        return ackermann(m-1, ackermann(m,n-1));
    }
    
}

int main(){

    printf("res = %d\n",ackermann(5,3));
    return 0;
}