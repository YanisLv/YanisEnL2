#include<stdio.h>

int main()
{
    int n, cpt = 0;
    printf("entrez n:\n");
    scanf("%d",&n);
    int tmp = n;
    do{
        
        if(tmp%10!=0){
            cpt = cpt +1;
        }
        tmp = tmp/10;
        

    }while(tmp>0);
    printf("il y'a %d chiffres non nuls dans %d\n",cpt,n);
    return 0;

}