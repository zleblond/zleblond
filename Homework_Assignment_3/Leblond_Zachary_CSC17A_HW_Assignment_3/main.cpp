//Zachary Leblond
//October 1st, 2017
//Homework Assignment 3

#include <iostream>
#include <string>

using namespace std;

#include "MovieData.h"
#include "Sales.h"
#include "Stats.h"
#include "Soccer.h"
#include "Budget.h"
#include "Machine.h"
#include "Bin.h"

void Menu();
int getN();
void def(int);

void movie(Movies); // Displays the information about the movie 
void problem1();

void profit(Movies); // Modifies program 1 to include cost and yield.
void problem2();

void display(Sales);
void problem3();

void problem4();

void addpart(int, int);
void remove(int, int);
void getPart(int);
void problem5();

void problem6();

void getBudg(Budget &);
void report(Budget);
void problem7();

void find(int);
void problem8();



    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem8();break;
          default:   def(inN);}
        }while(inN<9);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 for problem 8"<<endl;
           cout<<"Type 9 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void movie(Movies s)
    {
        cout << "Movie Title: " << s.title << endl;
        cout << "Director: " << s.director << endl;
        cout << "Year of Release: " << s.year << endl;
        cout << "Length: " << s.runTime << endl;
    }
    void problem1()
    {
           cout<<"Movie Data"<<endl<<endl;
           Movies movie1, movie2;
           cout << "Enter Movie Title: ";
           cin.ignore();
           getline(cin, movie1.title);
           cout << "\nEnter Director Name: ";
           getline(cin, movie1.director);
           cout << "\nEnter the year of release: ";
           cin >> movie1.year;
           cout << "\nHow long is the movie?(In minutes): ";
           cin >> movie1.runTime;
           cin.ignore();
           cout << "\nEnter the second Movie Title: ";
           getline(cin, movie2.title);
           cout << "\nEnter Director Name: ";
           getline(cin, movie2.director);
           cout << "\nEnter year of release: ";
           cin >> movie2.year;
           cout << "\nHow long is the movie?(In minutes): ";
           cin >> movie2.runTime;
           movie(movie1);
           movie(movie2);
    }
    
    void profit(Movies p)
    {
        cout << "Movie Title: " << p.title << endl;
        cout << "Director: " << p.director << endl;
        cout << "Year of Release: " << p.year << endl;
        cout << "Length: " << p.runTime << endl;
        if(p.cost < p.yield)
        {
            cout << "The profit is: " << p.yield - p.cost << endl;
        }
        else
        {
            cout << "The loss is: " << p.cost - p.yield << endl;
        }
    }
    void problem2()
    {
           cout<<"Movie data and Profits/Loss"<<endl<<endl;
           Movies movie1, movie2;
           cout << "Enter Movie Title: ";
           cin.ignore();
           getline(cin, movie1.title);
           cout << "\nEnter Director Name: ";
           getline(cin, movie1.director);
           cout << "\nEnter the year of release: ";
           cin >> movie1.year;
           cout << "\nHow long is the movie?(In minutes): ";
           cin >> movie1.runTime;
           cout << "\nEnter production costs: ";
           cin >> movie1.cost;
           cout << "\nEnter the revenue from first year of sales: ";
           cin >> movie1.yield;
           cin.ignore();
           cout << "\nEnter the second Movie Title: ";
           getline(cin, movie2.title);
           cout << "\nEnter Director Name: ";
           getline(cin, movie2.director);
           cout << "\nEnter year of release: ";
           cin >> movie2.year;
           cout << "\nHow long is the movie?(In minutes): ";
           cin >> movie2.runTime;
           cout << "\nEnter production costs: ";
           cin >> movie2.cost;
           cout << "\nEnter the revenue from first year of sales: ";
           cin >> movie2.yield;
           profit(movie1);
           profit(movie2);
    }
    
    void display(Sales s)
    {
        cout << "\n\nDivision name: " << s.name << endl;
        cout << "\nFirst Quarter Sales: " << s.first << endl;
        cout << "\nSecond Quarter Sales: " << s.second << endl;
        cout << "\nThird Quarter Sales: " << s.third << endl;
        cout << "\nFourth Quarter Sales: " << s.fourth << endl;
        cout << "\nAnnual Sales: " << s.total << endl;
        cout << "Average Sales: " << s.average << endl << endl;
    }
    void problem3()
    {
           cout<<"Corporate Sales Data"<<endl<<endl;
           Sales d1, d2, d3, d4; //Division 1 through 4
           
           d1.name = "East";
           cout << d1.name << "  Division.\n";
           cout << "Enter First Quarter Sales: ";
           cin >> d1.first;
           cout << "\nEnter Second Quarter Sales: ";
           cin >> d1.second;
           cout << "\nEnter Third Quarter Sales: ";
           cin >> d1.third;
           cout << "\nEnter Fourth Quarter Sales: ";
           cin >> d1.fourth;
           d1.total = d1.first + d1.second + d1.third + d1.fourth;
           d1.average = d1.total / 4;
           
           d2.name = "West";
           cout << d2.name << "  Division.\n";
           cout << "Enter First Quarter Sales: ";
           cin >> d2.first;
           cout << "\nEnter Second Quarter Sales: ";
           cin >> d2.second;
           cout << "\nEnter Third Quarter Sales: ";
           cin >> d2.third;
           cout << "\nEnter Fourth Quarter Sales: ";
           cin >> d2.fourth;
           d2.total = d2.first + d2.second + d2.third + d2.fourth;
           d2.average = d2.total / 4;
           
           d3.name = "North";
           cout << d3.name << "  Division.\n";
           cout << "Enter First Quarter Sales: ";
           cin >> d3.first;
           cout << "\nEnter Second Quarter Sales: ";
           cin >> d3.second;
           cout << "\nEnter Third Quarter Sales: ";
           cin >> d3.third;
           cout << "\nEnter Fourth Quarter Sales: ";
           cin >> d3.fourth;
           d3.total = d3.first + d3.second + d3.third + d3.fourth;
           d3.average = d3.total / 4;
           
           d4.name = "South";
           cout << d4.name << "  Division.\n";
           cout << "Enter First Quarter Sales: ";
           cin >> d4.first;
           cout << "\nEnter Second Quarter Sales: ";
           cin >> d4.second;
           cout << "\nEnter Third Quarter Sales: ";
           cin >> d4.third;
           cout << "\nEnter Fourth Quarter Sales: ";
           cin >> d4.fourth;
           d4.total = d4.first + d4.second + d4.third + d4.fourth;
           d4.average = d4.total / 4;
           
           cout << "Corporate Sales Data Report: ";
           display(d1);
           display(d2);
           display(d3);
           display(d4);
    }
    void problem4()
    {
           cout<<"Weather Statistics"<<endl<<endl;
           Stats months[12];
           float lowest = 0; 
           float highest = 0; 
           float avgsum = 0;
           float total = 0;
           int hiMonth, loMonth;
           string month[12] = {"January", "February", "March", "April", "May", 
                            "June", "July", "August", "September", "October", 
                            "November", "December" };
           for(int i = 0; i < 12; i++)
           {
               cout << "Enter the amount of total rain fall for month " << 
                       month[i] << ": ";
               cin >> months[i].rain;
               cout << "\nEnter the highest temperature in the month: ";
               cin >> months[i].hiTemp;
               if(months[i].hiTemp < -100 || months[i].hiTemp > 140)
               {
                   cout << "The temperature must be between -100 and 140\n";
                   cout << "High Temperature: ";
                   cin >> months[i].hiTemp;
               }
               cout << "Enter the lowest temperature in the month: ";
               cin >> months[i].lowTemp;
               if(months[i].lowTemp < -100 || months[i].lowTemp > 140)
               {
                   cout << "The temperature must be between -100 and 140.\n";
                   cout << "Low Temperature: ";
                   cin >> months[i].lowTemp;
               }
               total = total+months[i].rain;
               months[i].avgTemp = (months[i].hiTemp + months[i].lowTemp) / 2;
               if(months[i].hiTemp> highest)
               {
                   highest=months[i].hiTemp;
                   hiMonth = i;
               }
               if(months[i].lowTemp < lowest)
               {
                   lowest = months[i].lowTemp;
                   loMonth = i;
               }
               avgsum = avgsum + months[i].avgTemp;
           }
           cout << "Average monthly rainfall: " << total / 12 << endl;
           cout << "Total rainfall " << total << endl;
           cout << "Highest rainfall in " << month[hiMonth] << " is: " << 
                   highest << endl;
           cout << "Lowest rainfall in " << month[loMonth] << " is: " << lowest 
                   << endl;
           cout << "Average Temperature is: " << avgsum / 12 << endl;
    }
    void addpart(int parts, int i)
    {
        if(bins[i].numPrt + parts > 30)
        {
            cout << "\nSorry, you have enterted the parts to add more than "
                    "" << 30 - bins[i].numPrt << endl;
            cout << "The bin capacity is 30" << endl;
        }
        else
        {
            bins[i].numPrt = bins[i].numPrt + parts;
        }
    }
    void remove(int parts, int i)
    {
        if(bins[i].numPrt - parts < 0)
        {
            cout << "\nSorry you have entered the parts to remove more than " 
                    << bins[i].numPrt << endl;
            cout << "The bin should not have negative values" << endl;
        }
        else
        {
            bins[i].numPrt = bins[i].numPrt - parts;
        }
             
    }
    void getPart(int i)
    {
       string result;
       int parts;
       cout << "\nDo you want to add or remove parts?(Type add or remove): ";
       cin >> result;
       if(result == "add")
       {
           cout << "\nHow many parts do you want to add?: ";
           cin >> parts;
           addpart(parts, i);
       }
       else if(result == "remove")
       {
           cout << "\nHow many parts do you want to remove?: ";
           cin >> parts;
           remove(parts, i);
       }
       else
       {
           cout << "\nSorry, invalid option";
           cout << endl;
       }
    }
    void problem5()
    {
        cout << "Inventory Bins" << endl << endl;
        string bin;
        bool b = true;
        while(b)
        {
            cout << "\n-----------------------------------------------" << endl;
            cout << "Part Description       Number of parts in the bin" << endl;
            cout << "  -----------------------------------------------" << endl;
            for(int i = 0; i < parts; i++)
            {
                cout << bins[i].part << "     " << bins[i].numPrt << endl;
                cout << "------------------------------------------------------"
                        << endl << endl;
            }
            cout << "Please select a bin: ";
            cin >> bin;
            if(bin == "Valve")
                getPart(0);
            else if(bin == "Bearing")
                getPart(1);
            else if(bin == "Bushing")
                getPart(2);
            else if(bin == "Coupling")
                getPart(3);
            else if(bin == "Flange")
                getPart(4);
            else if(bin == "Gear")
                getPart(5);
            else if(bin == "GearHousing")
                getPart(6);
            else if(bin == "VacuumGripper")
                getPart(7);
            else if (bin == "Cable")
                getPart(8);
            else if(bin == "Rod")
                getPart(9);
            else
                b = false;
        }
        
    }
    void problem6()
    {
           cout<<"Soccer Scores"<<endl<<endl;
           Soccer players[12];
           int total, j;
           int highest = 0;
           for(int i = 0; i < 12; i++)
           {
               cout << "Enter Player Name: ";
               cin.ignore();
               getline(cin, players[i].name);
               cout << "Enter Player Number: ";
               cin >> players[i].number;
               cout << "Enter the number of points the player has: ";
               cin >> players[i].points;
               total = total + players[i].points;
               if(players[i].points > highest)
               {
                   highest = players[i].points;
                   j = i;
               }
           }
           cout << "Player who earned the most points: " << endl;
           cout << players[j].name << endl;
           cout << "Player Number: " << players[j].number << endl;
           cout << "Player had " << highest << " points." << endl;
           
    }
    void getBudg(Budget &b)
    {
        cout << "Student Budget" << endl;
        cout << "\nEnter amount for housing: ";
        cin >> b.housing;
        cout << "\nEnter amount spent for utilities: ";
        cin >> b.util;
        cout << "\nEnter amount spent for house expenses: ";
        cin >> b.expense;
        cout << "\nEnter amount spent for Transportation: ";
        cin >> b.trans;
        cout << "\nEnter amount spent for food: ";
        cin >> b.food;
        cout << "\nEnter amount spent for medical: ";
        cin >> b.medical;
        cout << "\nEnter amount spent for insurance: ";
        cin >> b.insuran;
        cout << "\nEnter amount spent for entertainment: ";
        cin >> b.enterta;
        cout << "\nEnter amount spent for clothing: ";
        cin >> b.clothin;
        cout << "\nEnter amount spent on miscellaneous: ";
        cin >> b.etc;
    }
    void report(Budget b)
    {
        float diff, total;
        cout << "\n\n-------REPORT-------" << endl;
        diff = 500 - b.housing;
        if(diff >=0)
            cout << "Housing expenses are UNDER budget\n";
        else
            cout << "Housing expenses are OVER budget\n";
        diff = 150 - b.util;
        if(diff >=0)
            cout << "Utility expenses are UNDER budget\n";
        else
            cout << "Utility expenses are OVER budget\n";
        diff = 65 - b.expense;
        if(diff >=0)
            cout << "Household expenses are UNDER budget\n";
        else
            cout << "Household expenses are OVER budget\n";
        diff = 50 - b.trans;
        if(diff >=0)
            cout << "Transportation expenses are UNDER budget\n";
        else
            cout << "Transportation expenses are OVER budget\n";
        diff = 250 - b.food;
        if(diff >=0)
            cout << "Food expenses are UNDER budget\n";
        else
            cout << "Food expenses are OVER budget\n";
        diff = 30 - b.medical;
        if(diff >=0)
            cout << "Medical expenses are UNDER budget\n";
        else
            cout << "Medical expenses are OVER budget\n";
        diff = 100 - b.insuran;
        if(diff >=0)
            cout << "Insurance expenses are UNDER budget\n";
        else
            cout << "Insurance expenses are OVER budget\n";
        diff = 150 - b.enterta;
        if(diff >=0)
            cout << "Entertainment expenses are UNDER budget\n";
        else
            cout << "Entertainment expenses are OVER budget\n";
        diff = 75 - b.clothin;
        if(diff >=0)
            cout << "Clothing expenses are UNDER budget\n";
        else
            cout << "Clothing expenses are OVER budget\n";
        diff = 50 - b.etc;
        if(diff >=0)
            cout << "Miscellaneous expenses are UNDER budget\n";
        else
            cout << "Miscellaneous expenses are OVER budget\n";
        total = b.clothin + b.enterta + b.food + b.expense + b.housing + 
                b.insuran + b.medical + b.trans + b.util + b.etc;
        if(total > 1420)
            cout << "Monthly expenses are OVER the budget\n";
        else
            cout << "Monthly expenses are UNDER the budget\n";
    
    }
    void problem7()
    {
            cout <<"Monthly Budget"<<endl<<endl;
            Budget budget1;
            getBudg(budget1);
            report(budget1);
    }
    void find(int i)
    {
        float total;
        float amount, change;
        cout << "Please enter the amount: $";
        cin >> amount;
        while(amount < 0 || amount > 1)
        {
            cout << "\nPlease enter the amount between $0 and $1 $: ";
            cin >> amount;
        }
        change = amount - machine[i].cost;
        cout << "\nYour change is: $" << change;
        machine[i].numleft = machine[i].numleft - 1;
        total = total + machine[i].cost;
        cout << "\nTotal amount of money the machine earned: $" << total 
                    <<endl;
    }
    void problem8()
    {
            cout<<"Drink Machine Simulator"<<endl<<endl;
            string drink;
            bool b = true;
            while(b)
            {
                cout << "------------ List of Drinks -----------------" << endl;
                cout << "Drink Name     Cost        Number in Machine" << endl;
                cout << "---------------------------------------------" << endl;
                for(int i = 0; i < size; i++) 
                {
                    cout << machine[i].name << "          " << machine[i].cost 
                            << "            " << machine[i].numleft << endl;
                }
                cout << endl;
                cout << "Enter the exact name of the drink you want or anything"
                        " else to quit: ";
                cin >> drink;
                if(drink == "Cola")
                    find(0);
                else if(drink == "RootBeer")
                    find(1);
                else if(drink == "LemonLime")
                    find(2);
                else if(drink == "GrapeSoda")
                    find(3);
                else if(drink == "CreamSoda")
                    find(4);
                else
                    b = false;
            } 
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }