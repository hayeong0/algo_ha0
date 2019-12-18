//백준 2753번


#include <iostream>
#include <string>
using namespace std;


int main(){
    int input = 0, result = 0;
    cin >> input;

    if(input%4 == 0){//4의 배수
        if(input%100 != 0 || input%400 ==0){//100의 배수
            cout << 1 << endl; 
        }
        else cout << 0 << endl;
    }
    else cout << 0 << endl;
    return 0;
}