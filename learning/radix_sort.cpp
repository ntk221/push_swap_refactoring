#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    stack<int> a;

    for (int i = 0; i < 5; i++)
        a.push(i);
    int     size  = a.size();
    int     max_num = size - 1;
    int     max_bits = 0;
    while ((max_num >> max_bits) != 0) ++max_bits;
    for (int i = 0; i < max_bits; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int num = a.top();
            if ((num >> i) & 1 == 1) 
        }
    }
}