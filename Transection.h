#include <iostream>
#include <string>
#include "Accound.h"
#include <vector>
using namespace std;        

class transection{
    public:
        static vector <int> arr1;
        static int z;
        static int x;
    
        transection(){
        }
        void deposite_withrowal(int account_id,string password);
};