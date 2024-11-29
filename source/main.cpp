#include <iostream>
#include <string>
#include <vector>

#include "../include/task1.hpp"
#include "../include/task2.hpp"



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
            WordManager::saveToFile("task1.txt", words);

            std::vector<std::string> out_words = {};
            WordManager::loadFromFile("task1.txt", out_words);
            for (std::string word : out_words) {
                std::cout << word << std::endl;
            }
            break;
        }
        case 2: {
            std::vector<BookManager::Book> books = {
                BookManager::Book {
                    "Лев Толстой",
                    "Война и мир",
                    1869
                },
                BookManager::Book {
                    "Фёдор Достоевский",
                    "Преступление и наказание",
                    1866
                },
                BookManager::Book {
                    "Антон Чехов",
                    "Дядя Ваня",
                    1897
                }
            };
            BookManager::saveToFile("task2.txt", books);

            std::vector<BookManager::Book> out_books = {};
            loadFromFile("task2.txt", out_books);
            for (BookManager::Book book : out_books) {
                std::cout << book.Author << " " << book.Title << " " << book.Year << std::endl;
            }
            break;
        }
        case 3: {
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
