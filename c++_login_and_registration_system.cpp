/*login and registration system
created by Jimmy on 08.07.21
*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
    
//arugment to determine validity of login
bool isLoggedIn()
{
    string username, password, un, pw;

    //obtain user infomation
    cout << "Please enter your username: "; 
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    //validates user information by checking if there's a valid username
    ifstream read("data\\" + username + ".txt");
    getline (read, un);
    getline (read, pw);
    
    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    int choice;

    //provide login or registration option for returning or new users
    cout << "Please select one of the following options: ";
    cout << "\n1. Register\n2. Login\n"; 
    cin >> choice;
    
    if (!1 || !2)
    {
        cerr << "Please enter a valid input, options 1 or 2.";
        exit(1);
    }
    else if  (choice == 1)
    {
        string username, password;

        cout << "Please enter a desired username: "; cin >> username;
        cout << "Please enter a desired password: "; cin >> password;

        //this will create a file to add new users
        //ofstream to write new data into text file

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();
        
        //this will give us the option to return back start to either login or register again
        main();

    }
    else if (choice == 2)
    {
        //reference boolean isLoggedIn
        bool status = isLoggedIn();

        if(!status)
        {
            cerr << "The login infomation is incorrect, please try again." << endl;
            system("PAUSE");
            
            return 0;

        }
        else
        {
            cout << "Login successful!" << endl;
            system("PAUSE");
            
            return 1;
        }
    }
}


