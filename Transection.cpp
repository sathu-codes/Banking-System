#include <iostream>
#include <string>
#include "Accound.h"
#include <fstream>
#include <vector>
#include "security.h"
#include "Transection.h"

using namespace std;

transection::transection(){
    fstream file("Account_balance.txt",ios::in);
    int u=0;
    int line;
    if(file.peek() == ifstream::traits_type::eof()){
        file.close();
    }
    else{
        while(file>>line){
            arr1.push_back(line);
            z++;
        }
    }
}
void transection::deposite_withrowal(int account_id,string password){
    Account::password = password;
    Account::account_id = account_id;
    int choice=0;
    while(x<=Account::i){
        if(Account::arr[x]==string("Account ID:") + to_string(Account::account_id) && Account::arr[x+5]==string("Password:") + password){
            cout<<"1.Deposite"<<endl;
            cout<<"2.Withdrawal"<<endl;
            cout<<"3.Fist time deposite"<<endl;
            cout<<"Enter your choice: ";
            int ammound=0;
            cin>>choice;
            int r=0;
            if(choice==1 || choice==2){
                while(r<z){
                    if(arr1.empty()){
                        break;
                    }
                    else{
                        if(arr1[r]==account_id){
                            if(choice==1){
                                cout<<"Enter the amound to deposite :"<<endl;
                                cin >> ammound;
                                cout <<ammound<<endl;
                                arr1[r+1]+=ammound;
                                break;
                            }
                            else if(choice==2){
                                cout<<"Enter the amound to whithrow :"<<endl;
                                cin >> ammound;
                                if(ammound<=arr1[r+1]){
                                    arr1[r+1]-=ammound;
                                    break;
                                }
                                else{
                                    cout<<string("Avilable balance:")+to_string(arr1[r+1])<<endl;
                                    break;
                                }
                            }
                        }
                        else{
                            r+=2;
                        }
                    }
                }
                break;
            }
            else if(choice==3){
                cout<<"Enter the ammoud to deposite"<<endl;
                cin >> ammound;
                arr1.push_back(account_id);
                arr1.push_back(ammound);
                z+=2 ;
                break;
            }
            cout<<"visit view account to check balance"<<endl;
            cin.ignore(1000,'\n');
            cin.get();
        }
        else{
            x+=7;
            continue;
        }
    }
    if(x>Account::i){
            cout<<"There is no accound id left"<<endl;
    }
    if(x<=Account::i){
        if(choice==3){
            fstream file("Account_balance.txt",ios::out);
            for(int j=0;j<z;j++){
                cout<<arr1[j]<<endl;
                file<<arr1[j]<<endl;
            }
            file.close();
        }
        else{
            fstream file("Account_balance.txt",ios::out);
            for(int j=0;j<z;j++){
                file<<arr1[j]<<endl;
            }
            file.close();
            cout<<"visit view account to check balance"<<endl;
            cin.ignore(1000,'\n');
            cin.get();
        }
    }
}


int transection::z=0;
int transection::x=0;
vector <int> transection::arr1;