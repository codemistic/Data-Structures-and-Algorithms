#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wordBreak(vector<string> const &dict, string word, string out)
{
    if (word.size() == 0)
    {
        cout << out << endl;
        return;
    }

    for (int i = 1; i <= word.size(); i++)
    {

        string prefix = word.substr(0, i);


        if (find(dict.begin(), dict.end(), prefix) != dict.end()) {
            wordBreak(dict, word.substr(i), out + " " + prefix);
        }
    }
}

int main()
{

    vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

    string word = "Wordbreakproblem";

    wordBreak(dict, word, "");

    return 0;
}
