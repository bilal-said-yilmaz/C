#include <stdio.h>
#include <stdlib.h>

int main(){
    int *numbers;
    int size=5;

    numbers = (int*) malloc(size * sizeof(int));
    
    for (int i =0; i<size ; i++){
        numbers[i]=i*10;
        printf("%d\t",numbers[i]);
    }

    free(numbers);
    return 0;
}
