// HW1-Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "hangman.h"

int main()
{
    int guessesLeft = 6;
    int lettersLeft = 0;
    int checkedIndex;

    bool wordGuessed = false;
    bool foundLetter;

    

    
    char guessedLetter;

    //make c-style string
    //using 30 as it is greater than most word lengths and greater than the alphabet's length
    char wordToBeGuessed[] = "greetings";
    //make empty guesses arrays
    char correctGuesses[30];
    char incorrectGuesses[30] = "";

    std::cout << "Welcome to hangman! Type in a letter when prompted to guess!\n";

    while (!wordGuessed && guessesLeft > 0) 
    {
        //reset guessing flag so if the checking loop finds a match it can set this to true
        foundLetter = false;

        //show gallows, print tries, reset letters
        //resets instead of a -1 block later on in case a word has more than one of a letter that gets guessed
        lettersLeft = 0;
        checkedIndex = 0;
        

        //count letters left based on where the guessed parts don't match the full word
        for (int i = 0; i < (strlen(wordToBeGuessed)); i++)
        {
            if (wordToBeGuessed[i] != correctGuesses[i])
            {
                lettersLeft += 1;
            }
        }

        //Exit loop if still 0
        if (lettersLeft == 0)
        {
            break;
        }
        //draw gallows and word parts
        showGallows(guessesLeft);
        showSolveDisplay(wordToBeGuessed, correctGuesses, incorrectGuesses, guessesLeft);

        //Inform stats
        std::cout << "\nYou have " << guessesLeft << " mistakes left\n";

        
        std::cout << "\nYou have " << lettersLeft << " letters left to guess\n";

        //get letter
        std::cin >> guessedLetter;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //check the word letter by letter. Insert where applicable

        //check string for letter, if not there add to incorrect letters
        if (strchr(wordToBeGuessed, guessedLetter) != NULL) 
        {
            foundLetter = true;

            //loop for all instances of the letter
            while (foundLetter == true)
            {

                char* indexFound = strchr(wordToBeGuessed + checkedIndex, guessedLetter);

                if (indexFound != NULL)
                {
                    
                    checkedIndex = indexFound - wordToBeGuessed + 1;
                    correctGuesses[checkedIndex - 1] = guessedLetter;
                    //(strchr(wordToBeGuessed, guessedLetter)) - wordToBeGuessed
                }
                else
                {
                    foundLetter = false;
                }
            }
            std::cout << "Correct!\n";
        }        
        else
        {
            std::cout << "Inorrect.\n";
            guessesLeft--;

            

         
            incorrectGuesses[(strlen(incorrectGuesses))] = guessedLetter;

        }
        
        
    }

    if (lettersLeft == 0) 
    {
        std::cout << "\"" << wordToBeGuessed << "\"\n";
        std::cout << "You win! Congratulations! :)";
    }
    else if (guessesLeft == 0) 
    {
        showGallows(guessesLeft);
        std::cout << "Ran out of guesses! :(";
    }
    else 
    {
        std::cout << "ERROR: UNKNOWN ENDING";
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
