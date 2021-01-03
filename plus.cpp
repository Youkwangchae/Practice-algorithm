#include <iostream>
#include <string>
int res[11];
using namespace std;

void make(int n)
{
	for (int i = 4; i <= n; i++)
		res[i] = res[i-1] + res[i- 2] + res[i-3];
}

int main()
{
	int cnt; string str = "";
	cin >> cnt;
	res[1] = 1; res[2] = 2; res[3] = 4;
	for (int i = 0; i < cnt; i++)
	{
		int num; cin >> num;
		make(num);
		str+=to_string(res[num])+"\n";
	}
	cout << str;
}