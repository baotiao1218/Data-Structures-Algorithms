#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int size;
    int *s;
};

void Create(struct Stack *st)
{
    printf("Enter Size of stack.");
    scanf("%d",&st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    if(IsEmpty(st))
        printf("Empty!");
    else
    {
        for(int i = st.top; i >= 0; i--)
        {
            printf("Pos: %d, Value: %d\n", (st.top-i+1), st.s[i]);
        }
    }
}

int Push(struct Stack *st, int x)
{
    if(st->top == (st->size)-1)
    {
        printf("Full!");
        return -1;
    }
    st->top++;
    st->s[st->top] = x;
    return 1;
}

int Pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Empty!");
        return -1;
    }
    x = st->s[st->top--];

    return x;
}

int Peek(struct Stack st, int pos)
{
    if(st.top == -1)
    {
        printf("Stack underflow!");
        return -1;
    }
    if(pos-1 > st.top)
    {
        printf("Stack overflow!");
        return -1;
    }
    if(pos < 1)
    {
        printf("pos start from 1.\n");
        return -1;
    }

    return st.s[(st.top-pos)+1];
}

int IsFull(struct Stack st)
{
    return st.top == st.size-1;
}

int IsEmpty(struct Stack st)
{
    return st.top==-1?1:0;
}

int StackTop(struct Stack st)
{
    if(IsEmpty(st))
        return -1;

    return st.s[st.top];
}

int main()
{
    int a[] = {1,3,5,7,9};
    int res = 0;
    struct Stack st;
    Create(&st);
    Push(&st, 35);
    Push(&st, 45);
    Push(&st, 55);
    Push(&st, 65);
    Display(st);
    return 0;
}



