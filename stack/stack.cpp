#include <iostream>
#include "Stack.h"
using namespace std;
void menu();
void welcome();
int main(int argc, char const *argv[])
{
    Stack s;
    int cmd;
    welcome();
    menu();
    while(true)
    {
        cin >> cmd;\
        switch (cmd)
        {
            case 1:
                cout << "input the number to push:  "; 
                int pushNumber;
                cin >> pushNumber;
                s.push(pushNumber);
                cout << "Pushed " << pushNumber << " successfully" << endl;
                break;
            case 2:
                int popNumber;
                popNumber = s.pop();
                cout << "Popped " << popNumber << " successfully" << endl;
                break;
            case 3:
                break;    
            case 9:
                return 0;
                break;
            default:
                cout << "Wrong command! these commands are valid:" << endl;
                menu();
                break;   
        } 
    }
    return 0;
}
void menu()
{
    cout    << "command     description"    << endl
            << "1           push a number"  << endl
            << "2           pop a number"   << endl
            << "9           exit"           << endl;
}
void welcome()
{
    cout    << "****************************"   << endl
            << "*  Welcome to Stack Test!  *"   << endl
            << "****************************"   << endl;
}
void send_copy( List ls )
{

}