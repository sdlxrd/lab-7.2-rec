#include <iostream>
#include <iomanip>

using namespace std;

void Input(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void exchange(int** a, const int colCount, int rowCount);

int Min(int** a, const int colCount, int rowCount);
int Max(int** a, const int colCount, int rowCount);

int main()
{

	int rowCount;
	int colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);

	cout << endl;

	exchange(a, colCount, rowCount);
	Print(a, rowCount, colCount, 0, 0);

	return 0;
}

void exchange(int** a, const int rowCount, int colCount_i) {
	colCount_i -= 1;

	int min = Min(a, colCount_i, rowCount);
	int max = Max(a, colCount_i, rowCount);

	int tmp = a[colCount_i][max];
	a[colCount_i][max] = a[colCount_i][min];
	a[colCount_i][min] = tmp;


	if (colCount_i > 0)
		exchange(a, rowCount, colCount_i);
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];

	if (j < colCount - 1)
		Input(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Input(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];

	j++;
	if (j == colCount)
	{
		i++;
		j = 0;
		cout << endl;
	}

	if (i == rowCount)
		return;
	Print(a, rowCount, colCount, i, j);
}


int Min(int** a, const int rowCount, int colCount)
{
	if (colCount > 1) {
		int min = Min(a, rowCount, colCount - 1);
		if (a[rowCount][min] > a[rowCount][colCount - 1])
			min = colCount - 1;
		return min;
	}
	return 0;
}

int Max(int** a, const int rowCount, int  colCount)
{
	if (colCount > 1) {
		int min = Max(a, rowCount, colCount - 1);
		if (a[rowCount][min] < a[rowCount][colCount - 1])
			min = colCount - 1;
		return min;
	}
	return 0;
}
