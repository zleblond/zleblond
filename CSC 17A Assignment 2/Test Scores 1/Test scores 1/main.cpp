//Zachary Leblond

#include <cstdlib>
#include <iostream>

using namespace std;

void sortAry(int[], int);
int avg(int[], int);
void prntAry(int[], int);

int main(int argc, char** argv) {

    int n;
    float score;
    cout << "Enter the number of test scores to be calculated: ";
    cin >> n;
    int*a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Enter test score #" << (i + 1) << ": ";
        cin >> score;
        a[i] = score;
        cout << endl;
    }
    sortAry(a, n);
    prntAry(a, n);
    delete[]a;
    
    return 0;
}

void sortAry(int a[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        if(a[i+1] < a[i])
        {
            int temp = a[i+1];
            a[i] = a[i+1];
            a[i+1] = temp; 
        }
    }
}
int avg(int a[], int n)
{
    
}
void prntAry(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}