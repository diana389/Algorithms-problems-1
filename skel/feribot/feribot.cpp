#include <iostream>
#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

vector<int64_t> ReadVector(istream &is, int size,
                    int64_t &elem_max, int64_t &sum) {
    vector<int64_t> vec(size);

    for (auto &num : vec) {
        is >> num;

        if (num > elem_max)
            elem_max = num;

        sum += num;
    }

    return vec;
}

// check if the cost could be a solution
bool PossibleResult(int64_t max, vector<int64_t> &v, int N, int K) {
    int i, groups = 1;
    int64_t current_sum = 0;

    // form groups to fit the cost
    for (i = 0; i < N; i++)
        if (current_sum + v[i] <= max) {
            current_sum += v[i];  // the car can be addes to the group
        } else {
            current_sum = v[i];  // it is formed a new group
            groups++;
        }

    // the minimum number of groups formed to fit the cost max
    if (groups <= K)
        return 1;

    return 0;
}

int64_t BinarySearch(int64_t left, int64_t right, vector<int64_t> &v,
                                                    int N, int K) {
    int64_t mid, res = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        if (PossibleResult(mid, v, N, K) == 1) {
            res = mid;        // the solution is saved
            right = mid - 1;  // the search continues for a smaller value
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int N, K;
    int64_t elem_max = -1, sum = 0;
    fin >> N >> K;

    auto v = ReadVector(fin, N, elem_max, sum);

    int64_t res = BinarySearch(elem_max, sum, v, N, K);
    fout << res << endl;
}
