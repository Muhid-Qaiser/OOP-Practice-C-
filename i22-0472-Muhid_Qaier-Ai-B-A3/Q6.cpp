#include <iostream>
#include <string>
using namespace std;

// ! Classes and functions

class RentalReservation
{
    string ID;
    string c_name;
    string c_make;
    string c_model;
    string pickUp_date;
    string return_date;
    int rental_duration;
    int rental_rate;
    int total_rent;
    long long int day1;
    long long int day2;

    struct reservationDetails
    {
        string id;
        string cust_name;
        string car_make;
        string car_model;
        string car_pickup;
        string car_return;
        int rent_Duration;
        int rent_Rate;
        int rent_Total;
    } res_Details;

public:
    RentalReservation()
    {
        c_name = "";
        c_make = "";
        c_model = "";
        ID = "";
        pickUp_date = "";
        return_date = "";
        rental_duration = 0;
        rental_rate = 0;
        total_rent = 0;

        res_Details.id = '\0';
        res_Details.cust_name = '\0';
        res_Details.car_make = '\0';
        res_Details.car_model = '\0';
        res_Details.car_pickup = '\0';
        res_Details.car_return = '\0';
        res_Details.rent_Duration = 0;
        res_Details.rent_Rate = 0;
        res_Details.rent_Total = 0;
    }

    ~RentalReservation()
    {
        cout << "\n\nCar Data Has Successfully Been Deleted/Created!" << endl
             << endl
             << "=========================================" << endl
             << endl;
    }

    RentalReservation(string id, string name, string make, string model, string pickUp_Date, string return_Date)
    {
        c_name = name;
        c_make = make;
        c_model = model;

        while (!validateMake_Model())
        {
            cout << "\nInvalid Car Make or/and Model\n"
                 << "Try Again\n\n";
            set_c_make();
            set_c_model();
        }

        ID = id;

        while (!validateReservationID())
        {
            cout << "\nInvalid ID\n"
                 << "Try Again\n\n";
            set_ID();
        }

        pickUp_date = pickUp_Date;
        return_date = return_Date;
        rental_duration = 0;
        rental_rate = 0;

        // rental_duration = return_Date - pickUp_Date;
        // rental_rate = 20; ? use if elses here

        calculateRentalDuration();
        calculateRentalRate();

        total_rent = rental_rate * rental_duration;

        res_Details.id = ID;
        res_Details.cust_name = c_name;
        res_Details.car_make = c_make;
        res_Details.car_model = c_model;
        res_Details.car_pickup = pickUp_date;
        res_Details.car_return = return_date;
        res_Details.rent_Duration = rental_duration;
        res_Details.rent_Rate = rental_rate;
        res_Details.rent_Total = total_rent;
    }

    // * Setters

    void set_ID()
    {
        cout << "Enter ID : ";
        getline(cin, ID);
    }

    void set_c_name()
    {
        cout << "Enter Name of Customer : ";
        cin.ignore();
        getline(cin, c_name);
    }

    void set_c_make()
    {
        cout << "Enter Car Maker : ";
        // cin.ignore();
        getline(cin, c_make);
    }

    void set_c_model()
    {
        cout << "Enter Car Model : ";
        // cin.ignore();
        getline(cin, c_model);
    }

    void set_pickUp()
    {
        cout << "Enter Pick Up Date : ";
        cin >> pickUp_date;
    }

    void set_returnDate()
    {
        cout << "Enter Return Date : ";
        cin >> return_date;
    }

    // * Getters

    string get_ID()
    {
        return ID;
    }

    string get_cName()
    {
        return c_name;
    }

    string get_cMake()
    {
        return c_make;
    }

    string get_cModel()
    {
        return c_model;
    }

    string get_pickUp()
    {
        return pickUp_date;
    }

    string get_returnDate()
    {
        return return_date;
    }

    int get_rentalDuration()
    {
        return rental_duration;
    }

    int get_rentalRate()
    {
        return rental_rate;
    }

    int get_rentalTotal()
    {
        return total_rent;
    }

    // * Functions

    bool validateReservationID() const
    {
        int check_chars = 0, check_numbers = 0, check_sum = 0, check_special_chars = 0, count = 0, i = 0;

        for (; ID[i] != '\0'; i++)
        {
            if (i < 8)
            {
                if (((ID[i] >= 'a' && ID[i] <= 'z') || (ID[i] >= 'A' && ID[i] <= 'Z')))
                {
                    check_chars++;
                }
            }

            else if (i >= 8 && i < 10)
            {
                if ((check_chars == 8) && ((ID[i] > 32 && ID[i] < 48) || (ID[i] > 57 && ID[i] < 65) || (ID[i] > 90 && ID[i] < 95)))
                {
                    check_special_chars++;
                }
            }

            else if (i >= 10 && i < 14)
            {
                if ((check_special_chars == 2) && (ID[i] >= '0' && ID[i] <= '9'))
                {
                    check_numbers++;
                    check_sum += (ID[i] - 48);
                }
            }
        }

        if (i == 14 && check_chars == 8 && check_numbers == 4 && check_sum < 18 && check_special_chars == 2)
            return true;
        else
            return false;
    }

    bool validate_Make() const
    {
        if (c_make == "Suzuki")
            return true;
        else if (c_make == "Honda")
            return true;
        else if (c_make == "Toyota")
            return true;
        else if (c_make == "Audi")
            return true;
        else if (c_make == "Bmw")
            return true;

        return false;
    }

    bool validate_Model(string c_make) const
    {
        if (c_make == "Suzuki" && (c_model == "Mehran" || c_model == "Alto"))
            return true;
        else if (c_make == "Honda" && (c_model == "City"))
            return true;
        else if (c_make == "Toyota" && (c_model == "Corolla" || c_model == "Land Cruiser"))
            return true;
        else if (c_make == "Audi" && (c_model == "A6"))
            return true;
        else if (c_make == "Bmw" && (c_model == "M3"))
            return true;

        return false;
    }

    bool validateMake_Model() const
    {

        if (c_make == "Suzuki" && (c_model == "Mehran" || c_model == "Alto"))
            return true;
        else if (c_make == "Honda" && (c_model == "City"))
            return true;
        else if (c_make == "Toyota" && (c_model == "Corolla" || c_model == "Land Cruiser"))
            return true;
        else if (c_make == "Audi" && (c_model == "A6"))
            return true;
        else if (c_make == "Bmw" && (c_model == "M3"))
            return true;

        return false;
    }

    int calculateRentalRate()
    {
        if (c_make == "Suzuki" && (c_model == "Mehran"))
            rental_rate = 15;
        else if (c_make == "Suzuki" && (c_model == "Alto"))
            rental_rate = 17;
        else if (c_make == "Honda" && (c_model == "City"))
            rental_rate = 23;
        else if (c_make == "Toyota" && (c_model == "Corolla"))
            rental_rate = 25;
        else if (c_make == "Toyota" && (c_model == "Land Cruiser"))
            rental_rate = 30;
        else if (c_make == "Audi" && (c_model == "A6"))
            rental_rate = 32;
        else if (c_make == "Bmw" && (c_model == "M3"))
            rental_rate = 33;

        // cout << "rental_rate :  " << rental_rate << endl;

        return rental_rate;
    }

    int days_In_Months(int m, int y) // calculates days in months
    {
        switch (m)
        {
        case 2:
            if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
                return 29;
            else
                return 28;

            // ? Method 2
            // return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        default:
            return 31;
        }
    }

    int calculatingDays(int d, int m, int y) // calculates days by adding days in months and years and days
    {
        int days = 0;

        for (int i = 0; i < y; i++)
        {
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
                days += 366;
            else
                days += 365;

            ////  days += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
        }

        for (int i = 1; i < m; i++)
        {
            days += days_In_Months(i, y);
        }
        days += d - 1;
        return days;
    }

    void calculateRentalDuration()
    {
        int year_pick = 0, month_pick = 0, day_pick = 0, count = 0,
            year_return = 0, month_return = 0, day_return = 0;
        long int Days_1 = 0, Days_2 = 0;

        // * Separating each integer from the string while keeping '/' as the delimiter
        for (int i = 0; pickUp_date[i] != '\0'; i++)
        {
            if (pickUp_date[i] != '/' && count < 2)
            {
                day_pick *= 10;
                day_pick += pickUp_date[i] - 48;

                day_return *= 10;
                day_return += return_date[i] - 48;

                count++;
            }
            else if (pickUp_date[i] != '/' && count < 4)
            {
                month_pick *= 10;
                month_pick += pickUp_date[i] - 48;

                month_return *= 10;
                month_return += return_date[i] - 48;

                count++;
            }
            else if (pickUp_date[i] != '/' && count < 8)
            {
                year_pick *= 10;
                year_pick += pickUp_date[i] - 48;

                year_return *= 10;
                year_return += return_date[i] - 48;

                count++;
            }
        }

        // cout << day_pick << " " << month_pick << " " << year_pick << endl;
        // cout << day_return << " " << month_return << " " << year_return << endl;

        Days_1 = calculatingDays(day_pick, month_pick, year_pick);
        Days_2 = calculatingDays(day_return, month_return, year_return);

        day1 = Days_1;
        day2 = Days_2;

        (Days_1 < Days_2) ? (rental_duration = Days_2 - Days_1) : (rental_duration = Days_1 - Days_2);

        // cout << "rental_duration : " << rental_duration << endl;
    }

    int calculateRentalTotal()
    {
        calculateRentalDuration();
        total_rent = rental_duration * rental_rate;
        return total_rent;
    }

    reservationDetails getReservationDetails()
    {
        // ? Method 1
        /*
        cout << "\nReservation Details\n------------------------\n"
             << "Customer ID : " << ID << endl
             << "Customer Name : " << c_name << endl
             << "Car Make : " << c_make << endl
             << "Car Model : " << c_model << endl
             << "Pick-Up Date : " << pickUp_date << endl
             << "Return Date : " << return_date << endl
             << "Rental Duration : " << rental_duration << endl
             << "Rental Rate : " << rental_rate << endl
             << "Total Amount : $" << total_rent << endl;
        */

        // ? Method 2
        res_Details.id = ID;
        res_Details.cust_name = c_name;
        res_Details.car_make = c_make;
        res_Details.car_model = c_model;
        res_Details.car_pickup = pickUp_date;
        res_Details.car_return = return_date;
        res_Details.rent_Duration = rental_duration;
        res_Details.rent_Rate = rental_rate;
        res_Details.rent_Total = total_rent;

        return res_Details;
    }

    void displayReservationDetails()
    {
        cout << "\nReservation Details\n------------------------\n"
             << "Customer ID : " << res_Details.id << endl
             << "Customer Name : " << res_Details.cust_name << endl
             << "Car Make : " << res_Details.car_make << endl
             << "Car Model : " << res_Details.car_model << endl
             << "Pick-Up Date : " << res_Details.car_pickup << endl
             << "Return Date : " << res_Details.car_return << endl
             << "Rental Duration : " << res_Details.rent_Duration << endl
             << "Rental Rate : " << res_Details.rent_Rate << endl
             << "Total Amount : $" << res_Details.rent_Total << endl;
    }

    void editReservationDetails()
    {
        int choice = 0;

        do
        {

            cout << "\nEdit Profile" << endl
                 << "-------------------------------" << endl
                 << endl
                 << "1. User ID" << endl
                 << "2. Customer Name" << endl
                 << "3. Car Make" << endl
                 << "4. Car Model" << endl
                 << "5. Pick-Up Date" << endl
                 << "6. Return Date" << endl
                 << "0. Exit" << endl
                 << endl
                 << "Enter Choice : ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                set_ID();

                while (!validateReservationID())
                {
                    cout << "\nInvalid ID\n"
                         << "Try Again\n\n";
                    set_ID();
                }
                break;
            case 2:
                set_c_name();
                break;
            case 3:
                set_c_make();
                while (!validate_Make())
                {
                    cout << "\nInvalid Car Make\n"
                         << "Try Again\n\n";
                    set_c_make();
                }

                set_c_model();
                while (!validateMake_Model())
                {
                    cout << "\nInvalid Car Model\n"
                         << "Try Again\n\n";
                    set_c_model();
                }
                calculateRentalRate();
                calculateRentalTotal();

                break;
            case 4:
                set_c_model();

                while (!validateMake_Model())
                {
                    cout << "\nInvalid Car Model\n"
                         << "Try Again\n\n";
                    set_c_model();
                }
                calculateRentalRate();
                calculateRentalTotal();
                break;
            case 5:
                set_pickUp();
                calculateRentalRate();
                calculateRentalTotal();

                if (day1 >= day2)
                {
                    cout << "\nAs Pick Up date exceeds or is equal to the Previous Return Date. Enter a New Return Date." << endl;
                    set_returnDate();
                    calculateRentalRate();
                    calculateRentalTotal();

                    while (day1 >= day2)
                    {
                        cout << "\nInValid Return Date" << endl
                             << "Return Date must be After Pick up Date" << endl
                             << endl;
                        set_returnDate();
                        calculateRentalRate();
                        calculateRentalTotal();
                    }
                }

                break;
            case 6:

                set_returnDate();
                calculateRentalRate();
                calculateRentalTotal();

                if (day1 >= day2)
                {
                    cout << "\nAs Pick Up date exceeds or is equal to the Previous Return Date. Enter a New Return Date." << endl;
                    set_returnDate();
                    calculateRentalRate();
                    calculateRentalTotal();

                    while (day1 >= day2)
                    {
                        cout << "\nInValid Return Date" << endl
                             << "Return Date must be After Pick up Date" << endl
                             << endl;
                        set_returnDate();
                        calculateRentalRate();
                        calculateRentalTotal();
                    }
                }

                break;

            case 0:
                cout << "\nExiting..." << endl
                     << endl;
                break;

            default:
                cout
                    << "\nError 404\n";
                break;
            }
        } while (choice);
    }
};

// ! Main

int main()
{
    RentalReservation r1("wersdfxc@@1234", "joe", "Toyota", "Corolla", "01/01/2001", "01/02/2001");

    cout << "\nRental Car Management System" << endl
         << "=========================================" << endl;

    /*
        r1.set_pickUp();
        r1.set_returnDate();
        cin.ignore();
        r1.set_c_make();
        r1.set_c_model();
        r1.calculateRentalRate();
    cout << "\ntotal rent : " << r1.calculateRentalTotal();
    */

    (r1.validateReservationID()) ? cout << "\nID is Valid\n" : cout << "\nID is Invalid\n";

    r1.editReservationDetails();

    r1.getReservationDetails();
    r1.displayReservationDetails();

    return 0;
}