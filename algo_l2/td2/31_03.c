#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

// EVALUER UNE EXPRESSION POSTFIXE :
// ALGO : Lire l'expression de gauche vers la droite. Push les opérandes. Si on rencontre un opérateur(+,*).
// POP 2 fois et évaluer avec l'opérateur et PUSH le résultat.
//#define PILE = stack

#define N 20
int s[N+1], top;
// initialisation stack 
void init(){
    top = 0;
}

//TEST PILE VIDE 
int empty(){
    return top == 0;
}

// TEST FULL STACK
int full(){
    return top == N +1;
}
void push(int x){
    // TESTER plein()
    if(!full()){
        s[top++] = x;
    }
    else{
        printf("Allouez plus d'espace\n");
        exit(1);
    }
    
}

double pop(){
    if(!empty()){
        return s[--top];
    }
    else{
        printf("erreur \n");
        exit(1);
    }
}

int main(int argc, char *argv[]){
    //exemple:argc=argumentcount
    //argu= argu=argumentvector
    //cela nous permet d'envoyer vers le main les entrées tapés a partir de clavier exemple
    //tapez 24 34 *
    //argc=1 argu[1]=24 34 *
    if (argc == 1) return 1;

    char *exp=argv[1]; //exp=24 34 *
    int l= strlen(exp);
    for (int i=0; i<l ; i++){
        //tester si exp[i]est un operateur
        // commutative
        if (exp[i]=='+') {push(pop()+pop());}
        if (exp[i]=='*') {push(pop()* pop());}
        // non commutative 
        if(exp[i] == '-' && exp[i+1] ==' '){
            // exp[i], un opérateur soustraction 
            double droite = pop(); 
            double gauche = pop();
            push(gauche-droite);
        }
        
        if(exp[i] == '-' || isdigit(exp[i])){
            char token[10] ="";     // vide
            int j = 0;
            if(exp[i] == '-' && isdigit(exp[i+1])){
                //ex 
                token[j++] = '-';
                // saisie des chiffres
            }
            while(isdigit(exp[i]) || exp[i] == '.'){
                token[j++] = exp[i++];
            }
            token[j] = '\0';
            // si on rencontre un opérande
            // push
            push(atof(token));  // ascii to float
            printf("la valeur de l'exp est %lf \n",pop());
        }
        
        
        if(exp[i]== '/'){
            double right = pop();
            double left = pop();
            if(right == '0'){
                printf("division par zero \n");
                exit(1);
            }
            push(left/right);
        }
        if(exp[i] == '%'){
            double den = pop();
            double num = pop();
            if(exp[i] == '0'){
                printf("division par 0 \n");
                exit(1);
            }
            push(fmod(num,den));

        }
        if(exp[i] == '^'){
            double expo = pop();
            double base = pop();
            /*
            if(base == '0' && expo == '0'){
                push(1); //0^0
            }*/
            push(pow(base,expo));   // pox = power
        }
        //tester un debut d'une operande 
        //horner initialisation 0.
        if(exp[i]>='0' && exp[i]<= '9'){
            int y=0; //initialisation
            while (exp[i]>= '0' && exp[i]<='9'){
                y=10*y+(exp[i++]-'0');
            }
            push(y);
        }
    }
    printf("le resultat est %d\n", pop());
    return 0;
}