#include <iostream>
using namespace std;

class Staff
{
protected:
    string name;
    int id;

public:
    Staff() {}
    Staff(string name, int id) : name(name), id(id) {}
    virtual void display() = 0;
    virtual ~Staff() {}
};

class Doctor : public Staff
{
    string specialization;

public:
    Doctor(string name, int id, string specialization) : Staff(name, id), specialization(specialization) {}
    void display()
    {
        cout << "Doctor \n";
        cout << "Name : " << name << endl
             << "ID : " << id << endl
             << "specialization : " << specialization << endl;
    }
};

class Patient
{

protected:
    string name;
    int id;

public:
    Patient() {}
    Patient(string name, int id) : name(name), id(id) {}
    virtual void display() = 0;
    virtual ~Patient() {}
};

class Inpatient : public Patient
{
    int room;

public:
    Inpatient(string name, int id, int room) : Patient(name, id), room(room) {}
    void display()
    {
        cout << "InPatient \n";
        cout << "Name : " << name << endl
             << "ID : " << id << endl
             << "Room Admitted : " << room << endl;
    }
};

class Outpatient : public Patient
{
    string date;

public:
    Outpatient(string name, int id, string date) : Patient(name, id), date(date) {}
    void display()
    {
        cout << "InPatient \n";
        cout << "Name : " << name << endl
             << "ID : " << id << endl
             << "Date Admitted : " << date << endl;
    }
};

class Hospital
{
    Patient **patient;
    Doctor **doctor;
    int pcount;
    int dcount;

public:
    Hospital()
    {
        patient = new Patient *[100];
        doctor = new Doctor *[100];
        pcount = 0;
        dcount = 0;
    }
    void addDoctor(Doctor *obj)
    {
        if (limitDoctor())
        {
            doctor[dcount++] = obj;
        }
        else
        {
            cout << "Limit Reached!" << endl;
        }
    }
    void addPatient(Patient *obj)
    {
        if (limitPatient())
        {
            patient[pcount++] = obj;
        }
        else
        {
            cout << "Limit Reached!" << endl;
        }
    }
    bool limitPatient()
    {
        return (pcount < 100);
    }
    bool limitDoctor()
    {
        return (dcount < 100);
    }
    void displayDoctors()
    {
        cout << "\nDoctor List\n----------------------------\n";
        for (int i = 0; i < dcount; i++)
        {
            doctor[i]->display();
            cout << endl;
        }
    }
    void displayPatients()
    {
        cout << "\nPatient List\n----------------------------\n";
        for (int i = 0; i < pcount; i++)
        {
            patient[i]->display();
            cout << endl;
        }
    }
};

int main()
{
    Hospital hospital;

    Doctor *doctor1 = new Doctor("Dr. John Doe", 1001, "Cardiology");
    Doctor *doctor2 = new Doctor("Dr. Jane Smith", 1002, "Orthopedics");
    Doctor *doctor3 = new Doctor("Dr. David Johnson", 1003, "Pediatrics");

    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);
    hospital.addDoctor(doctor3);

    Patient *patient1 = new Inpatient("John Smith", 2001, 101);
    Patient *patient2 = new Outpatient("Jane Doe", 2002, "2023-06-10");
    Patient *patient3 = new Inpatient("David Wilson", 2003, 202);

    hospital.addPatient(patient1);
    hospital.addPatient(patient2);
    hospital.addPatient(patient3);

    hospital.displayDoctors();
    hospital.displayPatients();

    delete doctor1;
    delete doctor2;
    delete doctor3;
    delete patient1;
    delete patient2;
    delete patient3;

    return 0;
}