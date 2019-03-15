//Dice Roller Pro
//by Ivan Peric

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

//function prototypes
void showMenu();
void rollVsCPU(int, int);
void rollVsP2();
void rollVsFile();

int main()
{
    srand(time(0)); //RNG
    int choice; //switch options
    char ans = 'y', ans1 = 'y', ans2 = 'y', ans3 = 'y'; //"play again?"
    int sides; //max sides for loading into the fxn
    int dice; //amt of dice to roll for loading into fxn

    do
    {//begin do
        system("cls");
        showMenu(); //call menu prompt
        cin >> choice;

        switch(choice)
        {//begin switch

        case 1: //vs CPU
            ans1='y';
            while(ans1=='y')
        {
            system("cls");
            cout << "\t\t\t\t*/*/Welcome to ULTIMATE Dice Roller Pro versus the Computer!*/*/\n\n"
                << "What is the maximum side per die? Please choose an integer: ";
            cin >> sides;
            cout << "\nHow many dice would you like to roll? Please choose an integer: ";
            cin >> dice;

            rollVsCPU(sides, dice);

            cout << "\n Play again? (Y/N): ";
            cin >> ans1;
            ans1 = tolower(ans1); //lowercase y/n so that it understands the while condition
        }
        break;

            case 2: //vs P2
                ans2='y';
                while(ans2=='y')
                {
                rollVsP2();
                cout << "Get revenge? (Y/N): ";
                cin >> ans2;
                ans2 = tolower(ans2);
                }
            break;

                case 3://From a file
                    ans3='y';
                    while(ans3=='y')
                    {
                    rollVsFile();
                    cout << "\n Play again? (Y/N): ";
                    cin >> ans1;
                    ans3 = tolower(ans1);
                    }
                break;

                    case 4:
                    cout << "\nThanks for playing! \n\n";
                    return 1;
                    break;

                        default:
                        cout << "\n\n\t\t\t***Please don't be disrespectful. Pick an integer 1-4.***\n\n ";
                        getch();
                        break;
    }//end switch
    }//end do
        while(choice != 4);
        cout << "Thanks for playing!";
    return 0;
}//end main

void showMenu()
{
        cout << "\t\t\t\t*/*/Welcome to ULTIMATE Dice Roller Pro!*/*/\n\n"
    	 << "Please select your option:\n"
	     << "\n1 - Play game against CPU"
	     << "\n2 - Play game against player 2 (2-player mode)"
	     << "\n3 - Play a game from file input"
	     << "\n4 - Quit\n\n";
}

void rollVsCPU(int maxSide, int diceAmt)//two main parameters are going to be sides and max die.
{
    int total = 0;
    int roll = 0;
    int total_CPU = 0;
    int roll_CPU = 0;
    srand(time(0)); //RNG
            cout << "\nRolling... Press any key to continue.\n";
            getch();
            system("cls");

            for(int i = 1; i < diceAmt+1; i++)
            {
                roll = (rand() % maxSide+1);
                cout << "Roll #" << i << " - P1: " << roll << endl;
                total += roll;
            }
            cout << "\n\n\t///Player 1:\nYour total is: " << total << endl
            << "Your average roll is: " << total / diceAmt << endl
            << "\nPress any key for CPU roll...";
            getch();
            cout << "\n\n************************************************\n" << endl;

                for(int o = 1; o < diceAmt+1; o++)
                {
                    roll_CPU = (rand() % maxSide+1);
                    cout << "Roll #" << o << " - CPU: " << roll_CPU << endl;
                    total_CPU += roll_CPU;
                }
            cout << "\n\t///CPU:\nYour total is: " << total_CPU << endl
                << "CPU's average roll is: " << total_CPU / diceAmt << endl;

            cout << "\nDrumroll, please! Press any key to see results...\n\n";
                getch();

                if(total > total_CPU)
                {
                    cout << "\n\n\t\t\t\t***Player One wins! Congrats!!***\n ";
                }
                    else if(total_CPU > total)
                    {
                        cout << "\n\n\t\t\t\t***Drats, CPU wins! Try again!***\n ";
                    }
                        else if(total_CPU == total)
                        {
                            cout << "\n\n\t\t\t\t***Unfathomable! It's a draw!! Maybe we should code an overtime game?***";
                        }
}

void rollVsP2()
{
    int total = 0;
    int roll = 0;
    int total_p2 = 0;
    int roll_p2 = 0;
    int maxSide = 0;
    int diceAmt = 0;
    string p1_name;
    string p2_name;
    srand(time(0)); //RNG

                system("cls");
                cout << "\t\t\t\t*/*/Welcome to ULTIMATE Dice Roller Pro versus Player 2!*/*/\n\n"
                    << "First, we need names! Player One--What's your name? ";
                    cin.ignore();
                getline(cin, p1_name);
                cout << "\n\tBeautiful! Nice to meet you, " << p1_name << "!\n\nHow about you, Player Two? Please input your name: ";
                getline(cin, p2_name);
                cout << "\n\tAlright, " << p2_name << "! \n\nLet's get into the game! Press any key to determine who chooses the dice rolls!\n";

                getch();
                system("cls");

                int randRoll_p1 = (rand() % 100+1);
                int randRoll_p2 = (rand() % 100+1);

                cout << "Let's see who gets to decide... Press any key to continue...";
                getch();

                cout << "\n\n" << p1_name << ", you rolled a " << randRoll_p1 << "! (Press any key to continue...)" << endl;
                getch();

                cout << "\n" << p2_name << ", you rolled a " << randRoll_p2 << "! (Press any key to continue...)" << endl;
                getch();

                    if (randRoll_p1 > randRoll_p2)
                    {
                        cout << "\nHot Start, " << p1_name << "! You choose! (Press any key to continue...)\n\n";
                    }
                        else if (randRoll_p2 > randRoll_p1)
                        {
                            cout << "\n" << p2_name << " is on a roll! You choose! (Press any key to continue...)\n\n";
                        }

                cout << "\n\tWhat is the maximum side per die? Please choose an integer: "; //maybe insert a dice roll for who gets to pick the variables
                cin >> maxSide;
                cout << "\n\tHow many dice would you like to roll? Please choose an integer: ";
                cin >> diceAmt;
                cout << "\nRolling... Press any key to continue.\n";
                getch();
                system("cls");

                    for(int i = 1; i < diceAmt+1; i++)
                        {
                            roll = (rand() % maxSide+1);
                            cout << "Roll #" << i << " - " << p1_name << ": " << roll << endl;
                            total += roll;
                        }
                cout << "\n\n\t///" << p1_name << ":\nYour total is: " << total << endl
                    << "Your average roll is: " << total / diceAmt << endl
            << "\nPress any key for " << p2_name << "'s roll...";
            getch();
            cout << "\n\n************************************************\n" << endl;
                cout << endl;

                        for(int o = 1; o < diceAmt+1; o++)
                        {
                            roll_p2 = (rand() % maxSide+1);
                            cout << "Roll #" << o << " - " << p2_name << ": " << roll_p2 << endl;
                            total_p2 += roll_p2;
                        }

                    cout << "\n\t///" << p2_name << ":\nYour total is: " << total_p2 << endl
                    << p2_name << "'s average roll is: " << total_p2 / diceAmt << endl;

            cout << "\nDrumroll, please! Press any key to see results...\n\n";
                getch();

                        if(total > total_p2)
                        {
                            cout << "\n\n\t\t\t\t***" << p1_name << " wins! Congrats!!***\n ";
                        }

                            else if(total_p2 > total)
                            {
                                cout << "\n\n\t\t\t\t***Drats, " << p2_name << " wins! Try again!***\n ";
                            }

                                else if(total_p2 == total)
                                {
                                    cout << "\n\n\t\t\t\t***Unfathomable! It's a draw!! Maybe we should code an overtime game?***";
                                }

}

void rollVsFile()
{
                int total = 0;
                int total_p2 = 0;
                int roll = 0;
                int roll_p2 = 0;
                fstream game_data;
                int n1, n4, n5;
                string p1, p2;
                system("cls");

                cout << "\t\t\t\t*/*/Welcome to ULTIMATE Dice Roller Pro--File input edition!*/*/\n\nNow loading from file... (Press any key to continue...)";
                getch();

                game_data.open("game_data.txt");

                    if(!game_data)
                    {
                        cout << "\n\nCould not open the file. Please make sure it is located in the same folder as this game. " << endl;
                    }

                        game_data >> n1 >> p1 >> p2 >> n4 >> n5;
                        game_data.close();

                        cout << "\n\nWelcome, " << p1 << "! (Press any key to continue...)";
                        getch();

                        cout << "\n\nGreetings, " << p2 << "! (Press any key to continue...)";
                        getch();

                        cout << "\n\nLet's get into the game! (Press any key to continue...)\n";
                        getch();

                        cout << "\nThe file determines that the maximum amount of sides per die is: " << n4 << endl;
                        cout << "\nThe file determines that the amount of dice rolls will be: " << n5 << endl;
                        cout << "\nNow rolling... (Press any key to continue...)\n\n";
                        getch();

                            for(int i = 1; i < n5+1; i++)
                                {
                                    roll = (rand() % n4+1);
                                    cout << "Roll #" << i << " - " << p1 << ": " << roll << endl;
                                    total += roll;
                                }

                            cout << "\n\n\t///" << p1 << ":\nYour total is: " << total << endl
                                << "Your average roll is: " << total / n5 << endl
                                << "\nPress any key for " << p2 << "'s roll...";
                                getch();
                            cout << "\n\n************************************************\n" << endl;
                            cout << endl;

                                for(int o = 1; o < n5+1; o++)
                                    {
                                        roll_p2 = (rand() % n5+1);
                                        cout << "Roll #" << o << " - " << p2 << ": " << roll_p2 << endl;
                                        total_p2 += roll_p2;
                                    }

                                cout << "\n\t///" << p2 << ":\nYour total is: " << total_p2 << endl
                                << p2 <<"'s average roll is: " << total_p2 / n5 << endl;

                                cout << "\nDrumroll, please! Press any key to see results...\n\n";
                                getch();

                                if(total > total_p2)
                                {
                                    cout << "\n\n\t\t\t\t***" << p1 << " wins! Congrats!!***\n ";
                                }
                                    else if(total_p2 > total)
                                    {
                                        cout << "\n\n\t\t\t\t***Drats, " << p2 << " wins! Try again!***\n ";
                                    }
                                        else if(total_p2 == total)
                                        {
                                            cout << "\n\n\t\t\t\t***Unfathomable! It's a draw!! Maybe we should code an overtime game?***";
                                        }
}
