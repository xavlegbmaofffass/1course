#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key) {
    if (!root) return new Node{ key, nullptr, nullptr };
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void print(Node* t, int u) {
    if (t == NULL) return;

    print(t->left, u + 1);

    for (int i = 0; i < u; ++i)
        cout << "|";
    cout << t->key << endl;

    print(t->right, u + 1);
}

int countEvenKeys(Node* root) {
    if (!root) return 0;
    int count = (root->key % 2 == 0) ? 1 : 0;
    return count + countEvenKeys(root->left) + countEvenKeys(root->right);
}

int main() {
    setlocale(LC_ALL, "Russian");

    Node* root = nullptr;
    int n, key;

    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Введите ключ: ";
        cin >> key;
        root = insert(root, key);
    }

    cout << "\nДерево:\n";
    print(root, 0);

    int evenCount = countEvenKeys(root);
    cout << "\nКоличество узлов с чётными ключами: " << evenCount << endl;

    return 0;
}
