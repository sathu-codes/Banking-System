#include <iostream>
#include <string>
#include "security.h"
#include "Accound.h"

using namespace std;

int strength_level(string pwd){
    if(pwd.length()>8){
        return 1;
    }
    else{
        return 0;
    }
    
}

int check(string password){
    int k=0;
    for(k=0;k<=Account::i;k=k+7){
        if(Account::arr[k]==string("Account ID:") + to_string(Account::account_id) && Account::arr[k+5]==string("Password:") + password){
            cout<<"Login successful."<<endl;
            return 0;
            break;
        }
    }
    cout<<"Incorrect password or Account ID."<<endl;
    return 1;
}


