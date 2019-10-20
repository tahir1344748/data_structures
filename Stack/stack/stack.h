class stack
{
private:
    int size;
    int top = - 1;
    int *array;
public:
    stack(int size);
    void push(int);
    int pop();
    bool isEmpty();
    bool isfull();
    int top_value();
    int bottom_value();
    int middle_value();
    void remove(int);  //takes value to be deleted
    void display();
    void del(int);  //takes index
    void head();
    void tail();
    bool ispresent(int);
};