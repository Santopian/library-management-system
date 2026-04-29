#include "file_manager.h"

//constructors
FileManager::FileManager(){
    last_user_location = 0;
    last_item_location = 0;
}

//methods
//user importer
void FileManager::importUsers(User* users[]){

    //variables
    std::string username;
    std::string password;
    int user_ID;
    bool is_admin;
    std::string checked_item_title;
    int checked_item_ID;

    //fstream
    std::ifstream in_file;

    //import users
    in_file.open("users.txt");
    //number of users in file
    in_file >> num_users;
    //get data from users.txt
    for(int index = 0; index < num_users; index++){

        in_file >> username >> password >> user_ID >> is_admin;

        //put in array
        users[index] = new User(username, password, user_ID, is_admin);

        //import data into the array of checked out items
        for(int checked_items = 0; checked_items < 5; checked_items++){

            in_file >> checked_item_title >> checked_item_ID;

            //replace _ in file with " "
            for(int character_index = 0; character_index < checked_item_title.length(); character_index++){

                if(checked_item_title.substr(character_index, 1) == "_"){

                    checked_item_title[character_index] = ' ';
                }
            }

            users[index]->loadItem(checked_items, checked_item_title, checked_item_ID);
        }
    }

    //close file
    in_file.close();

}
//item importer
void FileManager::importItems(Item* items[]){

}

//user exporter
void FileManager::exportUsers(User* users[]){

    system("cls");
    std::cout << "Saving Users...\n";

    //variables
    std::string username;
    std::string password;
    int user_ID;
    bool is_admin;
    std::string checked_item_title;
    int checked_item_ID;

    //file stream
    std::ofstream out_file;

    //export users
    out_file.open("users.txt");
    //save number of users in array
    out_file << num_users << std::endl;

    //save info from array
    for(int index = 0; index < num_users; index++){

        username = users[index]->getLogin();
        password = users[index]->getPassword();
        user_ID = users[index]->getUserID();
        is_admin = users[index]->getAdmin();

        out_file << username << std::endl << password << std::endl << user_ID << std::endl << is_admin << std::endl;

        //saves inventory back to memory
        for(int checked_items = 0; checked_items < 5; checked_items++){

            checked_item_title = users[index]->getTitle(checked_items);
            checked_item_ID = users[index]->getItemID(checked_items);

            //replace " " with "_" to save to memory
            for(int character_index = 0; character_index < checked_item_title.length(); character_index++){

                if(checked_item_title.substr(character_index) == " "){

                    checked_item_title[character_index] = '-';
                }
            }

            //save inventory
            out_file << checked_item_title << std::endl << checked_item_ID << std::endl;
        }
    }

    out_file.close();
}

//get number of users
int FileManager::getNumUsers(){
        return num_users;
}
