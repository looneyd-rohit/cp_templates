class Node {
public:
  vector<Node *> children;
  bool isEnd;
  Node() {
    this->children.resize(10, NULL);
    this->isEnd = false;
  }
  bool containsKey(char ch) { return this->children[ch - '0'] != NULL; }
  void insertChild(char ch, Node *node) { this->children[ch - '0'] = node; }
  Node *getChild(char ch) { return this->children[ch - '0']; }
  void markEnd() { this->isEnd = true; }
};
class Trie {
public:
  Node *root;
  Trie() { this->root = new Node(); };
  void insert(string &word) {
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        // not present
        // insert
        node->insertChild(word[i], new Node());
      }
      node = node->getChild(word[i]);
    }
    // mark as end
    node->markEnd();
  }
  int searchAndCount(string &word) {
    int len = 0;
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        // not present
        return len;
      }
      node = node->getChild(word[i]);
      len++;
    }
    return len;
  }
};