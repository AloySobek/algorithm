#include <functional>
#include <optional>

template <typename T> class SinglyLinkedList {
  public:
    SinglyLinkedList() : _head{nullptr} {}

    void prepend(T e) { _head = new Node(_head, e); }

    void append(T e) {
        Node *tail = _find([](Node *x) -> bool { return x->next == nullptr; });

        if (tail) {
            tail->next = new Node{nullptr, e};
        } else {
            _head = new Node(nullptr, e);
        }
    }

    std::optional<T> find(std::function<bool(T)> predicate) {
        Node *node = _find([&](Node *x) -> bool { return predicate(x->data); });

        if (node)
            return node->data;

        return {std::nullopt};
    }

    std::optional<T> at(size_t i) {
        size_t n{0};

        for (Node *iter = _head; iter; iter = iter->next, ++n) {
            if (n == i) {
                return iter->data;
            }
        }

        return {std::nullopt};
    }

    ~SinglyLinkedList() {}

  private:
    struct Node {
        Node *next;

        T data;
    };

    Node *_head;

    Node *_find(std::function<bool(Node *)> predicate) {
        for (Node *iter = _head; iter; iter = iter->next) {
            if (predicate(iter)) {
                return iter;
            }
        }

        return nullptr;
    }
};

template <typename T> class CircularSinglyLinkedList {
  public:
    CircularSinglyLinkedList() : _head{nullptr} {}

    void prepend(T e) { _head = new Node(_head, e); }

    void append(T e) {}

    std::optional<T> find(std::function<bool(T)> predicate) { return {std::nullopt}; }

    std::optional<T> at(size_t i) { return {std::nullopt}; }

    ~CircularSinglyLinkedList() {}

  private:
    struct Node {
        Node *next;

        T data;
    };

    Node *_head;
};

template <typename T> class DoublyLinkedList {
  public:
    DoublyLinkedList() : _head{nullptr} {}

    void prepend(T e) { _head = new Node(_head, e); }

    void append(T e) {}

    std::optional<T> find(std::function<bool(T)> predicate) { return {std::nullopt}; }

    std::optional<T> at(size_t i) { return {std::nullopt}; }

    ~DoublyLinkedList() {}

  private:
    struct Node {
        Node *next;

        T data;
    };

    Node *_head;
};

template <typename T> class CircularDoublyLinkedList {
  public:
    CircularDoublyLinkedList() : _head{nullptr} {}
    CircularDoublyLinkedList(CircularDoublyLinkedList<T> &other) {
        if (&other != this) {
            for (Node *iter = other._head; iter; iter = iter->next) {
                append(iter->data);
            }
        }
    }

    void clear() {
        for (Node *iter = _head; iter; iter = iter->next) {
        }
    }

    void prepend(T e) { _head = new Node(_head, e); }

    void append(T e) {}

    std::optional<T> find(std::function<bool(T)> predicate) { return {std::nullopt}; }

    std::optional<T> at(size_t i) { return {std::nullopt}; }

    ~CircularDoublyLinkedList() {}

  private:
    struct Node {
        Node *next;
        Node *prev;

        T data;
    };

    Node *_head;
};
