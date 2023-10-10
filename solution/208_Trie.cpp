//
// Created by Anti on 2022/11/10.
//
#include <iostream>
#include <map>
#include <string>
using std::map;
using std::string;
class TrieNode {
private:
    map<char, TrieNode *> children;
    char key;
    bool end_;

public:
    TrieNode(char c) : key(c), end_(false){};
    TrieNode *GetByKey(char key_) {
        auto it = children.find(key_);
        if (it == children.cend()) {
            return nullptr;
        }
        return it->second;
    }
    char GetKey() {
        return key;
    }
    void AddChild(char key_) {
        children[key_] = new TrieNode(key_);
    }
    bool IsEnd() {
        return end_;
    }
    void SetEnd(bool end) {
        end_ = end;
    }
};
class Trie {
public:
    Trie() {
        root_ = new TrieNode('\0');
    }

    void insert(string word) {
        auto current = root_;
        auto length = word.length();
        decltype(length) now = 0;
        while (now < length) {
            auto child = current->GetByKey(word[now]);
            if (child == nullptr) {
                current->AddChild(word[now]);
            }
            current = current->GetByKey(word[now]);
            now++;
        }
        current->SetEnd(true);
    }

    bool search(string word) {
        auto current = root_;
        auto length = word.length();
        decltype(length) now = 0;
        while (now < length) {
            auto child = current->GetByKey(word[now]);
            if (child == nullptr) {
                break;
            }
            current = child;
            now++;
        }
        return (now == length && current->IsEnd());
    }

    bool startsWith(string prefix) {
        auto current = root_;
        auto length = prefix.length();
        decltype(length) now = 0;
        while (now < length) {
            auto child = current->GetByKey(prefix[now]);
            if (child == nullptr) {
                break;
            }
            current = child;
            now++;
        }
        return (now == length);
    }

private:
    TrieNode *root_;
};
void test1() {
    char c;
    string s;
    using std::cin;
    using std::cout;
    using std::endl;
    auto tree = new Trie();
    while (cin >> c) {
        cin >> s;
        switch (c) {
            case 'i':// insert
                tree->insert(s);
                break;
            case 's':// search
                cout << tree->search(s) << endl;
                break;
            case 'w':// startwith
                cout << tree->startsWith(s) << endl;
                break;
            default:
                cout << "no matching action";
                break;
        }
    }
}

void test2() {
    char c;
    string s;
    using std::cin;
    using std::cout;
    using std::endl;
    auto tree = new Trie();
    Trie *obj = new Trie();
    string word = "apple";
    string prefix = "app";
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    cout << param_2 << " " << param_3 << endl;
}
int main() {
    test1();
}