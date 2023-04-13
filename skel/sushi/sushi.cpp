#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector<int> &p, vector<vector<int>> &g)
{
	// m -> number of plates
	// n * x -> max capacity
	// (prices[i], grades_sum[i])-> the characteristics of the object i ($i = 1 : m)

	// Stores the total value of each plate
	vector<int> grades_sum(m + 1, 0);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			grades_sum[i + 1] += g[j][i];

	// The vector should start at index 1
	vector<int> prices(m + 1, 0);

	for (int i = 1; i <= m; i++)
		prices[i] = p[i - 1];

	vector<vector<int>> dp(m + 1, vector<int>(n * x + 1, 0));

	// the base case
	for (int cap = 0; cap <= n * x; ++cap)
		dp[0][cap] = 0;

	// general case
	for (int i = 1; i <= m; ++i)
		for (int cap = 0; cap <= n * x; ++cap)
		{
			// We don't use object i => it's the solution from step i - 1
			dp[i][cap] = dp[i - 1][cap];

			// We use object i, so I need to reserve prices[i] units
			// => before we had to occupy at most (cap - prices[i]) units

			if (cap - prices[i] >= 0)
			{
				int sol_aux = dp[i - 1][cap - prices[i]] + grades_sum[i];
				dp[i][cap] = max(dp[i][cap], sol_aux);
			}
		}

	return dp[m][n * x];
}

int task2(int n, int m, int x, vector<int> &p, vector<vector<int>> &g)
{
	// Since we can add each type of plate 2 times, we consider it to be
	// 2 different objects with the same characteristics

	// 2 * m -> number of plates
	// n * x -> max capacity
	// (prices[i], grades_sum[i])-> the characteristics of the object i ($i = 1 : 2 * m)

	// Stores the total value of each plate
	vector<int> grades_sum(2 * m + 1, 0);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			grades_sum[2 * i + 1] += g[j][i];
			grades_sum[2 * i + 2] += g[j][i];
		}

	// The vector should start at index 1
	vector<int> prices(2 * m + 1, 0);

	for (int i = 0; i < m; i++)
	{
		prices[2 * i + 1] = p[i];
		prices[2 * i + 2] = p[i];
	}

	vector<vector<int>> dp(2 * m + 1, vector<int>(n * x + 1, 0));

	// the base case
	for (int cap = 0; cap <= n * x; ++cap)
		dp[0][cap] = 0;

	// general case
	for (int i = 1; i <= 2 * m; ++i)
		for (int cap = 0; cap <= n * x; ++cap)
		{
			// We don't use object i => it's the solution from step i - 1
			dp[i][cap] = dp[i - 1][cap];

			// We use object i, so we need to reserve prices[i] units
			// => before we had to occupy at most (cap - prices[i]) units

			if (cap - prices[i] >= 0)
			{
				int sol_aux = dp[i - 1][cap - prices[i]] + grades_sum[i];
				dp[i][cap] = max(dp[i][cap], sol_aux);
			}
		}

	return dp[2 * m][n * x];
}

int task3(int n, int m, int x, vector<int> &p, vector<vector<int>> &g)
{
	// TODO solve task 3
	return 0;
}

int main()
{
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task; // task number

	int n; // number of friends
	int m; // number of sushi types
	int x; // how much each of you is willing to spend

	vector<int> prices; // prices of each sushi type
	// the grades_sum you and your friends gave to each sushi type
	vector<vector<int>> grades_sum;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades_sum.assign(n, vector<int>(m, 0));

	// price of each sushi
	for (int i = 0; i < m; ++i)
	{
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grades_sum[i][j];
		}
	}

	int ans = -1;

	switch (task)
	{
	case 1:
		ans = task1(n, m, x, prices, grades_sum);
		break;
	case 2:
		ans = task2(n, m, x, prices, grades_sum);
		break;
	case 3:
		ans = task3(n, m, x, prices, grades_sum);
		break;
	default:
		cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
