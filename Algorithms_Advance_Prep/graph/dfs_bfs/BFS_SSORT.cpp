/**
 *   author: sahushivam
 *   created: 11 July 2019 (Thursday)  13:55:27
**/
//Explained here
//Take input and sort it in another array,
//map it to its correct position after sorted
//take cycle in which swap is going to happen
//if cycle size is k then k-1 swap occurs and always swap with minimum element of the cycle
//so in each cycle sum added will be (k-1)*min element + sum of all element in cycle-min element
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int a[100000];
int b[100000];
bool vis[100000];

int main (void) {
    int N;
    int t = 0;
    while (scanf("%d", &N) && N) {
        t++;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
            vis[i] = false;
        }
        sort(b, b + N);

        // Map the numbers to their desired place after sort
        map<int, int> place;
        
        for (int i = 0; i < N; ++i) {
            place[b[i]] = i;
        }
    
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (vis[i] == false) {
                if (place[a[i]] == i) {
                    vis[i] = true;
                    continue;
                }
                // We're in new cycle
                int min_val = a[i];
                int num = 0;
                int sum = 0;
                int j = i;

                while (vis[j] == false) {
                    sum += a[j];
                    num++;
                    if (a[j] < min_val) {
                        min_val = a[j];
                    }
                    vis[j] = true;
                    j = place[a[j]];
                }
                sum -= min_val;
                res += sum + min_val * (num - 1);
                
                // Let's try to borrow the minimum value.
                // If it's less costly then update our result.
                if (2 * (b[0] + min_val) <
                    (min_val - b[0]) * (num - 1)) {
                    res -= (min_val - b[0]) * (num - 1) -
                           2 * (b[0] + min_val);
                }    
            }
        }
        printf("Case %d: %d\n\n", t, res);
    }
    return 0;
}