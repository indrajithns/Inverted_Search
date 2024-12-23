Inverted Search:

Project Overview
This project implements an Inverted Search Database that allows users to build an index from a collection of text files. The index maps words to the files they appear in and tracks the frequency of each word across these files. The system allows users to search for specific words and display their occurrences in various files, update the database with new files, and save or load the database for later use.

Usage
1. Creating the Database
To create a database, select the option to create a new database from the main menu. The program will process all the provided files and create the database.

2. Displaying the Database
You can display the contents of the database using the "Display Database" option. This will show you the indexed words and the files they appear in along with the occurrence count.

3. Updating the Database
If you want to add new files to the database, use the "Update Database" option. You will be prompted to enter the file name, and the program will validate the file before adding it to the database.

4. Searching the Database
To search for a word, choose the "Search" option. Enter the word you want to search for, and the program will display the files where the word appears along with its occurrence count.

5. Saving the Database
You can save the current database to a file by selecting the "Save Database" option. You will be prompted to enter the filename for the saved database.

Instructions:
Build:
Run make to compile the project.
Run:
Use ./main.exe file1.txt file2.txt to interact with the application.
Commands:
The program supports commands to create the database, search, display, save, and update the database.
