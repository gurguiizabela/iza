#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
public:
    ~Stack(){};
    void push(const T&);
    void pop();
    bool isempty();
    T& top();
private:
    struct node
    {
        T dat;
        node *next;
        node(const T& newData, node *nextNode)
            {
                dat=newData;
                next=nextNode;
            }
    };
    node *topN = 0;
};

template<class T>
void Stack<T>::push(const T& item)
{
    topN = new node(item,topN);
}

template<class T>
void Stack<T>::pop()
{
    if(!isempty())
    {
        topN = topN->next;
    }
}

template<class T>
T& Stack<T>::top()
{
    if(!isempty())
    {
        return topN->dat;
    }
}

template<class T>
bool Stack<T>::isempty()
{
    return topN == 0;
}

template<class T>
class Stiva
{
public:
    ~Stiva(){};;
    bool isempty(){return (vect.size() !=0 );};
    void push(const T& item){vect.push_back(item);};
    const T& top(){return vect.back();};
    void pop(){vect.pop_back();};
private:
    vector<T> vect;
};


int main()
{
    Stack <int> stiva;
    stiva.push(1);
    stiva.push(2);
    stiva.push(3);
    stiva.push(4);
    stiva.push(5);
    stiva.push(6);
    stiva.push(7);
    cout<<stiva.top()<<endl;
    stiva.pop();
    cout<<stiva.top()<<endl;
    //stiva.pop();
    //cout<<stiva.top()<<endl;
    //stiva.pop();
    if(stiva.isempty())
        cout<<"Stiva este goala";

    else
        cout<<"Stiva nu este goala";

    cout<<"\n\n";

    Stiva<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    if(s.isempty())
        cout<<"Stiva nu este goala";
    else
        cout<<"Stiva este goala";
    return 0;

}
