#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <unistd.h>
#include "accounts.h"

using namespace std;

string passWord, username;
fstream userfile;
string dataBasePath = "database\\";

account user;

int menue();

void regist(){
    system("cls");
    string usernameINP;
    string passwordINP;
    string passwordINP2;
    char letter;

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
    << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
    << "\t\t\t==================================================" << endl
    << "\t\t\t\t\tSET USERNAME: " ;

    cin >> usernameINP;

    system("cls");

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t\t\tSET A PASSWORD: " ;

    letter = _getch();
    while(letter != 13){
        cout << "*";
        passwordINP.push_back(letter);
        letter = _getch();
    }

    system("cls");

    cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
         << "\n\t\t\t==================================================" << endl
         << "\t\t\t\t\tSET A PASSWORD: " ;

    letter = NULL;

    letter = _getch();
    while(letter != 13){
        cout << "*";
        passwordINP2.push_back(letter);
        letter = _getch();
    }
    
    system("cls");
    if(passwordINP == passwordINP2){
        cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
             << "\t\t\t||\t\tREGISTRED SUCCESSEFULLY\t\t|| " << endl
             << "\n\t\t\t==================================================" << endl;

        cout << "\n\t\t\t//////////////////////////////////////////////////" << endl;
        cout << "\t\tLOADING\t||";
    
        for(int i = 0; i < 48; i++){
            cout << "#";
            usleep(100000);
        }
        
        user.setUserName(usernameINP);
        user.setPassword(passwordINP2);
        user.isConnected = true;

        userfile.open("data\\" + user.getUserName() + ".txt", fstream::in | fstream::out | fstream::app);
        
        
        //userfile.open(dataBasePath + user.getUserName() + ".txt");
        userfile << user.getUserName() << endl << user.getpassword() << endl << user.getBalance() << endl;
        getch();
    }else if(passwordINP != passwordINP2){
        cout << "denied" << endl;
        usleep(9000);
        system("cls");
        regist();
    }

}

void login(){
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
    userfile.open("data\\" + username + ".txt", fstream::in | fstream::out | fstream::app);

    if(userfile){
        
        user.setUserName(username);
        user.setPassword(passWord);

        user.isConnected = true;
        

    }else if(!userfile){
        cout << "\n\t\t\t==================================================" << endl
             << "\t\t\t||\tERROR USER NOT FOUND IN DATABASE\t||" << endl
             << "\t\t\t==================================================" << endl;

            usleep(9000);
            
    }

}

int main()
{
    while(!user.isConnected){
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
            
        }
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