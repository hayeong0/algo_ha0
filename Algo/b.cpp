/*
    GBC_Algorithm_B
    21800758 Choi HaYeong
*/

#include <iostream>
//#define MAX 100001
using namespace std;
int x, y;
//int array[MAX][MAX];

int main(){
    cin >> x >> y;
    long long left = 1;
    long long right = y;
    int result = 0;

    while(left <= right){
        long long count = 0;
        //임의의 수 mid번째
        int mid = (left + right)/2;
        //ndl 1000보다 클 경우, 작은 값을 +
        for(int i = 1; i <= x; i++){
            //하나의 행에서 mid보다 작은 수의 갯수
            count = count + min(x, mid/i);
        }

        if(count < y){
            left = mid + 1;  
        }
        else{
            result = mid;
            right = mid-1; 
        }
    }
    cout << result << endl;
    return 0;
}