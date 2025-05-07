#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

struct patient
{
    string name;
    string id;
    int age;
    string appointment_date;
};

struct staff
{
    string name;
    string id;
    string role;
};

struct billing
{
    string patient_id;
    float amount;
    string status;
};

int main()
{
    const int MAX_RECORDS = 200;   // Maximum number of records
    patient patients[MAX_RECORDS]; // Array to store patient records
    staff staffs[MAX_RECORDS];     // Array to store staff records
    billing billings[MAX_RECORDS]; // Array to store billing records
    int patient_count = 0, staff_count = 0, billing_count = 0;
    string patient_id;

    while (true)
    {
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

        switch (choice1)
        {
        case 1:
        {
            cout << "Patient Management" << endl;
            int choice2;
            cout << "1. Patient Registration" << endl;
            cout << "2. Schedule Appointment" << endl;
            cout << "3. Check Appointment Records" << endl;
            cout << "4. Electronic Medical Records" << endl;
            cout << "5. Exit" << endl;
            cout << "Please enter your choice: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                cout << "Patient Registration" << endl;
                if (patient_count < MAX_RECORDS)
                {
                    cout << "Enter Patient Name: ";
                    cin.ignore(); // Clear buffer
                    getline(cin, patients[patient_count].name);

                    cout << "Enter Patient ID: ";
                    cin >> patients[patient_count].id;

                    // Check for existing ID
                    bool exists = false;
                    for (int i = 0; i < patient_count; i++)
                    {
                        if (patients[i].id == patients[patient_count].id)
                        {
                            exists = true;
                            break;
                        }
                    }
                    if (exists)
                    {
                        cout << "Patient ID already exists. Please enter a different ID." << endl;
                        break;
                    }

                    cout << "Enter Patient Age: ";
                    cin >> patients[patient_count].age;
                    fstream patientfile;
                    patientfile.open("Patient Record.txt", ios::app);
                    if (patientfile.is_open())
                    {
                        if (patient_count == 0)
                        {
                            patientfile << "Patient Name" << "\t"
                                        << "ID" << "\t"
                                        << "Age" << "\n";
                        }
                        patientfile << patients[patient_count].name << "\t"
                                    << patients[patient_count].id << "\t"
                                    << patients[patient_count].age << "\n";
                    }

                    cout << "Patient registered successfully!" << endl;
                    cout << "Patient ID: " << patients[patient_count].id << endl;
                    patient_count++;
                }
                else
                {
                    cout << "Patient records are full." << endl;
                }
                break; // Add break here
            }
            case 2:
            {
                cout << "Schedule Appointment" << endl;
                cout << "Enter Patient ID: ";
                cin >> patient_id;
                bool found = false;
                for (int i = 0; i < patient_count; i++)
                {
                    if (patients[i].id == patient_id)
                    {
                        found = true;
                        cout << "Enter Appointment Date (YYYY-MM-DD): ";
                        cin >> patients[i].appointment_date;
                        cout << "Appointment scheduled successfully!" << endl;
                        break;
                    }
                }
                if (!found)
                {
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
        case 2:
        {
            cout << "Staff Management" << endl;
            int choice3;
            cout << "1. Staff Registration" << endl;
            cout << "2. Schedule Shifts" << endl;
            cout << "3. Exit" << endl;
            cout << "Please enter your choice: ";
            cin >> choice3;

            switch (choice3)
            {
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
            while (true)
            { // Loop to allow returning to Billing Management or Main Menu
                int choice4;
                cout << "\n========== Billing Management ==========" << endl;
                cout << "1. Generate Bill" << endl;
                cout << "2. Insurance Claims" << endl;
                cout << "3. Payment Processing" << endl;
                cout << "4. View All Billing Records" << endl;
                cout << "5. Exit to Main Menu" << endl;
                cout << "========================================" << endl;
                cout << "Please enter your choice: ";
                cin >> choice4;

                switch (choice4)
                {
                case 1:
                {
                    cout << "\n--- Generate Bill ---" << endl;
                    cout << "Enter Patient ID: ";
                    cin >> billings[billing_count].patient_id;

                    // Check if the patient exists
                    bool patient_found = false;
                    for (int i = 0; i < patient_count; i++)
                    {
                        if (patients[i].id == billings[billing_count].patient_id)
                        {
                            patient_found = true;
                            break;
                        }
                    }

                    if (!patient_found)
                    {
                        cout << "Patient not found. Please register the patient first." << endl;
                        break;
                    }

                    // Input validation for bill amount
                    cout << "Enter Bill Amount: ";
                    while (!(cin >> billings[billing_count].amount) || billings[billing_count].amount <= 0)
                    {
                        cout << "Invalid amount. Please enter a positive number: ";
                        cin.clear();
                    }

                    // Default status for a new bill
                    billings[billing_count].status = "Unpaid";

                    // Save the bill to a file
                    fstream billingFile("Billing Records.txt", ios::in | ios::out | ios::app);
                    if (billingFile.is_open())
                    {
                        // Write header if the file is empty
                        billingFile.seekp(0, ios::end);
                        if (billingFile.tellp() == 0)
                        {
                            billingFile << "Patient ID" << "\t"
                                        << "Amount" << "\t"
                                        << "Status" << "\n";
                        }
                        billingFile << billings[billing_count].patient_id << "\t"
                                    << fixed << setprecision(2) << billings[billing_count].amount << "\t"
                                    << billings[billing_count].status << "\n";
                        billingFile.close();
                    }
                    else
                    {
                        cout << "Error: Unable to open billing file." << endl;
                    }

                    cout << "Bill generated successfully!" << endl;
                    billing_count++;
                    break;
                }
                case 2:
                {
                    cout << "\n--- Insurance Claims ---" << endl;
                    cout << "Enter Patient ID: ";
                    cin >> patient_id;

                    // Check if the patient has a bill
                    bool bill_found = false;
                    for (int i = 0; i < billing_count; i++)
                    {
                        if (billings[i].patient_id == patient_id)
                        {
                            bill_found = true;
                            cout << "Processing insurance claim for Patient ID: " << patient_id << endl;
                            cout << "Bill Amount: " << fixed << setprecision(2) << billings[i].amount << endl;

                            // Simulate insurance claim approval
                            cout << "Insurance claim approved for the full amount." << endl;
                            billings[i].status = "Paid (Insurance)";
                            break;
                        }
                    }

                    if (!bill_found)
                    {
                        cout << "No bill found for the given Patient ID." << endl;
                    }
                    break;
                }
                case 3:
                {
                    cout << "\n--- Payment Processing ---" << endl;
                    cout << "Enter Patient ID: ";
                    cin >> patient_id;

                    // Check if the patient has a bill
                    bool bill_found = false;
                    for (int i = 0; i < billing_count; i++)
                    {
                        if (billings[i].patient_id == patient_id)
                        {
                            bill_found = true;
                            cout << "Processing payment for Patient ID: " << patient_id << endl;
                            cout << "Bill Amount: " << fixed << setprecision(2) << billings[i].amount << endl;

                            // Input validation for payment amount
                            float payment;
                            cout << "Enter payment amount: ";
                            while (!(cin >> payment) || payment <= 0)
                            {
                                cout << "Invalid amount. Please enter a positive number: ";
                                cin.clear();
                                cin.ignore();
                            }

                            if (payment >= billings[i].amount)
                            {
                                cout << "Payment successful! Change: " << fixed << setprecision(2) << (payment - billings[i].amount) << endl;
                                billings[i].status = "Paid";
                            }
                            else
                            {
                                cout << "Insufficient payment. Please pay the full amount." << endl;
                            }
                            break;
                        }
                    }

                    if (!bill_found)
                    {
                        cout << "No bill found for the given Patient ID." << endl;
                    }
                    break;
                }
                case 4:
                {
                    cout << "\n--- View All Billing Records ---" << endl;
                    if (billing_count == 0)
                    {
                        cout << "No billing records found." << endl;
                    }
                    else
                    {
                        cout << left << setw(15) << "Patient ID" << setw(10) << "Amount" << setw(15) << "Status" << endl;
                        cout << "----------------------------------------" << endl;
                        for (int i = 0; i < billing_count; i++)
                        {
                            cout << left << setw(15) << billings[i].patient_id
                                 << setw(10) << fixed << setprecision(2) << billings[i].amount
                                 << setw(15) << billings[i].status << endl;
                        }
                    }
                    break;
                }
                case 5:
                    cout << "Exiting Billing Management..." << endl;
                    break; // Exit to Main Menu
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }

                // Ask user whether to return to Billing Management or Main Menu
                char next_action;
                cout << "\nWould you like to return to Billing Management (B) or Main Menu (M)? ";
                cin >> next_action;
                if (next_action == 'M' || next_action == 'm')
                {
                    break; // Exit to Main Menu
                }
            }
            break;

        case 4:
            cout << "Reports and Analytics" << endl;
            int choice5;
            cout << "1. Patient Statistics" << endl;
            cout << "2. Staff Performance" << endl;
            cout << "3. Financial Reports" << endl;
            cout << "4. Exit" << endl;
            cout << "Please enter your choice: ";
            cin >> choice5;

            switch (choice5)
            {
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

            switch (choice6)
            {
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
