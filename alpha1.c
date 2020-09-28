/*

 TORPEDÓ JÁTÉK v0.3 - Karácsonyi Péter
 Tekintettel a kevés rutinomra és erõsen hiányos c-nyelvi ismereteimre, és a kevés idõre
 a program nem csak belülrõl, a kódot nézve átláthatatlan, de még "játszva" is :) 

		            |    |    |
             )_)  )_)  )_)
            )___))___))___)\
           )____)____)_____)\\
         _____|____|____|____\\\__
---------\                   /---------
  ^^^^^ ^^^^^^^^^^^^^^^^^^^^^
    ^^^^      ^^^^     ^^^    ^^
         ^^^^      ^^^

...A program mukodesenek megertesehez ajanlom eloszor a main fuggvennyel kezdje az olvasast a felhasznalo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "asciikodok.h"
#include "logo.h"
#include "matrixrajzol.h"
#include "hajolerakas.h"

int ellenorzes(char **mx, int palyameret) {  //Ez a fuggveny arra szolgal, hogy a jateknak vege kell legyen
	int i, j, shotz;						//az osszes hajo kilovese utan -> ellenorizzuk a palyan levo
	shotz = 1;							   //osszes 'hajora loves' karaktert (-4), es ha annyi mint a hajok szama...
	switch(palyameret) {
		case 5:
			for(i=0;i<=palyameret+2;i++) {			
				for(j=0;j<=palyameret+2;j++) {
					if(mx[i][j] == -4)
						shotz+=1;
				}
			}
		if(shotz >= 10)
			return 0;
		break;
		case 6:
			for(i=0;i<=palyameret+2;i++) {
				for(j=0;j<=palyameret+2;j++) {
					if(mx[i][j] == -4)
						shotz+=1;
				}
			}
		if(shotz >= 15)
			return 0;
		break;
		case 7:
			for(i=0;i<palyameret+2;i++) {
				for(j=0;j<palyameret+2;j++) {
					if(mx[i][j] == -4)
						shotz+=1;
				}
			}
		break;
		if(shotz >= 20)
			return 0;
		case 8:
			for(i=0;i<=palyameret+2;i++) {
				for(j=0;j<=palyameret+2;j++) {
					if(mx[i][j] == -4)
						shotz+=1;
				}
			}
		if(shotz >= 23)
			return 0;
		break;
	}
	return shotz;
}
int cpushot(char **mx, int palyameret) {   //Az ellenfel lovese
	int i = 0;
	int x, y;
	srand( (unsigned)time( NULL ) );		//Hogy tenyleg mindig "random" legyen
	x = 2 + (rand() % (palyameret));	   //Sajnos csak randomra lo a mi draga ellenfelunk, de ez minket ne zavarjon
	y = 2 + (rand() % (palyameret));
	if(mx[x][y] == -2) {				//Ha hajó 
		printf("\nHopp! Egy talalat ert minket!");
		mx[x][y] = -4;
	}
	else if(mx[x][y] == 0) {  // Ha víz
		mx[x][y] = -3;
		printf("\nAz ellenfel vizbe lott!");
	}	
	else {
		return cpushot(mx, palyameret);
	}
	return 0;
}
void playershot(char **mx) {  //Fuggveny a mi lovesunkhoz

	int i;
	char shot[3];
	shot[0] = '\0';
	printf("\nA loveshez kerek egy xy koordinatat (pl. e4)!\t");
			scanf("%s", shot);
				//Konvertaljuk a  betuvel jelzett x koordinatat számmá
		switch(shot[0]) {
			case 'a':
				shot[0] = '1';
			break;
			case 'b':
				shot[0] = '2';
			break;
			case 'c':
				shot[0] = '3';
			break;
			case 'd':
				shot[0] = '4';
			break;
			case 'e':
				shot[0] = '5';
			break;
			case 'f':
				shot[0] = '6';
			break;
			case 'g':
				shot[0] = '7';
			break;
			case 'h':
				shot[0] = '8';
			break;
		}
		if(mx[(shot[1] - '0')+1][(shot[0] - '0')+1] == 0){  //Ha vizbe lo - lovest tesz a viz helyere
			mx[(shot[1] - '0')+1][(shot[0] - '0')+1] = -3;
			printf("\nSajnos nem talalt!");
		}
		else if(mx[(shot[1] - '0')+1][(shot[0] - '0')+1] == -5){ //Ha meg hajoba akkor kiirjuk h talalt!
			printf("\nTALALT!");
			mx[(shot[1] - '0')+1][(shot[0] - '0')+1] = -4;} 
		else {
			printf("\nNe ossze vissza keremszepen!");
			return playershot(mx);
		}
}
int tablarajzol(char jatekos[], char **mx, int n) {  //Függvény a pálya kirajzolásához
		int i, j;
		printf("\n\n\t");
		for(i=0;i<18;i++)
		printf("%c", jatekos[i]);
		printf("\n\n");
		for(i=0;i<n;i++) {
			printf("\t");
			for(j=0;j<n;j++) {
					if(mx[i][j] == 0)			//0-> viz
						printf("%c ",176);		
					else if(mx[i][j] == -1)		//-1 -> pálya széle
						printf("%c ",219);
					else if(mx[i][j] == -3)	    //-3 -> lövés vízbe
						printf("%c ",1);
					else if(mx[i][j] == -2)     //-2 -> hajó
						printf("%c ",15);
					else if(mx[i][j] == -4)     //-4 -> lövés hajóra
						printf("%c ",2);
					else if(mx[i][j] == -5)     //-5 az ellenfél által lerakott hajók
						printf("%c ",176);
					else						
						printf("%c ", mx[i][j]);
		}
			printf("\n\n");
		}
		return 0;
}

int main(void) {

	char jatekos1[18] = { "                  " };
	char cpu[18] = { "       A LOVESEINK" };
	int rajzhiba = 0;
	char **mx = NULL;				//A matrix amiben taroljuk a sajat hajokat es az ellenfel loveseit
	char **mx2 = NULL;				//A matrix amiben taroljuk az ellenfel hajoit es a loveseinket
	int n = 2;
	char re[3];
	char re2[3] = { "re" };			//A jatek ujrakezdesehez szukseges sztringvizsgalat
	int palyameret;					//A palya merete 5v6v7v8 egyseg - tobb fuggveny is hasznalja a valtozot
	int mem;
	int set1 = 1;					//A minket ert lovesek szama - ellenorzes a "jatek vege" kivizsgalaskor
	int set2 = 1;					//Az ellenfelet ert lovesek szama -||-
	int hajok = 0;
	char hajo_1[2] = { 4 };			//Hajo valtozok - csak karaketerek, amik hajo kinezetuek :)
	char hajo_2[3] = { 17, 16 };
	char hajo_3[4] = { 17, 15, 16 };
	char hajo_4[5] = { 17, 15, 15, 16 };
	char hajo_5[6] = { 17, 15, 15, 15, 16 };
	char hajo_6[7] = { 17, 15, 15, 15, 15, 16 };
	mem = n+15;

	mx = (char**)(malloc(mem*sizeof(char*)));
	mx2 = (char**)(malloc(mem*sizeof(char*)));
	logo();
	while(n > 8 || n < 5) {
		printf("\n\nKerlek add meg a palya meretet! (5-8)\t");
		scanf("%d", &n);
	}
	palyameret = n;
	printf("\nEnnel a palyameretnel (%d*%d) a kovetkezo kombinacioban rakhatsz le hajokat:\n\n\t", n, n);
	switch (n){
		case 5:
			printf("%s %s %s %s %s",hajo_3, hajo_3, hajo_2, hajo_1, hajo_1 );
			break;
		case 6:
			printf("%s %s %s %s %s %s ",hajo_4, hajo_3, hajo_3, hajo_2, hajo_2, hajo_1 );
			break;
		case 7:
			printf("%s %s %s %s %s %s %s",hajo_5, hajo_4, hajo_3, hajo_3, hajo_2, hajo_2, hajo_1 );
			break;
		case 8:
			printf("%s %s %s %s %s %s %s",hajo_6, hajo_5, hajo_4, hajo_3, hajo_2, hajo_2, hajo_1 );
			break;
	}
	n+=4;
	printf("\n\n\nJatekos neve:\t");
	scanf("%s", &jatekos1);
	matrix(n, mem, mx);					//A jatek felepitese - matrixoknak foglalunk helyet
		matrix(n, mem, mx2);				
			keretrajzol(n, mx);				//keretet es szamozast/betuzest rajzolunk
				keretrajzol(n, mx2);
					tablarajzol(jatekos1, mx, n);		//kirajzoljuk a jetekteret
						hajoletesz(mx, palyameret);			//Lerakunk hajokat
							tablarajzol(jatekos1, mx, n);		//Kirajzoljuk a tablat hajoinkkal
								cpuleteszhajokat(mx2, palyameret);		//A gep is lerak hajokat
	do{							//A jatek menete - egyet mi lovunk, egyet a gep kozben kirajzoljuk a tablakat
		playershot(mx2);
		tablarajzol(cpu, mx2, n);
		printf("_____________________________________________________");	//egy kis design
		cpushot(mx, palyameret);
		tablarajzol(jatekos1, mx, n);
		set1 = ellenorzes(mx, palyameret);
		set2 = ellenorzes(mx2, palyameret);
		if(set1 == 0 || set2 == 0)
			;
		else {
			printf("\n\n\tA jatek allasa: %d loves talalt minket, %d lovesunk talalt celba\n",set1-1, set2-1);
		}
	}while(set1 != 0 && set2 != 0);
	printf("\n%s", set1 < set2 ? "Sajnalom, nem nyertel, talan majd legkozelebb" : "Gratulalok, nyertel"); 
	
	printf("\n\n\nHa van kedved meg1et jatszani, ird be hogy  're' (aposztrof nelkul)\n");
	mxfree(mx, n);
	mxfree(mx2, n);
	scanf("%s", re);
	if(!strcmp(re, re2))		//Kivizsgaljuk hogy azt irta e be hogy "re" - ekkor regame lesz :)
		return main();
	else
		exit(-1);
}

