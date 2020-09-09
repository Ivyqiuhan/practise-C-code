int data[10];
int *g = data;

void add (int a, int i){
    g[i] += a;
}

void bar(){
    int x,y;
    x = 1;
    y = 2;
    add (3,4);
    add (x,y);
}

int main (){
    bar();
    for(int i = 0; i < 10; i++){
        printf("%d\n", data[i]);
    }
    
}
