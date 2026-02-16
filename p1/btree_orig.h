#include <memory>

using namespace std;

struct node
{
  int key_value;
  shared_ptr<node> left;
  shared_ptr<node> right;
};

class btree
{
    public:
		void insert(int key) {
			if (root != nullptr)
				insert(key, root);
			else
			{
				root = make_shared<node>();
				root->key_value = key;
			}
		}
		shared_ptr<node> search(int key) {
			return search(key, root);
		}

        btree copy() {
            btree tree;
			tree.root = copy(root);
            return tree;
		}

    private:
        shared_ptr<node> root;

        shared_ptr<node> copy(shared_ptr<node> originalRoot) {
            if (originalRoot == nullptr) {
                return nullptr;
            }

            shared_ptr<node> newRoot = make_shared<node>();

            newRoot->key_value = originalRoot->key_value;
            newRoot->left = copy(originalRoot->left);
            newRoot->right = copy(originalRoot->right);

            return newRoot;
        }
		void insert(int key, shared_ptr<node>& leaf) {
			if (key< leaf->key_value)
			{
				if (leaf->left != nullptr)
					insert(key, leaf->left);
				else
				{
					leaf->left = make_shared<node>();
					leaf->left->key_value = key;
				}
			}
			else if (key >= leaf->key_value)
			{
				if (leaf->right != nullptr)
					insert(key, leaf->right);
				else
				{
					leaf->right = make_shared<node>();
					leaf->right->key_value = key;
				}
			}
		}
		shared_ptr<node> search(int key, shared_ptr<node> leaf) {
			if (leaf != nullptr)
			{
				if (key == leaf->key_value)
					return leaf;
				if (key<leaf->key_value)
					return search(key, leaf->left);
				else
					return search(key, leaf->right);
			}
			else return nullptr;
		}
};




