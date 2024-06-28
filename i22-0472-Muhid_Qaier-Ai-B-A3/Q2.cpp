#include <iostream>
#include <cmath>
using namespace std;

// ! Structs and functions

struct points
{
    int **data_points;
    double **average;
    int group1;
    int group2;
    int group3;
};

void addAvg(points &p, int ***&groups, int n, int total, int count[]) // Calculates the average points
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            p.average[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < total; k++)
                p.average[i][j] += groups[i][k][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            p.average[i][j] /= count[i];

            /*
            // if (i == 0)
            // {
            //     p.average[i][j] /= count[i];
            // }
            // else if (i == 1)
            // {
            //     p.average[i][j] /= count[i];
            // }
            // else if (i == 2)
            // {
            //     p.average[i][j] /= count[i];
            // }
            */

            //  cout << p.average[i][j] << " ";
        }
        //   cout << endl;
    }
}

bool check(points p, double **temp, int n) // checking to see if average points have changed
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            //  cout << p.average[i][j] << " " << temp[i][j] << endl;
            if (p.average[i][j] != temp[i][j])
                return false;
        }
    }
    return true;
}

void Clustering(points &p, int n, const int total)
{

    int smallest_Index = 0, check_small = 0, iteration = 0;
    int *distance;

    int *count = new int[n];

    double **temp = new double *[n];
    int ***groups = new int **[n];
    distance = new int[n];

    for (int i = 0; i < n; i++)
    {
        groups[i] = new int *[total];
        for (int j = 0; j < total; j++)
        {
            temp[i] = new double[2];
            groups[i][j] = new int[2];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < total; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                groups[i][j][k] = 0;
            }
        }
    }

    do
    {
        iteration++;

        for (int i = 0; i < n; i++)
            count[i] = 0;

        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // calculating distance
                distance[j] = sqrt(((p.average[j][0] - p.data_points[i][0]) * (p.average[j][0] - p.data_points[i][0])) + ((p.average[j][1] - p.data_points[i][1]) * (p.average[j][1] - p.data_points[i][1])));
                //     cout << distance[j] << " ";
            }
            //   cout << endl;
            check_small = distance[0];
            smallest_Index = 0;

            for (int j = 0; j < n; j++)
            {
                if (check_small >= distance[j])
                {
                    check_small = distance[j];
                    smallest_Index = j;
                }
            }
            distance[0] = {0};
            //   cout << "smallest_Index: " << smallest_Index << endl;

            for (int j = 0; j < n; j++)
            {
                if (smallest_Index == j)
                {
                    for (int k = 0; k < 2; k++)
                        groups[j][count[j]][k] = p.data_points[i][k];

                    count[j]++;
                }
            }
        }

        // displaying groups
        cout << "\nGroups of Iteration " << iteration << "\n---------------------\n";

        cout << "Group 1 : ";
        for (int j = 0; j < count[0]; j++)
        {
            for (int k = 0; k < 2; k++)
                cout << groups[0][j][k] << " ";
            cout << "|| ";
        }
        cout << endl;

        cout << "Group 2 : ";
        for (int j = 0; j < count[1]; j++)
        {
            for (int k = 0; k < 2; k++)
                cout << groups[1][j][k] << " ";
            cout << "|| ";
        }
        cout << endl;

        cout << "Group 3 : ";
        for (int j = 0; j < count[2]; j++)
        {
            for (int k = 0; k < 2; k++)
                cout << groups[2][j][k] << " ";
            cout << "|| ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                temp[i][j] = p.average[i][j];

        addAvg(p, groups, n, total, count);

    } while (!check(p, temp, n));
}

int main()
{
    cout << "\nData Point Clustering Algorithm"
         << "\n===============================\n";

    int total_points = 8, n = 3;

    points p1;
    p1.data_points = new int *[total_points];
    p1.average = new double *[n];

    for (int i = 0; i < total_points; i++)
        p1.data_points[i] = new int[2];

    for (int i = 0; i < n; i++)
        p1.average[i] = new double[2];

    p1.data_points[0][0] = 2;
    p1.data_points[0][1] = 10;
    p1.data_points[1][0] = 2;
    p1.data_points[1][1] = 5;
    p1.data_points[2][0] = 8;
    p1.data_points[2][1] = 4;
    p1.data_points[3][0] = 5;
    p1.data_points[3][1] = 8;
    p1.data_points[4][0] = 7;
    p1.data_points[4][1] = 5;
    p1.data_points[5][0] = 6;
    p1.data_points[5][1] = 4;
    p1.data_points[6][0] = 1;
    p1.data_points[6][1] = 2;
    p1.data_points[7][0] = 4;
    p1.data_points[7][1] = 9;

    p1.average[0][0] = 2;
    p1.average[0][1] = 10;
    p1.average[1][0] = 5;
    p1.average[1][1] = 8;
    p1.average[2][0] = 1;
    p1.average[2][1] = 2;

    // ? self input
    /*

     int n = 0, total_points = 0;

     cout << "\nEnter Number of Data Points: ";
     cin >> total_points;

     cout << "\nEnter Number of Average Points: ";
     cin >> n;

     points p1;

     p1.data_points = new int *[total_points];
     p1.average = new double *[n];

     for (int i = 0; i < total_points; i++)
     {
         p1.data_points[i] = new int[2];

         cout << "\nPoint " << i + 1 << " : \n";
         for (int j = 0; j < 2; j++)
         {

             (j == 0) ? cout << " Enter x : " : cout << " Enter y : ";
             cin >> p1.data_points[i][j];
         }
     }

     cout << endl;

     for (int i = 0; i < n; i++)
     {
         p1.average[i] = new double[2];

         cout << "\nAvg Point " << i + 1 << " : \n";
         for (int j = 0; j < 2; j++)
         {

             (j == 1) ? cout << " Enter x : " : cout << " Enter y : ";
             cin >> p1.average[i][j];
         }
     }
     */

    Clustering(p1, n, total_points);

    cout << "\n\nThe Average Points : " << endl;
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". ( " << p1.average[i][0] << " , " << p1.average[i][1] << " ) " << endl;

    cout << "\n===============================\n\n";

    return 0;
}