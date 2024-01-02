
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Node Stucture 
typedef struct node_t {
  int data;
  struct node_t *next;
} Node;

//Function Declarations
Node * insert_top(int, Node *);
Node * insert_bottom(int, Node *);
Node * insert_anywhere(int num, int position, int target_num, Node *head);
Node * delete_first(Node *);
Node * delete_last(Node *);
Node * delete_anyone(int, Node *);
Node * search(int, Node *);
void print(Node *);
int count(Node *);

//Add a new node to the top of a list
Node * insert_top(int num, Node *head) {
    Node *new_node;
    new_node = (Node *) malloc(sizeof(Node));
 	new_node->data = num;
 	new_node->next= head;
 	head = new_node;
	return head;
}


//Add a new node to the bottom of a list
Node * insert_bottom(int num, Node *head) {
  	Node *current_node = head;
  	Node *new_node;
  	while ( current_node != NULL && current_node->next != NULL) {
   		current_node = current_node->next;
  	}

  	new_node = (Node *) malloc(sizeof(Node));
  	new_node->data = num;
  	new_node->next= NULL;
  	if (current_node != NULL)
    	current_node->next = new_node;
  	else
     	head = new_node;
return head;
}




//Add a new node before or after an element in the list
Node * insert_anywhere(int num, int position, int target_num, Node *head) {
    Node *current_node = head;
    Node *new_node;
    while (current_node != NULL && current_node->data != target_num) {
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("The target number %d was not found in the list.\n", target_num);
        return head;
    }

    new_node = (Node *) malloc(sizeof(Node));
    new_node->data = num;

    if (position == 1) { // Insert before
        if (current_node == head) {
            new_node->next = head;
            head = new_node;
        } else {
            Node *prev_node = head;
            while (prev_node->next != current_node) {
                prev_node = prev_node->next;
            }
            prev_node->next = new_node;
            new_node->next = current_node;
        }
    } else if (position == 2) { // Insert after
        new_node->next = current_node->next;
        current_node->next = new_node;
    } else {
        printf("Invalid position. Please enter 1 to insert before or 2 to insert after.\n");
        return head;
    }

    printf("Number %d inserted %s %d in the list", num, (position == 1) ? "before" : "after", target_num);
    return head;
}


//Delete the first node
Node * delete_first(Node *head) 
{ 
    if (head == NULL) 
        return NULL; 
  
    // Move the head pointer to the next node 
    Node *temp = head; 
    head = head->next; 
  
    free(temp); 
  
    return head; 
}

Node *delete_last(Node *head) {
    if (head == NULL)
        return NULL;

    // If there is only one node in the list, 
	//delete it and return NULL.
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    // Update the previous node's next 
	//pointer to NULL.
    prev->next = NULL;

    // Free the last node.
    free(curr);

    return head;
}

//Delete any node
Node *delete_anyone(int num, Node *head){
	if (head == NULL)
    	return NULL;
	
	Node *curr = head;
	Node *prev = NULL;
	
	for (curr = head, prev = NULL;
	curr != NULL && curr->data != num;
	prev = curr, curr = curr->next)
	;
	if (curr == NULL)
		return head; /* n was not found */
	if (prev == NULL)
		head = head->next; /* n is in the first node */
	else
		prev->next = curr->next; /* n is in some other node */
	free(curr);
	return head;
}

//Search for specific node
Node *search(int n, Node *list)
{ 
	Node *p;
	for (p = list; p != NULL; p = p->next)
		if (p->data == n)
			return p;
	return NULL;
}

//Print all the elements in the linked list
void print(Node *head) {
  Node *current_node = head;
  while ( current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
}

//Program main 
int main()
{
   Node *head = NULL;
   int num, prev_num, next_num;
   int option;
   char * temp;
   char ch;
   //Display Menu
   while(1) {

     printf("\n ==================\n");
     printf("\n1) Display         \n");
     printf("\n2) Insert First    \n");
     printf("\n3) Insert Last     \n");
	 printf("\n4) Insert Anywhere \n");
     printf("\n5) Delete First    \n");
     printf("\n6) Delete Last     \n");
	 printf("\n7) Delete Anyone   \n");
	 printf("\n8) Search          \n");
     printf("\n0) Quit            \n");
     printf("\nEnter your choice: ");
     if (scanf("%d", &option) != 1) {
        printf("Error: Invalid input. Try again.\n");
        scanf("%s", &temp); //clear input buffer 
        continue;
     }

     switch (option) {
      case 1:    //Print
          printf("\nElements in the list: \n [ ");
          print(head);
          printf("]\n\nPress any key to continue...");
          getch();
		  break;

      case 2:    //add to top
	      printf(" Enter a number to insert : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              scanf("%s", &temp);   //clear input buffer 
              continue;
          }
          head = insert_top(num, head);
          printf("Number %d added to the top of the list", num);
          printf("\nPress any key to continue...");
          getch();
          break;


      case 3:    //Insert Last
	      printf(" Enter a number to insert : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input. \n");
              scanf("%s", &temp); 
              continue;
          }
          head = insert_bottom(num, head);
          printf("%d added to the bottom of the list", num);
          printf("\nPress any key to continue...");
          getch();
          break;


      case 4:    //Insert anywhere
          printf("Enter a number to insert: ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              scanf("%s", &temp);   //clear input buffer 
              continue;
          }
		  
		  if(head == NULL){
		  	  printf("%d was added to the list", num);
			  printf("\nPress any key to continue...");
			  head = insert_top(num, head);
			  getch();
			  break;
		  }

          printf("Before or after the target number? (1 for before, 2 for after): ");
          if (scanf("%d", &prev_num) != 1 || (prev_num != 1 && prev_num != 2)) {
              printf("Invalid selection. Please enter 1 to insert before or 2 to insert after.\n");
              scanf("%s", &temp);   //clear input buffer
              continue;
          }

          printf("Enter the target number: ");
          if (scanf("%d", &next_num) != 1) {
              printf("Error: Invalid input.\n");
              scanf("%s", &temp);   //clear input buffer
              continue;
          }

          if (head != NULL) {
              head = insert_anywhere(num, prev_num, next_num, head);
          }
          printf("\nPress any key to continue...");
          getch();
          break;

      case 5: //Delete First
          if (head == NULL) {
              printf("List is empty.\n");
			  printf("\nPress any key to continue...");
			  getch();
              continue;
          }
          head = delete_first(head);
          printf("First element in the list has been deleted");
          printf("\nPress any key to continue...");
          getch();
          break;

      case 6:  //Delete Last
          if (head == NULL) {
              printf("List is empty.\n");
			  printf("\nPress any key to continue...");
			  getch();
              continue;
          }
		  
          head = delete_last(head);
          printf("Last element in the list has been deleted");
          printf("\nPress any key to continue...");
          getch();
          break;
		  
	  case 7: //Delete anyone
	      if (head == NULL) {
              printf("List is empty.\n");
			  printf("\nPress any key to continue...");
			  getch();
              continue;
          }
	  	  printf(" Enter a number to delete : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              scanf("%s", &temp);   //clear input buffer
              continue;
          }
		  
		  if(search(num, head) == NULL){
		  	  printf("%d is not in the list", num);
		      printf("\nPress any key to continue...");
			  getch();
              continue;
		  }
		  
          head = delete_anyone(num, head);
          printf("Number %d has been deleted the list", num);
          printf("\nPress any key to continue...");
          getch();
          break;
		  
	  case 8: //Search List
	  	  printf("Enter a number to search : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              scanf("%s", &temp);   //clear input buffer
              continue;
          }
		  
		  Node *result = search(num, head);

		  if (result != NULL) {
		      printf("The number %d was found in the list.\n", num);
			  printf("\nPress any key to continue...");
			  getch();
          	  break;
		  } else {
		      printf("The number %d was not found in the list.\n", num);
			  printf("\nPress any key to continue...");
			  getch();
              break;
		  }
		  
	  case 0: //Exit
          return(0);
          break;

      default:
          printf("Invalid Option. Please Try again.");
          getch();

      } //End of Switch
   } //End of While

return(0);
}

