#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<string>

using namespace std;

set<wstring> process_text(wstring str)
{
    wstring word = L"";
    set<wstring> word_list;

    for (auto x: str)
    {
        if (x == ' ' || x == '.' || x == '!' || x == ',' || x == '?')
        {
            word_list.insert(word);
            word = L"";
        }
        else
        {
            word += x;
        }
    }
    return word_list;
}

int main()
{
    wifstream fileA;
    wifstream fileB;

    fileA.open("FileA.txt");
    
    wstring word;
    map<wstring, int> vocab;

    while (!fileA.eof())
    {
        getline(fileA, word);
        vocab.insert({word, 1});
    }
    fileA.close();
    
    fileB.open("FileB.txt");

    set<wstring> B_in_A;
    wstring line;
    
    while (!fileB.eof())
    {
        getline(fileB, line);
        set<wstring> word_list = process_text(line);
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