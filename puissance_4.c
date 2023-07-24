#include <stdio.h>

void Plateau_jeu(int M[][7])
{
    int i, j;
    printf("\n          +-1-+-2-+-3-+-4-+-5-+-6-+-7-+\n");
    printf("          +---+---+---+---+---+---+---+\n");
    for (i = 0; i < 6; i++)
    {
        printf("          ");
        for (j = 0; j < 7; j++)
        {

            printf("|");
            if (M[i][j] == 0)
                printf("   ");
            if (M[i][j] == 1)
                printf(" x ");
            if (M[i][j] == 2)
                printf(" O ");
        }
        printf("|\n          +---+---+---+---+---+---+---+\n");
    }
}

int gagnant(int M[][7])
{
    for ( int i =5 ; i >= 0; i--)
            {
                for ( int j = 0; j < 7; j++)
                {   
                    if (M[i][j] == 2)
                    {
                        if (M[(i-1)][(j-1)] == 2 && M[(i-2)][(j-2)] == 2 && M[(i-3)][(j-3)] == 2 && (j-3)<7 && (i-3)>=0)
                        {
                            printf("Joueur 2 gagnant\n");
                            return 1;
                        }
                        else if (M[(i-1)][(j+1)] == 2 && M[(i-2)][(j+2)] == 2 && M[(i-3)][(j+3)] == 2 && (j+3)<7 && (i-3)>=0)
                        {
                            printf("Joueur 2 gagnant\n");
                            return 1;
                        }
                        if (M[i][j+1] == 2 && M[i][j+2] == 2 && M[i][j+3] == 2)
                        {
                            printf("Joueur 2 gagnant\n");
                            return 1;
                        }
                        if (M[i-1][j] == 2 && M[i-2][j] == 2 && M[i-3][j] == 2)
                        {
                            printf("Joueur 2 gagnant\n");
                            return 1;
                        }
                    }
                    if (M[i][j] == 1)
                    {
                        if (M[i-1][j-1] == 1 && M[i-2][j-2] == 1 && M[i-3][j-3] == 1 && (j-3)<7 && (i-3)>=0)
                        {
                            printf("Joueur 1 gagnant\n");
                            return 1;
                        }
                        if (M[i-1][j+1] == 1 && M[i-2][j+2] == 1 && M[i-3][j+3] == 1 && (j+3)<7 && (i-3)>=0)
                        {
                            printf("Joueur 1 gagnant\n");
                            return 1;
                        }
                        if (M[i][j+1] == 1 && M[i][j+2] == 1 && M[i][j+3] == 1)
                        {
                            printf("Joueur 1 gagnant\n");
                            return 1;
                        }
                        if (M[i-1][j] == 1 && M[i-2][j] == 1 && M[i-3][j] == 1)
                        {
                            printf("Joueur 1 gagnant\n");
                            return 1;
                        }    
                    }
                }
            }
}

int main()
{
    int M[6][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
    int test = 1, playeur, ligne, colone, lig;
    int lower = 1, upper = 7;
    int choix = 0;
    printf("---- Puissance 4 ----\n\n\n");
    printf("Voulez vous jouer avec bot ou sans bot? \n");
    printf("Avec Bot:1 \nSans Bot:2\n");
    printf("Réponse: ");
    scanf("%d", &choix);
    int col;
    int essais = 1;
    Plateau_jeu(M);
    
    while (essais<= 41)
    {
        for (playeur = 1; playeur <= 2; playeur++)
        {
            printf("Joueur 1: X\nJoueur 2: O\n");
            printf("Joueur numero %d  :\n", playeur);

            if (playeur == 1)
            {
                do
                {
                    printf("Donner le numero de la colonne soit 1,2 ou 3   :  ");
                    scanf("%d", &colone);
                    printf("\nvaleur de colonne %d\n",colone);
                } while (colone > 7);
                printf("%d\n",colone);
            }
            else{
                if (choix == 2)
                {
                    do
                    {
                        printf("Donner le numero de la colonne soit 1,2 ou 3   :  ");
                        scanf("%d", &colone);
                        printf("\nvaleur de colonne %d\n",colone);
                    } while (colone > 7);
                    printf("%d\n",colone);
                }
                else{
                    srand(time(0));
                    colone = (rand() % (upper - lower + 1)) + lower;
                    printf("%d ", colone);
                }
            }
            for ( col = colone-1; col <= colone-1; col++)
            {
                for ( lig = 0; lig < 6; lig++)
                {
                        if (M[lig][col] == 1 || M[lig][col] == 2)
                        {
                            if(lig == 0)
                            {
                                printf("la colonne est pleine !\n");
                                playeur-- ;
                                break;
                            }
                            M[lig-1][col] = playeur;
                            break;
                        }
                        
                }
                break;
            }
            if (M[lig-1 ][col] == 0)
            {   
                M[lig-1][col] = playeur;
                test++;
               // choix = 1;
            }
            Plateau_jeu(M);
            if (gagnant(M)== 1)
            {
                return 0;
            }
            essais++;
        }
    }
    printf("égalité\n");
    return 0;
}
