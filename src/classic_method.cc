#include "../include/tools.h"

INT_MATRIX classic_multiplication(INT_MATRIX m1, INT_MATRIX m2)
{
    if (m1[0].size() != m2.size()) return init_int_matrix(1);

    INT_MATRIX ans = init_int_matrix(m1.size());
    
    for(int i = 0; i < m1.size(); i++)
    {
        for(int j = 0; j < m2[0].size(); j++)
        {
            for(int k = 0; k < m2.size(); k++)
            {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    if (argc != 2) return -1;
    int _size = atoi(argv[1]);
    take_time(multiply_two_matrices, classic_multiplication, _size);
}