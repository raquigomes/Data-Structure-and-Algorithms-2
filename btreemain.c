#include "btree.h"

int main()
{	
	struct btree *bt = open_btree();

	size_t len = 0;
	ssize_t read;

	char *buf;
	char *res;

	while ((read = getline(&buf, &len, stdin)) != -1)
	{	
		res = strtok(buf,"\n");
		
		btree_insere(bt, res);
	}
	close(bt->fd);
	free(bt);


	//struct btree *b = malloc(sizeof( struct btree));
	/*bt->fd = open("words_en.txt",O_RDONLY);	

	FILE *fp = fopen("words_en.txt","r");
	
	while ((read = getline(&buf, &len, fp)) != -1)
	{	
		res = strtok(buf,"\n");
	//	printf("%d\n", res[strlen(res)+1]);
		//strcat(res,"\0");	
	}
	fclose(fp);
	
	free(b);
		int i = 0;
		
	while(fgets(buf,sizeof(buf),fp)){
		//getline( &buf, &len, fp );
		//printf("%s\n",buf );
		btree_insere(bt,buf);

		//printf("Y\n");
	}
	*/
	//btree_close(bt);

	return 0;
}

