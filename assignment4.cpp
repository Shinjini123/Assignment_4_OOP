#include <iostream>
using namespace std;
// Constructor class created to demonstrate constructors and destructors
class Constructor
{
public:
    int x;
    Constructor()
    {
        x = 7;
        cout << "\nDefault Constructor called with value: " << x;
    }
    Constructor(int a)
    {
        x = a;
        cout << "\nParameterised Constructor called with value: " << x;
    }
    Constructor (Constructor &c1, Constructor &c2)
    {
        x = c1.x + c2.x;
        cout << "\nCopy Constructor called with value: " << x;
    }
    ~Constructor()
    {
        cout << "\nDestructor called ";
    }
};
// Operator overloading to show ++operator overloading
class Count {
   private:
    int value;

   public:

    // Constructor to initialize count to 5
    Count() : value(5) {
        
    }

    // Overload ++ when used as prefix
    void operator ++ () {
        ++value;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};
// Function overloading to calculate area 
float area(int r)
{
    float a;
    float pi = 3.14;
    a = pi * r * r;
    return a;
}
int area(int l, int b)
{
    float a1;
    a1 = l * b;
    return a1;
}
float area(int n, int bs, int h)
{
    float a2;
    a2 = n * bs * h;
    return a2;
}
// friend function concept used to add two values
class base {
    int val1, val2;
public:

    void get() {
        cout << "Enter two values:";
        cin >> val1>>val2;
    }
    friend float mean(base ob);
};

float mean(base ob) {
    return float(ob.val1 + ob.val2) / 2;
}
// Demonstration of Inheritance
class A
{
protected:
    int a;

public:
    A()
    {
        a = 5;
    }
    virtual void Show_Value() = 0;
};
//use of virtual class
class B : virtual public A
{
protected:
    int b;

public:
    B()
    {
        b = 6;
    }
};
class C : virtual public A
{
protected:
    int c;

public:
    C()
    {
        c = 7;
    }
};
class D : public B, public C
{
protected:
    int d;

public:
    D()
    {
        d = 8;
    }
    void Show_Value()
    {
        cout << "\nA: " << a;
        cout << "\nB: " << b;
        cout << "\nC: " << c;
        cout << "\nD: " << d;
    }
};
// Template class to show the largest of the two numbers
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
// Exception handling to carry out division by zero error
void Div_by_zero()
{
    int a, b;
    cout << "\nEnter two numbers :";
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw -1;
        else
            cout << "\nAnswer: " << (a / b);
    }
    catch (int)
    {
        cout << "\nDivision not possible!";
    }
}
//program to show function overloading

int main()
{
    int c;
    while (1)
    {
        cout << "\n\nENTER YOUR CHOICE\n\n";
        cout << "\n1.Demonstrating use of constructor and destructor";
        cout << "\n2. Use of Operator Overloading";
        cout << "\n3.Using Function Overloading";
        cout << "\n4.Using Friend Function";
        cout << "\n5.Demonstrating Inheritance";
        cout << "\n6.Using Template";
        cout << "\n7.Using Exception Handling";
        cout << "\n9.Quit";
        cout << endl;
        cout << "Enter choice: ";
        cin >> c;
        if (c == 1)
        {
            Constructor s1 ;//default constructor called
            Constructor  s2(15);//parametarised constructor called
            Constructor  s3(s1, s2);//copy constructor called
        }
        else if (c == 2)
        {
            Count count1;
           // Call the "void operator ++" function
         ++count1;
          count1.display();
        }
        else if (c == 3)
        {
            int b, bs, h, r, l;
            float area1;
            cout << "\nEnter the Radius of Circle: \n";
            cin >> r;
            area1 = area(r);
            cout << "\nArea of Circle: " << area1 << endl;
            cout << "Enter the Base & Hieght of Triangle:\n";
            cin >> bs;
            cin >> h;
            area1 = area(0.5, bs, h);
            cout << "\nArea of Triangle: " << area1 << endl;
            cout << "\nEnter the Length & Bredth of Rectangle: \n";
            cin >> l >> b;
            area1 = area(l, b);
            cout << "\nArea of Rectangle: " << area1 << endl;
            break;
        }
        //to demonstrate friend function
        else if (c == 4)
        {
           base obj;
          obj.get();
          cout << "\n Mean value is : " << mean(obj);
        }
        //demonnstrating inheritence
        else if (c == 5)
        {
            D d;
            cout << "\ninherited values: ";
            d.Show_Value();
            break;
        }
        else if (c == 6)
        {
           cout << myMax<int>(3, 7) << endl;
            cout << myMax<double>(3.0, 7.0) << endl;
            cout << myMax<char>('f', 'b') << endl;
            break;
        }
        else if (c == 7)
        {
            cout << "\nDivision by Zero in Exception Handling: ";
            Div_by_zero();
            break;
        }
        else if (c == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\nWrong  Choice ! Enter valid choice ";
        }
    }
    return 0;
}