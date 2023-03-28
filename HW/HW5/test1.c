#include<stdio.h>
#include<time.h>
void trick(){
    return ;
}

void f(int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            trick();
        }
    }
}

clock_t start, end;
int main(){
    start = clock();
    f(10000000);
    end = clock();
    int n;
    scanf("%d", &n);
    if(n == 1){
        int time = 3;
    }
    else{
        int time = 4;
    }
    printf("%lu\n", end - start);
    printf("%lf\n", (double)(end - start));
}