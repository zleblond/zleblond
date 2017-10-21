//Zachary Leblond
//October 20th, 2017
//Assignment 4

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"
#include "Date.h"
#include "Employee.h"
#include "PersonalInfo.h"
#include "Retail.h"
#include "InventoryItem.h"

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();


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
          default:   def(inN);}
        }while(inN<7);
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
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void problem1()
    {
           
           Date input(1, 1, 2001);
           int day, month, year;
           cout<<"Date Class"<<endl<<endl;
           cout << "Enter a date to have it displayed in three formats.\n";
           cout << "Enter the day(In the format DD): ";
           cin >> day;
           if(day < 1 || day > 31)
           {
               cout << "Must be a day in the range of 1 - 31. Re enter: ";
               cin >> day;
           }
           cout << "Enter the month(In the format MM): ";
           cin >> month;
           if(month < 1 || month > 12)
           {
               cout << "Must be a month in the range of 1 - 12. Re enter: ";
               cin >> month;
           }
           cout << "Enter the year(In the format YYYY): ";
           cin >> year;
           input.setDate(month, day, year);
           cout << "Format 1: ";
           input.firstD();
           cout << "Format 2: ";
           input.secondD();
           cout << "Format 3: ";
           input.thirdD();
    }
    void problem2()
    {
           cout<<"Employee Class"<<endl<<endl;
           Employee e1("Susan Meyers", 47899, "Accounting", "Vice President");
           Employee e2("Mark Jones", 39119);
           e2.setDepartment("IT");
           e2.setPosition("Programmer");
           Employee e3;
           e3.setName("Joy Rogers");
           e3.setIdNumber(81774);
           e3.setDepartment("Manufacturing");
           e3.setPosition("Engineer");
           cout<<e1.getName()<<", "<<e1.getIdNumber()<<", "<<e1.getDepartment()
                   <<", "<<e1.getPosition()<<endl;
           cout<<e2.getName()<<", "<<e2.getIdNumber()<<", "<<e2.getDepartment()
                   <<", "<<e2.getPosition()<<endl;
           cout<<e3.getName()<<", "<<e3.getIdNumber()<<", "<<e3.getDepartment()
                   <<", "<<e3.getPosition()<<endl;
    }
    void problem3()
    {
           cout<<"Car Class"<<endl<<endl;
           Car car(2011, "abc");
           for(int faster = 0; faster < 5; faster++)
           {
               car.accelerate();
               cout << "The current speed while accelerating is: " << 
                       car.getSpeed() << endl;
           }
           for(int slower = 0; slower < 5; slower++)
           {
               car.brake();
               cout << "Now the current speed is: " << car.getSpeed() << endl;
           }
           cout << endl;
    }
    void problem4()
    {
           cout<<"Personal Information Class"<<endl<<endl;
           PersonalInfo yourInfo;
           PersonalInfo friendInfo;
           PersonalInfo familyInfo;
           
           cout << "Enter your information" << endl;
           yourInfo.readData();
           cout << "Enter your friends' information" << endl;
           friendInfo.readData();
           cout << "Enter your family members' information" << endl;
           familyInfo.readData();
           
           cout << "-- Your Info -- " << endl;
           yourInfo.displayData();
           cout << "-- Your friends info -- " << endl;
           friendInfo.displayData();
           cout << "--Your familys info -- " << endl;
           familyInfo.displayData();
    }
    void problem5()
    {
           RetailItem jacket("Jacket",12,59.95);
           RetailItem dJeans("Designer Jeans",40,34.95);
           RetailItem shirt("Shirt",20,24.95);

           jacket.describeItem();
           dJeans.describeItem();
           shirt.describeItem();
           getchar();
    }
    void problem6()
    {
           cout<<"Inventory Item"<<endl<<endl;
           InventoryItem item1;
           item1.setdesc("Hammer"); 
           item1.setIitemno(2);
           item1.setCost(6.95); 
           item1.setQuantity(12); 
           cout<<"Item 1:"<<endl;
           cout<<"desc:"<<item1.getdesc()<<endl;
           cout<<"Item Number:"<<item1.getIitemno()<<endl;
           cout<<"Quantity:"<<item1.getCost()<<endl;
           cout<<"Cost:"<<item1.getCost()<<endl;
           cout<<"Total Cost:"<<item1.gettcost()<<endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }