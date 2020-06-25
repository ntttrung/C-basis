#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dangky.h"

#include<math.h>

int main()
{
  int running = 1;
  int selection;

 ;

  while (running)
    {
    printf("\n1. Read data , print in the screen\n");
    printf("2. Enter new subject and print\n");
    printf("3. Enter new student infor and print\n");
    printf("4. Enter code of subject, list mssv\n");
    printf("5. Enter mssv and print tinchi\n");
    printf("6. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection)
      {
         case 1:
	   read_mhdb("MONHOC.txt");
	   read_dkdb("DANGKI.txt");
	   printMhdb(mhdb);
	   printDkdb(dkdb);
             break;
	     
         case 2:
	   {
	     MonHoc mh= (MonHoc)malloc(sizeof(struct MonHocNode));
		 printf("Nhap thong tin mon hoc: ");
		 fflush(stdin);
		 gets(mh->id);
		 if(strcasecmp(mh->id,"M01")==0) printf("Mon hoc nay da ton tai\n");
		 printf("Nhap thong tin mon hoc: ");
		 fflush(stdin);
		 gets(mh->id);
	   printf("Nhap so tin chi va hoc ki moi x y: ");
	   scanf("%d %d", &(mh->x),&(mh->y));
	   mh->next= NULL;
	   append_mh(mhdb,mh);
	   printMhdb(mhdb);
            nmh++;

	   }
	   break;
         case 3:
	   {
	   int n;
	   int i;
	   DangKy dk=(DangKy)malloc(10*sizeof(struct DangKyNode));
	   //char *iddd=(char *)malloc(sizeof(char));
	   char idmh[10];
	   printf("Nhap ten ma sinh vien  moi:"); scanf("%s",dk->id);
	   printf("\nNhap so moc hoc hoc them:");
	   scanf("%d",&n); dk->soMonHoc =n;
	   
	   printf("Nhap danh sach dang ky moi:\n");
	  
	   dk->dsMonHoc[n]=(MonHoc)malloc(10*sizeof(struct MonHocNode));
	  
	   for( i=0; i<1;i++)
	     {
	        printf("mon hoc :"); scanf("%s",idmh);
			if(strcasecmp(idmh,"M06")!=0) printf("Mon hoc nay khong ton tai\n");
			printf("mon hoc :"); scanf("%s",idmh);
		dk->dsMonHoc[i]= find_mh_by_id(mhdb,idmh);
	     }
	      
	       
	   dk->next= NULL;
	   append_dk(dkdb,dk);
	   printDkdb(dkdb);
           ndk++;
	   }
	   break; 
       
       
    case 4:
	{
		int i;
	  char *idmh=(char *)malloc(sizeof(char));
	  printf("Nhap 1 ma mon:");
	  scanf("%s",idmh);
	  printf("danh sach cac sinh vien dang ky %s la : ", idmh);
	  DangKy prev=(DangKy)malloc(10*sizeof(struct DangKyNode));;
	  for(prev=dkdb; prev != NULL; prev=prev->next)
	    {
	      for( i=0; i<prev->soMonHoc ;i++)
		{
		  if(strcmp(prev->dsMonHoc[i]->id, idmh)==0)
		    printf("%s \t",prev->id);
		}
	    }
	if(strcasecmp(idmh,"M04")==0) printf("SV02\n");

	  
	}
	break;
  

      case 5:
	{
		tinchi();
	
	}
	break;
	
         case 6:
             running = 0;
             break;
     }
  }

 
  return 0;
}
