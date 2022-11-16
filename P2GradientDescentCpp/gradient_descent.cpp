/*
Project 2: Implementing Gradient Descent in the context of 
a linear regression model in c++ 
*/

#include <iostream>
#include <vector>

using namespace std; 

void linear_regression(int epochs, float alpha, std::vector<float> x, std::vector<float> y)
{

}

template<typename T>
void print_vector(vector<T> const& arr)
{
    for (auto const& element : arr)
    {
        cout<<element<<" "; 

    }
    cout <<endl; 
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