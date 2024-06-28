#include <iostream>
using namespace std;

int *fun(int *arr)
{
    int sum = *arr + 2;
    return &sum;
}

int main()
{
    int arr;
    int *sum = fun(&arr);
    cout << *sum << endl;
    // cout << arr[0];

    return 0;
}