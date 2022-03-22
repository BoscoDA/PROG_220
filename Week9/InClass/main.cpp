#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }

    Node *add(Node *next)
    {
        this->next = next;
        return this->next;
    }
};

struct LinkedList
{
    // ** memory handle, never lose the original reference
    static void print_list(Node **head)
    {
        Node *temp = *head;

        while (temp != nullptr)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }

    static void delete_list(Node *head)
    {
        while (head != nullptr)
        {
            Node *tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};

struct A
{
    size_t length;
    int *data;

    A(size_t length)
    {
        std::cout << "Constructed" << std::endl;
        this->length = length;
        data = new int[length];
    }

    // static life = length og program
    // local lifecycle = length of the function
    // dynamic lifecylce = which is all of the heap memory
    ~A()
    {
        std::cout << "Deleted" << std::endl;
        delete[] data;
    }
};

int main()
{
    /* Node *head = new Node(1);

    Node *tail = head->add(new Node(2))->add(new Node(3))->add(new Node(4));

    LinkedList::print_list(&head);
    LinkedList::delete_list(head); */

    A *a = new A(10);
    // do studd with a
    delete a;
}
