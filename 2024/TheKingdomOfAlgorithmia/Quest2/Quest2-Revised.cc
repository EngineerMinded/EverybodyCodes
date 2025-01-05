/* Wayne Mack
 * Everybody Codes
 * Quest 2
 */

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
/*********************************************************************
 * Create an array with boolean variables. every valid letter is     *
 * determined by a true boolean, count them and you get to the       *
 * answer for part 2.                                                *
 *********************************************************************/
int countNumberOfRunes (vector<string> words, string Sentence, int wordSize, bool isPart3) {
    int count = 0;
    bool validRunes[Sentence.size()];
    for (int o = 0; o < Sentence.size(); o++) {
        validRunes[o] = false;
    }
    for (int r = 0; r < words.size(); r++) {
        for (int x = 0; x < Sentence.size() - words[r].size() + 1; x++) {
            int w = 0;
            bool wholeWord = true;
            for(char letter : words[r]) {
                if (letter != Sentence[x + w]) {
                    wholeWord = false;
                }
                w++;
            }

            if (!wholeWord) {
               int v = w - 1;
               wholeWord = true;
               for(char letter : words[r]) {
                    if (letter != Sentence[x + v]) {
                        wholeWord = false;
                    }
                    v--;
                }

            }
            if (wholeWord) {
                for (int i = x; i < x + w; i++ ) {
                    validRunes[i] = true;
                } 
            }
        }
    }
    for (int o = 0; o < Sentence.size(); o++) {
        if (validRunes[o]) {
            count ++;
            //cout << Sentence[o];
        }
        else {
            //cout << '_';
        }
    }
    //cout << endl;
    return count;

}

void _countNumberOfRunes (vector<vector<bool>>& validRunes, vector<string> words, vector<string> Puzzle, int wordSize, bool isPart3) {
    int row = -1;
    for (string Sentence : Puzzle) {
        row++;
        for (int r = 0; r < words.size(); r++) {
            for (int x = 0; x < Sentence.size() - words[r].size() + 1; x++) {
                int w = 0;
                bool wholeWord = true;
                for(char letter : words[r]) {
                    if (letter != Sentence[x + w]) {
                        wholeWord = false;
                    }
                    w++;
                }

                if (!wholeWord) {
                   int v = w - 1;
                   wholeWord = true;
                   for(char letter : words[r]) {
                        if (letter != Sentence[x + v]) {
                            wholeWord = false;
                        }
                        v--;
                    }

                }
                if (wholeWord) {
                    for (int i = x; i < x + w; i++ ) {
                        validRunes[row][i] = true;
                    } 
                }
            }
        }
    }
}

int countNumberOfRunes2 (vector<string> words, vector<string> Puzzle, int wordSize, bool isPart3) {
    vector<vector<bool>> nodeTable;
    for (int q = 0; q < Puzzle.size(); q++) {
        vector<bool> newLine;
        for (int r = 0; r < Puzzle.size(); r++) {
            newLine.push_back(false);
        }
        nodeTable.push_back(newLine);
    }
    _countNumberOfRunes(nodeTable,words,Puzzle,wordSize,isPart3);
    int count = 0;
    for (int q = 0; q < Puzzle.size(); q++) {
        for (int r = 0; r < Puzzle.size(); r++) {
            if (nodeTable[q][r]) count++;
        }
    }
    return count;
}

void part1 () {
    //string words[] =  {"THE","OWE","MES","ROD","HER"};
    //string sentence = "AWAKEN THE POWER ADORNED WITH THE FLAMES BRIGHT IRE";
    string words[] = {"LOR","LL","SI","OR","IA","FF","NO"};
    string sentence = "LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT, SED DO EIUSMOD TEMPOR INCIDIDUNT UT LABORE ET DOLORE MAGNA ALIQUA. UT ENIM AD MINIM VENIAM, QUIS NOSTRUD EXERCITATION ULLAMCO LABORIS NISI UT ALIQUIP EX EA COMMODO CONSEQUAT. DUIS AUTE IRURE DOLOR IN REPREHENDERIT IN VOLUPTATE VELIT ESSE CILLUM DOLORE EU FUGIAT NULLA PARIATUR. EXCEPTEUR SINT OCCAECAT CUPIDATAT NON PROIDENT, SUNT IN CULPA QUI OFFICIA DESERUNT MOLLIT ANIM ID EST LABORUM.";
    int partOne = 0;
    for (string word : words) {
        partOne += countWordInSentence(word, sentence);
    }
    cout << "Part One: " << partOne << endl;
}

void part2 () {
    int partTwo = 0;
    //string words[] = {"THE","OWE","MES","ROD","HER","QAQ"};
    //string sentences[] = {"AWAKEN THE POWE ADORNED WITH THE FLAMES BRIGHT IRE","THE FLAME SHIELDED THE HEART OF THE KINGS","POWE PO WER P OWE R","THERE IS THE END","QAQAQ"};
    vector<string> words = readWordsFromFile("Q2P2Words.txt");
    vector<string> sentences = readWordsFromFile("Q2P2Sentence.txt");
    int size = sizeof(words) / sizeof(words[0]);
    for (string sentence: sentences) {
            
        partTwo += countNumberOfRunes(words, sentence, size, false);
    }
    cout << "Part Two :" << partTwo << endl;
    partTwo = 0;
    partTwo = countNumberOfRunes2(words,sentences,size,false);
    cout << "Part Two:" << partTwo << endl;
}

/// PART 3 : COMING SOON

void part3() {
    int part3 = 0;
    vector<string>words = readWordsFromFile("part3WordsExample.txt");
    vector<string>puzzle = readWordsFromFile("part3PuzzleExample.txt");
    cout << puzzle[0][1] << " PPPP " << puzzle[1][2] << endl;



}

int main() {
    part1();
    part2();
    part3();
    return 0;
}
