#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <string> subsets(string s, int index, string current) {
	vector <string> results;//creates a vector of the subsets
	int size = s.size();
	for (int i = index + 1; i < size; i++) {
		current += s[i];//updates current to add each part of the string

	vector <string> new_results = subsets(s, i, current);//rescursively runs through the function with starting with each new letter
		for (int i = 0; i < new_results.size(); i++) {
			results.push_back(new_results[i]);//adds elements of new vector to vector to be returned
		}

		current.erase(current.size() - 1);
	}
	results.push_back(current);//inputs the elements into the vector starting from the largest element (end of for loop)

	return results;
}

vector <string> generate_subsets(string s) {
	int i = -1;
	string current = "";
	return subsets(s, i, current);//runs function that goes through each subset
}


int main()
{
	string word;
	string response;

	do {
		cout << "Enter a string: ";
		getline(cin, word);
		cout << pow(2, word.size()) << " subsets: " << endl;//tells us how many subsets there are

		for (int a = 0; a < generate_subsets(word).size(); a++) {
			cout << "\"" << generate_subsets(word)[a] << "\"" << endl;//outputs each element of the vector
		}

		cout << "Continue (y/n) ";
		getline(cin, response);
		cout << endl;

	} while (response == "y");

	return 0;
}