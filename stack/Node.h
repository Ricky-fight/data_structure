class Node
{
    friend class List;
private:
    int element;
    Node *next_node;
public:
    Node( int = 0, Node * = nullptr);


    int retrieve() const;
    Node *next() const;   
};
Node::Node( int e,Node *next):
element( e ),
next_node( next ){
    // empty constructor
}
int Node::retrieve() const{
    return element;
}
Node *Node::next() const{
    return next_node;
}
