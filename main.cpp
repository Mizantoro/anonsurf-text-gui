#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <thread>

using namespace std;

char getch(void) // https://stackoverflow.com/questions/3276546/how-to-implement-getch-function-of-c-in-linux
{
    struct termios oldattr, newattr;
    char ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void DisplayLine()
{
    cout<<"----------------------------------------------------------------------\n\n";
}

void DisplayError()
{
    cout<<"error: invalid command\n";
}

void DisplayOptions()
{
    cout<<"[1] - start\n";
    cout<<"[2] - stop\n";
    cout<<"[3] - restart\n";
    cout<<"[4] - change\n";
    cout<<"[5] - status\n";
    cout<<"[6] - myip\n";
    cout<<"[7] - starti2p\n";
    cout<<"[8] - stopi2p\n";
    cout<<"[9] - help\n";
    cout<<"[0] - exit\n";
}

int main()
{
    system("sudo -v");
    system("clear");
    cout<<"AnonSurf text gui\n\n";
    char ch;
    while(true) {
        DisplayOptions();
        ch=getch();
        switch(ch)
        {
            case '1':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf start");
                break;
            case '2':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf stop");
                DisplayLine();
                break;
            case '3':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf restart");
                break;
            case '4':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf change");
                break;
            case '5':
                cout<<endl;
                DisplayLine();
                system("anonsurf status");
                DisplayLine();
                break;
            case '6':
                cout<<endl;
                DisplayLine();
                system("anonsurf myip");
                break;
            case '7':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf starti2p");
                DisplayLine();
                break;
            case '8':
                cout<<endl;
                DisplayLine();
                system("sudo anonsurf stopi2p");
                DisplayLine();
                break;
            case '9':
                cout<<endl;
                DisplayLine();
                system("anonsurf help");
                DisplayLine();
                break;
            case '0':
                cout<<"\n[1] - quit Helper\n";
                cout<<"[2] - stop Anonsurf & quit Helper\n";
                ch=getch();
                switch(ch) {
                    case '1':
                        return 0;
                    case'2':
                        system("sudo anonsurf stop");
                        return 0;
                    default:
                        break;
                }
            default:
                DisplayError();
                break;
        }
    }
}
