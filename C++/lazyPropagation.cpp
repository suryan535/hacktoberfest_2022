#include <iostream>
#include <cmath>
using namespace std;

/*

IMPORTANT to update the lazy values while finding sum also

*/

void construct(int segTree[], int arr[], int l, int r, int node)
{
    if (l == r)
    {
        segTree[node] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    construct(segTree, arr, l, mid, 2 * node + 1);
    construct(segTree, arr, mid + 1, r, 2 * node + 2);

    segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

int getSum(int segTree[], int lazyTree[], int arr[], int l, int r, int reql, int reqr, int node)
{
    if (lazyTree[node] != 0)
    {
        segTree[node] += (r - l + 1) * lazyTree[node];

        if (l != r)
        {
            lazyTree[2 * node + 1] += lazyTree[node];
            lazyTree[2 * node + 2] += lazyTree[node];
        }

        lazyTree[node] = 0;
    }

    if (l >= reql && r <= reqr)
    {
        return segTree[node];
    }

    if (reql > r || reqr < l)
        return 0;

    int mid = l + (r - l) / 2;

    return getSum(segTree, lazyTree, arr, l, mid, reql, reqr, 2 * node + 1) + getSum(segTree, lazyTree, arr, mid + 1, r, reql, reqr, 2 * node + 2);
}

void updateRange(int segTree[], int lazyTree[], int arr[], int l, int r, int reql, int reqr, int diff, int node)
{
    if (lazyTree[node] != 0)
    {
        segTree[node] += (r - l + 1) * lazyTree[node];

        if (l != r)
        {
            lazyTree[2 * node + 1] += lazyTree[node];
            lazyTree[2 * node + 2] += lazyTree[node];
        }

        lazyTree[node] = 0;
    }

    if (l > reqr || r < reql)
        return;

    if (l >= reql && r <= reqr)
    {
        segTree[node] += (r - l + 1) * diff;

        if (l != r)
        {
            lazyTree[2 * node + 1] += diff;
            lazyTree[2 * node + 2] += diff;
        }

        return;
    }

    int mid = l + (r - l) / 2;

    updateRange(segTree, lazyTree, arr, l, mid, reql, reqr, diff, 2 * node + 1);
    updateRange(segTree, lazyTree, arr, mid + 1, r, reql, reqr, diff, 2 * node + 2);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int h = ceil(log2(n));
    int maxN = 2 * pow(2, h) - 1;

    int segTree[maxN];
    int lazyTree[maxN];

    fill(segTree, segTree + maxN, 0);
    fill(lazyTree, lazyTree + maxN, 0);

    construct(segTree, arr, 0, n - 1, 0);

    cout << getSum(segTree, lazyTree, arr, 0, n - 1, 1, 3, 0) << "\n";

    updateRange(segTree, lazyTree, arr, 0, n - 1, 1, 5, 10, 0);

    cout << getSum(segTree, lazyTree, arr, 0, n - 1, 1, 3, 0) << "\n";
    return 0;
}