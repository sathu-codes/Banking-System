#include <iostream>
#include <string>
#include "Accound.h"
#include <fstream>
#include <vector>
#include "security.h"
#include "Transection.h"

using namespace std;

transection::transection(){
    fstream file("Account_details.txt",ios::in);
    while(file>>arr1[z]){
        z++;
    }
}
void transection::deposite_withrowal(int account_id,string password){
    Account::password = password;
    Account::account_id = account_id;

    if(Account::arr[x]=="Account ID:"+to_string(account_id) && Account::arr[x+6]=="Password:"+password){
        cout<<"1. Deposite"<<endl;
        cout<<"2. Withdrawal"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        while(true){
            int q=0;
            if(choice==1 && arr1[q]==account_id){
                cout<<"Enter amount to deposite: ";
                double amount;
                cin>>amount;
                arr1[q+1]+=amount;
                cout<<"You have successfully deposied "<<endl;
            }
            else if(choice==2){
                int q=z;
                cout<<"Enter amount to deposite: ";
                double amount;
                cin>>amount;
                arr1[q+1]=amount;
                cout<<"You have successfully deposied "<<endl;
            }
            else if(choice==2 && arr1[q]==account_id){
                cout<<"Enter amount to withdraw: ";
                double amount;
                cin>>amount;
                cout<<"You have successfully withdrawn "<<amount<<endl;
            }
            else{
                cout<<"Invalid choice."<<endl;
            }
            cout<<"Do you want to perform more transactions? (y/n): ";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                q=0;
                continue;
            }
            else{
                fstream file("Account_balance.txt",ios::out);
                for(int j=0;j<=z;j++){
                    file<<arr1[j]<<endl;
                }
                file.close();
                break;
            }
        }
    }
}