#include <iostream>
#include <vector>
#include <string>

// Функция для получения символа на определенной позиции в строке
char getChar(const std::string &key, int pos)
{
    if (pos < key.length())
    {
        return key[pos];
    }
    return 0; // Если позиция выходит за пределы строки
}

// Функция для поразрядной сортировки
void radixSort(std::vector < std::pair < std::string, std::string>> &data)
{
    const int maxLen = 9; // Максимальная длина ключа (A 999 BC)
    for (int pos = maxLen - 1; pos >= 0; --pos)
    {
        std::vector < std::pair < std::string, std::string>> output(data.size());
        std::vector<int> count(256, 0); // 256 возможных символов

        // Подсчет количества каждого символа на текущей позиции
        for (const auto &pair : data)
        {
            char ch = getChar(pair.first, pos);
            count[ch]++;
        }

        // Преобразование count для хранения позиций
        for (int i = 1; i < 256; ++i)
        {
            count[i] += count[i - 1];
        }

        // Построение выходного массива
        for (int i = data.size() - 1; i >= 0; --i)
        {
            char ch = getChar(data[i].first, pos);
            output[count[ch] - 1] = data[i];
            count[ch]--;
        }

        // Копирование отсортированного массива обратно в data
        for (int i = 0; i < data.size(); ++i)
        {
            data[i] = output[i];
        }
    }
}

int main()
{
    std::vector < std::pair < std::string, std::string>> data;
    std::string key, value;
    printf("One");
    while((std::getline(std::cin, key)) || (std::getline(std::cin, value)))
    {
        
        data.emplace_back(key, value);
        std::cout << "Добавлено: " << data.back().first << " -> " << data.back().second << '\n';
    }
    // Сортировка
    radixSort(data);

    // Вывод отсортированных данных
    for (const auto &pair : data)
    {
        std::cout<<pair.first << '\t' << pair.second << '\n';
    }

    return 0;
}