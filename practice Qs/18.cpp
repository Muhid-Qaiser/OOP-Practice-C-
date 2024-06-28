#include <iostream>

class Department;
class Course;
class Student;

class Course
{
private:
    Student *students[50];
    int totalStudents;

public:
    Course() : totalStudents(0) {}

    void addStudent(Student *newStudent)
    {
        if (totalStudents < 50)
        {
            students[totalStudents] = newStudent;
            totalStudents++;
        }
        else
        {
            std::cout << "Maximum student capacity reached for this course." << std::endl;
        }
    }

    void removeStudent(int index)
    {
        if (index >= 0 && index < totalStudents)
        {
            for (int i = index; i < totalStudents - 1; i++)
            {
                students[i] = students[i + 1];
            }
            totalStudents--;
        }
        else
        {
            std::cout << "Invalid student index." << std::endl;
        }
    }

    Student *getStudent(int index)
    {
        if (index >= 0 && index < totalStudents)
        {
            return students[index];
        }
        return nullptr;
    }

    int getTotalStudents()
    {
        return totalStudents;
    }
};

class Department
{
private:
    Course courses[10];
    int totalCourses;

public:
    Department() : totalCourses(0) {}

    void addCourse(Course newCourse)
    {
        if (totalCourses < 10)
        {
            courses[totalCourses] = newCourse;
            totalCourses++;
        }
        else
        {
            std::cout << "Maximum course capacity reached for this department." << std::endl;
        }
    }

    void removeCourse(int index)
    {
        if (index >= 0 && index < totalCourses)
        {
            for (int i = index; i < totalCourses - 1; i++)
            {
                courses[i] = courses[i + 1];
            }
            totalCourses--;
        }
        else
        {
            std::cout << "Invalid course index." << std::endl;
        }
    }

    Course &getCourse(int index)
    {
        if (index >= 0 && index < totalCourses)
        {
            return courses[index];
        }
        // Return a reference to an invalid course if index is out of range
        static Course invalidCourse;
        return invalidCourse;
    }

    int getTotalCourses()
    {
        return totalCourses;
    }
};

class Student
{
private:
    Department *department;

public:
    Student() : department(nullptr) {}

    void setDepartment(Department *newDepartment)
    {
        department = newDepartment;
    }

    Department *getDepartment()
    {
        return department;
    }
};

int main()
{
    // Create departments
    Department department1;
    Department department2;

    // Create courses
    Course course1;
    Course course2;
    Course course3;

    // Add courses to departments
    department1.addCourse(course1);
    department1.addCourse(course2);
    department2.addCourse(course3);

    // Create students
    Student student1;
    Student student2;
    Student student3;

    // Enroll students in courses
    course1.addStudent(&student1);
    course1.addStudent(&student2);
    course2.addStudent(&student2);
    course3.addStudent(&student3);

    // Set department for students
    student1.setDepartment(&department1);
    student2.setDepartment(&department1);
    student3.setDepartment(&department2);

    // Print department of students
    std::cout << "Student 1 department: " << student1.getDepartment() << std::endl;
    std::cout << "Student 2 department: " << student2.getDepartment() << std::endl;
    std::cout << "Student 3 department: " << student3.getDepartment() << std::endl;

    return 0;
}
