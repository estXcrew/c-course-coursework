#ifndef __MONTHS_H__
#define __MOHTHS_H__

int karkausvuosi(int vuosiluku);


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

const char *KK_NIMET[KK_LKM] = {
    "tammikuu",
    "helmikuu",
    "maaliskuu",
    "huhtikuu",
    "toukokuu",
    "kesakuu",
    "heinakuu",
    "elokuu",
    "syyskuu",
    "lokakuu",
    "marraskuu",
    "joulukuu"
  };
  

const char KK_PAIVAT[2][KK_LKM] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  };
  
#endif