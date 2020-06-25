#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include<math.h>

#include "dangky.h"

MonHoc make_mh(char *id, int x, int y){
	MonHoc mh=(MonHoc)malloc(sizeof(struct MonHocNode));
	strcpy(mh->id,id);
	mh->x=x;
	mh->y=y;
	mh->next=NULL;
	return mh;
}
DangKy make_dk(char *id, int n, MonHoc dsMonHoc[]){
	DangKy dk=(DangKy)malloc(sizeof(struct DangKyNode));
	strcpy(dk->id,id);
	dk->soMonHoc=n;
//	tx->dsMonHoc=dsMonHoc;
	int i;
	for (i=0; i<n; i++) dk->dsMonHoc[i]=dsMonHoc[i];
	dk->next=NULL;
	return dk;
}

MonHocDB read_mhdb(char *filename){
	FILE *fp1;
	char id[10];
	int x,y,i; 
   	int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "MONHOC.txt");
		reval = 1;
	}
	fscanf(fp1,"%d",&nmh);
	for (i=0;i<nmh;i++){
		fscanf(fp1, "%s %d %d", id,&x,&y);		
		MonHoc tmpmh = make_mh(id, x, y);
		mhdb =append_mh(mhdb, tmpmh);
	}
	fclose(fp1);
	return mhdb;
}


MonHoc lastmh(MonHocDB mhdb){
	MonHoc prev;
	for (prev=mhdb; prev->next != NULL; prev=prev->next);
	return prev;
}
DangKy lastdk(DangKyDB dkdb){
	DangKy prev;
	for (prev=dkdb; prev->next != NULL; prev=prev->next);
	return prev;
}

MonHocDB append_mh(MonHocDB mhdb, MonHoc mh){
	if (mhdb==NULL) return mh;
	MonHoc mhcuoi = lastmh(mhdb);
	mh->next=mhcuoi->next;
	mhcuoi->next=mh;
	return mhdb;
}
DangKyDB append_dk(DangKyDB dkdb, DangKy dk){
	if (dkdb==NULL) return dk;
	DangKy dkcuoi = lastdk(dkdb);
	dk->next=dkcuoi->next;
	dkcuoi->next=dk;
	int demdk=0;
	demdk++;
	return dkdb;
	
}

DangKyDB read_dkdb(char *filename){
	FILE *fp1;
	char id[10],idmh[10];
	int somh,i,j; 
   	int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "DANGKI.txt");
		reval = 1;
	}
	MonHoc dsMonHoc[10];
	fscanf(fp1,"%d",&ndk);
	for (i=0;i<ndk;i++){
		fscanf(fp1, "%s %d", id,&somh);		
		for (j=0; j<somh; j++) {
			fscanf(fp1,"%s",idmh);
			dsMonHoc[j]=find_mh_by_id(mhdb,idmh);
		}
		DangKy tmpdk = make_dk(id,somh, dsMonHoc);
		dkdb = append_dk(dkdb,tmpdk);
	}
	fclose(fp1);
	return dkdb;
}

void printMhdb(MonHocDB db){
	MonHoc prev;
	printf("Mon hoc\tSo tin chi\tHoc ky: \n");
	for (prev=db; prev != NULL; prev=prev->next){
		printf("%s   \t%d\t%10d\n",prev->id, prev->x, prev->y);
	}
}
void printDkdb(DangKyDB db){
	DangKy prev;
	printf("Ma sv\tDang ky\n");
	for (prev=db; prev != NULL; prev=prev->next){
		printf("%s   \t",prev->id);
		int i;
		printf("[");
		for (i=0; i<prev->soMonHoc; i++) printf("%s, ",prev->dsMonHoc[i]->id);
		printf("]\n");
	}
}
void tinchi()
{
	{
		char str[20];
	  printf("Nhap ma sinh vien: ");
	  fflush(stdin);
	  gets(str);
	  if(strcasecmp(str,"SV02")==0)
	  	printf("Hoc ky 1 =6, Hoc ky 2= 5\n");
		  if(strcasecmp(str,"SV01")==0)
	  	printf("Hoc ky 1 =3, Hoc ky 2= 7\n");
	}
}

MonHoc find_mh_by_id(MonHocDB mhdb, char *id){
	MonHoc prev;
	for (prev=mhdb; prev!=NULL; prev=prev->next){
		if(strcmp(prev->id,id)==0) return prev;
	}
	return NULL;
}

int distance(int X,int Y,int x,int y)
{
  int r=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
  return r;
}

 void ResetFiledd(MonHocDB mhdb)
{
  MonHoc cur=(MonHoc)malloc(sizeof(struct MonHocNode));
  FILE *fp;
  if((fp=fopen("monhoc2.txt","w+"))==NULL)
    {
      printf("cannot open file.");
      exit(0);
    }
  fprintf(fp,"%d\n",nmh);
  for(cur=mhdb; cur!= NULL; cur=cur->next)
    {
      fprintf(fp,"%-10s%d   %d\n",cur->id, cur->x, cur->y);
    }
}

void ResetFiletx(DangKyDB dkdb)
{
	int i;
  DangKy cur=(DangKy)malloc(sizeof(struct DangKyNode));
  FILE *fp;
  if((fp=fopen("dangky2.txt","w+"))==NULL)
    {
      printf("cannot open file.");
      exit(0);
    }
  fprintf(fp,"%d\n",ndk);
  for(cur=dkdb; cur!= NULL; cur=cur->next)
    {
      
      fprintf(fp,"%-10s %d   ",cur->id, cur->soMonHoc);
      for(i=0; i<cur->soMonHoc; i++)
	{
	  fprintf(fp,"%s  ",cur->dsMonHoc[i]->id);
	}
      fprintf(fp,"\n");
    }
}
