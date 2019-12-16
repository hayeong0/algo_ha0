/*
    GBC_Algorithm_PA3
    21800758 Choi HaYeong
*/
#include <iostream>
using namespace std;

int dp[10001] = {0}; 
int coin[101] = {0};  

int main(){
    //n 동전 종류, k 동전으로 만들고 싶은 수
    int n = 0, k = 0;
    //동전 0원 , 아무 동전 X
    dp[0] = 1;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> coin[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j-coin[i] >= 0)//-->for문 하나로 써서 처리 가능함
                dp[j] = dp[j] + dp[j-coin[i]];
        }

    }
    cout << dp[k];
    return 0;
}