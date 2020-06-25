#ifndef _DANGKY_H_
#define _DANGKY_H_

struct MonHocNode{
	char id[10];
	int x;
	int y;
	struct MonHocNode *next;
};
typedef struct MonHocNode *MonHocDB;
typedef struct MonHocNode *MonHoc;

struct DangKyNode {
	char id[10];
	int soMonHoc;
	MonHoc dsMonHoc[10];
	struct DangKyNode *next;
};
typedef struct DangKyNode *DangKyDB;
typedef struct DangKyNode *DangKy;
MonHocDB mhdb;
DangKyDB dkdb;
int nmh,ndk;

MonHocDB read_mhdb(char* filename);
DangKyDB read_dkdb(char *filename);

void write_mhdb(char *filename, MonHocDB mhdb);
void write_dkdb(char *filename, DangKyDB dkdb);

MonHocDB append_mh(MonHocDB mhdb, MonHoc mh);
DangKyDB append_dk(DangKyDB dkdb, DangKy dk);

MonHoc find_mh_by_id(MonHocDB mhdb, char *id);

DangKy find_dk_by_id(DangKyDB dkdb, char *id);

void tinchi();

#endif
