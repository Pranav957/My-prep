void merge(int* arr, int l, int mid, int r) {
    int* output = new int[r - l + 1];
    int i = l, j = mid + 1, x = 0;

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            output[x++] = arr[i++];
        } else {
            output[x++] = arr[j++];
        }
    }

    while (i <= mid) {
        output[x++] = arr[i++];
    }

    while (j <= r) {
        output[x++] = arr[j++];
    }

    // Copy back to original array
    for (int k = 0; k < x; k++) {
        arr[l + k] = output[k];
    }

    delete[] output;  // ? Free the heap memory
}
void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    if(l>=r)
      return;

      int mid=l+(r-l)/2;
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      merge(arr,l,mid,r);
}
