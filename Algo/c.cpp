/*
    GBC_Algorithm_C
    21800758 Choi HaYeong
*/

#include <iostream>
using namespace std;

int T[48];
void init();
bool test(int num);

int main(){
    int test_case = 0, num = 0;
    int result = 0;
    cin >> test_case;
    init();
    
    for(int i = 0; i < test_case; i++){
        cin >> num;
    
        if(test(num)){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0; 
}

void init(){
    for(int i = 1; i <= 48; i++){
        T[i-1] = i*(i+1)/2;
    }
}

bool test(int num){
    for(int i = 0; i < 48; i++){
            for(int j = 0; j < 48; j++){
                for(int k = 0; k < 48; k++){
                    if(T[i] + T[j] + T[k] == num){
                        //cout << "1";
                        return true;
                    }
            }
        }
    }
    return false;
}