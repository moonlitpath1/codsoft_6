/*Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the correct number.*/

#include<iostream>
using namespace std;

int randomNumberGenerator(int level)
{
    srand(time(0));

    cout<<"   Your number lies between ";
    switch(level)
    {
        case 1:
            cout<<"1 - 10"<<endl;
            return rand() % 10 + 1;
            break;
        
        case 2:
            cout<<"1 - 50"<<endl;
            return rand() % 50 + 1;
            break;
        
        default:
            cout<<"1 - 100"<<endl;
            return rand() % 100 + 1;
            break;
    }
}

int main()
{
    int level = 1;
    int num, x;
    char b;
    int counter=0;

    while(true)
    {
        level<=3 ? cout<<"\n--{ Level "<<level<<" }--"<<endl : cout<<"--{ Highest Level } --";
        num = randomNumberGenerator(level);
        x = -1;
        counter=0;
        cout<<"\nGuessing game starts!\n   X.X Enter -1 if you give up X.X \n";
        while(num!=x)
        {
            counter++;
            cout<<"\nEnter number: ";
            cin>>x;
            if(x == -1)
            {
                cout<<"The number was "<<num<<endl;
                break;
            }   
            else if(x>num)
                cout<<x<<" is too big\n";
            else if(x<num)
                cout<<x<<" is too small\n";
            else
            {
                cout<<"\nCongratulations! You guessed the correct number within "<<counter<<" tries!!\n";
                break;
            }
        }
        if(level <= 3 && x!=-1)
        {
            level++;
            cout<<"Congratulations! You have ascended a level!!"<<endl;
        }
        else cout<<"You have cleared all levels.\n";
        cout<<"\nContinue playing?(y/n) : ";
        cin>>b;
        if(b == 'n' || b == 'N')
        {
            cout<<"Thank you for playing the guessing game ^.^\n";
            break;
        }
    }
    return 0;
}