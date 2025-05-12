#ifndef __MONTHS_H__
#define __MONTHS_H__

int karkausvuosi(int vuosiluku);
char kkPituus(const char *kkNimi, int vuosiluku);

typedef const enum {
    TAMMIKUU = 0,  
    HELMIKUU,      
    MAALISKUU,     
    HUHTIKUU,      
    TOUKOKUU,      
    KESAKUU,       
    HEINAKUU,      
    ELOKUU,        
    SYYSKUU,       
    LOKAKUU,       
    MARRASKUU,     
    JOULUKUU,      
    KK_LKM
} Kuukausi;

extern const char *KK_NIMET[KK_LKM];
extern const char KK_PAIVAT[2][KK_LKM];

#endif