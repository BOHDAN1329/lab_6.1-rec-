#include <iostream>
#include <time.h>
using namespace std;

void Create(int* r, const int size, const int Low, const int High, int i)
{
    r[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(r, size, Low, High, i + 1);
}



void result(int r[], const int size, int i) {
    if (i < size)
    {
        if (r[i] % 6 == 0 || !(i % 5 == 0) )
            r[i] = 0;
        return result(r, size, i + 1);
    }
}
int Sum(int* r, const int size, int i)
{
    if (r[i] % 6 == 0 || !(i % 5 == 0)) {
        if (i < size)
            return r[i] + Sum(r, size, i + 1);
    }
    else
        return Sum(r, size, i + 1);
}

int Count(const int r[], const int n, int i)
{
    if (i < n)
    {
        if (r[i] % 6 == 0 || !(i % 5 == 0))
            return 1 + Count(r, n, i + 1);
        else
            return Count(r, n, i + 1);
    }
    else return 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 25;

    int r[n];
    int Low = 4;
    int High = 73;
    Create(r, n, Low, High, 0);


    cout << r[0];
    for (int i = 1; i < sizeof r / sizeof(int);) cout << ' ' << r[i++];
    cout << endl;

    int sum = Sum(r, n, 0);
    cout << "Sum = " << sum << endl;

    result(r, n, 0);

    cout << r[0];
    for (int i = 1; i < sizeof r / sizeof(int);) cout << ' ' << r[i++];
    cout << endl;


    int Num = Count(r, n, 0);
    cout << "Number of elements = " << Num << endl;

    return 0;
}