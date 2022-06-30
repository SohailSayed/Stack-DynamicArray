class DynamicStack {
public:
    typedef int StackItem;
    static const StackItem EMPTY_STACK;

private:

    // MEMBER VARIABLES
    StackItem* items_;
    int capacity_;
    int size_;
    int init_capacity_;

    // Copy constructor
    DynamicStack(const DynamicStack& other) {}

    // Assignment operator
    DynamicStack operator=(const DynamicStack& other) {}


public:
    DynamicStack();

    DynamicStack(unsigned int capacity);

    ~DynamicStack();

    int size() const;

    bool empty() const;

    void print() const;

    StackItem peek() const;

    void push(StackItem value);

    StackItem pop();
