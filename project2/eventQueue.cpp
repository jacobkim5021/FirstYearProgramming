#include <iostream>

#include "eventQueue.h"

using namespace std;
/*
enum EventType { LOADSTORE, ALU, COMPAREJUMP };

struct Event {
  float     time;     // Simulated time
  EventType type;     // Event type
};
*/
struct Node{
    Event value;
    Node* next;
}*head = NULL;

bool enqueue(const Event* e){
    Node* node = new Node;
    node->value = *e;
    node->next = NULL;
    if(e->time < 0){
        cerr << "Error: negative time." << endl;
        return false;
    }

    if(head == NULL){
        head = node;
        return true;
        cout << "first one gud" << endl;
    }
    else{
        if(head->value.time > node->value.time){
            Node* tempNode2 = head;
            head = node;
            head->next = tempNode2;
            return true;
        }
        else if(head->value.time == node->value.time){
            if(head->next == NULL){
                head->next = node;
                node->next = NULL;
                return true;
            }
            else{
                Node* tempNode3 = head->next;
                Node* tempPrevious = head;
                while(node->value.time == tempNode3->value.time){
                    if(tempNode3->next == NULL){
                        tempNode3->next = node;
                        node->next = NULL;
                        return true;
                    }

                    tempPrevious = tempNode3;
                    tempNode3 = tempNode3->next;

                }
                tempPrevious->next = node;
                node->next = tempNode3;

                return true;
            }
        }
        else{
            Node* previous = head;
            Node* current = head->next;

            if(head->next == NULL){
                head->next = node;
                return true;
            }

            while(current->value.time < node->value.time){
                if(current->next == NULL){
                    current->next = node;
                    node->next = NULL;
                    return true;
                }
                previous = current;
                current = current->next;
            }
            while(node->value.time == current->value.time){
                if(current->next == NULL){
                    current->next = node;
                    node->next = NULL;
                    return true;
                }


                previous = current;
                current = current->next;
            }
            previous->next = node;
            node->next = current;

            return true;
        }

    }
}

const Event* dequeue(){

    if(head == NULL){
        return NULL;
    }
    Event* tempEvent = new Event;
    *tempEvent = head->value;

    Node* tempNode = head;
    head = head->next;
    tempNode->next = NULL;

    return tempEvent;
}

/*
int main(int argc, char* argv[]){


    return 0;
}
*/

