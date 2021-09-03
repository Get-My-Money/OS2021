#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
   int data;
   struct node *next;
} node;


void print_list(struct node *head) {

  struct node *cur = head->next;

  while(cur != NULL) {
    printf("%d",cur->data);
    cur = cur->next;
    printf("\n");
  }	
}


void add_element(struct node *head, int value){

  if (head->next == NULL){
    head->next = (struct node*) malloc(sizeof(struct node));
    head->next->data = value;
    }

  else{
    node *curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = malloc(sizeof(node));
		curr->next->data = value;
		curr->next->next = NULL;
  }
          
}


void insert_node(struct node *head, int prevvalue, int newvalue){

  struct node *cur = head->next;

  while(cur != NULL){
    if(cur->data == prevvalue){

      struct node *newnode = (struct node*) malloc(sizeof(struct node));
      newnode->data = newvalue;
      newnode->next = cur->next;
      cur->next = newnode;
      return;
    }

    cur = cur->next;
  }   
}


void delete_node(struct node *head, int index){

  struct node *cur = head->next;

  if(index < 0) 
		printf("ERROR: Wrong index\n");
  else{
    if(cur != NULL){

      int i = 1;
			while (i < index && cur->next != NULL){
				cur = cur->next;
        i++;
      }

		if(cur->next != NULL){
			if(index != 0){
				node* temp1 = cur->next->next;
				free(cur->next);
				cur->next = temp1;
			}

      else{
				node* temp2 = head->next;
				free(head);
				head = temp2;
				}

      }
		}
	}
}


int main(){

    struct node *ex = (struct node*) malloc(sizeof(struct node));
    

    ex->next = NULL;
     
     
    add_element(ex, 10);
    add_element(ex, 15);
    add_element(ex, 6);
    add_element(ex, 8);
    printf("Initial structure:\n"); 
    print_list(ex);


    insert_node(ex, 15, 78);
    printf("Insert node after node2:\n");
    print_list(ex);


    delete_node(ex, 3);
    printf("Delete node4:\n");
    print_list(ex);


    return 0;
}