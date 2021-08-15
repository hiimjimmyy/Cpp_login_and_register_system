/*login and registration system
created by Jimmy on 08.07.21 */
//this is the project file after receiving feedback from Prof. Kamto.


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
    
//arugment to determine validity of login
bool isLoggedIn(fstream & x)
{
    string username, password, un, pw;

    //obtain user infomation
    cout << "Please enter your loging username: "; 
    cin >> username;
    cout << "Please enter your loging password: ";
    cin >> password;

    if (!x)
        cout << "file not existing and cannot be used in reading mode";
    else
    {
        //validates user information by checking if there's a valid username
        x.open("data.txt");
        getline(x, un);
        getline(x, pw);
        x.close();

        if (un == username && pw == password)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int choice;

    //provide login or registration option for returning or new users
    cout << "\nPlease select one of the following options: ";
    cout << "\n1. Register\n2. Login\n"; 
    cin >> choice;
    
    while (choice < 1 || choice > 2)
    {
        cout << "Please enter a valid input, options 1 or 2.\n";
        cin >> choice;
    }
            
    if  (choice == 1)
    {
        string username, password;

        cout << "\nPlease enter a desired username: "; cin >> username;
        cout << "\nPlease enter a desired password: "; cin >> password;

        //this will create a file to add new users
        //ofstream to write new data into text file

        ofstream file;
        file.open("data.txt");
        file << username << endl << password;
        file.close();
        
        //this will give us the option to return back start to either login or register again
        main();

    }
    else if (choice == 2)
    {
        fstream file;
        //reference boolean isLoggedIn
        bool status = isLoggedIn(file);
        
        if(!status)
        {
            cout << "\nThe login infomation is incorrect, please try again.\n" << endl;
            system("PAUSE");            
            return 0;
        }
        else
        {
            cout << "\nLogin successful!" << endl;
            system("PAUSE");            
            return 1;
        }
    }
}





