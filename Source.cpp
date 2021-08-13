//#include<windows.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<string>
#include<algorithm>
#include<chrono>
#include<ctime>
#include<vector>
using namespace std::chrono;
using namespace std;

#define ARRAY_SIZE 256

// This function is for program loading and display
//  void Loading()
//  {
//  	for (int i = 1; i <= 100; i += 4)
//  	{
//  		cout << "Please Wait.. Loading " << i << "%";
//  		Sleep(5);
//  		system("cls");
//  	}

//  	system("cls");

//  }

// This is the hashing function used to generate hash values
int hashFunction(string substring)
{
	int hashValue;

	hashValue = substring[0];
	hashValue = 2 * hashValue + substring[1];
	hashValue = 2 * hashValue + substring[2];
	hashValue = hashValue % 256;

	return hashValue;
}

// This is the NEW3() Algorithm used in project article
int  NEW3(string X, int m, string Y, int n)
{

	//Dynamic Allocation of shift array
	int* shift = new int[ARRAY_SIZE];

	// Initializing shift array with value 'm-2'
	// which is the shift value of substrings
	// other than the substrings of Pattern X

	for (int i = 0; i < ARRAY_SIZE; i++)
		shift[i] = m - 2;


	// According to the project article
	int q = 3;	// q is the size of each substring
				// in this case q=3 for NEW3 Algorithm

	int substring_SIZE = (m - q + 1);


	// Dynamic Allocation of substring array B
	string* B = new string[substring_SIZE];

	int substring_counter = 0;

	while (substring_counter < substring_SIZE)
	{
		B[substring_counter] = X.substr(substring_counter, 3);
		substring_counter++;
	}

	substring_counter = 0;

	cout << "B substrings are as follows :: ";

	while (substring_counter < substring_SIZE)
	{
		cout << B[substring_counter] << " ";
		substring_counter++;
	}

	cout << endl;

	// Calculating the hash values of substring Array B

	cout << "Shift values are as follows :: ";

	int sh1 = 0;

	shift[hashFunction(B[0])] = m - 3;

	cout << shift[hashFunction(B[0])] << "   ";

	int i = 3, p = 1;

	while (p < (substring_SIZE - 1) && i <= (m - 2))
	{
		shift[hashFunction(B[p])] = (m - 1 - i);

		cout << shift[hashFunction(B[p])] << "   ";

		i++;
		p++;
	}
	
	sh1 = shift[hashFunction(B[substring_SIZE - 2])];
	//sh1=0;
	shift[hashFunction(B[substring_SIZE - 1])] = 0;

	cout << shift[hashFunction(B[substring_SIZE - 1])] << endl;

	Y = Y + X;
	//cout<<"new string y :: "<<y; 

	substring_counter = m - 1; //initializing substring_counter

	int sh = 0;

	int hashValue_Y = 0;

	int flag = 0;

	int pattern_counter = 0;

	while (true)
	{
		sh = 1;

		while (sh != 0)
		{
			hashValue_Y = Y[substring_counter - 2];
			hashValue_Y = 2 * hashValue_Y + Y[substring_counter - 1];
			hashValue_Y = 2 * hashValue_Y + Y[substring_counter];
			hashValue_Y = hashValue_Y % 256;

			sh = shift[hashValue_Y];
			//cout<<"sh "<< sh<<"  h_valueOfY "<< hashValue_Y <<" y = "<<Y[substring_counter-2]<<Y[substring_counter-1]<<Y[substring_counter]<<endl;
			substring_counter = substring_counter + sh;
			//cout<<"value of substring_counter " << substring_counter << endl;
		}

		if (substring_counter < n)
		{
			if (X == Y.substr(substring_counter - m + 1, m))
			{
				int index = (substring_counter - m + 1);

				cout << "\nPattern found at " << index << "th index" << endl;
				pattern_counter++;
				cout << "Number of times pattern found: " << pattern_counter << endl;

			}

			substring_counter = substring_counter + sh1;
		}
		else
			return 0;
	}

}

void funCall(string pattern, string filename)
{
	fstream myFile(filename, ios::in | ios::out);

	string TEXT = "";

	string temp;

	while (!myFile.eof())
	{
		myFile >> temp;

		TEXT = TEXT + temp;
	}

	// We consider TEXT as Y
	//cout << "TEXT:  " << TEXT << endl;

	// We consider TEXT_SIZE as n
	int TEXT_SIZE = TEXT.length();

	cout << "Pattern to find: " << pattern << endl;

	auto start = high_resolution_clock::now();

	NEW3(pattern, pattern.size(), TEXT, TEXT.size());

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	//cout << "Time taken by function: "
		//<< duration.count() << " microseconds" << endl;

	cout << "Time taken by function: "
		<< duration.count() / 1000000.0 << " seconds" << endl;
}

int main()
{
	string anykey;
	cout << "Press any key to continue..."; cin >> anykey;

	system("cls");

	//Loading();

	cout << "\t\t\t\t\t\t\t\t ***FAST EXACT STRING MATCHING ALGORITHM***" << endl << endl;

	cout << "String matching is the problem of finding all the occurences of a pattern in a text." << endl;
	cout << "We propose a very fast NEW3 algorithm of string matching; based on hashing q-grams" << endl;

	cout << "\nTesting NEW3 STRING MATCHING ALGORITHM..." << endl << endl;

	char option, anotheroption;

	do
	{
		option = ' ';
		anotheroption = ' ';
		cout << endl << endl;
		cout << "Option 1: Test algorithm on SHORT Pattern in Text String" << endl << endl;
		cout << "Option 2: Test algorithm on LONG Pattern in Text String" << endl << endl;
		cout << "Option 3: Test algorithm on SHORT Pattern in Numerical String" << endl << endl;
		cout << "Option 4: Test algorithm on LONG Pattern in Numerical String" << endl << endl;
		cout << "Option 5: Test algorithm on SHORT Pattern in Binary String" << endl << endl;
		cout << "Option 6: Test algorithm on LONG Pattern in Binary String" << endl << endl;
		cout << "Option 7: Test algorithm on SHORT Pattern in E. coli Genome String" << endl << endl;
		cout << "Option 8: Test algorithm on LONG Pattern in E. coli Genome String" << endl << endl;
		cout << "Press 'q' to exit..........." << endl << endl;
		cout << "Enter option no:  ";
		cin >> option;

		if (option == '1')
		{
			string filename = "TextFile.txt";
			// We consider PATTERN as X
			string PATTERN = "fingers";

			cout << "\n Reading Text File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == '2')
		{
			string filename = "TextFile.txt";
			// We consider PATTERN as X
			string PATTERN = "zaynentertainer";

			cout << "\n Reading Text File..." << endl << endl;

			funCall(PATTERN, filename);

		}
		else if (option == '3')
		{
			string filename = "NumericalFile.txt";

			// We consider PATTERN as X
			string PATTERN = "715268";

			cout << "\n Reading Numerical File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == '4')
		{
			string filename = "NumericalFile.txt";

			// We consider PATTERN as X
			string PATTERN = "03162533800715268";

			cout << "\n Reading Numerical File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == '5')
		{
			string filename = "BinaryFile.txt";


			// We consider PATTERN as X
			string PATTERN = "001100";

			cout << "\n Reading Binary File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == '6')
		{
			string filename = "BinaryFile.txt";

			// We consider PATTERN as X
			string PATTERN = "11001100110011001100";

			cout << "\n Reading Binary File..." << endl << endl;

			funCall(PATTERN, filename);

		}
		else if (option == '7')
		{
			string filename = "GeneticFile.txt";

			// We consider PATTERN as X
			string PATTERN = "zxzzsnydr";

			cout << "\n Reading E.coli Genome File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == '8')
		{
			string filename = "GeneticFile.txt";

			// We consider PATTERN as X
			string PATTERN = "radixsortingalgorithm";

			cout << "\n Reading E.coli Genome File..." << endl << endl;

			funCall(PATTERN, filename);
		}
		else if (option == 'q')
		{
			cout << "---------------Exiting-----------------" << endl;
			return 0;
		}
		else
			cout << "Invalid Option chosen........ try again" << endl;

		cout << "\n\nWould you like to select another Testing option ? (y/n)";
		cin >> anotheroption;

		if (anotheroption == 'y')
			system("cls");

	} while (option != 'q' && anotheroption != 'n');
}