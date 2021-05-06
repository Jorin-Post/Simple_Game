#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void guess_game()
{   
    int i;
    int number = rand() / 251;
    int guess;
    cout << "Guess the number under 250" << endl;

    for (i = 0; i < 1 + i ; i++)
    {        
        cin >> guess; 

        if (guess < number)
        {
            cout << "To low try agian." << endl;
        }
        else if (guess > number)
        {
            cout << "To high try agian." << endl;       
        }
        else if (guess == number)
        {
            cout << "You win!! " << "You did it in " << i << " times!" << endl;
            break;
        }
    }
}

void speed_count()
{
    int answer;
    int yanswer;
    int good = 0;
    int turns = 4;
    std::vector<int>yanswers{};
    std::vector<int>answers{};

    for (int i = 0; i < turns; i++)
    {
    int number1 = (rand() / 700) + 4;
    int number2 = (rand() / 500) + 3;

    cout << number1 << " + " << number2 << " = " << endl;
    cin >> yanswer;

    answers.push_back(number1 + number2);
    yanswers.push_back(yanswer);

    if (yanswer == 0) {break;}
    }
    
    cout << endl;

    for (int i = 0; i < turns; i++)
    {
        if (yanswers[i] == answers[i])
        {
            good++ ;
        }
        else
        {
            cout << "You did get this answer wrong " <<yanswers[i]<< " it needs to be " << answers[i] <<endl;
        }
    }
    
    cout << endl << good << " of the " << turns << " answers are good!" << endl;
}

void speed_prof()
{
    int answer;
    int yanswer;
    int good = 0;
    int turns = 4;
    std::vector<int>yanswers{};
    std::vector<int>answers{};

    for (int i = 0; i < turns; i++)
    {
    int number1 = (rand() / 1200) + 4;
    int number2 = (rand() / 900) + 3;

    cout << number1 << " x " << number2 << " = " << endl;
    cin >> yanswer;

    answers.push_back(number1 * number2);
    yanswers.push_back(yanswer);

    if (yanswer == 0) {break;}
    }
    
    cout << endl;

    for (int i = 0; i < turns; i++)
    {
        if (yanswers[i] == answers[i])
        {
            good++ ;
        }
        else
        {
            cout << "You did get this answer wrong " <<yanswers[i]<< " it needs to be " << answers[i] << endl;
        }
    }
    
    cout << endl << good << " of the " << turns << " answers are good!" << endl;
}

void speed_Einstein()
{
    int answer;
    int yanswer;
    int good = 0;
    int turns = 4;
    std::vector<double>yanswers{};
    std::vector<double>answers{};

    for (int i = 0; i < turns; i++)
    {
        int number1 = (rand() / 50) + 4;
        int number2 = (rand() / 100) + 3;

    
        cout << number1 << " x " << number2 << " = " << endl;
        cin >> yanswer;
        answers.push_back(number1 * number2); 
        yanswers.push_back(yanswer);

        if (yanswer == 0) {break;}
        }
        
        cout << endl;
        
        for (int i = 0; i < turns; i++)
        {
            if (yanswers[i] == answers[i])
            {
                good++ ;
            }
            else
            {
                cout << "You did get this answer wrong " <<yanswers[i]<<" it needs to be " << answers[i] << endl;
            }
        }      
    cout << endl << good << " of the " << turns << " answers are good!" << endl;
}

void calculate_game() // easy + - normal * / hard 3,6E8 * /
{
    int calculate_speed;

    cout << endl << "How good can you calculate?" << endl << endl << "0. I'm scared, back to menu!" << endl <<
    "1. I can count.." << endl << "2. I'm a prof!" << endl << "3. I'm the next Einstein!" << endl;
    cin >> calculate_speed;
        {
            if (calculate_speed == 1)
            {
                cout << "We will start slow. Press 0 to stop." << endl;
                speed_count();
            }
            if (calculate_speed == 2)
            {
                cout << "Good luck, press 0 to stop." << endl;
                speed_prof();
            }      
            if (calculate_speed == 3)
            {
                cout << "Good luck, you will need it! If you can't take it any more, press 0 to stop" << endl;
                speed_Einstein();
            }
           else calculate_speed == 0;
        }
}

int main()
{
    srand(time(NULL));
    int menu_choice;
    
    cout << "Lets play a game!" << endl;
    
        do
        {
            cout << endl << "Menu." << endl << endl << "0. Quit game menu!" << endl << "1. Play guess game.." << endl << "2. Play calculate game.." << endl;
            cin >> menu_choice;
            if (menu_choice == 1)
            {
                guess_game();
            }
            if (menu_choice == 2)
            {
                calculate_game();
            }    
        }
        while (menu_choice != 0);
     cout << "Till the next time!" << endl;
}