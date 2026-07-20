#include<stdio.h>
#include<stdlib.h>

void fermier(int t, int p){
    int solution = 0;
    int i=0;
    int m =p ,d = i;
    for(i = 0; i <= t && !solution; i++){
        m -= 4;
        d += 2;
        if(4*m + 2*d == p){
            solution = 1;
        }
        printf("%d m et %d d \n",m,d);
    }
    if(solution){
        printf("khoya t'as %d moutons et %d dindons dla farce \n",m,d);
    }
    else{
        printf("impossible avec %d moutons et %d dindons\n",m,d);
    }
    
}

int main(){
    fermier(36,100);
    return 0;
}