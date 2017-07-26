#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define T 3
#define MAX_STR_LENGTH 28
#define TRUE 1
#define FALSE 0

struct element 
{
	char word[MAX_STR_LENGTH];
};

struct no 
{
	int n;
	struct element element[2*T-1];
	int child[2*T];
	int leaf;
	
};

struct btree 
{
	int fd;
	struct no *root;
	int size;
};

no *no_novo();
btree *btree_nova();
btree *open_btree();
void btree_insere();
void btree_destroy();
int btree_existe();

