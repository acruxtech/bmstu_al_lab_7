#include <string>
#include <vector>


namespace BookManager {
    struct Book
    {
        std::string Author;
        std::string Title;
        int Year;
    };

    void saveToFile(const std::string& filename, const std::vector<Book>& data);

    void loadFromFile(const std::string& filename, std::vector<Book>& outData);
}
