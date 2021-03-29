#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <unistd.h>
#include <sstream>
#include "accounts.h"

using namespace std;

string passWord, username;
fstream userfile;
string dataBasePath = "database\\";

account user;

int menue()
{
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

void regist()
{
    system("cls");
    string usernameINP;
    string passwordINP;
    string passwordINP2;
    char letter;

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t\t\tSET USERNAME: ";

    cin >> usernameINP;

    system("cls");

    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t\t\tSET A PASSWORD: ";

    letter = _getch();
    while (letter != 13)
    {
        cout << "*";
        passwordINP.push_back(letter);
        letter = _getch();
    }

    system("cls");

    cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t\t||\t\tSIGN UP\t\t|| " << endl
         << "\n\t\t\t==================================================" << endl
         << "\t\t\t\t\tSET A PASSWORD: ";

    letter = NULL;

    letter = _getch();
    while (letter != 13)
    {
        cout << "*";
        passwordINP2.push_back(letter);
        letter = _getch();
    }

    system("cls");
    if (passwordINP == passwordINP2)
    {
        user.isConnected = true;

        cout << "\n\t\t\t//////////////////////////////////////////////////" << endl
             << "\t\t\t||\t\tREGISTRED SUCCESSEFULLY\t\t|| " << endl
             << "\n\t\t\t==================================================" << endl;

        cout << "\n\t\t\t//////////////////////////////////////////////////" << endl;
        cout << "\t\tLOADING\t||";

        for (int i = 0; i < 48; i++)
        {
            cout << "#";
            _sleep(50);
        }
        ofstream checker("data\\" + usernameINP + ".txt", ios::in);
        
        if(checker.is_open()){
            cout << "\n\t\t\tuser already exist, (the program will now exit)";
            sleep(5000);
            exit(EXIT_FAILURE);
        }
        userfile.open("data\\" + usernameINP , ios::in | ios::out | ios::app);

        user.setUserName(usernameINP);
        user.setPassword(passwordINP2);

        

        //userfile.open(dataBasePath + user.getUserName() + ".txt");
        userfile << user.getUserName() << endl
                 << user.getpassword() << endl
                 << user.getBalance() << endl;
        getch();
    }
    else if (passwordINP != passwordINP2)
    {
        cout << "denied" << endl;
        usleep(9000);
        system("cls");
        regist();
    }
}

void login()
{
    system("cls");
    char c;
    cout << "\t\t\t//////////////////////////////////////////////////" << endl
         << "\t\t\t||\t\t\tLOGIN IN \t\t|| " << endl
         << "\t\t\t==================================================" << endl
         << "\t\t\t\t\tUSERNAME: ";

    getline(cin, username);

    cout << "\n\t\t\t==================================================" << endl
         << "\t\t\t\t\tPASSWORD: ";
    c = _getch();
    while (c != 13)
    {
        passWord.push_back(c);
        cout << "*";
        c = _getch();
    }
    userfile.open("data\\" + username + ".txt", fstream::in | fstream::out | fstream::app);

    if (userfile)
    {
        string use;
        string pass;
        string bl;
        int balance;

        getline(userfile, use, '\n');
        getline(userfile, pass, '\n');
        getline(userfile, bl, '\n');

        stringstream ss;
        ss << bl;
        ss >> balance;

        if (passWord == pass)
        {

            user.setUserName(use);
            user.setPassword(pass);
            user.setBalance(balance);
            user.isConnected = true;

            cout << "*username: " << user.getUserName() << endl;
            cout << "*password: " << user.getpassword() << endl;
            cout << "*balance: " << user.getBalance() << endl;

            cout << "\n\t\t\t==================================================" << endl
                 << "\t\t\t||\t\t\tCONNECTED\t\t\t||" << endl
                 << "\t\t\t==================================================" << endl;

            getch();
        }
    }
    else if (!userfile)
    {
        cout << "\n\t\t\t==================================================" << endl
             << "\t\t\t||\tERROR USER NOT FOUND IN DATABASE\t||" << endl
             << "\t\t\t==================================================" << endl;

        usleep(9000);
    }
}

int main()
{
    while (!user.isConnected)
    {
        int choice = menue();
        if (choice == 1)
        {
            login();
        }
        else if (choice == 2)
        {
            regist();
        }
        else
        {
            system("cls");
            cout << "\t\t\t==================================================" << endl
                 << "\t\t\t||\tERROR PLEASE ENTER A VALID CHOICE\t||" << endl
                 << "\t\t\t==================================================" << endl;
            
            system("cls");
        }
    }

    return 0;
}
