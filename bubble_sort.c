#include <stdlib.h>
#include <stdio.h>

//change to

//pointer to a integer
int* var;

void sort(int n){
    int t;
    //sort using bubble sort
    for(int i = n-1; i>0; i--){
        for(int j = i-1; j>=0; j--){
            if(var[i] < var[j]){
                //t = val[i];
                //var[i] = var[j];
                //var[j] = t;
                t = *(var + i);
                *(var + i) = *(var +j);
                *(var + j) = t;
            }
        }
    }
}

int main (int argc, char** argv){
    //pointer to a char
    char* ep;
    //length of array
    int n;
    n = argc - 1;
    //size of int is 4
    var = malloc(n * 4);
    for(int i=0; i<n; i++){
        //strtol convert string to long integer
        //var[i] = strtol(argv[i+1], &ep, 10);
        *(var + i) = strtol(*(argv +i + 1), &ep, 10);
        if(*ep){
            fprintf(stderr, "Argument %d is not a number\n", i);
            return -1;
        }
    }
    sort(n);
    for(int i =0; i < n; ++i){
        //printf("%d\n", val[i]);
        printf("%d\n", *(var+i));
    }
}
