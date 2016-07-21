#ifndef __JWLOCK_H__
#define __JWLOCK_H__

#pragma pack(1)
typedef struct {
    unsigned char sec;
    unsigned char min;
    unsigned char hour;
    unsigned char day;
    unsigned char month;
    unsigned char week;
    unsigned char year;
} JwLockTime_t;

typedef enum {
    JWLOCK_DOOR_STA_OPEN,
    JWLOCK_DOOR_STA_CLOSE,
    JWLOCK_DOOR_STA_BACK_LOCK,
} JwLockDoorSta_t;

typedef struct {
    unsigned char low;
    unsigned char high;
} JwLockRecord_t;

typedef struct {
    unsigned char obligate[4];
    unsigned char gaffer;   /* ������� */
    unsigned char clean;    /* ������� */
    unsigned char floor;    /* ¥��� */
    unsigned char num;      /* ���� */
} JwLockRoomInfo_t;

typedef struct {
    JwLockTime_t time;
    unsigned char NotUsed;
    unsigned char bat;
    JwLockDoorSta_t sta;
    JwLockRecord_t record;
    JwLockRoomInfo_t info;
    unsigned char obligate[10];
    unsigned char rsp[2];   /* 0x90 0x00 */
} JwLockSta_t;

#define JWLOCK_RSP {0x00, 0x90, 0x00}

typedef struct {
    unsigned char low;
    unsigned char min;
    unsigned char high;
} JwLockId_t;

typedef enum {
    JWLOCK_OPEN_ATTR_3S_CLOSE,  /* 3s������ */    
    JWLOCK_OPEN_ATTR_LONG_OPEN, /* ���� */
    JWLOCK_OPEN_ATTR_FINISH_LONG_OPEN, /* �������� */
} JwLockOpenAttr_t;

typedef struct {
    JwLockId_t id;
    unsigned char min;
    unsigned char hour;
    unsigned char date[2];  /* ��/��/��(5λ4λ7λ��������) */
    unsigned char attr;
} JwLockOpenRecord_t;

#pragma pack()

void JwLockHandler(void);
void JwLockInit(void);
void JwLockRecv(void);
void JwLockOpen(void);
void JwLockClose(void);
void JwLockGetSta(void);
void JwLockSetTime(JwLockTime_t time);
void JwLockGetOpenRecord(unsigned int start, unsigned char num);

#endif


