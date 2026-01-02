#include <iostream>
#include <string>
#include "Accound.h"
#include "transection.h"

using namespace std;

int main(){
    Account acc;
    transection r;
    int choice;
    cout << "Welcome to the Banking System" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Create Account" << endl;    
    cout << "2. Update Account Details" << endl;
    cout << "3. Delete Account" << endl;
    cout << "4. View Account Details" << endl;
    cout << "5. Perform Transactions" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice==1){

        cout<<"Enter your first name: ";
        getline(cin,acc.firstname);
        cin.ignore(1000,'\n');
        cout<<"Enter your last name: ";
        getline(cin,acc.lastname);
        acc.name_assign();

        cout<<"Enter your phone number: ";
        cin>>acc.phone_number;
        acc.phone_number_check(acc.phone_number);

        cout<<"Enter your NIC number: ";
        cin>>acc.NIC_number;
        acc.nic_check(acc.NIC_number);

        cout<<"Enter your Nationality: ";
        getline(cin,acc.nationality);
        cin.ignore(1000,'\n');
        cout<<"Create a password: ";
        cin>>acc.password;

        acc.password_check(acc.password);
         acc.account_id_assign();
         acc.account_make();
        //Account acc(acc.firstname,acc.lastname,acc.phone_number,acc.NIC_number,acc.ethnicity,acc.password);
        
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
        acc.account_view(account_id);
    }
    else if(choice==5){
        cout<<"Enter your account ID: ";
        int account_id;
        cin>>account_id;
        cout<<"Enter your password: ";
        string password;
        cin>>password;
        transection t;
        t.deposite_withrowal(account_id,password);
    }
}


