#include "derived.h"

//Book Class
//constructor
Book::Book(std::string title, std::string itemType, int itemID, bool checkedOut, std::string author, int yearPublished, int numPages)
    : Item(title, itemType, itemID, checkedOut)
{
    this->author = author;
    this->yearPublished = yearPublished;
    this->numPages = numPages;
}

//get classes
std::string Book::getAuthor()
{
    return author;
}
int Book::getYearPublished()
{
    return yearPublished;
}
int Book::getNumPages()
{
    return numPages;
}

//set functions
void Book::setAuthor(std::string author)
{
    this->author = author;
}
void Book::setYearPublished(int yearPublished)
{
    this->yearPublished = yearPublished;
}
void Book::setNumPages(int numPages)
{
    this->numPages = numPages;
}

//display function
void Book::displayData()
{
    std::cout << "Book Data\n";
    std::cout << std::setw(16) << "Title: " << getTitle() << "\n";
    std::cout << std::setw(16) << "Item Type: " << getItemType() << "\n";
    std::cout << std::setw(16) << "Item ID: " << getItemID() << "\n";
    std::cout << std::setw(16) << "Author: " << author << "\n";
    std::cout << std::setw(16) << "Pages: " << numPages << "\n";
    std::cout << std::setw(16) << "Year Published: " << yearPublished << "\n";
    std::cout << std::setw(13) << "Checked Out: ";
    if (getCheckedOut())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}


//Movie Class
//constructor
Movie::Movie(std::string title, std::string itemType, int itemID, bool checkedOut, std::string director, int yearReleased, int lengthMins)
    : Item(title, itemType, itemID, checkedOut)
{
    this->director = director;
    this->yearReleased = yearReleased;
    this->lengthMins = lengthMins;
}

//get functions
std::string Movie::getDirector()
{
    return director;
}
int Movie::getYearReleased()
{
    return yearReleased;
}
int Movie::getLengthMins()
{
    return lengthMins;
}

//set functions
void Movie::setDirector(std::string director)
{
    this->director = director;
}
void Movie::setYearReleased(int yearReleased)
{
    this->yearReleased = yearReleased;
}
void Movie::setLengthMins(int lengthMins)
{
    this->lengthMins = lengthMins;
}

//display function
void Movie::displayData()
{
    std::cout << "Movie Data\n";
    std::cout << std::setw(16) << "Title: " << getTitle() << "\n";
    std::cout << std::setw(16) << "Item Type: " << getItemType() << "\n";
    std::cout << std::setw(16) << "Item ID: " << getItemID() << "\n";
    std::cout << std::setw(16) << "Director: " << director << "\n";
    std::cout << std::setw(16) << "Year Released: " << yearReleased << "\n";
    std::cout << std::setw(16) << "Length in Mins: " << lengthMins << "\n";
    std::cout << std::setw(13) << "Checked Out: ";
    if (getCheckedOut())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}

//Game Class
//Constructor
Game::Game(std::string title, std::string itemType, int itemID, bool checkedOut, std::string publisher, int yearReleased)
    : Item(title, itemType, itemID, checkedOut){
        this->publisher = publisher;
        this->yearReleased = yearReleased;
}

//get functions
std::string Game::getPublisher(){
    return publisher;
}
int Game::getYearReleased(){
    return yearReleased;
}

//set functions
void Game::setPublisher(std::string publisher){
    this->publisher = publisher;
}
void Game::setYearReleased(int yearReleased){
    this->yearReleased = yearReleased;
}

//display function
void Game::displayData(){
    std::cout << "Movie Data\n";
    std::cout << std::setw(16) << "Title: " << getTitle() << "\n";
    std::cout << std::setw(16) << "Item Type: " << getItemType() << "\n";
    std::cout << std::setw(16) << "Item ID: " << getItemID() << "\n";
    std::cout << std::setw(16) << "Publisher: " << publisher << "\n";
    std::cout << std::setw(16) << "Year Released: " << yearReleased << "\n";
    std::cout << std::setw(13) << "Checked Out: ";
    if (getCheckedOut())
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}