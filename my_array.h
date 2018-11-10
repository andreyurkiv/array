//
// Created by dinamic on 11/9/18.
//

#include <iostream>
#include <stdexcept>

#ifndef MY_VECTOR_MY_ARRAY_H
#define MY_VECTOR_MY_ARRAY_H



template<class T, std::size_t N>
struct my_array {
public:

    my_array(){
        array = new T[N];
    }

    my_array(std::initializer_list<T> list) {
        array = new T[N];
        for(const T& x : list){
            *(array + a_size) = x;
            a_size++;
        }
    }

    ~my_array(){
        delete [] array;
    }


    typedef T* iterator;
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
    const iterator begin() const noexcept { return array; }
    const iterator cbegin() const noexcept { return array; }

    iterator end() noexcept { return array + a_size; }
    const iterator end() const noexcept { return array + a_size; }
    const iterator cend() const noexcept { return array + a_size; }

    std::reverse_iterator<iterator> rbegin() noexcept {
        return std::reverse_iterator<iterator>(end());
    }
    const std::reverse_iterator<iterator> rbegin() const noexcept {
        return std::reverse_iterator<iterator>(end());
    }
    const std::reverse_iterator<iterator> crbegin() noexcept {
        return std::reverse_iterator<iterator>(end());
    }

    std::reverse_iterator<iterator> rend() noexcept {
        return std::reverse_iterator<iterator>(begin());
    }
    const std::reverse_iterator<iterator> rend() const noexcept {
        return std::reverse_iterator<iterator>(begin());
    }
    const std::reverse_iterator<iterator> crend() const noexcept {
        return std::reverse_iterator<iterator>(begin());
    }

    // capacity

    constexpr bool empty() const noexcept;
    constexpr size_t size() const noexcept;

    // operations

    void fill(const T& value);
    void swap(const my_array& other) noexcept;

    size_t a_size = N;
    T* array;
};

template<class T, size_t N>
T &my_array<T, N>::at(size_t pos) {
    if (pos >= a_size) {
        throw std::out_of_range("Index out of range");
    } else {
        return *(array + pos);
    }
}

template<class T, size_t N>
const T &my_array<T, N>::at(size_t pos) const {
    if (pos >= a_size) {
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
    return a_size ? *(array + a_size - 1) : *(array + a_size);
}

template<class T, size_t N>
const T &my_array<T, N>::back() const {
    return a_size ? *(array + a_size - 1) : *(array + a_size);
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
    return a_size == 0;
}

template<class T, size_t N>
constexpr size_t my_array<T, N>::size() const noexcept {
    return a_size;
}

template<class T, size_t N>
void my_array<T, N>::fill(const T &value) {
    for(size_t i = 0; i < a_size; ++i){
        *(array + i) = value;
    }
}

template<class T, size_t N>
void my_array<T, N>::swap(const my_array &other) noexcept {
    std::swap_ranges(begin(), end(), other.begin());
}



template< class T, std::size_t N >
bool operator==( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    if (lhs.a_size != rhs.v_size) return false;
    for (size_t i = 0; i < lhs.a_size; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return false;
        }
    }
    return true;
}

template< class T, std::size_t N >
bool operator!=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    if (lhs.a_size != rhs.v_size) return true;
    for (size_t i = 0; i < lhs.a_size; ++i) {
        if (*(lhs.array + i) != *(rhs.array + i)) {
            return true;
        }
    }
    return false;
}

template< class T, std::size_t N >
bool operator>( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    size_t min = lhs.a_size < rhs.a_size ? lhs.a_size : rhs.a_size;
    for (size_t i = 0; i < min; ++i) {
        if (*(lhs + i) != *(rhs.array + i)) {
            return *(lhs.array + i) > *(rhs.array + i);
        }
    }
    return lhs.a_size > rhs.v_size;
}

template< class T, std::size_t N >
bool operator<( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    size_t min = lhs.a_size < rhs.a_size ? lhs.a_size : rhs.a_size;
    for (size_t i = 0; i < min; ++i) {
        if (*(lhs + i) != *(rhs.array + i)) {
            return *(lhs.array + i) < *(rhs.array + i);
        }
    }
    return lhs.a_size < rhs.v_size;
}

template< class T, std::size_t N >
bool operator>=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    size_t min = lhs.a_size < rhs.a_size ? lhs.a_size : rhs.a_size;
    for (size_t i = 0; i < min; ++i) {
        if (*(lhs + i) != *(rhs.array + i)) {
            return *(lhs.array + i) > *(rhs.array + i);
        }
    }
    return lhs.a_size >= rhs.v_size;
}

template< class T, std::size_t N >
bool operator<=( const my_array<T, N>& lhs, const my_array<T, N>& rhs ){
    size_t min = lhs.a_size < rhs.a_size ? lhs.a_size : rhs.a_size;
    for (size_t i = 0; i < min; ++i) {
        if (*(lhs + i) != *(rhs.array + i)) {
            return *(lhs.array + i) < *(rhs.array + i);
        }
    }
    return lhs.a_size <= rhs.v_size;
}

#endif //MY_VECTOR_MY_ARRAY_H