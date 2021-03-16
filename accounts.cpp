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
    if(GetAuthontification){
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
            _sleep(9000);
            system("cls");
            return true;

        }else if(inpute != input2){
            system("cls");
            cout << "\n\t\t\t==================================================" << endl
                 << "\t\t\t||\t\tPASSWORD INPUTE DOESNT MUCH !!\t\t    ||" << endl
                 << "\t\t\t==================================================" << endl;
            _sleep(9000);
            system("cls");
        }

    }else if(!GetAuthontification){
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
        << "\t\t\t||\t\tENTER YOUR PASSWORD: " << endl;
    
    letter = _getch();
    while(letter != 13){
        pwCheck.push_back(c);
        letter = _getch();
        cout << "*";
    }

    // loading animation
    cout << "\t\t\t//////////////////////////////////////////////////" << endl;
    cout << "\t\tLOADING\t||";
    
    for(int i = 0; i < 48; i++){
        cout << "#";
    _sleep(100);
    }
    cout << "\n\t\t\t==================================================" << endl;
    cout << "\t\t\t\t"
    
    if(pwCheck == password){
        cout << "\t\t\t\tAUTHONTIFICATION SUCCESSFULY" << endl;
        _sleep(9000);
        system("cls");
        return true;
    }else if(pwCheck != password){
        cout << "\t\t\t\tAUTHONTIFICATION DENIED" << endl;
        _sleep(9000);
        system("cls");
        return false;
    }    
}

bool account::setBalance(int value){
    if(GetAuthontification){
        balance += value;
    }
}

bool account::throwBalance(int value){
    if(GetAuthontification){
        balance -= value;
    }
}
