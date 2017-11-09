#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>
#include <stddef.h>

using namespace std;

template <typename T>
class SLinkedList;

template <typename T>
class SNode {
private:
	T elem;
	SNode* next;
	friend class SLinkedList<T>;
};

template <typename T>
class SLinkedList {
public:
	SLinkedList(): head(NULL) { }

	bool empty() const{ return head == NULL; }

	const T& front() const{ return head->elem; }

	~SLinkedList(){ while (!empty()) removeFront(); }

	void addFront(const T& e) {                  // add to front of list
    		SNode<T>* v = new SNode<T>;          // create new node
		v->elem = e;                             // store data
    		v->next = head;                      // head now follows v
    		head = v;                            // v is now the head
  	}

	void removeFront() {             	         // remove front item
    		SNode<T>* old = head;                // save current head
    		head = old->next;                    // skip over old head
    		delete old;                          // delete the old head
  	}

	void print() {
    		SNode<T>* v = head;
    		while (v != NULL){
    			cout << v->elem << " ";
    			v = v->next;
   		}
   		cout << endl;
  	}

	SLinkedList(const SLinkedList & l) {
		if (l.head == NULL)
			head = NULL;
		else{
			head = new SNode<T>;
			//head->elem = l.head->elem;
			SNode<T>* myCursor = head, * theirCursor = l.head;

			if (l.empty())
				cout << "the other list is empty!" << endl;


			while(theirCursor != NULL){
				cout << "copying " << theirCursor->elem << endl;
				myCursor->elem = theirCursor->elem;
				if (theirCursor->next != NULL){
					myCursor->next = new SNode<T>;
					myCursor = myCursor->next;
				}
				else
					myCursor->next = NULL;

				//cout << "head->elem is " << head->elem << endl;
                                //cout << "myCursor->elem is " << myCursor->elem << endl;

				theirCursor = theirCursor->next;
			}

		}
	}

private:
	SNode<T>* head;
};

#endif // SLINKEDLIST_H
