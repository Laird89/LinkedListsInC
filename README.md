# LinkedListsInC

Secone assignment in Data Structures and Algortithms in C.

October 20, 2023

**1. Overview:**
   - The C project involves the implementation of basic operations on a singly linked list.
   - Users can perform operations like insertion, deletion, searching, and display on the linked list.

**2. Key Features:**

   - **Node Structure:**
     - Defines a node structure with an integer data field and a pointer to the next node.
     - Struct is named `node_t`.

   - **Insertion Operations:**
     - **Insert at Top:**
       - Inserts a new node at the beginning of the list.
       - Function: `insert_top(int num, Node *head)`

     - **Insert at Bottom:**
       - Inserts a new node at the end of the list.
       - Function: `insert_bottom(int num, Node *head)`

     - **Insert Anywhere:**
       - Inserts a new node before or after a specified target number.
       - Function: `insert_anywhere(int num, int position, int target_num, Node *head)`

   - **Deletion Operations:**
     - **Delete First:**
       - Deletes the first node in the list.
       - Function: `delete_first(Node *head)`

     - **Delete Last:**
       - Deletes the last node in the list.
       - Function: `delete_last(Node *head)`

     - **Delete Anywhere:**
       - Deletes a node with a specified number.
       - Function: `delete_anyone(int num, Node *head)`

   - **Search Operation:**
     - Searches for a specified number in the list.
     - Function: `search(int n, Node *list)`

   - **Display Operation:**
     - Prints all the elements in the linked list.
     - Function: `print(Node *head)`

   - **Count Operation:**
     - Counts the number of elements in the linked list.
     - Function: `count(Node *head)`

   - **Menu-Driven Interface:**
     - Provides a user-friendly menu for selecting different operations.
     - Implemented using an infinite loop until the user chooses to exit.

**3. Usage:**
   - Users can interact with the program through the console, selecting options to perform various operations on the linked list.

**4. Input Validation:**
   - Ensures that only valid numerical inputs are accepted.
   - Provides appropriate feedback for incorrect input types.

**5. Dynamic Memory Allocation:**
   - Allocates memory dynamically for new nodes during insertion operations.
   - Ensures proper memory deallocation during deletion operations.

**6. Error Handling:**
   - Handles scenarios such as empty lists, unsuccessful searches, and invalid inputs gracefully.
   - Prompts users with appropriate messages for better interaction.

**7. Continuous Execution:**
   - Program runs continuously until the user chooses to exit, allowing multiple operations in a single run.

**8. Conclusion:**
   - The project provides a practical implementation of basic linked list operations in C.
   - It serves as a learning tool for understanding linked list manipulation and dynamic memory allocation.
   - The menu-driven interface enhances user experience and ease of interaction.
