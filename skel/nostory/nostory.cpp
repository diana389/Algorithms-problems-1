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
int compare_desc(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

// sorting in ascending order
int compare_asc(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int64_t SolveTask1(const vector<int> &a, const vector<int> &b)
{
    int i;
    int64_t sum = 0;
    int vec[2 * a.size()];

    // vec contains the values from both vectors a and b
    for (i = 0; i < a.size(); i++)
        vec[i] = a[i];

    for (i = 0; i < b.size(); i++)
        vec[a.size() + i] = b[i];

    // vec is sorted in descending order
    qsort(vec, 2 * a.size(), sizeof(int), compare_desc);

    // the maxim sum is the sum of the biggest n values
    for (i = 0; i < a.size(); i++)
        sum += vec[i];

    return sum;
}

int64_t SolveTask2(ostream &fout, const vector<int> &a, const vector<int> &b, int moves)
{
    int64_t sum = 0;

    // initial sum
    for (int i = 0; i < a.size(); i++)
        sum += max(a[i], b[i]);

    int vec_min[a.size()]; // this vector stores the minimum value between numbers on the same position
    int vec_max[a.size()]; // this vector stores the maximum value between numbers on the same position

    for (int i = 0; i < a.size(); i++)
    {
        vec_min[i] = min(a[i], b[i]);
        vec_max[i] = max(a[i], b[i]);
    }

    // the minimum vector is sorted in descending order
    qsort(vec_min, a.size(), sizeof(int), compare_desc);

    // the maximum vector is sorted in ascending order
    qsort(vec_max, a.size(), sizeof(int), compare_asc);

    // for (int i = 0; i < a.size(); i++)
    //     fout << vec_max[i] << " ";
    // fout << endl;
    // for (int i = 0; i < a.size(); i++)
    //     fout << vec_min[i] << " ";
    // fout << endl;

    for (int move = 0; move < moves; move++)
        if (vec_min[move] > vec_max[move]) // the switch would increase the sum
            sum += vec_min[move] - vec_max[move];
        else
            break;

    // int prev_nr_max = 1000000001, prev_nr_min = 0;

    // for (int move = 0; move < moves; move++)
    // {
    //     int nr_max = 0, nr_min = 1000000001;

    //     for (int i = 0; i < a.size(); i++)
    //     {
    //         if (min(a[i], b[i]) > nr_max && min(a[i], b[i]) < prev_nr_max)
    //             nr_max = min(a[i], b[i]);

    //         if (max(a[i], b[i]) < nr_min && max(a[i], b[i]) > prev_nr_min)
    //             nr_min = max(a[i], b[i]);
    //     }

    //     prev_nr_min = nr_min;
    //     prev_nr_max = nr_max;

    //     if (nr_max > nr_min)
    //         sum += nr_max - nr_min;
    //     else
    //         break;

    //     // fout << nr_max << " " << nr_min << " " << sum << endl;
    // }

    return sum;
}

vector<int> ReadVector(istream &is, int size)
{
    vector<int> vec(size);
    for (auto &num : vec)
    {
        is >> num;
    }
    return vec;
}

int main()
{
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1)
    {
        fin >> n;
    }
    else
    {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(fout, a, b, moves);
    fout << res << "\n";

    return 0;
}
