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
void subrational(int *anum,int *aden,int num1,int den1,int num2,int den2){
    *anum = (num1 *den2)-(num2 * den1);
    *aden = (den1*den2);
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
   system("cls");
    int num,den;
    int num1,den1,num2,den2,anum,aden;
    cout<<"subtraction of rational numbers"<<endl;
    while(true){
        getRational(&num1,&den1);
        getRational(&num2,&den2);
        subrational(&anum, &aden,num1,den1,num2,den2);
        reduce(&anum,&aden);
       // displayRational(num,den);
        char user = '\0';
        cout<<"do you want to do more addition?(Y/N): ";
        cin>>user;
        cin.ignore();
       // if(user ='N')
        {
            break;
}

//this program is meant for fractions to be inputted and execute certain functions with them such as addittion and subtraction
//as seen in the code alot of the fuctions learned in class were applied to the best of our ability

