class Node{
    public:
    int bestInd;
    Node* next[26];

    Node(){
        bestInd = -1;
        for(int i = 0;i<26;i++)
            next[i] = nullptr;
    }

    ~Node(){
        for(int i = 0;i < 26;i++)
            delete next[i];
    }

    bool exists(char c){
        return next[c - 'a'] != nullptr;
    }

    Node* get(char c){
        return next[c - 'a'];
    }

    void put(char c){
        next[c - 'a'] = new Node();
    }
};

class Trie{
    public:
    Node *root;
    vector<string> words;
    Trie(vector<string>& wordsContainer){
        words = wordsContainer;
        root = new Node();
    }

    ~Trie(){
        delete root;
    }

    void updateBestInd(Node *temp, int ind){
        if(temp->bestInd == -1)
            temp->bestInd = ind;
        else{
            int currInd = temp->bestInd;
            if(words[ind].size() < words[currInd].size() or words[ind].size() == words[currInd].size() and ind < currInd)
                temp->bestInd = ind;
        }
    }

    void insert(int ind, string s){
        Node *temp = root;
        updateBestInd(temp, ind);
        for(int i = s.size() - 1;i >= 0;i--){
            if(!temp->exists(s[i]))
                temp->put(s[i]);
            temp = temp->get(s[i]);
            updateBestInd(temp, ind);
        }
    }

    int findShortest(string s){
        Node *temp = root;
        int i = s.size() - 1;
        while(i >= 0){
            if(temp->exists(s[i]))
                temp = temp->get(s[i]);
            else
                break;
            i--;
        }
        return temp->bestInd;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie(wordsContainer);
        for(int i = 0;i < wordsContainer.size();i++){
            trie.insert(i, wordsContainer[i]);
        }
        vector<int> ans;
        for(string s: wordsQuery){
            ans.push_back(trie.findShortest(s));
        }
        return ans;
    }
};