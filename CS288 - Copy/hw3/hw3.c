#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 100

void build_a_lst(),print_a_line(),print_lst();
void insert_at_end();

struct clip {
  int views;
  char *user;
  char *id;
  char *title;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  build_a_lst(*(argv+1));
  print_lst(head);		/* prints all the users */

  return 0;
}

void build_a_lst(char *fn) {
  FILE *fp;
  char line[LINE_LENGTH];
  //  char *line;
  if ((fp = fopen("users.txt","r")) != NULL) {
    while (fgets(line, LINE_LENGTH, fp) != NULL) {
      insert_at_end(line);	/* insert a user at end of the list */
    }
    fclose (fp);
  }
}

void insert_at_end(char *s)
{
  struct clip *cp, *tp;
  tp=malloc(sizeof(struct clip));
  tp->next=NULL;
  tp->user = malloc(strlen(s));
  strcpy(tp->user, s);
  if (head==NULL)
  {
    head=tp;
  }
  else
  {
    cp=head;
    while (cp->next!=NULL)
      {
	cp=cp->next;
      }
    cp->next=tp;
  }
  
}

/* prints all the users */
void print_lst(struct clip *cp) {
  while (cp->next!=NULL)
    {
      printf("%s",cp->user);
      cp=cp->next;
    }
}

/* end */
