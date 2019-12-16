/*
    GBC_Algorithm_PA2
    21800758 Choi HaYeong
*/

#include <iostream>
using namespace std;

int dp[10001];  //최대로 마신 양
int arr[10001]; //현재 잔의 담긴 양

int Max(int x, int y, int z);
int Find_maximum(int n, int *arr);

int main(){
    int n = 0, max = 0;
    std::cin >> n; 

    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
    }

    max = Find_maximum(n, arr);
    cout << max << endl;
    return 0;
}

int Find_maximum(int n, int arr[]){
    int max = 0; 
    for(int i = 1; i <= n; i++){
        if(i < 4){
            if(i == 3){
                //3+2, 3+1, 2+1 중 max
                dp[i] = Max(arr[i-1]+arr[i], arr[i-2]+arr[i-1], arr[i-2]+arr[i]);
            }
            else
                //max인 경우 -> 현재+현재까지의 최대 포도주 양
                dp[i] = arr[i]+dp[i-1];
        }
        else{
           //3번까지의 max/1번 연속:2번까지의 max+4번/2번 연속:1번까지의 max+3번+4번
           dp[i] = Max(dp[i-1], arr[i]+dp[i-2], arr[i]+arr[i-1]+dp[i-3]);
       }
    }
    max = dp[n];
    return max;
}

int Max(int x, int y, int z){
    int tmp = x;
    if(tmp < y)
        tmp = y;
    if(tmp < z)
        tmp = z;
    return tmp;
}