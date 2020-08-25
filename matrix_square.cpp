#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>>mul_matrix(vector<vector<long long>>arr1, vector<vector<long long>>arr2) {
	vector<vector<long long>>res;
	int len1 = arr1.size();
	int len2 = arr2.size();
	for (int i = 0; i < len1; i++) {
		vector<long long>result;
		for (int j = 0; j < len2; j++) {
			int sum = 0;
			for (int h = 0; h < len2; h++) {
				sum += ((arr1[i][h]%1000) * (arr2[h][j]%1000))%1000;
			}
			result.push_back(sum%1000);
		}
		res.push_back(result);
	}
	return res;
}


vector<vector<long long>>square(vector<vector<long long>>&arr, long long int B) {
	if (B == 1)
		return arr;
	else {
		if (B % 2 == 0) {
			vector<vector<long long>>res=square(arr,B/2);
			return mul_matrix(res, res);
		}
		else {
			return mul_matrix(square(arr, B - 1),arr);
		}
	}
}


void printMatrix(vector<vector<long long>>arr, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j]%1000 << " ";
		}
		cout << endl;
	}
}

int main() {
	int N; long long int B;
	cin >> N >> B;

	vector<vector<long long>> arr;
	
	for (int i = 0; i < N; i++) {
		vector<long long>res;
		for (int j = 0; j < N; j++){
			long long a;
			cin >> a;
			res.push_back(a);
		}
		arr.push_back(res);
	}

	//행렬 arr을 B제곱 해야 한다.
	//arr을 각각 N/2의 행렬 4개로 나눠서 계산해야 분할계산임.

	arr = square(arr, B);
	
	printMatrix(arr, N);

	system("pause");
}
