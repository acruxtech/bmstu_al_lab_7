#include <string>
#include <vector>
#include <fstream>
#include <iostream>


void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::fstream file;
    file.open("assets/" + filename, std::ios::out);
    if (file.is_open()) {
        for (std::string word : data) {
            file << word << " ";
        }
    }
    else {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    file.close();
};


void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {    
    std::fstream file;
    file.open("assets/" + filename, std::ios::in);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            outData.push_back(word);
        }
    }
    else {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    file.close();
}
