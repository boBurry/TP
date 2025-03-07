#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int ID, age;
    string name, email;
};

int main() {
    Student st[100];
    fstream file;
    char choice;
    int n,total, updateID;
    string searchEmail;

    cout<<"Enter number of student: ";
    cin>>n;
    total = n; 
    

    for (int k = 0; k < n; k++) {
        cout << "\n*** Input data for student " << k + 1 << " ***" << endl;
        cout << "Enter your name: ";
        cin >> st[k].name;
        cout << "Enter your ID: ";
        cin >> st[k].ID;
        cout << "Enter your age: ";
        cin >> st[k].age;
        cout << "Enter your email: ";
        cin >> st[k].email;
    }

    while(1){
        cout<<"***\tMenu\t***"<<endl;
        cout<<"a - Display the data from array"<<endl;
        cout<<"b - Add information of 3 more students"<<endl;
        cout<<"c - Search for a student based on email Address"<<endl;
        cout<<"d - Write students info in the array to file"<<endl;
        cout<<"e - Update a Student information based on ID"<<endl;
        cout<<"f - Exit the program"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 'a':
                for (int k = 0; k < total; k++) {
                    cout << "\n*** Display Student's N."<<k+1<<" Data *** "<<endl;
                    cout << st[k].name << "\t" << st[k].ID << "\t" << st[k].age << "\t" << st[k].email <<endl;
            }
            break;

            case 'b':
                for (int k = total; k < total+1; k++) {
                    cout << "\n*** Input data for student " << k + 1 << " ***" << endl;
                    cout << "Enter your name: ";
                    cin >> st[k].name;
                    cout << "Enter your ID: ";
                    cin >> st[k].ID;
                    cout << "Enter your age: ";
                    cin >> st[k].age;
                    cout << "Enter your email: ";
                    cin >> st[k].email;
            }
            total +=3;
            break;

            case 'c': {
                cout<<"\nEnter email to search: ";
                cin>>searchEmail;
                bool found = false;
            for (int k=0; k < total+4; k++) {
                if ( searchEmail == st[k].email ) {
                    cout << st[k].name << "\t" << st[k].ID << "\t" << st[k].age << "\t" << st[k].email <<endl;
                    found = true;
                    break;
                }
            } 
                if (!found) {
                    cout<<"Not found"<<endl;
                }
                break;
            }

            case 'd':
                file.open("StudentData.txt", ios::out);
            
                if(!file) {
                    cout<<"Error opening";
                    return 1;
                }

                for ( int k = 0; k < total; k++) {
                    file << st[k].name << " " << st[k].ID << " " << st[k].age << " " << st[k].email << endl;
                }
            file.close();
            cout<<"Student data saved to file successfully.\n";
            break;
            
            case 'e': { // Update student data based on ID
                int updateID;
                cout << "Enter the ID of the student you want to update: ";
                cin >> updateID;
                bool updated = false;

                for (int k = 0; k < total; k++) {
                    if (st[k].ID == updateID) {
                        cout << "Enter new name: ";
                        cin >> st[k].name;
                        cout << "Enter new age: ";
                        cin >> st[k].age;
                        cout << "Enter new email: ";
                        cin >> st[k].email;
                        cout << "Student data updated successfully!\n";
                        updated = true;
                        break;
                    }
                }

                if (!updated) {
                    cout << "Student ID not found!\n";
                }
                break;
            }

            case 'f':
                cout << "Exiting program...\n";
                exit(0);
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
