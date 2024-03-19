#include <iostream>

struct Node {
	Node() {}
	Node(int e, Node* n) : elem(e), next(n) {}
	int elem = 0;
	Node* next = nullptr;
	// you need to implement begin and end functions
	// both functions returns iterator
	NodeIterator begin() noexcept { return NodeIterator(); }
	NodeIterator end() noexcept { return NodeIterator(nullptr);}
};

// NodeIterator begin(Node* n) noexcept{ return NodeIterator(n);}

void add(Node& n, int x) {
	n.next = new Node(x, n.next);
}

struct NodeIterator {
	NodeIterator() {};
	NodeIterator(Node* x) : p(x) {}
	Node* p = nullptr;
	// you need to implement operations
	// == ( and !=)
	bool operator==(const NodeIterator& n){ return this->p==n.p;}
	bool operator!=(const NodeIterator& n){ return this->p!=n.p;}
	// *
	int operator*(){return this->p->elem;}
	// ++
	void operator++(){ this->p=this->p->next;}


};


int main() {
	Node head;
	add(head, 1);
	add(head, 2);
	add(head, 3);
	add(head, 4);
	add(head, 5);

	for (Node* p = head.next; p != nullptr; p = p->next) {
		std::cout << p->elem << " ";
	}
	std::cout << std::endl;

	for (int x : head) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (int& x : head) {
		x = 7;
	}
	for (const int& x : head) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}
