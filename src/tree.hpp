#include <functional>
#include <string>

namespace tree {

// Highly specialized tree
class Binary {
  public:
    struct Node {
        char data;

        struct Node *left;
        struct Node *right;
    };

    Binary() : root{nullptr} {}

    void construct(std::string constructor) {}

    bool eval() { return true; }

    ~Binary() {}

  private:
    struct Node *root;
};
} // namespace tree

template <typename T> class BinaryTree {
  public:
    struct Node {
        T data;

        struct Node *left;
        struct Node *right;
    };

    BinaryTree() : root{nullptr} {}

    void insert(T e) {}

    void traverse(std::function<void(struct Node *)> callback) {}

    ~BinaryTree() {}

  private:
    Node *root;
};
