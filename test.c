#include <stdio.h>

long long int dp[1000000];
long long int fibonacci(int x);

int main(){
    int input = 0;
    scanf("%d", &input);
    printf("%lld", fibonacci(input));
}

long long int fibonacci(int x){
    if(x == 0)return 0;
    if(x == 1)return 1;
    if(x == 2)return 1;
    if(dp[x] != 0) return dp[x];
    return dp[x] = fibonacci(x-1)+fibonacci(x-2);
}