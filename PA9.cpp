/*
    GBC_Algorithm_PA9
    21800758 Choi HaYeong
    [백준_1072 게임]
*/

#include <iostream>
#include <cstdio>
#define MAX 1000000000
using namespace std;
long long x, y, z;
 
int main() {
    long long left, right, mid;
    cin >> x >> y;
    long long temp = 0;
    z = 100 * y / x;
    left = 0;
    right = MAX;
 
    if (z >= 99) {
      cout << -1 << endl;
    }
    else {
      while (left <= right) {
        mid = (left + right) / 2;
        temp = 100 * (y+mid) / (x+mid);
        if (z < temp) {
          right = mid - 1;
        }
        else
          left = mid + 1;
      }
      cout << left << endl;
    }
    return 0;
  }

