#include <iostream>
#include <cstring>
#define n 5
#define m 6
using namespace std;

int C[m + 1][n + 1];

void CalPath(int P[][n + 1])
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (C[i][j] == 0)
				P[i][j] = 0;
			else if (i == 1)
				P[i][j] = 1;
			else if (j == 1)
				P[i][j] = 1;
			else
				P[i][j] = P[i - 1][j] + P[i][j - 1];
		}
	}
}

int CalP(int i, int j)
{
	if (C[i][j] == 0)
		return 0;
	else if (j == 1 || i == 1)
		return 1;
	else
		return CalP(i - 1, j) + CalP(i, j - 1);
}

int main()
{
	int P[m + 1][n + 1] = { 0, };
	memset(C, 1, sizeof(C));
	C[1][5] = 0; C[3][3] = 0; C[5][2] = 0;
	cout << CalP(6, 5);
	/*for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << P[i][j] << "\t";
		cout << endl;
	}*/

	return 0;
}