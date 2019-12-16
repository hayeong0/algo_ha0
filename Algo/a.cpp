/*
    GBC_Algorithm_A
    21800758 Choi HaYeong
*/

#include <iostream>
#include <algorithm>

using namespace std;
int x = 0, y = 0;

int main(){
    int sum = 0;
    int m = 1000000000; //min
    //10000이하의 자연수 x, y
    cin >> x >> y;

    for(int i = 1; i <= y; i++){
        int tmp = i*i;
        if(x <= tmp && tmp <= y){
            m = min(m, tmp);
            sum += i*i;
        }
    }
    if(!sum){
        cout << "-1";
    }
    else{
        cout << sum << "\n" << m;
    }
}
