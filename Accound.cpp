#include <iostream>
#include <string>
#include <fstream>
#include "Accound.h"
#include "security.h"
#include <vector>
#include "Transection.h"


using namespace std;

Account::Account(){

    fstream file("Account_details.txt",ios::in);
    if(!file.is_open()){
        file.close();
    }
    else{
        string line;
        while(getline(file,line)){
            arr.push_back(line);
        i++;
        }
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
            /*for(int j=0;c<c+3;j++){
                cout<<arr[c-3+j]<<endl;
            }*/
            int p=c-3;
            while(p<c+2){
                cout<<arr[p]<<endl;
            p++;
           }
           cin.ignore(1000, '\n');
           getchar();
           exit(0);
        }
        else{
            c=c+7;
            continue;
        }
    }
        this->NIC_number=NIC_number;
}
void Account::phone_number_check(int phone_number){
    fstream file("Account_details.txt",ios::in);
    int b=2;
    while(b<=i){
        if(arr[b]==string("Phone Number:")+to_string(phone_number)){
            cout<<"You already have an account"<<endl;
            cout<<"This is your existing account details:"<<endl;
            /*for(int j=0;b<b+3;j++){
                cout<<arr[b-2+j]<<endl;
            }*/
           int p=b-2;
           while(p<b+3){
            cout<<arr[p]<<endl;
            p++;
           }
           cin.ignore(1000, '\n');
           getchar();
           exit(0);
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
            cout<<"Password is strong."<<endl;
            this->password=password;
            break;
        }
        else{
            cout<<"Password is weak. Please enter a strong password: ";
            cin>>password;
        }
    }
}
void Account::account_id_assign(){
    if(arr.empty()){
        account_id = 1000;
    }
    else{
        int u=i/7;
        account_id=1000+u;
    }
}

void Account::update_details(int account_id){   
    int a=0;
    while(a<i){
        if(arr[a]==string("Account ID:") + to_string(account_id)){
            break;
        }
        else{
            a=a+7;
            continue;
        }
    }
    this->account_id=account_id;
    cout<<"Enter the psassword to continue: ";
    cin>>password;
    int res=check(password);
    if(res==0){
        while(true){
            cout<<"which detail do you want to update?"<<endl;
            cout<<"1. Full Name"<<endl; 
            cout<<"2. Phone Number"<<endl;
            cout<<"3. NIC Number"<<endl;
            cout<<"4. Nationality"<<endl;
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
                
            }
            else if(choice==2){
                cout<<"Enter new phone number: ";
                cin>>phone_number;
                phone_number_check(phone_number);
                arr[a+2]=string("Phone Number:")+to_string(phone_number);
            }
            else if(choice==3){
                cout<<"Enter new NIC number: ";
                cin>>NIC_number;
                nic_check(NIC_number);
                arr[a+3]="NIC Number:"+NIC_number;
            }
            else if(choice==4){
                cout<<"Enter new ethnicity: ";
                cin>>nationality;
                arr[a+4]="nationality:"+nationality;
            }
            else if(choice==5){
                cout<<"Enter new password: ";
                cin>>password;
                password_check(password);
                arr[a+5]="Password:"+password;
                
            }
            else{
                cout<<"Invalid choice."<<endl;
            }
            cout<<"Do you want to update more details? (y/n): ";
            char ch;
            cin>>ch;
            if(ch=='y'){
                continue;
            }
            else{
                fstream file("Account_details.txt",ios::out);
                for(int f=0;f<i;f++){
                    file<<arr[f]<<endl;
                }
                cout<<"Details updated successfully."<<endl;
                file.close();
                break; 
            }
        }
    }
}
void Account::delete_account(int account_id){
    this->account_id=account_id;
    cout<<"Enter the psassword to continue: ";
    string pwd; 
    cin>>pwd;
    int res=check(pwd);
    if(res==0){
        int d=0;
        int e=0;
        vector <string> temp_arr;
        while(d<i){
            if(arr[d]==string("Account ID:")+to_string(account_id)){
                d=d+7;
            }
            else{
                temp_arr.push_back(arr[d]);
                d++;
                e++;
            }
        }
        fstream file("Account_details.txt",ios::out);
        for(int f=0;f<e;f++){
                file<<temp_arr[f]<<endl;
        }
        file.close();
    }
}
void Account::account_make(){
    cout<<"Account ID: "<<account_id<<endl;
    cout<<"Full Name: "<<fullname<<endl;
    cout<<"Phone Number: "<<phone_number<<endl;
    cout<<"NIC Number: "<<NIC_number<<endl;
    cout<<"Nationality: "<<nationality<<endl;
    cout<<"Password: "<<password<<endl;

    
    //cout<<id<<endl;

    arr.push_back(string("Account ID:") + to_string(account_id) + "\n");
    arr.push_back(string("Full Name:") + fullname + "\n");
    arr.push_back(string("Phone Number:") + to_string(phone_number) + "\n");
    arr.push_back(string("NIC Number:") + NIC_number + "\n");
    arr.push_back(string("Nationality:") + nationality + "\n");
    arr.push_back(string("Password:") + password + "\n");
    arr.push_back(string("")+"\n");
    i=i+7;

    fstream file("Account_details.txt",ios::app);
    for(int j=i-7;j<arr.size();j++){
        file<<arr[j];
    }
    file.close();
    cin.ignore(1000, '\n');
    cin.get();

}
void Account::account_view(int account_id){
    this->account_id=account_id;
    cout <<"Enter your accound password: ";
    string pwd;
    cin>>pwd;
    int res=check(pwd);
    if(res==0){
        int o=0;
        vector <string> temp1;
        while(o<i){
            if(arr[o]==string("Account ID:")+to_string(account_id)){
                for(int p=0+o;p<6+o;p++){
                    temp1.push_back(arr[p]);
                }
                o=0;
                while(o<transection::z){
                    if(transection::arr1[o]==account_id){
                        for(int p=o+1; p<2+o;p++){
                            temp1.push_back(string("Your Accound Balace :")+to_string(transection::arr1[p]));
                        }
                        break;
                    }
                    else{
                        o+=2;
                        continue;
                    }
                }
                for(int y=0;y<temp1.size();y++){
                    cout<<temp1[y]<<endl;
                }
                cout<<"press enter to close"<<endl;
                cin.ignore(1000, '\n');
                getchar();
                break;
            }
            else{
                o+=7;
                continue;
            }
        }
    }
}

vector <string> Account::arr;
int Account::i=0;
int Account::account_id=0;
string Account::password="";
