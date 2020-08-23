#include <iostream>
#include <queue>
using namespace std;

int main() {
	int CASE;
	cin >> CASE;

	for (int i = 0; i < CASE; i++) {

		int n, m;
		cin >> n >> m;
		int arrImportance[10];//중요도가 1~9인 각 문서의 개수를 저장. (인덱스 5에는 중요도가 5인 문서 개수 저장.)
		for (int i = 0; i < 10; i++) arrImportance[i] = 0;

		bool *arr = new bool[n]; //각 문서별로 출력여부를 저장.
		for (int i = 0; i < n; i++) arr[i] = false;

		queue<int>idx;
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			arrImportance[a]++;
			idx.push(a);
		}

		int k = 0; // 큐의 포인터
		int cnt = 0; // 구하는 값
		bool finish=false;

		for (int h = 9; h > 0; h--) {
			while (arrImportance[h] != 0) {

				if (idx.front() == h) {
					cnt++;
					if (k == m) {
						cout << cnt<<endl;
						finish = true;
						break;
					}

					else {
						arrImportance[h]--;
						arr[k] = true;
						while(arr[k])
							k=(k+1)%n;
						idx.pop();
					}
				}
				else {
					k = (k + 1) % n;
					while(arr[k])
						k = (k + 1) % n;

					idx.push(idx.front());
					idx.pop();
				}

			}
			if (finish) break;
		}
		delete[] arr;
	}
}