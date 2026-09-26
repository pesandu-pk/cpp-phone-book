#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits> // added for numeric_limits
using namespace std;// Import the standard namespace to simplify code.

// Define a Contact class to represent individual contacts.
// Task 01: Contact class with attributes and getter methods
class Contact {
private:
    string fullName;
    string phoneNumber;
    string emailAddress;
    string address;
    string birthday;
    string notes;

public:
    // Constructor to initialize contact information
    Contact(const string& name, const string& phone, const string& email,
        const string& addr, const string& bday, const string& note)
        : fullName(name), phoneNumber(phone), emailAddress(email),
        address(addr), birthday(bday), notes(note) {
    }
     // Task 01: Public member functions (getters) to access contact information.
    string getFullName() const { return fullName; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmailAddress() const { return emailAddress; }
    string getAddress() const { return address; }
    string getBirthday() const { return birthday; }
    string getNotes() const { return notes; }

        // Display contact
    void display() const {
        cout << "\n--- Contact Info ---\n";
        cout << "Name: " << fullName << "\nPhone: " << phoneNumber
            << "\nEmail: " << emailAddress << "\nAddress: " << address
            << "\nBirthday: " << birthday << "\nNotes: " << notes << "\n";
    }
};

// Phonebook class to manage the list of contacts
class Phonebook {
private:
//Private member variable to store a vector of contact object
    vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully.\n";
    }
       // Task 02: View all contacts
    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts found.\n";
            return;
        }
        for (const Contact& contact : contacts) {
            contact.display();
        }
    }
// Task 03: Delete contact by name
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getFullName() == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully.\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void saveContactsToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Contact& contact : contacts) {
                file << "Name: " << contact.getFullName() << "\n";
                file << "Phone: " << contact.getPhoneNumber() << "\n";
                file << "Email: " << contact.getEmailAddress() << "\n";
                file << "Address: " << contact.getAddress() << "\n";
                file << "Birthday: " << contact.getBirthday() << "\n";
                file << "Notes: " << contact.getNotes() << "\n\n";
            }
            cout << "Contacts saved to " << filename << " successfully.\n";
            file.close();
        }
        else {
            cerr << "Error: Unable to open file.\n";
        }
    }
    //Task 6 Search contact
    void searchContact(const string& keyword) const {
        bool found = false;
        for (const Contact& contact : contacts) {
            if (contact.getFullName().find(keyword) != string::npos) {
                contact.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No matching contact found.\n";
        }
    }
};

int main() {
    Phonebook phonebook;
    while (true) {
        cout << "\nPhonebook Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Delete Contact\n";
        cout << "4. Save Contacts to File\n";
        cout << "5. Search Contact\n";
        cout << "6. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        //valid choice checker
    if (!(cin >> choice)) {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nInvalid input. Please enter a number between 1 to 6.\n\n";
        continue;
    }
    if (choice < 1 || choice > 6) {
        cout << "\nInvalid choice. please enter a number between 1 to 6. \n\n";
        continue;
    }
    cout << "\n";
    cin.ignore(); 

        switch (choice) {
        case 1: {
         //Task 4:Add a new contact to the phonebook
            string name, phone, email, addr, bday, note;
            cout << "Enter full name: "; getline(cin, name);
            cout << "Enter phone number: "; getline(cin, phone);
            cout << "Enter email: "; getline(cin, email);
            cout << "Enter address: "; getline(cin, addr);
            cout << "Enter birthday: "; getline(cin, bday);
            cout << "Enter notes: "; getline(cin, note);
            Contact newContact(name, phone, email, addr, bday, note);
            phonebook.addContact(newContact);
            break;
        }
        case 2:
        //Task 5:view all the contacts in the phone book
            phonebook.viewContacts();
            break;
        case 3: {
            string name;
            cout << "Enter full name to delete: ";
            getline(cin, name);
            phonebook.deleteContact(name);
            break;
        }
        case 4: {
            string filename;
            cout << "Enter filename to save: ";
            getline(cin, filename);
            phonebook.saveContactsToFile(filename);
            break;
        }
        case 5: {
            string keyword;
            cout << "Enter name to search: ";
            getline(cin, keyword);
            phonebook.searchContact(keyword);
            break;
        }
        case 6:
            cout << "Exiting Phonebook.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
