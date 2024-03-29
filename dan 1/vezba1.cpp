#include <iostream>

using NodeIterator = struct NodeIterator;
using Node = struct Node;

struct Node
{
	Node() {}
	Node(int e, Node *n) : elem(e), next(n) {}
	int elem = 0;
	Node *next = nullptr;
	NodeIterator begin();
	NodeIterator end();
};

void add(Node &n, int x)
{
	n.next = new Node(x, n.next);
}

struct NodeIterator
{
	NodeIterator(){};
	NodeIterator(Node *x) : p(x) {}
	Node *p = nullptr;

	bool operator==(const NodeIterator &n) const { return this->p == n.p; }
	bool operator!=(const NodeIterator &n) const { return this->p != n.p; }

	int &operator*() { return p->elem; }
	const int& operator*() const { return p->elem; }

	NodeIterator &operator++()
	{
		this->p = this->p->next;
		return *this;
	}
};

NodeIterator Node::begin() { return NodeIterator(this->next); }
NodeIterator Node::end() { return NodeIterator(); }

int main()
{
	Node head;
	add(head, 1);
	add(head, 2);
	add(head, 3);
	add(head, 4);
	add(head, 5);

	for (Node *p = head.next; p != nullptr; p = p->next)
	{
		std::cout << p->elem << " ";
	}
	std::cout << std::endl;

	for (int x : head)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (int &x : head)
	{
		x = 7;
	}
	for (const int &x : head)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}
