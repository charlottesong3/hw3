#ifndef HEAP_H
#define HEAP_H

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
    Heap(int m = 2, PComparator c = PComparator());
    ~Heap();

    void push(const T& item);
    const T& top() const;
    void pop();

    bool empty() const;
    std::size_t size() const;

private:
    std::vector<T> items_;
    int m_;
    PComparator comp_;
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
    : items_(), m_(m), comp_(c)
{
    if (m_ < 2) {
        throw std::invalid_argument("Heap arity must be at least 2");
    }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
    return items_.empty();
}

template <typename T, typename PComparator>
std::size_t Heap<T, PComparator>::size() const
{
    return items_.size();
}

template <typename T, typename PComparator>
const T& Heap<T, PComparator>::top() const
{
    if (empty()) { //cannot be empty 
        throw std::underflow_error("Cannot access the top of an empty heap");
    }

    return items_[0];
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
    items_.push_back(item);

    std::size_t current = items_.size() - 1;

    while (current > 0) {
        std::size_t parent =
            (current - 1) / static_cast<std::size_t>(m_);
// :3
        if (!comp_(items_[current], items_[parent])) {
            break;
        }

        std::swap(items_[current], items_[parent]);
        current = parent;
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
    if (empty()) {
        throw std::underflow_error("Cannot pop an empty heap");
    }

    if (items_.size() == 1) {
        items_.pop_back();
        return;
    }

    items_[0] = items_.back();
    items_.pop_back();

    std::size_t current = 0;

    while (true) {
        std::size_t firstChild =
            current * static_cast<std::size_t>(m_) + 1;

        if (firstChild >= items_.size()) {
            break;
        }

        std::size_t poopChild = firstChild;

        for (int offset = 1; offset < m_; ++offset) {
            std::size_t child =
                firstChild + static_cast<std::size_t>(offset);

            if (child >= items_.size()) {
                break;
            }

            if (comp_(items_[child], items_[poopChild])) {
                poopChild = child;
            }
        }

        if (!comp_(items_[poopChild], items_[current])) {
            break;
        } std::swap(items_[current], items_[poopChild]);
        current = poopChild;
    }
}

#endif