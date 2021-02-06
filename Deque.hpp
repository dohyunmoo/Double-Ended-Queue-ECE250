#include <iostream>

#include "Linkedlist.hpp"

class Deque {
private:
	Linkedlist* init_head = nullptr;
	Linkedlist* init_tail = nullptr;
	unsigned int size = 0;

public:
	void push_front(std::string url_name, std::string url) {
		Linkedlist* head = new Linkedlist();
		head->URL_name = url_name;
		head->URL = url;
		head->next = init_head;
		if (init_head == nullptr) {
			init_tail = head;
		}
		else {
			init_head->previous = head;
		}

		init_head = head;

		head = nullptr;

		size++;

		std::cout << "success" << std::endl;
	}

	void push_back(std::string url_name, std::string url) {
		Linkedlist* tail = new Linkedlist();
		tail->URL_name = url_name;
		tail->URL = url;
		tail->previous = init_tail;
		if (init_tail == nullptr) {
			init_head = tail;
		}
		else {
			init_tail->next = tail;
		}

		init_tail = tail;

		tail = nullptr;

		size++;

		std::cout << "success" << std::endl;
	}

	void pop_front() {
		if (size == 0) {
			std::cout << "failure" << std::endl;
		}
		else {
			Linkedlist* temp = init_head;
			init_head = init_head->next;
			delete temp;
			temp = nullptr;

			std::cout << "success" << std::endl;
			size--;
		}
	}

	void pop_back() {
		if (size == 0) {
			std::cout << "failure" << std::endl;
		}
		else {
			Linkedlist* temp = init_tail;
			init_tail = init_tail->previous;
			delete temp;
			temp = nullptr;

			std::cout << "success" << std::endl;
			size--;
		}
	}

	void return_size() {
		std::cout << "size is " << size << std::endl;
	}

	void front() {
		if (size == 0) {
			std::cout << "failure" << std::endl;
		}
		else {
			std::cout << "front is " << init_head->URL_name << " " << init_head->URL << std::endl;
		}
	}

	void back() {
		if (size == 0) {
			std::cout << "failure" << std::endl;
		}
		else {
			std::cout << "back is " << init_tail->URL_name << " " << init_tail->URL << std::endl;
		}
	}

	void empty() {
		if (size == 0) {
			std::cout << "empty 1" << std::endl;
		}
		else {
			std::cout << "empty 0" << std::endl;
		}
	}

	void clear() {
		Linkedlist* temp;
		while (init_head != nullptr) {
			temp = init_head;
			init_head = init_head->next;
			delete temp;
			temp = nullptr;
		}

		init_tail = nullptr;

		size = 0;

		std::cout << "success" << std::endl;
	}

	void find(std::string url_name) {
		Linkedlist* temp = init_head;
		bool check = false;
		while (temp != nullptr) {
			int j = 0;
			while (j < temp->URL_name.length() && j < url_name.length() && std::tolower(temp->URL_name[j]) == std::tolower(url_name[j])) {
				j++;
			}
			if (j == temp->URL_name.length() && j == url_name.length()) {
				check = true;
				break;
			}
			temp = temp->next;
		}

		if (check) {
			std::cout << "found " << temp->URL_name << " " << temp->URL << std::endl;
		}
		else {
			std::cout << "not found " << url_name << std::endl;
		}

		temp = nullptr;
	}

	void print() {
		Linkedlist* temp = init_tail;
		while (temp != nullptr) {
			std::cout << temp->URL_name << " " << temp->URL << std::endl;
			temp = temp->previous;
		}

		temp = nullptr;
	}

	~Deque() {
		Linkedlist* temp;
		while (init_head != nullptr) {
			temp = init_head;
			init_head = init_head->next;
			delete temp;
			temp = nullptr;
		}

		init_tail = nullptr;
	}
};