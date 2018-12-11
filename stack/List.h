#include "underflow.h"
#include "Node.h"
class List
{
public:
    List();
    List( List const &list );
    ~List();
    int retrieve();
    void push_front(int);
    int front() const;
    int pop_front();
    Node *head() const;
    int count( int ) const;
    int erase( int );
    bool empty() const;
    int size() const;

private:
    List &operator = ( List );
    Node *list_head;
};
List::List():
list_head( nullptr ){
    // empty constructor
}
List::List( List const &list ):
list_head( nullptr )
{
    if (list.empty())
    {
        return;
    }
    push_front( list.front() );
    for ( 
        Node *original = list.head(), *copy = head();
        original != nullptr;
        original = original->next(), copy = copy->next()
        )
    {
        copy->next_node = new Node( original->retrieve(), nullptr );
    }
}
List::~List()
{
    while( !empty() )
    {
        pop_front();
    }
}

bool List::empty() const{
    if ( list_head == nullptr ) {
        return true;
    } else
    {    
        return false;
    }
}
Node *List::head() const {
    return list_head;
}
int List::front() const {
    if ( empty() )
    {
        throw underflow();
    }

    return head()->retrieve();
} 
void List::push_front( int element)
{
    list_head = new Node( element, list_head );
}
int List::pop_front(){
    if (empty())
    {
        throw underflow();
    }

    Node *p = head();
    int e = front();
    list_head = p->next();
    delete p;
    return e;
}
int List::count(int element) const{
    int node_count = 0;

    for ( Node *ptr = head(); ptr != nullptr; ptr = ptr->next() )
    {
        if ( ptr->retrieve() != element)
        {
            ++node_count;
        }
    }

    return node_count;
}
int List::erase( int element )
{
    int node_count = 0;
    while(  element == head()->retrieve() ){
        pop_front();
        ++node_count;
    }
    for ( Node *ptr = head(); ptr != nullptr; ptr = ptr->next() )
    {
        while ( ptr->next() && element == ptr->next()->retrieve())
        {
            ptr->next_node = ptr->next()->next();
            free(ptr->next());
            ++node_count;
        }
    }

    return node_count;
}
