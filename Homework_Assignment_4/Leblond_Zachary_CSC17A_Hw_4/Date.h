
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int year;
    int month;
    int day;  
public:
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setDate(int, int, int);
    void firstD();
    void secondD();
    void thirdD();
    string monthName(int);
    Date(int, int, int);
};

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::firstD()
{
    cout << month << "/" << day << "/" << year << endl;
}
void Date::secondD()
{
    string convert;
    convert = monthName(month);
    cout << convert << " " << day << ", " << year << endl;    
}
void Date::thirdD()
{
    string convert;
    convert = monthName(month);
    cout << day << " " << convert << " " << year << endl << endl;
}
string Date::monthName(int m)
{
    string month;
    if(m == 1)
        month = "January";
    else if(m == 2)
        month = "February";
    else if(m == 3)
        month = "March";
    else if(m == 4)
        month = "April";
    else if(m == 5)
        month = "May";
    else if(m == 6)
        month = "June";
    else if(m == 7)
        month = "July";
    else if(m == 8)
        month = "August";
    else if(m == 9)
        month = "September";
    else if(m == 10)
        month = "October";
    else if(m == 11)
        month = "November";
    else if(m == 12)
        month = "December";
    else
        month = "Invalid Month";
    return month;
}

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}


#endif /* DATE_H */