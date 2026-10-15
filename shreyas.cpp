#include <iostream>
#include <string>
using namespace std;

struct Node {
    int songID;
    string songName;
    Node *left, *right;

    Node(int id, string name) {
        songID = id;
        songName = name;
        left = right = NULL;
    }
};

Node* root = NULL;
Node* head = NULL;
Node* prevNode = NULL;

// Insert a song into BST
Node* insert(Node* root, int id, string name) {
    if (root == NULL)
        return new Node(id, name);

    if (id < root->songID)
        root->left = insert(root->left, id, name);
    else if (id > root->songID)
        root->right = insert(root->right, id, name);
    else
        cout << "Song ID already exists!\n";

    return root;
}

// Display songs in sorted order
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->songID << " - "
         << root->songName << endl;
    inorder(root->right);
}

// Convert BST into sorted Doubly Linked List
void convertToDLL(Node* root) {
    if (root == NULL)
        return;

    convertToDLL(root->left);

    root->left = prevNode;

    if (prevNode == NULL)
        head = root;
    else
        prevNode->right = root;

    prevNode = root;

    convertToDLL(root->right);
}

// Display DLL from beginning to end
void displayDLL() {
    Node* temp = head;

    cout << "\nSorted Music Playlist:\n";

    while (temp != NULL) {
        cout << temp->songID << " - "
             << temp->songName << endl;
        temp = temp->right;
    }
}

int main() {
    int choice, id;
    string name;

    do {
        cout << "\n--- Music Playlist Application ---\n";
        cout << "1. Add Song\n";
        cout << "2. Display Songs (BST Sorted Order)\n";
        cout << "3. Convert BST to Doubly Linked List\n";
        cout << "4. Display Sorted Playlist\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;

            cout << "Enter Song Name: ";
            getline(cin >> ws, name);

            root = insert(root, id, name);
            break;

        case 2:
            cout << "\nSongs in Sorted Order:\n";
            inorder(root);
            break;

        case 3:
            if (head != NULL) {
                cout << "BST already converted!\n";
            } else if (root == NULL) {
                cout << "Playlist is empty!\n";
            } else {
                prevNode = NULL;
                convertToDLL(root);

                if (prevNode != NULL)
                    prevNode->right = NULL;

                cout << "BST converted successfully!\n";
            }
            break;

        case 4:
            displayDLL();
            break;

        case 5:
            cout << "Exiting application...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
