#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

char opt, opt2, opt3;
string line;
char checkID[5];

class Employee {

    public:
        char id[5];
        string name;
        int age;
        char gender;
        char contactnum[11];
        string post;
        int salary;
        int experience;

};

class Admin : public Employee{

    private:
        string password;
    public:
        void Login();
        void Logout();
        void Menu();
        void Add();
        void Search();
        void Edit();
        void View();

};


void Admin::Login(){

    system("cls");
    cout << "\tEmployee Management System";
    cout << "\n-------------------------------------------";
    cout << "\n\n\t   Password: ";
    cin >> password;

    cout << "\n\n\t  Checking";

    for(int a = 1; a < 6; a++)
    {
        Sleep(500);
        cout << "...";
    }

    if(password == "12345"){
        cout << "\33[2K\r  Welcome Back! Thank you for logging in.";
        Sleep(1500);
        Menu();
    }
    else{
        cout << "\33[2K\r  Invalid login attempt! Please try again.";
        Sleep(1500);
        Login();
    }

}

void Admin::Logout(){

    system("cls");

    cout << "\nDo you really want to log out? (y/n): ";
    cin >> opt;

    if(opt == 'Y' || opt == 'y'){
        cout << "\n\nLog out from the current account";
        for(int a = 1; a < 6; a++){
            Sleep(500);
                cout << "...";
        }
        system("cls");
        Login();
    }
    else{
        cout << "\nReturning to Menu";
        for(int a = 1; a < 6; a++){
        Sleep(500);
        cout << "...";
        }
        Menu();
    }

}

void Admin::Menu(){

    int opt;
    system("cls");
    cout << "------------------ Program Menu ------------------";
    cout << "\n\n\t1) Add new employee";
    cout << "\n\t2) View list of employee information";
    cout << "\n\t3) Search employee";
    cout << "\n\t4) Edit employee information";
    cout << "\n\t5) Logout";
    cout << "\n\n--------------------------------------------------";
    cout << "\n\n\t  Please enter your choice: ";
    cin >> opt;

    switch(opt){
        case 1 :
            Add();
            break;

        case 2 :
            View();
            break;

        case 3 :
            Search();
            break;

        case 4 :
            Edit();
            break;

        case 5 :
            Logout();
            break;

        default :
            cout<<"\nInvalid input! Please choose again.";
            Sleep(1000);
            Menu();
    }
}

void Admin::Add(){

    fstream file;

    do{
        system("cls");
        if(!file){
            cout << "Error: file could not be opened!";
            Sleep(1000);
            file.close();
        }
        else{
            cout << "--------------- Add a new record ---------------";
            cout << "\n\nEnter employee ID [max 4 digits]: ";
            cin >> checkID;

            file.open("EmployeeRecord.txt");
            file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            while(getline(file, line)){
                if(strcmp(checkID, id) == 0){
                   cout << "\nThis ID already exist! Try another ID.";
                   Sleep(1000);
                   Add();
                }
                file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            }
            file.close();
            copy(checkID, checkID + 5, id);

            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter the age: ";
            cin >> age;
            cout << "Enter the gender(m/f): ";
            cin >> gender;
            cout << "Enter the contact number: ";
            cin >> contactnum;
            cout << "Enter the post(boss/manager/staff): ";
            cin >> post;
            cout << "Enter the salary: ";
            cin >> salary;
            cout << "Enter the experience(years): ";
            cin >> experience;

            cout << "\nPress 's' to save the record or any key to abort this perform: ";
            cin >> opt;

            if (opt=='s'||opt=='S'){
                file.open("EmployeeRecord.txt", ios::app | ios::out);
                file << id << " " << name << " " << age << " " << gender << " " << contactnum << " " << post << " " << salary << " " << experience << endl;
                file.close();

                cout << "\nAdding";
                for(int a = 1; a < 6; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\33[2K\rRecord save successfully !";
            }
            else cout << "\nRecord is failed to save!";

            Sleep(800);
            cout <<"\n\nDo you want to add another record?(y/n): ";
            cin >> opt2;

            if(opt2=='n'||opt2=='N')
            {
                cout << "\nReturning to Menu";
                for(int a = 1; a < 6; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                Menu();
            }
        }
    }while(opt2=='y'||opt2=='Y');
}


void Admin::View(){

    system("cls");
    int num = 1;

    fstream file;
    file.open("EmployeeRecord.txt");

    if(!file){
        cout << "Error: file could not be opened!";
        Sleep(1000);
        file.close();
    }
    else{
        cout << "\n\t\t\t\t\t\t\t   EMPLOYEE RECORD" << endl;
        cout << "\n ----------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n ||     ID     ||       Name        ||    Age    ||    Gender    ||    Contact Number    ||    Post    ||   Salary   ||   Experience   ||";
        cout << "\n ----------------------------------------------------------------------------------------------------------------------------------------";

        file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
        while(getline(file, line)){
            cout << endl;
            cout << setw(2) << num++ << "." << setw(8) << id << setw(20) << name << setw(14) << age << setw(13) << gender << setw(25) << contactnum << setw(17)<< post << setw(14) << salary << setw(13) << experience << endl;
            file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
        }
        file.close();
    }

    cout << "\n\nPress 'y' to return to menu or any key to log out from the current account.";
    cin >> opt;

    if(opt == 'y'|| opt == 'Y'){
        cout << "\nReturning to Menu";
        for(int a = 1; a < 6; a++)
        {
            Sleep(500);
            cout << "...";
        }
        Menu();
    }
    else Logout();

}

void Admin::Search(){

    ifstream file;

    do{
        system("cls");
        file.open("EmployeeRecord.txt");
        int found = 0;

        if(!file){
            cout << "Error: file could not be opened!";
            Sleep(1000);
            file.close();
        }
        else{
            cout << "---------- Search Employee ----------";
            cout << "\n\nEnter Employee ID: ";
            cin >> checkID;
            cout << "\nSearching";
            for(int a = 1; a < 6; a++){
                Sleep(500);
                cout << "...";
            }
            file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            while(getline(file, line)){
                if(strcmp(checkID, id) == 0){
                    found++;
                    cout << "\33[2K\n-------- Employee Information -------";
                    cout << "\n\nEmployee ID: " << id;
                    cout << "\nEmployee Name: " << name;
                    cout << "\nEmployee Age: " << age;
                    cout << "\nEmployee Gender: " << gender;
                    cout << "\nEmployee Phone Number: " << contactnum;
                    cout << "\nEmployee Post: " << post;
                    cout << "\nEmployee Salary: " << salary;
                    cout << "\nEmployee Experience: " << experience << " years";
                    cout << "\n\n-------------------------------------";
                }
                file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            }

            if(found == 0){
                cout << "\33[2K\nEmployee ID not found! Please try again.";
                Sleep(800);
                Search();
            }

            file.close();

            cout << "\n\nDo you want to search for another employee?(y/n): ";
            cin >> opt;

            if(opt=='n'||opt=='N')
            {
                cout << "\nReturning to Menu";
                for(int a = 1; a < 6; a++){
                Sleep(500);
                cout << "...";
                }
                Menu();
            }
        }

    }while(opt=='y'||opt=='Y');
}

void Admin::Edit(){

    fstream file, file2;

    do{
        system("cls");
        int found = 0;
        file.open("EmployeeRecord.txt", ios::in);
        file2.open("tmp.txt", ios::app | ios::out);

        if(!file){
            cout << "Error: file could not be opened!";
            Sleep(1000);
            file.close();
        }
        else{
            cout << "---------- Edit Employee Information ----------";
            cout << "\n\nEnter Employee ID to edit: ";
            cin >> checkID;

            file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            while(!file.eof()){
                if(strcmp(checkID, id) == 0){
                    found++;
                    cout << "\n-----------------------------------------------";
                    cout << "\n\nEnter employee ID [max 4 digits]: ";
                    cin >> id;
                    cout << "Enter employee name: ";
                    cin >> name;
                    cout << "Enter the age: ";
                    cin >> age;
                    cout << "Enter the gender(m/f): ";
                    cin >> gender;
                    cout << "Enter the contact number: ";
                    cin >> contactnum;
                    cout << "Enter the post(boss/manager/staff): ";
                    cin >> post;
                    cout << "Enter the salary: ";
                    cin >> salary;
                    cout << "Enter the experience(years): ";
                    cin >> experience;
                    cout << "\n-----------------------------------------------";

                    cout << "\n\nPress 'y' to CONFIRM update or any key to abort this perform: ";
                    cin >> opt;

                    if (opt=='y'||opt=='Y'){
                        file2 << id << " " << name << " " << age << " " << gender << " " << contactnum << " " << post << " " << salary << " " << experience << endl;

                        cout << "\nUpdating";
                        for(int a = 1; a < 6; a++)
                        {
                            Sleep(500);
                            cout << "...";
                        }

                        cout << "\33[2K\rRecord update successfully !";
                    }
                    else {
                        cout << "\nRecord is failed to update!";
                    }
                }
                if(strcmp(checkID, id) != 0){
                    file2 << id << " " << name << " " << age << " " << gender << " " << contactnum << " " << post << " " << salary << " " << experience << endl;
                }
                file >> id >> name >> age >> gender >> contactnum >> post >> salary >> experience;
            }

            if(found==0)
            {
                    cout << "\n\nEmployee ID not found! Please try again.";
                    Sleep(800);
                    Edit();
            }
            file.close();
            file2.close();
            remove("EmployeeRecord.txt");
            rename("tmp.txt","EmployeeRecord.txt");

            cout << "\n\nDo you want to edit another employee record?(y/n): ";
            cin >> opt2;

            if(opt2 == 'n' || opt2 == 'N')
            {
                cout << "\nReturning to Menu";
                for(int a = 1; a < 6; a++){
                    Sleep(500);
                    cout << "...";
                }
                Menu();
            }
        }
    }while(opt2=='y'||opt2=='Y');

}

int main(){

    Admin a;

    cout << "\n   -------------------------------------------";
    cout << "\n   | Welcome to Employee Management System ! |";
    cout << "\n   -------------------------------------------";
    cout << "\n\n   Loading";

    for(int a = 1; a < 6; a++)
    {
        Sleep(500);
        cout << "...";
    }

    system("cls");
    cout << "\n   -------------------------------------------";
    cout << "\n   | Welcome to Employee Management System ! |";
    cout << "\n   -------------------------------------------";
    cout << "\n\n   Load Successful!";
    Sleep(1500);

    system("cls");
    a.Login();

    return 0;
}



