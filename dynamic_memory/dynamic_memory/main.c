//
//  main.c
//  dynamic_memory
//
//  Created by Jaron Treyer on 29.12.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(int argc, const char * argv[]) {
    char *arr, size = 5 , i;
    
    arr = malloc(size);
    
    if(!arr){
        printf("Memory allocation didn't work\n");
        return 0;
    }
    
    *arr = 10;
    *(arr+1) = 20;
    *(arr+2) = 30;
    
    printf("%p - address in Heap\n%p - next address in Heap\n%d - Value in Heap\n%d - Next value in Heap\n%d\n\n", arr, arr+1, *arr, *(arr+1),*(arr+2));
    return 0;
}
*/

/*
int main () {
    
    int size, i, num, sum = 0;
    
    printf("Tell me the size of the Array:\n");
    scanf("%d", &size);
    
    printf("Tell me the number you want to check:\n");
    scanf("%d", &num);
    
    int *p = calloc(size, sizeof(int));
    int *p1 = calloc(size, sizeof(int));

    
    if(p == NULL){
        printf("Couldn't allocate memory!");
        return 0;
    }
    
    printf("Enter the values of the array:\n");
    
    for (i = 0; i < size; i++) {
        scanf("%d", p+i);
        if(*(p+i) == num){
            sum += 1;
            *p1 = calloc(<#size_t __count#>, <#size_t __size#>)
        }
    }
    
    for (i = 0; i < sum; i++) {
        printf("%d, ", *(p1+i));
    }
    return 0;
    

}
*/

/*
char * checkString(char *p, char tav){
    
    return p;
}


int main () {
    char * string;
    printf("%s\n", string);
}
*/

int * combineArrays(int * p, int *p1, int size, int size1){
    int *new = calloc(size+size1, sizeof(int));
    
    for (int i = 0; i < size+size1; i++) {
        if(i == size){
            for (int y = 0; y < size1; y++) {
                *(new+i+y) = *(p1+y);
            }
            break;
        }
        *(new+i) = *(p+i);
    }
    return new;
}

int main () {
    int arr[] = {1,2,12,2,1};
    int arr1[] = {4,5,6,21};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int newSize = size + size1;

    int *new = combineArrays(arr, arr1, size, size1);
    
    for (int *i = new; i < new+newSize; i++) {
        printf("%d ", *i);
    }
}
