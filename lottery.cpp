// Demonstrates displaying an array passed to a function
// Kaila Anderson
// October 3, 2022

#include <iostream>
#include <cstdlib>

void assign(int[], int);
bool check(int[], int);
void draw(int[]);
int entry(int);
void printOut(int[]);

using std::cin; using std::cout; using std::endl;

const int arraySize = 10; 
int chosen[arraySize]; 

int main() {

	assign(chosen, -1);
	draw(chosen); 
	for (int input = 0; input < 5; ++input) {
		int guess = entry(input); 
		bool winOrLose = check(chosen, guess);
		if (winOrLose == true) {
			cout << "You've won the lottery! Congratulations!" << endl;
			exit(true);
		}
	}
	cout << "Sorry, you did not win the lottery today. Try again sometime!" << endl;
	printOut(chosen); 

}

// initialize array to -1
void assign(int[], int) {
	 
	for (int element = 0; element < arraySize; ++element) { 
		chosen[element] = -1; 
	}	
}

// check if number is already in array
// true if in array, false if not
bool check(int[], int number) {

	for (int element = 0; element < arraySize; ++element) {
		if (number == chosen[element]) {
			return true;
		}
	} return false;
}

// generate a random number to add to list of lottery numbers
void draw(int[]) {
	for (int element = 0; element < arraySize; ++element) {
		int lottoNum = rand() % 100; 
		if (check(chosen, lottoNum)) {
			chosen[element] = rand() % 100; //if number is not already in array, add to array
		}
		chosen[element] = lottoNum;
	}
}

// user lottery number entry
int entry(int input) {
	cout << "Insert a number from 0 to 99 to have a chance at winning the lottery!: " << endl; 
	cin >> input;
	return input; 
}

//prints out the lottery numbers
void printOut(int[]) { 
	cout << "The Lottery Numbers were: ";

	for (int element = 0; element < arraySize; ++element) {
		cout << chosen[element] << " "; 

	} 
	cout << endl;
}