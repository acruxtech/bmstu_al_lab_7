#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/task2.hpp"


namespace BookManager {
    std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }


    void saveToFile(const std::string& filename, const std::vector<Book>& data) {
        std::fstream file;
        file.open("../assets/" + filename, std::ios::out);
        if (file.is_open()) {
            for (Book book : data) {
                file << book.Author << ";" << book.Title << ";" << book.Year << std::endl;
            }
        }
        else {
            std::cout << "Не удалось открыть файл" << std::endl;
        }
        file.close();
    }

    void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
        std::fstream file;
        file.open("../assets/" + filename, std::ios::in);
        if (file.is_open()) {
            std::string book_line;
            while (std::getline(file, book_line)) {  
                std::vector<std::string> book_info = split(book_line, ";");
                outData.push_back(
                    Book {
                        book_info[0],
                        book_info[1],
                        std::stoi(book_info[2]),
                    }
                );
            }
        }
        else {
            std::cout << "Не удалось открыть файл" << std::endl;
        }
        file.close();
    }
}

