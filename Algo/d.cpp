/*
    GBC_Algorithm_D
    21800758 Choi HaYeong
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a, b, c, d, e, f, gs;
vector<vector<int> > map;
vector<int> check;
int dfs(int x, int y);

int main(){
    int test;
    cin >> test;
    
    for(int i = 0; i < test; i++){
        vector<pair<int,int> > x;
        cin >> gs;  //편의점
        //gs + 상근이 집, 락페스티벨 좌표 
        map = vector<vector<int> >(gs+2);
        check = vector<int>(gs+2,0);

        //상근이네 집
        cin >> a >> b;
        x.push_back(make_pair(a, b));

        for(int i = 0; i < gs; i++){
            //편의점 좌표
            cin >> c >> d;
            x.push_back(make_pair(c, d));
        }
        //페스티벌 좌표
        cin >> e >> f;
        x.push_back(make_pair(e,f));

        //입력받은 좌표 -> 1개의 노드
        //맥주 1박스, 최대 1000
        //각 좌표 거리 1000 이하면 가능 --> 연결리스트
        for(int i = 0; i < x.size(); i++){
            for(int j = i+1; j < x.size(); j++){
                if(1000 >= (abs(x[i].first - x[j].first) + abs(x[i].second - x[j].second))){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        //시작점 0, 상근이네 집 --> 락페스티벌 장소까지
        if(dfs(0, gs+1) == 2){
            cout << "happy\n";
        }
        else{
            cout << "sad\n";
        }
    }
    return 0;
}

int dfs(int x, int y) {
	check[x] = true;
    //현재 노드 페스티벌 노드면 가능 리턴
	if(x == y)
        return 2;
    
	for (int i = 0; i < map[x].size(); i++) {
		int next = map[x][i];
		if (!check[next]){
			if(dfs(next, y)) {
                return 2;
            }          
        }
	}
	return false;
}
