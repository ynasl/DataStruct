#pragma once

template <typename T>
class Stack {
public:

    Stack(); // Конструктор по умолчанию

    Stack(const int capacity); // Конструктор по умолчанию

    Stack(const Stack& stack); // Конструктор копирования

    Stack(Stack&& stack); // Конструктор перемещения

    Stack<T>& operator =(const Stack& stack); // Перегрузка оператора присваивания

    Stack<T>& operator=(Stack&& stack); // Перегрузка оператора присваивания перемещением

    void push(T data); // Метод добавления данных в стек

    T pop(); // Метод удаления последнего элемента из стека

    bool is_empty(); // Проверка на пустоту стека

    bool is_full(); // Проверка на заполненость стека

    T peek();

private:
    T* vector; // Векторное хранение
    int size; // Размер стека (сколько в данный момент элементов)
    int capacity; // Размер стека (сколько возможно всего элементов в стеке)
};

template<typename T>
Stack<T>::Stack() {
    vector = new T[1];
    size = 0;
    capacity = 1;
}

template<typename T>
Stack<T>::Stack(const int capacity) {
    this->capacity = capacity; 
    this->size = 0;
    this->vector = new T[capacity];
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& stack) {
    if (this == &stack) return *this;

    delete[] this->vector;

    this->size = stack.size;
    this->vector = new T[stack.size];
    this->capacity = stack.capacity;

    for (int i = 0; i < stack.size; i++)
        this->vector[i] = stack.vector[i];
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& stack) {

    if (this == &stack) return *this;

    delete[] this->vector;

    this->size = stack.size;
    this->vector = stack.vector;
    this->capacity = stack.capacity;

    stack.vector = nullptr;

    return *this;
}

template<typename T>
Stack<T>::Stack(Stack&& stack) {
    this->size = stack.size;
    this->vector = stack.vector;
    this->capacity = stack.capacity;

    stack.vector = nullptr;
}

template<typename T>
Stack<T>::Stack(const Stack& stack) {

    this->vector = new T[stack.size];
    this->size = stack.size;

    for (int i = 0; i < stack.size; i++)
        this->vector[i] = stack.vector[i];

}

template<typename T>
void Stack<T>::push(T data) {

    if (size + 1 > capacity)
        throw("Выход за пределы стека");

    this->vector[size++] = data;
}

template<typename T>
T Stack<T>::pop() {

    if (size - 1 < 0)
        throw("Выход за пределы стека");

    return vector[size-- - 1];
}

template<typename T>
T Stack<T>::peek() {
    return vector[size - 1];
}

template<typename T>
bool Stack<T>::is_empty() {
    return (size == 0);
}

template<typename T>
bool Stack<T>::is_full() {
    return (size == capacity);
}
