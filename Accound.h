#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        string firstname;
        string lastname;
        string fullname;
        string phone_number;
        string NIC_number;
        string ethnicity;
        string password;
        int account_id;

    public:     
        Account(string name, string phone_number, string NIC_number, string ethnicity, string password){
            this->firstname = firstname;
            this->lastname = lastname;
            this->phone_number = phone_number;
            this->NIC_number = NIC_number;
            this->ethnicity =   ethnicity;
            this->password = password;
        }
            void name_assign();
            void nic_check(string NIC_number);
            void phone_number_check(string phone_number);
            void password_check(string password);
            void update_details(int account_id);
            void delete_account(int account_id);
            int account_id_assign();
            void account_details();
};
