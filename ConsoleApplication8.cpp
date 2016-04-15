#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "windows.h"

using namespace cv;
using namespace std;

int main(void)
{
	int counter = 0;
	int a = 0;
	Mat image;
	int position[55] = { 0 };
	int posCounter = 0;
	int dotCounter = 0;
	int morseCounter = 0;
	int textCounter = 0;
	int digicode[100] = { 0 };
	string morseCode[100] = { "" };
	string textCode[100] = { "" };
	string finalCode = { "" };
	
	string alphabet[36] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
							"k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
							"u", "v", "w", "x", "y", "z", "0", "1", "2", "3",
							"4", "5", "6", "7", "8", "9" };

	string morseAlphabet[36] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
								"....", "..", ".---", "-.-", ".-..", "--", "-.",
								"---", ".--.", "--.-", ".-.", "...", "-", "..-",
								"...-", ".--", "-..-", "-.--", "--..", "-----",
								".----", "..---", "...--", "....-", ".....",
								"-....", "--...", "---..", "----."};

	
	ushort table[3000] = { 0 };

	

	typedef map<string, string > textMorseMap;

	

	textMorseMap morseMap;

	textMorseMap * morseMapPtr = &morseMap;
	
	string *morsePtr = morseAlphabet;
	string *alphaPtr = alphabet;


	textMorseMap::iterator iter = morseMap.begin();
	
	morseMap.insert(make_pair(morseAlphabet[0], alphabet[0]));
	morseMap.insert(make_pair(morseAlphabet[1], alphabet[1]));
	morseMap.insert(make_pair(morseAlphabet[2], alphabet[2]));
	morseMap.insert(make_pair(morseAlphabet[3], alphabet[3]));
	morseMap.insert(make_pair(morseAlphabet[4], alphabet[4]));
	morseMap.insert(make_pair(morseAlphabet[5], alphabet[5]));
	morseMap.insert(make_pair(morseAlphabet[6], alphabet[6]));
	morseMap.insert(make_pair(morseAlphabet[7], alphabet[7]));
	morseMap.insert(make_pair(morseAlphabet[8], alphabet[8]));
	morseMap.insert(make_pair(morseAlphabet[9], alphabet[9]));
	morseMap.insert(make_pair(morseAlphabet[10], alphabet[10]));
	morseMap.insert(make_pair(morseAlphabet[11], alphabet[11]));
	morseMap.insert(make_pair(morseAlphabet[12], alphabet[12]));
	morseMap.insert(make_pair(morseAlphabet[13], alphabet[13]));
	morseMap.insert(make_pair(morseAlphabet[14], alphabet[14]));
	morseMap.insert(make_pair(morseAlphabet[15], alphabet[15]));
	morseMap.insert(make_pair(morseAlphabet[16], alphabet[16]));
	morseMap.insert(make_pair(morseAlphabet[17], alphabet[17]));
	morseMap.insert(make_pair(morseAlphabet[18], alphabet[18]));
	
	morseMap.insert(make_pair(morseAlphabet[19], alphabet[19]));
	morseMap.insert(make_pair(morseAlphabet[20], alphabet[20]));
	morseMap.insert(make_pair(morseAlphabet[21], alphabet[21]));
	morseMap.insert(make_pair(morseAlphabet[22], alphabet[22]));
	morseMap.insert(make_pair(morseAlphabet[23], alphabet[23]));
	morseMap.insert(make_pair(morseAlphabet[24], alphabet[24]));
	morseMap.insert(make_pair(morseAlphabet[25], alphabet[25]));
	morseMap.insert(make_pair(morseAlphabet[26], alphabet[26]));
	morseMap.insert(make_pair(morseAlphabet[27], alphabet[27]));
	morseMap.insert(make_pair(morseAlphabet[28], alphabet[28]));
	morseMap.insert(make_pair(morseAlphabet[29], alphabet[29]));
	morseMap.insert(make_pair(morseAlphabet[30], alphabet[30]));
	morseMap.insert(make_pair(morseAlphabet[31], alphabet[31]));
	morseMap.insert(make_pair(morseAlphabet[32], alphabet[32]));
	morseMap.insert(make_pair(morseAlphabet[33], alphabet[33]));
	morseMap.insert(make_pair(morseAlphabet[34], alphabet[34]));
	morseMap.insert(make_pair(morseAlphabet[35], alphabet[35]));


	/*for (const auto& p : morseMap)
	{
		cout << p.first << "\t : \t" << p.second << endl;
	}*/

	image = imread("download.png", CV_LOAD_IMAGE_GRAYSCALE);   // Read the file
	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	
	CV_Assert(image.depth() != sizeof(uchar));
	uchar* p;
	position[0] = 0;
	posCounter++;


	for (int i = 0; i < image.rows; ++i)
	{
		p = image.ptr<uchar>(i);
		

		for (int j = 0; j < image.cols; ++j)
		{
		
			table[counter] = p[j];
			if (table[counter] == 255)
			{
				position[posCounter] = counter;

				posCounter++;
			}
			/*cout << "Row " << i << ", Number " << j << ": " << table[counter] << endl; */
			counter++;
		}
		cout << "\n\n";

		
	}

	for (int k = 0; k < 47; k++)
	{
		if (position[k] > 0)
		{
			/*cout << "Counter " << dotCounter + 1 << "\t" << position[k] << endl;*/
		}

		

		if (dotCounter < 47)
		{
			digicode[morseCounter] = position[k + 1] - position[k];

				if (digicode[morseCounter] == 45)
				{
					 
					textCode[textCounter] += "-";
				}
				else if (digicode[morseCounter] == 46)
				{
					
					textCode[textCounter] += ".";
				}
				else
				{
					textCounter++;
				}
				

		}

		dotCounter++; 
	}

	for (int m = 0; m < 10; m++)
	{
		finalCode += morseMap.at(textCode[m]);

	}

	const char* output = &finalCode[0];
	const size_t len = strlen(output) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	  
	                                         // Wait for a keystroke in the window

	return 0;
}

