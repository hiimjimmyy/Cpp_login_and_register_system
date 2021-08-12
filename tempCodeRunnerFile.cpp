/*this is a test file to test for a switch statement 
opposed to having multiple if statements
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isLoggedIn ()
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



    
}