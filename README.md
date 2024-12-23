
# Inverted Search

## Project Overview

This project implements an Inverted Search Database that allows users to build an index from a collection of text files. The index maps words to the files they appear in and tracks the frequency of each word across these files. The system allows users to search for specific words and display their occurrences in various files, update the database with new files, and save or load the database for later use.

### Key Features of This Project:

- **Inverted Index Creation**: Process one or more text files to build an index of words and their corresponding file occurrences.
- **Word Frequency Tracking**: Each word's frequency is tracked within individual files, providing detailed insights into its usage.
- **Search Functionality**: Users can search for a word and view all files in which it appears, including the frequency in each file.
- **Database Update**: New files can be added to the existing database, and the index is updated accordingly.
- **File Validation**: Before processing files, the system checks their availability and content to ensure they can be included in the index.
- **Database Persistence**: The database can be saved to a file and reloaded, enabling users to continue their search operations without rebuilding the entire index.

This project is designed to be highly modular, with separate functions for creating the index, updating the database, displaying the index, saving it, and performing searches. This design allows for easy maintenance and future expansions, such as supporting more advanced search features or handling additional file types.


## Files

### `create_database.c`
This file contains the functions responsible for traversing the list of files, reading their contents, and building the inverted index. It includes the `create_database` and `read_datafile` functions.

### `display.c`
This file contains functions to display the contents of the inverted index, including the word list, file counts, and word frequencies in each file.

### `file_validation.c`
Responsible for validating the existence and content of the files before processing them in the database.

### `insert_last.c`
Includes functions to insert new words into the word list (Wlist) and update the link table (Ltable), which tracks the occurrences of words in specific files.

### `inverted_search.h`
This is the header file that defines all the structures, constants, and function prototypes used throughout the project.

### `main.c`
The main entry point for the program, which allows the user to interact with the system, including selecting various operations like adding files, searching, or displaying the database.

### `save_database.c`
Handles saving the current state of the inverted search database to a file.

### `search.c`
Implements the functionality to search for a word in the database and display its occurrences in various files.

### `update_database.c`
Provides functionality to add new files to the database, validate their content, and update the database accordingly.

### `Makefile`
A file used to automate the compilation of the C source files and create the executable.

## Usage

### 1. **Creating the Database**

   To create a database, select the option to create a new database from the main menu. The program will process all the provided files and create the database.

### 2. **Displaying the Database**

   You can display the contents of the database using the "Display Database" option. This will show you the indexed words and the files they appear in along with the occurrence count.

### 3. **Updating the Database**

   If you want to add new files to the database, use the "Update Database" option. You will be prompted to enter the file name, and the program will validate the file before adding it to the database.

### 4. **Searching the Database**

   To search for a word, choose the "Search" option. Enter the word you want to search for, and the program will display the files where the word appears along with its occurrence count.

### 5. **Saving the Database**

   You can save the current database to a file by selecting the "Save Database" option. You will be prompted to enter the filename for the saved database.

   
### Instructions:

1. **Build**: 
   - Run `make` to compile the project.
2. **Run**: 
   - Use `./main.exe file1.txt file2.txt` to interact with the application.
3. **Commands**: 
   - The program supports commands to create the database, search, display, save, and update the database.


## Functions

- **create_database()**: Creates the database by processing the files.
- **display_database()**: Displays the current content of the database.
- **update_database()**: Updates the database with a new file.
- **search()**: Searches for a word in the database.
- **save_database()**: Saves the database to a file.

## Error Handling

The program provides feedback for the following error cases:

- **File Not Available**: The file doesn't exist or cannot be accessed.
- **File Empty**: The file has no content.
- **File Repeated**: The file has already been added to the database.



