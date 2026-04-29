#include <string>
#include <fstream>
#include "user.h"
#include "item.h"
#include "derived.h"

//prevent multiple inclusions of a header
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

class FileManager{
    private:
        int last_user_location;
        int num_users;
        int last_item_location;
        int num_items;

        
    public:
        FileManager();

        void importUsers(User* users[]);
        void importItems(Item* items[]);

        void exportUsers(User* users[]);

        int getNumUsers();
};
#endif