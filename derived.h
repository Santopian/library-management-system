#include <iostream>
#include <string>
#include <iomanip>
#include "item.h"

//prevent multiple inclusions of a header
#ifndef DERIVED_H
#define DERIVED_H

//Book Class
class Book : public Item
{
    private:
        std::string author;
        int yearPublished;
        int numPages;
    public:
        //constructor
        Book(std::string title, std::string itemType, int itemID, bool checkedOut, std::string author, int yearPublished, int numPages);

        //get functions
        std::string getAuthor();
        int getYearPublished();
        int getNumPages();

        //set functions
        void setAuthor(std::string author);
        void setYearPublished(int yearPublished);
        void setNumPages(int numPages);

        //display
        virtual void displayData();
};

//Movie Class
class Movie : public Item
{
    private:
        std::string director;
        int yearReleased;
        int lengthMins;
    public:
        //constructos
        Movie(std::string title, std::string itemType, int itemID, bool checkedOut, std::string director, int yearReleased, int lengthMins);

        //get functions
        std::string getDirector();
        int getYearReleased();
        int getLengthMins();

        //set functions
        void setDirector(std::string director);
        void setYearReleased(int yearReleased);
        void setLengthMins(int lengthMins);

        //display function
        virtual void displayData();
};

//Game Class
class Game : public Item{
    private:
        std::string publisher;
        int yearReleased;
    public:
        //contructors
        Game(std::string title, std::string itemType, int itemID, bool checkedOut, std::string publisher, int yearReleased);

        //getFunctions
        std::string getPublisher();
        int getYearReleased();

        //setFunctions
        void setPublisher(std::string publisher);
        void setYearReleased(int yearReleased);

        //display function
        virtual void displayData();
};

#endif