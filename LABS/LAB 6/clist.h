/*#ifndef CLIST_H
#define CLIST_H 
struct node 
{
	int key_;
	struct node *next_;
};
typedef struct node node_t;

struct clist 
{
	node_t* current_; 
};
typedef struct clist clist_t;

void init(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key);
void disp(clist_t *ptr_list);

// implement the following
void deinit(clist_t *ptr_list);  
int delete(clist_t *ptr_clist);
void find_kth(clist_t* ptr_list, int k);
#endif
*/












#ifndef CLIST_H
#define CLIST_H

#define NAME_LEN 15

struct node 
{
    int key_;
    char name_[NAME_LEN];
    struct node *next_;
};
typedef struct node node_t;

struct clist 
{
    node_t* current_; 
};
typedef struct clist clist_t;

void init(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key, const char *name);
void disp(clist_t *ptr_clist);
void deinit(clist_t *ptr_clist);  
void delete(clist_t *ptr_clist, char *out_name, int *out_key);
void find_kth(clist_t* ptr_list, int k);

#endif