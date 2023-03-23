#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class auth{
public:
    void menu();
    void login();
    void signup();
    void forgot();
    void reset(string);
};

void auth::menu()
{
    int choice;

    cout << "\nChoose an option: " << endl
         << endl;

    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "3. Forgot password" << endl
         << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        forgot();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    cout << endl;
    int x;
    char c;
    cout << "Do you want to continue? (Y/N) " << endl;

    cin >> c;
    cout << endl;
    if (c == 'Y' || c == 'y')
    {
        menu();
    }
    else if (c == 'N' || c == 'n')
    {
        cout << "Thank you for using our service!" << endl;
        cout << "Enter any key to exit" << endl;
        cin >> c;
        exit(0);
    }
    else
    {
        cout << "Invalid choice!" << endl
             << endl;
        cout << "Enter 1 for menu and any key for exit." << endl;
        cin >> x;
        if (x == 1)
        {
            menu();
        }
        else
        {
            exit(0);
        }
    }
}

void auth ::signup()
{
    int t = 0;
    string name, pass, user, password, squestion, answer, a;
    int security;
    system("cls");
    cout << "Enter username: ";
    cin >> name;
    ofstream write("username.txt", ios::app);
    ifstream read("username.txt");
    while (read >> user >> password)
    {
        if (user == name)
        {
            t = 1;
            break;
        }
    }

    if (t == 1)
    {
        cout << "Username " << name << " is already taken." << endl;
    }
    else
    {
        cout << "Enter password: ";
        cin >> pass;
        cout << "Choose security question:" << endl
             << endl;
        cout << "1. Name  your birth place" << endl;
        cout << "2. Your father's name" << endl;
        cout << "3. First pet name" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> a;
        cout << "Enter your answer: " << endl;
        cin >> answer;
        write << name << " " << pass << " " << a << " " << answer << endl;
        cout << "Signed up successfully!" << endl;
    }
    write.close();
}
void auth ::login()
{
    int t = 0;
    string name, pass, user, password;
    cout << "Enter username: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> pass;
    ifstream read("username.txt");
    while (read >> user >> password)
    {
        if (user == name && pass == password)
        {
            t = 1;
            break;
        }
    }
    read.close();
    if (t == 1)
    {
        cout << "Login successful!" << endl;
    }
    else
    {
        cout << "Invalid username or password!" << endl;
    }
}
void auth ::forgot()
{
    int t;
    system("cls");
    cout << "1. Reset your account password" << endl;
    cout << "2. Main Menu" << endl
         << endl;
    cout << "Enter your choice: ";
    cin >> t;
    switch (t)
    {
    case 1:{
        int c = 0;
        string searchuser, user, password, ans, ans1, ans2, reedm;
        cout << "Enter username: ";
        cin >> searchuser;
        ifstream read("username.txt");

        while (read >> user >> password >> ans1 >> ans2)
        {
            if (searchuser == user)
            {
                c = 1;
                break;
            }

            else
            {
                cout << "Invalid username!" << endl;
            }
        }
        read.close();

        cout << endl;

        if (c == 1)
        {
            cout << "Your account has been found. "
                 << "To reset your password, please choose the correct security question you chose during registration "
                 << "and answer it correctly." << endl
                 << endl;
            cout << "Choose your security question: " << endl
                 << endl;
            cout << "1. Name  your birth place" << endl;
            cout << "2. Your father's name" << endl;
            cout << "3. First pet name" << endl
                 << endl;
            cout << "Enter your choice: ";
            cin >> reedm;

            if (reedm == ans1)
            {
                cout << "Enter your answer: ";
                cin >> ans;
                if (ans == ans2)
                {
                    reset(user);
                }

                else
                {
                    cout << "Sorry! Details you entered didn't match." << endl;
                }
            }

            else
            {
                cout << "Enter your answer: ";
                cin >> ans;
                cout << "Sorry! Details you entered didn't match." << endl;
            }
        }


    }

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice" << endl;
    }
}


void auth :: reset(string name){
    string new_pass, user, password, ans1, ans2;
    cout << "Enter new password: ";
    cin >> new_pass;
    
    ofstream temp("temp.txt");
    ifstream read("username.txt");
    while (read >> user >> password >> ans1 >> ans2)
    {
        if (user == name)
        {
            temp << user << " " << new_pass << " " << ans1 << " " << ans2 << endl;
        }
        else
        {
            temp << user << " " << password << " " << ans1 << " " << ans2 << endl;
        }
    }
    read.close();
    temp.close();
    remove("username.txt");
    rename("temp.txt", "username.txt");
}

int main()
{
    auth a;
    a.menu();
    return 0;
}
