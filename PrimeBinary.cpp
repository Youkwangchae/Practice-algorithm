#include <iostream>
using namespace std;

long long res[91][2] = { 0, };

int main()
{
	int cnt; cin >> cnt;

	res[1][1] = 1;
	res[2][0] = 1;

	for (int i = 3; i <= cnt; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				res[i][j] += res[i - 1][j];
				res[i][j + 1] += res[i - 1][j];
			}
			else
				res[i][j-1] += res[i - 1][j];
		}
	}

	long long ans = 0;

	for (int i = 0; i < 2; i++)
		ans += res[cnt][i];

	cout << ans;
	
	return 0;
}