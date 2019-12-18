//백준 10817

#include <iostream>
using namespace std;

int main(){

	int arr[3], i, j, tmp;

    cin >> arr[0] >> arr[1] >> arr[2];
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++)
			if(arr[j] >= arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
    }
    cout << arr[1] << endl;
    
	return 0;
}

