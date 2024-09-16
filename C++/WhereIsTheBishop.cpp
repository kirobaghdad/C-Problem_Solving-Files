#include <iostream>
using namespace std;

void printArray(int* arr, int num) {
	cout << "[  ";
	for (int i = 0; i < num; i++)
	{
		if (i > 0)
			cout << ",  ";
		cout << arr[i] << "  ";
	}

	cout << "]" << endl;

}


void readArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void readChessBoard(bool arr[8][8]) {
	char in;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> in;
			if (in == '.')
				arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
}

void whereIsTheBishop(bool board[8][8], int* row, int* column, int c) {
	int sum;
	int sumPrev = 0;
	int index;
	for (int i = 0; i < 8; i++) {
		sum = 0;

		for (int j = 0; j < 8; j++)
		{
			if (board[i][j])
				index = j;
			sum += board[i][j];
		}
		if (sum == 1 && sumPrev == 2) {
			row[c] = i;
			column[c] = index;
			break;
		}
		sumPrev = sum;
	}
}

int main() {
	int t, n;
	cin >> t;
	int* ansColumn = new int[t];
	int* ansRow = new int[t];
	bool board[8][8];

	for (int i = 0; i < t; i++) {
		readChessBoard(board);
		whereIsTheBishop(board, ansRow, ansColumn, i);
	}

	for (int i = 0; i < t; i++)
	{
		cout << ansRow[i] + 1 << " " << ansColumn[i] + 1 << endl;
	}

	delete[]ansColumn;
	delete[]ansRow;
}