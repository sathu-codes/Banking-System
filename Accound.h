#ifndef ACCOUND_H
#define ACCOUND_H


#include <string>
#include <fstream>
#include <vector>

using namespace std;


class Account{
    public:
        static vector <string> arr;
        static int i;
        static int account_id;
        static string password;
        string firstname;
        string lastname;
        string fullname;
        int phone_number;
        string NIC_number;
        string nationality;
        Account();
        /*Account(string firstname, string lastname, string phone_number, string NIC_number, string ethnicity, string password){
            this->firstname = firstname;
            this->lastname = lastname;
            this->ethnicity = ethnicity;
            
        }*/
        void name_assign();
        void nic_check(string NIC_number);
        void phone_number_check(int phone_number);
        void password_check(string password);
        void update_details(int account_id);
        void delete_account(int account_id);
        void account_id_assign();
        void account_make();
        void account_view(int account_id);
};

#endif