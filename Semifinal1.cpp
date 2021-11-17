#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class SinglyLinkedList {
  public:
    Node * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }


  Node * nodeExists(int k) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }

  void InsertNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Insert another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Inserted" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }

  }
 
  void DeleteNode(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }

  }
 
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};

int main() {

  SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Delete Node" << endl;    
    cout << "3. Print Nodes" << endl;
    cout << "4. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Insert Node \nEnter key & data of the Node to be inserted" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.InsertNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
   
    case 2:

      cout << "Delete Node - \nEnter Node to be deleted: " << endl;
      cin >> k1;
      s.DeleteNode(k1);

      break;
    
     case 3:
      s.printList();

      break;
    
    case 4:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}