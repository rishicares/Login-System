# Login System

This is a simple authentication program in C++ that allows users to create an account, log in, and reset their password if they forget it. The program uses a text file to store user account information and password reset security questions and answers.

## Getting started
To use the program, simply compile the code and run the executable. The program will display a menu with three options: Login, Signup, and Forgot password.

1. Login - Allows users to enter their username and password to log in to their account. If the username and password match an account in the system, the user is logged in. If not, the user is prompted to enter their details again.

2. Signup - Allows users to create a new account. Users enter a unique username and password, as well as choose a security question and answer that can be used to reset their password in the future. If the username is already taken, the user is prompted to choose a different one.

3. Forgot password - Allows users to reset their password if they forget it. Users enter their username and answer the security question they chose during registration. If the answer is correct, the user is prompted to enter a new password.

## Code structure
The program is written in C++ and contains a single class called auth. The auth class contains several methods that handle the program's functionality.

1. menu - Displays the main menu and prompts the user to choose an option. Based on the user's choice, the method calls the corresponding method (login, signup, or forgot password).

2. login - Prompts the user to enter their username and password. The method reads the user account information from the text file and checks if the username and password match. If they do, the user is logged in. If not, the user is prompted to enter their details again.

3. signup - Prompts the user to enter a unique username and password and choose a security question and answer. The method writes the user account information to the text file.

4. forgot - Prompts the user to choose between resetting their password or returning to the main menu. If the user chooses to reset their password, the method prompts them to enter their username and answer the security question they chose during registration. If the answer is correct, the user is prompted to enter a new password and the account information is updated in the text file.

5. reset - Prompts the user to enter a new password and updates the account information in the text file.

## Usage and modifications
This program is intended to be a simple example of authentication functionality and is not intended to be used in production environments. 

## Dependencies
This program does not have any external dependencies and should run on any system that supports C++.




