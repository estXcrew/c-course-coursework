#ifndef __BITIT_H__

void kaannaScharBitit(signed char *x);
void kaannaShortBitit(short *x);
void kaannaIntBitit(int *x);
void kaannaLongBitit(long *x);

#endif

/*

 Aseta arvo merkki unsigned int -muuttujaan.
    Laske, kuinka monta bittiä arvon x esittäminen vähintään vaatii: tutki, missä kohdassa oikealta vasemmalle laskettuna arvon x viimeinen 1-bitti on. Huomioi erikoistapaus, missä x = 0 eli yhtään 1-bittiä ei ole.
    Oletetaan, että kohdassa 2 havaittiin, että viimeinen 1-bitti on oikealta laskien indeksin k kohdalla. Valitaan lyhin sellainen UTF-8-koodin pituus, jossa on vähintään k+1 arvobittiä.
        1-tavuisessa on 7 arvobittiä, 2-tavuisessa on 11, 3-tavuisessa on 16 ja 4-tavuisessa on 21 arvobittiä.
    Koodataan arvon x oikeanpuoleisimmat k+1 bittiä valitunpituisen UTF-8-koodin arvobiteiksi.
        Aloita täysin nollatuista arvoista.
            Esim. jos 2-tavuinen koodi, aseta vaikkapa utf8[0] = utf8[1] = 0 ja lisäksi muista lopetusmerkki utf8[2] = '\0'.
        Tarkastellaan esimerkkinä 2-tavuiseen UTF-8-koodiin mahtuvan 'ä'-kirjaimen koodin 228 eli bittijonon 11100100 koodausta. Voinet ensin alustaa tavujen "etuosat": arvoon utf8[0] 1-bitit indeksien 7 ja 6 ja arvoon utf8[1] 1-bitti indeksin 7 kohdalle. Kuten luentokalvoilla on mainittu, esim. näistä viimeisin asetus onnistuu tapaan utf8[1] = utf8[1] | (1 << 7). Sen jälkeen kirjoitetaan arvon x = 228 oikeanpuoleisimmat k+1 = 8 bittiä tavujen utf8[1] ja utf8[0] arvo-osiin. Oikealta vasemmalle edeten: ensin arvoon utf8[1] 1-bitit indeksien 2 ja 5 kohdille, sen jälkeen arvoon utf8[0] indeksien 0 ja 1 kohdille. Näin muodostui bittiesitykset utf8[0] = 11000011 ja utf8[1] = 10100100 omaavat tavut.
    Koodi on valmis ja funktiokutsu voi palata.

    
*/