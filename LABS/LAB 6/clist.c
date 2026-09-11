/*#include <stdio.h> 
#include <stdlib.h>
#include "clist.h" 

void init(clist_t *ptr_clist)
{
	ptr_clist->current_ = NULL;
}

void add(clist_t *ptr_clist, int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	if(temp == NULL)
	{
		printf("full\n"); exit(1);
	}
	if(ptr_clist->current_ == NULL)
	{
		ptr_clist->current_ = temp;
		temp->next_ = temp;
	}
	else 
	{
		temp->next_ = ptr_clist->current_->next_;
		ptr_clist->current_->next_ = temp;
	}
	ptr_clist->current_ = ptr_clist->current_->next_;
} 


void disp(clist_t *ptr_clist)
{
	node_t* pres = ptr_clist->current_;
	if(pres != NULL)
	{
		do 
		{
			pres = pres->next_;
			printf("%d ", pres->key_);
		} 	while(pres != ptr_clist->current_);
	}
	printf("\n");
	
}

// TODO : delete all the nodes
void deinit(clist_t *ptr_clist)
{
    while (ptr_clist->current_ != NULL)
    {
        delete(ptr_clist);
    }
}
// TODO : add this function 
int delete(clist_t *ptr_clist)
{
    if (ptr_clist->current_ == NULL)
    {
        return -1;
    }

    node_t* target = ptr_clist->current_->next_;
    int deleted_key = target->key_;

    // Only 1 node left in list
    if (target == ptr_clist->current_)
    {
        free(target);
        ptr_clist->current_ = NULL;
    }
    else
    {
        ptr_clist->current_->next_ = target->next_;
        free(target);
    }

    return deleted_key;
 
    
}
// TODO : move k-1 times
void find_kth(clist_t* ptr_list, int k)
{
    if (ptr_list->current_ == NULL)
    {
        return;
    }

    for (int i = 0; i < k - 1; ++i)
    {
        ptr_list->current_ = ptr_list->current_->next_;
    }
}*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"

void init(clist_t *ptr_clist)
{
    ptr_clist->current_ = NULL;
}

void add(clist_t *ptr_clist, int key, const char *name)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->key_ = key;
    strncpy(temp->name_, name, NAME_LEN - 1);
    temp->name_[NAME_LEN - 1] = '\0';

    if (ptr_clist->current_ == NULL)
    {
        ptr_clist->current_ = temp;
        temp->next_ = temp;
    }
    else 
    {
        temp->next_ = ptr_clist->current_->next_;
        ptr_clist->current_->next_ = temp;
        ptr_clist->current_ = temp;
    }
}

void disp(clist_t *ptr_clist)
{
    node_t* pres = ptr_clist->current_;
    if (pres != NULL)
    {
        do 
        {
            pres = pres->next_;
            printf("[%d: %s] ", pres->key_, pres->name_);
        } while (pres != ptr_clist->current_);
    }
    printf("\n");
}

void find_kth(clist_t* ptr_list, int k)
{
    if (ptr_list->current_ == NULL)
    {
        return;
    }

    for (int i = 0; i < k - 1; ++i)
    {
        ptr_list->current_ = ptr_list->current_->next_;
    }
}

void delete(clist_t *ptr_clist, char *out_name, int *out_key)
{
    if (ptr_clist->current_ == NULL)
    {
        return;
    }

    node_t* target = ptr_clist->current_->next_;

    if (out_key != NULL)
    {
        *out_key = target->key_;
    }
    if (out_name != NULL)
    {
        strncpy(out_name, target->name_, NAME_LEN);
    }

    if (target == ptr_clist->current_)
    {
        free(target);
        ptr_clist->current_ = NULL;
    }
    else
    {
        ptr_clist->current_->next_ = target->next_;
        free(target);
    }
}

void deinit(clist_t *ptr_clist)
{
    while (ptr_clist->current_ != NULL)
    {
        delete(ptr_clist, NULL, NULL);
    }
}
