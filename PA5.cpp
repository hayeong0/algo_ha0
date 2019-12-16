/*
    GBC_Algorithm_PA5
    21800758 Choi HaYeong
    [백준 2573_ 빙산]
*/

#include <iostream>
using namespace std;

int n = 0, m = 0;   //세로, 가로
int iceberg[301][301];  //빙산 배열
int tmp[301][301];  //녹인 값 임시 저장
int visit[301][301]; //방문한 거
//(-1,0), (0, 1), (1, 0), (0, -1) 상하좌우 탐색 쉽게
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int x, int y); //빙산 분리 여부
void check_iceberg(); //전체적인 체크
void melting_iceberg(); //녹여야 돼..

int main(){
    //n이 세로, m이 가로
    cin >> n >> m;
    //빙산 value 채우기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> iceberg[i][j];
    }
    check_iceberg();
    return 0;
}

void check_iceberg(){
    int year = 0;
    while(true){
        int divide = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //현재 칸 0아니고, 방문 하지 않았어야함
                if(iceberg[i][j] != 0 && !visit[i][j]){
                    divide++;
                    DFS(i, j);
                }
            }
        }
        //빙산이 전부 0일 경우
        if(divide == 0){
            cout << "0" << endl;
            break;
        }
        //아직 빙산 한덩어리 --> 연도 ++, 녹이기
        else if(divide == 1){
            year++;
            melting_iceberg();
        }
        //빙산 분리 완료
        else{
            cout << year << endl;
            break;
        }
    }
}

void DFS(int x, int y){
    visit[x][y] = true;
     //상하좌우 check 0
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
       
        if(nextX < n && nextY < m && nextX >= 0 && nextY >= 0){
            //다음 칸 방문한적 X + 빙산에서 0이 아닌 value
            if(visit[nextX][nextY] == 0 && iceberg[nextX][nextY] != 0)
                DFS(nextX, nextY);  
            //0일때 녹일 값 저장
            if(iceberg[nextX][nextY] == 0) 
                tmp[x][y]++;
        }
    }
}

void melting_iceberg(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(iceberg[i][j] != 0){
                iceberg[i][j] -= tmp[i][j];
            }
            //해당 칸이 음수 값 나올 경우 0으로 
            if(iceberg[i][j] < 0) 
                iceberg[i][j] = 0;
            //다음 번을 위해 다시 0으로 초기화 + 방문 여부도 초기화
            tmp[i][j] = 0;
            visit[i][j] = false;
        }
    }
}