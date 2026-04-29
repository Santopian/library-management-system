#include "user.h"

//constructors
User::User(std::string login, std::string password, int userID, bool admin)//creates user
{
    //dynamic array
    inventory = new item[5];
    this->login = login;
    this->password = password;
    this->userID = userID;
    this->admin = admin;

    //fill array with default values
    for(int i = 0; i < 5; i++)
    {
        inventory[i].title = " ";
        inventory[i].itemID = 0;
    }
}
//deconstructor
User::~User()
{
    //frees up memory
    delete[] inventory;
    inventory = 0;
}

//get functions
std::string User::getLogin()
{
    return login;
}
std::string User::getPassword()
{
    return password;
}
int User::getUserID()
{
    return userID;
}
bool User::getAdmin()
{
    return admin;
}

//set functions
void User::setLogin(std::string login)
{
    this->login = login;
}
void User::setPassword(std::string password)
{
    this->password = password;
}

//display data
void User::displayData()
{
    std::cout << "Login: " << login << "\n";
    std::cout << "Password: " << password << "\n";
    std::cout << "User ID: " << userID << "\n";
}
void User::displayInventory()
{
    std::cout << "Items Checked Out:\n";

    //goes through array
    for(int i = 0; i < 5; i++)//makes sure not empty
    {
        if((inventory + i)->title != " " && (inventory + i)->itemID != 0)
        {
            std::cout << std::setw(9) << "Title: " << (inventory + i)->title << "\n";
            std::cout << std::setw(9) << "Item ID: " << (inventory + i)->itemID << "\n";
            std::cout << "\n";
        }
    }
}

//load item
void User::loadItem(int index, std::string title, int itemID)
{
    inventory[index].title = title;
    inventory[index].itemID = itemID;
}
void User::loadTitle(int index, std::string title)
{
    (inventory + index)->title = title;
}

// get Items
std::string User::getTitle(int index)
{
    std::string returnVal;
    returnVal = (inventory + index)->title;
    return returnVal;
}
int User::getItemID(int index)
{
    int returnVal;
    returnVal = (inventory + index)->itemID;
    return returnVal;
}