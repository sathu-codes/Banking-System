#ifndef TRANSECTION_H
#define TRANSECTION_H

#include <iostream>
#include <string>
#include "accound.h"
#include <vector>
using namespace std;        

class transection{
    public:
        static vector <int> arr1;
        static int z;
        static int x;
    
        transection();
        void deposite_withrowal(int account_id,string password);
};
#endif