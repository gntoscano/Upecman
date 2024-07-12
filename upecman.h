/***************************************************************************
 *   upecman.h                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION
#define VERSION "20160529.013231" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */
#define LABL 23 /**< Number of lines in labyrinth */
#define LABC 21 /**< Number of columns in labyrinth */

// fantasmas //
#define direita 1
#define esquerda 2
#define baixo 3
#define cim 4

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

const char labmodel[LABL][LABC] =
{
    /*01234567890123456789*/
    {"####################"},    /* 0*/
    {"#........##........#"},    /* 1*/
    {"#o##.###.##.###.##o#"},    /* 2*/
    {"#..................#"},    /* 3*/
    {"#.##.#.######.#.##.#"},    /* 4*/
    {"#....#...##...#....#"},    /* 5*/
    {"####.###.##.###.####"},    /* 6*/
    {"   #.#... ....#.#   "},    /* 7*/
    {"   #.#.##--##.#.#   "},    /* 8*/
    {"####.#.#    #.#.####"},    /* 9*/
    {"    ...#    #...    "},    /*10*/
    {"####.#.#    #.#.####"},    /*11*/
    {"   #.#.######.#.#   "},    /*12*/
    {"   #.#........#.#   "},    /*13*/
    {"####.#.######.#.####"},    /*14*/
    {"#........##........#"},    /*15*/
    {"#o##.###.##.###.##o#"},    /*16*/
    {"#..#..... ......#..#"},    /*17*/
    {"##.#.#.######.#.#.##"},    /*18*/
    {"#....#...##...#....#"},    /*19*/
    {"#.######.##.######.#"},    /*20*/
    {"#..................#"},    /*21*/
    {"####################"}     /*22*/
};


typedef enum e_ghostmode {chase, scatter, afraid, dead} t_ghostmode;
typedef enum e_direction {up, left, down, right} t_direction;
typedef enum e_premove {cima, esq, bai, dir} t_premove;
typedef enum e_ghosts {blinky, pinky, inky, clyde} t_ghosts;

typedef struct st_position
{
    int y; /* line */
    int x; /* column */
} t_pos;

typedef struct st_timer
{
    int timeNow; //Tempo atual
    int timeIni; //Tempo inicial do jogo
    int timeAfraid; //Tempo no modo afraid - Variavel em camelcase pra separar as palavras.
} t_timer;

typedef struct st_pacman
{
    t_pos pos; /* current pacman position */
    t_premove premove;
    t_direction dir; /* direction */
    int life; /* how many lifes pacman has */
    int score; /* dot = 10 point; pill = 50 points; ghost = 750 points; cherry = 500 */
    int cherry1, cherry2, cherry3; //Cerejas aparecerem 3 vezes
    int pelota;
} t_pacman;

typedef struct st_ghost
{
    t_pos pos; /* ghost position */
    t_premove premove;
    t_direction dir; /* ghost current direction */
    t_pos starget; /* ghost scatter preferred corner */
    t_ghostmode mode; /* chase, scatter, afraid or dead */
} t_ghost;

typedef struct st_pacdata
{
    char lab[LABL][LABC]; /* the labyrinth map */
    t_pacman pacman; /* pacman data */
    t_ghost ghost[4]; /* ghost[blinky], ghost[pinky], ghost[inky], ghost[clyde] */
    t_timer tempo; /* Conta o tempo do jogo */
} t_game;

int px, py;
clock_t afraid_t;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
t_game upecman_init(void); /* initialize game variables */
void printlab(t_game g);/* print the labyrinth */
t_game pac_move(t_game g); //Funcao do movimento do pacman
t_game comer(t_game g); //Funcao do pacman comer as pelotas
t_game mode_afraid(t_game g); //Funcao que alterna o modo dos fantasmas
t_game blinky_move(t_game g); //Movimento do Blinky
t_game pinky_move(t_game g); //Movimento do Pinky
t_game inky_move(t_game g); //Movimento do Inky
t_game clyde_move(t_game g); //Movimento do Clyde
//t_game chronomode(t_game g);
t_game cherry(t_game g); //Funcao do surgimento das cerejas
t_game derrota(t_game g); //Printa a tela de derrota se o pacman morrer
t_game vitoria(t_game g); //Printa a tela de vitoria se o pacman vencer
void menu(); //Inicializa o menu do jogo
void color_map(t_game g); //Pinta os elementos do mapa
t_game colisao_ghosts(t_game g); //Checa as colisões do pacman com os fantasmas
t_game ghost_mode(t_game g); //Alterna os modos dos fantasmas com o tempo
t_game timer_count(t_game g); //Conta o tempo que rege o jogo
t_game ghostsIA(t_game g, int i); // Inteligencia artificial da movimentacao dos fantasmas
t_game pac_tutorial(t_game g);

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
