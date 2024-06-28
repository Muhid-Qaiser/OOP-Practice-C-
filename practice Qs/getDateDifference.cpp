#include <iostream>

int calculateDays(int day, int month, int year)
{
    const int HARD_CODED_DAY = 1;
    const int HARD_CODED_MONTH = 1;
    const int HARD_CODED_YEAR = 2000;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int startYear = HARD_CODED_YEAR;
    int startMonth = HARD_CODED_MONTH;
    int startDay = HARD_CODED_DAY;

    int endYear = year;
    int endMonth = month;
    int endDay = day;

    int days = 0;

    while (startYear != endYear || startMonth != endMonth || startDay != endDay)
    {
        days++;
        startDay++;

        if (startDay > daysInMonth[startMonth - 1])
        {
            startDay = 1;
            startMonth++;
        }

        if (startMonth > 12)
        {
            startMonth = 1;
            if ((startYear % 4 == 0 && startYear % 100 == 0) || (startYear % 400 == 0))
            {
                days++;
            }
            startYear++;
        }
    }

    return days;
}

int main()
{
    int day, month, year;

    std::cout << "Enter the date (day month year): ";
    std::cin >> day >> month >> year;

    int days = calculateDays(day, month, year);

    std::cout << "Number of days between 1/1/2000 and " << day << "/" << month << "/" << year
              << " is " << days << " days." << std::endl;

    return 0;
}
