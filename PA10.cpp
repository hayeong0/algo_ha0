/*
    GBC_Algorithm_PA10
    21800758 Choi HaYeong
    [백준_1670 정상회담 2]
*/

#include<iostream>
using namespace std;

long long dp[100001];
long long tmp = 987654321;

int main()
{
	int n = 0;
	cin >> n;
	dp[0] = 1;  
	for(int i=2; i<=n; i+=2)
	{
		for(int j=0; j<= i-2; j+=2)
			dp[i] += dp[j] * dp[i-j-2] % tmp;
	}
    long long result = dp[n];
	cout << result;
}