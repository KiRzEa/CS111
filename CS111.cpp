#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main()
{
    ifstream fileA;
    ifstream fileB;

    fileA.open("FileA.txt");
    
    string word;
    int line_number = 0;
    map<string, int> vocab;

    while (!fileA.eof())
    {
        line_number ++;
        getline(fileA, word);
        vocab.insert({word, 1});
    }
    fileA.close();
    
    fileB.open("FileB.txt");

    set<string> B_in_A;

    while (!fileB.eof())
    {
        getline(fileB, word);
        if (vocab[word] == 1)
            B_in_A.insert(word);
    }
    fileB.close();
    cout << (double(B_in_A.size()) / double(vocab.size())) * 100 << "%";
    return 0;
}