#include <iostream>
#include <string>
#include <iomanip>

//prevent multiple inclusions of header
#ifndef USER_H
#define USER_H

class User
{
    private:
        //holds info of checked out items
        struct item
        {
            std::string title;
            int itemID;
        };
        item *inventory;
        std::string login;
        std::string password;
        int userID;
        bool admin;
    public:
        //constructor
        User(std::string login, std::string password, int ID, bool admin);
        //destructor
        ~User();
        
        //get functions
        std::string getLogin();
        std::string getPassword();
        int getUserID();
        bool getAdmin();
        
        //set functions
        void setLogin(std::string login);
        void setPassword(std::string password);
        
        //display user data
        void displayData();
        void displayInventory();

        //load item
        void loadItem(int index, std::string title, int itemID);
        void loadTitle(int index, std::string title);

        //get item
        std::string getTitle(int index);
        int getItemID(int index);
};

#endif