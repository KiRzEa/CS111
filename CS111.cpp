#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>

using namespace std;

set<string> process_text(string str)
{
    string word = "";
    set<string> word_list;

    for (auto x: str)
    {
        if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
        {
            word += x;
        }
        else
        {
            word_list.insert(word);
            word = "";
        }
    }
    return word_list;
}

int main()
{
    ifstream fileA;
    ifstream fileB;

    fileA.open("FileA.txt");
    
    string word;
    map<string, int> vocab;

    while (!fileA.eof())
    {
        getline(fileA, word);
        vocab.insert({word, 1});
    }
    fileA.close();
    
    fileB.open("FileB.txt");

    set<string> B_in_A;
    string line;
    
    while (!fileB.eof())
    {
        getline(fileB, line);
        set<string> word_list = process_text(line);
        for (auto word : word_list)
        {
            if (vocab[word] == 1)
                B_in_A.insert(word);
        }
    }
    fileB.close();

    cout << B_in_A.size() << endl;
    cout << (double(B_in_A.size()) / double(vocab.size())) * 100 << "%";
    
    return 0;
}