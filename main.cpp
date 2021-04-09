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
    char choice;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t||\t\tWELCOME TO THE SYSTEM\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t||\t\t1- LOGIN\t\t\t||" << endl
         << "\t\t\t||\t\t2- REGISTER\t\t\t||" << endl
         << "\t\t\t==================================================" << endl;
    choice = _getch();

    return choice;
}

void login(account &user){
    string usnm;
    string psw;
    string fsName, lsName;
    string bal;
    int balance;
    char c[15];
    
    string pswd, usnmd;

    system("cls");

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tUSERNAME: ";
    cin >> usnm;

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tPASSWORD: ";
    cin >> psw;
    
    fstream userFile ("data\\" + usnm + ".txt");
    if(!userFile.is_open()){
        cout << "USER NOT FOUND !!!" << endl;
        getch();
        system("cls");
        return;
    }
    getline(userFile, usnmd);
    getline(userFile, pswd);
    getline(userFile, fsName);
    getline(userFile, lsName);
    getline(userFile, bal);
    //cout << usnmd << endl << pswd << endl << fsName << endl << lsName << endl << bal << endl;
    
    cerr << c;
    if(psw == pswd && usnm == usnmd){
        system("cls");
        cout << "\t\t\t//////////////////////////////////////////////////" << endl
             << "\t\t\t||\t\tLOGIN SUCCESSFULLY\t\t|| " << endl
             << "\t\t\t==================================================" << endl;
        getch();

        user.isConnected = true;
        user.setUserName(usnmd);
        user.setPassword(pswd);
        user.setID(fsName, lsName);
        user.setBalance(stoi(bal));
        
        system("cls");
    }else{
        system("cls");

        cout << "\t\t\t//////////////////////////////////////////////////" << endl
             << "\t\t\t||\t\t\tLOGIN DENIED\t\t\t|| " << endl
             << "\t\t\t==================================================" << endl;
        
        getch();
        system("cls");
    }
}

void regist(){
    system("cls");
    string username, password, data;
    char a;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tUSERNAME: ";
    cin >> username;
    
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tPASSWORD: ";
    a = _getch();
    while(a != 13){
        password.push_back(a);
        cout << "*";
        a = _getch();
    } 
    
    string path = "data\\" + username + ".txt";

    fstream checkFile (path, ios::out | ios::in);

    if(checkFile.is_open()){
        system("cls");
        cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
             << "\t\t\t||\t\tUSER ALREADY EXISTE\t\t|| " << endl
             << "\t\t\t==================================================" << endl;
            
            getch();
            system("cls");
            return;
    }

    fstream userfile (path, ios::in | ios::out | ios::app);
    userfile << username << endl;
    userfile << password << endl;

    cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tFIST NAME: ";
    cin >> data;
    userfile << data << endl;
        
    cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t\tLAST NAME: ";
    cin >> data;
    userfile << data << endl;
    system("cls");

    userfile << 0 ;


    cout << "\nregistred successfully !!!";
    getch();
    system("cls");    
}

int main(){
    while(true){
        account user;
        while(!user.isConnected){
            char choice = menue();
            if(choice == '1'){
                login(user);
            }else if(choice == '2'){
                regist();
            }else{
                system("cls");
                cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
                    << "\t\t\t||\tERRORE!!! PLEASE ENTER A VALID INPUTE\t|| " << endl
                    << "\t\t\t==================================================" << endl;
                getch();
                system("cls");
            }
        }

        system("cls");

        while(user.isConnected){
            cout << "*FIRST NAME: " + user.getFirstn() << endl;
            cout << "*LAST NAME: " + user.getLastn() << endl;
            printf("*BALANCE: %d", user.getBalance());
            //cout << "*BALANCE: " + to_string(user.getBalance()) << endl;
            
            getch();
        }
    }
    return 0;
}