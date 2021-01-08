#include <iostream>
using namespace std;
int num[101][10] = { 0, };
long long ans = 0;

void upstairs(int cnt)
{
	if (cnt == 1)
		return;

	for (int i = 1; i < 10; i++)
		num[1][i] = 1;
	num[1][0] = 0;
		for (int i = 2; i <= cnt; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j == 0)//앞의 계단수가 0으로 끝나는 경우. 즉, 그 뒤에 1밖에 못 붙음.
				{
					num[i][j] += num[i - 1][j + 1] % 1000000000;
				}

				else if (j == 9)//앞의 계단수가 9로 끝나는 경우. 즉, 그 뒤에 8밖에 못 붙음.
				{
					num[i][j] += num[i - 1][j - 1] % 1000000000;
				}

				else
				{
					num[i][j] += (num[i - 1][j - 1] + num[i - 1][j + 1]) % 1000000000;
				}
			}
		}
		
	
	return;
}

int main()
{
	int cnt; cin >> cnt;

	if (cnt == 1)
	{
		cout << 9;
		return 0;
	}

	upstairs(cnt);

	for (int j = 0; j < 10; j++)
		ans += num[cnt][j];
	cout << ans % 1000000000;
}