#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

#define print_vector(v) for(int i = 0; i < v.size(); i++) std::cout << v[i] << " "; std::cout << std::endl;
#define print_matrix(m) for(int j = 0; j < m.size(); j++) {print_vector(m[j]);}
#define init_int_matrix(u) std::vector<std::vector<int>>(u, std::vector<int>(u,0));
#define init_float_matrix(u) std::vector<std::vector<float>>(u, std::vector<float>(u,0.f));
#define init_double_matrix(u) std::vector<std::vector<double>>(u, std::vector<double>(u,0));
#define LIMIT 10000
#define BLOCK_SIZE 64

typedef std::vector<std::vector<int>> INT_MATRIX;
typedef std::vector<std::vector<float>> FLOAT_MATRIX;
typedef std::vector<std::vector<double>> DOUBLE_MATRIX;
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<float> fsec;

INT_MATRIX generate_random_matrix(unsigned int _size)
{
    INT_MATRIX ans = init_int_matrix(_size);
    
    srand(time(NULL));

    for(int i = 0; i < _size; i++)
    {
        for(int j = 0; j < _size; j++)
        {
            ans[i][j] = rand() % LIMIT + 1; 
        }
    }
    return ans;
}

void multiply_two_matrices(INT_MATRIX (*mult)(INT_MATRIX, INT_MATRIX), unsigned int _size)
{
    INT_MATRIX m1 = generate_random_matrix(_size), m2 = generate_random_matrix(_size);
    INT_MATRIX m3 = mult(m1, m2);
}

void take_time(void (*func)(INT_MATRIX(*)(INT_MATRIX, INT_MATRIX), unsigned int ), INT_MATRIX (*mult)(INT_MATRIX, INT_MATRIX), unsigned int _size)
{
    auto start = Time::now();
    func(mult, _size);
    auto end = Time::now();
    fsec fs = end - start;
    std::cout << "Elapsed time: " << fs.count() << "s" << std::endl;
}
