#include "common/node.hpp"
#include "grammar/parser.hpp"
#include "grammar/lexer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
    // if (argc != 3) {
    //     std::cerr << "Invalid number of args" << std::endl;
    //     std::cerr << "Usage: " << argv[0] << " <path_to_source>" << " build/<destination_file-name>" << std::endl;
    //     return 1;
    // } 
    if (argc != 2 ){
        std::cerr << "Expected 2 args but got " + std::to_string(argc) + " were given" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <path_to_source> " << std::endl;
        return 1; 
    }
    std::string sourceName = argv[1];
    // std::string destName = argv[2];
    std::cout << "Source file path: " << sourceName << std::endl;
    // std::cout << "Destination file path: " << destName << std::endl;
    std::ifstream src_file(sourceName);
    if (!src_file.is_open()) {
        std::cerr << "File don't open" << std::endl;
        return 1;
    }
    FILE* file_ptr = std::fopen(sourceName.c_str(), "r");
    yyin = file_ptr; 

    Node* root = nullptr;
    yyparse((void **)&root);

    if( root == nullptr ){
        std::cerr << "Root is null";
        return 1; 
    }

    std::cout << root->print();

    return 0;
}