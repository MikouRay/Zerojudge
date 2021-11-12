#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef union
{
    char opt;
    long long number;
} data_t;

typedef struct stack_s
{
    data_t value;
    struct stack_s* next;
} stack_t;

stack_t* create(data_t input)
{
    stack_t* pos = (stack_t*)malloc(sizeof(stack_t)*1);
    if(pos!=NULL)
    {
        pos->value = input;
        pos->next = NULL;
    }
    return pos;
}

void push(stack_t** head,stack_t* node)
{
    stack_t* temp = (*head);
    if(node == NULL)
    {
        return;
    }

    if(temp == NULL)
    {
        (*head) = node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

stack_t* pop(stack_t** head)
{
    stack_t* prev = (*head);
    stack_t* temp = (*head);
    if((*head) == NULL)
    {
        return NULL;
    }

    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == (*head))
    {
        (*head) = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    return temp;
}

long long operation(char opt, long long num1, long long num2)
{
    switch (opt)
    {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return floor(num1 / num2);
        case '%': return floor(num1 % num2);
    }
    return 0;
}

void do_operation(char opt, stack_t **head)
{
    data_t temp_data;
    stack_t *temp = NULL;

    //get first number
    temp = pop(head);
    if(temp != NULL)
    {
        temp_data.number = temp->value.number;
        free(temp);

        //get second number;
        temp = pop(head);
        if(temp != NULL)
        {
            temp_data.number = operation(opt,temp->value.number,temp_data.number);
            temp->value = temp_data;
            push(head,temp);
        }
        else
        {
            //No second number
            temp = create(temp_data);
            push(head,temp);
        }
    }
}

int main(int argc,char* argv[])
{
    data_t data;
    stack_t *head_num = NULL, *head_opr = NULL;
    stack_t *temp = NULL;

    char *input = NULL, *buf = NULL;
    char opt;

    input = (char*)malloc(sizeof(char)*65536);
    if(input == NULL)
    {
        return -1;
    }

    while(fgets(input,65536,stdin)!=NULL)
    {
        buf = strtok(input," ");
        while(buf != NULL)
        {
            if(buf[strlen(buf)-1] == '\n')
                buf[strlen(buf)-1] = 0;

            temp = NULL;
            if(buf[0] == '(' || buf[0] == ')')
            {
                if(buf[0] == ')')
                {
                    temp = pop(&head_opr);
                    while((temp != NULL) && (temp->value.opt != '('))
                    {
                        //store operator
                        opt = temp->value.opt;
                        free(temp);

                        do_operation(opt, &head_num);
                        temp = pop(&head_opr);
                    }
                    if(temp!=NULL)
                    {
                        free(temp);
                    }
                }
                else
                {
                    data.opt = buf[0];
                    temp = create(data);
                    push(&head_opr,temp);
                }
            }
            else if(buf[0]=='+' || buf[0] == '-' ||
               buf[0] == '*' || buf[0] == '/' || buf[0] == '%' )
            {
                //pop previous operator to check
                temp = pop(&head_opr);
                if(temp!=NULL)
                {
                    //If previous operator is ( or small than *,/,%.
                    //Store current operator to stack and wait next operator
                    if(((temp->value.opt == '(') ||
                       ((buf[0] == '*' || buf[0] == '/' || buf[0] == '%') && ((temp->value.opt == '+') || (temp->value.opt == '-')))))
                    {
                        push(&head_opr,temp);
                    }
                    else
                    {
                        //If level is same, do leftmost first
                        while((temp != NULL) && (temp->value.opt != '('))
                        {
                            opt = temp->value.opt;
                            do_operation(opt, &head_num);
                            free(temp);
                            temp = pop(&head_opr);
                        }
                        if((temp != NULL) && (temp->value.opt == '('))
                        {
                            push(&head_opr,temp);
                        }
                    }
                    data.opt = buf[0];
                    temp = create(data);
                    push(&head_opr,temp);
                }
                else
                {
                    data.opt = buf[0];
                    temp = create(data);
                    push(&head_opr,temp);
                }
            }
            else if(buf[0]!=' ' && buf[0]!= 0)//store number
            {
                data.number = (long long)atoll(buf);
                temp = create(data);
                push(&head_num,temp);
            }

            buf = strtok(NULL," ");
        }

        //end parsing and do last operator
        temp = pop(&head_opr);
        while(temp != NULL)
        {
            opt = temp->value.opt;
            free(temp);

            if(opt == ')')
            {
                temp = pop(&head_opr);
                while((temp != NULL) && (temp->value.opt != '('))
                {
                    //store operator
                    opt = temp->value.opt;
                    free(temp);

                    do_operation(opt, &head_num);
                    temp = pop(&head_opr);
                }
                if(temp!=NULL)
                {
                    free(temp);
                }
            }
            else if(opt =='+' || opt == '-' ||
               opt == '*' || opt == '/' || opt == '%')
            {
                do_operation(opt, &head_num);
            }

            temp = pop(&head_opr);
        }

        //output last result
        temp = pop(&head_num);
        if(temp != NULL)
        {
            printf("%I64d\n",temp->value.number);
            free(temp);
        }
    }

    free(input);
    return 0;
}
