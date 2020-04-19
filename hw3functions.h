#include <iostream>
#include <sstream>
#include <unistd.h>
using namespace std;
char cont = 'y';

void showMenu(){
    cout << "Ration numbers calculator" << endl;
    cout << "(A)ddition" << endl << "(S)ubtraction" << endl << "(Q)uit" << endl;
    cout << "Enter your option: ";
}

void DisplayRational(int *inum, int *iden){
    if(*inum == *iden)
        cout << "1";
    else
        cout << *inum << "/" << *iden;
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
    *num /= b;
    *den /= b;
}

void addRational(int num1, int den1, int num2, int den2, int *inum, int *iden){
    reduce(&num1, &den1);
    reduce(&num2, &den2);
    *inum = (num1 * den2) + (num2 * den1); 
    *iden = den1 * den2;
    DisplayRational(inum, iden);
    //cout << *inum << "/" << *iden;
}

void add(){
    while(cont == 'Y' || cont == 'y'){
    int num1, num2, den1, den2, inum,iden;
    system("CLS");
    cout << "Addition of rational numbers" << endl;
    getRational(&num1, &den1);
    getRational(&num2, &den2);
    addRational(num1, den1, num2, den2, &inum, &iden);
    cout << endl << "Do you want to do more additions?(Y/N) ";
    cin >> cont;
    }
    
}

void subtract(){
    //while(cont == 'Y' || cont == 'y'){
    cout << "";
    //cout << "Do you want to do more subtractions?(Y/N) ";
    //cin >> cont;
    //}
}



