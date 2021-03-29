#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctype.h>
#include "accounts.h"

using namespace std;

int menue()
{
    int choice;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t||\t\tWELCOME TO THE SYSTEM\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t||\t\t1- LOGIN\t\t\t||" << endl
         << "\t\t\t||\t\t2- REGISTER\t\t\t||" << endl
         << "\t\t\t==================================================" << endl;
    cin >> choice;

    return choice;
}

account login(){
    string usnm;
    string psw;
    
    string pswd, usnmd;

    system("cls");

    cout << "\nUSERNAME: ";
    cin >> usnm;

    cout << "\nPASSWORD: ";
    cin >> psw;
    
    fstream userFile ("data\\" + usnm + ".txt");
    if(!userFile.is_open()){
        cout << "USER NOT FOUND !!!" << endl;
        getch();
    }
    getline(userFile, usnmd);
    getline(userFile, pswd);

    if(psw == pswd && usnm == usnmd){
        system("cls");
        cout << "accepted";
        getch();
    }else{
        system("cls");
        cout << "denied" ;
        getch();
    }
}

void regist(){
    system("cls");
    string username, password;
    char a;
    cout << "USERNAME: ";
    cin >> username;
    system("cls");
    cout << "PASSWORD: ";
    a = _getch();
    while(a != 13){
        password.push_back(a);
        cout << "*";
        a = _getch();
    } 
    
    string path = "data\\" + username + ".txt";
    fstream checkfile (path);

    if(checkfile.is_open()){
        system("cls");
        char c;
        cout << "USER FILE ALREADY EXISTE, DO YOU WANNA OVERIDE IT ? [Y/N]: ";
        c = _getch();
        if(tolower(c) == 'y'){
            //remove(path);
        }else if(tolower(c) == 'n'){
            return;
        }
    }

    fstream userfile ("data\\" + username + ".txt", ios::in | ios::out);
    userfile << username << endl;
    userfile << password << endl;
    userfile << 0 ;
    cout << "\nregistred successfully !!!";
    getch();
    system("cls");    
}

int main(){
    account user;
    while(!user.isConnected){
        menue:
        int choice = menue();
        if(choice == 1){
            login();
        }else if(choice == 2){
            regist();
        }else{
            cout << "ERRORE!!! Please enter a valid Input";
            getch();
            goto menue;
        }
    }

    return 0;
}