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

int countNumberOfRunes (vector<string> words, string Sentence, int wordSize) {
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
    for (string sentence: sentences) {
            int size = sizeof(words) / sizeof(words[0]);
        partTwo += countNumberOfRunes(words, sentence, size);
    }
    cout << "Part Two :" << partTwo << endl;
}

/// PART 3 : COMING SOON

int main() {
    part1();
    part2();
    return 0;
}
