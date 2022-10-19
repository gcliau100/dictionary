#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


bool dict_count(fstream& f, vector<string>& word)
{
	bool flag = false;
	string def;
	if (f.is_open()) {
		word.clear(); // will always clear, but it addresses situation where another dictionary not named dictionary.txt is loaded
		while (getline(f, def))
		{
			size_t colon = def.find(":");	// function checks for the ":" and "." required for dictionary format
			size_t period = def.find(".");
			if (colon != string::npos && period != string::npos)	// variable = string::nops, if not found
				word.push_back(def);
		}
		f.close();
		flag = true;
	}
	return flag;
}


int main(int argc, char *argv[])
{
	fstream dict;	// fstream object
	vector<string> words;	// vector string container that holds each word and definition 
	string dname = "dictionary.txt";	// default dictionary name
	
	// initialize dictionary before checking for commands
	dict.open(dname, fstream::in);
	dict_count(dict, words);	// function defined above

	// FEATURE A
	// this means: ./dict
	if (argc == 1)
		cout << dname << " has " << words.size() << " words.\n";

	else
	{

		// for command that looks like: ./dict -d xxxxxxxx.txt
		if (strcmp(argv[1], "-d") == 0)
		{
			dict.open(argv[2], fstream::in);
			bool flag = dict_count(dict, words);	// true if some other dictionary name exists
			if (flag)
				dname = argv[2];
			cout << dname << " has " << words.size() << " words.\n";
		}

	
		// FEATURE B
		// command: ./dict -p prefix -n number
		if (strcmp(argv[1], "-p") == 0)
		{	
			int count = -1;	// assuming user will not enter a negative integer as argv[4]
			if (argc == 5) // assuming argv[3] = "-n"
				count = atoi(argv[4]);	// converts char * to int

			cout << dname << " has " << words.size() << " words.\n";

			string prefix = argv[2];
            size_t x = prefix.size();
			for (size_t i = 0; i < words.size(); i++) {
				// size_t colon = words[i].find(":");
				// string word = words[i].substr(0, colon-1);	// grabbing just the word being defined from the string
                
                string word = words[i].substr(0, x);	
                
                // if (word.find(prefix) != string::npos && count != 0)
				if (prefix.compare(word) == 0) // if not found == string::npos
				{
					cout << words[i] << endl;
					count--;
				}
			}
		}

	
		// FEATURE C
		// command: ./dict -s word -r replacement
		if (strcmp(argv[1], "-s") == 0)
		{	
			string tobereplace = argv[2];
			string replace = argv[2];
			if (argc == 5)	// assuming argv[3] = "-r"
				replace = argv[4];
		
			dict.open(dname, fstream::out);
			for (size_t i = 0; i < words.size(); i++) {
				int n = 0;
				while ((n = words[i].find(tobereplace, n)) != string::npos)	// loops to find each occurrence of the word to be replaced in the string
				{
					words[i].replace(n, tobereplace.size(), replace);
					n += replace.size();
				}
				dict << words[i] << endl;	// writes the string to the file and newline via endl
			}
			dict.close();
		}

		// FEATURE D
		// command: ./dict -v binary
		if (strcmp(argv[1], "-v") == 0)
		{
			const string binary = argv[2];
			string cmd = binary + " " + dname;
			const char *command = cmd.c_str();	//converts string to const char *, which system requires
			
			int i = system(command);	// executes the command

		}

	} // ends the else statement

    return 0;

} // ends main



