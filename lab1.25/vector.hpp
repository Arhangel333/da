#include <iostream>
#include <cstring> // Для memcpy

template <typename T>
class Vector {
private:
    T* data;        // Указатель на массив элементов
    size_t capacity; // Вместимость вектора
    size_t size;     // Текущее количество элементов в векторе

    // Функция для перевыделения памяти
    void realloc(size_t new_capacity) {
        T* new_data = new T[new_capacity]; // Выделяем новый блок памяти
        if (data) {
            // Копируем старые данные в новый блок
            std::memcpy(new_data, data, size * sizeof(T));
            delete[] data; // Освобождаем старую память
        }
        data = new_data;
        capacity = new_capacity;
    }

public:
    // Конструктор по умолчанию
    Vector() : data(nullptr), capacity(0), size(0) {}

    // Конструктор с заданной вместимостью
    explicit Vector(size_t initial_capacity) : capacity(initial_capacity), size(0) {
        data = new T[capacity];
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Конструктор копирования
    Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
        data = new T[capacity];
        std::memcpy(data, other.data, size * sizeof(T));
    }

    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];
            std::memcpy(data, other.data, size * sizeof(T));
        }
        return *this;
    }

    // Добавление элемента в конец вектора
    void push_back(const T& value) {
        if (size >= capacity) {
            realloc(capacity == 0 ? 1 : capacity * 2); // Увеличиваем вместимость
        }
        data[size++] = value;
    }

    // Удаление последнего элемента
    void pop_back() {
        if (size == 0) {
            std::cerr << "Error: Vector is empty, cannot pop_back." << std::endl;
            return;
        }
        --size;
    }

    // Доступ к элементу по индексу
    T& operator[](size_t index) {
        if (index >= size) {
            std::cerr << "Error: Index out of range." << std::endl;
            // Возвращаем ссылку на последний элемент, чтобы избежать неопределённого поведения
            return data[size - 1];
        }
        return data[index];
    }

    // Получение текущего размера вектора
    size_t get_size() const {
        return size;
    }

    // Получение текущей вместимости вектора
    size_t get_capacity() const {
        return capacity;
    }

    // Вставка элемента по индексу
    void insert(size_t index, const T& value) {
        if (index > size) {
            std::cerr << "Error: Index out of range." << std::endl;
            return;
        }
        if (size >= capacity) {
            realloc(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Удаление элемента по индексу
    void erase(size_t index) {
        if (index >= size) {
            std::cerr << "Error: Index out of range." << std::endl;
            return;
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
};

int main() {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Size: " << vec.get_size() << ", Capacity: " << vec.get_capacity() << std::endl;

    vec.insert(1, 15);
    vec.erase(2);

    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Попытка доступа к несуществующему индексу
    std::cout << "Attempting to access out of range index: ";
    std::cout << vec[10] << std::endl;

    return 0;
}
