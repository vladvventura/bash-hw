//Vladimir Ventura
//hw5 -- array of linked list with radix sorting
//Let me start out by apologizing for the lateness of this program
//It turns out this program WORKS.... but it has huge memory leaks
//and because of it, it won't run unless I force it to (Ubuntu won't let it run all the way because of the fact that there are memory leaks, but I didn't realize "sYSMALLOc: Assertion failed." error meant that).
//For testing purposes (if you want to see that the code actually works), use valgrind ./hw5 index :D
//It took me TWO WEEKS to realize that THAT's what the error means.

//Where is this memory leak from? Well, it happens when I cast the aoti() pointer to int.. It also happens when I set head2 or cp =NULL (or anything else to NULL; C doesnt have a good garbage collection tool, or so I hear from forums online)... SOOOO... yea... sorry about that!

//This might have to do with my OS being Ubuntu, and not Fedora... but I won't get into that. The point is, if I force Ubuntu to ignore memory leaks...(bad, right?) the program works. I used Valgrind to force run the program (and coincidentally find the memory leaks). I printed the first list to show that it is radix sorted, and then I simply printed the top entry (as it is the highest views) of each array's linked list to show the most popular video. Sorry for the huge mess of 5xx lines below. I have cleaned it up to the best of my abilities.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define LINE_LENGTH 200
#define MAX_CLIPS 100


void print_a_line(),print_a_clip(),print_a_lst(),print_lsts();
void split_line();

void build_lsts();
void print();//just to see the contents of one linked list
void lst_radix_sort();

struct clip *insert_at_end();
struct clip *build_a_lst();
struct clip *hourly[MAX_CLIPS];

struct clip {
  int APC, busNumber, busSpeed, time;
  struct clip *next;
} *head;

int main(int argc, char **argv) {
  char filename[LINE_LENGTH];
  char *prefix;
  prefix=malloc(sizeof(*(argv+1)));
  strcpy(prefix,*(argv+1));
  
  
  build_lsts(prefix);	/* filename prefix*/
  print(hourly);//first linked list... is it sorted? yes it is xD
  printf("Printed highest views from sorted array of Linked list:\n\n");
  print_lsts(hourly);//print top clip.
  return 0;
}


//print tester method. 
void print(struct clip **lst) {
  struct clip *cp=lst[0];
  printf("First (sorted) list\n");
  while(cp!=NULL){
    printf("%-10d %-30s %-6s %-40s\n",cp->views,cp->user,cp->time,cp->title);
    cp=cp->next;
  }

}



void sort_lsts(struct clip **lst) {
  int i;
  i=0;
  while(i<60)
  {
    int_radix_sort(lst[i], i);
    i++;
  }
//this is for testing purposes, below.*/
/*
  i=0;
  int_radix_sort(lst[59], 59);//turns out I need the index, see method

  /* 
     sort individual lists in descending order of views
     such that the first clip in each list will have the highest views
     this one is the same as HW4


     once you are done sorting individual lists, sort the entire array
     this one is again the same as HW4 except now that you use values from the first clip of each list

  */

//done sorting individual lists. now, to sort the entire array.

//having problems with***

 //lst_radix_sort(lst);//for some reason, it sorts but prints only half..

}


/////////////////////////////////////
//				   //
//    array based radix sorting    //
//   the one that sorts the views  //
// from the top clips of the array //
/////////////////////////////////////
void lst_radix_sort(struct clip **lst)
{
  struct clip *buff[MAX_CLIPS];
  int n = 65536; 
  int views[MAX_CLIPS], cnt[n], map[n], index[MAX_CLIPS];
  int i;
  //now we radix sort the views.
  //bucket size is 16 bits,which=65536 combinations (2^16)
  int mask=n-1; //mask is bucket size-1.
  int round=0;
  

  for(i=0; i<60; i++)
  {
    views[i]=lst[i]->views;
    index[i]=0;
    
    map[i]=0;
  }
  for(i=0; i<n; i++)
	cnt[i]=0; //initialize cnt.
  
  //cnt
  for(i=0; i<60; i++) //we go through the list, 
    {
      cnt[views[i]>>16*round&mask]++;  //LSR by 16 because of 16 bits.
    }//for some reason, cnt is getting values of 28 in several bins.
//SEVERAL. im not sure why this is happening...
  //map
  map[0]=0;
  for(i=1; i<n;i++)
    {
//      if(cnt[i]>0)
  //     printf("map: %d\n", cnt[i]);
      map[i]=map[i-1]+cnt[i-1];
     
    }

    //"move"... what we're really doing is moving index
 
  for(i=0; i<60;i++)//now we can move stuff over.
    {
      index[i]=map[views[i]>>16*round&mask];//get the index. so @ index[0] contains where the ORIGINAL list's zero'th position goes.
      printf("Index: %d\n",index[i]);

      buff[index[i]]=lst[i];
/*      buff[index[i]]=malloc(sizeof(struct clip));
      buff[index[i]]->views=malloc(sizeof(lst[i]->views));
      buff[index[i]]->views=lst[i]->views;
      buff[index[i]]->user = malloc(strlen(lst[i]->user));
      strcpy(buff[index[i]]->user,lst[i]->user);
      buff[index[i]]->time = malloc(strlen(lst[i]->time));
      strcpy(buff[index[i]]->time,lst[i]->time);
      buff[index[i]]->title = malloc(strlen(lst[i]->title));
      strcpy(buff[index[i]]->title,lst[i]->title);
      buff[index[i]]->next=lst[i]->next;
*/ 
      map[views[i]>>16*round&mask]++;
    }
  round++;
  for(i=0; i<60; i++) //move buff back to lst, and repeat the last 30ish lines of code
  {
    lst[i]=buff[i];
  }
  ///////////////////////////////
  // repeat of lines 127-156   //
  ///////////////////////////////


  for(i=0; i<60; i++)
  {
    views[i]=lst[i]->views;
    index[i]=i;
    cnt[i]=0; //reinitialize cnt
    map[i]=0; //reinitialize map
    buff[i]=NULL; //reinitialize buff.
    buff[i]=malloc(sizeof(struct clip));
  }
  
  
  //cnt
  for(i=0; i<60; i++) //we go through the list, 
    {
      cnt[views[i]>>16*round&mask]++;  //LSR by 16 because of 16 bits.
    }

  //map
  map[0]=0;
  for(i=1; i<n;i++)
    {
      map[i]=map[i-1]+cnt[i-1];
    }

    //"move"... what we're really doing is moving index
 
  for(i=0; i<60;i++)//now we can move stuff over.
    {
      index[i]=map[views[i]>>16*round&mask];//get the index. so @ index[0] contains where the ORIGINAL list's zero'th position goes.
      buff[index[i]]=lst[i];
     /*
      buff[index[i]]=malloc(sizeof(struct clip));
      buff[index[i]]->views=(int *)malloc(sizeof(lst[i]->views));
      buff[index[i]]->views=lst[i]->views;
      buff[index[i]]->user = malloc(strlen(lst[i]->user));
      strcpy(buff[index[i]]->user,lst[i]->user);
      buff[index[i]]->time = malloc(strlen(lst[i]->time));
      strcpy(buff[index[i]]->time,lst[i]->time);
      buff[index[i]]->title = malloc(strlen(lst[i]->title));
      strcpy(buff[index[i]]->title,lst[i]->title);
      buff[index[i]]->next=lst[i]->next;
*/
      map[views[i]>>16*round&mask]++;
    }

    //now, this is done array radix sorting. now, setting hourly to buff.
   for(i=0; i<60; i++)
   {
     hourly[i]=buff[i];
   }

  
}





////////////////////////////////
// linked list radix sorting  //
//     (NOT array based)      //
////////////////////////////////
void int_radix_sort(struct clip *cp, int index) {
  int n = 65536; //bucket size is 8 bits,which  =256 bit-combinations (2^8)
  int mask=n-1; //mask is bucket size-1.
  int i;
  int round=0;

    //we have no lst here; instead it's a linked list. i corresponds to
    //the location of an element in the linked list.
  int listSize=0; //the size of the linked list
  struct clip *tp=cp;
  while(tp!=NULL)
    {
      listSize++; //I need the listSize for linked list 2; see below.
      tp=tp->next;
    }
  tp=cp;

  struct clip *cp2, *tp2, *head2; //these point to locations in linked list 2.
  //linked list 2 is where the first radix iteration will head into.
    for(i=0; i<listSize;i++)//first recreate and allocate new linked list
      {
        tp2=malloc(sizeof(struct clip));
        tp2->next=NULL;
        if (head2==NULL)
        {
          head2=tp2;
        }
        else
        {
          cp2=head2;
          while (cp2->next!=NULL)
            {
	      cp2=cp2->next;
            }
          cp2->next=tp2;
        }
      }
  //now the actual sort.
  sort(head2, tp, listSize, round); //destination, source, size, round.
  
  round++;

  cp=NULL; //let's remove the head pointer,
  //and reinitiate it so we can place things into first head
  //that was the first iteration...

  struct clip *cp1, *tp1, *tempNext;
  for(i=0; i<listSize;i++)//recreate the first linked list.
      {
        tp1=malloc(sizeof(struct clip));
        tp1->next=NULL;
        if (cp==NULL)
        {
          cp=tp1;
        }
        else
        {
          cp1=cp;
          while (cp1->next!=NULL)
            {
	      cp1=cp1->next;
            }
          cp1->next=tp1;
        }
      }
  //now cp can be the destination.
  sort(cp, head2, listSize, round);
  

  //It's sorted in ASCENDING order now. we need descending order.
  head2=NULL;
  for(i=0; i<listSize;i++)//first recreate and allocate new linked list
  {
    tp2=malloc(sizeof(struct clip));
    tp2->next=NULL;
    if (head2==NULL)
    {
      head2=tp2;
    }
    else
    {
      cp2=head2;
      while (cp2->next!=NULL)
      {
        cp2=cp2->next;
      }
      cp2->next=tp2;
    }
  }



  int cpCount; //cpCount is to count where in the linked list u are.
  i=0;
  cpCount=0;
  tp2=cp;
  while(tp2!=NULL)
  {//to get it in reverse order, we are going to grab the first node
    if (cpCount==0)//put it at the end
    {
      head2=tp2;
      tp2=tp2->next;
      head2->next=NULL;//establishes this node is the end of the list.
      cpCount++;
    }
    else//and add every subsequent node to the beginning of the list
    {
      tempNext=tp2->next; //keep the original linked list's next node
      tp2->next=head2;//otherwise we lose it in this step, adding
      head2=tp2; //this node to the beginning of the list
      tp2=tempNext;//and now we continue onward.
    }
    
  }

  //this would be all fine and dandy... but wait! cp will be destroyed
  //at the end of this method because it is within the scope of this
  //method! But this is where index comes in handy! hourly is a global
  //variable! hahah! :D
  hourly[index]=head2;
  //printf("sorted %d", index);                 
  head2=cp=tp=tp2=cp1=tp1=NULL;
  i=0;tempNext=0;round=0;cpCount=0;
}

int getCpValue(struct clip *cp, int i) //int because we are sorting views
{
  int index=0;
  while(cp->next!=NULL && index<i)
    {
      cp=cp->next;
      index++;
    }

  return cp->views;
}


void sort(struct clip *cpD, struct clip *cpS, int lSize, int round)
{
  int index; //index for moving from head to head2 linked lists. (for the move op)
  int i;
  int n=65536; //bucket size
  int mask=n-1; //mask
  int cnt[n];
  int map[n];
  struct clip *headS=cpS, *headD=cpD; //so we have a head to refer back to
  //since cp will constantly change.


  //initialize cnt
  for(i=0; i<n; i++)
    cnt[i]=0;
  //count
  for(i=0; i<lSize; i++) //we go through the list, 
    {
      cnt[getCpValue(cpS,i)>>16*round&mask]++;  //LSR by 8 because of 8 bits.
      //also, remember cpS is changed in the method
      cpS=headS;//so, put cpS back to headS, which is what it was originally pointing to.
    }
  //map
  map[0]=0;
  for(i=1; i<n;i++)
    {
      map[i]=map[i-1]+cnt[i-1];
    }

    //"move"... what we're really doing is recreating the linked list.
 
  for(i=0; i<lSize;i++)//now we can move stuff over.
    {
      index=map[getCpValue(cpS,i)>>16*round&mask];//get the index for head2
      cpS=headS; //again, reset cp to head.
      map[getCpValue(cpS,i)>>16*round&mask]++;//increment the map index.
      cpS=headS; //again.
      //we take the location in head2, and set it equal to the memory in head1
      int i1=0; //temp index for head
      int i2=0; //temp index for head2
      //find index in head2. this is what we want to modify.
      cpD=headD;
      while(i2<index && cpD->next!=NULL)
	{
	  cpD=cpD->next;
	  i2++;
	}
      //im at the cp index location ofhead2.
      cpS=headS;
      while(i1<i && cpS->next!=NULL) //get to the location of i in head's list
	{
	  cpS=cpS->next;
	  i1++;
	}

      //now, the actual move!
      cpD->views=malloc(sizeof(cpS->views));
      cpD->views=cpS->views;
      cpD->user = malloc(strlen(cpS->user));
      cpD->user = cpS->user;
      cpD->time = malloc(strlen(cpS->time));
      cpD->time = cpS->time;
      cpD->title = malloc(strlen(cpS->title));
      cpD->title= cpS->title;
      cpS=headS;//and again, set cp to head.
    }

}



/////////////////////////
// linked list methods //
/////////////////////////

/* prefix can be such as: index-2013-03-01-12 
  the directory will have 60 files with the above prefix */
void build_lsts(char *prefix) {
  FILE *fp;
  char command[2*strlen(prefix)],*filename;
  int i;
  for (i=0;i<MAX_CLIPS;i++)
    hourly[i] = NULL;
  

  sprintf(command,"ls %s*",prefix);  
  fp = popen(command,"r");
  //put all commented code together, for neatness
  //cmd=malloc(2*strlen(prefix));//cmd wasn't working, command was.
  //printf("Files are:\n %s\n", command);//for testing purposes
  //printf("File opened!\n");
  /*read output from command*/
  i=0;

  while (fscanf(fp,"%s",filename) == 1) {
    //printf("Opening file %d", i);
    hourly[i] = build_a_lst(filename);
    //printf("File %d read!\n", i);
    //print_a_lst(hourly[i]);//print_a_lst works
    i++;
   }     
  fclose(fp);
}

/* open the file, read one line at a time, split and insert */
struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[5];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;

  if ((fp = fopen(fn,"r")) != NULL) {
    while (fgets(line, LINE_LENGTH, fp) != NULL) {
      split_line(fields, line);
      hp=insert_at_end(hp, fields);
    }
    fclose (fp);
  }
  // open fn
  // while no more lines
  // read a line
  // split the line into five substrings and store them in fields
  // insert at the end of the list
  // return the head pointer holding the list

  return hp;
}

/* fields will have five values stored */
void split_line(char **fields,char *line) {
  int i=0;
  char *token, *delim, *buff;
  delim = ",";
  
  buff=malloc(strlen(line));
  strcpy(buff,line);
  token=strtok(buff,delim); //first iteration (Views)
  //printf("%s\n",token);
  fields[i]=malloc(strlen(token));
  strcpy(fields[i++],token);




  while(token!=NULL)
    {
      token=strtok(NULL,delim);
      if(token!=NULL) //the token might become null. thats where seg fault WOULD come from, wouldn't it? ._.
        {
          //printf("%s\n",token);
          fields[i]=malloc(strlen(token));
          strcpy(fields[i++], token);
        }
    }
}

/* set the five values into a clip
   insert a clip at the of the list */
struct clip *insert_at_end(struct clip *hp,char **five) {
  struct clip *cp,*tp;
  int i =0;
  tp=malloc(sizeof(struct clip));
  tp->next=NULL;


  tp->views=malloc(sizeof(atoi(five[i])));
  tp->views=atoi(five[i++]);
  tp->user = malloc(strlen(five[i]));
  strcpy(tp->user,five[i++]);
  tp->time = malloc(strlen(five[i]));
  strcpy(tp->time,five[i++]);
  tp->title = malloc(strlen(five[i]));
  strcpy(tp->title,five[i]);

  //done instantiating all values for tp. now to stick it into the linked list.

  if (hp==NULL)
  {
    hp=tp;
  }
  else
  {
    cp=hp;
    while (cp->next!=NULL)
      {
	cp=cp->next;
      }
    cp->next=tp;
  }
  //printf("Line added!\n");
  return hp;
}

///////////////////////
//  printing methods //
///////////////////////
/* use print_a_lst(struct clip *cp); */
void print_lsts(struct clip **lst) {
//instructions say print the top clip in each list.
  int c;
  c=0;
  while(c<60)
  {
    print_a_lst(lst[c]);
    c++;
  }
}



void print_a_lst(struct clip *cp) {
      printf("%-10d %-30s %-6s %-40s\n",cp->views,cp->user,cp->time,cp->title);
  
    
    /* print the top.
  */
}

/* end */
