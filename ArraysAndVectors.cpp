#include <stdio.h>
#include <stdlib.h>

int ID = 1;

struct vec{
  int id;
  int size;
  int cap;
  int *arr;
};

//to prevent global access to the newvec object instance, you can return it from
//construct vec and only use that instance (which is way better practice)

void constructVec(int val, struct vec *newvec){
    newvec->id = ID;
    newvec->cap = val;
    newvec->size = 0;
    newvec->arr = (int *)malloc(newvec->cap * sizeof(int));
    
    ID++;
}

void push(int val, struct vec *newvec){
    if(newvec->size < newvec->cap){
        newvec->arr[newvec->size] = val;
        newvec->size++;
    }else{
        printf("the vector is full");
    }
}

void pop(struct vec *newvec){
    if(newvec->size > 0){
        newvec->size--;
        newvec->arr[newvec->size] = 0;
    }else{
        printf("the vector is empty");
    }
}

void unshift(int val, struct vec *newvec){
    if(newvec->size < newvec->cap){
        int i = newvec->size;
        
        while(i >= 0){
            newvec->arr[i + 1] = newvec->arr[i];
            newvec->arr[i] = val;
            i--;
        }
        newvec->size++;
    }else{
        printf("the vector is full");
    }
}

void shift(struct vec *newvec){
    if(newvec->size > 0){
        int i = 0;
        
        while(i < newvec->size){
            newvec->arr[i] = newvec->arr[i + 1];
            i++;
        }
        newvec->size--;
    }else{
        printf("the vector is empty");
    }
}

void insert(int index, int val, struct vec *newvec){
    if(newvec->size < newvec->cap){
        int i = newvec->size;
        
        while(i >= index){
            newvec->arr[i + 1] = newvec->arr[i];
            newvec->arr[i] = val;
            i--;
        }
        newvec->size++;
    }else{
        printf("the vector is full");
    }
}

void del(int index, struct vec *newvec){
    if(newvec->size > 0 && index <= newvec->size){
        int i = index;
        
        while(i < newvec->size){
            newvec->arr[i] = newvec->arr[i + 1];
            i++;
        }
        newvec->size--;
    }else{
        printf("the vector is empty");
    }
}

void displaySum(struct vec *newvec){
    int total = 0;
    int i = 0;
    
    while(i < newvec->size){
        total += newvec->arr[i];
        
        i++;
    }
    
    printf("sum of v%d", newvec->id);
    printf(" = %d", total);
    printf("\n");
}

void getMax(struct vec *newvec){
    int max = 0;
    
    for(int i = 0; i < newvec->size; i++){
        if(newvec->arr[i] > max){
            max = newvec->arr[i];
        }
    }
    
    printf("largest element in v%d", newvec->id);
    printf(" = %d", max);
    printf("\n");
}

void getMin(struct vec *newvec){
    int min = 2147483647;
    
    for(int i = 0; i < newvec->size; i++){
        if(newvec->arr[i] < min){
            min = newvec->arr[i];
        }
    }
    
    printf("smallest element in v%d", newvec->id);
    printf(" = %d", min);
    printf("\n");
}

int Get(struct vec *newvec, int idx){
    
    for(int i = 0; i < newvec->size; i++){
        if(i == idx){
            return newvec->arr[i];
        }
    }
    
    return 0;
}

int Set(struct vec *newvec, int idx, int num){
    if(idx < newvec->cap){
        for(int i = 0; i < newvec->size; i++){
            if(i == idx){
                newvec->arr[i] = num; 

                return 1;
            }
        }
    }else{
        printf("numbah too huge!!");
    }
    
    return 0;
}

void displayVector(struct vec *newvec){
    printf("\n");
    printf("v%d", newvec->id);
    printf("<");
    for(int i = 0; i < newvec->cap; i++){
        printf("%d ", *(newvec->arr + i));
        if(i < newvec->cap - 1){
            printf(",");
        }
    }
    printf(">  ");
}

//MUST FIX DISPLAY VECTOR
void reverseVec(struct vec *newvec){
    //printf("%d", newvec->size);
    
    for(int i = 0; i < newvec->size; i++){
        printf("%d", newvec->arr[i]);
    }
    
    int i = 0;
    int j = newvec->size - 1;
    int temp = 0;
    
    while(i < j){
        temp = newvec->arr[i];
        newvec->arr[i] = newvec->arr[j];
        newvec->arr[j] = temp;
        
        i++;
        j--;
    }
    
    for(int i = 0; i < newvec->size; i++){
        printf("%d", newvec->arr[i]);
    }
    
    //displayVector(&newvec);
}

int getAvg(struct vec *newvec){
    int average;
    int total = 0;
    int i = 0;
    
    while(i < newvec->size){
        total += newvec->arr[i];
        i++;
    }
    
    average = total/newvec->size;
    
    return average;
}

void addAllVectors(struct vec arr [], int arrSize, int sizeOfVectorSet){
    /*printf("%d ", arr[0].arr[0] + arr[1].arr[0]);
    printf("%d ", arr[0].arr[1] + arr[1].arr[1]);
    printf("%d ", arr[0].arr[2] + arr[1].arr[2]);*/
    
    struct vec vecTotal;
    constructVec(sizeOfVectorSet, &vecTotal);

    //iterate through total of total of arrays passed
    for(int i = 0; i < sizeOfVectorSet; i++){
        int total = 0;
        for(int j = 0; j < arrSize; j++){
            total += arr[j].arr[i];
        }
        push(total, &vecTotal);
    }
    
    displayVector(&vecTotal);
}

void subtractAllVectors(struct vec arr [], int arrSize, int sizeOfVectorSet){
    struct vec vecTotal;
    constructVec(sizeOfVectorSet, &vecTotal);
    
    for(int i = 0; i < sizeOfVectorSet; i++){
        int total = 0;
        for(int j = 0; j < arrSize; j++){
            total -= arr[j].arr[i];
        }
        push(total, &vecTotal);
    }
    
    displayVector(&vecTotal);
}

void scalarMultiplyVector(struct vec *newvec, int multiple, int vecSize){
    struct vec vecScalarProduct;
    constructVec(vecSize, &vecScalarProduct);
    
    //printf("%d ", multiple * newvec->arr[0]);
    int product = 0;
    
    for(int i = 0; i < vecSize; i++){
        product = multiple * newvec->arr[i];
        push(product, &vecScalarProduct);
        product = 0;
    }
    
    displayVector(&vecScalarProduct);
}

void dotProduct(struct vec *newvec1, struct vec *newvec2){
    //printf("%d ", newvec1->arr[0] * newvec2->arr[0] + newvec1->arr[1] * newvec2->arr[1] + newvec1->arr[2] * newvec2->arr[2]);

    int dotProduct = 0;
    
    for(int i = 0; i < 3; i++){
        dotProduct += newvec1->arr[i] * newvec2->arr[i];
    }
    
    printf("%d", dotProduct);
}

void destroyVec(struct vec *newvec){
    newvec->id = 0;
    newvec->cap = 0;
    newvec->size = 0;
    newvec->arr = NULL;
    
    ID--;
}

int main()
{
    struct vec vec1;
    
    constructVec(4, &vec1);
    
    push(10, &vec1);
    push(10, &vec1);
    push(10, &vec1);
    push(1, &vec1);
    
    printf("%d", getAvg(&vec1));
    //displayVector(&vec1);
    
    destroyVec(&vec1);

    return 0;
}