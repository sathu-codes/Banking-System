#include <iostream>
#include <string>
#include "security.h"
#include "Accound.h"

using namespace std;

int strength_level(string pwd){
    if(pwd.length()<8){
        return 1;
    }
    else{
        return 0;
    }
    
}

int check(string password){
    int k=0;
    while(true){
        if(Account::arr[k]=="Account ID:"+to_string(Account::account_id)){
            if(Account::arr[k+5]=="Password:"+password){
                cout<<"Login successful."<<endl;
                return 0;
                break;
            }
            else{
                cout<<"Incorrect password or account id try again.. "<<endl;
                return 1;
                cout<<"Do you want to try again? (y/n): ";
                char ch;
                cin>>ch;
                if(ch=='y' || ch=='n'){
                    continue;
                }
                else{
                    break;
                }
            }
        }
    }
} 