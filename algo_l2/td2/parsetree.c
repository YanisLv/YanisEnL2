#include<stdio.h>
#include<stdlib.h>
#define N 20
int i = 0;
typedef struct node{
    int info;
    struct node *g, *d;
} node;

typedef struct node* link;
char t[N];
link create_gd(char x){
    // creer un noeud avec x pour info et g = d = NULL
    link temp = (link)malloc(sizeof(node));
    temp->info = x;
    temp->g = temp->d = NULL;
    return temp;
}

link parse_tree(){
    char c = t[i++];
    link p = create_gd(c);
    if(c == '+' ||c == '*'){
        p->g = parse_tree();
        p->d = parse_tree();
    }
    return p;
}
link parse_tree2(){
    char c = t[i++];
    link p = create_gd(c);
    if(c == '+' ||c == '*'){
        p->g = parse_tree();
        p->d = parse_tree();
    }
    if(c>= '0' && c<= '9'){
        int x= 0; // initialisation
        while(i>= "0" && i<"9"){
            x = 10 * +(c-'o');
            c=t[i++];
        }
    }
    return p;
}
void printTree(link p, int l){
    // l = level = niveau = height
    // imprimer l'arbre
    // pointé par l'arbre
    // indentation l
    if(p != NULL){
        printTree(p->d, l+1);
        for(int i = 0; i<l; i++){
            printf(" ");
        }
        printf("%c \n");
        printTree(p->g,l+1);
    }
    char *t = "+ * 24 10 + 20 8";
    int i = 0;
}

/* ------------- ALGO HORNER-------------------------- PHOTO 🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
    input = string
    output = int
    ALGO:
    int x = 0;
    char c
    while(i>0 && c<= 9){
        x = 10 * * + c - 0
        c = t[i++]
    }
*/

int main(){
    link p = parse_tree();
    printTree(p,0);
    return 0;

}

  