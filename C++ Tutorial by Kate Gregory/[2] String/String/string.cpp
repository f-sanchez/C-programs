#include<iostream>
#include<string>

using namespace std;

void flush_stdin(void) {
	int ch;
	do {
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

int main() {
	
	/* DEMO
	string name;

	cout << "Who are you? ";
	cin >> name;
	string greeting = "Hello, " + name;

	if (name == "Fretzel") {
		greeting += ", I know you!";
	}
	cout << greeting << endl;

	int l = greeting.length();
	cout << "\"" + greeting + "\" is " << l << " characters long." << endl << endl;

	auto space = greeting.find(' ');
	cout << "space: " << space << endl;
	string beginning = greeting.substr(space + 1);
	cout << greeting.substr(space, 2) << endl;
	cout << greeting.substr(space + 1) << endl;
	cout << greeting.substr(space + 2) << endl;
	cout << greeting.substr(space + 3) << endl;
	cout << beginning << endl;
	if (beginning == name) {
		cout << "expected result." << endl;
	}
	*/

	string word1;
	string word2;

	int choice;
	while (1) {
		cout << endl << "--------------------------------" << endl;
		cout << "[1] Compare length of two words" << endl;
		cout << "[0] Exit" << endl;
		cout << "Please choose a task." << endl;
		cin >> choice;
		flush_stdin();

		if (choice == 1) {
			cout << "Enter word1: ";
			getline(cin, word1);
			cout << "Enter word2: ";
			getline(cin, word2);
			system("cls");

			if (word1.length() == word2.length()) {
				
				cout << "Word1 and word2 have the same length." << endl;
			}
			else if (word1.length() > word2.length()) {
				
				cout << "Word1 is longer than word2." << endl;
			}
			else {
				
				cout << "Word2 is longer." << endl;
			}

			cout << "Word1 \" " + word1 << "\" length: " << word1.length() << endl;
			cout << "Word2 \" " + word2 << "\" length: " << word2.length() << endl;
		}
		else {
			exit(0);
		}	
	}

	system("pause");
	return 0;
}