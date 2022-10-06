// Quick Select Method - o(n) average
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[], int l, int h, int pivot)
{
    int i = l, j = l;
    while (i <= h)
        if (A[i] > pivot)
            i++;
        else
        {
            swap(A, i, j);
            i++;
            j++;
        }
    return j - 1;
}

int kthSmallest(int A[], int l, int h, int k)
{
    int pivot = A[h];
    int pi = partition(A, l, h, pivot);

    if (k - 1 == pi)
        return A[pi];
    else if (k - 1 < pi)
        return kthSmallest(A, l, pi - 1, k);
    else
        return kthSmallest(A, pi + 1, h, k);
}

// Min Heap Method - O(nlogk)
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> maxH;
    for (int i = l; i <= r; i++)
    {
        maxH.push(arr[i]);
        if (maxH.size() > k)
            maxH.pop();
    }
    return maxH.top();
}