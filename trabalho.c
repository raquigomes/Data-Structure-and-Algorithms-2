#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

//trie
void *readTrie(char *words_en.txt)
{
    FILE *file = fopen(words_en.txt);
    //char *word = malloc(100);
    //int index = 0;
    //int c;
    
    fclose(file);
}

trie *nova_trie() {

  trie*t = malloc(sizeof(trie));
  t->father = NULL;
  t->existe =0; 

  int j; 
  for (j=0; j <Nel; j++){
    t->prox[j] = NULL; 
  }

  return t;
}

void insere_trie(trie *t, char *chave)
{

  int i;
  if (*chave==0) {
    t->existe =1;
  }
  else {

    if (t->prox[*chave - Minel]==NULL) {

      t->prox[*chave - Minel]= malloc(sizeof(trie));
      t->prox[*chave - Minel]->existe=0;
      t->prox[*chave-Minel]->father = t;

      for (i=0;i<Nel;i++) {
        t->prox[*chave - Minel]->prox[i]=NULL; 
      }
    }
    insere_trie(t->prox[*chave-Minel],chave+1);
  }
}

int existe_trie (trie *t, char *chave){
  
  if (!*chave){
    return t->existe;  
  }

  else if (t->prox[*chave - Minel]==NULL){
    return 0;
  }

  else {
    return existe_trie(t->prox[*chave - Minel], chave+1);
  }

}

void remover_trie(trie *t, char *chave)
{
  trie *no = t;
  int x = 0;
  
  while (no != NULL && chave[x])   
  {
    
    no = no->prox[chave[x] - Minel];
    x++;
  }

  if (no != NULL && no->existe)
  {
    no->existe = 0;

    int empty = 1;
    do
    {
      x--;
      
      int j;
      for (j = 0; j < Nel; j++)
      {
        if (no->prox[j] != NULL)
          empty = 0;
      }

      if (empty)
      {
        trie *f = no->father;

        if (f != NULL)
        {
          int x = chave[x] - Minel;
          f->prox[x] = NULL;
        }

        free(no);
        no= f;
      }

    } while (no != NULL && empty && !no->existe);
  }
}

void destroy_trie(trie *t){
	
	int i;
	for (i=0; i<Ne; i++){
		if (t->prox[i]==NULL){
			destroy_trie(t->prox[i]);
		}
	}
}







//btree
struct btree {
  int leaf; 
  int n; 
  char *key[maxkeys]; 
  struct btree *child[maxchildren];
};


btree new_node()
{
    return ((BTREE)malloc(sizeof(NODE)));
}


btree create_tree(DATA a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return(init_node(a[i],
    create_tree(a, 2*i+1, size),
    create_tree(a, 2*i+2, size)));
}

void btree_nova(btree **t); 


void btree_insere(btree **t, char k[]);


void btree_remover();


int pesquisa(btree *t, int v)
{
  int i;

  /* pesquisar na raiz até encontrar v ou um maior que v */
  for (i=0; i < t->n; i++) {
    if (t->chave[i] == v) { /* encontrou */
      return 1;
    }
    else if (t->chave[i] > v) { 
      break;
    }
  }
  
  if (t->folha) return 0;
  else return pesquisa(t->filho[i], v);
}

