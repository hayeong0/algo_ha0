/*
    GBC_Algorithm_PA4
    21800758 Choi HaYeong
*/

#include <iostream>
#include <stack>
using namespace std;

int Count_Virus_computer(int n, int connect);
int main(){
    int n = 0, connect = 0;
    int result = 0;
    
    cin >> n >> connect;
    result = Count_Virus_computer(n, connect);
    cout << result;

    return 0;
}

int Count_Virus_computer(int n, int connect){
    int tree[101][101];
    int visited[101];
    stack<int> virus;
    int cnt = 0;

    for(int i = 0; i < connect; i++){
        int x, y;
        cin >> x >> y;
        tree[x][y] = 1;
        tree[y][x] = 1;
    }

    virus.push(1);
    visited[1] = 1;
   
    while(!virus.empty()){
        int cur = virus.top();
        int status = 1;
        
        for(int i = 1; i <= n; i++){
            if(!visited[i] && tree[cur][i] == 1){
                visited[i] = 1;
                virus.push(i);
                status = 2;
                cnt++;
                break;
            }
        }
        if(status == 1)virus.pop();
    }
    return cnt;
}
