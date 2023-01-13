#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "menu.h"

using namespace std;

class UserName_Password
{
  string Username;
  string Password;

public:
  UserName_Password()
  {
    ifstream file;
    file.open("pass_info.txt");

    string line;

    for (line; getline(file, line);)
    {
      istringstream input(line);

      string username;
      string password;

      input >> username;

      input >> password;

      set_username_pass(username, password);
    }
  }

  void set_username_pass(string a, string b)
  {
    Username = a;
    Password = b;
  }

  void edit_pass()
  {
    string new_username, new_password;

    cout << "\tEnter new username: ";
    cin >> new_username;
    cout << endl;
    cout << "\tEnter new password: ";
    cin >> new_password;

    ofstream file("temp.txt", ofstream::app | ofstream::out);

    file << new_username << " " << new_password;

    file.close();

    remove("pass_info.txt");
    rename("temp.txt", "pass_info.txt");
  }

  int info_checker(string user, string pass)
  {
    if (Username == user && Password == pass)
    {
      getchar();
      cout << "Password and username are correct" << endl;
      getchar();
      return 2;
    }

    else
    {
      getchar();
      cout << "Username and password is not correct\nPress a to try again" << endl;
      getchar();
      return 1;
    }
  }
};

int main(void)
{
  int x = 1, choice;
  UserName_Password ob1;

  while (x == 1)
  {
    system("cls");

    string user, pass;
    cout << "Enter Username and Password: " << endl;
    cin >> user >> pass;
    x = ob1.info_checker(user, pass);
    //getchar();
  }

  while (int x = 1)
  {

    system("cls");
    cout << "\n\n1. Edit Username and password\n2. Add expenditure\n3. Show total expenditure\n4. Total expenditure \n5. Delete expense \n6. Exit" << endl;
    cin >> choice;

    system("cls");
    switch (choice)
    {

    case (1):
      getchar();
      ob1.edit_pass();
      getchar;
      break;

    case (2):

      getchar();
      info_add();
      getchar();
      break;

    case (3):

      getchar();
      show_info();
      getchar();
      break;

    case (4):

      getchar();
      total_expenditure();
      getchar();
      break;

    case (5):

      getchar();
      delte_info();
      delete_info01();
      getchar();
      break;

    case (6):
      return 0;
    }
  }

  return 0;
}