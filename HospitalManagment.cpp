#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct patient {
    string name;
    string id;
    int age;
    string appointment_date;
};

struct staff {
    string name;
    string id;
    string role;
};

struct billing {
    string patient_id;
    float amount;
    string status;
};

int main() {
    const int MAX_RECORDS = 200; // Maximum number of records
    patient patients[MAX_RECORDS]; // Array to store patient records
    staff staffs[MAX_RECORDS]; // Array to store staff records
    billing billings[MAX_RECORDS]; // Array to store billing records
    int patient_count = 0, staff_count = 0, billing_count = 0;
    string patient_id;

    while (true) {
        int choice1;
        cout << "Welcome to the Hospital Management System" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Staff Management" << endl;
        cout << "3. Billing Management" << endl;
        cout << "4. Reports and Statistics" << endl;
        cout << "5. Feedback" << endl;
        cout << "6. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice1;

        switch (choice1) {
            case 1: {
                cout << "Patient Management" << endl;
                int choice2;
                cout << "1. Patient Registration" << endl;
                cout << "2. Schedule Appointment" << endl;
                cout << "3. Check Appointment Records" << endl;
                cout << "4. Electronic Medical Records" << endl;
                cout << "5. Exit" << endl;
                cout << "Please enter your choice: ";
                cin >> choice2;

                switch (choice2) {
                    case 1: {
                        cout << "Patient Registration" << endl;
                        if (patient_count < MAX_RECORDS) {
                            cout << "Enter Patient Name: ";
                            cin.ignore(); // Clear buffer
                            getline(cin, patients[patient_count].name);

                            cout << "Enter Patient ID: ";
                            cin >> patients[patient_count].id;

                            // Check for existing ID
                            bool exists = false;
                            for (int i = 0; i < patient_count; i++) {
                                if (patients[i].id == patients[patient_count].id) {
                                    exists = true;
                                    break;
                                }
                            }
                            if (exists) {
                                cout << "Patient ID already exists. Please enter a different ID." << endl;
                                break;
                            }

                            cout << "Enter Patient Age: ";
                            cin >> patients[patient_count].age;
                            fstream patientfile;
                            patientfile.open("Patient Record.txt", ios::app);
                            if(patientfile.is_open()){
                                if(patient_count == 0){
                                    patientfile << "Patient Name" << "\t"
                                                << "ID" << "\t"
                                                << "Age" << "\n";
                                }
                                patientfile << patients[patient_count].name << "\t"
                                            << patients[patient_count].id  << "\t"
                                            << patients[patient_count].age << "\n";
                            }

                            cout << "Patient registered successfully!" << endl;
                            cout << "Patient ID: " << patients[patient_count].id << endl;
                            patient_count++;
                        } else {
                            cout << "Patient records are full." << endl;
                        }
                        break; // Add break here
                    }
                    case 2: {
                        cout << "Schedule Appointment" << endl;
                        cout << "Enter Patient ID: ";
                        cin >> patient_id;
                        bool found = false;
                        for (int i = 0; i < patient_count; i++) {
                            if (patients[i].id == patient_id) {
                                found = true;
                                cout << "Enter Appointment Date (YYYY-MM-DD): ";
                                cin >> patients[i].appointment_date;
                                cout << "Appointment scheduled successfully!" << endl;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Patient not found." << endl;
                        }
                        break; // Add break here
                    }
                    case 3:
                        cout << "Check Appointment Records" << endl;
                        // Add appointment records checking code here
                        break; // Add break here
                    case 4:
                        cout << "Electronic Medical Records" << endl;
                        // Add EMR code here
                        break; // Add break here
                    case 5:
                        cout << "Exiting..." << endl;
                        return 0; // Exit the program
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break; // Add break here
            }
            case 2: {
                cout << "Staff Management" << endl;
                int choice3;
                cout << "1. Staff Registration" << endl;
                cout << "2. Schedule Shifts" << endl;
                cout << "3. Exit" << endl;
                cout << "Please enter your choice: ";
                cin >> choice3;

                switch (choice3) {
                    case 1:
                        cout << "Staff Registration" << endl;
                        // Add staff registration code here
                        break;
                    case 2:
                        cout << "Schedule Shifts" << endl;
                        // Add shift scheduling code here
                        break;
                    case 3:
                        cout << "Exiting..." << endl;
                        return 0; // Exit the program
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break; // Add break here
            }
            case 3:
                cout << "Billing Management" << endl;
                int choice4;
                cout << "1. Generate Bill" << endl;
                cout << "2. Insurance Claims" << endl;
                cout << "3. Payment Processing" << endl;
                cout << "4. Exit" << endl;
                cout << "Please enter your choice: ";
                cin >> choice4;

                switch (choice4) {
                    case 1:
                        cout << "Generate Bill" << endl;
                        // Add bill generation code here
                        break;
                    case 2:
                        cout << "Insurance Claims" << endl;
                        // Add insurance claims code here
                        break;
                    case 3:
                        cout << "Payment Processing" << endl;
                        // Add payment processing code here
                        break;
                    case 4:
                        cout << "Exiting..." << endl;
                        return 0; // Exit the program
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break; // Add break here
            case 4:
                cout << "Reports and Analytics" << endl;
                int choice5;
                cout << "1. Patient Statistics" << endl;
                cout << "2. Staff Performance" << endl;
                cout << "3. Financial Reports" << endl;
                cout << "4. Exit" << endl;
                cout << "Please enter your choice: ";
                cin >> choice5;

                switch (choice5) {
                    case 1:
                        cout << "Patient Statistics" << endl;
                        // Add patient statistics code here
                        break;
                    case 2:
                        cout << "Staff Performance" << endl;
                        // Add staff performance code here
                        break;
                    case 3:
                        cout << "Financial Reports" << endl;
                        // Add financial reports code here
                        break;
                    case 4:
                        cout << "Exiting..." << endl;
                        return 0; // Exit the program
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break; // Add break here
            case 5:
                cout << "Feedback" << endl;
                int choice6;
                cout << "1. Patient Feedback on Staff Handling" << endl;
                cout << "2. Patient Feedback on Facilities" << endl;
                cout << "3. Staff Feedback on Management" << endl;
                cout << "4. Exit" << endl;
                cout << "Please enter your choice: ";
                cin >> choice6;

                switch (choice6) {
                    case 1:
                        cout << "Patient Feedback on Staff Handling" << endl;
                        // Add feedback code here
                        break;
                    case 2:
                        cout << "Patient Feedback on Facilities" << endl;
                        // Add feedback code here
                        break;
                    case 3:
                        cout << "Staff Feedback on Management" << endl;
                        // Add feedback code here
                        break;
                    case 4:
                        cout << "Exiting..." << endl;
                        return 0; // Exit the program
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break; // Add break here
            case 6:
                cout << "Exiting..." << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
