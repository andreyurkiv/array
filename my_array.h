//
// Created by dinamic on 11/9/18.
//

#include <iostream>
#include <stdexcept>

#ifndef MY_VECTOR_MY_ARRAY_H
#define MY_VECTOR_MY_ARRAY_H



template<class T, std::size_t N>
struct my_array {

    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::size_t size_t;

    // element access

    T& at(size_t pos);
    const T& at(size_t pos) const;
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data() noexcept;
    const T* data() const noexcept;

    // iterators

    iterator begin() noexcept { return array; }
    const_iterator begin() const noexcept { return array; }
    const_iterator cbegin() const noexcept { return array; }

    iterator end() noexcept { return array + N; }
    const_iterator end() const noexcept { return array + N; }
    const_iterator cend() const noexcept { return array + N; }

    std::reverse_iterator<iterator> rbegin() noexcept {
        return std::reverse_iterator<iterator>(end());
    }
    const std::reverse_iterator<iterator> rbegin() const noexcept {
        return std::reverse_iterator<iterator>(end());
    }
    std::reverse_iterator<iterator> rend() noexcept {
        return std::reverse_iterator<iterator>(begin());
    }
    const std::reverse_iterator<iterator> rend() const noexcept {
        return std::reverse_iterator<iterator>(begin());
    }

    std::reverse_iterator<const_iterator> crbegin() noexcept {
        return std::reverse_iterator<const_iterator >(end());
    }
    std::reverse_iterator<const_iterator> crend() const noexcept {
        return std::reverse_iterator<const_iterator>(begin());
    }

    // capacity

    constexpr bool empty() const noexcept;
    constexpr size_t size() const noexcept;

    // operations

    void fill(const T& value);
    void swap(my_array& other) noexcept;

    T array[N];
};

template<class T, size_t N>
T &my_array<T, N>::at(size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("Index out of range");
    } else {
        return *(array + pos);
    }
}

template<class T, size_t N>
const T &my_array<T, N>::at(size_t pos) const {
    if (pos >= N) {
        throw std::out_of_range("Index out of range");
    } else {
        return *(array + pos);
    }
}

template<class T, size_t N>
T &my_array<T, N>::operator[](size_t pos) {
    return *(array + pos);
}

template<class T, size_t N>
const T &my_array<T, N>::operator[](size_t pos) const {
    return *(array + pos);
}

template<class T, size_t N>
T &my_array<T, N>::front() {
    return *(array);
}

template<class T, size_t N>
const T &my_array<T, N>::front() const {
    return *(array);
}

template<class T, size_t N>
T &my_array<T, N>::back() {
    return N ? *(array + N - 1) : *(array + N);
}

template<class T, size_t N>
const T &my_array<T, N>::back() const {
    return N ? *(array + N - 1) : *(array + N);
}

template<class T, size_t N>
T *my_array<T, N>::data() noexcept {
    return array;
}

template<class T, size_t N>
const T *my_array<T, N>::data() const noexcept {
    return array;
}

template<class T, size_t N>
constexpr bool my_array<T, N>::empty() const noexcept {
    return N == 0;
}

template<class T, size_t N>
constexpr size_t my_array<T, N>::size() const noexcept {
    return N;
}

template<class T, size_t N>
void my_array<T, N>::fill(const T &value) {
    for(size_t i = 0; i < N; ++i){
        array[i] = value;
    }
}

template<class T, size_t N>
void my_array<T, N>::swap(my_array &other) noexcept {
    std::swap_ranges(begin(), end(), other.begin());
}



template< class T, std::size_t N >
bool operator==( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return false;
        }
    }
    return true;
}

template< class T, std::size_t N >
bool operator!=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return true;
        }
    }
    return false;
}

template< class T, std::size_t N >
bool operator>( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return *(lhs.array + i) > *(rhs.array + i);
        }
    }
    return false;
}

template< class T, std::size_t N >
bool operator<( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return *(lhs.array + i) < *(rhs.array + i);
        }
    }
    return false;
}

template< class T, std::size_t N >
bool operator>=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return *(lhs.array + i) > *(rhs.array + i);
        }
    }
    return true;
}

template< class T, std::size_t N >
bool operator<=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    for (size_t i = 0; i < N; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return *(lhs.array + i) < *(rhs.array + i);
        }
    }
    return true;
}

#endif //MY_VECTOR_MY_ARRAY_H