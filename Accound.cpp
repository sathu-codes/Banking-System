#include <iostream>
#include <string>
#include "Accound.h"
#include "security.h"
#include <vector>

using namespace std;

Account::Account(){
    fstream file("Account_details.txt",ios::out);
    while(getline(file,arr[i])){
        i++;
    }
    file.close();
}

void Account::name_assign(){
    string full_name = firstname + " " + lastname;
    this->fullname = full_name;

}
void Account::nic_check(string NIC_number){
    fstream file("Account_details.txt",ios::in);
    int c=3;
    while(c<=i){
        if(arr[c]=="NIC Number:"+NIC_number){
            cout<<"You already have an account"<<endl;
            cout<<"This is our existing account details:"<<endl;
            for(int j=0;c<c+3;j++){
                cout<<arr[c-3+j]<<endl;
            }
        }
        else{
            c=c+7;
            continue;
        }
    }
        this->NIC_number=NIC_number;
}
void Account::phone_number_check(string phone_number){
    fstream file("Account_details.txt",ios::in);
    int b=2;
    while(b<=i){
        if(arr[b]=="Phone Number:"+phone_number){
            cout<<"You already have an account"<<endl;
            cout<<"This is our existing account details:"<<endl;
            for(int j=0;b<b+3;j++){
                cout<<arr[b-2+j]<<endl;
            }
        }
        else{
            b=b+7;
            continue;
        }
    }
        this->phone_number=phone_number;
}
void Account::password_check(string password){
    while(true){
        int result = strength_level(password);
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
    this->password=password;
}
int Account::account_id_assign(){
    if(arr.empty()){
        account_id = 1000;
    }
    else{
        int u=i/7;
        account_id=1001+u;
    }
    this->account_id=account_id;
}
void Account::update_details(int account_id){
    this->account_id=account_id;
    int a=0;
    cout<<"Enter the psassword to continue: ";
    string pwd; 
    cin>>pwd;
    int res=check(pwd);
    if(res==1){
        while(true){
            if(arr[a]=="Account ID:"+to_string(account_id)){
                while(true){
                    cout<<"which detail do you want to update?"<<endl;
                    cout<<"1. Full Name"<<endl; 
                    cout<<"2. Phone Number"<<endl;
                    cout<<"3. NIC Number"<<endl;
                    cout<<"4. Ethnicity"<<endl;
                    cout<<"5. Password"<<endl;  
                    int choice;
                    cin>>choice;
                    if(choice==1){
                        cout<<"Enter new first name: ";
                        cin>>firstname;
                        cout<<"Enter new last name: ";
                        cin>>lastname;
                        name_assign();
                        arr[a+1]="Full Name:"+fullname;
                        break;
                    }
                    else if(choice==2){
                        cout<<"Enter new phone number: ";
                        cin>>phone_number;
                        phone_number_check(phone_number);
                        arr[a+2]="Phone Number:"+phone_number;
                    }
                    else if(choice==3){
                        cout<<"Enter new NIC number: ";
                        cin>>NIC_number;
                        nic_check(NIC_number);
                        arr[a+3]="NIC Number:"+NIC_number;
                    }
                    else if(choice==4){
                        cout<<"Enter new ethnicity: ";
                        cin>>ethnicity;
                        arr[a+4]="Ethnicity:"+ethnicity;
                    }
                    else if(choice==5){
                        cout<<"Enter new password: ";
                        cin>>password;
                        password_check(password);
                        arr[a+5]="Password:"+password;
                    }
                    else{
                        cout<<"Invalid choice."<<endl;
                        continue;
                    }
                    cout<<"Do you want to update more details? (y/n): ";
                    char ch;
                    cin>>ch;
                    if(ch=='y' || ch=='Y'){
                        continue;
                    }
                }
            }
            else{
                a=a+7;
                continue;
            }  
        }
        fstream file("Account_details.txt",ios::out);
            for(int j=0;j<=i;j++){
                file<<arr[j]<<endl;
            }
            file.close();
    }
}
void Account::delete_account(int account_id){
    this->account_id=account_id;
    cout<<"Enter the psassword to continue: ";
    string pwd; 
    cin>>pwd;
    int res=check(pwd);
    if(res==1){
        int d=0;
        int e=0;
        vector <string> temp_arr;
        while(d<=i){
            if(arr[d]=="Account ID:"+to_string(account_id)){
                d=d+7;
            }
            else{
                temp_arr[e]=arr[d];
                d++;
                continue;
            }
            e++;
        }
        fstream file("Account_details.txt",ios::out);
        for(int f=0;f<=e;f++){
                file<<temp_arr[f]<<endl;
        }
        file.close();
    }
}
void Account::account_details(){
    cout<<"Account ID: "<<account_id<<endl;
    cout<<"Full Name: "<<fullname<<endl;
    cout<<"Phone Number: "<<phone_number<<endl;
    cout<<"NIC Number: "<<NIC_number<<endl;
    cout<<"Ethnicity: "<<ethnicity<<endl;
    cout<<"Password: "<<password<<endl;

    arr[i] = "Account ID:"+account_id;
    arr[i+1] = "Full Name:"+fullname;
    arr[i+2] = "Phone Number:"+phone_number;
    arr[i+3] = "NIC Number:"+NIC_number;
    arr[i+4] = "Ethnicity:"+ethnicity;
    arr[i+5] = "Password:"+password;
    arr[i+6] = "";
    i=i+7;
    fstream file("Account_details.txt",ios::in);
    for(int j=0;j<=i;j++){
        file<<arr[j]<<endl;
    }

}