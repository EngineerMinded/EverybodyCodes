/* Wayne Mack
 * Everybody Codes
 * Quest 2
 */
// WHY DID I PUNISH MYSELF? I WANT TO GET BETTER AT C/C++ AND IF THIS THE WAY TO DO IT, WELL OKAY!!!
// CRYPTOCURRENCY IS A SCAM ... KIDS!
// JESUS SAVES !!!

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
/**************************************************************************
 * Read data from file and create data array from them                    *
 **************************************************************************/
std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);  // Open the file
    std::vector<std::string> words;  // Vector to store the words
    std::string word;

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return words;  // Return empty vector if file can't be opened
    }
    // Read the file word by word
    while (file >> word) {
        words.push_back(word);  // Add each word to the vector
    }

    file.close();  // Close the file
    return words;  // Return the vector of words
}
/********************************************************************
 * Count how many times a specific word shows up in the sentence    *
 ********************************************************************/
int countWordInSentence(string word, string sentence) {
    int count = 0;
    for (int x = 0; x < sentence.size() - word.size(); x++) {
        int w = 0;
        bool wholeWord = true;
        for(char letter : word) {
           if (letter != sentence[x + w]) {
                wholeWord = false;
           }
           w++;
        }
        if (wholeWord) {
           count++; 
        }
    }
    return count;
}
/**********************************************************************
 * Determine a safe number so that the number does not go over        *
 * creating a segmentation fault.                                     *
 **********************************************************************/
int revisedNumber (int number, int sentenceLimit) {
    return (number >= sentenceLimit) ? number - (sentenceLimit): number;
}
/***********************************************************************
 * This is the main procedure that determines the valid spaces for all *
 * of the runes to be counted. The Vector-vector-bool validRunes is    *
 * passed by reference and updated.                                    *
 ***********************************************************************/
void _countNumberOfRunes (vector<vector<bool>>& validRunes, vector<string> words, vector<string> Puzzle, bool isPart3, bool isSecondStepOfPart3) {
    int row = -1;
    for (string Sentence : Puzzle) {
        row++;
        for (int r = 0; r < words.size(); r++) {
            int wordSize = (isPart3 && !isSecondStepOfPart3) ? Sentence.size(): Sentence.size() - words[r].size() + 1;
            for (int x = 0; x < wordSize; x++) {
                int w = 0;
                bool wholeWord = true;
                for(char letter : words[r]) {
                    if (letter != Sentence[revisedNumber(x + w, Sentence.size())]) {
                        wholeWord = false;
                    }
                    w++;
                }
                if (!wholeWord) {
                   int v = w - 1;
                   wholeWord = true;
                   for(char letter : words[r]) {
                        if (letter != Sentence[revisedNumber(x + v, Sentence.size())]) {
                            wholeWord = false;
                        }
                        v--;
                    }
                }
                if (wholeWord) {
                    for (int i = x; i < x + w; i++ ) {
                        if (isSecondStepOfPart3) {
                            validRunes[row][revisedNumber(i, Sentence.size())]= true;
                        }
                        else {
                            validRunes[row][revisedNumber(i, Sentence.size())] = true;
                        }
                    } 
                }
            }
        }
    }
}
/********************************************************************
 * The answers for part 2 and part 3 are given here where the bool  *
 * vector is counted for true answers.                              *
 ********************************************************************/
int getCountForAnswers(vector<vector<bool>> nodeTable) {
    int count = 0;
    for (vector<bool> line : nodeTable) {
        for (bool thisOne : line) {
            if (thisOne == 1) count++;
        }
    }
    return count;
}
/*********************************************************************
 * Create an array with boolean variables. every valid letter is     *
 * determined by a true boolean, count them and you get to the       *
 * answer for part 2 and Part 3.                                     *
 *                                                                   *  
 * The main procedure is implemeted in _countNumberOfRunes above.    *
 *********************************************************************/
int countNumberOfRunes (vector<string> words, vector<string> Puzzle, int wordSize, bool isPart3 ) {
    vector<vector<bool>> nodeTable, nodeTable2;
    for (int q = 0; q < Puzzle.size(); q++) {
        vector<bool> newLine;
        for (int r = 0; r < Puzzle[q].size(); r++) {
            newLine.push_back(false);
        }
        nodeTable.push_back(newLine);
    }
    // revise nodeTable by reference
    _countNumberOfRunes(nodeTable,words,Puzzle,isPart3, false);
    if (isPart3) {
      
        vector<string>Puzzle2;
        for (int q = 0; q < Puzzle[0].length(); q++) {
            string newLine;
            vector<bool> newBool;
            for (int r = 0; r < Puzzle.size(); r++) {
                newLine = newLine + Puzzle[r][q];
                newBool.push_back(nodeTable[r][q]);
            }
            Puzzle2.push_back(newLine);
            nodeTable2.push_back(newBool);
        }
        _countNumberOfRunes(nodeTable2,words,Puzzle2,isPart3, true);
        
    }
    if (isPart3) {
        return getCountForAnswers(nodeTable2);
    }
    else {
        return getCountForAnswers(nodeTable);
    }
}
/*********************************************************************
 * Let's get the answer for part one.                                *
 *********************************************************************/
void part1 () {
    string words[] = {"LOR","LL","SI","OR","IA","FF","NO"};
    string sentence = "LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT, SED DO EIUSMOD TEMPOR INCIDIDUNT UT LABORE ET DOLORE MAGNA ALIQUA. UT ENIM AD MINIM VENIAM, QUIS NOSTRUD EXERCITATION ULLAMCO LABORIS NISI UT ALIQUIP EX EA COMMODO CONSEQUAT. DUIS AUTE IRURE DOLOR IN REPREHENDERIT IN VOLUPTATE VELIT ESSE CILLUM DOLORE EU FUGIAT NULLA PARIATUR. EXCEPTEUR SINT OCCAECAT CUPIDATAT NON PROIDENT, SUNT IN CULPA QUI OFFICIA DESERUNT MOLLIT ANIM ID EST LABORUM.";
    int partOne = 0;
    for (string word : words) {
        partOne += countWordInSentence(word, sentence);
    }
    cout << "Part One: " << partOne << endl;
}
/**********************************************************************
 * Let's get the answer for part two.                                 *
 **********************************************************************/
void part2 () {
    int partTwo = 0;
    vector<string> words = readWordsFromFile("Q2P2Words.txt");
    vector<string> sentences = readWordsFromFile("Q2P2Sentence.txt");
    int size = sizeof(words) / sizeof(words[0]);
    partTwo = countNumberOfRunes(words,sentences,size,false);
    cout << "Part Two: " << partTwo << endl;
}
/***********************************************************************
 * Let's get the answers for part three.                               *
 ***********************************************************************/
void part3() {
    int partThree = 0;
    vector<string>words = readWordsFromFile("part3Words.txt");
    vector<string>puzzle = readWordsFromFile("part3Puzzle.txt");
    int size = sizeof(words) / sizeof(words[0]);
    partThree = countNumberOfRunes(words,puzzle,size,true);
    cout << "Part Three: " << partThree<< endl;
}
/************************************************************************
 * THe main function                                                    *
 ************************************************************************/
int main() {
    part1();
    part2();
    part3();
    return 0;
}