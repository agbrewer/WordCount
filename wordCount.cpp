#include <vector>
#include <iostream>
#include <string>

struct node{
	std::string data;
	int appears;
};

//shellsort was adapted from www.geeksforgeeks.org/shellshort
void shellSortStrings(std::vector<node> data, int numberOfElements){
	for (int gap = numberOfElements/2; gap > 0; gap /= 2){
		for (int i = gap; i < numberOfElements; i++) {
			std::string temp = data[i].data;
			int tempN = data[i].appears;
			int j;
			for (j = i; j >= gap && data[j - gap].data > temp; j -= gap){
				data[j].data = data[j - gap].data;
				data[j].appears = data[j - gap].appears;
			}
		data[j].data = temp;
		data[j].appears = tempN;
		}
	}
	
	for (auto i = 0; i < numberOfElements; i++){
		std::cout << data[i].data << " " << data[i].appears << "\n";
	}
}// shellShortStrings

void shellSortAppears(std::vector<node> data, int numberOfElements){
	for (int gap = numberOfElements/2; gap > 0; gap /= 2){
		for (int i = gap; i < numberOfElements; i++){
			std::string temp = data[i].data;
			int tempN = data[i].appears;
			int j;
			for (j = i; j >= gap && data[j - gap].appears < tempN; j -= gap){
				data[j].appears = data[j - gap].appears;
				data[j].data = data[j - gap].data;
			}
		data[j].data = temp;
		data[j].appears = tempN;
		}
	}

	for (auto i = 0; i < numberOfElements; i++){
		std::cout <<data[i].data << " " << data[i].appears << "\n";
	}
}// shellSortAppears

int main(){
	
	std::vector<node> table[26];
	std::vector<int> appears;
	std::vector<std::string> wordList;
	std::string word;
	
	//Read data from file
	while (std::cin >> word) {
		wordList.push_back(word);
		node temp;
		temp.data = word;
		temp.appears = 1;
		int sum = word.size(); //a very poor hash function, but it works
		
		//check if strings have been seen before
		for (int i = 0; i < table[sum].size(); i++){
			if (table[sum].at(i).data == word){
				// if they have been seen before
				// delete the other string and add one to appears
				temp.appears += table[sum].at(i).appears;
				table[sum].erase(table[sum].begin() + i);
			}

		}
		table[sum].push_back(temp);
	}


	
	std::vector<node> answer;
	
	//place data from hashtable into a new vector. This will make sorting easy.
	for (auto i = 0; i < 26; i++){
		for (auto j = 0; j < table[i].size(); j++){
			answer.push_back(table[i].at(j));
		}
	}	

	shellSortStrings(answer, answer.size());
	std::cout << "\n";
	shellSortAppears(answer, answer.size());
	return 0;
}
