#include <iostream>
using namespace std;
int num = 0;

int main() {
	int CASE;
	cin >> CASE;
	for (int i = 0; i < CASE; i++) {
		num = 0;
		int n, m, cnt;
		cnt = 0;//내가 찾는 수가 나오는 순서.
		cin >> n >> m;
		num = n;
		int test[10000];
		for (int i = 0; i < n; i++)
			cin >> test[i];
		int k = 0;//스택 포인터
		while (true) {
			bool is_same = false;
			bool is_small = true;
			if (k == m) {
				is_same = true;
			}

			int j = 0;
			for (int j = k; j < num + k; j++) {
				if (test[k] < test[j]) {
					is_small = false;
					test[num + k] = test[k++];
					break;
				}
			}
			if (is_small) {
				cnt++;
				num--;
				k++;
				if (is_same)
				{
					cout << cnt << endl;
					break;
				}
			}

			if (is_same)
				m = k + num - 1;

		}
	}
}