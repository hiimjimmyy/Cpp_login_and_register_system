/*login and registration system
created by Jimmy on 08.07.21*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
    
//determine validity of login
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
    cout << "\nPlease select one of the following options: \n";
    cout << "\n1. Register\n2. Login\n"; 
    cin >> choice;
    
    if (choice == !1 || choice == !2)
    {
        cerr << "Please enter a valid input, options 1 or 2.";
        cin.clear();
        cin.ignore();
        main();
    }
    else if  (choice == 1)
    {
        string username, password;

        cout << "Please enter a desired username: "; cin >> username;
        cout << "Please enter a desired password: "; cin >> password;
        cout <<"\nYou've successfully registered\n";
        //this will create a file to add new users
        //ofstream to write new data into text file

        //this will check to see if there's an exisiting username
        

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
            cerr << "\nThe login infomation is incorrect, please try again.\n" << endl;
            
            main();
        }
        else
        {
            cout << "\nLogin successful!\n" << endl;
            
            return 1;
        }
    }
}


