
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee {

private:
string name;
int idNumber;
string department;
string position;

public:
Employee(string n, int i, string d, string p) {
name = n;
idNumber = i;
department = d;
position = p;
}

Employee(string n, int i) {
name = n;
idNumber = i;
department = "";
position = "";
}

Employee() {
name = "";
idNumber = 0;
department = "";
position = "";
}

void setName(string n) {
name = n;
}

void setIdNumber(int i) {
idNumber = i;
}

void setDepartment(string d) {
department = d;
}

void setPosition(string p) {
position = p;
}

string getName() {
return name;
}

int getIdNumber() {
return idNumber;
}

string getDepartment() {
return department;
}

string getPosition() {
return position;
}

};
#endif /* EMPLOYEE_H */

