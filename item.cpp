#include "item.h"

//constructor
Item::Item()
{
    title = "NULL";
    itemType = "NULL";
    itemID = 0;
    checkedOut = 0;
}
Item::Item(std::string title, std::string itemType, int itemID, bool checkedOut)
{
    this->title = title;
    this->itemType = itemType;
    this->itemID = itemID;
    this->checkedOut = checkedOut;
}
//get functions
std::string Item::getTitle()
{
    return title;
}
std::string Item::getItemType()
{
    return itemType;
}
int Item::getItemID()
{
    return itemID;
}
bool Item::getCheckedOut()
{
    return checkedOut;
}
//set functions
void Item::setTitle(std::string title)
{
    this->title = title;
}
void Item::setItemType(std::string itemType)
{
    this->itemType = itemType;
}
void Item::setCheckedOut(bool checkedOut)
{
    this->checkedOut = checkedOut;
}
//display functions
void Item::displayData()
{
    std::cout << "Item Data\n";
    std::cout << std::setw(13) << "Title: " << title << "\n";
    std::cout << std::setw(13) << "Item Type: " << itemType << "\n";
    std::cout << std::setw(13) << "Item ID: " << itemID << "\n";
    std::cout << std::setw(13) << "Checked Out: ";
    if (checkedOut)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}