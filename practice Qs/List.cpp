#include <iostream>
using namespace std;

class List
{
    float *list;
    int count;

public:
    List() {}
    List(float *arr, int count) : count(count)
    {
        list = new float[count];
        for (int i = 0; i < count; i++)
        {
            list[i] = arr[i];
        }
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << list[i] << endl;
        }
    }
    List &operator+(float n)
    {
        List *temp = new List;
        temp->count = count + 1;
        temp->list = new float[temp->count];

        for (int i = 0; i < count; i++)
        {
            temp->list[i] = list[i];
        }

        temp->list[count++] = n;
        return *temp;
    }
    List &operator+(List &obj)
    {
        List *temp = new List;
        temp->count = count + obj.count;
        temp->list = new float[temp->count];
        int counter = 0;

        for (int i = 0; i < count; i++)
        {
            temp->list[counter++] = list[i];
        }

        for (int i = 0; i < count; i++)
        {
            temp->list[counter++] = obj.list[i];
        }

        return *temp;
    }
    int operator[](float n)
    {
        for (int i = 0; i < count; i++)
        {
            if (n == list[i])
                return i;
        }
        return -1;
    }
    int Length()
    {
        return count;
    }
    float operator-()
    {
        if (count > 0)
        {
            float item = list[0];

            count--;

            for (int i = 0; i < count; i++)
            {
                list[i] = list[i + 1];
            }

            return item;
        }
        return 0.0f;
    }
    void reverse()
    {
        float temp = 0.0;
        for (int i = 0; i < count / 2; i++)
        {
            temp = list[i];
            list[i] = list[count - i - 1];
            list[count - i - 1] = temp;
        }
    }
    void setCount(int n)
    {
        count = n;
    }
    int getCount()
    {
        return count;
    }
    friend ostream &operator<<(ostream &out, List &obj);
};

ostream &operator<<(ostream &out, List &obj)
{
    for (int i = 0; i < obj.count; i++)
    {
        out << obj.list[i] << endl;
    }
    return out;
}

int main()
{
    float arr[] = {1, 2, 3, 4, 5};
    float arr2[] = {6, 7, 8, 9, 10};
    List l(arr, 5), l2(arr2, 5);
    l.print();

    l = l + 6.7;
    cout << endl;
    l.print();

    cout << endl;
    l = l + l2;
    l.print();

    cout << endl;

    float item = -l;
    cout << item << endl
         << endl;
    l.print();

    cout << "Index : ";
    cout << l[6.8] << endl;

    cout << endl;
    l.reverse();
    l.print();

    cout << endl;
    cout << l;
    cout << endl;
    cout << l2;
    return 0;
}