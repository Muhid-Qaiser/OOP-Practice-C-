#include <iostream>
using namespace std;

template <typename T>
class Set
{
    T *set;
    int count;

public:
    Set() : count(0) {}
    Set(T *arr, int count) : count(count)
    {
        set = new T[count];
        for (int i = 0; i < count; i++)
        {
            set[i] = arr[i];
        }
    }

    Set operator-(Set &obj)
    {

        Set res;
        res.count = 0;
        int big = (count > obj.count) ? count : obj.count;
        int small = (count < obj.count) ? count : obj.count;

        int temp = 0;
        int arr[big];
        bool checker = true;

        for (int i = 0; i < big; i++)
        {
            for (int j = 0; j < small; j++)
            {
                if (set[i] == obj.set[j])
                {
                    checker = false;
                }
            }

            if (checker)
            {
                arr[res.count] = set[i];
                res.count++;
            }
            checker = true;
        }

        res.set = new T[res.count];

        for (int i = 0; i < res.count; i++)
        {
            res.set[i] = arr[i];
        }

        return res;
    }
    Set operator+(Set &obj)
    {
        Set res;
        res.count = 0;
        int counter = 0;
        int temp[10];

        for (int i = 0; i < 10; i++)
        {
            temp[i] = -1;
        }

        for (int i = 0; i < count; i++)
        {
            if (findUnique(temp, set[i], res.count))
            {
                temp[res.count++] = set[i];
            }
        }

        for (int i = 0; i < obj.count; i++)
        {
            if (findUnique(temp, obj.set[i], res.count))
            {
                temp[res.count++] = obj.set[i];
            }
        }

        res.set = new T[res.count];

        for (int i = 0; i < res.count; i++)
        {
            res.set[i] = temp[i];
        }

        return res;
    }
    Set operator^(Set &obj)
    {
        Set res;
        res.count = 0;
        int temp[10];

        for (int i = 0; i < ((count > obj.count) ? count : obj.count); i++)
        {
            for (int j = 0; j < ((count < obj.count) ? count : obj.count); j++)
            {
                if (obj.set[j] == set[i])
                {
                    temp[res.count++] = set[i];
                }
            }
        }

        res.set = new T[res.count];
        for (int i = 0; i < res.count; i++)
        {
            res.set[i] = temp[i];
        }

        return res;
    }
    bool operator==(Set &obj)
    {
        if (count != obj.count)
            return false;

        for (size_t i = 0; i < count; i++)
            if (set[i] != obj.set[i])
                return false;

        return true;
    }

    bool findUnique(int temp[], int x, int size)
    {
        for (int i = 0; i < size; i++)
            if (temp[i] == x)
                return false;

        return true;
    }
    void display()
    {
        for (int i = 0; i < count; i++)
        {
            cout << set[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int a1[] = {3, 5};
    int a2[] = {3, 5};

    Set<int> s1(a1, (sizeof(a1) / sizeof(a1[0]))), s2(a2, (sizeof(a2) / sizeof(a2[0])));

    Set<int> s3 = s1 - s2;

    s3.display();

    s3 = s1 + s2;
    s3.display();

    s3 = s1 ^ s2;
    s3.display();

    bool result = s1 == s2;
    cout << result << endl;

    return 0;
}