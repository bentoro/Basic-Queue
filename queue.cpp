#include "queue.h"
#include <string>
#include <iostream>

using namespace std; 

Queue::Queue(){ // Constructs a new empty queue.
	//set the size and the pointers to null and 0
	current_size =0;
	back_p = NULL;
	front_p = NULL;
}
Queue::Queue( const Queue& q ){ // Copy constructor.
	//current is the pointer to back
	node *current = q.back_p;
	//create new node and point to NULl
	node *h = new node(current->data,NULL);
	back_p = h;
	current_size=q.current_size;
	current = current->next;
	//if the current node is not NULL
	while(current !=NULL){
		h = h->next = new node(current->data,NULL);
		current = current->next;
	}
	//set front_p to head
	front_p= h;
}
Queue::~Queue(){ // Destructor.
	node *bk = back_p;
	node *prev;
	node *fr = front_p;
	while (bk != fr){
		prev = bk;
		bk = bk->next;
		delete prev;
	}
		delete fr;
	}
void Queue::enqueue( int item ){ // Enqueues <item>.
	node *n = new node(item,back_p);
	if (current_size == 0){
	    front_p = n;
	}
	back_p = n;
	current_size++;
}

int Queue::dequeue(){  // Dequeues the front item.
	node *n = back_p;
	node *prev;
	int temp = 0;
	while (n != front_p){
		prev = n;
		n = n->next;
	} if (current_size == 1){
		temp = front_p->data;
		back_p = front_p;
		front_p->next = back_p;
		current_size--;
	}else if(current_size == 0){
		cout<<"The list is empty."<< endl;
	} else {
		temp = front_p->data;
		front_p = prev;
		delete n;
		current_size--;
	}
		return temp;
	}

int Queue::front(){  // Returns the front item without dequeuing it.
	return (front_p->data);
}

bool Queue::empty(){  // Returns true iff the queue contains no items.
	return (current_size==0);
}

int Queue::size(){  // Returns the current number of items in the queue.
	return current_size;
}

// If <item> occurs in the queue more 
// than once, remove all occurrences of <item> except the first. 
// Return the number of elements removed.
int Queue::makeUnique(int item){
	//if the list is empty
	if (current_size==0){
		front_p->next = back_p;
	}
	//Initilize values
	node *n = back_p;
	int count =0;
	int pos = current_size;

	//count amount of duplicates
	while (pos != 0){
		if(n->data == item){
			count++;
		}
		pos--;
		n=n->next;
	}

	//reset values
	n = back_p;
	int tp = count;
	pos = current_size;
	
	//if back_p is equal to item
	if (n->data == item){
		back_p = back_p->next;
		cout<<"delete"<<endl;
		//delete current head
		delete n;
		n=back_p;
		count--;
		current_size--;
	//if the count is less than or equal to 1 return 0
	} else if (count<=1){
		return 0;
	} else{
	//while the list isnt empty
		while(pos != 0){
			if(n->next->data == item){
			node *temp= n->next;
				if( count == 1){
					return tp-1;
				} else{
					n->next = n->next->next;
					current_size--;
					count--;
					delete temp;
				}
			} else {
				n=n->next;
			}
			pos--;
		}// end of while
	}// end of else
	return 0;
	}
