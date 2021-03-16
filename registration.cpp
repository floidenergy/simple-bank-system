#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include "accounts.h"

using namespace std;

string passWord, username;
fstream userfile;

int menue();

account regist(){
    
}

account login(){
    system("cls");
    char c;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
    << "\t\t\t||\t\t\tLOGIN IN \t\t|| " << endl
    << "\t\t\t==================================================" << endl
    << "\t\t\t\t\tUSERNAME: " ;
    cin >> username;
    cout << "\n\t\t\t==================================================" << endl
         << "\t\t\t\t\tPASSWORD: ";
    c = _getch();
    while(c != 13){
        passWord.push_back(c);
        cout << "*";
        c = _getch();
    }
    userfile.open("database\\" + username + ".txt");

    if(userfile){
        account user;
        
        user.setUserName()
    }else if(!userfile){
        cout << "\n\t\t\t==================================================" << endl
             << "\t\t\t||\tERROR USER NOT FOUND IN DATABASE\t||" << endl
             << "\t\t\t==================================================" << endl;
    }

}

int main()
{
    _menue:
    int choice = menue();
    if( choice == 1){
        login();
    }else if(choice == 2){
        regist();
    }else{
        system("cls");
        cout << "\t\t\t==================================================" << endl
             << "\t\t\t||\tERROR PLEASE ENTER A VALID CHOICE\t||" << endl
             << "\t\t\t==================================================" << endl;
        getch();
        system("cls");
        goto _menue;
    }
    
    return 0;
}

int menue(){
    int choice;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t||\t\tWELCOME TO THE SYSTEM\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t||\t\t1- LOGIN\t\t\t||" << endl
         << "\t\t\t||\t\t2- REGISTER\t\t\t||" << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t\tMAKE A CHOISE: ";
         cin >> choice;

         return choice;

}