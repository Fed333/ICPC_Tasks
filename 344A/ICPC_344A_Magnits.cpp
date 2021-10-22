#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cin >> a;
    vector<int> arr;

    for (int i = 0; i < a; i++)
    {
        int b;
        cin >> b;
        arr.push_back(b);

    }

    int num=0;
    int last=arr[0];
    for (int i = 1; i < a; i++)
    {
            if (last%10==arr[i]/10)
            {
                num++;
            }

            last = arr[i];
    }
    num++;
    cout<<num;
}
