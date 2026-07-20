#include<stdio.h>
int main()
{
    int age;
    printf("entrez l'âge \n");
    scanf("%d",&age);
    if(age<5)
        printf("trop jeune \n");
    else
    {
        switch(age){
            case 5:
            case 6:
                printf("poussin\n");
                break;
            case 7:
            case 8:
                printf("diablotin\n");
                break;
            case 9:
            case 10:
                printf("préminime\n");
            case 11:
            case 12:
                printf("minime\n");
                break;
            case 13:
            case 14:
                printf("cadet\n");
                break;
            case 15:
            case 16:
                printf("scolaire\n");
                break;
            case 17:
            case 18:
                printf("espoir\n");
                break;
            default:
                printf("senior\n");
        }
    }
    return 0;
}