#include <iostream>
#include <string>

#include "Deque.hpp"

int main()
{
    std::string line;
    Deque deque;

    while (!std::cin.eof()) {

        std::getline(std::cin, line);

        if (line == "exit") {
            break;
        }

        int divider = line.find(" ");
        std::string command = line.substr(0, divider);
        std::string content = line.substr(divider + 1);

        if (command == "push_front") {
            int divider2 = content.find("\"", 2);
            std::string url_name = content.substr(1, divider2 - 1);

            std::string url = content.substr(divider2 + 3, content.length() - divider2 - 4);

            deque.push_front(url_name, url);
        }
        else if (command == "push_back") {
            int divider2 = content.find("\"", 2);
            std::string url_name = content.substr(1, divider2 - 1);

            std::string url = content.substr(divider2 + 3, content.length() - divider2 - 4);

            deque.push_back(url_name, url);
        }
        else if (command == "pop_front") {
            deque.pop_front();
        }
        else if (command == "pop_back") {
            deque.pop_back();
        }
        else if (command == "size") {
            deque.return_size();
        }
        else if (command == "front") {
            deque.front();
        }
        else if (command == "back") {
            deque.back();
        }
        else if (command == "empty") {
            deque.empty();
        }
        else if (command == "clear") {
            deque.clear();
        }
        else if (command == "find") {
            int divider2 = content.find("\"", 2);
            std::string url_name = content.substr(1, divider2 - 1);
            deque.find(url_name);
        }
        else if (command == "print") {
            deque.print();
        }
    }
    return 0;
}
