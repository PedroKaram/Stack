#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int day, month, year;
} DateTime;

typedef struct
{
  char name[50];
  DateTime date;
} Person;

typedef struct stack
{
  Person person;
  struct stack *next;
} Stack;

int user_interface();
Person read_person();
void print_person(Person person);
void print_stack(Stack *top);
Stack *push(Stack *top);
Stack *pop(Stack **top);

int main()
{
  Stack *remove, *top = NULL;
  int opt;

  do
  {
    opt = user_interface();

    switch(opt)
    {
      case 1:
        top = push(top);
        break;

      case 2:
        remove = pop(&top);
        if(remove)
        {
          printf("\nElement successfully removed!\n");
          print_person(remove->person);
        }
        else
          printf("No element to remove");
        break;

      case 3:
        print_stack(top);
        break;

      case 4:
        printf("Exit");
        break;

      default:
        printf("[ERROR] Try another value!");
        break;
    }
  } while(opt != 4);
  
  return 0;
}

int user_interface()
{
  int opt;

  printf("\n\nChoose a Stack operation: \n\n");

  printf("[1] - Push \n");
  printf("[2] - Pop \n");
  printf("[3] - Print Stack \n");
  printf("[4] - Exit \n\n");
  
  printf("Option: ");
  scanf("%d", &opt);

  return opt;
}

Person read_person()
{
  Person person;

  printf("\nType in person's name: \n\n");
  scanf("%s", person.name);

  printf("\nType in person's birthday(dd mm yyyy)\n");
  scanf("%d %d %d", &person.date.day, &person.date.month, &person.date.year);

  return person;
}

void print_person(Person person)
{
  printf("\nName: %s\n", person.name);
  printf("Date: %2d/%2d/%4d\n", person.date.day, person.date.month, person.date.year);
}

void print_stack(Stack *top)
{
  printf("\n--------Start--------");
  while(top)
  {
    print_person(top->person);
    top = top->next;
  }
  printf("\n---------End---------");
}

Stack *push(Stack *top)
{
  Stack *new = malloc(sizeof(Stack));

  if(new)
  {
    new->person = read_person();
    new->next = top;
    return new;
  }
  else
    printf("No memory available");
  
  return NULL;
}

Stack *pop(Stack **top)
{
  if(*top != NULL)
  {
    Stack *remove = *top;
    *top = remove->next;
    return remove;
  }
  else
    printf("No elements on the Stack");

  return NULL;
}
