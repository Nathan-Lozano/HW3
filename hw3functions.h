#include <iostream>
#include <sstream>
using namespace std;

void showMenu(){
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
}

void add(){
    //while(cont == 'Y' || cont == 'y'){
    int num1, num2, den1, den2, inum,iden;
    system("CLS");
    cout << "Addition of rational numbers" << endl;
    getRational(&num1, &den1);
    getRational(&num2, &den2);
    cout << num1 << " " << den1 << endl << num2 << " " << den2;
    //cout << "Do you want to do more additions?(Y/N) "
    //cin >> cont;
    //}
    
}

void subtract(){
    //while(cont == 'Y' || cont == 'y'){
    cout << "";
    //cout << "Do you want to do more subtractions?(Y/N) ";
    //cin >> cont;
    //}
}