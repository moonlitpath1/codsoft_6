//Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers and choose an operation to perform.

#include<iostream>
using namespace std;

int main()
{
    int operation;
    int n1, n2;

    cout<<"Welcome to Simple Calculator!";
    while(true)
    {
        cout<<"\nWhat operation would you like to perform?\n        1. Addition\n        2. Subtraction \n        3. Multiplication \n        4. Division\n        5. Exit\nEnter number: ";
        cin>>operation;
        if(operation == 5)  return 0;
        if(operation > 4 || operation < 1)
        {
            cout<<"Enter valid number.";
            continue;
        }

        cout<<"Enter number 1:";
        cin>>n1;
        cout<<"Enter number 1:";
        cin>>n2;

        switch(operation)
        {
            case 1:
                printf("%d + %d = %d", n1,n2, n1+n2);
                break;
            case 2:
                printf("%d + %d = %d", n1,n2, n1+n2);
                break;
            case 3:
                printf("%d + %d = %d", n1,n2, n1+n2);
                break;
            case 4:
                printf("%d + %d = %d", n1,n2, n1+n2);
                break;
        }
    }
    
}