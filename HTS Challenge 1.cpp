

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

int main()
{
	static int foundCounter = 0;
	static int letter_it = 0;

	string
		line = { "" }, scramWord = { "" }, foundWords[12] = { "" };

	ifstream scrambled("Scrambled.txt");
	ifstream myfile("wordlist.txt");
	ofstream unscrambled;

	// Search  PossibleWord for the matching length of  Scrambled;
	if (myfile.is_open() && scrambled.is_open())
	{
		while (getline(scrambled, scramWord))
		{ 
			while (getline(myfile, line))
			{/* Go through the list of words, word by word until the program finds a word with the same number of letters */
				letter_it = 0;
			
				if (scramWord.size() == line.size())
				{ /* If Scrambled word has the same number of letters as the word presently in list... */
					/* ...go through, letter by letter, and compare if those are in word presently in list */

					while (line.find(scramWord[letter_it]) != string::npos && scramWord.find(line[letter_it]) != string::npos)
					{ /* If letter from scrambled word is found in word, move on to next letter */
						/* cout << "Found " << scramWord[letter_it] << "!\n\n" << endl;*/
						letter_it++;
						
						if (letter_it == scramWord.size())
						{
							/* cout << "It's " << line << "\n\n" << endl;*/
							foundWords[foundCounter] = line;
							
						}
					}
				}
			}

		++foundCounter;
		scramWord.clear();
		line.clear();
		myfile.clear();
		myfile.seekg(0, ios::beg);

		}

	} // If myfile is open
	else
	{
		cout << "Unable to load file.\n\n";
	}

	unscrambled.open("Unscrambled.txt");

	for (int i = 0; i < sizeof(foundWords) / sizeof(*foundWords); i++)
	{
		if (i == (sizeof(foundWords) / sizeof(*foundWords)))
		{
			unscrambled << foundWords[i];
		}
		if (foundWords[i] != "")
		{
			unscrambled << foundWords[i] << ",";
		}

		
	}

	
	myfile.close();
	scrambled.close();
	unscrambled.close();
	
	return 0;
}
