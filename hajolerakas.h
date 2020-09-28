void hajokonvert(char milyenhajo[]) {

	// A fuggveny atkonvertalja a bekert hajokoordinatakat betu(x) szam(y) alakbol szam-szam alakba
	int i;
	for(i=0;i<40;i++) {
		switch(milyenhajo[i]) {
			case 'a':
				milyenhajo[i] = '1';
			break;
			case 'b':
				milyenhajo[i] = '2';
			break;
			case 'c':
				milyenhajo[i] = '3';
			break;
			case 'd':
				milyenhajo[i] = '4';
			break;
			case 'e':
				milyenhajo[i] = '5';
			break;
			case 'f':
				milyenhajo[i] = '6';
			break;
			case 'g':
				milyenhajo[i] = '7';
			break;
			case 'h':
				milyenhajo[i] = '8';
			break;
		}
	}
		}


int hajoletesz(char **mx, int mapsize) {
		
	// A lerakando hajok koordinatait eloszor bekerjuk betu-szam alakban, a palya meretetol fuggoen!
	// majd atkonvertaljuk a hajokonvert fuggvennyel szam-szam alakba, majd felfuzzuk egy nagy valtozoba
	// Azon nemes celbol hogy a matrixunkba be lehessen tenni :>

		int i, j;
		char hajo6_1[13], hajo5_1[11], hajo4_1[9], hajo3_1[7];
		char hajo3_2[7], hajo2_1[5], hajo2_2[5], hajo1_1[3], hajo1_2[3], hajok[64];
		hajo6_1[0] = '\0';
		hajo5_1[0] = '\0';
		hajo4_1[0] = '\0';
		hajo3_1[0] = '\0';
		hajo3_2[0] = '\0';
		hajo2_1[0] = '\0';
		hajo2_2[0] = '\0';
		hajo1_1[0] = '\0';
		hajo1_2[0] = '\0';
		switch(mapsize) {
		case 5:
		printf("\nElso 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", hajo3_1);
		hajokonvert(hajo3_1);

		printf("\nMasodik 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", hajo3_2);
		hajokonvert(hajo3_2);

		printf("\nA 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", hajo2_1);
		hajokonvert(hajo2_1);

		printf("\nAz elso 1hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", hajo1_1);
		hajokonvert(hajo1_1);

		printf("\nA masodik 1hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", hajo1_2);
		hajokonvert(hajo1_2);
		break;

		case 6:
		printf("\n4hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo4_1);
		hajokonvert(hajo4_1);

		printf("\nElso 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo3_1);
		hajokonvert(hajo3_1);

		printf("\nMasodik 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo3_2);
		hajokonvert(hajo3_2);

		printf("\nAz elso 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_1);
		hajokonvert(hajo2_1);

		printf("\nA masodik 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_2);
		hajokonvert(hajo2_2);

		printf("\nAz 1hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo1_1);
		hajokonvert(hajo1_1);
		break;

		case 7:
		printf("\n5hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo5_1);
		hajokonvert(hajo5_1);


		printf("\n4hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo4_1);
		hajokonvert(hajo4_1);

		printf("\nElso 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo3_1);
		hajokonvert(hajo3_1);

		printf("\nMasodik 3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo3_2);
		hajokonvert(hajo3_2);

		printf("\nAz elso 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_1);
		hajokonvert(hajo2_1);

		printf("\nA masodik 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_2);
		hajokonvert(hajo2_2);

		printf("\nAz 1hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo1_1);
		hajokonvert(hajo1_1);
		break;

		case 8:
		printf("\n6hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo6_1);
		hajokonvert(hajo6_1);

		printf("\n5hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo5_1);
		hajokonvert(hajo5_1);

		printf("\n4hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo4_1);
		hajokonvert(hajo4_1);

		printf("\n3hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo3_1);
		hajokonvert(hajo3_1);

		printf("\nAz elso 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_1);
		hajokonvert(hajo2_1);

		printf("\nA masodik 2hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo2_2);
		hajokonvert(hajo2_2);

		printf("\nAz 1hosszu hajo helye: (formatum pl: a1b1c1)\t");
		scanf("%s", &hajo1_1);
		hajokonvert(hajo1_1);
		break;
		}
		//A hajo valtozok bekerulnek egy nagy tombbe!
		i=0;
			for(j=0;hajo6_1[j] != '\0';j++) 
				hajok[i++] = hajo6_1[j];
			for(j=0;hajo5_1[j] != '\0';j++) 
				hajok[i++] = hajo5_1[j];
			for(j=0;hajo4_1[j] != '\0';j++) 
				hajok[i++] = hajo4_1[j];
			for(j=0;hajo3_1[j] != '\0';j++)
				hajok[i++] = hajo3_1[j];
			for(j=0;hajo3_2[j] != '\0';j++) 
				hajok[i++] = hajo3_2[j];
			for(j=0;hajo2_1[j] != '\0';j++) 
				hajok[i++] = hajo2_1[j];
			for(j=0;hajo2_2[j] != '\0';j++) 
				hajok[i++] = hajo2_2[j];
			for(j=0;hajo1_1[j] != '\0';j++) 
				hajok[i++] = hajo1_1[j];
			for(j=0;hajo1_2[j] != '\0';j++) 
				hajok[i++] = hajo1_2[j];
		hajok[i] = '\0';
		//Most pedig berakjuk a matrixba a hajokat
			for(i=0;hajok[i] !=  '\0';i+=2) {
				mx[(hajok[i+1]-'0')+1][(hajok[i]-'0')+1] = -2;
			}
		return 1;
}

void cpuleteszhajokat(char **mx, int palyameret) {
	
	int i = 0;
	int x, y;
	srand( (unsigned)time( NULL ) );

	switch(palyameret) {
		case 5:
			for(i=0;i<10;++i){
		x = 2 + (rand() % (palyameret));
		y = 2 + (rand() % (palyameret));
		if(mx[x][y] == -5)
			i--;
		else
			mx[x][y] = -5;
			}
		break;
		case 6:
			for(i=0;i<15;++i){
		x = 2 + (rand() % (palyameret));
		y = 2 + (rand() % (palyameret));
		if(mx[x][y] == -5)
			i--;
		else
			mx[x][y] = -5;
			}
		break;
		case 7:
			for(i=0;i<20;++i){
		x = 2 + (rand() % (palyameret));
		y = 2 + (rand() % (palyameret));
		if(mx[x][y] == -5)
			i--;
		else
			mx[x][y] = -5;
			}
		break;
		case 8:
			for(i=0;i<23;++i){
		x = 2 + (rand() % (palyameret));
		y = 2 + (rand() % (palyameret));
		if(mx[x][y] == -5)
			i--;
		else
			mx[x][y] = -5;
		break;
			}
	}
	printf("\n A gep 'sikeresen' lerakta a hajoit! - KEZDODHET A JATEK!");
}