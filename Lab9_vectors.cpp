// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// John Walter

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++11
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
// ***********************************************************************
// Try all the wasy to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	vector<int> v1(5); // vector of 5 0s
	vector<char> v2(5, 'a'); // vector of 5 1s
	vector<double> v3(5, 10); // vector of 5 10s
	vector<double> v4 (v3); // v4 = copy of v3
	vector<char> v5 = v2; // v5 = copy of v2
	vector<int> v6{1,2,3,4,5,6}; //v6 has elements 1,2,3,4,5,6
	vector<int> v7 = {1,2,3,4,5,6}; // v7 is identical to v6

	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	for(int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	for(int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
	for(int i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl;
	for(int i = 0; i < v5.size(); i++)
		cout << v5[i] << " ";
	cout << endl;
	for(int i = 0; i < v6.size(); i++)
		cout << v6[i] << " ";
	cout << endl;
	for(int i = 0; i < v7.size(); i++)
		cout << v7[i] << " ";
	cout << endl;

	cout << "********** Exercise 3.14************" << endl;
	int e, i;
	for(i=0;i<v1.size();i++){
		cout << "Enter number: ";
		cin >> e;
		v1[i] = e;
	}
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl << "************************************" << endl;
	cout << "********** Exercise 3.15************" << endl;
	vector<string> v8(5);
	string f;
	for(i=0;i<v8.size();i++){
		cout << "Enter string: ";
		cin >> f;
		v8[i] = f;
	}
	for(int i = 0; i < v8.size(); i++)
		cout << v8[i] << " ";
	cout << endl;
	cout << "************************************" << endl;
	cout << "************** Operations from table 3.5 **************" << endl;
	if(v8.empty()){
		cout << "V8 is empty" << endl;
	}
	cout << "The size of v8 is :" << v8.size() << endl;
	v8.push_back("newstring");
	cout << "v8 now is: ";
	for(int i = 0; i < v8.size(); i++)
		cout << v8[i] << " ";
	cout << endl;
	cout << "The value at position 4 in v8 is: " << v8[4] << endl;
	vector<string>v9 = v8;
	cout << "v9 is now equal to v8: v9 = ";
	for(int i = 0; i < v9.size(); i++)
		cout << v9[i] << " ";
	cout << endl;
	v1 = {10,20,30,40,50};
	cout << "V1 is now: ";
	for(int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	if (v1 == v6){
		cout << "V1 and v6 have the same number of elements" << endl;
	}
	if(v1 != v6){
		cout << "V1 and v6 do not have the same number of elements" << endl;
	}
	if (v1 > v6){
		cout << "v1 is bigger than v6" << endl;
	}else{
		cout << "v1 is smaller than v6" << endl;
	}




	return 0;
}