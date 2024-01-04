#include <stdio.h>

int main(void)
{
    //declare and initialize a variable of datatype integer
    int x = 100;
    //we print the value of x
    printf("x equals to %i\n", x);

    //declare and initialize another variable of datatype integer
    int y = 0;
    //we print the value of y
    printf("y equals to %i\n", y);

    //we print the address of y
    printf("the memory address of y equals to %p\n", &y);

    //declare a pointer and initialize it to NULL
    int* pointer = NULL;

    //we point the pointer variable to the adress of x
    pointer = &x;

    //we print the memory address of x
    printf("the memory address of x equals to %p\n", &x);

    //we print the memory address of , which is what the pointer is pointing at
    printf("the memory address of pointer equals to %p\n", pointer);

    //we print the value of y
    printf("y equals to %i\n", y);

    //we assign variable y by dereferncing the pointer
    y = *pointer;

    //we print the value of y
    printf("y equals to %i\n", y);

    printf("*****************************************************\n");

    //lets do the same thing with chars
    //char charArrayX[5] = "TEST\0";
    //if we dont include the end character then we are not sure on how our string performs
    char charArrayX[4] = "TEST";

    //we print the value of charArrayX
    printf("charArrayX equals to %s\n", charArrayX);
    printf("We might get unknown values in the end because we did not use backslash 0 in the end\n");

    //we print the memory address of charArrayX,
    printf("the memory address of charArrayX equals to %p\n", &charArrayX);

    //lets save it into a pointer - the pointer points to the address of charArrayX
    char* pointerChar = &charArrayX[0];

    //we print the memory address that the pointer pointerChar is pointing,
    printf("the memory address of pointerChar equals to %p\n", pointerChar);

   // we print the letters of the string TEST by dererencing teh pointer pointerChar
    printf("the first letter of TEST is %c\n", *pointerChar);
    printf("the second letter of TEST is %c\n", *(pointerChar+1));
    printf("the third letter of TEST is %c\n", *(pointerChar+2));
    printf("the fourth letter of TEST is %c\n", *(pointerChar+3));
    //printf("the fifth letter of TEST is %c\n", *(pointerChar+4));
    printf("the fifth letter of TEST is %i\n", *(pointerChar+4));
    printf("The fifth letter though is out of our array. So the result we get is what happens to be at the memory at the moment\n");

    printf("*****************************************************\n");

    //lets create a char pointer array
    char* newPointer[] = {"Hello", ",", "How", "Are", "You", "?"};

    printf("the newPointer char array is %s\n", *newPointer);
    printf("Remember, it just points to the first value. Since we use percentage s we get its value\n");
    // and we print the memory location of the first char
    printf("the address of the newPointer char array is %p\n", newPointer);
    printf("Which is basically the memory location of the word Hello\n");

    // we can also print the string Hello by using a %s
    printf("the content of the newPointer[0] char array is %s\n", newPointer[0]);

    // we can also print the 3rd char array
    printf("the content of the newPointer[2] char array is %s\n", newPointer[2]);

    printf("The 4th char array is Are\n");
    //and if we want to print a specific letter from the 4th char array
   printf("the second letter of the 4th char array of newPointer is %c\n", newPointer[3][1]);

    //the memory address of this letter is
   printf("the memory address of the second letter of the 4th char array of newPointer is %p\n", &newPointer[3][1]);

    // a bit silly example as we go to that address and then we get its value
   printf("the second letter of the 4th char array of newPointer is %c\n", *&newPointer[3][1]);

}