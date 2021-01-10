#include <iostream>
#include <algorithm>
using namespace std;

int sticker(int num, int res[2][100001], int dp[3][100001])
{
	int result;
	
	dp[0][0] = 0;
	dp[1][0] = res[0][0];
	dp[2][0] = res[1][0];

	for (int i = 1; i <= num; i++)
	{
		dp[0][i] = max(dp[1][i-1], dp[2][i-1]);
		dp[1][i] = res[0][i] + max(dp[0][i - 1], dp[2][i-1]);
		dp[2][i] = res[1][i] + max(dp[0][i - 1], dp[1][i-1]);

		result = max(dp[1][i], dp[2][i]);

	}
	
	return result;
}

int main()
{
	//아래는 cin과 cout의 연결을 끊는다. 각각 독립적으로 움직이게 됨. 그래서 버퍼도 덜 쓰게 되고, 더 빠르게 돌아감.
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt; cin >> cnt;
	
	while (cnt > 0)
	{
		int res[2][100001] = { 0, };
		int dp[3][100001] = { 0, };

		cnt--;

		int num; cin >> num;

		for (int i = 0; i < num; i++) cin >> res[0][i];
		for (int i = 0; i < num; i++) cin >> res[1][i];

		cout << sticker(num, res, dp) << endl;


	}
	return 0;
}