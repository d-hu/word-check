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