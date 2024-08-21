#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int value;
    int frequency;
    struct node* next;
}node;


node* empty(){

    node* root=NULL;
    return root;

}

void add(node** root,int value){

node* temp=malloc(sizeof(node));
temp->next=*root;
temp->value=value;

*root=temp;

}

void print_node(node** root){



for(node* curr=root;curr!=NULL;curr=curr->next){

    printf(" '%d' ",curr->value);


}
printf("\n");
}


void doubles_sorted(node** root)
{
int i=0;

     if (*root == NULL || (*root)->next == NULL) {
        return;
    }
    int swapped;
    node* ptr1;
    node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *root;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);


    for (node* curr = *root; curr != NULL; curr = curr->next)
        {
            node* prev = curr;
            for (node* curr2 = curr->next; curr2 != NULL; curr2 = curr2->next)
                {
                    if (curr2->value == curr->value)
                        {
                        node* to_remove = curr2;
                        prev->next = curr2->next;
                        curr2 = prev;
                        free(to_remove);
                    }
                    else
                    {
                        prev = curr2;
                    }
                }
        }
}

int isSubList(node* list1, node* list2) {
    if (list1 == NULL || list2 == NULL) {
        return 0;
    }
    node* ptr1 = list1;
    node* ptr2 = list2;
    while (ptr2 != NULL) {
        if (ptr1 == NULL) {
            return 0;
        }
        if (ptr1->value == ptr2->value) {
            ptr2 = ptr2->next;
        }
        else {
            ptr2 = list2;
        }
        ptr1 = ptr1->next;
    }
    return 1;
}

bool unic(node* root){
int a=root->value;
    for(node* curr=root->next;curr!=NULL;curr=curr->next){
        if(curr->value != a){
            return false;
        }
    }
return true;
}

int kthSmallestElement(node* queue, int k) {

    node* tempQueue = NULL;


    while (k > 0) {

        int smallest = queue->value;
        node* curr = queue->next;
        while (curr != NULL) {
            if (curr->value < smallest) {
                smallest = curr->value;
            }
            curr = curr->next;
        }


        node* prev = NULL;
        curr = queue;
        while (curr != NULL) {
            if (curr->value == smallest) {
                if (prev == NULL) {
                    queue = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
        }


        node* newNode = (node*)malloc(sizeof(node));
        newNode->value = smallest;
        newNode->next = tempQueue;
        tempQueue = newNode;


        k--;
    }


    int kthSmallest = tempQueue->value;


    node* temp;
    while (tempQueue != NULL) {
        temp = tempQueue;
        tempQueue = tempQueue->next;
        free(temp);
    }

    return kthSmallest;
}

node* sort_by_frequency(node* head) {

    node* curr = head;
    while (curr != NULL) {
        int freq = 0;
        node* temp = head;
        while (temp != NULL) {
            if (temp->value == curr->value) {
                freq++;
            }
            temp = temp->next;
        }
        curr->frequency = freq;
        curr = curr->next;
    }


    node* new_head = NULL;
    while (head != NULL) {
        node* max_node = head;
        curr = head;
        while (curr != NULL) {
            if (curr->frequency > max_node->frequency) {
                max_node = curr;
            }
            curr = curr->next;
        }

        if (max_node == head) {
            head = head->next;
        } else {
            curr = head;
            while (curr->next != max_node) {
                curr = curr->next;
            }
            curr->next = max_node->next;
        }

        max_node->next = new_head;
        new_head = max_node;
    }
    return new_head;
}
void main()
{

node* root=empty();
node* root2=empty();
add(&root,1);
add(&root,2);
add(&root,3);
add(&root,3);
add(&root,4);
add(&root,4);
add(&root,4);


add(&root2,1);
add(&root2,2);
add(&root2,3);
add(&root2,4);
//add(&root,90);
//add(&root,6);
//add(&root,90);
print_node(root);
//doubles_sorted(&root);
print_node(root);

if(unic(root)){
    printf("yes\n");
}else{
    printf("no\n");
}
if (isSubList(root, root2)) {
        printf("list1 is a sublist of list2\n");
    }
    else {
        printf("list1 is not a sublist of list2\n");
    }
print_node(root);

//int a=kthSmallestElement(temp,3);
 root=sort_by_frequency(root);
print_node(root);
//printf("%d",a);
}
