#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

using namespace std;

class account{
    string username;
    string password;
    string fullName;
    string FirstName;
    string LastName;
    int balance;
    

    bool GetAuthontification();

    public:
    bool isConnected = false;
    string getUserName();
    bool setUserName(string value);
    bool changePassword();
    bool setBalance(int value);
    bool throwBalance(int value);
    void setPassword(string value);
    string getpassword();
    int getBalance();
    void setID(string first, string last);
    string getFirstn();
    string getLastn();
    account();

};

#endif