#include <functional>
#include <optional>

template <typename T> class SinglyLinkedList {
  public:
    SinglyLinkedList() : head{nullptr}, tail{nullptr} {}

    // O(1)
    void append(T e) {
        if (!head) {
            head = new Node{nullptr, e};
            tail = head;
        } else {
            tail->next = new Node{nullptr, e};
            tail = tail->next;
        }
    }

    // O(1)
    void append(SinglyLinkedList<T> l) {
        if (!head) {
            head = l.head;
            tail = head;
        } else {
            tail->next = l.head;

            if (tail->next) {
                tail = tail->next;
            }
        }
    }

    // O(n)
    std::optional<T> find(std::function<bool(T)> predicate) {
        Node *node = _find(predicate);

        if (node)
            return node->data;

        return {std::nullopt};
    }

    ~SinglyLinkedList() {}

  private:
    struct Node {
        Node *next;

        T data;
    };

    Node *head;
    Node *tail;

    // O(n)
    Node *_find(std::function<bool(T)> predicate) {
        Node *iter = head;

        while (iter) {
            if (predicate(iter->data)) {
                return iter;
            }

            iter = iter->next;
        }

        return nullptr;
    }
};
