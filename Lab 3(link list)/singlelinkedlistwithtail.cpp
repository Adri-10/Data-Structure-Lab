#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * head;
struct listNode * tail;

void initializeList()
{
    head = 0;  //initially set to NULL
	tail = 0;
}

//The following function inserts the item in front of the list
int insertItem(int item) //insert at the beginning
{
    //Write your code here. Make sure to handle tail pointer.
    struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head;
	head = newNode;
	if(tail==0)
    {
        tail=newNode;
    }
	return SUCCESS_VALUE ;
}

//The following function deletes the item from the list
int deleteItem(int item)
{
    //Write your code here. Make sure to handle tail pointer.
     struct listNode *temp, *prev ;
	temp = head ;
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ;

	if (temp == 0) return NULL_VALUE ;
	if (temp == head)
	{
		head= head->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		if(prev->next==0)
            tail=prev;
		    free(temp);
	}
	}
	return SUCCESS_VALUE ;
}


//The following function returns the address of the item in the list. If the item is not present, it returns 0 or null pointer.
struct listNode * searchItem(int item)
{
    //Write your code here.
     struct listNode * temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ;
		if(head->item==item)
    {
        return head;
    }}
    if(tail->item==item)
    {
       return tail;
    }
	return 0 ;
}

void printList()
{
    struct listNode * temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

//The following function inserts item at the end of the list
int insertLast(int item)
{
    //write your codes here
struct listNode *newNode ;
   newNode = (struct listNode*) malloc (sizeof(struct listNode));
   newNode->item =item ;

    if(head==NULL)
    {
       head=newNode;
       tail=newNode;
       newNode->next=NULL;
    }
        tail->next =newNode;
        newNode->next=NULL;
        tail=newNode;
        return SUCCESS_VALUE;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. InsertLast. 5. Print. 6. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d",&item);
            insertLast(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}

