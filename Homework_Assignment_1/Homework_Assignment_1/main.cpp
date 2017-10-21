//Zachary Leblond
//September 4th, 2017

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
float celsius(float);
void problem7();
void problem8();
int bSearch(const string array[], int size, string name);
void strSort(string names[], int size);
void problem9();
void problem10();


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
          case 9:    problem9();break;
          case 10:   problem10();break;
          default:   def(inN);}
        }while(inN<11);
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
           cout<<"Type 9 for problem 9"<<endl;
           cout<<"Type 10 for problem 10"<<endl;
           cout<<"Type 11 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    
    void problem1()
    {
        // Celsius to Fahrenheit Temperature Conversion
        float fahr, celsius;
        cout << "Enter a Celsius Temperature to convert to Fahrenheit: ";
        cin >> celsius;
        fahr = (9/5.0) * celsius + 32;
        cout << celsius << " degrees Celsius is " << fahr << " degrees "
                "Fahrenheit." << endl;
    }
    void problem2()
    {
        //U.S. dollar amounts converted to Yen and Euros. Fixed-point notation
        float dollar, yen, euro;
        cout << "Enter an amount of U.S. dollars to convert to Yen and Euros: ";
        cin >> dollar;
        yen = dollar * 109.69;
        euro = dollar * 0.84;
        cout << setprecision(2) << fixed;
        cout << dollar << " dollars is equivalent to " << yen 
                << " yen and " << euro << " euros." << endl;
    }
    void problem3()
    {
        //Days in a month 
        int month, year, days;
        cout << "Enter the month(1-12): ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;
        if(month == 4 || month == 6 || month == 9 || month == 11){
            days = 30;
            cout << days << " days.\n;";
        }
        else if(month == 2) {
            if(year % 100 != 0 && year % 4 == 0) {
                days = 29;
                cout << days << " days.\n";
            }
            else {
                days = 28;
                cout << days << " days.\n";
            }
        }
        else {
            days = 31;
            cout << days << " days.\n";
        }       
    }
    void problem4()
    {
         // Minimum/Maximum
        int num1, num2;
        cout << "Find the Maximum and Minimum number. Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        if(num1 > num2)
            cout << num1 << " is the maximum number.\n";
        else if(num1 < num2)
            cout << num2 << " is the maximum number.\n";
        else
            cout << "The numbers are the same." << endl;
    }
    void problem5()
    {
        //Miles Per Gallon
        float gallons, miles, mpg;
        cout << "Miles per gallon(MPG) calculator. Enter the number of gallons"
                " your vehicle can hold: ";
        cin >> gallons;
        cout << "Enter the number of miles your vehicle can travel on a full "
                "tank of gas: ";
        cin >> miles;
        mpg = miles/gallons;
        cout << "Your vehicle gets " << mpg << " miles to the gallon." << endl;
    }
    void problem6()
    {
        //Population Growth
        int start, rate, time;
        cout << "This program will predict the size of a population of "
                "organisms.";
        cout << "Enter the starting number of organisms: ";
        cin >> start;
        if(start < 2)
        {
            cout << "Need at least two to populate, try again: ";
            cin >> start;
        }
        cout << "Enter their average daily population increase(As a "
                "percentage): ";
        cin >> rate;
        if(rate < 0)
        {
            cout << "The average daily population increase must be positive, "
                    "try again: ";
            cin >> rate;
        }
        rate = (rate * start) / 100;
        cout << "Enter the number of days they will multiply: ";
        cin >> time;
        for(int i=0; i< time; i++)
        {
            cout << "Day " << i+1 << " : " << start << endl;
            start = start + rate;
        }
    }
    float celsius(float f)
    {
        //Fahrenheit to Celsius Function
        float c;
        c = (9.0 / 5.0)*(f - 32);
        return c;
    }
    void problem7()
    {
        //Celsius Temperature Table
        float fTemp, cTemp;
        cout << "-------------------------\n";
        cout << "Celsius Temperature Table\n";
        cout << "-------------------------\n";
        cout << "Fahrenheit        Celsius\n";
        cout << "-------------------------\n";
        for(int i =0; i < 21; i++)
        {
            cTemp = celsius(fTemp);
            cout << setw(2) << i << "                  " << cTemp << endl;
            fTemp++;
        }
    }
    void problem8()
    {
	//Rain or Shine
        cout << "Rain or Shine\n";
        const int months = 3;
        const int days = 30;
        int types = 3;
        char weather[months][days];
        int month;
        int sMonth = 0;
        int rMonth = 0;
        int cMonth = 0;
        int rainy = 0;
        int sunny = 0;
        int cloudy = 0;
        int temp = 0;
        string line;
        ifstream in;
        in.open("RainOrShine.txt");
        if(in.is_open())
        {
            for(month = 0; month < months; month++)
               {
                sMonth = 0;
                rMonth = 0;
                cMonth = 0;
                for(int day = 0; day < days; day++)
                   {
                       in >> weather[month][day];
                       cout << weather[month][day] << " ";
                       if(weather[month][day] == 'R')
                       {
                           rainy++;
                           rMonth++;
                       }
                       if(weather[month][day] == 'S')
                       {
                           sunny++;
                           sMonth++;
                       }
                       if(weather[month][day] == 'C')
                       {
                           cloudy++;
                           cMonth++;
                       }
                   }
                cout << rMonth <<" rainy days, " << sMonth << " sunny days, "
                        "and " << cMonth << " cloudy days in month " << month 
                        << endl; 
                if(cMonth > temp)
                    temp = cMonth;
               }
            cout << "Month " << (month - 1) << " had the most rainy days: " 
                    << (temp - 1) << " rainy days";
        }
        else
        {
            cout << "Error opening file";
        }
        cout << "\nDuring the three month summer season " << rainy << 
                " days were rainy, " << sunny << " days were sunny,"
                << "and " << cloudy << " days were cloudy. \n";
        in.close();
        
    }
    int bSearch(const string array[], int size, string name)
    {
        int first = 0;
        int last = size - 1;
        int position = -1;
        int middle = -1;
        bool found = false;
        while(!found && first <= last)
        {
            middle = (first + last) / 2;
            if(array[middle] == name)
            {
                found = true;
                position = middle;
            }
            else if(array[middle] > name)
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
        }
        return position;
            
    }
    void strSort(string names[], int size)
    {
        //string sort
        int start, mIndex;
        string mVal;
        for(start = 0; start < (size - 1); start++)
        {
            mIndex = start;
            mVal = names[start];
            for(int index = start + 1; index < size; index++)
            {
                if(names[index] < mVal)
                {
                    mVal = names[index];
                    mIndex = index;
                }
            }
            names[mIndex] = names[start];
            names[start] = mVal;
        }
    }
    void problem9()
    {
	const int size = 20;
        int results;
        string empName;
        string names[size] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", 
                              "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                              "Taylor, Terry", "Johnson, Jill", "Allison, Jeff", 
                              "Looney, Joe", "Wolfe, Bill", "James, Jean", 
                              "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", 
                              "Javens, Renee", "Harrison, Rose", 
                              "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"
                            };
        for(int i =0; i < (size-1); i++)
        {
            cout << " " << names[i] << " ";
        }
        cout << "\nEnter the name of the employee you'd like to search: ";
        cin.ignore();
        getline(cin, empName);
        cout << "-------------------------------------------------------------";
        cout << "-------------------------------------------------------------";
        cout << endl;
        cout << "Array of employees before sort: \n";
        for(int i =0; i < (size-1); i++)
        {
            cout << " " << names[i] << " ";
        }
        cout << "\n" << endl;
        cout << "-------------------------------------------------------------";
        cout << "-------------------------------------------------------------";
        cout << "\n" << endl;
        strSort(names, size);
        cout << "Array of employees after sort: \n";
        for(int i =0; i < (size-1); i++)
        {
            cout << " " << names[i] << " ";
        }
        cout << "\n" << endl;
        cout << "-------------------------------------------------------------";
        cout << "-------------------------------------------------------------";
        cout << "\n" << endl;
        results = bSearch(names, size, empName);
        if(results == -1)
        {
            cout << empName << " is not in the array." << endl;
        }
        else
        {
            cout << "Employee " << empName << " found at the index " << 
                    (results + 1) << " in the array.\n";
        } 
    }
    void problem10()
    {
        int input;
        int sum = 0;
        cout<<"Sum of all numbers. Enter a positive integer value: ";
        cin >> input;
        for(int i = 0; i <= input; i++)
        {
           sum += i;
        }
        cout << "The sum of all integers from 1 up to " << input << " is " << 
                sum << endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }