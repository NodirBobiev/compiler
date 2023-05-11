#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node{
public:
      std::string type;
      std::string value;
      std::vector<Node*> children;
      int size = 0;

      Node(const std::string&,  const std::string&);

      Node(const std::string&);

      ~Node();

      Node* add(Node*);

      std::string print(int = 0);

};


std::string rep(std::string, int);

Node* mNode(std::string, std::string);

Node* mNode(std::string);

Node* mpNode(std::string, std::string, int, ...);

Node* mpNode(std::string, int, ...);


#endif // NODE_HPP
