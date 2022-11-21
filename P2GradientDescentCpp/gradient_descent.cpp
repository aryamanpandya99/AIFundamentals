/*
Project 2: Implementing Gradient Descent in the context of 
a linear regression model in c++ 
*/

#include <iostream>
#include <vector>
#include "/home/aryaman.pandya/matplotlib-cpp/matplotlibcpp.h"
//#include "gnuplot-iostream.h"

using namespace std;
namespace plt = matplotlibcpp;  

template<typename T>
void print_vector(vector<T> const& arr)
{
    for (auto const& element : arr)
    {
        cout<<element<<" "; 

    }
    cout <<endl; 
}

//sum of all elements in a vector 
float sum_vector(vector<float> const& arr)
{
    float output; 
    for (auto const& element : arr)
    {
        output += element; 

    }
    return output; 
}

vector<float> multiply_vectors(vector<float> a, vector<float> b)
{
    vector<float> solution; 
    int n = a.size(); 
    if(a.size() != b.size())
    {
        cerr<< "Vectors must be the same length to be multiplied"<<endl;
        return  solution; 
    }

    for (int i = 0; i < n; i++)
    {
        solution.push_back(a[i]*b[i]); 
    }

    return solution; 
}

vector<float> add_vectors(vector<float> a, vector<float> b)
{
    vector<float> solution; 
    int n = a.size(); 
    if(a.size() != b.size())
    {
        cerr<< "Vectors must be the same length to be added"<<endl;
        return  solution; 
    }

    for (int i = 0; i < n; i++)
    {
        solution.push_back(a[i]+b[i]); 
    }

    return solution; 
}

//a - b
vector<float> sub_vectors(vector<float> a, vector<float> b)
{
    vector<float> solution; 
    int n = a.size(); 
    if(a.size() != b.size())
    {
        cerr<< "Vectors must be the same length to be subtracted"<<endl;
        return  solution; 
    }

    for (int i = 0; i < n; i++)
    {
        solution.push_back(a[i]-b[i]); 
    }

    return solution; 
}

vector<float> mult_scalar_vector(float a, vector<float> vec)
{
    vector<float> solution; 
    int n = vec.size(); 
    
    for (int i = 0; i < n; i++)
    {
        solution.push_back(a*vec[i]); 
    }

    return solution; 
}

template<typename T> 
void plot_data (vector<T> x_data, vector<T>y_data)
{
    plt::figure_size(224, 168); 
    plt::plot(x_data, y_data); 
    plt::title("Simple x v/s y plot"); 
    plt::xlabel("X"); 
    plt::ylabel("Y"); 
}

void linear_regression(int epochs, float alpha, std::vector<float> x, std::vector<float> y)
{
    if(x.size()!=y.size())
    {
        cerr << "X and Y have dimensions, correct and try again" << endl; 
        return; 
    }

    //Gnuplot gp; 
    int n = x.size(); 
    float m_hat = 0, c_hat = 0, dm= 0, dc = 0, coeff = (-2/n); 
    vector<float> y_hat(n,0), c_hat_vec(n, c_hat); 

    for(int i = 0; i < epochs; i++)
    {
        y_hat = add_vectors(mult_scalar_vector(m_hat, x), c_hat_vec); //y = m*x + c
        dm = coeff * sum_vector(multiply_vectors(x, sub_vectors(y, y_hat))); 
        dc = coeff * sum_vector(sub_vectors(y, y_hat)); 

        m_hat = m_hat - (alpha * dm);
        c_hat = c_hat - (alpha * dc); 
    }


}

int main() 
{
    //generate data - gotta add noise 
    int n_data = 1000; 
    vector<float> m(n_data, 5); 
    vector<float> c(n_data,1); 

    vector<float> x; 
    int rand_num;
    float rand_float;

    vector<float> noise; 
    float r;

    for (int i = 0; i < n_data; i ++)
    {
        rand_num = rand() % 100 + 30; 
        rand_float = (float) rand_num; 
        x.push_back(rand_float); 
        
        r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        r = (r - 0.5) * 10;  
        noise.push_back(r);

    }

    /*print_vector(x);
    print_vector(noise);
    print_vector(m);
    */
    //set hyper parameters 
    int epochs = 20; 
    float learning_rate = 0.0001; 

    //call regression model 
}