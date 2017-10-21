
#ifndef CAR_H
#define CAR_H
class Car

{
private:
int yearMade, speed;
string make;

public:
Car(int y, string m)
{
yearMade = y;
make = m;
speed = 0;
}

int getYear()
{
return yearMade;
}

string getMake()
{
return make;
}

int getSpeed()
{
return speed;
}

void accelerate()
{
speed = speed + 5;
}

void brake()
{
speed = speed - 5;
}

};
#endif /* CAR_H */
