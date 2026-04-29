# Library Management System (C++)

A simple C++ console application for managing a small library catalog (Books and Movies) with user logins.

Users can log in and check items in/out (up to 5 items at a time). Admin users can create accounts and manage the catalog.

## Features

- Login with username/password
- Role-based menus
  - **Admin**: create users, view user data, add books, remove items
  - **User**: check out items, check in items, change password
- Persistent storage using plain text files:
  - `users.txt`
  - `books.txt`
  - `movies.txt`

## Project Structure

- `project.cpp` — program entry point and menu flows
- `item.h/.cpp` — base `Item` type
- `derived.h/.cpp` — `Book` and `Movie` derived item types (also includes a `Game` type, currently unused)
- `user.h/.cpp` — `User` model and checked-out inventory
- `file_manager.h/.cpp` — import/export for `users.txt`
- `books.txt`, `movies.txt`, `users.txt` — sample data

## Build

This is a standard C++ project (no external dependencies). Any modern compiler should work.

### Windows (MinGW g++)

From the project folder:

```bash
g++ -std=c++17 -O2 -o project.exe project.cpp item.cpp derived.cpp user.cpp file_manager.cpp
```

### macOS / Linux (g++)

```bash
g++ -std=c++17 -O2 -o project project.cpp item.cpp derived.cpp user.cpp file_manager.cpp
```

## Run

Make sure the data files are in the same directory as the executable:

- `users.txt`
- `books.txt`
- `movies.txt`

Then run:

### Windows

```bash
./project.exe
```

### macOS / Linux

```bash
./project
```

## Default Sample Accounts

The included `users.txt` contains sample accounts. If you haven’t changed it:

- Regular user: `ssanc111` / `ssanc111`
- Admin user: `admin` / `admin`

## Data Files

The program reads/writes simple text files.

### `users.txt`

Format:

1. First line: number of users (`N`)
2. For each user:
   - `username`
   - `password`
   - `userID` (integer)
   - `admin` (boolean: `0` or `1`)
   - Then 5 checked-out slots (each slot is two lines):
     - `title`
     - `itemID`

Notes:
- Titles stored in files use underscores instead of spaces.

### `books.txt`

Format:

1. First line: number of books (`N`)
2. For each book:
   - `title`
   - `itemType` (should be `Book`)
   - `itemID`
   - `checkedOut` (`0` or `1`)
   - `author`
   - `yearPublished`
   - `numPages`

Notes:
- `title` and `author` use underscores instead of spaces.

### `movies.txt`

Format:

1. First line: number of movies (`N`)
2. For each movie:
   - `title`
   - `itemType` (should be `Movie`)
   - `itemID`
   - `checkedOut` (`0` or `1`)
   - `director`
   - `yearReleased`
   - `lengthMins`

Notes:
- `title` and `director` use underscores instead of spaces.

## Known Limitations

- The Admin menu option **“Add Movie”** is present but not implemented in `project.cpp`.
- Catalog persistence is done in `project.cpp` for books/movies; only users are handled by `FileManager`.

## License

Add a license if you plan to distribute this project publicly.
