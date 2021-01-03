#include <iostream>
using namespace std;
long long res[1001];

void tiles(int n)
{
	if (n == 1)
		return;
	for (int i = 3; i <= n; i++)
	{
		res[i] += (res[i - 1] + res[i - 2])%10007;
	}
}


int main()
{
	int cnt;
	cin >> cnt;

	for (int i = 2; i < cnt; i++)
		res[i] = 0;
	res[1] = 1; res[2] = 2;

	tiles(cnt);

	cout << res[cnt];
}