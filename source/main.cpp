#include <iostream>
#include <string>
#include <vector>

#include "../include/task1.hpp"
#include "../include/task2.hpp"
#include "../include/task3.hpp"


int main() {
    int task_number;
    std::cout << "Введите номер задачи: ";
    std::cin >> task_number;
    switch (task_number) {
        case 1: {
            using namespace WordManager;

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
            using namespace BookManager;

            std::vector<Book> books = {
                Book {
                    "Лев Толстой",
                    "Война и мир",
                    1869
                },
                Book {
                    "Фёдор Достоевский",
                    "Преступление и наказание",
                    1866
                },
                Book {
                    "Антон Чехов",
                    "Дядя Ваня",
                    1897
                }
            };
            saveToFile("task2.txt", books);

            std::vector<Book> out_books = {};
            loadFromFile("task2.txt", out_books);
            for (Book book : out_books) {
                std::cout << book.Author << " " << book.Title << " " << book.Year << std::endl;
            }
            break;
        }
        case 3: {
            using namespace GroupsManager;

            Groups groups = {
                {
                    "ИУ8-14", 
                    {
                        Student {
                            "Иван Иванов",
                            1,
                            {{"Математика", Good}, {"Физика", Excellent}}
                        },
                        Student {
                            "Петр Петров",
                            1,
                            {{"Математика", Satisfactorily}, {"Физика", Good}}
                        },
                    }
                },
                {
                    "БМТ2-32", 
                    {
                        Student {
                            "Алексей Алексеев",
                            2,
                            {{"Математика", Excellent}, {"Физика", Good}}
                        },
                        Student {
                            "Дмитрий Дмитриев",
                            2,
                            {{"Математика", Good}, {"Физика", Satisfactorily}}
                        },
                    }
                },
                {
                    "МТ10-52", 
                    {
                        Student {
                            "Сергей Сергеев",
                            3,
                            {{"Математика", Excellent}, {"Физика", Excellent}}
                        }
                    }
                }
            };
            saveToFile("task3.txt", groups);
            groups = {};
            loadFromFile("task3.txt", groups);
            saveToFile("task3_after_load.txt", groups);
            break;
        }  
        default: {
            std::cout << "Неверный номер задания" << std::endl;
            break;
        }       
    }
    
    return 0;
}
