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
}