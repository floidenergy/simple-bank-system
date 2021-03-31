#include <iostream>
#include <string>
#include <conio.h>
#include "accounts.h"

using namespace std;

string account::getUserName(){
    return username;
}

bool account::setUserName(string value){
    if(isConnected){
        username = value;
        return true;
    }else if(!isConnected){
        cerr << "You need to connect first" << endl;
        return false;
    }
}

bool account::changePassword(){
    if(account::GetAuthontification()){
        string input;
        string input2;
        char c;

        cout << "\t\t\t==================================================" << endl
             << "\t\t\t||\t\tENTER YOUR PASSWORD: " << endl ;
        c = _getch();
        while(c == 13){
            input.push_back(c);
            cout << "*";
            c = _getch();
        }
        cout << endl;
        cout << "\t\t\t==================================================" << endl
             << "\t\t\t||\t\tRE-ENTER YOUR PASSWORD: " << endl ;
        c = _getch();
        while(c == 13){
            input.push_back(c);
            cout << "*";
            c = _getch();
        }

        if(input == input2){
            
            password = input;
            system("cls");
            
            cout << "\n\t\t\t==================================================" << endl
                 << "\t\t\t||\t\tSET UP SECCUSFULLY\t\t    ||" << endl
                 << "\t\t\t==================================================" << endl;
            getch();
            system("cls");
            return true;

        }else if(input != input2){
            system("cls");
            cout << "\n\t\t\t==================================================" << endl
                 << "\t\t\t||\t\tPASSWORD INPUTE DOESNT MUCH !!\t\t    ||" << endl
                 << "\t\t\t==================================================" << endl;
            getch();
            system("cls");
        }

    }else if(!account::GetAuthontification()){
        system("cls");
        cout << "\t\t\t==================================================" << endl
             << "\t\t\t||\tERROR PLEASE ENTER A VALID PASSWORD\t||" << endl
             << "\t\t\t==================================================" << endl;
    }
}

bool account::GetAuthontification(){
    char letter;
    string pwCheck;
    system("cls");
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
        << "\t\t\t||\t\t\tSECURITY CHECK\t\t|| " << endl
        << "\t\t\t==================================================" << endl
        << "\t\t\t\t\tENTER YOUR PASSWORD: ";
    
    letter = _getch();
    while(letter != 13){
        cout << "*";
        letter = _getch();
        pwCheck.push_back(letter);
    }

    // loading animation
    cout << "\t\t\t//////////////////////////////////////////////////" << endl;
    cout << "\t\tLOADING\t||";
    
    for(int i = 0; i < 48; i++){
        cout << "#";
        _sleep(50);
    }
    cout << "\n\t\t\t==================================================" << endl;
    cout << "\t\t\t\t";
    
    if(pwCheck == password){
        cout << "\t\t\t\tAUTHONTIFICATION SUCCESSFULY" << endl;
        getch();
        system("cls");
        return true;
    }
    if(pwCheck != password){
        cout << "\t\t\t\tAUTHONTIFICATION DENIED" << endl;
        getch();
        system("cls");
        return false;
    }    
}

bool account::setBalance(int value){
    if(account::GetAuthontification()){
        balance += value;
        return true;
    }else if(!account::GetAuthontification()){
        return false;
    }
}

bool account::throwBalance(int value){
    if(account::GetAuthontification()){
        balance -= value;
        return true;
    }else if(!account::GetAuthontification()){
        return false;
    }
}

void account::setPassword(string value){
    password = value;
}

string account::getpassword(){
    return password;
}

int account::getBalance(){
    return balance;
}

void account::setID(string first, string last){
    FirstName = first;
    LastName = last;
}

string account::getFirstn(){
    return FirstName;
}

string account::getLastn(){
    return LastName;
}