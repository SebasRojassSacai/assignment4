//Sebastian Rojas
//10/25/2023
//The reason for writing this code is delve deeper into Classes, Encapsulation, Inheritance

#include <iostream>
#include <string>
using namespace std;

class COP3014
{
private:
    string first_name;
    string last_name;
    string z_number;
    double grades[5];
    double total_grade;
    char final_letter_grade;

public:
    COP3014()
    {
        first_name = "";
        last_name = "";
        z_number = "";
        for (int i = 0; i < 5; i++)
        {
            grades[i] = 0.0;
        }
        total_grade = 0.0;
        final_letter_grade = ' ';
    }

    void setFirstName(const string& fname)
    {
        first_name = fname;
    }

    void setLastName(const string& lname)
    {
        last_name = lname;
    }

    void setZNumber(const string& znum)
    {
        z_number = znum;
    }
    void settotal_grade(const double tot)
    {
        total_grade = tot;
    }
    void setGrades(double assignment1, double assignment2, double assignment3, double midterm, double final)
    {
        grades[0] = assignment1;
        grades[1] = assignment2;
        grades[2] = assignment3;
        grades[3] = midterm;
        grades[4] = final;
    }
    double getassignment1() const
    {
        return grades[0];
    }
    double getassignment2() const
    {
        return  grades[1];
    }
    double getassignment3() const
    {
        return grades[2];
    }
    double getmidterm() const
    {
        return grades[3];
    }
    double getfinal() const
    {
        return grades[4];
    }

    string getFirstName() const
    {
        return first_name;
    }

    string getLastName() const
    {
        return last_name;
    }

    string getZNumber() const
    {
        return z_number;
    }
    double gettotalGrade() const
    {
        return total_grade;
    }

    void computeTotalGrade()
    {
        total_grade =
            ((grades[0] + grades[1] + grades[2]) / 3.0) * 0.25 + grades[3] * 0.3 +
            grades[4] * 0.45;
    }

    void computeFinalLetterGrade()
    {
        if (total_grade >= 90)
        {
            final_letter_grade = 'A';
        }
        else if (total_grade >= 80)
        {
            final_letter_grade = 'B';
        }
        else if (total_grade >= 70)
        {
            final_letter_grade = 'C';
        }
        else if (total_grade >= 60)
        {
            final_letter_grade = 'D';
        }
        else
        {
            final_letter_grade = 'F';
        }
    }

    void inputStudentInfo()
    {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        cout << "Enter student's Z-number: ";
        cin >> z_number;
        cout << "Enter grade for assignment 1: ";
        cin >> grades[0];
        cout << "Enter grade for assignment 2: ";
        cin >> grades[1];
        cout << "Enter grade for assignment 3: ";
        cin >> grades[2];
        cout << "Enter grade for midterm: ";
        cin >> grades[3];
        cout << "Enter grade for final: ";
        cin >> grades[4];
    }

    void outputStudentInfo()
    {
        cout << "" << first_name << " " << "" << last_name << endl;
        cout << "Z-number: Z" << z_number << endl;
        cout << "Assign 1: " << grades[0] << endl;
        cout << "Assign 2: " << grades[1] << endl;
        cout << "Assign 3: " << grades[2] << endl;

        cout << "Midterm: " << grades[3] << endl;
        cout << "Final: " << grades[4] << endl;
        cout << "Total Grade: " << total_grade << endl;
        cout << "Final Grade: " << final_letter_grade << endl;
    }
};


class Fall23 :public COP3014
{
private:
    double assignment4;		// New member variable for the 4th assignment

public:
    Fall23() :assignment4(0.0)
    {
    }				// Constructor for the derived class

    // Redefine the input function to include all assessments
    void inputStudentInfo()
    {
        COP3014::inputStudentInfo();	// Call the base class input function
        cout << "Enter grade for assignment 4: ";
        cin >> assignment4;
    }

    // Redefine the output function to display the 4th assignment grade
    void outputStudentInfo()
    {
        COP3014::outputStudentInfo();	// Call the base class output function
        cout << "Assign 4: " << assignment4 << endl;	// Display Assign 4
    }

    // Redefine the function to compute the student's total grade, including the 4th assignment
    void computeTotalGrade()
    {
        settotal_grade(((getassignment1() + getassignment2() + getassignment3() + assignment4) / 4.0) * 0.25 + getmidterm() * 0.3 + getfinal() * 0.45);
    }
};


class Summer23 :public COP3014
{
private:
    double bonus;

public:
    Summer23() :bonus(0.0) {}


    void inputStudentInfo()
    {
        COP3014::inputStudentInfo();
        cout << "Enter bonus (1-3): ";
        cin >> bonus;
    }
    // Redefine the output function
    void outputStudentInfo()
    {
    COP3014:outputStudentInfo(); // Call the base class output function
        cout << "Bonus: " << bonus << "%" << endl; //Display bonus
    }

    void addBonusToFinalGrade()
    {
        settotal_grade((((getassignment1() + getassignment2() + getassignment3()) / 3.0) * 0.25 + getmidterm() * 0.3 + getfinal() * 0.45) + bonus);
    }

};



int
main()
{
    Fall23 student1;
    Fall23 student2;
    student1.inputStudentInfo();
    student1.computeTotalGrade();
    student1.computeFinalLetterGrade();

    student2.inputStudentInfo();
    student2.computeTotalGrade();
    student2.computeFinalLetterGrade();


    student1.outputStudentInfo();
    cout << endl;
    student2.outputStudentInfo();
    cout << endl;

    Summer23 student11;
    Summer23 student22;
    student11.inputStudentInfo();
    student11.computeTotalGrade();
    student11.computeFinalLetterGrade();

    student22.inputStudentInfo();
    student22.computeTotalGrade();
    student22.computeFinalLetterGrade();
    cout << "Summer23" << endl;
    student11.outputStudentInfo();
    cout << endl;
    student22.outputStudentInfo();




    return 0;
}