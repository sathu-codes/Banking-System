#include <iostream>
#include <string>
#include "Accound.h"
#include "security.h"
#include "Transection.h"

using namespace std;

int main(){
    Account acc;
    cout << "Welcome to the Banking System" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Create Account" << endl;    
    cout << "2. Update Account Details" << endl;
    cout << "3. Delete Account" << endl;
    cout << "4. View Account Details" << endl;
    cout << "5. Perform Transactions" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if(choice==1){
        cout<<"Enter your first name: ";
        cin>>acc.firstname;
        cout<<"Enter your last name: ";
        cin>>acc.lastname;
        cout<<"Enter your phone number: ";
        cin>>acc.phone_number;
        cout<<"Enter your NIC number: ";
        cin>>acc.NIC_number;
        cout<<"Enter your ethnicity: ";
        cin>>acc.ethnicity;
        cout<<"Create a password: ";
        cin>>acc.password;
        //Account acc(acc.firstname,acc.lastname,acc.phone_number,acc.NIC_number,acc.ethnicity,acc.password);
        acc.name_assign();
        acc.phone_number_check(acc.phone_number);
        acc.nic_check(acc.NIC_number);
        acc.password_check(acc.password);
        acc.account_id_assign();
        acc.account_details();
    }
    else if(choice==2){
        cout<<"Enter your account ID: ";
        int account_id;
        cin>>account_id;
        acc.update_details(account_id);
    }
    else if(choice==3){
        cout<<"Enter your account ID: ";
        int account_id;
        cin>>account_id;
        acc.delete_account(account_id);
    }
    else if(choice==4){
        cout<<"Enter your account ID: ";
        int account_id;
        cin>>account_id;
        acc.account_details();
    }
    else if(choice==5){
        transection t;
        cout<<"Enter your account ID: ";
        int account_id;
        cin>>account_id;
        cout<<"Enter your password: ";
        string password;
        cin>>password;
        t.deposite_withrowal(account_id,password);

    }
}

