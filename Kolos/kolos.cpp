struct element{
    int number;
    element* next;
}
int countEvenElements(stos* w) {
    int count = 0;
    stos* tempStack = nullptr;  

    while (!isEmpty(w)) {
        int element = first(w);  
        pop(w); 

        if (element % 2 == 0) {
            count++; 
        }

        push(tempStack, element); 

    while (!isEmpty(tempStack)) {
        int element = first(tempStack);  
        pop(tempStack);  
        push(w, element);
    }

    return count;
}
