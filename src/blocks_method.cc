#include "../include/tools.h"

INT_MATRIX blocks_multiplication(INT_MATRIX m1, INT_MATRIX m2)
{
    if (m1[0].size() != m2.size()) return init_int_matrix(1);

    INT_MATRIX ans = init_int_matrix(m1.size());

    int i, j , k;
    int i1, j1, k1;

    for(i = 0; i < m1.size(); i+=BLOCK_SIZE)
    {
        for(j = 0; j < m1.size(); j+=BLOCK_SIZE)
        {
            for(k = 0; k < m1.size(); k+=BLOCK_SIZE)
            {
                for(i1 = i; i1 < i+BLOCK_SIZE; i1++)
                {
                    for(j1 = j; j1 < j+BLOCK_SIZE; j1++)
                    {
                        for(k1 = k; k1 < k+BLOCK_SIZE; k1++)
                        {
                            ans[i1][j1] += m1[i1][k1] * m2[k1][j1];
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    multiply_two_matrices(blocks_multiplication, 8);
}