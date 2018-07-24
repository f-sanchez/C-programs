#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //for sort and count

using namespace std;

int main() {
	
	vector<int> vi;
	for (int i = 0; i < 10; i++) {
		vi.push_back(i);
	}

	for (auto item : vi) {
		cout << item << " ";
	}
	cout << endl;

	vector<string> vs;
	cout << "Enter 3 words:" << endl;
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		vs.push_back(s);
	}

	for (auto item : vs) {
		cout << item << " ";
	}
	cout << endl;
	cout << "int vector vi has " << vi.size() << " elements" << endl;

	vi[5] = 99;
	//vi[1] = -1;
	vi[2] = 1;

	//one way to print
	for (auto item : vi) {
		cout << item << " ";
	}
	cout << endl;

	//another way
	for (unsigned int i= 0; i < vi.size(); i++) {
		cout << vi[i] << " ";
	}
	cout << endl;

	//3rd way
	for (auto i = begin(vi); i != end(vi); i++) {
		cout << *i << " ";
	}
	cout << endl;

	/********************/
	sort(begin(vs), end(vs));
	for (auto item : vs) {
		cout << item << " ";
	}
	cout << endl;

	int ones = count(begin(vi), end(vi), 1);
	cout << "vector of ints has " << ones << " 1 elements." << endl; 

	int tees = count(begin(vs[0]), end(vs[0]), 't');
	cout << "First word has " << tees << " letter t's." << endl;

	system("pause");
	return 0;
}