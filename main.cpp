#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
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
         << "\t\t\t||\t\t3_ EXIT\t\t\t\t||" << endl
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
    
    fstream userFile ("data\\" + usnm);
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
             << "\t\t\t||\t\tLOGIN DENIED\t\t\t|| " << endl
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
    
    string path = "data\\" + username;

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

void addBal(account &u){
    cout << "How many u wanna add: ";
    int value ;
    cin >> value;
    system("cls");
    u.setBalance(value);
    string path;
    path = ("data\\" + u.getUserName());
    ofstream f (path, ios::out | ios::trunc);
    f << u.getUserName() << endl
        << u.getpassword() << endl
        << u.getFirstn() << endl
        << u.getLastn() << endl
        << u.getBalance();
    cout << "Balance Added Successfuly.";
    f.close();
}

void throwBal(account &u){
    cout << "How Many You Wanna Throw: ";
    int value;
    cin >> value;
    system("cls");
    u.throwBalance(value);
    string path;
    path = ("data\\" + u.getUserName());
    ofstream f (path, ios::out | ios::trunc);
    f << u.getUserName() << endl
        << u.getpassword() << endl
        << u.getFirstn() << endl
        << u.getLastn() << endl
        << u.getBalance();
    f.close();
}

void changePass(account &u){
    system("cls");
    cout << "enter your new password: ";

    string value, value2;
    char a;

    a = _getch();
    while(a != 13){
        value.push_back(a);
        cout << "*";
        a = _getch();
    }
    cout << endl << "re-enter your new password: ";
    
    a = _getch();
    while(a != 13){
        value2.push_back(a);
        cout << "*";
        a = _getch();
    }

    if (value != value2){
        cout << "password doesnt much:";
        _sleep(3000);
        return;
    }
    u.setPassword(value);
    
    string path;
    path = ("data\\" + u.getUserName());
    ofstream f (path, ios::out | ios::trunc);
    f << u.getUserName() << endl
        << u.getpassword() << endl
        << u.getFirstn() << endl
        << u.getLastn() << endl
        << u.getBalance();
    f.close();
}

int main(){
    mkdir("data");
    while(true){
        account user;
        while(!user.isConnected){
            char choice = menue();
            if(choice == '1'){
                login(user);
            }else if(choice == '2'){
                regist();
            }else if(choice == '3'){
                exit(0);
            }else{
                system("cls");
                cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
                    << "\t\t\t||\tERRORE!!! PLEASE ENTER A VALID INPUTE\t|| " << endl
                    << "\t\t\t==================================================" << endl;
                getch();
                system("cls");
            }
        }

        while(user.isConnected){
            system("cls");
            fstream userFile ("data\\" + user.getUserName() + ".txt");
            

            cout << "*FIRST NAME: " + user.getFirstn() << endl
                 << "*LAST NAME: " + user.getLastn() << endl
                 << "*BALANCE: " << user.getBalance() << endl
                 << "=========================================" << endl;
            
            
            cout << "1_ Add Balance" << endl
                 << "2_ Throw Balance" << endl
                 << "3_ Settings" << endl
                 << "4_ Disconnect" << endl
                 << "5_ Exit" << endl;
            
            char a = _getch();
            
            system("cls");

            switch (a){
                    
                case '1':{
                    addBal(user);
                    _sleep(3000);
                }break;
                    
                case '2':{
                    throwBal(user);
                }break;
                    
                case '3':{
                    cout << "1_ Change Password" << endl
                        << "0_ return" << endl;
                    char a = _getch();
                    switch(a){
                        case '1':
                            changePass(user);
                            break;
                    }
                }break;
                
                case '4':{
                    user.isConnected = false;
                }break;
                case '5':{
                    cout << "GOOD BY Mr." << user.getLastn();
                    _sleep(3000);
                    exit(0);
                }break;
            }
            
        }
    }
    return 0;
}