#include <iostream>
#include "hw3functions.h"
using namespace std;
char userchoice, cont = 'Y';


int main(){
    showMenu();
    cin >> userchoice;
    if(userchoice == 'A' || userchoice == 'a')
        add();
    else if(userchoice == 'S' || userchoice == 's')
        subtract();
    else
        exit;
}



