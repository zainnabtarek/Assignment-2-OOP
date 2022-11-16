//Name : Mennatallah Mahmoud Abdullah
//ID : 20210405
//Sheet 2 (problem 1)
#include <iostream>
using namespace std;
double cube (double );
double second (double );
double fun (double );
class Function
{
    protected:
        double (*p1)(double );//pointer to the functions
        double (*p2)(double );//pointer to the functions
        double p;//container
    public:
        virtual double evaluateAt(double value) = 0;
};
class SimpleFunction:public Function
{
    public:
        SimpleFunction(double (*func)(double ))
        {
            p1 = func;
        }
        double evaluateAt(double value)
        {
            return p1(value);
        }
        
};

class CompositionFunction:public Function
{
    public:
        CompositionFunction(double (*f)(double ), double (*g)(double ))//F,G = F(G(x))
        {
            p1 = f;
            p2 = g;
        }
        double evaluateAt(double value)
        {
            double result;
            result = p2(value);
            return p1(result);
        }
};
class DerivativeFunction:public Function
{
    public:
        DerivativeFunction(double (*func)(double ), double num)
        {
            p1 = func;
            p = num;
        }
        double evaluateAt(double value)
        {
            //(F(x + Δx) – F(x - Δx)) / 2Δx  (p = Δx, x = value) 
            double derivative;
            derivative = (p1(value + p) - p1(value - p)) / (2*p);
            return derivative;
        }
};

int main()
{
    SimpleFunction f1(cube);
    cout << f1.evaluateAt(5) << endl;
    CompositionFunction f3(fun,cube);
    cout << f3.evaluateAt(5) << endl;
    DerivativeFunction f2(second,5);
    cout << f2.evaluateAt(5);
    

    return 0;
}
//test functions
double cube (double n) 
{
    return n * n * n;
}
double second (double d) 
{
    return d * d - 5 * d - 4;
}
double fun (double d) 
{
    return d * d - 3 * d - 4;
}

