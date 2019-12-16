/*
    GBC_Algorithm_PA6
    21800758 Choi HaYeong
    [백준 2110_ 공유기]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>house;
int house_num, wifi_num;
int result;

int main(){
    int left = 0, right = 0;
    int index = 0;
    cin >> house_num >> wifi_num;

    for(int i = 0; i < house_num; i++){
        cin >> index;
        house.push_back(index);
    }
    sort(house.begin(), house.end());
    
    left = 1;   //최소 거리
    right = house[house_num-1] - house[0]; //최대 거리

    while(left <= right){
        int mid = (left+right)/2;
        int count = 1;
        int first = house[0];

        for(int i = 1; i < house_num; i++){
            //공유기 설치 O
            if(mid <= house[i]-first){
                count ++;   //공유기
                first = house[i];
            }
        }
        if(wifi_num > count){
            //더 설치되야됨 --> 간격 줄이기
            right = mid - 1;
        }
        else{
            //더 많이 설치되거나 같음 --> 간격 넓히기
            result = mid;
            left = mid+1;
        }
    }
    cout << result << endl;
    return 0;
}