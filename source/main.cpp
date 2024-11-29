#include <iostream>
#include <string>
#include <vector>

#include "../include/task1.hpp"



int main() {
    int task_number;
    std::cout << "Введите номер задачи: ";
    std::cin >> task_number;
    switch (task_number) {
        case 1: {
            std::vector<std::string> words = {
                "hello",
                "okay",
                "bye",
                "bye",
                "bye",
            };
            saveToFile("task1.txt", words);

            std::vector<std::string> out_words = {};
            loadFromFile("task1.txt", out_words);
            for (std::string word : out_words) {
                std::cout << word << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "not implemented" << std::endl;
            break;
        }  
        default: {
            std::cout << "Неверный номер задания" << std::endl;
            break;
        }       
    }
    
    return 0;
}
