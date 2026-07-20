#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//1)
int addition_rec(int a,int b){
    if(b == 0){
        return a;
    }
    return addition_rec(a+1,b-1);    
}
//2)
int sub_rec(int a, int b){
    if(b==0){
        return a;
    }
    return sub_rec(a-1,b-1);
}

//3)
int mul_rec(int a, int b){
    int res = 0;
    if(b==0){
        return res;
    }
    a= addition_rec(b,b);
    return mul_rec(a,b-1);
}

int main(){
    int a = 2,b=5;
    int res = addition_rec(a,b);
    int res_sub = sub_rec(a,b);
    int res_mul = mul_rec(a,b);
    printf("le resultat de %d + %d est %d \n",a,b,res);
    printf("le resultat de %d - %d est %d \n",a,b,res_sub);
    printf("le resultat de %d * %d est %d \n",a,b,res_mul);
    return 0;
}