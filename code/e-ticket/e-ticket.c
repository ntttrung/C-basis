#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

#include "request.h"
#include "seat_queue.h"
#include "request_list.h"

sq_queue w_seats;
sq_queue c_seats;
sq_queue n_seats;
rl_list requests;

void initialize();
void cleanup();

void make_new_request();
void cancel_request();
void print_requests();
void modify_request();

int main() {
  int running = 1;
  int selection;

  initialize();

  while (running) {
    printf("\n1. Make new request\n");
    printf("2. Cancel request\n");
    printf("3. Print all requests\n");
    printf("4. Modifying\n");
    printf("5. Quit\n\n");
    printf("Choose an option: ");
    scanf("%d", &selection);
    printf("\n");
    switch (selection) {
    case 1:
      make_new_request();
      break;
    case 2:
      cancel_request();
      break;
    case 3:
      print_requests();
      break;
    case 4:
      modify_request();
      break;
    case 5:
      running = 0;
      break;
    }
  }

  cleanup();
  return 0;
}


void initialize() {
  struct Seat seat;
  int i;
  
  w_seats = sq_create();
  c_seats = sq_create();
  n_seats = sq_create();
  
  // Initialize available seats
  for (i = 1; i <= 50; i++) {
    seat.row = i;
    seat.col = 'C';
    w_seats = sq_enqueue(w_seats, seat);
    seat.row = i;
    seat.col = 'F';
    w_seats = sq_enqueue(w_seats, seat);
    seat.row = i;
    seat.col = 'B';
    n_seats = sq_enqueue(n_seats, seat);
    seat.row = i;
    seat.col = 'E';
    n_seats = sq_enqueue(n_seats, seat);
    seat.row = i;
    seat.col = 'A';
    c_seats = sq_enqueue(c_seats, seat);
    seat.row = i;
    seat.col = 'D';
    c_seats = sq_enqueue(c_seats, seat);
  }

  // Initialize request list
  requests = rl_create();
}

void cleanup() {
  sq_free(w_seats);
  sq_free(c_seats);
  sq_free(n_seats);

  rl_free(requests);
}


void make_new_request() {
  int i,j,dk;
  struct Request in_request;
  printf("Enter your name: ");
  fflush(stdin);
  gets(in_request.name);
  printf("Enter the quantity: ");
  scanf("%d",&in_request.quantity);
  // printf("Enter the seat_type [W-1,C-2.N-3]: ");
  // scanf("%d",&in_request.seat_type);
  for(i=1;i<=in_request.quantity;i++)
    {
      do
        {
              printf("SEAT %d:\n",i);
              printf("Enter the column: ");
              fflush(stdin);
              in_request.reserved_seats[i].col=getchar();
              in_request.reserved_seats[i].col=toupper(in_request.reserved_seats[i].col);
              printf("Enter the row: ");
              scanf("%d",&in_request.reserved_seats[i].row);
              if((in_request.reserved_seats[i].col=='A')||(in_request.reserved_seats[i].col=='D'))
                {
                  for(j=c_seats->f;j<=c_seats->r;j++)
                    if((in_request.reserved_seats[i].col==c_seats->data[j].col)&&(in_request.reserved_seats[i].row==c_seats->data[j].row))
                      {
                        c_seats=sq_delete(c_seats,in_request.reserved_seats[i]);
                        dk=1;
                        break;
                      }
                    else dk=0;
                }
              else  if((in_request.reserved_seats[i].col=='B')||(in_request.reserved_seats[i].col=='E'))
                      {
                        for(j=n_seats->f;j<=n_seats->r;j++)
                          if((in_request.reserved_seats[i].col==n_seats->data[j].col)&&(in_request.reserved_seats[i].row==n_seats->data[j].row))
                            {
                              n_seats=sq_delete(n_seats,in_request.reserved_seats[i]);
                              dk=1;
                              break;
                            }
                          else dk=0;
                      }
                    else  if((in_request.reserved_seats[i].col=='C')||(in_request.reserved_seats[i].col=='F'))
                      {
                        for(j=w_seats->f;j<=w_seats->r;j++)
                          if((in_request.reserved_seats[i].col==w_seats->data[j].col)&&(in_request.reserved_seats[i].row==w_seats->data[j].row))
                            {
                              w_seats=sq_delete(w_seats,in_request.reserved_seats[i]);
                              dk=1;
                              break;
                            }
                          else dk=0;
                      }
              if(dk==0)
                printf("This seat is not available!Please, choose another one.\n");
              else printf("Your request is accepted\n");
         }
        while(dk==0);

    }
  requests=rl_insert_after(requests,requests,in_request);

}

void cancel_request() {
  char *name;
  int dk;
  int i;
  struct Request out_request;
  printf("Enter your name: ");
  fflush(stdin);
  gets(name);
  rl_list hihihaha=requests;
  while(hihihaha!=NULL)
    {
      if(strcasecmp(hihihaha->data.name,name)==0)
        {
          out_request=hihihaha->data;
          dk=1;
          requests=rl_remove_at(requests,hihihaha);
          break;
        }
      else dk=0;
      hihihaha=hihihaha->next;
    }
  if(dk==0) printf("Cannot find request made by %s\n",name);
  else if(dk==1) printf("SUCCESS\n");
  for(i=1;i<=out_request.quantity;i++)  
    {
      if(out_request.reserved_seats[i].col=='C'||out_request.reserved_seats[i].col=='F')
        w_seats=sq_enqueue(w_seats,out_request.reserved_seats[i]);
      else if(out_request.reserved_seats[i].col=='B'||out_request.reserved_seats[i].col=='E')
        n_seats=sq_enqueue(n_seats,out_request.reserved_seats[i]);
           else if(out_request.reserved_seats[i].col=='A'||out_request.reserved_seats[i].col=='D')
                  c_seats=sq_enqueue(c_seats,out_request.reserved_seats[i]);
    }
}
void print_requests() {
  int i=1,j;
  rl_list hihihaha=requests;
  while(hihihaha!=NULL)
    {
      printf("Request %d :\n",i);
      printf("\t\tName: ");
      puts(hihihaha->data.name);
      printf("\t\tQuantity: %d\n",hihihaha->data.quantity);
      printf("\t\tReserved_seats: ");
      for(j=1;j<=hihihaha->data.quantity;j++)
        {
            printf("%c%d  ",hihihaha->data.reserved_seats[j].col,hihihaha->data.reserved_seats[j].row);
        }
      printf("\n");
      hihihaha=hihihaha->next;
      i++;
    }
}
void modify_request() {
  cancel_request();
  make_new_request();
}
