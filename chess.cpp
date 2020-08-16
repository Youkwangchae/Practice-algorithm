#include <iostream>
#include <string>
using namespace std;
int z = 2500;

int colorcheck1(const string chess[50][50], int i, int j) {
	int cnt1 = 0;

	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (chess[2 * a + i][2 * b + j] != "W")
				cnt1++;
			if (chess[2 * a + i][2 * b + 1 + j] != "B")
				cnt1++;
			if (chess[2 * a + 1 + i][2 * b + j] != "B")
				cnt1++;
			if (chess[2 * a + 1 + i][2 * b + 1 + j] != "W")
				cnt1++;
		}
	}
	return cnt1;
}

int colorcheck2(const string chess[50][50], int i, int j) {
	int cnt2 = 0;

	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (chess[2 * a + i][2 * b + j] != "B")
				cnt2++;
			if (chess[2 * a + i][2 * b + 1 + j] != "W")
				cnt2++;
			if (chess[2 * a + 1 + i][2 * b + j] != "W")
				cnt2++;
			if (chess[2 * a + 1 + i][2 * b + 1 + j] != "B")
				cnt2++;
		}
	}

	return cnt2;
}

int main() {
	int n, m;
	cin >> n >> m;
	string chess[50][50];
	string str = "";
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			chess[i][j] = str.at(j);
		}
	}



	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			if (z > colorcheck1(chess, i, j))
				z = colorcheck1(chess, i, j);
			if (z > colorcheck2(chess, i, j))
				z = colorcheck2(chess, i, j);

		}
	}

	cout << z;
}