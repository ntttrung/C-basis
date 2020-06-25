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
void initilize() {
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

}
int main()
    {
        int i;
        initilize();
        struct Seat tmp;
        tmp.col='A';
        tmp.row=3;
        c_seats=sq_delete(c_seats,tmp);
        for(i=c_seats->f;i<=c_seats->r;i++)
        {
            printf("%c",c_seats->data[i].col);
            printf("%d\n",c_seats->data[i].row);
        }
        // sq_delete(c_seats,tmp);
        // for(i=c_seats->f;i<=c_seats->r;i++)
        //     printf("%d\n",c_seats->data[i].row);
    }