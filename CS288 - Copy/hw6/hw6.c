//Vladimir Ventura
//CS288 hw6
//Due Date.... well,It's late
//Last modified 5/5/2013
//I keep getting a memory error in expand
/*UPDATE: 5/10/2013 So we were given more time? I did A* search. I got the idea during the exam, actually... hahah... so yea.
//UPDATE: 5/12/2013: I give up. I can't understand how expanded is giving me an error. Maybe it's because I'm sending a dereferenced ptr to swap... but then why does it not give me an error about that, instead of expanded not being initialized?
//So yea, sorry..
/******************************************************************************
 CS288 HW6 three search strategies: depth, breadth, and intelligent
 command example: command 16 numbers and search strategy
   fifteen 1 2 3 4 5 6 7 8 9 10 11 12 13 14 0 15 {dfs|bfs|astar}
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BF 4			/* Branching factor of the search tree */
#define N 4			/* fix to fifteen puzzle but should be */
#define NxN 16			/* able to handle any size */

#define DFS 0                   /* depth first search */
#define BFS 1                   /* breadth first search */
#define BEST 2                  /* best first search */
#define BB 3                    /* branch and bound */
#define ASTAR 4                 /* A* search */

struct node {
  int loc[N+1][N];		/* the last row holds f, g and h */
  struct node *next;
};
struct node *start,*goal;
struct node *initialize(),*expand(),*merge(),*filter();
struct node *insert_front(),*insert_end(),*insert_by_h(),*insert_by_g(),*insert_by_f();
char strategy[10];

int TRUE = 1;
int FALSE = 0;
int up(),dn(),lt(),rt(),goal_found(),expand_a_node(),nodes_same(),find_h(),count(),getManhattanDistance();
void swap(),print_a_node(),print_nodes();
int flag;

int main(int argc,char **argv) {
  int iter,cnt,total;
  struct node *tsucc,*csucc,*copen,*topen,*open,*closed,*succ;

  open=closed=succ=NULL;
  start=initialize(argc,argv);	/* init initial and goal states */
  open=start; 
  iter=0; total=1;
  while (open!=NULL) {		/* Termination cond is tested in expand. */
      copen=open;
      open=open->next; /* get the first node from open to expand */
      succ=expand(copen);       /* Find new successors */
      succ=filter(open,succ);   /* New succ list */
      succ=filter(closed,succ); /* New succ list */
      if (goal_found(succ,goal)==TRUE) break;
      cnt=count(succ);
      total=total+cnt;
      if (succ!=NULL) open=merge(succ,open,flag); /* New open list */
      copen->next=closed;
      closed=copen;		/* New closed */
      iter++;
   }
   printf("%s strategy: %d iterations %d nodes\n",strategy,iter,total);
   return 0;
}				/* end of main */

int goal_found(struct node *cp,struct node *goal){ /* cp=openp */
  int flg;
  while (cp!=NULL && !nodes_same(cp->loc,goal->loc)) {
      cp=cp->next;
   }
   if (cp==NULL) flg=FALSE; else flg= TRUE;
  return flg;
}

int count(struct node *succ) {
  int cnt=0;
  while (succ!=NULL) {
    cnt++;
    succ=succ->next;
  }
  return cnt;
}

struct node *merge(struct node *succ,struct node *open,int flag) {
  struct node *csucc,*copen;
  
  if (flag==DFS) {	/* attach to the front: succ -> ... -> open */
    csucc=succ;
	while(csucc->next!=NULL)
	{
		csucc=csucc->next;
	}
	csucc->next=open;
	open=succ; //we need this since we are going to return open.
  }
  else if (flag==BFS) { /* attach to the end: open -> ... -> succ */
    copen=open;
	while(copen->next!=NULL)
	{
		copen=copen->next;
	}
	copen->next=succ;
  }


  else {	      /* Best first: insert in asc order of h value */
    //scratch what I said previously. I think i got it
    csucc=succ;
    while(csucc!=NULL)
    {
       open=insert_by_h(csucc, open);//csucc is inserted based on its H value. this assumes open is already sorted...which it is since the first open will be just one node (one node is already sorted on its own).
       csucc=csucc->next;
    }
  }
  
  csucc=NULL; copen=NULL; //bad garbage removal in C, I'll set these to NULL just in case.
  return open;
}

/* insert succ into open in ascending order of H value */
struct node *insert_by_h(struct node *succ,struct node *open) {
//.. I just realized. this says to insert succ into open. DUAH..
  struct node *copen,*prev;
  copen=open;
  prev=NULL;
  while(copen!=NULL)
  {
    if(succ->loc[N+1][2] < copen->loc[N+1][2])//succ's H<copen's H
    {
       if(prev==NULL)//it's at the beginning
       {
          succ->next=open;//we want the least H to be first.
          open=succ;
          break;
       }
       else
       {
          succ->next=prev->next;
          prev->next=succ;
          break;
       }
    }
    prev=copen; copen=copen->next;
  }  
  //if it was put in the linked list, copen will NOT be NULL due to the break.
  //but if succ's H is the largest... copen will become NULL
  if(copen==NULL)
  {
     prev->next=succ; succ->next=NULL; //the latter isnt necessary
  }
  
  return open;
}

struct node *expand(struct node *selected) {
  int i,j,k,cnt,succ_buf[BF][N+1][N];
  struct node *cp,*tp,*expanded;
  expanded=NULL;
  cnt=selected->loc[N+1][1]; //this is where g is located
  
  //put the loc into buf
  for(i=0; i<BF; i++)
    for(j=0; j<N; j++)
      for(k=0; k<N; k++)
        succ_buf[i][j][k]=selected->loc[j][k];



  //find zero.
  for(i=0;i<N; i++)
  {
    for(j=0;j<N;j++)
    {
      if(selected->loc[i][j]==0)
         break;
    }
    if(selected->loc[i][j]==0)
      break;
  }
  //we have where 0 is
  //if statements to see if down, right, up, left are legal
  //along with the statements to create the linked list.
  if(dn(i,j,succ_buf[0])==1)
  {
    tp=malloc(sizeof(struct node));
    tp->next=NULL;
    swap(i,j,i+1,j, ++cnt, (*succ_buf[0]));//swap, and update cnt
    (**tp->loc)=(**succ_buf[0]); //loc=the 2D array succ_buf[0].
    //LINES 149 169, 188, 207 need to see if ** dereferencing works
    if(expanded==NULL)
      expanded=tp;
    else
    {
      cp=expanded;
      while(cp->next!=NULL)
      {
        cp=cp->next;
      }
      cp->next=tp;
      tp=NULL;//delete tp because it may be used again below.
    }
  }
  if(rt(i,j,succ_buf[1])==1)
  {
    tp=malloc(sizeof(struct node));
    tp->next=NULL;
    swap(i,j,i,j+1, ++cnt, (*succ_buf[1]));//swap, and update cnt
    (**tp->loc)=(**succ_buf[1]); //2D array = 2D array
    if(expanded==NULL)
      expanded=tp;
    else
    {
      cp=expanded;
      while(cp->next!=NULL)
      {
        cp=cp->next;
      }
      cp->next=tp;
      tp=NULL;//delete tp because it may be used again below.
    }
  }
  if(up(i,j,succ_buf[2])==1)
  {
    tp=malloc(sizeof(struct node));
    tp->next=NULL;
    swap(i,j,i,j-1, ++cnt, (*succ_buf[2]));//swap, and update cnt
    (**tp->loc)=(**succ_buf[2]);
    if(expanded==NULL)
      expanded=tp;
    else
    {
      cp=expanded;
      while(cp->next!=NULL)//this is giving me an error... I'm  not quite sure why or why it would. . . .
      {
        cp=cp->next;
      }
      cp->next=tp;
      tp=NULL;//delete tp because it may be used again below.
    }
  }
  if(lt(i,j,succ_buf[3])==1)
  {
    tp=malloc(sizeof(struct node));
    tp->next=NULL;
    swap(i,j,i,j-1, ++cnt, (*succ_buf[3]));//swap, and update cnt
    (**tp->loc)=(**succ_buf[3]);
    if(expanded==NULL)
      expanded=tp;
    else
    {
      cp=expanded;
      while(cp->next!=NULL)
      {
        cp=cp->next;
      }
      cp->next=tp;
      tp=NULL;//delete tp because it may be used again below.
    }
  }
  //expanded now holds whichever of dwn right up left are legal moves, in that order.
  
  
  
  return expanded;//expanded is a linked list
}

//this method seems to be for finding g (number of nodes expanded= distance traveled)... ._. not useful as its own method
/*
int expand_a_node(int node[N+1][N],int succ_buf[BF][N+1][N]) {
  int i,j,cnt,found,g_val,h_val;
  //...
  return cnt;			/* number of nodes expanded */
//}

/* 0 goes down by a row */
int dn(int i,int j,int succ_buf[N+1][N]){//i,j tells where zero is.
  if(i+1<N) return 1;
  else return 0;
}

/* 0 goes right by a column */
int rt(int i,int j,int succ_buf[N+1][N]){
  if(j+1<N) return 1;
  else return 0;
}

/* 0 goes up by a row */
int up(int i,int j,int **succ_buf){
  if(i-1>=0) return 1;
  else return 0;
}

/* 0 goes left by a column */
int lt(int i,int j,int succ_buf[N+1][N]){
  if(j-1>=0) return 1;
  else return 0;
}

void swap(int i,int j,int k,int l,int index,int *succ_buf[N+1][N]){
  int temp = (int)(succ_buf[i][j]);
  (succ_buf[i][j])=(succ_buf[k][l]); //dereference, write
  (succ_buf[k][l])=temp; //dereference, write
  (succ_buf[N+1][1])=index; //g
  (succ_buf[N+1][2])=getManhattanDistance(succ_buf);//h
  (succ_buf[N+1][0])=index+(succ_buf[N+1][2]);
}
int getManhattanDistance(int succ_buf[N+1][N])
{
  int i,j,cnt;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      if(succ_buf[i][j]==1)
      	cnt+=i+j;//supposed to be in [0][0]
      else if(succ_buf[i][j]==2)//[0][1]
        cnt+=i+abs(j-1);
      else if(succ_buf[i][j]==3)//[0][2]
        cnt+=i+abs(j-2);
      else if(succ_buf[i][j]==4)//[0][3]
        cnt+=i+abs(j-3);//abs not necessary here.. but eh.
      else if(succ_buf[i][j]==5)//[1][0]
        cnt+=abs(i-1) + j;
      else if(succ_buf[i][j]==6)//[1][1]
        cnt+=abs(i-1) + abs(j-1);
      else if(succ_buf[i][j]==7)//[1][2]
        cnt+=abs(i-1) + abs(j-2);
      else if(succ_buf[i][j]==8)//[1][3]
        cnt+=abs(i-1) + abs(j-3);
      else if(succ_buf[i][j]==9)//[2][0]
        cnt+=abs(i-2) + j;
      else if(succ_buf[i][j]==10)//[2][1]
        cnt+=abs(i-2) + abs(j-1);
      else if(succ_buf[i][j]==11)//[2][2]
        cnt+=abs(i-2) + abs(j-2);
      else if(succ_buf[i][j]==12)//[2][3]
        cnt+=abs(i-2) + abs(j-3);
      else if(succ_buf[i][j]==13)//[3][0]
        cnt+=abs(i-3) + j;
      else if(succ_buf[i][j]==14)//[3][1]
        cnt+=abs(i-3) + abs(j-1);
      else if(succ_buf[i][j]==15)//[3][2]
        cnt+=abs(i-3) + abs(j-2);
      else if(succ_buf[i][j]==0)//[3][3]
        cnt+=abs(i-3) + abs(j-3); 
    }
  }
  
  return cnt;
}

struct node *filter(struct node *hp,struct node *succ){ 
  struct node *cp, *scp, *prev;
  cp=hp;
  while(cp!=NULL)
  {
    scp=succ;
    while(scp!=NULL)
    {
      if(nodes_same(scp->loc, cp->loc))//if they are the same state
      {
        if(prev==NULL)
        {
          succ=scp->next; //deletes the first node in linked list
        }
        else{
          prev->next=scp->next; //delete any pointers to this node
        }
        prev=scp;
        scp=scp->next;
        prev->next=NULL;
        prev=NULL;
      }
      else
      {
        prev=scp;
        scp=scp->next;
      }
    }
    cp=cp->next;
  }
  return succ;
}

int nodes_same(int **a,int **b) {
  int i,j,flg=TRUE;
  for(i=0; i<N; i++)
  {
    for(j=0;j<N;j++)
    {
      if(a[i][j]!=b[i][j])
      {
        break;
        flg=FALSE;
      }
    }
    if(a[i][j]!=b[i][j])
      {
        break;
        flg=FALSE;
      }
  }
  return flg;
}

void print_nodes(struct node *cp) {
  while (cp!=NULL) {
    print_a_node(cp);
    cp=cp->next;
  }
}

void print_a_node(struct node *np) {
  int i,j, (*mp)[N];
  mp = np->loc;
  for (i=0;i<N;i++) {
    for (j=0;j<N;j++) printf("%2d ",np->loc[i][j]);
    printf("\n");
  }
  printf("\n");
  mp=NULL;
}

struct node *initialize(int argc, char **argv){
  int i,j,k,idx;
  struct node *tp;

  tp=(struct node *) malloc(sizeof(struct node));
  idx = 1;
  for (j=0;j<N;j++)
    for (k=0;k<N;k++) tp->loc[j][k]=atoi(argv[idx++]);
  for (k=0;k<N;k++) tp->loc[N][k]=0;	/* set f,g,h of initial state to 0 */
  tp->next=NULL;
  start=tp;
  printf("initial state\n"); print_a_node(start);
  
  tp=(struct node *) malloc(sizeof(struct node));
  idx = 1;
  for (j=0;j<N;j++)
    for (k=0;k<N;k++) tp->loc[j][k] = idx++;
  tp->loc[N-1][N-1] = 0;	      /* empty tile=0 */
  for (k=0;k<N;k++) tp->loc[N][k]=0;	/* set f,g,h of goal state to 0 */
  tp->next=NULL;
  goal=tp;
  printf("goal state\n"); print_a_node(goal);
  

  strcpy(strategy,argv[idx]);
  if (strcmp(argv[idx],"dfs")) {flag=DFS;}
  else if (strcmp(argv[idx],"bfs")){ flag = BFS;}
  else flag=BEST;

  return start;
}
/* end of hw4.c */
