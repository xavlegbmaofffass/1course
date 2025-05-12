#include <iostream>
using namespace std;

struct Node {
    int key;
    int val1, val2;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key, int v1, int v2) {
    if (!root) {
        root = new Node{ key, v1, v2, nullptr, nullptr };
        return root;
    }
    if (key < root->key)
        root->left = insert(root->left, key, v1, v2);
    else
        root->right = insert(root->right, key, v1, v2);
    return root;
}

void print(Node* root, int space = 0, int indent = 4) {
    if (root) {
        print(root->right, space + indent);
        cout << string(space, ' ') << root->key << " (" << root->val1 << "," << root->val2 << ")" << endl;
        print(root->left, space + indent);
    }
}

Node* findMaxSumNode(Node* root, Node*& parent, Node* prev = nullptr) {
    static int maxSum = INT_MIN;
    static Node* maxNode = nullptr;
    if (!root) return maxNode;

    int sum = root->val1 + root->val2;
    if (sum > maxSum) {
        maxSum = sum;
        maxNode = root;
        parent = prev;
    }

    findMaxSumNode(root->left, parent, root);
    findMaxSumNode(root->right, parent, root);

    return maxNode;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            Node* succ = root->right;
            while (succ->left) succ = succ->left;
            root->key = succ->key;
            root->val1 = succ->val1;
            root->val2 = succ->val2;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}

Node* deleteMaxSumNode(Node* root) {
    Node* parent = nullptr;
    Node* target = findMaxSumNode(root, parent);
    if (target) {
        int keyToDelete = target->key;
        int sumToDelete = target->val1 + target->val2;
        root = deleteNode(root, keyToDelete);
        cout << "Удалена вершина с ключом " << keyToDelete
            << " и максимальной суммой значений: " << sumToDelete << endl;
    }
    return root;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Node* root = nullptr;
    int n, key, v1, v2;

    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Введите ключ и два значения: ";
        cin >> key >> v1 >> v2;
        root = insert(root, key, v1, v2);
    }

    cout << "Исходное дерево:\n";
    print(root);

    root = deleteMaxSumNode(root);

    cout << "\nДерево после удаления:\n";
    print(root);

    return 0;
}
