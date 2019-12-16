/*
    GBC_Algorithm_E
    21800758 Choi HaYeong
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];
//int input[1001]; //처음에 입력을 배열로 받넹
int square[1001][1001];

int main(){
    int n = 0, m = 0;
    string input;
    int result = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> input;
        for(int j = 0; j < m; j++){
            square[i][j] = input[j]-48;
            if(square[i][j] == 1){
                dp[i][j] = 1;
                result = 1;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(dp[i][j] == 1){
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                result = max(result, dp[i][j]);
            }
            //else dp[i][j] = 0;
        }
    }
    cout << result*result ;
    return 0;
}
