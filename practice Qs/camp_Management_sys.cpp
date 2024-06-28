#include <iostream>
using namespace std;

class Department
{
    char *dname;
    int f, s;

public:
    Department() {}
    Department(char *name, int f, int s) : dname(name), f(f), s(s) {}
    void set(char *name, int f, int s)
    {
        dname = name;
        this->f = f;
        this->s = s;
    }
    void setF(int f)
    {
        this->f = f;
    }
    void setS(int s)
    {
        this->s = s;
    }
    void display()
    {
        cout << "Department : " << dname << endl;
        cout << "Faculty : " << f << endl;
        cout << "Staffs : " << s << endl;
    }
    char *getName()
    {
        return dname;
    }
};

class UniversityCampus
{
    char *name;
    Department *d;
    int count;
    int curr;

public:
    UniversityCampus(char *name, char **dp, int *f, int *s) : name(name)
    {
        count = 0, curr = 0;

        for (int i = 0; dp[i] != nullptr; i++)
        {
            count = i;
        }
        count++;

        d = new Department[100];

        // for (int i = 0; dp[count++] == nullptr; i++)
        for (int i = 0; i < count; i++)
        {
            // d[curr] = new Department(dp[i], f[i], s[i]);
            d[curr++].set(dp[i], f[i], s[i]);
        }
    }

    bool operator+(char *dname)
    {
        bool checkr = true;

        for (int i = 0; i < curr; i++)
        {
            if (dname == d[i].getName())
            {
                checkr = false;
            }
        }

        if (checkr)
        {
            cout << "\nAdding Department...\n";

            d[curr++].set(dname, 0, 0);
            return true;
        }
        else
        {
            cout << "\nDepartment already exists\n";
            return false;
        }
    }

    void leftShift(int index)
    {
        for (int i = index; i < curr; i++)
        {
        }
    }

    bool operator-(char *dname)
    {
        bool checkr = false;

        for (int i = 0; i < curr; i++)
        {
            if (dname == d[i].getName())
            {
                d[i] = d[i + 1];
                curr--;
                checkr = true;
            }
            else if (checkr == true)
            {
                d[i] = d[i + 1];
            }
        }

        if (checkr)
            return true;

        return false;
    }

    void printCampusDetails()
    {
        cout << "\n\nCampus Details\n------------------------" << endl;
        cout << "Name : " << name << endl;
        for (int i = 0; i < curr; i++)
        {
            d[i].display();
            cout
                << endl;
        }
        cout << "\n-------------------------------\n\n";
    }

    void addFaculty(char *dname, int n)
    {
        for (int i = 0; i < curr; i++)
        {
            if (dname == d[i].getName())
            {
                d[i].setF(n);
            }
        }
    }

    void addStafftoDepartments(char *dname, int n)
    {
        for (int i = 0; i < curr; i++)
        {
            if (dname == d[i].getName())
            {
                d[i].setS(n);
            }
        }
    }
};

int main()
{
    char *dpts[20] = {"CS", "EE", "A&F", nullptr};
    int faculty[] = {46, 33, 23}, staff[] = {4, 3, 5};
    UniversityCampus lhr("Lahore", dpts, faculty, staff);
    lhr.printCampusDetails();

    bool successFull = lhr + "Mng";

    lhr.addFaculty("Mng", 44);

    lhr.addStafftoDepartments("Mng", 4);

    lhr.printCampusDetails();

    successFull = lhr - "A&F";

    if (successFull)
    {
        cout << "Department removed successfully." << endl;
    }
    else
        cout << "Data not found." << endl;

    lhr.printCampusDetails();

    return 0;
}