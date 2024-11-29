#include <string>
#include <vector>


void saveToFile(const std::string& filename, const std::vector<std::string>& data);

void loadFromFile(const std::string& filename, std::vector<std::string>& outData);
