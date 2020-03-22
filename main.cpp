#include<iostream>
#include<math.h>
#include<ctype.h>
#include<cstring>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void intro();
void initialize();
void menu();
void menu_2();
void game();
void exit_game();
void print_board();
void p1_input();
void p2_input();
void winner_check(int);
void reset();
void play_sound();
void marquee();

string player1,player2;
int score1,score2;
char game_board[9];
boolean multi_player;
int p1_choice;
int p2_choice;
int random=1;

void marquee(string s)
{

}
void play_sound()
{
    for(int a=200;a<=10000;a+=200)
    {
        Beep(a,10);
    }
    for(int a=10000;a>=200;a-=200)
    {
        Beep(a,10);
    }

}

int main()
{
    play_sound();
    intro();
    menu();
}
void p1_input()
{
    cout<<"\n\n\n\n\t\t\t\t\t\t"<<player1<<" 'S TURN :";
    Beep(1223,300);
    cin>>p1_choice;
    if(game_board[p1_choice-1]=='X' || game_board[p1_choice-1]=='O' || p1_choice>9 || p1_choice<1)
    {
        cout<<"\n\n\t\t\t\t\t\tINVALID CHOICE.PLEASE ENTER AGAIN.";
        Beep(423,300);
        Sleep(1000);
        print_board();
        p1_input();
    }
    else
    {
        game_board[p1_choice-1]='X';
    }
}
void p2_input()
{
    cout<<"\n\n\n\n\t\t\t\t\t\t"<<player2<<" 'S TURN : ";
    Beep(1223,300);
    if(multi_player==true)
    {
        cin>>p2_choice;
        if(game_board[p2_choice-1]=='X' || game_board[p2_choice-1]=='O' || p2_choice>9 || p2_choice<1)
        {
            cout<<"\n\n\t\t\t\t\t\tINVALID CHOICE.PLEASE ENTER AGAIN.";
            Beep(423,300);
            Sleep(1000);
            print_board();
            p2_input();
        }
        else
        {
            game_board[p2_choice-1]='O';
        }

    }
    else
    {
        //if(game_board[0]==)

    }
}
void game()
{
    int i=1;
    while(i<=9)
    {
        if(random==1)
        {
        print_board();
        p1_input();
        print_board();
        winner_check(1);
        }
        else
        {
        print_board();
        p2_input();
        print_board();
        winner_check(2);
        }
        random*=-1;
        i++;
    }
    cout<<"\n\n\n\t\t\t\tGAME DRAW!!";
    menu_2();
}
void winner_check(int i)
{
    //int a=1;
    char c;
    if(i==1)
    c='X';
    else
    c='O';
    if((game_board[0]==c && game_board[1]==c && game_board[2]==c) || (game_board[3]==c && game_board[4]==c && game_board[5]==c) || (game_board[6]==c && game_board[7]==c && game_board[8]==c) || (game_board[0]==c && game_board[3]==c && game_board[6]==c) || (game_board[1]==c && game_board[4]==c && game_board[7]==c) || (game_board[2]==c && game_board[5]==c && game_board[8]==c) || (game_board[0]==c && game_board[4]==c && game_board[8]==c) || (game_board[2]==c && game_board[4]==c && game_board[6]==c))
    {
        if(i==1)
        {
            for(int j=1;j<=40;j+=1)
            {
                if(j==1)
                {
                    Beep(723,300);
                    Beep(923,300);
                }
                print_board();
                cout<<"\n\n\n\n\t\t\t\t\t\t";
                if(j<=30)
                    for(int k=1;k<=j;k++)cout<<" ";
                else
                    for(int k=60;k>=j;k--)cout<<" ";
                cout<<player1<<" WON !!";
                Sleep(100);
            }
            score1++;
        }
        else
        {
            for(int j=1;j<=40;j+=1)
            {

                if(j==1)
                {
                    Beep(723,300);
                    Beep(923,300);
                }
                print_board();
                cout<<"\n\n\n\n\t\t\t\t\t\t";
                if(j<=30)
                    for(int k=1;k<=j;k++)cout<<" ";
                else
                    for(int k=60;k>=j;k--)cout<<" ";
                cout<<player2<<" WON !!";
                Sleep(100);
            }
            score2++;
        }
        menu_2();

    }

}
void reset()
{
    game_board[0]='1';
    game_board[1]='2';
    game_board[2]='3';
    game_board[3]='4';
    game_board[4]='5';
    game_board[5]='6';
    game_board[6]='7';
    game_board[7]='8';
    game_board[8]='9';
}
void initialize()
{
    score1=score2=0;
    cout<<"\n\n\t\t\t\t\t\tENTER PLAYER1 : ";
    Beep(1223,300);
    cin>>player1;
    if(multi_player==true)
    {
        cout<<"\n\t\t\t\t\t\tENTER PLAYER2 : ";
        Beep(1223,300);
        cin>>player2;
    }
    else
        player2="CPU";
    game();
}
void intro()
{
    string loading="LOADING";
    for(int i=1;i<6;i++)
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t________ __ ________     ________   __   ________    ________ _______ _______\n";
        cout<<"\t\t\t\t\t\t======== == ========     ========   ==   ========    ======== ======= =======\n";
        cout<<"\t\t\t\t\t\t   ==    == ==              ==     ====  ==             ==    ==   == ==     \n";
        cout<<"\t\t\t\t\t\t   ==    == ==        ==    ==    ==  == ==       ==    ==    ==   == =======\n";
        cout<<"\t\t\t\t\t\t   ==    == ==        ==    ==    ====== ==       ==    ==    ==   == ==     \n";
        cout<<"\t\t\t\t\t\t   ==    == ========        ==    ==  == ========       ==    ======= =======\n";
        cout<<"\n\t\t\t\t\t------------------------------------------------------------------------------------------------\n";
        cout<<"\n\n\t\t\t\t\t\t                                                           ---A GAME BY SKILITE INDUSTRIES---";
        cout<<"\n\n\t\t\t\t\t\t                                                           ---         CREATOR: KTZ       ---";
        cout<<"\n\n\n\t\t\t\t\t\t                           "<<loading;
        Beep(12223,300);
        Sleep(600);
        system("CLS");
        loading=loading+".";
    }
}
void menu()
{
        system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t________ __ ________     ________   __   ________    ________ _______ _______\n";
        cout<<"\t\t\t\t\t\t======== == ========     ========   ==   ========    ======== ======= =======\n";
        cout<<"\t\t\t\t\t\t   ==    == ==              ==     ====  ==             ==    ==   == ==     \n";
        cout<<"\t\t\t\t\t\t   ==    == ==        ==    ==    ==  == ==       ==    ==    ==   == =======\n";
        cout<<"\t\t\t\t\t\t   ==    == ==        ==    ==    ====== ==       ==    ==    ==   == ==     \n";
        cout<<"\t\t\t\t\t\t   ==    == ========        ==    ==  == ========       ==    ======= =======\n";
        cout<<"\n\t\t\t\t\t------------------------------------------------------------------------------------------------\n";
        cout<<"\n\n\n\t\t\t\t\t\t                           MENU:\n";
        cout<<"\t\t\t\t\t\t                           1 : SINGLE PLAYER\n";
        cout<<"\t\t\t\t\t\t                           2 : MULTI PLAYER\n";
        cout<<"\t\t\t\t\t\t                           PRESS ANY OTHER KEY TO EXIT...\n";
        cout<<"\n\t\t\t\t\t\tENTER YOUR CHOICE : "<<flush;
        int ch;
        cin>>ch;
        Beep(200,500);
        if(ch==1)
            {
                multi_player=false;
                reset();
                initialize();
            }
        else if(ch==2)
            {
                multi_player=true;
                reset();
                initialize();
            }
        else
            exit_game();
}
void exit_game()
{
    system("CLS");
    Beep(1223,100);
    Beep(1123,110);
    Beep(1023,120);
    Beep(923,130);
    Beep(823,140);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tTHANKS FOR PLAYING. GOODBYE!!!\n\n\t\t\t\t";
    Sleep(2000);
    system("PAUSE");
    system("CLS");
    exit(0);
}

void print_board()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t"<<player1<<"[X]\tVS\t"<<player2<<"[O]"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\tSCORE-\t\t"<<score1<<"\t:\t"<<score2<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t___________________";
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
        cout<<"\n\n\t\t\t\t\t\t\t\t\t|  ";
        cout<<game_board[i]<<"  |  ";
        if((i+1)%3==0)
        cout<<"\n\t\t\t\t\t\t\t\t\t___________________";
    }
}
void menu_2()
{
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t1 : RETRY";
    cout<<"\n\t\t\t\t\t\t\t\t\t2 : MAIN MENU";
    cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ANY OTHER KEY TO EXIT...";
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE : ";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        reset();
        game();
    }
    else if(ch==2)
    {
        reset();
        menu();
    }
    else
        exit_game();
}
