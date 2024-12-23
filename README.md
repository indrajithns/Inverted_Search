
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

## How to Use

1. **Compile the Program**: Run `make` to compile the program and generate the executable.
2. **Create a Database**: Use the `create_database` function to process text files and build the inverted index.
3. **Search for a Word**: Use the `search` function to look for a word in the database and display its occurrences in various files.
4. **Display Database**: Use the `display_database` function to print out the contents of the database.
5. **Save Database**: Use the `save_database` function to save the current database state to a file.
6. **Update Database**: Add new files to the database using the `update_database` function.



