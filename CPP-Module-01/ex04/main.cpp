/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:43:19 by pchung            #+#    #+#             */
/*   Updated: 2025/05/02 22:49:01 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceAll(std::string& content, const std::string& s1, const std::string& s2) {
    std::size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: string1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line)) {
        content += line;
        if (!inputFile.eof())
            content += '\n';
    }
    inputFile.close();

    replaceAll(content, s1, s2);

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create output file: " << outputFilename << std::endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();

    std::cout << "Successfully created: " << outputFilename << std::endl;
    return 0;
}

// echo "Hello World! This is a test file." > hello.txt
// ./replace hello.txt "World" "C++"