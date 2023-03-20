#include "../include/tools.h"

INT_MATRIX blocks_multiplication(INT_MATRIX m1, INT_MATRIX m2)
{
    if (m1[0].size() != m2.size()) return init_int_matrix(1);

    INT_MATRIX ans = init_int_matrix(m1.size());
    
    return ans;
}

int main()
{
    multiply_two_matrices(blocks_multiplication, 5);
}