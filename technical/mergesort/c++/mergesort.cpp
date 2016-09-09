void mergesort(int *array, unsigned size) {
  if(size < 2) return;
  if(size == 2 && array[0] > array[1]) {
    int tmp = array[0];
    array[0] = array[1];
    array[1] = tmp;
  } else {
    mergesort(array, size/2); // part a
    mergesort(array+(size/2), size - (size/2)); // part b

    int* buffer = new int[size];
    unsigned insert = 0, a = 0, b = size/2;
    while(a < size/2 && b < size) {
      if(array[a] <= array[b]) {
        buffer[insert++] = array[a++];
      }
      if(a < size/2 && array[a] > array[b]) {
        buffer[insert++] = array[b++];
      }
    }
    while(a < size/2) {
      buffer[insert++] = array[a++];
    }
    while(b < size) {
      buffer[insert++] = array[b++];
    }
    //copy back
    for(unsigned i = 0; i < size; i++) {
      array[i] = buffer[i];
    }
    //de-allocate
    delete[] buffer;
  }
}