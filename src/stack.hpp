#include <cstdio>
#include <cstring>
#include <optional>

// Incredibly inefficient FILO stack
template <typename T> class Stack {
  public:
    Stack() : data{nullptr}, capacity{0}, length{0} {}

    void push(T e) {
        if (length >= capacity) {
            increase_capacity_by_one();
        }

        *(data + length) = e;

        length += 1;
    }

    std::optional<T> peek() {
        if (data != nullptr && length > 0) {
            return *(data + length);
        }

        return {};
    }

    std::optional<T> pop() {
        if (data != nullptr && length > 0) {
            length -= 1;

            return *(data + length);
        }

        return {};
    }

    ~Stack() {}

  private:
    T *data;

    size_t capacity;
    size_t length;

    void increase_capacity_by_one() {
        T *new_data = new T[capacity + 1];

        if (data != nullptr) {
            memcpy(new_data, data, sizeof(T) * capacity);
        }

        data = new_data;

        capacity += 1;
    }
};
