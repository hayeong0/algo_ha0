#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
 
#define MAX 501
#define INF 987654321
 
using namespace std;
 
int n, m;
 
int dijk(int start, int goal, vector<vector<pair<int, int> > >&arr, vector<vector<pair<int, int> > >&trace) {
 
    vector<int>dist(n + 1,987654321);
 
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(0,start));
    dist[start] = 0;
 
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
 
        for (int i = 0; i < arr[now].size(); i++) {
            int to = arr[now][i].first;
            int c = arr[now][i].second;
 
            if (c == -1)continue;
 
        
 
            if (dist[to] > cost + c) {
                dist[to] = cost + c;
                pq.push(make_pair(-dist[to], to));
 
 
                trace[to].clear();
                trace[to].push_back(make_pair(now, dist[to]));
            }
            if (dist[to] == cost + c) {
                trace[to].push_back(make_pair(now, dist[to]));
            }
        }
    }
    
    return dist[goal];
 
}
void bfs(int goal, vector<vector<pair<int, int> > >&arr, vector<vector<pair<int, int> > >&trace) {
    queue <int > q;
 
    q.push(goal);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
 
        for (int i = 0; i < trace[now].size(); i++) {
            int to = trace[now][i].first;
 
            for (int i = 0; i < arr[to].size(); i++) {
                if (arr[to][i].first == now) {
                    arr[to][i].second = -1;
                }
            }
            q.push(to);
        }
    }
 
}
 
 
int main() {
    //freopen("Text.txt", "r", stdin);
    
    while (1) {
 
        vector<vector<pair<int, int> > >arr;
        vector<vector<pair<int, int> > >trace;
 
        cin >> n >> m;
 
        if (n == 0 && m == 0)break;
        
        int start, goal;
        
        cin >> start >> goal;
 
        arr.resize(n + 1);
        trace.resize(n + 1);
 
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
 
            arr[from].push_back(make_pair(to, cost));
        }
 
        dijk(start, goal,arr,trace);
 
        bfs(goal,arr,trace);
 
        if (dijk(start, goal,arr,trace) == 987654321) {
            cout << -1 << endl;
        }
        else cout << dijk(start, goal,arr,trace)<<endl;
 
    }
 
 
 
}
