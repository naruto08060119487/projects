#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <map>
#include <list>
#include <sstream>
#include <vector>
using namespace std;

vector<string> fileReader(string path)
{
    //read the file
    ifstream infile(path) ;
    //create a vector to hold the files read
    vector<string> lin;
    //check if the file opens successfully
    if (!infile.is_open()) {
        cout << "Error opening file " << path << endl;
        return lin;
    }
    string lines;
    while (getline(infile, lines)) {
        string tempLine;

        for (char ch : lines) {
            ch = tolower(ch);
            tempLine += ch;

            if(ch  == '.' ){
                tempLine += "\n";
            }
        }
        lin.push_back(tempLine);

    }
    infile.close();
    return lin;
}

void searchFile(vector<string> lines, string const &input) {

    map<string, int> freq;


    for( int i = 0; i < lines.size(); i++ ) {
        const auto&(word) = lines[i];
        istringstream stream(word);
        string temp;

        while(stream >> temp) {
            for( int j = 0; j < temp.length(); j++) {
                if(ispunct(temp[j]) && temp[j] != '+') {
                    temp[j] = ' ';
                }
            }
            string sam = temp;
            for( char c : sam) {
                tolower(c);
            }
            istringstream wordstream(sam);
            while(wordstream >> sam) {
                if(!sam.empty()) {

                    freq[sam]++;


                }
            }
        }

    }
    bool found = false;
    for(const auto &it : freq) {

        if(it.first == input) {
            cout << it.second << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout<< 0<<endl;
    }


}
int wordCounter(vector<string> lines) {
    int wordCounter = 0;

    for(auto& line : lines) {
        string tempLine;
        for (char ch : line) {
            if(isalnum(ch) || ch == '+' || ch == '-') {
                tempLine.push_back(ch);
            }
            else if(isspace(ch)) {
                tempLine.push_back(' ');
            }
        }

        istringstream stream (tempLine);
        string word;
        while (stream >> word) {
            wordCounter++;
        }

    }
    return wordCounter;
}
void wordFrequencyCounter(vector<string> lines) {
    map<string, int> freq;

    for(const auto & word : lines) {
       istringstream stream(word);
        string temp;

        while(stream >> temp) {
            for( int j = 0; j < temp.length(); j++) {
                if(ispunct(temp[j])&& temp[j] != '+' ) {
                    temp[j] = ' ';
                }
            }
            istringstream wordstream(temp);
            while(wordstream >> temp) {
                if(!temp.empty()) {
                    freq[temp]++;
                }
            }
        }

    }
    for(auto & it : freq) {
        cout << it.first << " = " << it.second << endl;
    }
}
int sentenceCounter(vector<string> lines) {
    int tempnumber = 0;
    for(auto & line : lines) {
        for(int j = 0; j < line.length(); j++) {
            if(line[j] == '.' || line[j]  == '!' || line[j]  == '?') {
                tempnumber++;
            }
        }

    }
    return tempnumber;
}

void indexer(const vector<string>& lines, const string& input) {
    list<string> newWords;


    for (const auto & line : lines) {
        istringstream stream(line);
        string temp;

        while (stream >> temp) {

            string cleanedWord;
            for (char& ch : temp) {
                if (isalnum(ch) || ch == '+' || ch == '-') {
                    cleanedWord.push_back(tolower(ch));
                }
            }

            for (char& ch : cleanedWord) {
                ch = tolower(ch);
            }
            newWords.push_back(cleanedWord);
        }
    }


    bool found = false;
    int index = 1;
    for (const auto& word : newWords) {
        if (word == input) {
            cout << input << " found at index " << index << endl;
            found = true;
        }
        index++;
    }

    if (!found) {
        cout << input << " not found in the document." << endl;
    }
}


int main() {
    string path = "/home/emmanuel/clionProject/Task2_input_test.txt";
    vector<string> lines = fileReader(path);
    string input;


    if(!lines.empty()) {
        cout<<"file content is: \n";
    }
    for( const auto& line : lines) {
        cout << line << endl;
    }
    int sentencecounter = sentenceCounter(lines);
    int wordcounter = wordCounter(lines);



    cout << "number of sentences= "<<sentencecounter << endl;
    cout << "number of words is = "<<wordcounter << endl;
    wordFrequencyCounter(lines);

    cout<<"what word do u want to search for?";
    getline(cin, input);
    for(char &ch : input) {
        ch = tolower(ch);
    }
    searchFile(lines, input);
    indexer(lines, input);

    return 0;
}
