#ifndef HT_H
#define HT_H

#define HT_PRIME_1 151
#define HT_PRIME_2 171
#define HT_INITIAL_BASE_SIZE 53

typedef struct {
  char * key;
  char * value;
} ht_item;

typedef struct {
  int size;
  int count;
  ht_item ** items;
  int base_size;
} ht_hash_table;

static ht_item*		ht_new_item (const char*, const char*);
static void		ht_del_item (ht_item*);
static int		ht_hash (const char*, const int, const int);
static int		ht_get_hash (const char*, const int, const int);
static ht_hash_table*	ht_new_sized (const int);
static void		ht_resize (ht_hash_table *, const int);
static void             ht_resize_up(ht_hash_table *);
static void             ht_resize_down(ht_hash_table*);

ht_hash_table*  ht_new();
void		ht_del_hash_table(ht_hash_table*);
void		ht_insert(ht_hash_table *, const char *, const char *);
char*		ht_search(ht_hash_table *, const char *);
void		ht_delete(ht_hash_table *, const char *);

#endif
