#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

#define MAX 50000 // max number of rows

// ! Functions and classes

// Defining struct
struct dataset
{
    int *swimPool, *Deck, *Garden, *FirePlace, *Garage, *Hardwood, *Balcony, *Gym, *ageRange, *demo;

    string *property_age, *cond, *price, *Amenities, *beds, *baths, *type, *age_Range, *city, *Demo, *Age, *Area, *property;

    unsigned long long int twentyplus = 0;
    unsigned long long int ten_20 = 0;
    unsigned long long int five_10 = 0;
    unsigned long long int lessthan5 = 0;

    unsigned long long int FWC_avg1;
    int FWC_avg1_div;
    unsigned long long int FWC_avg2;
    int FWC_avg2_div;

    unsigned long long int EE_avg1;
    int EE_avg1_div;
    unsigned long long int EE_avg2;
    int EE_avg2_div;

    unsigned long long int YP_avg1;
    int YP_avg1_div;
    unsigned long long int YP_avg2;
    int YP_avg2_div;

    unsigned long long int ST_avg1;
    int ST_avg1_div;
    unsigned long long int ST_avg2;
    int ST_avg2_div;

    unsigned long long int RT_avg1;
    int RT_avg1_div;
    unsigned long long int RT_avg2;
    int RT_avg2_div;
};

unsigned long long int StoI(string s) // convert string to unsigned long long int
{
    unsigned long long int num = 0;
    int n = 0;

    while (s[n++] != '\0')
    {
    }
    n--;

    // Iterate till length of the string
    for (int i = 0; i < n; i++)

        // Subtract 48 from the current digit
        num = num * 10 + (s[i] - 48);

    return num;
}

// ! ******************************** OLD LOGIC

int Part1_()
{
    string check;
    int i = 0, j = 0;
    unsigned long long int avg_urb = 0, avg_sub = 0, urb_div = 0, sub_div = 0;

    ifstream inputFile("data.csv");

    if (!inputFile.is_open())
    {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    string line;
    const int ROWS = 1; // Maximum number of rows
    int row = 0;
    while (getline(inputFile, line))
    {
        if (row >= ROWS)
        {
            cout << "Maximum number of rows exceeded!" << endl;
            break;
        }

        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ','))
        {
            // cout << cell << " ";

            if (cell == "Suburbia")
                i = 1;

            if (j == 9 && i == 1)
            {
                check = cell;
                avg_sub += StoI(check);
                sub_div++;
                i = 0;
            }

            else if (j == 9)
            {
                check = cell;
                avg_urb += StoI(check);
                urb_div++;
                i = 0;
            }

            j++;
        }
        j = 0;
        // cout << endl;
    }
    inputFile.close();

    cout << "\nAnswer : \n";
    cout << avg_sub / sub_div << endl;
    cout << avg_urb / urb_div << endl;

    return 0;
}

int Part3_()
{
    int i = 0, j = 0, k = 0, swim_div = 0, no_swim_div = 0;
    unsigned long long int price_swim = 0, price_no_swim = 0, temp = 0;
    string check;

    ifstream inputFile("data.csv");

    if (!inputFile.is_open())
    {
        cout << "Failed to open file!" << endl;
        return 1;
    }
    string line;
    const int ROWS = 1; // Maximum number of rows
    int row = 0;
    while (getline(inputFile, line))
    {
        if (row >= ROWS)
        {
            cout << "Maximum number of rows exceeded!" << endl;
            break;
        }

        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ','))
        {
            // cout << cell << " ";
            if (j == 9)
                temp = StoI(cell);

            if (j == 12)
            {
                if (cell == "\"['Swimming Pool'")
                {
                    price_swim += temp;
                    // cout << cell << endl;
                    swim_div++;
                }
                else
                {
                    price_no_swim += temp;
                    no_swim_div++;
                }
            }

            j++;
        }
        j = 0;
    }
    inputFile.close();

    cout << "Answer : " << endl
         << price_no_swim / no_swim_div << endl
         << price_swim / swim_div << endl;

    return 0;
}

int Part4_()
{
    int i = 0, j = 0, good_div = 0, fair_poor_div = 0;
    unsigned long long int price_good = 0, price_fair_poor = 0, temp = 0;
    string check;

    ifstream inputFile("data.csv");

    if (!inputFile.is_open())
    {
        cout << "Failed to open file!" << endl;
        return 1;
    }
    string line;
    const int ROWS = 1; // Maximum number of rows
    int row = 0;
    while (getline(inputFile, line))
    {
        if (row >= ROWS)
        {
            cout << "Maximum number of rows exceeded!" << endl;
            break;
        }

        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ','))
        {
            // cout << cell << " ";
            if (cell == "Good")
                i = 1;
            else if (cell == "Poor" || cell == "Fair")
                i = 2;

            if (j == 9 && i == 1)
            {
                price_good += StoI(cell);
                good_div++;
                i = 0;
            }
            else if (j == 9 && i == 2)
            {
                price_fair_poor += StoI(cell);
                fair_poor_div++;
                i = 0;
            }

            j++;
        }
        j = 0;
    }
    inputFile.close();

    cout << "\nAnswer : " << endl
         << price_good / good_div << endl
         << price_fair_poor / fair_poor_div << endl
         << (price_good / good_div) - (price_fair_poor / fair_poor_div) << endl;

    return 0;
}

// ! ******************************** OLD LOGIC

void Display(string *&str, int size)
{
    for (int i = 0; i < size; i++)
        cout << str[i] << "|\n";
    cout << endl;
}

string *colSeperate(string *&fileData, int colNum, int maxRows, char delim = ',')
{
    string temp;
    string *res = new string[maxRows];
    for (int i = 0; i < maxRows; i++)
    {
        stringstream lineStream(fileData[i]);
        for (int j = 0; j < colNum; j++)
            getline(lineStream, temp, ',');
        getline(lineStream, res[i], delim);
    }
    return res;
}

int *EvalAge(string *&lineData, int maxRows)
{
    int *res = new int[maxRows];
    for (int i = 0; i < maxRows; i++)
    {
        if (lineData[i] == "New")
            res[i] = 1;
        else if (lineData[i] == "1-5 years")
            res[i] = 2;
        else if (lineData[i] == "5-10 years")
            res[i] = 3;
        else if (lineData[i] == "10+ years")
            res[i] = 4;
    }

    return res;
}

int *EvalCondition(string *&lineData, int maxRows)
{
    int *res = new int[maxRows];
    for (int i = 0; i < maxRows; i++)
    {
        if (lineData[i] == "Excellent")
            res[i] = 1;
        else if (lineData[i] == "Good")
            res[i] = 2;
        else if (lineData[i] == "Fair")
            res[i] = 3;
    }

    return res;
}

int *CountAmen(string *&lineData, int maxRows)
{
    int Count, j;
    int *res = new int[maxRows];
    for (int i = 0; i < maxRows; i++)
    {
        j, Count = 0;
        for (j = 0; lineData[i][j] != '\0'; j++)
            if (lineData[i][j] == ',')
                Count++;
        if (j != 2)
            Count++;
        res[i] = Count;
    }

    for (int i = 0; i < 5; i++)
    {
        // cout << res[i] << endl;
    }

    return res;
}

void CalMeans(int *&X, int *&Y, double &XMean, double &YMean, int size)
{
    XMean = 0, YMean = 0;
    for (int i = 0; i < size; i++)
    {
        XMean += X[i];
        YMean += Y[i];
    }
    XMean /= double(size);
    YMean /= double(size);
}

double findCorrelation(int *X, int *Y, int n)
{
    double xDiff, yDiff, cov = 0,
                         mX, mY, sX = 0, sY = 0;

    CalMeans(X, Y, mX, mY, n);

    for (int i = 0; i < n; i++)
    {
        xDiff = double(X[i]) - mX;
        yDiff = double(Y[i]) - mY;

        sX += (xDiff) * (xDiff);
        sY += (yDiff) * (yDiff);

        // todo why did we take square here for sX and sY

        cov += xDiff * yDiff;
    }

    sX = sqrt(sX / n);
    sY = sqrt(sY / n);
    cov /= (n - 1);

    return cov / (sX * sY);
}

string **Amenities_words(string *&lineData, int maxRows)
{
    string **words = new string *[maxRows];

    int count1 = 0, count2 = 0, checker = 0;

    for (int i = 0; i < maxRows; i++)
    {
        words[i] = new string[20];
    }

    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; lineData[i][j] != '\0'; j++)
        {
            if ((lineData[i][j] >= 'A' && lineData[i][j] <= 'Z') || (lineData[i][j] >= 'a' && lineData[i][j] <= 'z') || (lineData[i][j] == ' ' && (lineData[i][j + 1] >= 'A' && lineData[i][j] <= 'Z')))
            {
                words[count1][count2] += lineData[i][j];

                if (lineData[i][j + 1] == '\'')
                {
                    checker++;
                    count2++;
                }
            }
        }

        if (count2 > 0)
        {
            count1++;
            checker, count2 = 0;
        }
        else
        {
            words[count1][count2] += '\0';
            count1++;
            checker, count2 = 0;
        }
    }

    /* Displays the words
        for (int i = 0; i < count1; i++)
        {
            for (int j = 0; j < checker; j++)
            {
                cout << words[i][j] << " ";
            }
            cout << endl;
        }
    */

    return words;
}

int *string_to_int(string *&string, int size)
{
    int *res = new int[size];

    for (int i = 0; i < size; i++)
    {
        res[i] = string[i][0] - 48;
    }

    return res;
}

void Part1(string *&fileData)
{
    unsigned long long int sub = 0, urb = 0, avg1 = 0, avg2 = 0;

    dataset Pt1;

    Pt1.Area = colSeperate(fileData, 0, MAX);
    Pt1.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt1.Area[i] == "Suburbia")
        {
            sub += StoI(Pt1.price[i]);
            avg1++;
        }
        else
        {
            urb += StoI(Pt1.price[i]);
            avg2++;
        }
    }

    sub /= avg1;
    urb /= avg2;

    cout << "\nAverage Price of Suburbia Properties : " << sub << endl
         << "Average Price of Urban Properties : " << urb << endl

         << "\nConclusion : " << endl
         << "The Average Price of Suburbia Properties is sligthly more than the Average Price of Urban Properties \nBecause Suburbian Properties are high in demand Because of their Peaceful environment and modern life style." << endl;

    delete[] Pt1.price;
    delete[] Pt1.Area;
}

void Part2(string *&fileData)
{
    double correlation = 0.0;
    // string *property_age = colSeperate(fileData, 2, MAX), *num_bedrooms = colSeperate(fileData, 7, MAX);

    dataset Pt2;

    Pt2.property_age = colSeperate(fileData, 2, MAX);
    Pt2.beds = colSeperate(fileData, 7, MAX);

    int *X = EvalAge(Pt2.property_age, MAX);
    int *Y = string_to_int(Pt2.beds, MAX);

    correlation = findCorrelation(X, Y, MAX);

    cout << "\nCorrelation between Property age and Number of Bedrooms : " << (correlation) << endl;

    if (correlation >= 0)
        cout << "Weak Positive Correlation" << endl;
    else if (correlation == 0)
        cout << "No Correlation" << endl;
    else if (correlation <= -0)
        cout << "Weak Negative Correlation" << endl;

    cout << "\nConclusion : " << endl
         << "There is a slightly Negative Correlation between Property age \nand Number of Bedrooms as in the past, big families would live under one roof" << endl;

    delete[] Pt2.property_age;
    delete[] Pt2.beds;
}

void Part3(string *&fileData)
{
    unsigned long long int avg1 = 0, avg2 = 0;
    long long int avg1_div = 0, avg2_div = 0;

    //  string *Amenities = colSeperate(fileData, 12, 50000, '\0');
    // string *price = colSeperate(fileData, 9, 50000);

    dataset Pt3;

    Pt3.Amenities = colSeperate(fileData, 12, MAX, '\0');
    Pt3.price = colSeperate(fileData, 9, MAX);

    string **words = Amenities_words(Pt3.Amenities, MAX);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
        {

            if (words[i][j] == "Swimming Pool")
            {
                avg1 += StoI(Pt3.price[i]);
                avg1_div++;
                //   cout << avg1 << endl;
            }
            else
            {
                avg2 += StoI(Pt3.price[i]);
                avg2_div++;
            }
        }
    }

    avg1 /= avg1_div;
    avg2 /= avg2_div;

    cout << "\nAverage Price of Properties with Swimming Pool : " << avg1 << endl;
    cout << "Average Price of Properties without Swimming Pool : " << avg2 << endl

         << "\nConclusion : " << endl
         << "The Average Price of Properties with Swimming Pool with slightly higher than the Average Price of \nProperties without Swimming Pool Because swimming pools are an extra edition to the Property and require extra land" << endl;

    delete[] Pt3.Amenities;
    delete[] Pt3.price;
}

void Part4(string *&fileData)
{
    dataset Pt4;

    unsigned long long int avg1 = 0, avg2 = 0;
    long long int avg1_div = 0, avg2_div = 0;

    Pt4.cond = colSeperate(fileData, 4, MAX);
    Pt4.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt4.cond[i] == "Good")
        {
            avg1 += StoI(Pt4.price[i]);
            avg1_div++;
        }
        else if (Pt4.cond[i] != "Excellent")
        {
            avg2 += StoI(Pt4.price[i]);
            avg2_div++;
        }
    }

    avg1 /= avg1_div;
    avg2 /= avg2_div;

    cout << "\nAverage Price with Condition Good : " << avg1 << endl
         << "Average Price with Condition Fair or Poor : " << avg2 << endl

         << "\nConclusion : " << endl
         << "The Average Price of property with Good Condition is slightly higher than the Average Price of property with Fair or Poor Condition \nas a property with good condition comes with good amenities and a good living environment which is in demand." << endl;

    delete[] Pt4.cond;
    delete[] Pt4.price;
}

void Part5(string *&fileData)
{
    unsigned long long int apartment = 0, house = 0, condo = 0, townHouse = 0;
    long long int apartment_div = 0, house_div = 0, townHouse_div = 0, condo_div = 1;

    //   string *type = colSeperate(fileData, 1, MAX);
    //  string *Price = colSeperate(fileData, 9, MAX);

    dataset Pt5;

    Pt5.type = colSeperate(fileData, 1, MAX);
    Pt5.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt5.type[i] == "House")
        {
            house += StoI(Pt5.price[i]);
            house_div++;
        }
        else if (Pt5.type[i] == "Townhouse")
        {
            townHouse += StoI(Pt5.price[i]);
            townHouse_div++;
        }
        else if (Pt5.type[i] == "Apartment")
        {
            apartment += StoI(Pt5.price[i]);
            apartment_div++;
        }
        else if (Pt5.type[i] == "Condo")
        {
            condo += StoI(Pt5.price[i]);
            condo_div++;
        }
    }

    house = house / house_div;
    townHouse /= townHouse_div;
    apartment /= apartment_div;
    condo /= condo_div;

    cout << "\nAverage Price : " << endl
         << "\nHouse : " << house << endl
         << "TownHouse : " << townHouse << endl
         << "Apartment : " << apartment << endl
         << "Condo : " << condo << endl

         << "\nConclusion : " << endl
         << "The Average Price of a Townhouse Property is less than the Average Price of a House or an Apartment.\nThis is because a Townhouse is less in demand compared to a House or an Apartment.\nThere is almost no difference between the Average Prices of a House and an Apartment." << endl;

    delete[] Pt5.type;
    delete[] Pt5.price;
}

void Part6(string *&fileDate)
{
    //  string *bed = colSeperate(fileDate, 7, MAX), *bath = colSeperate(fileDate, 8, MAX),       *ageRange = colSeperate(fileDate, 3, MAX);
    // int lessthan5 = 0, five_ten = 0, ten_twenty = 0, twentyplus = 0;

    string num_bed = "3", num_bath = "2";

    dataset Pt6;

    Pt6.beds = colSeperate(fileDate, 7, MAX);
    Pt6.baths = colSeperate(fileDate, 8, MAX);
    Pt6.age_Range = colSeperate(fileDate, 3, MAX);

    Pt6.lessthan5 = 0;
    Pt6.five_10 = 0;
    Pt6.ten_20 = 0;
    Pt6.twentyplus = 0;

    double average = 0.0;

    // ? User InPut
    /*
        cout << "Enter the Number of Bedrooms : ";
        cin >> num_bed;

        cout << "Enter the Number of Bathrooms : ";
        cin >> num_bath;
    */

    for (int i = 0; i < MAX; i++)
    {
        if (Pt6.beds[i] == num_bed && Pt6.baths[i] == num_bath)
        {
            if (Pt6.age_Range[i] == "Less than 5 years old")
                Pt6.lessthan5++;
            else if (Pt6.age_Range[i] == "5-10 years old")
                Pt6.five_10++;
            else if (Pt6.age_Range[i] == "10-20 years old")
                Pt6.ten_20++;
            else if (Pt6.age_Range[i] == "20+ years old")
                Pt6.twentyplus++;
        }
    }

    cout << "\nLess than 5 years old : " << Pt6.lessthan5 << "\n5-10 years old : " << Pt6.five_10 << "\n10-20 years old : " << Pt6.ten_20 << "\n20+ years old : " << Pt6.twentyplus << endl
         << endl;

    if (Pt6.lessthan5 >= Pt6.five_10)
    {
        if (Pt6.lessthan5 >= Pt6.ten_20)
        {
            if (Pt6.lessthan5 >= Pt6.twentyplus)
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : Less than 5 years old" << endl
                     << "It was Repeated " << Pt6.lessthan5 << " times " << endl;
            }
            else
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 20+ years old" << endl
                     << "It was Repeated " << Pt6.twentyplus << " times " << endl;
            }
        }
        else
        {
            if (Pt6.ten_20 >= Pt6.twentyplus)
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 10-20 years old" << endl
                     << "It was Repeated " << Pt6.ten_20 << " times " << endl;
            }
            else
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 20+ years old" << endl
                     << "It was Repeated " << Pt6.twentyplus << " times " << endl;
            }
        }
    }
    else
    {

        if (Pt6.five_10 >= Pt6.ten_20)
        {
            if (Pt6.five_10 >= Pt6.twentyplus)
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 5-10 years old" << endl
                     << "It was Repeated " << Pt6.five_10 << " times " << endl;
            }
            else
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 20+ years old" << endl
                     << "It was Repeated " << Pt6.twentyplus << " times " << endl;
            }
        }
        else
        {
            if (Pt6.ten_20 >= Pt6.twentyplus)
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 10-20 years old" << endl
                     << "It was Repeated " << Pt6.ten_20 << " times " << endl;
            }
            else
            {
                cout << "Most Common Property Range with " << num_bed << " beds and " << num_bath << " bathrooms : 20+ years old" << endl
                     << "It was Repeated " << Pt6.twentyplus << " times " << endl;
            }
        }
    }

    cout << "\nConclusion : " << endl
         << "The Most Common Property Age Range is 20+ years old because the families in the past \nhad alot of members who needed multiple bedrooms and bathrooms." << endl;

    delete[] Pt6.beds;
    delete[] Pt6.baths;
    delete[] Pt6.age_Range;
}

void Part7_(string *&fileData)
{
    double correlation = 0.0;
    int rows = 0;
    int *swim, *gard, *garg, *dec, *fire, *gym, *bal, *hardw;
    int *bath_num = new int[MAX];

    dataset Pt7;
    Pt7.Balcony = new int[MAX], Pt7.Deck = new int[MAX], Pt7.FirePlace = new int[MAX], Pt7.Garden = new int[MAX],
    Pt7.Garage = new int[MAX], Pt7.Gym = new int[MAX], Pt7.Hardwood = new int[MAX], Pt7.swimPool = new int[MAX];

    string *bathroom = colSeperate(fileData, 8, MAX);
    string *Amenities = colSeperate(fileData, 12, MAX, '\0');
    string **words = Amenities_words(Amenities, MAX);

    // *initializing arrays
    for (int i = 0; i < MAX; i++)
    {
        Pt7.Balcony[i] = {0};
        Pt7.Deck[i] = {0};
        Pt7.FirePlace[i] = {0};
        Pt7.Garage[i] = {0};
        Pt7.Garden[i] = {0};
        Pt7.Gym[i] = {0};
        Pt7.Hardwood[i] = {0};
        Pt7.swimPool[i] = {0};
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (words[i][j] == "Garden")
                Pt7.Garden[i]++;
            else if (words[i][j] == "Swimming Pool")
                Pt7.swimPool[i]++;
            else if (words[i][j] == "Gym")
                Pt7.Gym[i]++;
            else if (words[i][j] == "Hardwood Floors")
                Pt7.Hardwood[i]++;
            else if (words[i][j] == "Fireplace")
                Pt7.FirePlace[i]++;
            else if (words[i][j] == "Balcony")
                Pt7.Balcony[i]++;
            else if (words[i][j] == "Deck")
                Pt7.Deck[i]++;
            else if (words[i][j] == "Garage")
                Pt7.Garage[i]++;
        }
    }

    cout << "Enter How Many Rows Do you want to Compare : ";
    cin >> rows;

    cout << "Balcony "
         << "Garage "
         << "Swim_Pool "
         << "Deck "
         << "FirePlace "
         << "Garden "
         << "HardWood "
         << "Gym " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << Pt7.Balcony[i] << "          " << Pt7.Garage[i] << "      "
             << Pt7.swimPool[i] << "       " << Pt7.Deck[i] << "       "
             << Pt7.FirePlace[i] << "        " << Pt7.Garden[i] << "       "
             << Pt7.Hardwood[i] << "     " << Pt7.Gym[i] << "      " << endl;
    }

    for (int i = 0; i < MAX; i++)
    {
        bath_num[i] = StoI(bathroom[i]);
    }

    correlation = findCorrelation(bath_num, Pt7.swimPool, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Balcony, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Deck, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Garage, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Garden, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Gym, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.FirePlace, MAX);
    cout << correlation << endl;

    correlation = findCorrelation(bath_num, Pt7.Hardwood, MAX);
    cout << correlation << endl;

    delete[] Pt7.Balcony;
    delete[] Pt7.Deck;
    delete[] Pt7.FirePlace;
    delete[] Pt7.Garage;
    delete[] Pt7.Garden;
    delete[] Pt7.Gym;
    delete[] Pt7.Hardwood;
    delete[] Pt7.swimPool;
}

// * with swim and gym only
void Part7(string *&fileData)
{
    double correlation = 0.0;
    int rows = 0;
    int *swim, *gym;
    int *bath_num = new int[MAX];

    dataset Pt7;
    Pt7.Gym = new int[MAX], Pt7.swimPool = new int[MAX];

    string *bathroom = colSeperate(fileData, 8, MAX);
    string *Amenities = colSeperate(fileData, 12, MAX, '\0');
    string **words = Amenities_words(Amenities, MAX);

    // *initializing arrays
    for (int i = 0; i < MAX; i++)
    {
        Pt7.Gym[i] = 0;
        Pt7.swimPool[i] = 0;
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (words[i][j] == "Swimming Pool")
                Pt7.swimPool[i]++;
            else if (words[i][j] == "Gym")
                Pt7.Gym[i]++;
        }
    }

    cout << "\nEnter How Many Rows Do you want to Compare : ";
    cin >> rows;

    cout << "\nComparing Rows \n----------------------------\n"
         << "  Swim Pool "
         << "Gym " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << ".    " << Pt7.swimPool[i] << "      " << Pt7.Gym[i] << "      " << endl;
    }

    cout << endl;

    for (int i = 0; i < MAX; i++)
    {
        bath_num[i] = StoI(bathroom[i]);
    }

    correlation = findCorrelation(bath_num, Pt7.swimPool, MAX);
    cout << "Correlation with Swimming Pool : " << correlation << endl
         << "Weak Positive Correlation " << endl;

    correlation = findCorrelation(bath_num, Pt7.Gym, MAX);
    cout << "Correlation with Gym : " << correlation << endl
         << "Very Weak Negative Correlation " << endl;

    cout << "\nConclusion : " << endl
         << "There is a Weak Positive Correlation between Properties with Swimming pools and Number of Bathrooms \nas where there are swimming pools, there usually are bathrooms too for people go shower in or change their outfits." << endl
         << "\nThere is a Very Weak Positive Correlation between Properties with Gyms and Number of Bathrooms \nas where there are gyms, there usually are some bathrooms there too for people go shower in or change their outfits." << endl;

    delete[] Pt7.Gym;
    delete[] Pt7.swimPool;
}

void Part8(string *&fileData)
{

    unsigned long long int houstin = 0, san_d = 0, los_Ang = 0, san_j = 0, pheonix = 0, phila = 0, nyk = 0, chic = 0,
                           dallas = 0, san_a = 0, avg = 0;
    long long int houstin_div = 0, san_d_div = 0, los_Ang_div = 0, san_j_div = 0, pheonix_div = 0, phila_div = 0, nyk_div = 0, chic_div = 0,
                  dallas_div = 0, san_a_div = 0;

    //   string *city = colSeperate(fileData, 5, MAX);
    //  string *price = colSeperate(fileData, 9, MAX);

    dataset Pt8;

    Pt8.city = colSeperate(fileData, 5, MAX);
    Pt8.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt8.city[i] == "Houston")
        {
            houstin += StoI(Pt8.price[i]);
            houstin_div++;
        }
        else if (Pt8.city[i] == "San Diego")
        {
            san_d += StoI(Pt8.price[i]);
            san_d_div++;
        }
        else if (Pt8.city[i] == "Los Angeles")
        {
            los_Ang += StoI(Pt8.price[i]);
            los_Ang_div++;
        }
        else if (Pt8.city[i] == "San Jose")
        {
            san_j += StoI(Pt8.price[i]);
            san_j_div++;
        }
        else if (Pt8.city[i] == "Phoenix")
        {
            pheonix += StoI(Pt8.price[i]);
            pheonix_div++;
        }
        else if (Pt8.city[i] == "San Antonio")
        {
            san_a += StoI(Pt8.price[i]);
            san_a_div++;
        }
        else if (Pt8.city[i] == "Philadelphia")
        {
            phila += StoI(Pt8.price[i]);
            phila_div++;
        }
        else if (Pt8.city[i] == "Chicago")
        {
            chic += StoI(Pt8.price[i]);
            chic_div++;
        }
        else if (Pt8.city[i] == "Dallas")
        {
            dallas += StoI(Pt8.price[i]);
            dallas_div++;
        }
        else if (Pt8.city[i] == "New York")
        {
            nyk += StoI(Pt8.price[i]);
            nyk_div++;
        }
        else
            cout << "\nError : Unknown city\n";
    }

    houstin /= houstin_div;
    san_a /= san_a_div;
    san_d /= san_d_div;
    san_j /= san_j_div;
    phila /= phila_div;
    pheonix /= pheonix_div;
    los_Ang /= los_Ang_div;
    nyk /= nyk_div;
    chic /= chic_div;
    dallas /= dallas_div;

    avg = (houstin + san_a + san_d + san_j + phila + pheonix + los_Ang + nyk + chic + dallas) / 10;

    cout << "\nAverage Price of Properties in 10 Cities : " << avg << endl

         << "\nConclusion : " << endl
         << "As Cities are modern and provide a wide variety of activities and jobs, the properties are expensive." << endl;

    delete[] Pt8.city;
    delete[] Pt8.price;
}

void Part9(string *&fileData)
{
    long long int div1 = 0, div2 = 0;
    double avg1 = 0.0, avg2 = 0.0;

    string bed1 = "2", bath1 = "2", bed2 = "3", bath2 = "2";

    // string *beds = colSeperate(fileData, 7, 50000), *baths = colSeperate(fileData, 8, 50000),   *price = colSeperate(fileData, 9, 50000);

    dataset Pt9;

    Pt9.beds = colSeperate(fileData, 7, MAX);
    Pt9.baths = colSeperate(fileData, 8, MAX);
    Pt9.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt9.beds[i] == bed1 && Pt9.baths[i] == bath1)
        {
            div1++;
            avg1 += StoI(Pt9.price[i]);
        }
        else if (Pt9.beds[i] == bed2 && Pt9.baths[i] == bath2)
        {
            div2++;
            avg2 += StoI(Pt9.price[i]);
        }
    }

    avg1 /= div1;
    avg2 /= div2;

    cout << "\nAverage Price of 2 bedrooms and 2 bathrooms : " << avg1 << endl
         << "Average Price of 3 bedrooms and 2 bathrooms : " << avg2 << endl

         << "\nConclsion : " << endl
         << "There is a Significant Difference between the average price of Properties with \n2 bedrooms and bathrooms and Average price of properties with 3 bedrooms and 2 bathrooms." << endl
         << endl
         << "This is because Properties with 2 bedrooms and bathrooms are more in demand by \ncitizens as such properties are compact and easy to manage." << endl;

    delete[] Pt9.beds;
    delete[] Pt9.baths;
    delete[] Pt9.price;
}

void Part10(string *&fileData)
{
    unsigned long long apart = 0, house = 0, town = 0, avg1 = 0, avg2 = 0, avg3 = 0;

    dataset Pt10;

    Pt10.property = colSeperate(fileData, 1, MAX);
    Pt10.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt10.property[i] == "House")
        {
            house += StoI(Pt10.price[i]);
            avg1++;
        }
        else if (Pt10.property[i] == "Townhouse")
        {
            town += StoI(Pt10.price[i]);
            avg2++;
        }
        else if (Pt10.property[i] == "Apartment")
        {
            apart += StoI(Pt10.price[i]);
            avg3++;
        }
    }

    house /= avg1;
    town /= avg2;
    apart /= avg3;

    cout << "\nAverage Price per square ft of House : " << house << endl
         << "Average Price per square ft of Township : " << town << endl
         << "Average Price per square ft of Apartment : " << apart << endl

         << "\nConclusion : " << endl
         << "There is a Significant difference between the Average Price of a Township and the Average Price of a House or Apartment" << endl
         << "\nThe Average Price of a Townhouse Property is less than the Average Price of a House or an Apartment.\nThis is because a Townhouse is less in demand compared to a House or an Apartment.\nThere is almost no difference between the Average Prices of a House and an Apartment." << endl;

    delete[] Pt10.property;
    delete[] Pt10.price;
}

void Part11(string *&fileData)
{
    unsigned long long int los = 0, dallas = 0, avg1 = 0, avg2 = 0;

    dataset Pt11;

    Pt11.city = colSeperate(fileData, 5, MAX);
    Pt11.price = colSeperate(fileData, 9, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt11.city[i] == "Los Angeles")
        {
            los += StoI(Pt11.price[i]);
            avg1++;
        }
        else if (Pt11.city[i] == "Dallas")
        {
            dallas += StoI(Pt11.price[i]);
            avg2++;
        }
    }

    los /= avg1;
    dallas /= avg2;

    cout << "Average Price of Properties in the Highest Income City : " << los << endl
         << "Average Price of Properties in the Highest Populated City : " << dallas << endl

         << "\nConclusion : " << endl
         << "The Average Price of Properties in the Highest Income City is Higher than the \nAverage Price of Properties in the Highest Populated City as Properties in Cities with high \nincome are targeted towards the Elite class who can easily afford them.\n";

    delete[] Pt11.city;
    delete[] Pt11.price;
}

void Part12(string *&fileData)
{
    double correlation = 0.0;

    dataset Pt12;

    Pt12.Amenities = colSeperate(fileData, 12, MAX, '\0');
    Pt12.Age = colSeperate(fileData, 2, MAX);

    // string *Age = colSeperate(fileData, 2, MAX);
    // string *Amenities = colSeperate(fileData, 12, MAX, '\0');

    int *X = EvalAge(Pt12.Age, MAX);
    int *Y = CountAmen(Pt12.Amenities, MAX);

    correlation = findCorrelation(X, Y, MAX);

    cout << "\nCorrelation : " << (correlation) << endl;

    if (correlation >= 0)
        cout << "Weak Positive Correlation" << endl;
    else if (correlation == 0)
        cout << "No Correlation" << endl;
    else if (correlation <= 0)
        cout << "Weak Negative Correlation" << endl;

    cout << "\nConclusion : " << endl
         << "There is a slight negative correlation between Property age and Number of Amenities in the Property" << endl
         << "This is because in the past, having multiple amenities in a Property was a luxury which only the elite class could enjoy." << endl;

    delete[] Pt12.Amenities;
    delete[] Pt12.Age;
}

void Part13(string *&fileData)
{
    dataset d, FWC, EE, YP, ST, RT;
    string *ageRange = colSeperate(fileData, 3, MAX);
    string *demo = colSeperate(fileData, 6, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (demo[i] == "Families with children")
        {
            if (ageRange[i] == "20+ years old")
                FWC.twentyplus++;
            else if (ageRange[i] == "Less than 5 years old")
                FWC.lessthan5++;
            else if (ageRange[i] == "5-10 years old")
                FWC.five_10++;
            else if (ageRange[i] == "10-20 years old")
                FWC.ten_20++;
        }
        else if (demo[i] == "Ethnic enclaves")
        {
            if (ageRange[i] == "20+ years old")
                EE.twentyplus++;
            else if (ageRange[i] == "Less than 5 years old")
                EE.lessthan5++;
            else if (ageRange[i] == "5-10 years old")
                EE.five_10++;
            else if (ageRange[i] == "10-20 years old")
                EE.ten_20++;
        }
        else if (demo[i] == "Young professionals")
        {
            if (ageRange[i] == "20+ years old")
                YP.twentyplus++;
            else if (ageRange[i] == "Less than 5 years old")
                YP.lessthan5++;
            else if (ageRange[i] == "5-10 years old")
                YP.five_10++;
            else if (ageRange[i] == "10-20 years old")
                YP.ten_20++;
        }
        else if (demo[i] == "Students")
        {
            if (ageRange[i] == "20+ years old")
                ST.twentyplus++;
            else if (ageRange[i] == "Less than 5 years old")
                ST.lessthan5++;
            else if (ageRange[i] == "5-10 years old")
                ST.five_10++;
            else if (ageRange[i] == "10-20 years old")
                ST.ten_20++;
        }
        else if (demo[i] == "Retirees")
        {
            if (ageRange[i] == "20+ years old")
                RT.twentyplus++;
            if (ageRange[i] == "Less than 5 years old")
                RT.lessthan5++;
            else if (ageRange[i] == "5-10 years old")
                RT.five_10++;
            else if (ageRange[i] == "10-20 years old")
                RT.ten_20++;
        }
    }

    cout << "\n\nLess than 5 years old : " << FWC.lessthan5 << "\n5-10 years old : " << FWC.five_10 << "\n10-20 years old : " << FWC.ten_20 << "\n20+ years old : " << FWC.twentyplus << endl;
    cout << "\nMost Common Property Range for Families with Children : ";
    if (FWC.twentyplus > FWC.ten_20)
    {
        if (FWC.twentyplus > FWC.five_10)
        {
            if (FWC.twentyplus > FWC.lessthan5)
                cout << "20+ years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (FWC.five_10 > FWC.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }
    else
    {
        if (FWC.ten_20 > FWC.five_10)
        {
            if (FWC.ten_20 > FWC.lessthan5)
                cout << "10-20 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (FWC.five_10 > FWC.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }

    cout << "\n\nLess than 5 years old : " << EE.lessthan5 << "\n5-10 years old : " << EE.five_10 << "\n10-20 years old : " << EE.ten_20 << "\n20+ years old : " << EE.twentyplus << endl;

    cout << "\nMost Common Property Range for Ethnic enclaves : ";
    if (EE.twentyplus > EE.ten_20)
    {
        if (EE.twentyplus > EE.five_10)
        {
            if (EE.twentyplus > EE.lessthan5)
                cout << "20+ years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (EE.five_10 > EE.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }
    else
    {
        if (EE.ten_20 > EE.five_10)
        {
            if (EE.ten_20 > EE.lessthan5)
                cout << "10-20 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (EE.five_10 > EE.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }

    cout << "\n\nLess than 5 years old : " << YP.lessthan5 << "\n5-10 years old : " << YP.five_10 << "\n10-20 years old : " << YP.ten_20 << "\n20+ years old : " << YP.twentyplus << endl;

    cout << "\nMost Common Property Range for Young Professors : ";
    if (YP.twentyplus > YP.ten_20)
    {
        if (YP.twentyplus > YP.five_10)
        {
            if (YP.twentyplus > YP.lessthan5)
                cout << "20+ years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (YP.five_10 > YP.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }
    else
    {
        if (YP.ten_20 > YP.five_10)
        {
            if (YP.ten_20 > YP.lessthan5)
                cout << "10-20 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (YP.five_10 > YP.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }

    cout << "\n\nLess than 5 years old : " << ST.lessthan5 << "\n5-10 years old : " << ST.five_10 << "\n10-20 years old : " << ST.ten_20 << "\n20+ years old : " << ST.twentyplus << endl;

    cout << "\nMost Common Property Range for Students : ";
    if (ST.twentyplus > ST.ten_20)
    {
        if (ST.twentyplus > ST.five_10)
        {
            if (ST.twentyplus > ST.lessthan5)
                cout << "20+ years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (ST.five_10 > ST.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }
    else
    {
        if (ST.ten_20 > ST.five_10)
        {
            if (ST.ten_20 > ST.lessthan5)
                cout << "10-20 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (ST.five_10 > ST.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }

    cout << "\n\nLess than 5 years old : " << RT.lessthan5 << "\n5-10 years old : " << RT.five_10 << "\n10-20 years old : " << RT.ten_20 << "\n20+ years old : " << RT.twentyplus << endl;

    cout << "\nMost Common Property Range for Retirees : ";
    if (RT.twentyplus > RT.ten_20)
    {
        if (RT.twentyplus > RT.five_10)
        {
            if (RT.twentyplus > RT.lessthan5)
                cout << "20+ years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (RT.five_10 > RT.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }
    else
    {
        if (RT.ten_20 > RT.five_10)
        {
            if (RT.ten_20 > RT.lessthan5)
                cout << "10-20 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
        else
        {
            if (RT.five_10 > RT.lessthan5)
                cout << "5-10 years old\n";
            else
                cout << "Less than 5 years old\n";
        }
    }

    cout << "\nConclusion : " << endl
         << "\nMost Common Property Age Range for Families with Children is 10-20 years old because families require a house that doesnt cost too much \nbut is in Good condition as well." << endl
         << "\nMost Common Property Age Range for Ethnic Enclaves is 5-10 years old because ethnic enclaves require a house in Great condition in \nGood neighborhoods." << endl
         << "\nMost Common Property Age Range for Young Professors is less than 5 years old because Young Professors have alot of money which enables them \nto buy houses in Excellent conditions" << endl
         << "\nMost Common Property Age Range for Students is 10-20 years old because Students don't have enough money to purchase or rent houses in the \nbest of conditions. So, they opt for old houses." << endl
         << "\nMost Common Property Age Range for Retirees is 10-20 years old because Retirees don't require extravagent houses nor do they want to \nmove from their old houses to a new one." << endl;
}

void Part14(string *&fileData)
{
    double correlation1 = 0.0, correlation2 = 0.0;

    dataset Pt14;

    Pt14.cond = colSeperate(fileData, 4, MAX);
    Pt14.Amenities = colSeperate(fileData, 12, MAX, '\0');

    // string *Condition = colSeperate(fileData, 4, MAX);
    // string *Amenities = colSeperate(fileData, 12, MAX, '\0');

    string **words = Amenities_words(Pt14.Amenities, MAX);

    Pt14.swimPool = new int[MAX], Pt14.Gym = new int[MAX];

    for (int i = 0; i < MAX; i++)
    {
        Pt14.swimPool[i] = 0;
        Pt14.Gym[i] = 0;
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (words[i][j] == "Swimming Pool")
                Pt14.swimPool[i]++;

            else if (words[i][j] == "Gym")
                Pt14.Gym[i]++;
        }
    }

    int *X = EvalCondition(Pt14.cond, MAX);

    correlation1 = findCorrelation(X, Pt14.swimPool, MAX);
    correlation2 = findCorrelation(X, Pt14.Gym, MAX);

    cout << "\nCorrelation with Swimming Pool : " << (correlation1) << endl;

    if (correlation1 >= 0)
        cout << "Weak Positive Correlation" << endl;
    else if (correlation1 == 0)
        cout << "No Correlation" << endl;
    else if (correlation1 <= 0)
        cout << "Weak Negative Correlation" << endl;

    cout << "\nCorrelation with Gym : " << (correlation2) << endl;

    if (correlation2 >= 0)
        cout << "Weak Positive Correlation" << endl;
    else if (correlation2 == 0)
        cout << "No Correlation" << endl;
    else if (correlation2 <= 0)
        cout << "Weak Negative Correlation" << endl;

    cout << "\nConclusion : " << endl
         << "\nThere is a Weak Negative Correlation between Properties with a Swimming Pool and Property Condition because with the presence of a \nswimming pool, more people come to enjoy the swimming pool and exploite it" << endl
         << "\nThere is a Weak Negative Correlation between Properties with a Gym and Property Condition because with the presence of a \ngym, more people come to enjoy the gym and exploite it" << endl;

    delete[] Pt14.Amenities;
    delete[] Pt14.cond;
    delete[] words;
}

void Part15(string *&fileData)
{
    // string *baths = colSeperate(fileData, 8, 50000),*price = colSeperate(fileData, 9, 50000),*demo = colSeperate(fileData, 6, 50000);

    string bath = "1";

    dataset Pt15;

    Pt15.baths = colSeperate(fileData, 8, MAX);
    Pt15.price = colSeperate(fileData, 9, MAX);
    Pt15.Demo = colSeperate(fileData, 6, MAX);

    Pt15.FWC_avg1 = 0;
    Pt15.FWC_avg1_div = 0;
    Pt15.FWC_avg2 = 0;
    Pt15.FWC_avg2_div = 0;

    Pt15.EE_avg1 = 0;
    Pt15.EE_avg1_div = 0;
    Pt15.EE_avg2 = 0;
    Pt15.EE_avg2_div = 0;

    Pt15.YP_avg1 = 0;
    Pt15.YP_avg1_div = 0;
    Pt15.YP_avg2 = 0;
    Pt15.YP_avg2_div = 0;

    Pt15.ST_avg1 = 0;
    Pt15.ST_avg1_div = 0;
    Pt15.ST_avg2 = 0;
    Pt15.ST_avg2_div = 0;

    Pt15.RT_avg1 = 0;
    Pt15.RT_avg1_div = 0;
    Pt15.RT_avg2 = 0;
    Pt15.RT_avg2_div = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (Pt15.Demo[i] == "Families with children")
        {
            if (Pt15.baths[i] == bath)
            {
                Pt15.FWC_avg1 += StoI(Pt15.price[i]);
                Pt15.FWC_avg1_div++;
            }
            else
            {
                Pt15.FWC_avg2 += StoI(Pt15.price[i]);
                Pt15.FWC_avg2_div++;
            }
        }
        else if (Pt15.Demo[i] == "Ethnic enclaves")
        {
            if (Pt15.baths[i] == bath)
            {
                Pt15.EE_avg1 += StoI(Pt15.price[i]);
                Pt15.EE_avg1_div++;
            }
            else
            {
                Pt15.EE_avg2 += StoI(Pt15.price[i]);
                Pt15.EE_avg2_div++;
            }
        }
        else if (Pt15.Demo[i] == "Young professionals")
        {
            if (Pt15.baths[i] == bath)
            {
                Pt15.YP_avg1 += StoI(Pt15.price[i]);
                Pt15.YP_avg1_div++;
            }
            else
            {
                Pt15.YP_avg2 += StoI(Pt15.price[i]);
                Pt15.YP_avg2_div++;
            }
        }
        else if (Pt15.Demo[i] == "Students")
        {
            if (Pt15.baths[i] == bath)
            {
                Pt15.ST_avg1 += StoI(Pt15.price[i]);
                Pt15.ST_avg1_div++;
            }
            else
            {
                Pt15.ST_avg2 += StoI(Pt15.price[i]);
                Pt15.ST_avg2_div++;
            }
        }
        else if (Pt15.Demo[i] == "Retirees")
        {
            if (Pt15.baths[i] == bath)
            {
                Pt15.RT_avg1 += StoI(Pt15.price[i]);
                Pt15.RT_avg1_div++;
            }
            else
            {
                Pt15.RT_avg2 += StoI(Pt15.price[i]);
                Pt15.RT_avg2_div++;
            }
        }
    }

    Pt15.FWC_avg1 /= Pt15.FWC_avg1_div;
    Pt15.FWC_avg2 /= Pt15.FWC_avg2_div;

    Pt15.EE_avg1 /= Pt15.EE_avg1_div;
    Pt15.EE_avg2 /= Pt15.EE_avg2_div;

    Pt15.YP_avg1 /= Pt15.YP_avg1_div;
    Pt15.YP_avg2 /= Pt15.YP_avg2_div;

    Pt15.ST_avg1 /= Pt15.ST_avg1_div;
    Pt15.ST_avg2 /= Pt15.ST_avg2_div;

    Pt15.RT_avg1 /= Pt15.RT_avg1_div;
    Pt15.RT_avg2 /= Pt15.RT_avg2_div;

    cout << "\nAverage Price of Properties with 1 Bathroom for Families with Children : " << Pt15.FWC_avg1 << endl
         << "Average Price of Properties with Multiple Bathrooms for Families with Children : " << Pt15.FWC_avg2 << endl
         << endl
         << "Average Price of Properties with 1 Bathroom for Ethenic Enclaves : " << Pt15.EE_avg1 << endl
         << "Average Price of Properties with Multiple Bathrooms for Ethenic Enclaves : " << Pt15.EE_avg2 << endl
         << endl
         << "Average Price of Properties with 1 Bathroom for Students : " << Pt15.ST_avg1 << endl
         << "Average Price of Properties with Multiple Bathrooms for Students : " << Pt15.ST_avg2 << endl
         << endl
         << "Average Price of Properties with 1 Bathroom for Young Professors : " << Pt15.YP_avg1 << endl
         << "Average Price of Properties with Multiple Bathrooms for Young Professors : " << Pt15.YP_avg2 << endl
         << endl
         << "Average Price of Properties with 1 Bathroom for Retirees : " << Pt15.RT_avg1 << endl
         << "Average Price of Properties with Multiple Bathrooms for Retirees : " << Pt15.RT_avg2 << endl
         << endl

         << "\nConclusion : " << endl
         << "\nThe Average Price of Properties with 1 Bathroom is less than the Average Price of Properties with Multiple \nBathrooms for Families with Children as such families require Multiple bathrooms because of the number of family members." << endl
         << "\nThe Average Price of Properties with 1 Bathroom is less than the Average Price of Properties with Multiple \nBathrooms for Ethnic Enclaves as they live in high concentrated areas, so they require multiple bathrooms because of their high numbers." << endl
         << "\nThe Average Price of Properties with 1 Bathroom is almost the same as the Average Price of Properties with Multiple \nBathrooms for Students as they usually live alone or in pairs or in groups. So depending on how many live together, they require one or \nmore bathrooms." << endl
         << "\nThe Average Price of Properties with 1 Bathroom is less than the Average Price of Properties with Multiple \nBathrooms for Young Professors as they usually have enough money to purchase big houses with multiple bathrooms." << endl
         << "\nThe Average Price of Properties with 1 Bathroom is almost the same as the Average Price of Properties with Multiple \nBathrooms for retirees as they usually either live in pair where they will require 1 bathroom or live in groups and require multiple bathrooms." << endl;

    delete[] Pt15.baths;
    delete[] Pt15.price;
    delete[] Pt15.Demo;
}

void Part16(string *&fileData)
{
    unsigned long long int Sub = 0, West = 0, East = 0, West_East = 0, avg1 = 0, avg2 = 0, avg3 = 0, avg4 = 0;

    dataset Pt16;

    Pt16.Amenities = colSeperate(fileData, 12, MAX, '\0');
    Pt16.Area = colSeperate(fileData, 0, MAX);

    int *Y = CountAmen(Pt16.Amenities, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt16.Area[i] == "Suburbia")
        {
            Sub += Y[i];
            avg1++;
        }
        else if (Pt16.Area[i] == "Westside")
        {
            West += Y[i];
            avg2++;

            West_East += Y[i];
            avg4++;
        }
        else if (Pt16.Area[i] == "Eastside")
        {
            East += Y[i];
            avg3++;

            West_East += Y[i];
            avg4++;
        }
    }

    cout << "\nTotal Number of Amenities in Suburbia Properties : " << Sub << endl
         << "Total Number of Amenities in Westside Properties : " << West << endl
         << "Total Number of Amenities in Eastside Properties : " << East << endl
         << "Total Number of Amenities in Westside and Eastside Properties : " << West_East << endl;

    Sub /= avg1;
    West /= avg2;
    East /= avg3;
    West_East /= avg4;

    cout << "\nAverage Number of Amenities in Suburbia Properties : " << Sub << endl
         << "Average Number of Amenities in Westside Properties : " << West << endl
         << "Average Number of Amenities in Eastside Properties : " << East << endl
         << "Average Number of Amenities in Westside and Eastside Properties : " << West_East << endl
         << endl;

    cout << "\nConclusion : " << endl
         << "\nNumber of Amenities in Suburbia Properties are less than Westside and Eastside Properties. This is because Westside and Eastside \nproperties are situated in a more modern neighborhood which inceases the odds of more amenities per property and has more variety of Amenities.  " << endl;

    delete[] Pt16.Amenities;
    delete[] Pt16.Area;
}

void Part17(string *&fileData)
{
    unsigned long long int gard = 0, deck = 0, fire = 0, gar = 0, Hardwood = 0, bal = 0, gym = 0, swim = 0,
                           avg_gard = 0, avg_deck = 0, avg_fire = 0, avg_gar = 0, avg_Hardwood = 0, avg_bal = 0,
                           avg_gym = 0, avg_swim = 0,
                           wo_gard = 0, wo_deck = 0, wo_fire = 0, wo_gar = 0, wo_Hardwood = 0, wo_bal = 0, wo_gym = 0, wo_swim = 0,
                           wo_avg_gard = 0, wo_avg_deck = 0, wo_avg_fire = 0, wo_avg_gar = 0, wo_avg_Hardwood = 0, wo_avg_bal = 0,
                           wo_avg_gym = 0, wo_avg_swim = 0;

    dataset Pt17;

    Pt17.Amenities = colSeperate(fileData, 12, MAX, '\0');
    Pt17.Demo = colSeperate(fileData, 6, MAX);
    Pt17.price = colSeperate(fileData, 9, MAX);

    string **words = Amenities_words(fileData, MAX);

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Garden")
                {
                    gard += StoI(Pt17.price[i]);
                    avg_gard++;
                }
                else
                {
                    wo_gard += StoI(Pt17.price[i]);
                    wo_avg_gard++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Garage")
                {
                    gar += StoI(Pt17.price[i]);
                    avg_gar++;
                }
                else
                {
                    wo_gar += StoI(Pt17.price[i]);
                    wo_avg_gar++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Deck")
                {
                    deck += StoI(Pt17.price[i]);
                    avg_deck++;
                }
                else
                {
                    wo_deck += StoI(Pt17.price[i]);
                    wo_avg_deck++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Fireplace")
                {
                    fire += StoI(Pt17.price[i]);
                    avg_fire++;
                }
                else
                {
                    wo_fire += StoI(Pt17.price[i]);
                    wo_avg_fire++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Gym")
                {
                    gym += StoI(Pt17.price[i]);
                    avg_gym++;
                }
                else
                {
                    wo_gym += StoI(Pt17.price[i]);
                    wo_avg_gym++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Hardwood Floors")
                {
                    Hardwood += StoI(Pt17.price[i]);
                    avg_Hardwood++;
                }
                else
                {
                    wo_Hardwood += StoI(Pt17.price[i]);
                    wo_avg_Hardwood++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Balcony")
                {
                    bal += StoI(Pt17.price[i]);
                    avg_bal++;
                }
                else
                {
                    wo_bal += StoI(Pt17.price[i]);
                    wo_avg_bal++;
                }
            }
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        if (Pt17.Demo[i] == "Families with children")
        {
            for (int j = 0; j < 20; j++)
            {
                if (words[i][j] == "Swimming Pool")
                {
                    swim += StoI(Pt17.price[i]);
                    avg_swim++;
                }
                else
                {
                    wo_swim += StoI(Pt17.price[i]);
                    wo_avg_swim++;
                }
            }
        }
    }

    swim /= avg_swim;
    wo_swim /= wo_avg_swim;

    gar /= avg_gar;
    wo_gar /= wo_avg_gar;

    gard /= avg_gard;
    wo_gard /= wo_avg_gard;

    gym /= avg_gym;
    wo_gym /= wo_avg_gym;

    fire /= avg_fire;
    wo_fire /= wo_avg_fire;

    Hardwood /= avg_Hardwood;
    wo_Hardwood /= wo_avg_Hardwood;

    bal /= avg_bal;
    wo_bal /= wo_avg_bal;

    deck /= avg_deck;
    wo_deck /= wo_avg_deck;

    cout << "\nAverage Price of Property with Swimming Pool : " << swim << endl
         << "Average Price of Property without Swimming Pool : " << wo_swim << endl
         << "\nAverage Price of Property with Garage : " << gar << endl
         << "Average Price of Property without Garage : " << wo_gar << endl
         << "\nAverage Price of Property with Gym : " << gym << endl
         << "Average Price of Property without Gym : " << wo_gym << endl
         << "\nAverage Price of Property with Garden : " << gard << endl
         << "Average Price of Property without Garden : " << wo_gard << endl
         << "\nAverage Price of Property with Balcony : " << bal << endl
         << "Average Price of Property without Balcony : " << wo_bal << endl
         << "\nAverage Price of Property with Hardwood Floors : " << Hardwood << endl
         << "Average Price of Property without Hardwood Floors : " << wo_Hardwood << endl
         << "\nAverage Price of Property with Fireplace : " << fire << endl
         << "Average Price of Property without Fireplace : " << wo_fire << endl
         << "\nAverage Price of Property with Deck : " << deck << endl
         << "Average Price of Property without Deck : " << wo_deck << endl
         << "\nProperties with Balcony are the most expensive. As balconies are desired by almost \neveryone, which increases their demand. Hence, they are the most expensive." << endl
         << endl;

    delete[] Pt17.Amenities;
    delete[] Pt17.Demo;
    delete[] Pt17.price;
    delete[] words;
}

void Menu(string *&fileData);

int main()
{
    string *fileData = new string[MAX];

    ifstream file("data.csv", ios::in);
    if (!getline(file, fileData[0]))
        return 0;

    for (int i = 0; i < MAX; i++)
        getline(file, fileData[i]);

    file.close();

    Menu(fileData);

    return 0;
}

void Menu(string *&fileData)
{
    int choice = 0;

    do
    {

        cout << "\nMENU FOR Q1" << endl
             << "========================================" << endl
             << "\nChoose Your choice " << endl
             << "1. Part 1 \n"
             << "2. Part 2 \n"
             << "3. Part 3 \n"
             << "4. Part 4 \n"
             << "5. Part 5 \n"
             << "6. Part 6 \n"
             << "7. Part 7 \n"
             << "8. Part 8 \n"
             << "9. Part 9 \n"
             << "10. Part 10 \n"
             << "11. Part 11 \n"
             << "12. Part 12 \n"
             << "13. Part 13 \n"
             << "14. Part 14 \n"
             << "15. Part 15 \n"
             << "16. Part 16 \n"
             << "17. Part 17 \n"
             << "0. Exit \n"
             << endl
             << "Enter : ";
        cin >> choice;

        cout << "\nAnswer : \n----------------------------------------\n";

        switch (choice)
        {
        case 1:
            Part1(fileData);
            break;
        case 2:
            Part2(fileData);
            break;
        case 3:
            Part3(fileData);
            //  Part3_();
            break;
        case 4:
            Part4(fileData);
            //    Part4_();
            break;
        case 5:
            Part5(fileData);
            break;
        case 6:
            Part6(fileData);
            break;
        case 7:
            Part7(fileData);
            // cout << "\n";
            //  Part7_(fileData);
            break;
        case 8:
            Part8(fileData);
            break;
        case 9:
            Part9(fileData);
            break;
        case 10:
            Part10(fileData);
            break;
        case 11:
            Part11(fileData);
            break;
        case 12:
            Part12(fileData);
            break;
        case 13:
            Part13(fileData);
            break;
        case 14:
            Part14(fileData);
            break;
        case 15:
            Part15(fileData);
            break;
        case 16:
            Part16(fileData);
            break;
        case 17:
            Part17(fileData);
            break;
        case 0:
            cout << "\nExiting..." << endl;
            break;
        default:
            break;
        }

    } while (choice);

    cout << "\nProgram Exited successfully" << endl;

    cout << "\n========================================" << endl
         << endl;
}
