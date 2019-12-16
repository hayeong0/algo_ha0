/*
    GBC_Algorithm_PA8
    21800758 Choi HaYeong
    [백준_3649 로봇 프로젝트]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int hole = 0, rego = 0;

    while(scanf("%d", &hole) != EOF){
        //나노니까 *10^7
        //hole = hole * 1000000;
        hole = hole * 10000000;
        scanf("%d", &rego);
        vector<int> v(rego);

        for(int i = 0; i < rego; i++){
            scanf(" %d", &v[i]);
        }
        sort(v.begin(), v.end());

        int left = 0, right = rego-1;
        while(left < right){
            int tmp = v[left] + v[right];
            if(tmp == hole){
                break;
            }
            else if(tmp > hole){
                right--;
            }
            else left++;
        }
        if(left < right){
            printf("yes %d %d\n", v[left], v[right]);  
        }
        else{
            cout << "danger\n";
        }
    }
    return 0;
}