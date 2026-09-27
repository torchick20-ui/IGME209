#include <iostream>

void showGallows(int wrongGuessesRemaining)
{
	//top of image always draws the same
	std::cout << "---------\n|\t|\n|";

	//draw head or not
	if (wrongGuessesRemaining <= 5)
	{
		std::cout << "\tO\n";
	}
	else 
	{
		std::cout << "\n";
	}

	//draw torso and arms as applicable
	if (wrongGuessesRemaining > 4) 
	{
		std::cout << "|\n";
	}
	else if (wrongGuessesRemaining == 4)
	{
		std::cout << "|\t|\n";
	}
	else if (wrongGuessesRemaining == 3)
	{
		std::cout << "|      /|\n";
	}
	else
	{
		std::cout << "|      /|\\ \n";
	}
		
	//draw legs as applicable
	if (wrongGuessesRemaining > 1) 
	{
		std::cout << "|\n";
	}
	else if (wrongGuessesRemaining == 1) 
	{
		std::cout << "|      / \n\n ";
	}
	else
	{
		std::cout << "|      / \\\n";
	}

	//draw base 
	std::cout << "|\n|\n|\n_________\n\n";
	
}

void showSolveDisplay(char word[], char correctGuesses[], char incorrectGuesses[], int guessesLeft)
{
	//print word
	std::cout << "Word so far: \n";
	/*
	for (int i = 0; i < sizeof(correctGuesses) / sizeof(correctGuesses[0]); i++)
	{
		if (correctGuesses[i] == word[i])
		{
			std::cout << correctGuesses[i];
		}
		else
		{
			std::cout << "_";
		}

	}
	*/
	for (int i = 0; i < (strlen(word)); i++)
	{
		if (word[i] != correctGuesses[i])
		{
			std::cout << "_";
		}
		else
		{
			std::cout << correctGuesses[i];
		}
	}

	

	//will not print if there are no wrong guesses yet
	if (guessesLeft < 6)
	{
		//print letters
		std::cout << "\nInorrectly guessed letters:\t";

		for (int i = 0; i < strlen(incorrectGuesses); i++)
		{
			std::cout << incorrectGuesses[i] << ",";
		}
		//sizeof(incorrectGuesses) / sizeof(incorrectGuesses[0]
	}
	
	
}
