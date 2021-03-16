#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

using std::string;

class account{
    string username;
    string password;
    string fullName;
    int balance;
    bool isConnected;

    bool GetAuthontification();

    public:
    string getUserName();
    bool setUserName(string value);
    bool changePassword();
    bool setBalance(int value);
    bool throwBalance(int value);
    
};

#endif