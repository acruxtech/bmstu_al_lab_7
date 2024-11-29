#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/task3.hpp"


namespace GroupsManager {
    Score stringToScore(int score_value) {
        switch (score_value) {
            case 2:
                return Unsatisfactorily;
            case 3:
                return Satisfactorily;
            case 4:
                return Good;
            case 5:
                return Excellent;
        }
        throw std::invalid_argument("Недопустимое значение оценки");
    }

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

    void saveToFile(const std::string& filename, const Groups& groups) {
        std::fstream file;
        file.open("../assets/" + filename, std::ios::out);
        if (file.is_open()) {
            for (std::pair<std::string, std::vector<Student>> group : groups) {
                file << group.first << "  ";
                for (auto student_it = group.second.begin(); student_it != group.second.end(); ++student_it) {
                    file << student_it->Name << ";" << student_it->Year << ";";
                    for (auto it = student_it->RecordBook.begin(); it != student_it->RecordBook.end(); ++it) {
                        file << it->first << ":" << it->second;
                        if (std::next(it) != student_it->RecordBook.end()) {
                            file << ";";
                        }
                    }
                    if (std::next(student_it) != group.second.end()) {
                        file << "#";
                    }
                }
                file << std::endl;
            }
        }
        else {
            std::cout << "Не удалось открыть файл" << std::endl;
        }
        file.close();
    }

    void loadFromFile(const std::string& filename, Groups& outGroups) {
        std::fstream file;
        file.open("../assets/" + filename, std::ios::in);
        if (file.is_open()) {
            std::string group_line;
            while (std::getline(file, group_line)) {
                std::vector<std::string> group_info = split(group_line, "  ");
                std::string group_name = group_info[0];
                std::vector<std::string> students = split(group_info[1], "#");
                std::vector<Student> all_students = {};
                for (std::string student : students) {
                    Student student_from_file;
                    std::vector<std::string> student_info = split(student, ";");
                    student_from_file.Name = student_info[0];
                    student_from_file.Year = std::stoi(student_info[1]);
                    for (int i = 2; i < student_info.size(); ++i) {
                        std::vector<std::string> record = split(student_info[i], ":");
                        student_from_file.RecordBook[record[0]] = stringToScore(std::stoi(record[1]));
                    }
                    all_students.push_back(student_from_file);
                }
                outGroups[group_name] = all_students; 
            }
        }
        else {
            std::cout << "Не удалось открыть файл" << std::endl;
        }
        file.close();
    }
}