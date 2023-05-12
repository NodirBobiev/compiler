#include "common/node.hpp"
#include "grammar/parser.hpp"
#include "grammar/lexer.hpp"
#include "semantical_analyzer/analyzer.hpp"
#include "generator/generator.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Expected 4 arguments but got " + std::to_string(argc) + " were given" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <source_file_name> " << " <dest_file_name> " <<  " <classname> " << std::endl;
        // std::cerr << "Usage: " << argv[0] << " <source_file_name> " << " <dest_file_name> " <<  " <classname> " << " <semantic_flag> " << std::endl;
        
        return 1;
    } 
    // if (argc != 2 ){
    //     std::cerr << "Expected 2 args but got " + std::to_string(argc) + " were given" << std::endl;
    //     std::cerr << "Usage: " << argv[0] << " <path_to_source> " << std::endl;
    //     return 1; 
    // }
    std::string sourceFile = "tests/" + std::string(argv[1]);
    std::string destFile = "generateds/" + std::string(argv[2]);
    std::string className = "outs/" + std::string(argv[3]);
    // std::string semanticFlag = argv[4];

    std::cout << "Source file path: " << sourceFile << std::endl;
    std::cout << "Destination file path: " << destFile << std::endl;
    std::cout << "ClassName: " << className << std::endl;

    std::ifstream src_file(sourceFile);
    if (!src_file.is_open()) {
        std::cerr << "File don't open" << std::endl;
        return 1;
    }
    FILE* file_ptr = std::fopen(sourceFile.c_str(), "r");
    yyin = file_ptr; 

    Node* root = nullptr;
    yyparse((void **)&root);

    if( root == nullptr ){
        std::cerr << "Root is null";
        return 1; 
    }

    std::cout << root->print();
    
    // if( semanticFlag == "t"){
    //     auto semantic_analyzer = new Analyzer();
    //     semantic_analyzer->analyze(root);
    // }

    auto semantic_analyzer = new Analyzer();
    semantic_analyzer->analyze(root);
    
    auto generator = new Generator(className);

    auto generatedOutput = generator->generate(root);

    
    std::ofstream outFile(destFile);

    outFile << generatedOutput << std::endl;

    outFile.close();

    return 0;   
}