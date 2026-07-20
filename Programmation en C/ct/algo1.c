#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<math.h>

int main(){

    int n,w, L;
    float nb_eta;
    printf("entre nombre de livres\n");
    scanf("%d",&n);
    printf("entre largeur des livres\n");
    scanf("%d",&w);
    printf("entre largeur etagere\n");
    scanf("%d",&L);
    nb_eta = (float)(n*w) / (float)L;
    printf("%.2f \n",nb_eta);
    if(nb_eta - (int)nb_eta == (int)0){
        printf("il faudra %d etageres \n",(int)nb_eta);
    }
    else{
        printf("il faudra %d etageres \n",(int)nb_eta+1);
    }

}