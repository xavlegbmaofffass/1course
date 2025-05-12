#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key) {
    if (!root) {
        root = new Node{ key, nullptr, nullptr };
        return root;
    }
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

int sumTree(Node* root) {
    if (!root) return 0;
    return root->key + sumTree(root->left) + sumTree(root->right);
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

    int total = sumTree(root);
    cout << "\nСумма значений всех узлов: " << total << endl;

    return 0;
}
