#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 100

typedef struct {
  char  model[20];
  int   memory;
  double screen_size;
  int   price;
} phone_t;

struct node {
  phone_t data;
  struct node *next;
};

struct node *root;
struct node *cur;

void freeDB() {
  struct node *tmp;
  cur = root;
  while (cur != NULL) {
    tmp = cur;
    cur = cur->next;
    free(tmp);
  }
  root = NULL;
  cur = NULL;
}

void convertDB() {
  FILE *fin;
  FILE *fout;
  phone_t phone;
  char str[MAXCHAR+1];

  if ((fin = fopen("NokiaDB.txt", "r")) == NULL) {
    printf("Can\'t read from NokiaDB.txt\n");
    return;
  };

  if ((fout = fopen("NokiaDB.dat", "w")) == NULL) {
    printf("Can\'t open NokiaDB.dat\n");
    return;
  };

  while (fgets(str, MAXCHAR, fin) != NULL) {
    sscanf(str, "%s %d %lf %d",
	   &(phone.model),
	   &(phone.memory),
	   &(phone.screen_size),
	   &(phone.price));
    printf("%s,%d,%f,%d\n", phone.model, phone.memory, phone.screen_size, phone.price);
    fwrite(&phone, sizeof(phone_t), 1, fout);
  }

  fclose(fin);
  fclose(fout);
}

struct node* makeNode(phone_t *phone) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = *phone;
  n->next = NULL;
  return n;
}

void addDB(phone_t *phone) {
  struct node *new_node = makeNode(phone);

  if (root == NULL) {
    root = new_node;
    cur = new_node;
  } else {
    new_node->next = cur->next;
    cur->next = new_node;
    cur = new_node;
  }
}

void readDB() {
  FILE *fin;
  phone_t phone;
  
  freeDB();

  if ((fin = fopen("NokiaDB.dat", "rb")) == NULL) {
    printf("Can\'t read from NokiaDB.dat\n");
    return;
  };

  while(!feof(fin)) {
    fread(&phone, sizeof(phone_t), 1, fin);
    printf("%s,%d,%f,%d\n", phone.model, phone.memory, phone.screen_size, phone.price);    
    addDB(&phone);
  }
  fclose(fin);
}

void printDB() {
  struct node *it;
  for (it = root; it != NULL; it = it->next)
    printf("%s,%d,%f,%d\n",
	   (it->data).model,
	   (it->data).memory,
	   (it->data).screen_size,
	   (it->data).price);
}

void searchDB() {
  char model[20];
  struct node *it;
  
  printf("Enter model:");
  scanf("%s", model);
 
  for (it = root; it != NULL; it = it->next)
    if (strcmp(model, (it->data).model) == 0) {
      printf("\n%s,%d,%f,%d\n",
	     (it->data).model,
	     (it->data).memory,
	     (it->data).screen_size,
	     (it->data).price);
      break;
    }

  if (it == NULL)
    printf("\nCan\'t find %s\n", model);
}

void inputDB() {
  phone_t phone;

  printf("\nEnter model:"); scanf("%s", phone.model);
  printf("\nEnter memory:"); scanf("%d", &(phone.memory));
  printf("\nEnter screen size:"); scanf("%lf", &(phone.screen_size));
  printf("\nEnter price:"); scanf("%d", &(phone.price));

  if (root != NULL)
    for (cur = root; cur->next != NULL; cur = cur->next);

  addDB(&phone);
}

int main() {
  int running = 1;
  int selection;

  root = NULL;
  cur = 0;
  
  while (running) {
    printf("\n1. Convert from text to binary\n");
    printf("2. Read binary file\n");
    printf("3. Print database\n");
    printf("4. Search by model\n");
    printf("5. Add new entry\n");
    printf("6. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection) {
    case 1:
      convertDB();
      break;
    case 2:
      readDB();
      break;
    case 3:
      printDB();
      break;
    case 4:
      searchDB();
      break;
    case 5:
      inputDB();
      break;
    case 6:
      running = 0;
      break;
    }
  }

  freeDB();

  return 0;
}
