#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

vector<int64_t> ReadVector(istream &is, int size, int64_t &elem_max, int64_t &sum)
{
    vector<int64_t> vec(size);

    for (auto &num : vec)
    {
        is >> num;

        if (num > elem_max)
            elem_max = num;

        sum += num;
    }

    return vec;
}

bool PossibleResult(ostream &fout, int64_t min, vector<int64_t> &v, int N, int K)
{
    int i, groups = 1;
    int64_t current_sum = 0;

    for (i = 0; i < N; i++)
        if (current_sum + v[i] <= min)
            current_sum += v[i];
        else
        {
            current_sum = v[i];
            groups++;
        }

    if (groups <= K)
        return 1;

    return 0;
}

int64_t BinarySearch(ostream &fout, int64_t left, int64_t right, vector<int64_t> &v, int N, int K)
{
    int64_t mid, res = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (PossibleResult(fout, mid, v, N, K) == 1)
        {
            res = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return res;
}

int main()
{
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int N, K;
    int64_t elem_max = -1, sum = 0;
    fin >> N >> K;

    auto v = ReadVector(fin, N, elem_max, sum);

    int64_t res = BinarySearch(fout, elem_max, sum, v, N, K);
    fout << res << endl;
}