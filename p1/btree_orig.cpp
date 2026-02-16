#include <iostream>
#include "btree_orig.h"

using namespace std;

int main() {
    btree tree;

    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(5);
    tree.insert(8);

    shared_ptr<node> result = tree.search(6);
    if (result != nullptr)
        cout << "Found: " << result->key_value << endl;
    else
        cout << "Not found" << endl;

    result = tree.search(99);
    if (result != nullptr)
        cout << "Found: " << result->key_value << endl;
    else
        cout << "Not found" << endl;

    btree copy = tree.copy();
    result = copy.search(6);
    if (result != nullptr)
        cout << "Found: " << result->key_value << endl;
    else
        cout << "Not found" << endl;

    copy.insert(99);
    result = copy.search(99);
    if (result != nullptr)
        cout << "Found: " << result->key_value << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
