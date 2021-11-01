#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;


typedef vector<int> vi;

int gcd(int a, int b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}


int find_odd_index(vi v, int last_i) {
    int o_i = last_i;
    while (o_i > 1 && v[o_i] % 2 > 0) {
        o_i--;
    }
    return o_i;
}

int main() {
    
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {

        scanf("%d", &n);
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int odd_index = find_odd_index(arr, arr.size() - 1);
        
        for (int i = 0; i < odd_index; i++)
        {
            if (arr[i] % 2 > 0)
            {
                arr[i] ^= arr[odd_index] ^= arr[i] ^= arr[odd_index];
                odd_index = find_odd_index(arr, odd_index);
            }
           
        }

        int counter = 0;
       
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0) {
                counter += n - (i + 1);
            }
            else
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (gcd(arr[i], 2 * arr[j]) > 1) {
                        counter++;
                    }

                }
            }

        }
        printf("%d\n", counter);
    }

    return 0;
}