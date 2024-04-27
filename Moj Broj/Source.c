#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int BrojGenerator(int max, int min)
{
	Sleep(200);
	int broj;

	broj = (rand() * 2134532) % (max + 1 - min) + min;

	if (broj == 0)
	{
		return 1;
	}
	return abs(broj);
}

struct HighScore
{
	int currentScore;
	int highScore;
};

void ScoreUpdate(struct HighScore* s)
{
	s -> currentScore += 1;
}

void ScoreReset(struct HighScore* s)
{
	s -> currentScore = 0;
}

int ReadScore(struct HighScore s)
{
	return s.currentScore;
}

int ReadHighScore()
{
	FILE* f;

	int highScore;

	f = fopen("HighScore.txt", "r");

	if (f == NULL) {
		printf("Not able to open the file.");
	}
	else
	{
		fscanf(f, "%d", &highScore);
		fclose(f);
		return highScore;
	}

	fclose(f);
}

void WriteHighScore(struct HighScore s)
{
	FILE* f;

	f = fopen("HighScore.txt", "w");

	if (f == NULL) {
		printf("Not able to open the file.");
	}
	else
	{
		fprintf(f, "%d", s.currentScore);
	}

	fclose(f);
}

int main()
{
	srand(time(NULL));

	int glavniBroj;
	int brojevi[6];
	char unos;
	char* unosptr = &unos;
	char* unosi = calloc(0, sizeof(char));
	char repeat = 'y';
	char zagradaZnak = '0';

	char hs[] = "HighScore: ";

	struct HighScore score;

	score.currentScore = 0;

	while (repeat == 'y')
	{
		int velicina = 0;
		int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, broj = 0, zagrada = 0, zagradaOtvorena = 0;
		*unosptr = '0';
		char poslednjiUnos = '0';

		score.highScore = ReadHighScore();

		glavniBroj = BrojGenerator(999, 1);

		for (int i = 0; i <= 3; i++)
		{
			brojevi[i] = BrojGenerator(9, 1);
		}

		brojevi[4] = BrojGenerator(4, 2) * 5;
		brojevi[5] = (rand() % (4 + 1 - 1) + 1) * 25;

		if (brojevi[4] == 5)
		{
			brojevi[4] = 10;
		}

		while ((*unosptr != 'f') && (*unosptr != 'F'))
		{
			system("cls");

			printf("                ---\n               |%d|\n                ---\n", glavniBroj);

			printf("  -    -    -    -    --    ---\n");
			for (int i = 0; i < 6; i++)
			{
				printf(" |%d| ",brojevi[i]);
			}
			printf("\n");
			printf("  -    -    -    -    --    ---\n");
			for (int i = 1; i < 5; i++)
			{
				printf("  %d  ", i);
			}
			for (int i = 5; i < 7; i++)
			{
				printf("   %d  ", i);
			}
			printf("\n\n");

			printf("Unesite vase resenje (pritisnite f da bi zavrsili): \n");

			for (int i = 0; i < velicina; i++)
			{
				if (unosi[i] == '+' || unosi[i] == '-' || unosi[i] == '*' || unosi[i] == '/' || unosi[i] == '(' || unosi[i] == ')')
				{
					printf("%c ", unosi[i]);
				}
				else
				{
					printf("%d ", unosi[i]);
				}
			}

			*unosptr = getch();

			switch (*unosptr)
			{
			case '1':
				if (n1 == 0 && (poslednjiUnos != '2' && poslednjiUnos != '3' && poslednjiUnos != '4' && poslednjiUnos != '5' && poslednjiUnos != '6' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[0];
					velicina++;
					poslednjiUnos = '1';
					n1 = 1;
				}
				break;
			case '2':
				if (n2 == 0 && (poslednjiUnos != '1' && poslednjiUnos != '3' && poslednjiUnos != '4' && poslednjiUnos != '5' && poslednjiUnos != '6' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[1];
					velicina++;
					poslednjiUnos = '2';
					n2 = 1;
				}
				break;
			case '3':
				if (n3 == 0 && (poslednjiUnos != '2' && poslednjiUnos != '1' && poslednjiUnos != '4' && poslednjiUnos != '5' && poslednjiUnos != '6' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[2];
					velicina++;
					poslednjiUnos = '3';
					n3 = 1;
				}
				break;
			case '4':
				if (n4 == 0 && (poslednjiUnos != '2' && poslednjiUnos != '3' && poslednjiUnos != '1' && poslednjiUnos != '5' && poslednjiUnos != '6' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[3];
					velicina++;
					poslednjiUnos = '4';
					n4 = 1;
				}
				break;
			case '5':
				if (n5 == 0 && (poslednjiUnos != '2' && poslednjiUnos != '3' && poslednjiUnos != '4' && poslednjiUnos != '1' && poslednjiUnos != '6' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[4];
					velicina++;
					poslednjiUnos = '5';
					n5 = 1;
				}
				break;
			case '6':
				if (n6 == 0 && (poslednjiUnos != '2' && poslednjiUnos != '3' && poslednjiUnos != '4' && poslednjiUnos != '5' && poslednjiUnos != '1' || poslednjiUnos == '+' || poslednjiUnos == '-' || poslednjiUnos == '*' || poslednjiUnos == '/' || poslednjiUnos == '(' || poslednjiUnos == ')'))
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = brojevi[5];
					velicina++;
					poslednjiUnos = '6';
					n6 = 1;
				}
				break;
			case '+':
				if (poslednjiUnos != '+' && poslednjiUnos != '-' && poslednjiUnos != '*' && poslednjiUnos != '/' && poslednjiUnos != '(')
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = '+';
					velicina++;
					poslednjiUnos = '+';
				}
				break;
			case '-':
				if (poslednjiUnos != '+' && poslednjiUnos != '-' && poslednjiUnos != '*' && poslednjiUnos != '/')
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = '-';
					velicina++;
					poslednjiUnos = '-';
				}
				break;
			case '*':
				if (poslednjiUnos != '+' && poslednjiUnos != '-' && poslednjiUnos != '*' && poslednjiUnos != '/' && poslednjiUnos != '(')
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = '*';
					velicina++;
					poslednjiUnos = '*';
				}
				break;
			case '/':
				if (poslednjiUnos != '+' && poslednjiUnos != '-' && poslednjiUnos != '*' && poslednjiUnos != '/' && poslednjiUnos != '(')
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = '/';
					velicina++;
					poslednjiUnos = '/';
				}
				break;
			case '(':
				if (poslednjiUnos != ')' && poslednjiUnos != '(' && poslednjiUnos != '1' && poslednjiUnos != '2' && poslednjiUnos != '3' && poslednjiUnos != '4' && poslednjiUnos != '5' && poslednjiUnos != '6' && zagradaOtvorena == 0)
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = '(';
					velicina++;
					poslednjiUnos = '(';
					zagradaOtvorena = 1;
				}
				break;
			case ')':
				if (poslednjiUnos != '+' && poslednjiUnos != '-' && poslednjiUnos != '*' && poslednjiUnos != '/' && poslednjiUnos != '(' && zagradaOtvorena == 1)
				{
					unosi = realloc(unosi, (velicina + 1) * sizeof(char));
					unosi[velicina] = ')';
					velicina++;
					poslednjiUnos = ')';
					zagradaOtvorena = 0;
				}
				break;
			case 'd':
				if (velicina != 0)
				{
					if (unosi[velicina - 1] == brojevi[0])
					{
						n1 = 0;
					}
					else if (unosi[velicina - 1] == brojevi[1])
					{
						n2 = 0;
					}
					else if (unosi[velicina - 1] == brojevi[2])
					{
						n3 = 0;
					}
					else if (unosi[velicina - 1] == (char)brojevi[3])
					{
						n4 = 0;
					}
					else if (unosi[velicina - 1] == (char)brojevi[4])
					{
						n5 = 0;
					}
					else if (unosi[velicina - 1] == (char)brojevi[5])
					{
						n6 = 0;
					}
					unosi = realloc(unosi, (velicina - 1) * sizeof(char));
					velicina--;
					poslednjiUnos = 'd';
				}
				break;
			}
		}
		int brojac = 0;
		if (unosi[brojac] == brojevi[0])
		{
			broj = brojevi[0];
			brojac++;
		}
		else if (unosi[brojac] == brojevi[1])
		{
			broj = brojevi[1];
			brojac++;
		}
		else if (unosi[brojac] == brojevi[2])
		{
			broj = brojevi[2];
			brojac++;
		}
		else if (unosi[brojac] == brojevi[3])
		{
			broj = brojevi[3];
			brojac++;
		}
		else if (unosi[brojac] == brojevi[4])
		{
			broj = brojevi[4];
			brojac++;
		}
		else if (unosi[brojac] == brojevi[5])
		{
			broj = brojevi[5];
			brojac++;
		}
		for (brojac; brojac < velicina - 1;)
		{
				if (unosi[brojac] == '+')
			{
				if (unosi[brojac + 1] == brojevi[0])
				{
					broj += brojevi[0];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[1])
				{
					broj += brojevi[1];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[2])
				{
					broj += brojevi[2];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[3])
				{
					broj += brojevi[3];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[4])
				{
					broj += brojevi[4];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[5])
				{
					broj += brojevi[5];
					brojac += 2;
				}
				else
				{
					brojac++;
				}
			}
			else if (unosi[brojac] == '-')
			{
				if (unosi[brojac + 1] == brojevi[0])
				{
					broj -= brojevi[0];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[1])
				{
					broj -= brojevi[1];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[2])
				{
					broj -= brojevi[2];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[3])
				{
					broj -= brojevi[3];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[4])
				{
					broj -= brojevi[4];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[5])
				{
					broj -= brojevi[5];
					brojac += 2;
				}
				else
				{
					brojac++;
				}
			}
			else if (unosi[brojac] == '*')
			{
				if (unosi[brojac + 1] == brojevi[0])
				{
					broj *= brojevi[0];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[1])
				{
					broj *= brojevi[1];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[2])
				{
					broj *= brojevi[2];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[3])
				{
					broj *= brojevi[3];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[4])
				{
					broj *= brojevi[4];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[5])
				{
					broj *= brojevi[5];
					brojac += 2;
				}
				else
				{
					brojac++;
				}
			}
			else if (unosi[brojac] == '/')
			{
				if (unosi[brojac + 1] == brojevi[0])
				{
					broj /= brojevi[0];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[1])
				{
					broj /= brojevi[1];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == brojevi[2])
				{
					broj /= brojevi[2];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[3])
				{
					broj /= brojevi[3];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[4])
				{
					broj /= brojevi[4];
					brojac += 2;
				}
				else if (unosi[brojac + 1] == (char)brojevi[5])
				{
					broj /= brojevi[5];
					brojac += 2;
				}
				else
				{
					brojac++;
				}
			}
			else if (unosi[brojac] == '(')
			{
				if (unosi[brojac - 1] == '+')
				{
					zagradaZnak = '+';
				}
				else if (unosi[brojac - 1] == '-')
				{
					zagradaZnak = '-';
				}
				else if (unosi[brojac - 1] == '*')
				{
					zagradaZnak = '*';
				}
				else if (unosi[brojac - 1] == '/')
				{
					zagradaZnak = '/';
				}
				while (unosi[brojac] != ')')
				{
					if (unosi[brojac] == '+')
					{
						if (unosi[brojac + 1] == brojevi[0])
						{
							zagrada += brojevi[0];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[1])
						{
							zagrada += brojevi[1];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[2])
						{
							zagrada += brojevi[2];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[3])
						{
							zagrada += brojevi[3];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[4])
						{
							zagrada += brojevi[4];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[5])
						{
							zagrada += brojevi[5];
							brojac += 2;
						}
						else
						{
							brojac++;
						}
					}
					else if (unosi[brojac] == '-')
					{
						if (unosi[brojac + 1] == brojevi[0])
						{
							zagrada -= brojevi[0];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[1])
						{
							zagrada -= brojevi[1];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[2])
						{
							zagrada -= brojevi[2];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[3])
						{
							zagrada -= brojevi[3];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[4])
						{
							zagrada -= brojevi[4];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[5])
						{
							zagrada -= brojevi[5];
							brojac += 2;
						}
						else
						{
							brojac++;
						}
					}
					else if (unosi[brojac] == '*')
					{
						if (unosi[brojac + 1] == brojevi[0])
						{
							zagrada *= brojevi[0];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[1])
						{
							zagrada *= brojevi[1];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[2])
						{
							zagrada *= brojevi[2];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[3])
						{
							zagrada *= brojevi[3];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[4])
						{
							zagrada *= brojevi[4];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[5])
						{
							zagrada *= brojevi[5];
							brojac += 2;
						}
						else
						{
							brojac++;
						}
					}
					else if (unosi[brojac] == '/')
					{
						if (unosi[brojac + 1] == brojevi[0])
						{
							zagrada /= brojevi[0];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[1])
						{
							zagrada /= brojevi[1];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == brojevi[2])
						{
							zagrada /= brojevi[2];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[3])
						{
							zagrada /= brojevi[3];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[4])
						{
							zagrada /= brojevi[4];
							brojac += 2;
						}
						else if (unosi[brojac + 1] == (char)brojevi[5])
						{
							zagrada /= brojevi[5];
							brojac += 2;
						}
						else
						{
							brojac++;
						}
					}
					else if (unosi[brojac] == brojevi[0])
					{
						zagrada = brojevi[0];
						brojac++;
					}
					else if (unosi[brojac] == brojevi[1])
					{
						zagrada = brojevi[1];
						brojac++;
					}
					else if (unosi[brojac] == brojevi[2])
					{
						zagrada = brojevi[2];
						brojac++;
					}
					else if (unosi[brojac] == brojevi[3])
					{
						zagrada = brojevi[3];
						brojac++;
					}
					else if (unosi[brojac] == brojevi[4])
					{
						zagrada = brojevi[4];
						brojac++;
					}
					else if (unosi[brojac] == brojevi[5])
					{
						zagrada = brojevi[5];
						brojac++;
					}
					else
					{
						brojac++;
					}
				}
			}
			else if (unosi[brojac] == ')')
			{	
				if (zagradaZnak == '+')
				{
					broj += zagrada;
				}
				else if (zagradaZnak == '-')
				{
					broj -= zagrada;
				}
				else if (zagradaZnak == '*')
				{
					broj *= zagrada;
				}
				else if (zagradaZnak == '/')
				{
					broj /= zagrada;
				}
				zagrada = 0;
				brojac++;
			}
		}
		printf("Vas broj je %d \n", broj);
		if (broj == glavniBroj)
		{
			ScoreUpdate(&score);
			if (score.currentScore > score.highScore)
			{
				WriteHighScore(score);
				score.highScore = ReadHighScore();
			}
			printf("Pobedili ste, vas trenutni score je %d \n \n", score.currentScore);
			printf("HighScore: %d \n", score.highScore);
		}
		else
		{
			printf("Izgubili ste \n");
			if (score.currentScore > score.highScore)
			{
				WriteHighScore(score);
				score.highScore = ReadHighScore();
			}
			printf("%s %d \n", hs, score.highScore);
			ScoreReset(&score);
		}



		printf("Da li zelite da nastavite? (y/n) \n");
		repeat = getch();
		while (repeat != 'y' && repeat != 'n')
		{
			printf("Los unos, probajte ponovo. \n");
			repeat = getch();
		}
		unosi = realloc(0, sizeof(char));
		system("cls");
	}
}