 /*
  Author: Dennis Hu
  Course: {135,136}
  Instructor: 
  Assignment: Project 3a

  This program does:
  1. Removes a range of punctuation / symbols by setting limits with their ASCII Values and adding the ASCI Value of 32 to all ASCII value range of uppercase letters
  2. Counts the amount of words inputted by user to make sure it is a valid entry. The sentence must be at least three to four words.
  3. Extracts each words using four four loops by starting with the first loop to obtain the first word and then using the index of the first loop to initialize the next loop...
  4. Then determines if the sentence is either three or four words.
  5. If three, checks rules 1/3/5. If four, checks rules 2/4
  
  CONTINUED FOR Project 3
    Reused code from Project 1, but this time reprsenting an ADT using classes. Added vectors to store the wordlist files and we iterate the elements in a vector to compare the words from inputted sentence.
  
	Input:
	1. thanks come thanks
	2. history see different people
	3. i develop bird
	4. yourself add united meat
	5. whos her learn
	6. i see i
	
	Output:
	1.Your sentence is a legal sentence by rule {1}
	2.Your sentence is a legal sentence by rule {2}
	3.Your sentence is a legal sentence by rule {3)
	4.Your sentence is a legal sentence by rule {4}
	5.Your sentence is not a legal sentence.
	6.Your sentence is a legal sentence by rule {5}
  
  
  
  
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Sentence{
	public:
		
		
		// accessor / mutator
		string setString(string sentence){ userInput = sentence;}
		string getString(string sentence){ return userInput;}
		

		// member functions
		
		
		string remExcess(string s);
	    string wordExtract(string s);
		int wordCount(string s);
		bool checkNoun(string word);
		bool checkVerb(string word);
		bool checkPronoun(string word);
		bool checkAdj(string word);
		string sentCheck(string s);
	    void readNouns();
		void readVerbs();
		void readAdjs();
		void readPronouns();
		
	private:
		string userInput;
		string fixedInput;
		vector<string> nounList;
		vector<string> adjList;
		vector<string> pronounList;
		vector<string> verbList;
		string w1;
		string w2;
		string w3;
		string w4;
		
		
};
string Sentence::remExcess(string s){
	for(int i = 0; i < s.length(); i++){ // Removes a range of ASCII punctuation / symbols and sets uppercases to lowercases.
		if(s[i] > 32 && s[i] < 65){
			s[i] = 32;
		}
		if(s[i] > 64 && s[i] < 91){
			s[i] += 32;
		}
	}
	return s;
}
int Sentence::wordCount(string s){ //Forumula for checking to see if there are at least three to four words to be considered a valid input.
	int wordCount = 0;
	char space = ' '; //incase a space is infront of string
	string sr = remExcess(s);
	for(int y = 0; y < sr.length(); y++){
		if(s[y] == ' '){		
			space = s[y];
		}
		if(s[y]!=' ' && space== ' '){
			wordCount += 1;			// Word counter
			space = s[y];
		}
	}
	return wordCount;
}
string Sentence::wordExtract(string s){
	int pos1 = 0;
	int pos2 = 0;
	int pos3 = 0;
	int pos4 = 0;
	string sent = remExcess(s);
	for(int index1 = 0; index1 < sent.length(); index1++){
		if(sent[index1] != ' '){
			w1 += sent[index1];
			pos1 = index1 + 1;
			if(sent[pos1] == ' '){
				break;
			}
		}
	}
	for(int index2 = pos1; index2 < sent.length(); index2++){
		if(sent[index2] != ' '){
			w2 += sent[index2];
			pos2 = index2 + 1;
			if(sent[pos2] == ' '){
				break;
			}
		}
	}
	for(int index3 = pos2; index3 < sent.length(); index3++){
		if(sent[index3] != ' '){
		w3 += sent[index3];
			pos3 = index3 + 1;
			if(sent[pos3] == ' '){
				break;
			}
		}
	}
	if(wordCount(sent) == 4)
	{
		for(int index4 = pos3; index4 < sent.length(); index4++){
			if(sent[index4] != ' '){
				w4 += sent[index4];
				pos4 = index4 + 1;
				if(sent[pos4] == ' '){
					break;
				}
			}
		}
	}
	return sent;
}

bool Sentence::checkNoun(string word){ // Function that checks if the extracted word is a noun and returns a bool value
    string t1 = word;
	for(int i=0;i<nounList.size();i++)
	{
        if(nounList[i] == word)
            return true;
    }
    
}
bool Sentence::checkVerb(string word){ // Function that checks if the extracted word is a verb and returns a bool value
	string t2 = word;
	for( int i = 0; i < verbList.size(); i++)
	{
		if(verbList[i] == t2)
			return true;
		
	}
	return 0;
}
bool Sentence::checkPronoun(string word){ // Function that checks if the extracted word is a pronoun and returns a bool value
	string t3 = word;
	for( int i = 0; i < pronounList.size(); i++)
	{
		if(pronounList[i] == t3)
			return true;
		
	}
	return 0;
}
bool Sentence::checkAdj(string word){	
	string t4 = word;
	for( int i = 0; i < adjList.size(); i++)
	{
		if(adjList[i] == t4)
			return true;
		
	}
	return 0;
}
void Sentence::readNouns(){
	ifstream nList;
	nList.open("nouns");
	string temp1;
	while (!nList.eof()){                  //while not the end of file
		while (nList >> temp1){
			nounList.push_back(temp1);     //store vector with all the words
		}
	}
	nList.close();
}
void Sentence::readVerbs(){
	ifstream vList;
	vList.open("nouns");
	string temp2;
	while (!vList.eof()){                  //while not the end of file
		while (vList >> temp2){
			verbList.push_back(temp2);     //store vector with all the words
		}
	}
	vList.close();
}
void Sentence::readAdjs(){
	ifstream aList;
	aList.open("nouns");
	string temp3;
	while (!aList.eof()){                  //while not the end of file
		while (aList >> temp3){
			adjList.push_back(temp3);     //store vector with all the words
		}
	}
	aList.close();
}
void Sentence::readPronouns(){
	ifstream pList;
	pList.open("nouns");
	string temp4;
	while (!pList.eof()){                  //while not the end of file
		while (pList >> temp4){
			pronounList.push_back(temp4);     //store vector with all the words
		}
	}
	pList.close();
}

string Sentence::sentCheck(string s){
    
	if(checkNoun(w1) == true && checkVerb(w2) == true && checkNoun(w3) == true)
	{
        cout<<"Your sentence is a legal sentence by rule 1";
    }
	if(checkNoun(w1) == true && checkVerb(w2) == true && checkAdj(w3) && checkNoun(w4) == true)
	{
		cout<<"Your sentence is a legal sentence by rule 2";
    }
	if(checkPronoun(w1) == true && checkVerb(w2) == true && checkNoun(w3) == true)
	{
		cout<<"Your sentence is a legal sentence by rule 3";
	}
     if(checkPronoun(w1) == true && checkVerb(w2) == true && checkAdj(w3) && checkNoun(w4) == true)
	{
		cout<<"Your sentence is a legal sentence by rule 4";
	}
	if(checkPronoun(w1) && checkVerb(w2) && checkPronoun(w3))
	{
		cout<<"Your sentence is a legal sentence by rule 5";
	}
	else
		cout<<"Your sentence is not a legal sentence." << endl;
}
int main(){
	Sentence sent;
	string userIN;
	cout << "Enter a three or four word sentence: ";
	getline(cin, userIN);
	sent.setString(userIN);
	
	while (sent.wordCount(userIN) > 4 || sent.wordCount(userIN) <=0)	
	{  // Check if inputted sentence is legal(THREE or FOUR words)
		cout << "Enter a valid response";
		getline(cin, userIN);
		sent.setString(userIN);
	}
	// read from file and store in vector
	sent.readAdjs();
	sent.readNouns();
	sent.readPronouns();
	sent.readVerbs();
	sent.wordExtract(userIN);
	// end result 
	cout << sent.sentCheck(userIN);
	
	return 0;
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
