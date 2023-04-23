/*
 * Acest schelet citește datele de intrare și scrie răspunsul generat de voi,
 * astfel că e suficient să completați cele două funcții.
 *
 * Scheletul este doar un punct de plecare, îl puteți modifica oricum doriți:
 * puteți schimba parametrii, reordona funcțiile etc.
 */

#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

// sorting in descending order
int compare_desc(const void *a, const void *b) {
    return *((int *)b) - *((int *)a);
}

// sorting in ascending order
int compare_asc(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int64_t SolveTask1(const vector<int> &a, const vector<int> &b) {
    int i, size = (int)a.size();
    int64_t sum = 0;
    int *vec = new int[2 * size];

    // vec contains the values from both vectors a and b
    for (i = 0; i < size; i++)
        vec[i] = a[i];

    for (i = 0; i < size; i++)
        vec[size + i] = b[i];

    // vec is sorted in descending order
    qsort(vec, 2 * size, sizeof(int), compare_desc);

    // the maxim sum is the sum of the biggest n values
    for (i = 0; i < size; i++)
        sum += vec[i];

    delete[] vec;

    return sum;
}

int64_t SolveTask2(const vector<int> &a, const vector<int> &b, int moves) {
    int64_t sum = 0;
    int i, size = (int)a.size();

    // initial sum
    for (i = 0; i < size; i++)
        sum += max(a[i], b[i]);

    // this vector stores the minimum value between numbers on the same position
    int *vec_min = new int[size];

    // this vector stores the maximum value between numbers on the same position
    int *vec_max = new int[size];

    for (i = 0; i < size; i++) {
        vec_min[i] = min(a[i], b[i]);
        vec_max[i] = max(a[i], b[i]);
    }

    // the minimum vector is sorted in descending order
    qsort(vec_min, size, sizeof(int), compare_desc);

    // the maximum vector is sorted in ascending order
    qsort(vec_max, size, sizeof(int), compare_asc);

    for (int move = 0; move < moves; move++)
        if (vec_min[move] > vec_max[move])  // the switch would increase the sum
            sum += vec_min[move] - vec_max[move];
        else
            break;

    delete[] vec_min;
    delete[] vec_max;

    return sum;
}

vector<int> ReadVector(istream &is, int size) {
    vector<int> vec(size);
    for (auto &num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
    fout << res << "\n";

    return 0;
}
