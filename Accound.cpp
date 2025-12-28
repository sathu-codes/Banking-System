#include <iostream>
#include <string>
#include "Accound.h"
#include "security.h"

using namespace std;


void Account::name_assign(){
    string full_name = firstname + " " + lastname;
    fullname = full_name;
}
void Account::nic_check(string NIC_number){

}
void Account::phone_number_check(string phone_number){

}
void Account::password_check(string password){
    while(true){
        check_security cs;
        int result = cs.check(password);
        if(result==1){
            this->password=password;
            cout<<"Password is strong."<<endl;
            break;
        }
        else{
            cout<<"Password is weak. Please enter a strong password: ";
            cin>>password;
        }
    }
}
void Account::update_details(int account_id){

}
void Account::delete_account(int account_id){

}
void Account::account_details(){
    cout<<"Account ID: "<<account_id<<endl;
    cout<<"Full Name: "<<fullname<<endl;
    cout<<"Phone Number: "<<phone_number<<endl;
    cout<<"NIC Number: "<<NIC_number<<endl;
    cout<<"Ethnicity: "<<ethnicity<<endl;
}