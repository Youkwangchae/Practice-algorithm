#include <iostream>
using namespace std;

int num[1001][10] = { 0, };
long long ans = 0;

int main()
{
	int cnt; cin >> cnt;

	for (int i = 0; i < 10; i++)
		num[1][i] = 1;

	for (int i = 2; i <= cnt; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int sum = 0;
			for (int k = 0; k <= j; k++)
			{
				sum += num[i - 1][k];
			}
			num[i][j] += sum % 10007;
		}
	}

	for (int i = 0; i < 10; i++)
		ans += num[cnt][i];
	cout << ans % 10007;
}