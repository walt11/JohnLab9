/*
#########################
Name:		John Walter
Date:		10/12/16
Class:		ECE 3220
Assignment:	Lab 9
#########################
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// class for a signal
class Signal{
	// private members
	/*
	private:
		int max;
		double average;
		//double *data = NULL;
		vector<double>data;
		int length;
		vector<double>array;
		//double *array = NULL;
		int check;
*/
	// public members and methods
	public:

		int max;
		double average;
		int length;
		//double *data = NULL;
		vector<double>data;
		vector<double>array;
		//double *array = NULL;
		int check;




		// open file, read data into private variables, close file
		Signal();
		Signal(int); //receives file number
		Signal(const char *); // receives filename
		~Signal();

		void operator+(double); // overloaded operator for offset
		void operator*(double); // overloaded operator for scale

		void center(Signal);
		void normalize(Signal);
		void statistics();
		//void exit();
		//int check_file_success();
		void sig_info();
		void save_file(int,int);
		void print_signal(vector<double>);
		void mean();
		void deletePointers();
		int check_file_success();
		

};

// This method is used to check that the file loaded correctly
// by check if data is NULL or not
int Signal::check_file_success(){
	//cout << data << endl;
	if(data.empty()){
		// File did not load correctly
		return -1;
	}else{
		// file loaded correctly
		return 0;
	}
}

// This function writes the transformed signal to a file
// int flag represents which transformation was done
// int num represents the file number
void Signal::save_file(int flag, int num){
	char filename[20];
	// Below forms the filename for the output file to write the new signal to
	// if no transformations have been done then there is no point
	// to create a file with the raw signal because that file already exists
	if(flag == 0){
		cout << "No transformations have been done." << endl;
		return;
	// if an offset was done
	}else if(flag == 1){
		if(num<9){ // includes a zero in the name
			sprintf(filename,"Offset_data_0%d.txt",num);
		}else{ //doesn't include a zero in the name
			sprintf(filename,"Offset_data_%d.txt",num);
		}
	// if a scale was done
	}else if(flag == 2){
		if(num<9){ // includes a zero in the name
			sprintf(filename,"Scale_data_0%d.txt",num);
		}else{ //doesn't include a zero in the name
			sprintf(filename,"Scale_data_%d.txt",num);
		}
	// if center was done
	}else if(flag == 3){
		if(num<9){ // includes a zero in the name
			sprintf(filename,"Center_data_0%d.txt",num);
		}else{ //doesn't include a zero in the name
			sprintf(filename,"Center_data_%d.txt",num);
		}
	// if normalize was done
	}else{
		if(num<9){ // includes a zero in the name
			sprintf(filename,"Normalize_data_0%d.txt",num);
		}else{ //doesn't include a zero in the name
			sprintf(filename,"Normalize_data_%d.txt",num);
		}
	}

	cout << "Writing new signal to file." << endl;
	int i;
	
	// Open the file and write the signal to the file
	FILE *fp = fopen(filename,"w");
	if(fp == NULL){
		printf("ERROR opening file\n");
	}else{
		fprintf(fp,"%d %d\n",length,max);
		for(i=0;i<length;i++){
			fprintf(fp,"%.4f\n",array[i]);
		}
		fclose(fp);
	}
}

// This method displays the max, length, and average of the raw signal
void Signal::sig_info(){
	cout << "Signal Info\n\tMax: ";
	cout << max << endl;
	cout << "\n\tLength: ";
	cout << length << endl;
	cout << "\n\tAverage: ";
	cout << average << endl;
}

// This method prints an array of doubles 
void Signal::print_signal(vector<double>x){
	//cout << "Inside print" <<endl;
	int i;
	for(i=0;i<length;i++){
		cout << x[i];
		cout << " ";
	}
}

// This function generates a file containing the mean and max of the raw signal
void Signal::statistics(){
	char file_name[] = "Statistics_File.txt";
	FILE * fp = fopen(file_name,"w");
	fprintf(fp,"%.4f %d",average,max);
	cout << "Mean and max written to file" << endl;
	cout << "The mean is: ";
	cout << average << endl;
	cout << "The max is: ";
	cout << max << endl; 
	fclose(fp);
}

// This function calculates the average of the raw signal
void Signal::mean(){
	double total = 0.0;
	int i=0;
	for(i=0;i<length;i++){
		total = total+data[i];
	}
	average = total/(double)length; //length is type int
}

// This function offsets the signal based on an offset value inputted
void Signal::operator+(double offset_value){
	cout << "Offset started" << endl;
	int i;
	//array = new double [length];
	if(array.empty()){
		for(i=0;i<length;i++){
			array.push_back(data[i] + offset_value);
		}
	}else{
		for(i=0;i<length;i++){
			array[i] = data[i] + offset_value;
		}
	}
	cout << "The signal now is: ";
	print_signal(array);
}

//This function scales the signal based on a scale factor inputted
void Signal::operator*(double scale_factor){
	cout << "Scale started" << endl;
	//array = new double [length];
	int i;
	//printf("%f\n",scale_factor);
	if(array.empty()){
		for(i=0;i<length;i++){
			array.push_back(data[i] * scale_factor);
		}
	}else{
		for(i=0;i<length;i++){
			array[i] = data[i] * scale_factor;
		}
	}
	cout << "The signal now is: ";
	print_signal(array);
}


//This function centers the signal 
void Signal::center(Signal x){
	// Since centering is the same as offsetting the signal by a factor
	// of -mean, the offset can be used with an offset value of -mean
	cout << "Centering data" << endl;
	x + (-average);
}

// This function normalizes the singal
void Signal::normalize(Signal x){
	// Since normalizing is the same as scaling the signal by a factor
	// of 1/max, the scaleSignal() function can be used with a scale value of 1/max
	cout << "Normalizing data" << endl;
	//data * (1/(double)max);
	x*(1/(double)max);
}

// This is the first constructor which takes no parameters
// and initializes all members to zero or NULL
Signal::Signal(){
	// the vectors are defined as private members of the class and are already initialized to zero
	max = 0;
	//data = NULL;
	length = 0;
	average = 0;
	//array = NULL;
}

// This is the second constructor that takes in the file number
// and reads in the data from the file
Signal::Signal(int file){
	double cell;
	int i;
	char file_name[20];

	// form the file name using the file number
	if(file<9){
		sprintf(file_name,"Raw_data_0%d.txt",file);
	}else{
		sprintf(file_name,"Raw_data_%d.txt",file);
	}

	//open file
	FILE *fp = fopen(file_name,"r");
	if (fp == NULL){
		return;
	}

	// read in contents
	fscanf(fp,"%d %d",&length,&max);
	//data = new double [length];
	for(i=0;i<length;i++){
		fscanf(fp,"%lf",&cell);
		data.push_back(cell);
		//cout << data[i] << endl;
	}

	// Display the signal
	cout << "The signal from file is: ";
	print_signal(data);
	fclose(fp);
}

// This is the third constructor that takes in the file name
// and reads in the data from the file
Signal::Signal(const char * file_name){
	double cell;
	int i;

	// open file
	FILE *fp = fopen(file_name,"r");
	if (fp == NULL){
		return;
	}
	// read in contents
	fscanf(fp,"%d %d",&length,&max);
	//data = new double [length];
	for(i=0;i<length;i++){
		fscanf(fp,"%lf",&cell);
		data.push_back(cell);
	}
	//display signal
	cout << "The signal from file is: ";
	print_signal(data);
	fclose(fp);
}

// This is the destructor 
Signal::~Signal(){
	// nothing to be deleted here because use of vectors
}

Signal operator+(Signal &one, Signal &two){
	cout << "Inside 8" << endl;
	Signal three;

	// do element additions between one and two and then assign
	// those values to three's data
	for(int i=0;i<one.data.size();i++){
		three.data.push_back(one.data[i] + two.data[i]);
	}
	cout << endl;

	// get the max 
	if(one.max > two.max){
		three.max = one.max;
	}else{
		three.max = two.max;
	}

	double total;

	// print the new signals data and also calculate the average 
	cout << "The new signals data vector is: ";
	for(int i=0;i<three.data.size();i++){
		total+=three.data[i];
		cout << three.data[i];
		cout << " ";
	}
	three.average = total/three.data.size();

	cout << "\nThe max is: " << three.max << endl;
	cout << "The average is: " << three.average << endl;


	return three;
}

int main(int argc, char *argv[]){
	char filename[20];
	int filenumber = 0;
	int choice, i;
	int flag = 0; // for which transformation is done

	// if no command line arguments are given
	if(argc == 1){
		// as the user to enter the filename
		cout << "No arguments given" << endl;
		cout << "Enter filename> " << endl;
		cin >> filename;
	}
	// otherwise
	else if(argc == 3){
		// if -n is given
		if(strcmp(argv[1],"-n") == 0){
			//cout << "File number given" << endl;
			// check that a number is given
			if(isdigit(*argv[2])){
				filenumber = atoi(*(argv+2));
			}else{
				cout << "ERROR: '-n' expects a number not a string\nExiting.\n";
				return -1;
			}
			//cout << filenumber;
		}
		// if -f is given
		else if(strcmp(argv[1],"-f") == 0){
			cout << "File name given" << endl;

			if(isdigit(*argv[2])){
				// check that a string is given and not a number
				cout << "ERROR: '-f' expects a string not a number\nExiting.\n";
				return -1;
			}else{
				strcpy(filename,argv[2]);	
			}
		}
	// otherwise the input is incorrect
	}else{
		cout << "ERROR with arguments\nExpecting:\n\t'./a.out -n filenumber'\n\t'./a.out -f filename.txt'\n" << endl;
		return -1;
	}

	// initialize the object signal
	Signal sig1;
	// if a filenumber was given call the appropriate constructor 
	if(filenumber != 0){
		sig1 = Signal(filenumber);
		// check that the file was able to be read from 
		if(sig1.check_file_success() == -1){
			cout << "File given was not found.\nExiting.\n";
			return -1;
		}
	// otherwise a filename was given
	}else{
		// call the constructor 
		sig1 = Signal(filename);
		// check that the file was able to be read from
		if(sig1.check_file_success() == -1){
			cout << "File given was not found.\nExiting.\n";
			return -1;
		}
	}

	//get file number if filename is given
	if(filenumber == 0){
		char *split;
		split = strtok (filename,"_.");
    	split = strtok (NULL, "_.");
    	split = strtok(NULL, "_.");
    	filenumber = atoi(split);
    }

    // find the average of the signal
    sig1.mean();
    //cout << filenumber << endl;

    // User menu
	while(1){
		// ask the user to pick what they would like to do
		cout << "\nSelect:\n\t(0) Get Info\n\t(1) Offset\n\t(2) Scale\n\t(3) Center\n\t(4) Normalize\n\t(5) Statistic\n\t(6) Save To File\n\t(7) Exit\n\t(8) Add two Signals\n> ";
		cin >> choice;
		while(choice > 8 | choice < 0){
			cout <<"Invalid. Enter again: ";
			cin >> choice;
		}

		// based on their choice, call the correct method
		switch(choice){
			case 0:{
				// display info
				sig1.sig_info();
				break;}
			case 1: {
				// do offset
				flag = 1;
				double offset_num = 0.0;
				cout << "Enter offset value: ";
				cin >> offset_num;
				cout << "Calling offset" << endl;
				//sig1.offset(offset_num);
				sig1+offset_num;
				break;}
			case 2: {
				// do scale
				flag = 2;
				double scale_num = 0.0;
				cout << "Enter a scale factor: ";
				cin >> scale_num;
				//sig1.scale(scale_num);
				sig1*scale_num;
				break;}
				
			case 3:{
				// do center
				flag = 3;
				sig1.center(sig1);
				break;}
			
			case 4:{
				// do normalize
				flag = 4;
				sig1.normalize(sig1);
				break;}
			case 5:{
				// create statistics file
				sig1.statistics();
				break;}
			case 6:{
				// save signal to file
				sig1.save_file(flag,filenumber);
				break;}
				
			case 7:{
				// exit program
				return 0;
				break;}
			case 8:{
				// this is for the non-member addition operator
				Signal sig2("Raw_data_01.txt");
				Signal sig3("Raw_data_01.txt");
				Signal added;
				//Signal &x = sig2;
				//Signal &y = sig3;
				added = operator+(sig2,sig3);
			}
		}		
	}
}