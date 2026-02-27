#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CONSTRUIRE UN HEAP (TAS)

// t = [44,55,12,42,94,18,6,67]
// est un tas si t[i]>t[2i] && t[i] > t[2i+1]

int est_tas(int t[], int n){    // mon code
    // on utilise t[0]
    int i = 1;
    while(i<= n/2 &&  t[i]>= t[2*i] && t[i]>= t[2*i+1]){
        i++;
    }
    if(i==n/2){
        return 1;
    }
    else{
        return -1;
    }
}

int est_tas2(int t[], int n){       // code du prof
    for(int i = 1; i<= n/2; i++){

    
        if(t[i]< t[2*i] ||t[i]< t[2*i+1]){
            return 0;
            //tester si n est j
        }
        if(n/2 == 0 && t[n/2]>t[n]){
            return 0;
        }
    }
    return 1;
}