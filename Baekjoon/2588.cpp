//백준 2588번

#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = 0, y = 0;
    int r1 = 0, r2 = 0, r3 = 0, result = 0;
    int tmp = 0, tmp2 = 0, tmp3 = 0;

    cin >> x >> y;
    r1 = x*(y%10);

    tmp2 = y%100;
    tmp2 -= tmp;    
    tmp2 /= 10;
    r2 = x*tmp2;
    // r2 = x*((y/10)%10);

    tmp3 -= tmp2;
    tmp3 = y/100;
    r3 = x*tmp3;
    // r3 = x*(((y/10)/10)%10);
    result = x*y;

    cout << r1 << "\n" << r2 << "\n" << r3 << "\n" << result << endl;
    return 0;
}