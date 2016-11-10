// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

// John Walter

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	
	string s4(s1); // copies s1 into s4
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
	
	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************
	cout << "\n********** New Stuff Part 1 **********" << endl;

	s1 = "Hi";
	s2 = "There";

	// checks if s1 is empty
	if(s1.empty()){
		cout << "S1 is empty" << endl;
	}else{
		cout << "S1 is not empty" << endl;
	}

	// gets the length of s1
	cout << "The length of s1 is: " << s1.size() << endl;
	// gets the character at position 1 in s1
	cout << "The letter at position 1 in s1 is: " << s1[1] << endl;
	// combines s1 and s2
	cout << "s1 + s2 is: " << s1+s2 << endl;
	// make s1 equal to s2
	s1 = s2;
	cout << "Now s1 is s2: s1 = " << s1 << endl;
	// check to see if s1 and s2 are equal
	if(s1 == s2){
		cout << "s1 and s2 are equal" << endl;
	}
	// check to see if s1 and s2 are not equal
	if(s1 != s2){
		cout << "s1 and s2 are not equal" << endl;
	}
	// change s1
	s1 = "hello";
	// see if s1 or s2 is bigger
	if(s1 > s2){
		cout << "s1 is bigger than s2" << endl;
	}else{
		cout << "s1 is less than s2" << endl;
	}
	cout << "************************************" << endl;
// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text, finish it with an &" << endl;
	getline(cin, line, '&');
	cout << line << endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************
	cout << "******** New Stuff Part 2 **********" << endl;
	string c;
	//convert every character to upper
	for (auto &c : line)
		c = toupper(c);
	cout << line << endl;

	//convert every character to lower
	for (auto &c : line)
		c = tolower(c);
	cout << line << endl;

	// replace every space with a .
	for (auto &c : line)
		if(!isalnum(c)){
			c = '.';
		}
	cout << line << endl;
	cout << "************************************" << endl;
	return 0;
}