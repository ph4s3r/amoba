#include <stdlib.h>

void matrix(int n, int mem, char **mx) {

	int mxhiba = 0;
	int i, j;
		if (mx == NULL) 
		{
		   mxhiba = 1;
		   printf("\nSikertelen helyfoglalás a sorvektorok címei számára!\n");
		}
		else
		{
			for (i = 0; i < n; mx[i++] = NULL);
			for (i = 0; (i < n) && !mxhiba; i++) 
			{
				mx[i] = (char*)(malloc(mem*sizeof(char)));
				mxhiba = (mx[i]==NULL);
				if (mxhiba) printf("\nA(z) %d. sornak nem sikerült memóriát foglalni!\n",i);
			}
		}
		 if (!mxhiba) 
    {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				mx[i][j] = 0;
			}
		}
	}
}

void mxfree(char **mx, int n) {
	int i;
	if (mx != NULL){
        for (i = 0; i < n; i++)
            if (mx[i] != NULL) 
				free(mx[i]);
		free(mx);
        mx = NULL;
	}
}

void keretrajzol(int n, char **mx) {
		//Keret
		int i;
		char betuk[11] ={ 0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
		char szamok[12] ={ 0, '40', '41', '42', '43', '44', '45', '46', '47', '48', '49', '50'};
		//felso + also
		for(i=0;i<n;i++) {
				mx[i][0] = -1;
				mx[i][n-1] = -1;
		}
		for(i=0;i<n;i++) {
				mx[0][i] = -1;
				mx[n-1][i] = -1;
		}
		//Szamozas+betuzes
		for(i=2;i<n-2;i++) {
				mx[i][1] = szamok[i]; //2.oszlop szamai
				mx[i][n-2] = szamok[i]; //utso elotti oszlop szamai
		}
		for(i=1;i<n-2;i++) {
				mx[1][i] = betuk[i-1];
				mx[n-2][i] = betuk[i-1];
		}
}

