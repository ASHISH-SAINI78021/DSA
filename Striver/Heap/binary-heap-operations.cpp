int MinHeap::extractMin() {
    if (heap_size <= 0)
        return -1;  // return -1 when heap is empty

    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


// Function to delete a key at index i
void MinHeap::deleteKey(int i) {
    if (i < 0 || i >= heap_size) return;

    decreaseKey(i, INT_MIN);
    extractMin();
}

// Function to insert a new key
void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "Overflow: Could not insertKey\n";
        return;
    }

    // Insert at the end
    int i = heap_size;
    harr[heap_size++] = k;

    // Fix min heap property
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to decrease value at index i
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Heapify function
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

