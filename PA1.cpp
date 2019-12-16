/* 
	GBC_Algoritm 1-1
    21800758 choi hayeong 
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int m = 0, n = 0;
	int x = 0, y = 0;
	int dir = 0; //0 : 동, 1 : 남,  2 : 서, 3 : 북
    int d = 0;  //로봇이 향하는 방향 (d > 0) 
    string input;

	std::cin >> m >> n;
	while(n--){
		cin >> input >> d;

		if(input.compare("TURN") == 0){
            if(d == 1){ 
                dir = (dir + 1) % 4;
			}
			else{ //0 : 왼쪽 90 , 동 --> 북
				dir--;
                if (dir == -1) {    
                    dir = 3;    //왼쪽으로 돌림
                }
			}
		}
        else if (input.compare("MOVE") == 0){
            if (dir == 0){ //동
				x = x + d;
			}
			else if (dir == 1){//남
				y = y - d;
			}
			else if (dir == 2){//서
                x = x - d;
			}
			else{//북
				y = y + d;
			}
		}

        //영역 넘어가면 -1
		if (x > m || y > m || x < 0 || y < 0){
			cout << -1;
			return 0;
		}
	}
	cout << x << " " << y << endl;

	return 0;
}