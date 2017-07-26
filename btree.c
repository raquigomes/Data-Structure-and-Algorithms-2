#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "btree.h"

#define T 3
#define TRUE 1
#define FALSE 0

struct btree 
{
	int fd;                  //file descriptor do ficheiro onde se encontra a b-tree
	struct node *root;       //raíz da b-tree

	int size;             //tamanho da btree
};


struct no *no_novo()
{
	struct no *no = malloc(sizeof(struct node));
	no->n = 0;
	no->leaf = TRUE;
	return no;
}

struct btree *btree_nova()
{
	struct btree *bt = malloc(sizeof(struct btree));
	struct no *no = new_no();
	node->leaf = TRUE;
	bt->root = no;
	bt->size = 1;

	return bt;
}


struct btree *open_btree()
{
	//int status;
	struct btree *bt = btree_nova();
	
	bt->fd = open("novo.dat", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
                    
	//printf("file descriptor: %d\n", bt->fd);
	
	if (bt->fd == -1)
	{
		//free para limpar mem
		perror("cant open or create file");
		return NULL; 
	}

	/*
	status = read_root(bt);
	
	//printf("Estou aqui status: %d\n", status);
	
	if (status == -1)
	{
		free
		perror("Cant read file");
		return NULL;
	}

	if (status == 0)
	{
		bt->root.head = 0;
		bt->root.used = 0;                          esta parte vai para o disck write e disk read
		status = write_root(bt);
		//printf("E aqui!\n");
		
		if (status == -1)
		{
			perror("Cant write file");
			return NULL;
		}
		else { //printf("TA tudo bem\n") };
	}
	*/
	return bt;
}

/*
void split_child(struct btree *bt, struct node *node, int index, int nodeIndex)
{
	struct node *childNode = disk_read(bt, node->child[index]); 
	struct node *newNode = new_node();
	bt->size++;
	
	newNode->leaf = childNode->leaf;
	newNode->n = T-1;
	
	for (int j = 0; j < T-1; j++)
		strcpy(newNode->element[j].word, childNode->element[j + T].word);
	
	if (childNode->leaf == FALSE)
	{
		for (int j = 0; j < T; j++)
			newNode->child[j] = childNode->child[j + T];
	}
	
	childNode->n = T - 1;
	
	for (int j = node->n; j >= index+1; j--) 
		node->child[j + 1] = node->child[j];
	
	node->child[index + 1] = bt->size; //size corresponde à localização do newNode, uma vez que foi o ultimo nó criado;
	
	for (int j = node->n - 1; j >= index; j--)
		strcpy(node->element[j + 1].word, node->element[j].word);
	
	
	strcpy(node->element[index].word, childNode->element[T].word);
	node->n++;
	
	//printf("\n3\n");
	disk_write(bt, childNode, node->child[index]);
	//free(childNode);
	//printf("\n2\n");
	disk_write(bt, newNode, node->child[index + 1]);
	//free(newNode);
	//printf("\n1\n");
	disk_write(bt, node, nodeIndex);
	//free(node);
	free(newNode);
	free(childNode);
}
*/
void btree_insert(struct btree *bt, char *word)
{
	struct node *root = bt->root;
	//printf("ola tou aqui\n");
	if (root->n == 2*T - 1)                   //verifica se a raíz está cheia
	{
		struct node *newNode = new_node();
		newNode->leaf = FALSE;
		newNode->n = 0;
		newNode->child[0] = bt->rootPos;    //atribui a pos da raiz anterior oa filho da nova raiz
		free(root);
		bt->root = newNode;                 
		bt->size++;                        //incrementa o tamanho da btree 
		bt->rootPos = bt->size;           //atribui a nova pos da raíz 
		
		disk_write(bt, newNode, bt->rootPos);       
		//free(newNode);
		//printf("\nraiz cheia\n");
		split_child(bt, bt->root, 0, bt->rootPos);
		insert_nonfull(bt, bt->root, word, bt->rootPos);
		//free(newNode);
	}
	
	else {
		//printf("\nraiz não cheia\n"); 
		insert_nonfull(bt, root, word, bt->rootPos); 
	}
	//free(root);
}

int pesquisa(btree *t, int v)
{
  int i;
  for (i=0; i < t->n; i++) {
    if (t->chave[i] == v) {
      return 1;
    }
    else if (t->chave[i] > v) { 
      break;
    }
  }
  
  if (t->folha) return 0;
  else return pesquisa(t->filho[i], v);
}


