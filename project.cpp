#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "item.h"
#include "derived.h"
#include "user.h"
#include "file_manager.h"

using namespace std;

//prototypes
int adminMenu();
int userMenu();

//main
int main()
{

    //create file manager object
    FileManager file_manager = FileManager();

    //list of users
    User *users[10];
    int lastUserLocation = 0; //keeps track of how many users
    int numUsers; //used when importing from file

    //variables to hold values for objects
    //list for users
    string username;
    string password;
    int userID;
    bool admin;
    string checkedItemTitle;
    int checkedItemID;

    //list of items in library
    Item *library[20];
    int lastItemLocation = 0; //keeps track of how many books
    string title;
    string itemType;
    int itemID;
    bool checkedOut;

    //variables for books
    string author;
    int yearPublished;
    int numPages;
    int numBooks;

    //variables for movies
    string director;
    int yearReleased;
    int lengthMins;
    int numMovies;

    //counters to save back into files
    int bookCounter = 0;
    int movieCounter = 0;

    //file import and export variables
    ifstream inFile;
    ofstream outFile;



    /*
    //import users
    inFile.open("users.txt");
    //number of users in file
    inFile >> numUsers;
    //get data from users.txt
    for(int i = 0; i < numUsers; i++)
    {
        inFile >> username >> password >> userID >> admin;

        //put in array
        users[i] = new User(username, password, userID, admin);

        //import data into the array of checked out items
        for(int j = 0; j < 5; j++)
        {
            inFile >> checkedItemTitle >> checkedItemID;

            //get rid of _ in title and replace with " "
            for (int y=0; y<checkedItemTitle.length();y++)
		    {
			    if (checkedItemTitle.substr(y,1)=="_")
			    {
			    	checkedItemTitle[y] = ' ';
			    }
		    }

            users[i]->loadItem(j, checkedItemTitle, checkedItemID);
        }

    }
    inFile.close();
    */
    

    file_manager.importUsers(users);

    numUsers = file_manager.getNumUsers();


    //import books
    inFile.open("books.txt");
    //number of books in books.txt
    inFile >> numBooks;
    //begin importing
    for(int i = 0; i < numBooks; i++)
    {
        inFile >> title >> itemType >> itemID >> checkedOut >> author >> yearPublished >> numPages;

        //get rid of _ and replace with " " in title
        for (int y=0; y<title.length();y++)
		{
			if (title.substr(y,1)=="_")
			{
				title[y] = ' ';
			}
		}
        //get rid of _ in author and replace with " "
        for (int y=0; y<author.length();y++)
		{
			if (author.substr(y,1)=="_")
			{
				author[y] = ' ';
			}
		}

        //put in array
        library[lastItemLocation] = new Book(title,itemType,itemID,checkedOut,author,yearPublished,numPages);

        //itterate counter for array
        lastItemLocation++;
    }
    //close file
    inFile.close();

    //import Movies
    inFile.open("movies.txt");
    //number of movies in movies.txt
    inFile >> numMovies;
    //begin importing
    for(int i = 0; i < numMovies; i++)
    {
        inFile >> title >> itemType >> itemID >> checkedOut >> director >> yearReleased >> lengthMins;

        //get rid of _ in title and replace with " "
        for (int y=0; y<title.length();y++)
		{
			if (title.substr(y,1)=="_")
			{
				title[y] = ' ';
			}
		}
        //get rid of _ in director and replace with " "
        for (int y=0; y<director.length();y++)
		{
			if (director.substr(y,1)=="_")
			{
				director[y] = ' ';
			}
		}

        //put into array
        library[lastItemLocation] = new Movie(title,itemType,itemID,checkedOut,director,yearReleased,lengthMins);

        //itterate counter for array
        lastItemLocation++;
    }
    inFile.close();


    //main program
    //menu 1
    int choice;
    do
    {
        //menu 1
        cout << "Santiago Library\n";
        cout << "1: Log In\n";
        cout << "2: Exit\n";
        cout << "Choice: ";
        cin >> choice;
        while(choice < 1 || choice > 2)
        {
            cout << "ERROR! Select valid choice: ";
            cin >> choice;
        }
        //end program if 2 is chosen
        if(choice == 2)
        {
            return 0;
        }
        //breaks out if choice = 1
        if(choice == 1)
        {
            break;
        }
    } while (1);

    //menu 2
    int incorrectCounter = 0; //used to check if max attempts are reached
    bool correctLogin;
    bool isAdmin = false;
    do
    {
        system("cls");

        //set to false by default
        correctLogin = false;

        //asks for username and password
        cout << "Username: ";
        cin >> username;
        cout << "password: ";
        cin >> password;

        //loops thorugh list to make sure it works
        for(int i = 0; i < numUsers; i++)
        {
            //if login is correct, breaks out of loop
            if(username == users[i]->getLogin() && password == users[i]->getPassword())
            {
                correctLogin = true;
                isAdmin = users[i]->getAdmin();
                break;
            }
        }

        if(!correctLogin)
        {
            cout << "Incorrect Username or Password\n";
            incorrectCounter++; //itterates counter

            if(incorrectCounter >= 3)//checks for max attempts
            {
                cout << "Maximum attempts reached! Closing Program...\n";
            }

            system("pause");//pauses to read message

            //if max attempts reached, ends program
            if(incorrectCounter >= 3)
            {
                return 0;
            }
        }
    } while (!correctLogin);

    //menu 3
    int choice2;
    system("cls");
    //admin menu
    if(isAdmin)
    {
        do
        {
            //sort by item type
            for (int x=0; x<lastItemLocation; x++)
	        {
		        for (int y=0; y<lastItemLocation-1-x; y++)
		        {
			        if (library[y]->getTitle()>library[y+1]->getTitle())
				        swap(library[y],library[y+1]);
		        }
	        }
            //sort by item type
            for (int x=0; x<lastItemLocation; x++)
	        {
		        for (int y=0; y<lastItemLocation-1-x; y++)
		        {
			        if (library[y]->getItemType()>library[y+1]->getItemType())
				        swap(library[y],library[y+1]);
		        }
	        }

            system("cls");
            choice2 = adminMenu();

            //vars used in admin menu
            int userChoice;
            int itemChoice;
            string newUsername;
            string newPassword;
            int newID;
            char newAdminChar;
            bool newAdmin = false;
            string newTitle;
            string newAuthor;
            int newYearPublished;
            int newNumPages;
            bool isRepeat = false;

            //switch for choices
            switch(choice2)
            {
                case 1://create user
                    system("cls");
                    cout<<"Create User\n";
                    cout<<"Username: ";
                    cin>>newUsername;
                    cout<<"Password: ";
                    cin>>newPassword;
                    cout<<"User ID: ";
                    cin>>newID;
                    cout<<"Admin (Y/N): ";
                    cin>>newAdminChar;

                    //saves the char as a bool in newAdmin
                    if(newAdminChar == 'Y' || newAdminChar == 'y')
                    {
                        newAdmin = true;
                    }
                    
                    //checks if username is taken
                    for(int i = 0; i < numUsers; i++)//checks if username is taken
                    {
                        while(newUsername == users[i]->getLogin())
                        {
                            cout<<"Username is taken. Enter another username.\n";
                            cout<<"Username: ";
                            cin>>newUsername;
                            i = 0; //set back to 0 to check from first index for repeated name
                        }
                    }

                    //checks if userID is taken
                    for(int i = 0; i < numUsers; i++)//checks if username is taken
                    {
                        while(newID == users[i]->getUserID())
                        {
                            cout<<"User ID is taken. Enter another user ID.\n";
                            cout<<"User ID: ";
                            cin>>newID;
                            i = 0; //set back to 0 to check from first index for repeated name
                        }
                    }

                    //add the user to the array
                    users[numUsers] = new User(newUsername, newPassword, newID, newAdmin);

                    //itterate users counter
                    numUsers++;

                    break;
                case 2://list user data
                    system("cls");
                    cout<<"View User Data\n";
                    for(int i = 0; i < numUsers; i++)//lists logins
                    {
                        cout<<i+1<<": "<<users[i]->getLogin()<<"\n";
                    }
                    cout<<"Select a user: ";
                    cin>>userChoice;
                    cout<< "**********\n";
                    users[userChoice-1]->displayData();
                    system("pause");
                    break;
                case 3://add book
                    system("cls");
                    cout<<"Add Book\n";
                    cout<<"Title: ";
                    cin.ignore();//clear buffer
                    getline(cin, newTitle);
                    cout<<"Item ID: ";
                    cin>>newID;
                    cout<<"Author: ";
                    cin.ignore();
                    getline(cin, newAuthor);
                    cout<<"Year Published: ";
                    cin>>newYearPublished;
                    cout<<"Number of Pages: ";
                    cin>>newNumPages;

                    //checks for repeats
                    for(int i = 0; i < lastItemLocation; i++)
                    {
                        if(library[i]->getTitle() == newTitle)
                        {
                            cout<<"ERROR! Book already in library.\n";
                            isRepeat = true;
                        }
                    }
                    if(isRepeat)//breaks out if book already exists
                    {
                        system("pause");
                        break;
                    }

                    //checks for itemID repeat
                    for(int i = 0; i < lastItemLocation; i++)
                    {
                        //asks user to input a nonexistant ID
                        while(library[i]->getItemID() == newID)
                        {
                            cout<<"ERROR! Enter a nonesiting ID: ";
                            cin>>newID;
                            i = 0;
                        }
                    }
                    
                    //put into array
                    library[lastItemLocation] = new Book(newTitle,"Book",newID,false,newAuthor,newYearPublished,newNumPages);

                    //itterate lastItemLocation
                    lastItemLocation++;
                    break;
                case 4://add movie
                    break;
                case 5://remove item
                    system("cls");
                    cout<<"Remove Item\n";
                    for(int i = 0; i < lastItemLocation; i++)
                    {
                        cout<<i+1<<": "<<library[i]->getTitle()<<"\n";
                    }
                    cin>>itemChoice;

                    //set choice to NULL
                    library[itemChoice-1] = new Item();
                    
                    
                    //moves NULL objects to the end of array
                    for (int x=0; x<lastItemLocation; x++)
		            {
			            for (int y=0; y<lastItemLocation; y++)
			            {
				            if (library[y]->getTitle()=="NULL")
				            {
					            swap(library[y],library[lastItemLocation-1]);
					            lastItemLocation--;
				            }
			            }
		            }
                    break;
                case 6://EXIT
                    break;
                default:
                    break;
            }

        }while(choice2 != 6);
    }

    //nonadmin menu
    if(!isAdmin)
    {
        //variables used in user menu
        int userIndex;
        string newPassword;
        int bookChoice;
        int numChecked;
        int libraryIndex;

        for(int i = 0; i < numUsers; i++)
        {
            if(users[i]->getPassword() == password)
            {
                userIndex = i;
            }
        }

        do
        {
            numChecked = 0;
            //checks for checked out books
            for(int i = 0; i < 5; i++)
            {
                if(users[userIndex]->getItemID(i) != 0)
                {
                    numChecked++;
                }
            }

            system("cls");
            choice2 = userMenu();

            //switch for choices
            switch(choice2)
            {
                case 1://check out book
                    system("cls");
                    cout << "Check out Item\n";
                    cout << "Items checked out: " << numChecked << "\n";
                    for(int i = 0; i < lastItemLocation; i++)
                    {
                        //we start at i+1 but index is i
                        cout << i+1 << ": "<<library[i]->getTitle()<<endl;
                    }
                    cout << "Select an item: ";
                    cin >> bookChoice;
                    if(library[bookChoice-1]->getCheckedOut()){//checks if book is checked out
                        cout << "Item is Checked Out\n";
                        system("pause");
                        break;
                    }
                    if(numChecked >= 5)//checks if max items checked out
                    {
                        cout << "Max items checked out\n";
                        system("pause");
                        break;
                    }

                    title = library[bookChoice-1]->getTitle();//stores title of selected book
                    itemID = library[bookChoice-1]->getItemID();//stores id of selected book
                    library[bookChoice-1]->setCheckedOut(true);

                    users[userIndex]->loadItem(numChecked, title, itemID);//stores book info in array

                    break;
                case 2://check in book
                    system("cls");
                    cout << "Check in Item\n";
                    cout << "Items checked out: " << numChecked << "\n";
                    if(numChecked == 0)//makes sure items are checked out
                    {
                        cout << "No items checked out\n";
                        system("pause");
                        break;
                    }
                    for(int i = 0; i < numChecked; i++)//select item to check in
                    {
                        cout << i+1 << ": " << users[userIndex]->getTitle(i) << endl;;
                    }
                    cout << "Select an item: ";
                    cin >> bookChoice;

                    title = users[userIndex]->getTitle(bookChoice-1);
                    itemID = users[userIndex]->getItemID(bookChoice-1);

                    users[userIndex]->loadItem(bookChoice-1, "_", 0);

                    for(int i = 0; i < lastItemLocation; i++)
                    {
                        if(itemID == library[i]->getItemID())
                        {
                            library[i]->setCheckedOut(false);
                        }
                    }

                    break;
                case 3://change password
                    system("cls");
                    cout << "Current Password: " << users[userIndex]->getPassword() << "\n";
                    cout << "New Password: ";
                    cin >> newPassword;
                    users[userIndex]->setPassword(newPassword);
                    password = newPassword;
                    break;
                case 4:
                    break;
                default:
                    break;
            }
            
        }while(choice2 != 4);
    }
    
    //searches for empty index and places at end of array
    for (int x=0; x<lastItemLocation; x++)
	{
		for (int y=0; y<lastItemLocation; y++)
		{
			if (library[y]->getTitle()=="NULL")
			{
				//inventory[x] = inventory[lastitemlocation-1];
				swap(library[y],library[lastItemLocation-1]);
				lastItemLocation--;
			}
		}
	}

    system("cls");
    cout << "Saving...";


    /*
    //writing data back to files
    outFile.open("users.txt");
    //save num of users
    outFile << numUsers << endl;
    //save info from array
    for(int i = 0; i < numUsers; i++)
    {

        username = users[i]->getLogin();
        password = users[i]->getPassword();
        userID = users[i]->getUserID();
        admin = users[i]->getAdmin();

        outFile<<username<<endl<<password<<endl<<userID<<endl<<admin<<endl;

        for(int j = 0; j < 5; j++)
        {
            title = users[i]->getTitle(j);
            itemID = users[i]->getItemID(j);

            //get rid of " " in title and replace with _
            for (int y=0; y<title.length();y++)
		    {
			    if (title.substr(y,1)==" ")
			    {
			    	title[y] = '_';
			    }
		    }

            outFile<<title<<endl<<itemID<<endl;
        }
    }
    outFile.close();
    */

    file_manager.exportUsers(users);

    //sort by item type
    for (int x=0; x<lastItemLocation; x++)
	{
		for (int y=0; y<lastItemLocation-1-x; y++)
		{
			if (library[y]->getItemType()>library[y+1]->getItemType())
				swap(library[y],library[y+1]);
		}
	}


    //goes through list to itterate counters for itemTypes
    for(int i = 0; i < lastItemLocation; i++)
    {
        if(library[i]->getItemType() == "Book")
        {
            bookCounter++;
        }
        if(library[i]->getItemType() == "Movie")
        {
            movieCounter++;
        }
    }

    //counters
    int libraryCounter = 0;
    int tempCounter = 0;

    //saving
    //write back to books.txt
    outFile.open("books.txt");

    outFile<<bookCounter<<endl;
    tempCounter = libraryCounter;
    for(int i = libraryCounter; i < (tempCounter+bookCounter); i++)
    {
        //change from Item to Book to get members not in base class
        Book* book = dynamic_cast<Book*>(library[i]);

        title = book->getTitle();
        itemType = book->getItemType();
        itemID = book->getItemID();
        checkedOut = book->getCheckedOut();
        author = book->getAuthor();
        yearPublished = book->getYearPublished();
        numPages = book->getNumPages();

        //get rid of " " in title and replace with _
        for (int y=0; y<title.length();y++)
		{
			if (title.substr(y,1)==" ")
			{
			    title[y] = '_';
			}
		}
        //get rid of " " in author and replace with _
        for (int y=0; y<author.length();y++)
		{
			if (author.substr(y,1)==" ")
			{
			    author[y] = '_';
			}
		}

        outFile<<title<<endl<<itemType<<endl<<itemID<<endl<<checkedOut<<endl<<author<<endl<<yearPublished<<endl<<numPages<<endl;

        libraryCounter++;
    }
    //close file
    outFile.close();

    //write back to movies.txt
    outFile.open("movies.txt");

    outFile<<movieCounter<<endl;
    tempCounter = libraryCounter;
    for(int i = libraryCounter; i < (tempCounter + movieCounter); i++)
    {
        Movie* movie = dynamic_cast<Movie*>(library[i]);

        title = movie->getTitle();
        itemType = movie->getItemType();
        itemID = movie->getItemID();
        checkedOut = movie->getCheckedOut();
        director = movie->getDirector();
        yearReleased = movie->getYearReleased();
        lengthMins = movie->getLengthMins();

        //get rid of " " in title and replace with _
        for (int y=0; y<title.length();y++)
		{
			if (title.substr(y,1)==" ")
			{
			    title[y] = '_';
			}
		}
        //get rid of " " in author and replace with _
        for (int y=0; y<director.length();y++)
		{
			if (director.substr(y,1)==" ")
			{
			    director[y] = '_';
			}
		}

        //save to file
        outFile<<title<<endl<<itemType<<endl<<itemID<<endl<<checkedOut<<endl<<director<<endl<<yearReleased<<endl<<lengthMins<<endl;

        //itterate counter
        libraryCounter++;
    }
    outFile.close();
    
    return 0;
}

//

//admin menu
int adminMenu()
{
    int choice;

    cout << "1. Create User\n";
    cout << "2. View User Data\n";
    cout << "3. Add Book\n";
    cout << "4. Add Movie\n";
    cout << "5. Remove Item\n";
    cout << "6. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;

    while(choice < 1 || choice > 7)
    {
        cout << "ERROR! Select valid option: ";
        cin >> choice;
    }

    return choice;
}

//regular menu
int userMenu()
{
    int choice;

    cout << "1. Check Out Book\n";
    cout << "2. Check In Book\n";
    cout << "3. Change Password\n";
    cout << "4. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;

    while(choice < 1 || choice > 4)
    {
        cout << "ERROR! Select valid option: ";
        cin >> choice;
    }

    return choice;
}