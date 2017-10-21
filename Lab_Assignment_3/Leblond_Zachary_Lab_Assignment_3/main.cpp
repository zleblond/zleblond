//Zachary Leblond
//CSC17A Lab 3

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

#include "Inventory.h"

void Menu();
int getN();
void def(int);

int count(char *);
void problem1();

void reverse(char *);
void problem2();

int numWord(char *, int);
void problem3();

void problem4();

void capital(char *, int);
void problem5();

void add();
void display();
void edit();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

class Company{
   public:
       string name;
       int quarter[4];
       int sales[4];
};

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
    int count(char *word)
    {
       int length;
       length = strlen(word);
       return length;
    }
    void problem1()
    {
        cout<<"String Length"<<endl<<endl;
        const int size = 50;
        char word[size];
        cout << "Enter a string to have the number of characters counted: ";
        cin.ignore();
        cin.getline(word, size);
        cout << word << " has " << count(word) << " characters.\n";  
    }
    void reverse(char *original)
    {
        char *backward = original;
        while(*backward != '\0')
        {
            backward++;
        }
        while(backward != original)
        {
            *backward--;
            cout << *backward;
        }
        cout << endl;
        
    }
    void problem2()
    {
        cout<<"Backward String"<<endl<<endl;
        const int size = 50;
        char original[size];
        cout << "Enter a string: ";
        cin.ignore();
        cin.getline(original, size);
        reverse(original);
    }
    int numWord(char *cntWord, int size)
    {
        int count = 1;
        int c;
        for(int i = 0; i < size; i++)
        {
            cntWord[i] = c;
            if(cntWord[i] == c && cntWord[i+1] == ' ')
            {
                count++;
            }
        }
        return count;
       
    }
    void problem3()
    {
        cout<<"Word Counter"<<endl<<endl;
        const int size = 50;
        char cntWord[size];
        int num;
        cout << "Enter a string to have the number of words counted: ";
        cin.ignore();
        cin.getline(cntWord, size);
        cout << cntWord << endl;
        num = numWord(cntWord, size);
        cout << "Number of words: " << num << endl << endl;              
    }
    void problem4()
    {
        cout<<"Average Number of Letters"<<endl<<endl;
        const int size = 50;
        char avgNum[size];
        float counter = 0;
        int words = 1;
        float average = 0;
        int length;
        cout << "Enter a string to count the average number of "
                "letters per word: ";
        cin.ignore();
        cin.getline(avgNum, size);
        length = strlen(avgNum);
        for(int i = 0; i < length; i++)
        {
            if(avgNum[i] == ' ')
            {
                words++;
            }
            else
                counter++;
        }
        average = counter / words;
        cout << "The average number of letters is " << average << endl << endl;  
    }
    void capital(char *phrase, int size)
    {
        if(phrase[0] != ' ')
        {
            phrase[0] = toupper(phrase[0]);
        }
        for(int i = 0; i < size; i++)
        {
            if(phrase[i] == '.' || phrase[i] == '?')
            {
                phrase[i+2] = toupper(phrase[i+2]);
            }
        }
        cout << phrase;
    }
    void problem5()
    {
        cout<<"Sentence Capitalizer"<<endl<<endl;
        const int size = 50;
        char phrase[size];
        cout << "Enter a sentence in lower case to have the proper "
                "capitalization applied: ";
        cin.ignore();
        cin.getline(phrase, size);
        capital(phrase, size);
        cout << endl;
        
    }
    void add()
    {
        fstream out;
        char ch;
        int i = 0;
        out.open("Records.txt", ios::out | ios::binary);
        Inventory inv;
        do
        {
            cout << "Enter item description: ";
            cin.ignore();
            cin.getline(inv.item, size);
            cout << "Enter quantity: ";
            cin >> inv.qty;
            cout << "Enter wholesale cost: ";
            cin >> inv.wCost;
            cout << "Enter retail cost: ";
            cin >> inv.rCost;
            cout << "Enter date(DD/MM/YY): ";
            cin.ignore();
            cin.getline(inv.date, 9);
            out.write(reinterpret_cast<char*>(&inv), sizeof(inv));
            cout<<"Do you want to add another record? Y for yes anything else "
                "for no: ";
            cin>>ch;
        }while(ch == 'Y' && i<3);
        out.close();   
    }
    void display()
    {
        fstream fout;
        fout.open("Records.txt", ios::in);
        Inventory inv;
        fout.read(reinterpret_cast<char*>(&inv),sizeof(inv));
        while(!fout.eof())
        {
        cout<<"\nDescription\t";
        cout<<inv.item;
        cout<<"\nQuantity\t";
        cout<<inv.qty;
        cout<<"\nWhole sale cost\t";
        cout<<inv.wCost;
        cout<<"\nRetail cost\t";
        cout<<inv.rCost;
        cout<<"\nDate\t";
        cout<<inv.date << endl;
        fout.read(reinterpret_cast<char*>(&inv), sizeof(inv));
        }
        fout.close(); 
    }
    void edit()
    {
        fstream fout;
        fout.open("Records.txt", ios::in | ios::out);
        Inventory inv;
        int recNum;
        cout<<"Enter the number of the record you want to edit: ";
        cin>>recNum;
        fout.seekg(recNum*sizeof(inv), ios::beg);
        fout.read(reinterpret_cast<char*>(&inv), sizeof(inv));
        cout<<"\nDescription\t";
        cout<<inv.item;
        cout<<"\nQuantity\t";
        cout<<inv.qty;
        cout<<"\nWhole sale cost\t";
        cout<<inv.wCost;
        cout<<"\nRetail cost\t";
        cout<<inv.rCost;
        cout<<"\nDate\t";
        cout<<inv.date;

        cout<<"\nEnter new data\n";
        cout<<"Enter new item description: ";
        cin.ignore();
        cin.getline(inv.item, size);
        cout<<"Enter new quantity: ";
        cin>>inv.qty;
        cout<<"Enter new wholesale cost: ";
        cin>>inv.wCost;
        cout<<"Enter new retail cost: ";
        cin>>inv.rCost;
        cout<<"Enter new date: ";
        cin.ignore();
        cin.getline(inv.date, 9);
        fout.write(reinterpret_cast<char*>(&inv), sizeof(int));
        fout.close();
    }
    void problem6()
    {
        cout<<"Inventory Program"<<endl<<endl;
        int choice;
        do 
        {
            cout<<"MENU\n";
            cout<<"1.Add Record\n";
            cout<<"2.Display Record\n";
            cout<<"3.Edit Record\n";
            cout<<"4.To exit\n";
            cout<<"Enter your choice: \n";
            cin >> choice;
            switch(choice)
            {
                case 1: add();break;
                case 2: display();break;
                case 3: edit();break;
                case 4: break;
                default: cout<<"Invalid choice\n";
            }        
        }while(choice <=3);
    }
    void problem7()
    {
        cout<<"Corporate Sales Data Output"<<endl<<endl;
        Company c;
        fstream out;
        out.open("corporateData.txt", ios::out);
        if(!out)
        {
            cout << "Error creating file.";
        }
        else
        {
            for(int i = 0; i < 4; i++)
            {
                cout << "Enter the division(East, West, North, or South): ";
                cin >> c.name;
                out << c.name << " ";
                for(int j = 0; j < 4; j++)
                { 
                    cout << "Enter the quarter number(1-4): ";
                    cin >> c.quarter[i];
                    out << c.quarter[i] << " ";
                    cout << "Enter quarter "<< j + 1 << " sales: ";
                    cin >> c.sales[i];
                    if(c.sales[i] < 0)
                    {
                        cout<<"Enter only positive sales: ";
                        cin>> c.sales[i];
                    }
                    out << c.sales[i] << " ";
                    if(j == 3)
                    {
                        out << "|";
                        cout << endl;
                    }
                }               
            }
            cout << "Sales data has been written to the file named "
                    "corporateData.txt\n" << endl;
        }
        out.close();
    }
    void problem8()
    {
        cout<<"Corporate Sales Data Input"<<endl<<endl;
        fstream in;
        string line, wrd, word;
        string data[100];
        
        int inc = 0;
        int totalq1=0,sum1=0,totalq2=0,sum2=0,totalq3=0,sum3=0,totalq4=0,sum4=0;
        int high=sum1;
        int east=0, esale=0,west=0,wsale=0,south=0,ssale=0,north=0,nsale=0;
        int ecount1=0, ecount2=0, ecount3=0, ecount4=0;
        int wcount1=0, wcount2=0, wcount3=0, wcount4=0;
        int ncount1=0, ncount2=0, ncount3=0, ncount4=0;
        int scount1=0, scount2=0, scount3=0, scount4=0;
        
        int esaleamt1=0, esaleamt2=0, esaleamt3=0, esaleamt4=0;
        int wsaleamt1=0, wsaleamt2=0, wsaleamt3=0, wsaleamt4=0;
        int nsaleamt1=0, nsaleamt2=0, nsaleamt3=0, nsaleamt4=0;
        int ssaleamt1=0, ssaleamt2=0, ssaleamt3=0, ssaleamt4=0;
        in.open("corporateData.txt", ios::in);
        if(in.fail())
        {
            cout << "Error opening the file";
        }
        else
        {
            while(in.good())
            {
                getline(in, line, '\n');
                stringstream ss(line);
                while(getline(ss, wrd, '|'))
                {
                    stringstream str(wrd);
                while(getline(str, word, ' '))
                {
                    data[inc] = word;
                    inc++;
                }
                }
            }   
        if(inc > 0)
        {
            for(int i=0; i<inc; i++)
            {
                if(data[i] == "East")
                {
                    east=1;
                    west = south = north = 0;
                }
                if(data[i] == "West")
                {
                    west=1;
                    east = south = north = 0;
                }
                if(data[i] == "North")
                {
                    north=1;
                    west = south = east = 0;
                }
                if(data[i] == "South")
                {
                    south=1;
                    west = east = north = 0;
                }
                if(data[i] == "1")
                {
                    stringstream q1(data[i+1]);
                    q1 >> totalq1;
                    sum1 += totalq1;
                    if(high < sum1)
                        high = sum1;
                    if(east)
                        esale += sum1, esaleamt1+=totalq1, ecount1++;
                    if(west)
                        wsale += sum1, wsaleamt1+=totalq1, wcount1++;
                    if(south)
                        ssale += sum1, ssaleamt1+=totalq1, scount1++;
                    if(north)
                        nsale += sum1, nsaleamt1+=totalq1, ncount1++;
                }
                if(data[i] == "2")
                {
                    stringstream q2(data[i+1]);
                    q2 >> totalq2;
                    sum2 += totalq2;
                    if(high < sum2)
                        high = sum2;
                    if(east)
                        esale += sum2, esaleamt2+=totalq2, ecount2++;
                    if(west)
                        wsale += sum2, wsaleamt2+=totalq2, wcount2++;
                    if(south)
                        ssale += sum2, ssaleamt2+=totalq2, scount2++;
                    if(north)
                        nsale += sum2, nsaleamt2+=totalq2, ncount2++;
                }
                if(data[i] == "3")
                {
                    stringstream q3(data[i+1]);
                    q3 >> totalq3;
                    sum3 += totalq3;
                    if(high < sum3)
                        high = sum3;
                    if(east)
                        esale += sum3, esaleamt3+=totalq3, ecount3++;
                    if(west)
                        wsale += sum3, wsaleamt3+=totalq3, wcount3++;
                    if(south)
                        ssale += sum3, ssaleamt3+=totalq3, scount3++;
                    if(north)
                        nsale += sum3, nsaleamt3+=totalq3, ncount3++;
                }
                if(data[i] == "4")
                {
                    stringstream q4(data[i+1]);
                    q4 >> totalq4;
                    sum4 += totalq4;
                    if(high < sum4)
                        high = sum4;
                    if(east)
                        esale += sum4, esaleamt4+=totalq4, ecount4++;
                    if(west)
                        wsale += sum4, wsaleamt4+=totalq4, wcount4++;
                    if(south)
                        ssale += sum4, ssaleamt4+=totalq4, scount4++;
                    if(north)
                        nsale += sum4, nsaleamt4+=totalq4, ncount4++;
                }
            }
        }
        int low = sum1;
        if(low > sum1 || low == 0)
            low = sum1;
        if(low > sum2 || low == 0)
            low = sum2;
        if(low > sum3 || low == 0)
            low = sum3;
        if(low > sum4 || low == 0)
            low = sum4;
        
       cout << "The Corporate sale for each quarter"<<endl;
       cout << "For first quater : "<<sum1<<endl;
       cout << "For second quater : "<<sum2<<endl;
       cout << "For third quater : "<<sum3<<endl;
       cout << "For fourth quater : "<<sum4<<endl<<endl;
      
       cout << "Highest Corporate value is : " << high << endl;
       cout << "Lowest Corporate value is : " << low << endl<<endl;
      
       cout << "Total yearly sales for each division " << endl;
       cout << "Sale for East division : " << esale << endl;
       cout << "Sale for West division : " << wsale << endl;
       cout << "Sale for South division : " << ssale << endl;
       cout << "Sale for North division : " << nsale << endl<<endl;
      
       cout << "Average quarterly sales for the divisions" << endl;
       cout << "For East " <<endl;
       cout << "For quarter 1 " << (esaleamt1/ecount1) << endl;
       cout << "For quarter 2 " << (esaleamt2/ecount2) << endl;
       cout << "For quarter 3 " << (esaleamt3/ecount3) << endl;
       cout << "For quarter 4 " << (esaleamt4/ecount4) << endl<< endl;
      
       cout << "For West " <<endl;
       cout << "For quarter 1 " << (esaleamt1/wcount1) << endl;
       cout << "For quarter 2 " << (wsaleamt2/wcount2) << endl;
       cout << "For quarter 3 " << (wsaleamt3/wcount3) << endl;
       cout << "For quarter 4 " << (wsaleamt4/wcount4) << endl<< endl;
      
       cout << "For South " <<endl;
       cout << "For quarter 1 " << (ssaleamt1/scount1) << endl;
       cout << "For quarter 2 " << (ssaleamt2/scount2) << endl;
       cout << "For quarter 3 " << (ssaleamt3/scount3) << endl;
       cout << "For quarter 4 " << (ssaleamt4/scount4) << endl<< endl;
      
       cout << "For North " <<endl;
       cout << "For quarter 1 " << (nsaleamt1/ncount1) << endl;
       cout << "For quarter 2 " << (nsaleamt2/ncount2) << endl;
       cout << "For quarter 3 " << (nsaleamt3/ncount3) << endl;
       cout << "For quarter 4 " << (nsaleamt4/ncount4) << endl<< endl;
      
       cout << "Total yearly corporate sales "<< (sum1+sum2+sum3+sum4) <<endl;
       in.close();
        
        }
        cout << endl;
    }
    void problem9()
    {
        cout<<"File Encryption Filter"<<endl<<endl;
        char ch;
        fstream in, out;
        in.open("original.txt", ios::in);
        out.open("encrypted.txt", ios::out);
        if(in.fail() || out.fail())
        {
            cout << "Error opening files.\n";
        }
        else
        {
            cout << "Files opened successfully, Encrypting original file.\n";
        while(in.get(ch))
        {
            out.put(ch + 10);
        }
        }
        cout << "File encrypted, closing files now.\n";
        in.close();
        out.close();
        cout << "Go to problem 10 to have the file decrypted.\n";
    }
    void problem10()
    {
        cout<<"File Decryption Filter"<<endl<<endl;
        char ch, decrypt;
        fstream out, output;
        out.open("encrypted.txt", ios::out | ios::in);
        output.open("decrypted.txt", ios::out);
        while(!out.eof())
        {
            cout<<"File opened successfully.\n";
            out.get(ch);
            decrypt = ch - 10;
            cout<<"File decrypted.\n";
            output.put(decrypt);
            cout << "Decrypted text written to file.\n";
        }
        out.close();
        output.close();
    }
    void def(int inN)
    {
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
