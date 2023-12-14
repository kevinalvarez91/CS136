#include <iostream>
#include <stack>
using namespace std;
//last element that is put in is the first element that comes out

class Employee{
public:
int days;
Employee(int days)
{
    cout << "Constructed called " << days << endl;
    this->days=days;
}

Employee(const Employee &employee)
{
    cout << "Copy constructed called " << employee.days;
    cout << endl;
    this->days = employee.days;

}

~Employee()
{
    cout << "Destructor called " << days << endl;
}


};



int main ()
{
stack<int> numbers;

cout << "size: " << numbers.size() << endl;

if (numbers.empty())
{
    cout << "Stack is empty " << endl;
}

numbers.push(8);

cout << "size: " << numbers.size() << endl;

if (!numbers.empty())
{
    cout << "Stack is not empty " << endl;
}

cout << "top: " << numbers.top()<< endl;

numbers.push(9);
numbers.push(5);
cout << endl;
cout << "top: " << numbers.top()<<endl;
cout << "size " << numbers.size()<<endl;

int popped_value = numbers.top();

numbers.pop();
cout << "top: " << numbers.top()<< endl;
cout << "size " << numbers.size() << endl;

cout << "popped_value: " << popped_value << endl;



stack<int> other_stack;

other_stack.push(4);
cout << "other_stack size: " << other_stack.size() << endl;

other_stack.swap(numbers);
cout << endl << "other stack size: " << other_stack.size();
cout << endl;
cout << "numbers size: " << numbers.size() << endl;


stack<Employee> Employee_stack;
//Employee joe(10);
//this does call a copy constructor
//Employee_stack.push(joe);
//emplace does not call a copy constructor
Employee_stack.emplace(20);

//Employee topemployer = Employee_stack.top();

Employee_stack.pop();


return 0;
}