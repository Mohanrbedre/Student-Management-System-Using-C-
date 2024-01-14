#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Student
{
public:
    int admno;
    char name[20];
    char gender;
    char std;
    float marks;
    float percentage;


    void getData();
    void showData();
    int getAdmno() { return admno; }
}s;

void Student::getData()
{
    cout << "\n\nEnter Student Details......\n";
    cout << "Enter Admission No.     : "; cin >> admno;
    cout << "Enter Full Name         : "; cin.ignore(); cin.getline(name, 20);
    cout << "Enter Gender (M/F)      : "; cin >> gender;
    cout << "Enter Standard          : "; cin >> std;
    cout << "Enter Marks (out of 500): "; cin >> marks;
    cout << endl;
    percentage = marks * 100.0 / 500.00;
}

void Student::showData()
{
    cout << "\n\n.......Student Details......\n";
    cout << "Admission No.     : " << admno << endl;
    cout << "Full Name         : " << name << endl;
    cout << "Gender            : " << gender << endl;
    cout << "Standard          : " << std << endl;
    cout << "Marks (out of 500): " << marks << endl;
    cout << "Percentage        : " << percentage << endl;
    cout << endl;
}

void addData()
{
    ofstream fout;
    fout.open("Students.txt", ios::out | ios::app);
    s.getData();
    fout << "Admission No.     : " << s.getAdmno() << endl;
    fout << "Full Name         : " << s.name << endl;
    fout << "Gender            : " << s.gender << endl;
    fout << "Standard          : " << s.std << endl;
    fout << "Marks (out of 500): " << s.marks << endl;
    fout << "Percentage        : " << s.percentage << endl;
    fout << endl;
    fout.close();
    cout << "\n\nData Successfully Saved to File....\n";
}

void displayData()
{
    ifstream fin;
    fin.open("Students.txt", ios::in);
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void searchData()
{
    int n, flag = 0;
    ifstream fin;
    fin.open("Students.txt", ios::in);
    cout << "Enter Admission Number you want to search : ";
    cin >> n;

    string line;
    while (getline(fin, line))
    {
        if (line.find("Admission No.     : " + to_string(n)) != string::npos)
        {
            cout << "The Details of Admission No. " << n << " shown herewith:\n";
            cout << line << endl;
            for (int i = 0; i < 5; i++)
            {
                getline(fin, line);
                cout << line << endl;
            }
            flag++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "The Admission No. " << n << " not found....\n\n";
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void deleteData()
{
    int n, flag = 0;
    ifstream fin;
    ofstream fout, tout;

    fin.open("Students.txt", ios::in);
    fout.open("TempStud.txt", ios::out | ios::app);
    tout.open("TrashStud.txt", ios::out | ios::app);

    cout << "Enter Admission Number you want to move to Trash : ";
    cin >> n;

    string line;
    while (getline(fin, line))
    {
        if (line.find("Admission No.     : " + to_string(n)) != string::npos)
        {
            cout << "The Following Admission No. " << n << " has been moved to Trash:\n";
            cout << line << endl;
            for (int i = 0; i < 5; i++)
            {
                getline(fin, line);
                cout << line << endl;
                tout << line << endl;
            }
            flag++;
        }
        else
        {
            fout << line << endl;
        }
    }
    fout.close();
    tout.close();
    fin.close();
    if (flag == 0)
        cout << "The Admission No. " << n << " not found....\n\n";
    remove("Students.txt");
    rename("TempStud.txt", "Students.txt");
}

void getTrash()
{
    ifstream fin;
    fin.open("TrashStud.txt", ios::in);
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
    cout << "\n\nData Reading from Trash File Successfully Done....\n";
}

void modifyData()
{
    int n, flag = 0;
    ifstream fin;
    ofstream fout;

    fin.open("Students.txt", ios::in);
    fout.open("TempStud.txt", ios::out);

    cout << "Enter Admission Number you want to Modify: ";
    cin >> n;

    string line;
    while (getline(fin, line))
    {
        if (line.find("Admission No.     : " + to_string(n)) != string::npos)
        {
            cout << "The Following Admission No. " << n << " will be modified with new data:\n";
            cout << line << endl;
            for (int i = 0; i < 5; i++)
            {
                getline(fin, line);
                cout << line << endl;
            }
            cout << "\n\nNow Enter the New Details....\n";
            s.getData();
            fout << "Admission No.     : " << s.getAdmno() << endl;
            fout << "Full Name         : " << s.name << endl;
            fout << "Gender            : " << s.gender << endl;
            fout << "Standard          : " << s.std << endl;
            fout << "Marks (out of 500): " << s.marks << endl;
            fout << "Percentage        : " << s.percentage << endl;
            flag++;
        }
        else
        {
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();

    if (flag == 0)
    {
        cout << "The Admission No. " << n << " not found....\n\n";
        remove("TempStud.txt");  // Remove the temporary file if record not found
    }
    else
    {
        remove("Students.txt");        // Remove the original file
        rename("TempStud.txt", "Students.txt");  // Rename the temporary file to replace the original file
        cout << "Data Modified Successfully.\n\n";
    }
}


void project()
{
    int ch;
    do
    {
        system("cls");
        cout << "...............STUDENT MANAGEMENT SYSTEM..............\n";
        cout << "======================================================\n";
        cout << "0. Exit from Program\n";
        cout << "1. Write Data to File\n";
        cout << "2. Read Data From File\n";
        cout << "3. Search Data From File\n";
        cout << "4. Delete Data From File\n";
        cout << "5. Get Deleted Records from Trash file\n";
        cout << "6. Modify Data in File\n";
        cout << "Enter your choice  : ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 1:
            addData();
            break;
        case 2:
            displayData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            getTrash();
            break;
        case 6:
            modifyData();
            break;
        }
        system("pause");
    } while (ch);
}

int main()
{
    project();
}
