#include <string>
#include <map>
#include <vector>


namespace GroupsManager {
    enum Score
    {
        Unsatisfactorily = 2,
        Satisfactorily,
        Good,
        Excellent
    };

    struct Student
    {
        std::string Name;
        int Year;
        std::map<std::string, Score> RecordBook;
    };

    using Groups = std::map<std::string, std::vector<Student>>;

    void saveToFile(const std::string& filename, const Groups& groups);

    void loadFromFile(const std::string& filename, Groups& outGroups);
}