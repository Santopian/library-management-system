#include <iostream>
#include <string>
#include <iomanip>

//prevent multiple inclusions of a header
#ifndef ITEM_H
#define ITEM_H

class Item
{
    private:
        std::string title;
        std::string itemType;
        int itemID;
        bool checkedOut;
    public:
        //constructor
        Item();
        Item(std::string title, std::string itemType, int itemID, bool checkedOut);
        
        //get functions
        std::string getTitle();
        std::string getItemType();
        int getItemID();
        bool getCheckedOut();

        //set functions
        void setTitle(std::string title);
        void setItemType(std::string itemType);
        void setCheckedOut(bool checkedOut);
        
        //display data
        virtual void displayData();
};

#endif