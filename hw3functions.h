//************************************************************************************************************************************************************
//team #9           CSCI/CMPE1370             SPRING 2020        HOMEWORK #3
//SEBASTIAN THOMAS 
//NATHAN LOZANO 
//this program was created to be able to perform different  elementary functions such as a calculator would do with fractions such as addition and subtraction.
//the use of euclids theorem was thoroughly used, not to its full capacity but taking ist main objective and applying it in our code
//************************************************************************************************************************************************************

#include <iostream>
#include <sstream>
#include <unistd.h>
using namespace std;
char cont = 'y', choice;
//the code packages inputted above is what allows us to use certain funcytions in our code below
void showMenu(){
    //the following fuctions wil display the menu for our program 
    cout << "Ration numbers calculator" << endl;
    cout << "(A)ddition" << endl << "(S)ubtraction" << endl << "(Q)uit" << endl;
    cout << "Enter your option: ";
}


void getRational(int *num, int *den){
    string numstring, denstring, str;
    cout << "Please enter a fraction (n/d): ";
    cin >> str;
    stringstream stream1(str);
    getline(stream1, numstring, '/');
    getline(stream1, denstring, '/');
    *num = stoi(numstring);
    *den = stoi(denstring);
    if(*den == 0)
        system("EXIT");
}

void reduce(int *num, int *den){
    int x = *num % *den;
    int a = *num, b = *den;
    while(x != 0){
        a = b;
        b = x;
        x = a % b;
        //cout << x;
    }
    //divides gcf of num value and den values
    *num /= b;
    *den /= b;
}

void DisplayRational(int *inum, int *iden){
    reduce(inum, iden);
    if(*iden < 0)
        *inum *= -1, *iden *= -1;
    if(*inum == *iden && choice == 'a')
        cout << "1";
    else if(*inum == *iden && choice == 's')
        cout << "0";
    else
        if(*inum == 0)
            cout << "0";
        else
            cout << *inum << "/" << *iden;
}

void addRational(int num1, int den1, int num2, int den2, int *inum, int *iden){
    reduce(&num1, &den1); //reduces num and den for first fraction
    reduce(&num2, &den2); //reduces num and den for second fraction
    *inum = (num1 * den2) + (num2 * den1); 
    *iden = den1 * den2;
    DisplayRational(inum, iden); //function to display the result
}

void subtractRational(int num1, int den1, int num2, int den2, int *inum, int *iden){
    reduce(&num1, &den1);
    reduce(&num2, &den2);
    *inum = (num1 * den2) - (num2 * den1);
    *iden = den1 * den2;
    DisplayRational(inum, iden);
}
//the follwing add function will allow for the addition of the fractions being inputted by the user 
void add(){
    choice = 'a';
    while(cont == 'Y' || cont == 'y'){
    int num1, num2, den1, den2, inum, iden;
    system("CLS");
    cout << "Addition of rational numbers" << endl;
    getRational(&num1, &den1);
    getRational(&num2, &den2);
    //gets num and den in int values
    addRational(num1, den1, num2, den2, &inum, &iden);//adds values
    cout << endl << "Do you want to do more additions?(Y/N) ";
    cin >> cont;
    }
}
//the following fuction will allow for the subtraction of fractions as selected by the user 
void subtract(){
    choice = 's';
    while(cont == 'Y' || cont == 'y'){
    int num1, num2, den1, den2, inum, iden;
    system("CLS");
    cout << "Subtraction of rational numbers" << endl;
    getRational(&num1, &den1);
    getRational(&num2, &den2);
    //gets num and den in int values
    subtractRational(num1, den1, num2, den2, &inum, &iden);
    cout << endl << "Do you want to do more subtractions?(Y/N) ";
    cin >> cont;
    }
}
