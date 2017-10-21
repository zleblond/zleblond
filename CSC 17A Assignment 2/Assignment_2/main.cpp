//Zachary Leblond
//September 20th, 2017

#include <iostream>
using namespace std;

void Menu();
int getN();
void def(int);

void problem1();
int *dynArry(int numElem);

void problem2();
void sort(int*, int);
float avg(int*, int);
void print(int*, int);

void problem3();
void lowSort(int*, int);
float lowAvg(int*, int);

void problem4();
void nameSrt(int*, string*, int);
float avg2(int*, int);

void problem5();

void problem6();
void aSelSrt(int *[], int); // Array Selection Sort (Ascending order)
void showAry(const int [], int); // Show Array
void shwArPt(int *[], int); // Show Array Pointer
   
void problem7();
void aryDSrt(int *[], int); //Array Selection Sort (Descending order)

void problem8();

void problem9();
int mode(int *, int);
int mean(int *, int);
int median(int *, int);

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
          default:   def(inN);}
        }while(inN<10);
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
           cout<<"Type 10 to exit \n"<<endl;
    }
    
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    
    void problem1()
    {
        int *array;
        int numElem;
           cout<<"Array Allocator"<<endl<<endl;
           cout << "Enter the number of elements for the dynamic array: ";
           cin >> numElem;
           array = dynArry(numElem);
           for(int i = 0; i < numElem; i++)
           {
               cout << array[i] << " ";
           }
           delete []array;
           cout << endl;
    }
    int *dynArry(int numElem) 
    {
        int *a = new int [numElem];
        for(int i = 0; i < numElem; i++)
        {
            cout << "Enter the element #" << (i + 1) << ": ";
            cin >> a[i];
        }
        return a;   
    }
    
    void problem2()
    {
           cout<<"Test Scores #1"<<endl<<endl;
           int num, scores;
           cout << "Enter the total number of test scores to be input: ";
           cin >> num;
           int *array = new int [num];
           cout << "Enter " << num << " test scores.\n ";
           for(int i = 0; i < num; i++)
           {
               cout << "Test Score #" << (i + 1) << ": ";
               cin >> scores;
               while(scores < 0) 
               {
                   cout << "Enter only positive test scores. Test Score #" << 
                           (i + 1) << ": ";
                   cin >> scores;
               }
               array[i] = scores;
           }
           cout << "Array before sort:  ";
           for(int i=0; i<num; i++)
           {
               cout << array[i] << "  ";
           }
           sort(array, num);
           cout << "Array after sort:  ";
           print(array, num);
           avg(array, num);
           cout << endl;
           delete[]array;
    }
    void sort(int* array, int num)
    {
        for(int i = 0; i < (num - 1); i++)
        {
            for(int j = i+1; j<num; j++)
            {
                if(array[i] > array[j])
                {
                    array[i] = array[i]^array[j];
                    array[j] = array[i]^array[j];
                    array[i] = array[i]^array[j];
                }
            }
        }
    }
    float avg(int* array, int num)
    {
        float sum = 0;
        float average = 0;
        for(int i = 0; i < num; i++)
        {
            sum += array[i];
        }
        average = sum / num;
        cout << "Average test score: " << average;
        return average;      
    }
    void print(int* array, int num)
    {
        for(int i=0; i < num; i++)
        {
            cout << array[i] << "  ";
        }
    }
    
    void problem3()
    {
           cout<<"Drop Lowest Score"<<endl<<endl;
           
           int num, scores;
           cout << "Enter the total number of test scores to be input: ";
           cin >> num;
           int *array = new int [num];
           cout << "Enter " << num << " test scores.\n ";
           for(int i = 0; i < num; i++)
           {
               cout << "Test Score #" << (i + 1) << ": ";
               cin >> scores;
               while(scores < 0) 
               {
                   cout << "Enter only positive test scores. Test Score #" << 
                           (i + 1) << ": ";
                   cin >> scores;
               }
               array[i] = scores;
           }
           cout << "Array before sort:  ";
           for(int i=0; i<num; i++)
           {
               cout << array[i] << "  ";
           }
           lowSort(array, num);
           cout << "Array after sort:  ";
           print(array, num);
           lowAvg(array, num);
           cout << endl;
           delete[]array;
    }
    void lowSort(int* array, int num)
    {
        int lowestS; // Lowest Score
        int lowestI; // Lowest Index
        for (int i = 0; i < (num - 1); i++)
        {
            lowestS = array[i];
            lowestI = i;
            for (int j = i + 1; j < num; j++) 
            {
                if(lowestS > array[j])
                {
                    lowestS = array[j];
                    lowestI = j;
                }
            }
                array[lowestI] = array[i];
                array[i] = lowestS;
        }
    }
    float lowAvg(int* array, int num)
    {
        float sum = 0;
        float average = 0;
        for(int i = 1; i < num; i++)
        {
            sum += array[i];
        }
        average = sum / num;
        cout << "Average test score: " << average << endl;
        average = sum / (num - 1);
        cout << "Average test score after dropping the lowest score: " << 
                average;
        return average;
    }  

    void problem4()
    {
           cout<<"Test Scores #2"<<endl<<endl;
           int num;
           float average;
           int *array2 = new int [num];
           string *names = new string [num];
           cout << "Enter the number of test scores: ";
           cin >> num;
           
           for(int i = 0; i < num; i++)
           {
               cout << "Enter the students name: ";
               cin >> names[i];
               cout << "Enter test score: ";
               cin >> array2[i];
           }
           nameSrt(array2, names, num);
           cout << "Name\t" << "Test Score" << endl;
           for(int i = 0; i < num; i++)
           {
               cout << names[i] << "\t";
               cout << array2[i] << endl;
           }
           average = avg2(array2, num);
           cout << endl;
           delete []array2;
    }
    void nameSrt(int* array2, string* names, int num)
    {
        int minIndx;
        for(int i = 0; i < num - 1; i++)
        {
            minIndx = i;
            for(int j = i + 1; j < num; j++)
            {
                if(*(array2 + j) < *(array2 + minIndx))
                {
                    minIndx = j;
                    int temp = array2[minIndx];
                    array2[minIndx] = array2[i];
                    array2[i] = temp;
                    //
                    string temp1 = names[minIndx];
                    names[minIndx] = names[i];
                    names[i] = temp1;
                }
            }
        }
    }
    float avg2(int *array, int num)
    {
        float sum = 0;
        for(int i = 0; i < num; i++)
        {
            sum += array[i];
        }
        return sum / num;
    }
    
    void problem5()
    {
           cout<<"Median Function"<<endl<<endl;
           int size, aMedian;
           cout << "Enter the size of the array: ";
                cin >> size;
                int *mArray = new int [size];
                cout << "Enter the number set: ";
                for(int i=0; i < size; i++)
                {
                    cout << "Number " << (i + 1) << ": ";
                    cin >> mArray[i];
                }
                sort(mArray, size);
                aMedian = median(mArray, size);
                cout << "The median of the array is: " << aMedian << endl;
                delete [] mArray;   
    }

    void problem6()
    {
           cout<<"Case Study Modification #1"<<endl<<endl;
           int numDono = 0; // Number of donations
           cout << "Enter the number of donations: ";
           cin >> numDono;
           int **arrPtr = new int*[numDono];
           int *donations = new int[numDono];
           for(int i = 0; i < numDono; i++)
           {
               cout << "Enter donation #" << (i + 1) << ": ";
               cin >> donations[i];
               arrPtr[i] = &donations[i];
           }
           aSelSrt(arrPtr, numDono);
           cout << "\nThe donations: ";
           showAry(donations, numDono);
           cout << "\nThe Donations in Ascending order: ";
           shwArPt(arrPtr, numDono);
           cout << endl;
           delete []arrPtr;
           delete []donations;
    }
    void aSelSrt(int *arrPtr[], int numDono) // Array Selection Sort
    {
        int strtScn, mIndx; // startScan, minimumIndex
        int *minElem;
        for(strtScn = 0; strtScn < (numDono - 1); strtScn++)
        {
            mIndx = strtScn;
            minElem = arrPtr[strtScn];
            for(int index = strtScn + 1; index < numDono; index++)
            {
                if (*(arrPtr[index]) < *minElem)
                {
                    minElem = arrPtr[index];
                    mIndx = index;
                }
            }
            arrPtr[mIndx] = arrPtr[strtScn];
            arrPtr[strtScn] = minElem;
        }
    }
    void showAry(const int donations[], int numDono) // Show Array
    {
        //Display the original input dynamic array elements
        for(int i = 0; i < numDono; i++)
        {
            cout << donations[i] << " ";
        }
    }
    void shwArPt(int *arrPtr[], int numDono) // Show Array Pointer
    {
        //Display the sorted dynamic array elements
        for(int i = 0; i < numDono; i++)
        {
            cout << *(arrPtr[i]) << " ";
        }
    }
    
    void problem7()
    {
           cout<<"Case Study Modification #2"<<endl<<endl;
           int numDono = 0; // Number of donations
           cout << "Enter the number of donations: ";
           cin >> numDono;
           int **arrPtr = new int*[numDono];
           int *donations = new int[numDono];
           for(int i = 0; i < numDono; i++)
           {
               cout << "Enter donation #" << (i + 1) << ": ";
               cin >> donations[i];
               arrPtr[i] = &donations[i];
           }
           aryDSrt(arrPtr, numDono);
           cout << "\nThe donations: ";
           showAry(donations, numDono);
           cout << "\nThe Donations in Descending order: ";
           shwArPt(arrPtr, numDono);
           cout << endl;
           delete []arrPtr;
           delete []donations;
    }
    void aryDSrt(int *arrPtr[], int numDono) //Array Selection Sort (Descending order)
    {
        int strtScn, mIndx; // startScan, minimumIndex
        int *minElem;
        for(strtScn = 0; strtScn < (numDono - 1); strtScn++)
        {
            mIndx = strtScn;
            minElem = arrPtr[strtScn];
            for(int index = strtScn + 1; index < numDono; index++)
            {
                if (*(arrPtr[index]) > *minElem)
                {
                    minElem = arrPtr[index];
                    mIndx = index;
                }
            }
            arrPtr[mIndx] = arrPtr[strtScn];
            arrPtr[strtScn] = minElem;
        }
    }
    
    void problem8()
    {
		cout<<"Mode Function"<<endl<<endl;
                int size, modeFx; //mode function
                cout << "Enter the size of the array: ";
                cin >> size;
                int *a = new int [size];
                cout << "Enter the number set: ";
                for(int i = 0; i < size; i++)
                {
                    cout << "Number " << (i+1) << ": ";
                    cin >> a[i];
                }
                sort(a, size);
                modeFx = mode(a, size);     
    }
    
    
    void problem9()
    {
		cout<<"Mean, Median, and Mode"<<endl<<endl;
                int size, aMedian, aMode, aMean;
                cout << "Enter the size of the array: ";
                cin >> size;
                int *mArray = new int [size];
                cout << "Enter the number set: ";
                for(int i=0; i < size; i++)
                {
                    cout << "Number " << (i + 1) << ": ";
                    cin >> mArray[i];
                }
                sort(mArray, size);
                aMean = mean(mArray, size);
                aMedian = median(mArray, size);
                aMode = mode(mArray, size);
                cout << "The mean of the array is: " << aMean << endl;
                cout << "The median of the array is: " << aMedian << endl;
                delete []mArray;
    }
    int mode(int *mArray, int size)
    {
        int num =0;
        int maxima = 0;
        int mode;
        int c[size];
        int numMode = 1;
        int i;
        for(i=0;i<size;i++){
            c[i]=0;
        }
        for(i=0;i<size;i++){
                for(int j =i;j<size;j++){
                    if(mArray[j]==mArray[i]){
                        c[j]++;
                        if(c[j]>=maxima){
                            maxima = c[j];
                        }
                    }
                }
        }
        cout<< "The mode of the array is/are: ";
        for(i=0;i<size;i++){
            //cout<<c[i];
            if(c[i]==maxima){
                mode = mArray[i];
                cout << mode <<" ";
            }
        }
     }
        
    int mean(int *mArray, int size)
    {
        float average;
        for(int i=0; i<size; i++)
        {
            average += mArray[i];
        }
        return average / size;
    }
    int median(int *mArray, int size)
    {
        int median;
        if(size%2 == 0)
        {
            median = (mArray[size/2] + mArray[size/2-1]) / 2;
        }
        else
        {
            median = mArray[size/2];
        }
        return median;
    }
    
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }