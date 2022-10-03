/*

There is a dictionary A of N words, and ith word has a unique weight Wi.

Another string array B of size M contains the prefixes. For every prefix B[i], output atmost 5 words from the dictionary A that start with the same prefix.

Output the words in decreasing order of their weight.

NOTE: If there is no word that starts with the given prefix output -1.



*/


#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode{
    public:
        TrieNode *alphabets[26]; 
        bool endOfword;
        vector<int>indexes;

        TrieNode(){
            for (int i=0; i<26; i++){
                alphabets[i]=NULL; 
            }
            endOfword=false; 
        }
};

void insertTrie(TrieNode *root, string &s, int index){
    for (int i=0; i<s.size(); i++){
        if (root->alphabets[s[i]-'a']==NULL){
            root->alphabets[s[i]-'a']=new TrieNode(); 
        }
        if (root->indexes.size()<5) root->indexes.push_back(index); 
        root=root->alphabets[s[i]-'a']; 
    }
    if (root->indexes.size()<5) root->indexes.push_back(index); 
    root->endOfword=true; 
}

bool comp(pair <string,int> p1, pair <string,int>p2){
    if (p1.second>=p2.second) return true; 
    return false;
}

void searchAndPrint(vector <pair<string,int> > &words, TrieNode *root, string &prefix){
    TrieNode *temp=root; 
    int flag=1; 
    
    for (int i=0; i<prefix.size(); i++){
        if (temp->alphabets[prefix[i]-'a']==NULL){
            cout << "-1 "; 
            flag=0; 
            break; 
        }
        temp=temp->alphabets[prefix[i]-'a']; 
    }

    if (flag){
        for (int i=0; i<temp->indexes.size(); i++){
            cout << words[temp->indexes[i]].first << " "; 
        }
    }

    cout << endl; 
    
}



void solve(){
    int N, M;
    cin >> N; 
    cin >> M; 
    vector <pair<string,int>> words(N);

    for (int i=0; i<N; i++){
        cin >> words[i].first; 
    }

    for (int i=0; i<N; i++){
        cin >> words[i].second;  
    }

    sort(words.begin(), words.end(), comp); 

   /* for (int i=0; i<N; i++){
        cout << words[i].first << " " << words[i].second << " " << endl; 
    }
    */

    TrieNode *root=new TrieNode(); 

    for (int i=0; i<N; i++){
        insertTrie(root,words[i].first,i); 
    }

    for (int i=0; i<M; i++){
        string prefix; 
        cin >> prefix; 

        searchAndPrint(words, root,prefix); 
    }
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int T; 
    cin>>T; 

    while(T--){
        solve(); 
    }
    
    return 0;
}