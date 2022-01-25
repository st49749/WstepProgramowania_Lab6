#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void showAddress(int* ptr);
void showAddressValue(int* ptr);
int addressDifference(int* ptr1, int* ptr2);
int average(int* ptr1, int* ptr2, int* ptr3);
int arrayAvg(int* arrPtr, int arrSize);
int power(int* number);
int* powerN(int* number, int n);
void repeatChar(char* character, int* times);
int* min(int* n1, int* n2);
void swap(int* n1, int* n2);

void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
void zad8();

int main()
{
    srand(time(NULL));

    // zad1();
    // zad2();
    // zad3();
    // zad4();
    // zad5();
    // zad6();
    // zad7();
    zad8();
}

void zad1()
{
    // a
    int zmienna = 1;
    int *ptr = &zmienna;
    showAddress(ptr);
    
    // b
    showAddressValue(ptr);

    // c
    int b = 5;
    int* ptr2 = &b;
    cout << "Sub: " << addressDifference(ptr, ptr2) << endl;

    // d
    int c = 60;
    int* ptr3 = &c;
    cout << "Avg: " << average(ptr, ptr2, ptr3) << endl;
}

void zad2()
{
    const int size = 5;
    int* arr = new int[size];

    // a
    cout << "First address: " << arr << endl;

    // b
    cout << "Last address: " << arr + size - 1 << endl;

    // c
    int range[2] = { 1,10 };
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (range[1] - range[0] + 1) + range[0];
        cout << "Adres: " << arr + i << " value: " << arr[i] << endl;
    }

    delete[] arr;
}

void zad3()
{
    const int size = 10;
    int* arr = new int[size];

    int range[2] = { 1,10 };
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (range[1] - range[0] + 1) + range[0];
        cout << arr[i] << " ";
    }
    cout << endl;

    int average = arrayAvg(arr, size);
    cout << "Average: " << average << endl;
    cout << "Above average elements: " ;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > average)
            cout << arr[i] << " ";
    }

    delete[] arr;
}

void zad4()
{
    int number = 10;
    cout << number << "^2 = " << power(&number) << endl;
}

void zad5()
{
    int number = 10;
    int n = 2;

    int* result = powerN(&number, n);
    cout << *result;
}

void zad6()
{
    char znak = 'a';
    int times = 10;

    repeatChar(&znak, &times);
}

void zad7()
{
    int n1 = 8;
    int n2 = 9;

    cout << *min(&n1, &n2);
}

void zad8()
{
    int n1 = 8;
    int n2 = 9;

    int* ptrN1 = &n1;
    int* ptrN2 = &n2;

    cout << "Before: n1: " << *ptrN1 << ", n2: " << *ptrN2 << endl;
    swap(ptrN1, ptrN2);
    cout << "After: n1: " << *ptrN1 << ", n2: " << *ptrN2 << endl;
}

void showAddress(int* ptr)
{
    cout << "Address: " << ptr << endl;
}
void showAddressValue(int* ptr)
{
    cout << "Address Value: " << *ptr << endl;
}

int addressDifference(int* ptr1, int* ptr2)
{
    return *ptr1 - *ptr2;
}

int average(int* ptr1, int* ptr2, int* ptr3)
{
    return (*ptr1 + *ptr2 + *ptr3) / 3;
}

int arrayAvg(int* arrPtr, int arrSize)
{
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum = sum + *(arrPtr + i);
    }

    return sum / arrSize;
}

int power(int* number)
{
    return *number * *number;
}

int* powerN(int* number, int n)
{
    int sum = *number;
    for (int i = 1; i < n; i++)
    {
        sum = sum * *number;
    }
    
    return &sum;
}

void repeatChar(char* character, int* times)
{
    for (int i = 0; i < *times; i++)
    {
        cout << *character;
    }
    cout << endl;
}

int* min(int* n1, int* n2)
{
    if(*n1 <= *n2)
        return n1;
    else
        return n2;
}

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}