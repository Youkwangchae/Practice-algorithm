#include <iostream>
using namespace std;

int matrix1[100][100]; //NxM 행렬
int matrix2[100][100]; //MxK 행렬

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix1[i][j];
	
	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> matrix2[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int sum = 0;
			for (int h = 0; h < m; h++) {
				sum += matrix1[i][h] * matrix2[h][j];
			}
			cout << sum << " ";
		}
		cout << endl;
	}
	system("pause");
}