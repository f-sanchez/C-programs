#include<iostream>

using namespace std;

int main() {

	int answer = 7;

	int guess = 0;

	while (guess != answer) {
		cout << "Guess the number: ";
		cin >> guess;

		if (guess == answer) {
			cout << "You got it!" << endl;
		}
		else if (guess > answer) {
			cout << "Guess is too high." << endl;
		}
		else {
			cout << "Guess is too low." << endl;
		}
	}

	/*int n;
	cin >> n;*/
	return 0;
}