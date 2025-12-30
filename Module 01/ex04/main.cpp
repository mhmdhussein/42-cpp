#include <iostream>
#include <fstream>
#include <string>

static std::string replace_all(const std::string &input, const std::string &s1, const std::string &s2) {
    if (s1.empty()) return input;
    std::string out;
    out.reserve(input.size());
    std::string::size_type i = 0;
    while (i < input.size()) {
        std::string::size_type pos = input.find(s1, i);
        if (pos == std::string::npos) {
            out.append(input, i, input.size() - i);
            break;
        }
        out.append(input, i, pos - i);
        out.append(s2);
        i = pos + s1.size();
    }
    return out;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << "./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: cannot open input file" << std::endl;
        return 1;
    }
    std::string content;
    std::string line;
    while (std::getline(in, line)) {
        content += line;
        if (!in.eof()) content += "\n";
    }
    in.close();

    std::string replaced = replace_all(content, s1, s2);

    std::ofstream out((filename + ".replace").c_str());
    if (!out) {
        std::cerr << "Error: cannot open output file" << std::endl;
        return 1;
    }
    out << replaced;
    out.close();
    return 0;
}
