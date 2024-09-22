#include <functional>

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
