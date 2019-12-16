/*
    GBC_Algorithm_PA7
    21800758 Choi HaYeong
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int a = (int)1e9;
int daextra(int start, int end, vector<vector<pair<int, int> > >&graph, vector<vector<pair<int, int> > >&distance);
void bfs(int end, vector<vector<pair<int, int> > >&graph, vector<vector<pair<int, int> > >&distance);
int main(){
   int U, V, P;
    while(true){
        cin >> N >> M;
        if(N == 0) break;
       
        vector<vector<pair<int, int> > >graph;
        vector<vector<pair<int, int> > >distance;
        int start, end;
        cin >> start >> end;
        graph.resize(N+1);
        distance.resize(N+1);

        while(M--){
            cin >> U >> V >> P;
            graph[U].push_back(make_pair(V, P));
        }
        
        daextra(start, end, graph, distance);
        bfs(end, graph, distance);

        int tmp = daextra(start, end, graph, distance);
        if(tmp == a){
            cout << -1 << endl;
        }
        else{
            cout << tmp << endl;
        }
    }
}
int daextra(int start, int end, vector<vector<pair<int, int> > >&graph, vector<vector<pair<int, int> > >&distance){
    //시작노드를 제외한 모든 노드의 거리를 무한대로 초기화
    vector<int>v(N+1, a);//start로부터 거리
    //weight, node
    priority_queue<pair<int, int> >p;
    p.push(make_pair(0, start));   //초기 weight, 시작점
    v[start] = 0;   //현재 weight 0
 
    while (!p.empty()) {
        int node = p.top().second;
        int weight = -p.top().first; //weight 부호 바꾸면 거리 작은 것부터 꺼내짐
        p.pop();
        //다음 노드들 확인
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i].first;
            int next_w = graph[node][i].second;
        //삭제된건 무시하구 넘어가기
            if (next_w == -1) continue;
        //최소 경로일 경우 distance에 갱신
            if (v[next] > weight + next_w) {
                v[next] = weight + next_w;
                //작은 것부터 꺼내고 싶음
                p.push(make_pair(-v[next], next));
                //distance 갱신
                distance[next].clear();
                distance[next].push_back(make_pair(node, v[next]));
            }
            //최단거리 찾으면 업데이트
            if (v[next] == weight + next_w) {
                distance[next].push_back(make_pair(node, v[next]));
            }
        }
    }
    return v[end];
}

void bfs(int end, vector<vector<pair<int, int> > >&graph, vector<vector<pair<int, int> > >&distance) {
    queue<int>q;    //정점 지울 큐
 
    q.push(end);    //도착점을 넣어준다
    //도착점 ----> 시작점
    //반대방향 벡터
    while (!q.empty()) {
        int node = q.front();
        q.pop();
 
        for (int i = 0; i < distance[node].size(); i++) {
            int next = distance[node][i].first;
            
            for (int i = 0; i < graph[next].size(); i++) {
                if (graph[next][i].first == node) {
                    graph[next][i].second = -1;
                    //graph[node][i].second
                    //처음 node가 도착점
                }   
            }
            q.push(next);
        }
    }
}