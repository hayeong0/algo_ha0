//백준 2884

#include <iostream>
using namespace std;

int main(){
    int hour = 0, min = 0;
    cin >> hour >> min;

    if(min < 45){
        min += 15;
        if(--hour < 0) hour = 23;
    }
    else min -= 45;

    cout << hour << " " << min << endl;
    
    return 0;
}
