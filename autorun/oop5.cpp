#include <iostream>
template <typename T>
void selectionSort(T arr[], int size) {
 for (int i = 0; i < size - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < size; j++) {
 if (arr[j] < arr[minIndex]) {
 minIndex = j;
 }
 }
 if (minIndex != i) {
 std::swap(arr[i], arr[minIndex]);
 }
 }
}
int main() {
 int intArray[] = {5, 2, 9, 3, 4};
 float floatArray[] = {3.14, 2.71, 1.618, 2.0, 0.5};
 int intSize = sizeof(intArray) / sizeof(intArray[0]);
 int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
 // Sort integer array
 selectionSort(intArray, intSize);
 std::cout << "Sorted Integer Array: ";
 for (int i = 0; i < intSize; i++) {
 std::cout << intArray[i] << " ";
 }
 std::cout << std::endl;
 // Sort float array
 selectionSort(floatArray, floatSize);
 std::cout << "Sorted Float Array: ";
 for (int i = 0; i < floatSize; i++) {
 std::cout << floatArray[i] << " ";
 }
 std::cout << std::endl;
 return 0;
}

