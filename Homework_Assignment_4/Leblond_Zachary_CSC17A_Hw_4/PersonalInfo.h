
#ifndef PERSONALINFO_H
#define PERSONALINFO_H
class PersonalInfo
{
private:
    string name;
    string address;
    int age;
    int phoneNum;
public:
    void setName(string nameParam)
    {
        name = nameParam;
    }
    void setAddress(string addressParam)
    {
        address = addressParam;
    }
    void setAge(int ageParam)
    {
        age = ageParam;
    }
    void setPhoneNum(int phoneNumParam)
    {
        phoneNum = phoneNumParam;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    int getPhoneNum()
    {
        return phoneNum;
    }
    
    void readData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter phone number: ";
        cin >> phoneNum;
    }
    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phoneNum << endl;
    } 
};


#endif /* PERSONALINFO_H */

