#include <iostream>

using namespace std;

int Kvadrat(unsigned char *);

int main(void)
{
    unsigned char array[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    short int sum=0;
    
    sum=Kvadrat(array);
    
    printf("Sum ^2 %d\n", sum);

    return 0;
}

int Kvadrat(unsigned char *data)
{
    short int sum=0;

    __asm__
    (
        "movl $10, %%ecx\n\t"
        "m1:\n\t"
        "movb (%%rbx), %%al\n\t"
        "movb (%%rbx), %%dl\n\t"
        "mulb %%dl\n\t"
        "addw %%ax, %%si\n\t"
        "incq %%rbx\n\t"
        "loop m1\n\t"
        :"=S"(sum)
        :"S"(sum), "b"(data)
        :"cc", "memory"
    );

    return sum;
}
