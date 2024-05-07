#include <iostream>
#include "Person.h"
#include "IndividualCandidate.h"
#include "Address.h"
#include "RegistrationIndividualCandidates.h"
#include "userInterface.h"
using namespace std;

int main() {

    int input;
    char processFinished;
    do{
        system("clear");
        cout << "           Individual Candidate Module         " << endl;
        cout << "1. Register." << endl;
        cout << "2. Login." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter your choice :";
        cin >> input;
        RegistrationIndividualCandidates *registrationIndividualCandidates = RegistrationIndividualCandidates::getInstance();
        switch(input){
            case 1:{
                string username,password,name,gender,address,cnic,dob;
                cin.ignore();
                cout << "Enter your Name :";
                getline(cin,name);
                cout << "Enter your CNIC :";
                getline(cin,cnic);
                cout << "Enter your Gender :";
                getline(cin,gender);
                cout << "Enter your Date of Birth :";
                getline(cin,dob);
                cout << "Enter your address :";
                getline(cin,address);
                cout << "Enter your username :";
                getline(cin,username);
                cout << "Enter your password :";
                getline(cin,password);
                Address address1;
                address1.setConcatenatedAddress(address);
                auto *individual = new IndividualCandidate(username,password,name,cnic,dob,gender,address1);
                registrationIndividualCandidates->registerIndividualCandidate(individual);
                break;
            }
            case 2:{
                string username,password;
                cout  << "Enter username :";
                cin >> username;
                cout << "Enter Password :";
                cin >> password;
                registrationIndividualCandidates->loginCandidate(username,password);
                break;
            }
            default:{
                cout << "Invalid Input. Please enter valid input...." << endl;
                break;
            }
        }
        cout << "Do you want to continue(Y/N) :";
        cin >> processFinished;
    }while(processFinished == 'Y' || processFinished == 'y');
    return 0;
}
