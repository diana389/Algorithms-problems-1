#include <iostream>

using namespace std;

const int mod = 1000000007;

int type1(int x, int y)
{
	// allocate the memory
	int **dp = new int *[x + 1];
	for (int i = 0; i <= x; i++)
		dp[i] = new int[y + 1];

	// the base cases
	for (int i = 0; i <= x; i++)
		dp[i][0] = 1;

	dp[0][1] = 1;

	for (int j = 2; j <= y; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
		{
			// if it starts with a 0 => x - 1 zeros and y ones to arrange
			dp[i][j] = dp[i - 1][j] % mod;

			// if it starts with a 1, it must be followed bt a 0 => x - 1 zeros and y - 1 ones to arrange
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
		}

	int result = dp[x][y];

	// free the memory
	for (int i = 0; i <= x; i++)
		delete[] dp[i];

	delete[] dp;

	return result;
}

int type2(int x, int y)
{
	// allocate the memory
	int **dp = new int *[x + 1];
	for (int i = 0; i <= x; i++)
		dp[i] = new int[y + 1];

	// the base cases
	for (int i = 0; i <= x; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i + 1;
	}

	dp[0][2] = 1;

	for (int j = 3; j <= y; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= x; i++)
		for (int j = 2; j <= y; j++)
		{
			// if it starts with a 0 => x - 1 zeros and y ones to arrange
			dp[i][j] = dp[i - 1][j] % mod;

			// if it starts with a 10 => x - 1 zeros and y - 1 ones to arrange
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1] % mod) % mod;

			// if it starts with a 11, it must be followed bt a 0 => x - 1 zeros and y - 2 ones to arrange
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 2] % mod) % mod;
		}

	int result = dp[x][y];

	// free the memory
	for (int i = 0; i <= x; i++)
		delete[] dp[i];

	delete[] dp;

	return result;
}

int main()
{
	freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

	switch (sig_type)
	{
	case 1:
		cout << type1(x, y);
		break;
	case 2:
		cout << type2(x, y);
		break;
	default:
		cout << "wrong task number" << endl;
	}

	return 0;
}
