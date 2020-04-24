#pragma once
#include <iostream>
// list base element type
class NodeList {				// node-based list
private:
	// Doubly Linked-list
	struct Node
	{
		char elem;
		Node* prev;
		Node* next;
	};
public:
	class Iterator {				// an iterator for the list
	public:
		char& operator*()
		{
			return v->elem;
		}			// reference to the element
		bool operator==(const Iterator& p) const
		{
			return v == p.v;
		}// compare positions
		bool operator!=(const Iterator& p) const
		{
			return v != p.v;
		}
		Iterator& operator++()
		{
			v = v->next;
			return *this;
		}// move to next position
		Iterator& operator--()
		{
			v = v->prev;
			return *this;
		}// move to previous position
		friend class NodeList;			// give NodeList access
	private:
		Node* v;					// pointer to the node
		Iterator(Node* u)
		{
			v = u;
		}			// create from node
	};
public:
	NodeList();					// default constructor
	int size() const;				// list size
	bool empty() const;				// is the list empty?
	Iterator begin() const
	{
		return Iterator(header->next);
	}// beginning position
	Iterator end() const
	{
		return Iterator(trailer);
	}// (just beyond) last position
	void insertFront(const char& e);		// insert at front
	void insertBack(const char& e);		// insert at rear
	void insert(const Iterator& p, const char& e); // insert e before p
	void eraseFront();				// remove first
	void eraseBack();				// remove last
	void erase(const Iterator& p);
	int indexOf(const Iterator &p)
	{
		int index = -1;
		for (auto i = begin(); i != p; ++i)
		{
			index += 1;
		}
		if (begin() == p)
		{
			return 0;
		}
		return index;
	}
	Iterator atIndex(int i)
	{
		Node* temp = header;
		int count = 0;
		while (temp->next != nullptr && count <= i)
		{
			temp = temp->next;
			count++;
		}
		if (temp->next == nullptr)
		{
			std::cout << "Index out of bounds!" << std::endl;
		}
		return Iterator(temp);
	}
	// remove p
	// housekeeping functions omitted...
private:					// data members
	int     n;					// number of items
	Node*   header;				// head-of-list sentinel
	Node*   trailer;				// tail-of-list sentinel
};

NodeList::NodeList() {			// constructor
	n = 0;					// initially empty
	header = new Node;				// create sentinels
	trailer = new Node;
	header->next = trailer;			// have them point to each other
	trailer->prev = header;
}

int NodeList::size() const 			// list size
{
	return n;
}

bool NodeList::empty() const 			// is the list empty?
{
	return (n == 0);
}

// insert e before p
void NodeList::insert(const NodeList::Iterator& p, const char& e) {
	Node* w = p.v;				// p's node
	Node* u = w->prev;				// p's predecessor
	Node* v = new Node;				// new node to insert
	v->elem = e;
	v->next = w;  w->prev = v;			// link in v before w
	v->prev = u;  u->next = v;			// link in v after u
	n++;
}

void NodeList::insertFront(const char& e)	// insert at front
{
	insert(begin(), e);
}

void NodeList::insertBack(const char& e)	// insert at rear
{
	insert(end(), e);
}

void NodeList::erase(const Iterator& p) {	// remove p
	Node* v = p.v;				// node to remove
	Node* w = v->next;				// successor
	Node* u = v->prev;				// predecessor
	u->next = w;  w->prev = u;			// unlink p
	delete v;					// delete this node
	n--;					// one fewer element
}

void NodeList::eraseFront()			// remove first
{
	erase(begin());
}

void NodeList::eraseBack()			// remove last
{
	erase(--end());
}
