#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void info_add(void)
{
    string expense;
    int amount;
    ofstream ofc;
    ofstream total;

    ofc.open("check.txt", ofstream::out | ofstream::app);

    total.open("total-expenditure.txt", ofstream::out | ofstream::app);
    cout << "Enter expense: ";
    cin >> expense;

    cout << "Enter amount: ";
    cin >> amount;

    ofc << expense << " : " << amount << endl;

    total << amount << " : " << expense << endl;
    ;

    ofc.close();
}

void show_info()
{

    string getcontent;
    ifstream openfile("check.txt");
    int x = 1;
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            getline(openfile, getcontent);
            if (getcontent.length() == 0)
            {
                break;
            }
            else
            {
                cout << x << ". " << getcontent << endl;
                x++;
            }
        }
    }
    openfile.close();
}

void total_expenditure()
{
    vector<int> data;
    ifstream fin("total-expenditure.txt");
    int number;
    string eater;
    int sum = 0;

    while (fin >> number) // get first 8 digit number.  stops at the '-'
    {

        data.push_back(number);
        getline(fin, eater); // consume the rest of the line
        //now we are on the next line
    }

    if (data.empty() == false)
    {
    }
    //cout << "\nVector is not empty";

    else
        cout << "\nVector is empty";

    int q = data.size();
    for (int i = 0; i < q; i++)
    {
        sum = sum + data[i];
    }
    cout << "Total expenditure is " << sum;
}

int line_delete;

void delte_info()
{

    cout << "Which line do you want to delete: " << endl
         << endl;
    show_info();
    cin >> line_delete;
    string getcontent, tempstring, getcontent01, tempstring01;
    int count = 1;
    ifstream openfile("check.txt");
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            getline(openfile, getcontent);

            if (count != line_delete)
            {
                ofstream temp("temp.txt", ofstream ::app | ofstream ::out);
                if (getcontent.length() == 0)
                {
                    continue;
                }
                temp << getcontent << endl;
            }
            count++;
        }
    }
    openfile.close();

    remove("check.txt");
    rename("temp.txt", "check.txt");
}

void delete_info01(void)
{
    string getcontent;
    int count = 1;
    ifstream totalfile("total-expenditure.txt");
    if (totalfile.is_open())
    {
        while (!totalfile.eof())
        {
            getline(totalfile, getcontent);

            if (count != line_delete)
            {
                ofstream temp01("temp1.txt", ofstream ::app | ofstream ::out);
                if (getcontent.length() == 0)
                {
                    continue;
                }
                temp01 << getcontent << endl;
            }
            count++;
        }
    }
    totalfile.close();

    remove("total-expenditure.txt");
    rename("temp1.txt", "total-expenditure.txt");
}

#endif