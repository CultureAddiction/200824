#include <stdio.h>
void swap(int *a, int* b);
int main() {
	int a[] = { 5,6,2,4,2,1,9,10,7 };

}
void sort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[j] > a[j + 1]) {

			}
		}
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}