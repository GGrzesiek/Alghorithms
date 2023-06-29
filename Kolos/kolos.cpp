
struct element{
    int number;
    element* next;
};
int countEvenElements(element* stos)
{
    int count = 0;
    element* tempStack = nullptr;  

    while (!isEmpty(stos)) {
        int element = first(stos);  
        pop(stos); 

        if (element % 2 == 0)
        {
            count++; 
        }

        push(tempStack, element); 
    }
    while (!isEmpty(tempStack))
    {
        int element = first(tempStack);  
        pop(tempStack);  
        push(stos, element);
    }

    return count;
}
