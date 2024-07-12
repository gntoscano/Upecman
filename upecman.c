/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
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
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <bits/time.h>
#include <bits/types/clock_t.h>
#include <curses.h>
#include <stdbool.h>
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */
#include <time.h> /* Time and date functions */
#include <math.h> /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
int main(int argc, char *argv[])
{
    menu(); //Menu do jogo
    IFDEBUG("main()\n");
    int opt; /* return from getopt() */
    t_game g; /* the game */
    const char *sready = "Are you ready? (y/n)"; /* ready string */
    int kin; /* keyboard input */

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright & version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hvc")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'c':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    IFDEBUG("Starting the game now...\n");

    g = upecman_init();

    printlab(g);
    mvprintw(10, 25, "%s", sready);
    mvprintw(11, 25, "Press 'q' to end the game! ");

    refresh();

    while(1)
    {
        kin = getch();
        if(kin == 'y' || kin == KEY_LEFT) //Inicia o jogo
            break;
        usleep(16667); /* wait 16666 microseconds to avoid frying the processor (1/60 s) */
        if(kin == 'n') //Encerra o jogo
        {
            endwin();
            return EXIT_SUCCESS;
        }

    }

/*--------------------------------------------------------------------LOOP-DO-JOGO---------------------------------------------------------*/

    while(kin != 'q') //Se o jogador pressionar q, o jogo encerra.
    {
        usleep(250000);

        kin = getch(); //Recebe o input do teclado do jogador
        if(kin == KEY_RIGHT)
            g.pacman.premove = dir; //Recebe o premove
        else if(kin == KEY_LEFT)
            g.pacman.premove = esq;
        else if(kin == KEY_UP)
            g.pacman.premove = cima;
        else if(kin == KEY_DOWN)
            g.pacman.premove = bai;

        IFDEBUG("While main");

        g = pac_move(g);
        printlab(g);
        g = comer(g);
        g = mode_afraid(g);
        g = cherry(g);
        g = ghost_mode(g);
        g = colisao_ghosts(g);
        //g = blinky_move(g);
        //g = pinky_move(g);
        //g = inky_move(g);
        //g = clyde_move(g);

        if(g.pacman.life == 0) //Checa se o pacman perdeu as vias
        {
            clear();
            while(1)
            {
                g = derrota(g); //Chama a tela de derrota
                kin = getch(); //Pega a tecla
                if(kin == 'y') //Pressionar y para reiniciar o jogo
                {
                    g = upecman_init();
                    printlab(g);
                    break;
                }
                if(kin == 'n') //Pressionar n para encerrar o jogo
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
        }

        if(g.pacman.pelota == 187) //Checa se o pacman comeu todas as pelotas disponiveis
        {
            clear();
            while(1)
            {
                g = vitoria(g); //Chama a funcao derrota
                kin = getch(); // Recebe o input do teclado
                if(kin == 'y') //Pressionar y para reiniciar o jogo
                {
                    g = upecman_init();
                    printlab(g);
                    break;
                }
                if(kin == 'n') //Pressionar n para encerrar o jogo
                {
                    endwin();
                    return EXIT_SUCCESS;
                }
            }
        }
        clear();
    }
    clear();
    endwin();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "upecman", "Pacman Ncurses");
    printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/*
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "upecman", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */

/*---------------------------------------------------CONFIGURACOES-INICIAIS----------------------------------------------------------------*/

t_game upecman_init(void)
{
    IFDEBUG("init()");
    /* initialization */

    t_game g;
    int f, y;

    for(y = 0; y < LABL; y++)
        strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

    g.pacman.cherry1 = 0; //Contabiliza as 3 cerejas que aparecem
    g.pacman.cherry2 = 0; //Contabiliza as 3 cerejas que aparecem
    g.pacman.cherry3 = 0; //Contabiliza as 3 cerejas que aparecem

    g.tempo.timeIni = time(NULL);
    g.tempo.timeAfraid = 0;
    g.tempo.timeNow = 0; //Tempo comeca em 0

    g.pacman.premove = esq; //Pacman comeca o jogo para a esquerda
    g.pacman.pos.y = 17; /* pacman start position (line) */
    g.pacman.pos.x = 9; /* pacman start position (column) */
    g.pacman.dir = left; /* pacman start direction */
    g.pacman.life = 3; /* 3 lifes */
    g.pacman.score = 0; /* 0 points */
    g.pacman.pelota = 0; //Pacman comeca o jogo com 0 pelotas

    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
    {
        switch(f)
        {
            case blinky:
                g.ghost[f].pos.y = 7; /* blinky start position (line) */
                g.ghost[f].pos.x = 9; /* blinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case pinky:
                g.ghost[f].pos.y = 9; /* pinky start position (line) */
                g.ghost[f].pos.x = 10; /* pinky start position (column) */
                g.ghost[f].starget.y = 0; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
                break;
            case inky:
                g.ghost[f].pos.y = 10; /* inky start position (line) */
                g.ghost[f].pos.x = 10; /* inky start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 19; /* preferred corner (column) */
                break;
            case clyde:
                g.ghost[f].pos.y = 11; /* clyde start position (line) */
                g.ghost[f].pos.x = 10; /* clyde start position (column) */
                g.ghost[f].starget.y = 22; /* preferred corner (line) */
                g.ghost[f].starget.x = 0; /* preferred corner (column) */
        }
        g.ghost[f].dir = left; /* start direction and future direction: left */
        g.ghost[f].mode = chase;
    }

    initscr(); /* start ncurses mode screen */
    cbreak(); /* stop line buffering */
    keypad(stdscr, TRUE); /* grab extended keys */
    noecho(); /* stop echoing chars */
    timeout(0); /* do not wait */
    start_color(); /* initialize the color functionality */

    /* Initialize all the colors */
    init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
    init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
    init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
    init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
    init_pair(6, COLOR_YELLOW, COLOR_BLACK); /* Pacman */

    return g;
}

/*------------------------------------------------------PACMAN-----------------------------------------------------------------------------*/

t_game pac_move(t_game g) //Movimentacao pacman
{
    IFDEBUG("pac_move");
    int px = 0, py = 0; //Posicoes novas do pacman

    if(!(g.lab[22][20])) //Checa os limites do mapa
    {
        if(g.pacman.premove == esq) //Checa se pode ir para a esquerda
            if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#') //Checa se tem parede
                g.pacman.dir = left; //Altera a direcao do pacman

        if(g.pacman.dir == left)//Mover o X e Y do pacman
        {
            if(g.lab[g.pacman.pos.y][g.pacman.pos.x - 1] != '#')
            {
                px = -1; // Altera as coordenadas x momentaneas do pacman
                py = 0; //Altera as coordenadas y momentaneas do pacman
            }
            else
            {
                px = 0;
                py = 0;
            }
            if(g.pacman.pos.x == 0 && g.pacman.pos.y == 10) //Portal esquerda-direita
            {
                g.pacman.pos.x = 19;
                g.pacman.pos.y = 10;
            }
        }

        if(g.pacman.premove == dir) //Checa se o pacman pode ir para a direita
            if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
                g.pacman.dir = right;

        if(g.pacman.dir == right)
        {
            if(g.lab[g.pacman.pos.y][g.pacman.pos.x + 1] != '#')
            {
                px = + 1;
                py = 0;
            }
            else
            {
                px = 0;
                py = 0;
            }
            if(g.pacman.pos.x == 19 && g.pacman.pos.y == 10) //Portal direita-esquerda
            {
                g.pacman.pos.x = 0;
                g.pacman.pos.y = 10;
            }
        }
        if(g.pacman.premove == bai)//Checa se o pacman pode ir para baixo
            if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
                g.pacman.dir = down;

        if(g.pacman.dir == down)
        {
            if(g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '#' && g.lab[g.pacman.pos.y + 1][g.pacman.pos.x] != '-')
            {
                px = 0;
                py = + 1;
            }
            else
            {
                px = 0;
                py = 0;
            }
        }
        if(g.pacman.premove == cima) //Checa se o pacman pode ir para cima
            if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
                g.pacman.dir = up;

        if(g.pacman.dir == up)
        {
            if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
            {
                px = 0;
                py = - 1;
            }
            else
            {
                px = 0;
                py = 0;
            }
        }



        g.pacman.pos.x += px; //Adiciona a coordenada (x) novas na posicao do pacman
        g.pacman.pos.y += py; //Adiciona a coordenada (y) novas na posicao do pacman

    }
    return g;
}

/*-----------------------------------------------------COMER------------------------------------------------------------------------------*/


t_game comer(t_game g) //Funcao para comer
{

    if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '.') //Funcao para comer as pelotas
    {
        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' '; //Remove a pelota do lugar apos o pacman comer

        g.pacman.score += 10; //Aumenta a pontuacao do pacman

        g.pacman.pelota++; //Contador da vitoria do jogo. Quantas pelotas o pacman comeu

    }

    while(g.lab[g.pacman.pos.y][g.pacman.pos.x] ==  'o') //Funcao de comer os pastilhoes
    {
        g.tempo.timeAfraid = 1; //Calcula o tempo que os fantasmas permnecem no modo afraid
        afraid_t = clock();

        g.pacman.pelota++;
        g.pacman.score += 50;

        g.lab[g.pacman.pos.y][g.pacman.pos.x] = ' ';

        for(int f = blinky; f <= clyde; f++)  //Coloca os fantasmas no modo afraid
            g.ghost[f].mode = afraid;

    }
    return g;
}

t_game cherry(t_game g) //Funcao que determina o spawn das cerejas
{
    g.tempo.timeNow = time(NULL);
    int temp;
    temp = g.tempo.timeNow - g.tempo.timeIni;

    if(temp >= 10 && temp <= 20 && g.pacman.cherry1 == 0) //Aparece cereja 1 em determinado tempo
    {
        g.lab[13][10] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (temp >= 10 && temp <= 20))
        {
            g.lab[13][10] = ' ';
            g.pacman.score += 500; //Comer a cereja da 500 pontos
            g.pacman.cherry1 += 1; //Contabiliza a cereja
        }

    }

    if(temp >= 20 && temp <= 40) //Desaparece a cereja 1
        g.lab[13][10] = ' ';

    if(temp >= 40 && temp <= 50 && g.pacman.cherry2 == 0) //Aparece cereja 2
    {
        g.lab[13][10] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (temp >= 40 && temp <= 50))
        {
            g.lab[13][10] = ' ';
            g.pacman.score += 500;
            g.pacman.cherry2 += 1;
        }
    }

    if(temp >= 50 && temp <= 70) //Desaparece cereja 2
        g.lab[13][10] = ' ';

    if(temp >= 70 && temp <= 80 && g.pacman.cherry3 == 0) //Aparece cereja 3
    {
        g.lab[13][10] = '%';

        if(g.lab[g.pacman.pos.y][g.pacman.pos.x] == '%' && (temp >= 70 && temp <= 80))
        {
            g.lab[13][10] = ' ';
            g.pacman.score += 500;
            g.pacman.cherry3 += 1;
        }
    }

    if(temp >= 80) //Desaparece cereja 3
        g.lab[13][10] = ' ';

    return g;
}

/*------------------------------------------------------TEMPO------------------------------------------------------------------------------*/

t_game mode_afraid(t_game g) //Trocar entre afraid e scatter em determinado tempo
{

    if((g.tempo.timeAfraid == 0) || (g.tempo.timeAfraid == 1 && clock() - afraid_t > 20000))
    {
        g.tempo.timeAfraid = 0;
        g.tempo.timeNow = time(NULL);
        g = timer_count(g);
    }

    return g;
}

t_game timer_count(t_game g) //Calcula o tempo pros fantasmas trocarem de modo
{

    int temp;
    temp = g.tempo.timeNow - g.tempo.timeIni; //Calcula a diferenca de tempo

    for(int i = blinky; i <= clyde; i++)
    {

        if(temp <= 7) //Depois de 7 segundos os fantasmas entram no modo scatter
            g.ghost[i].mode = scatter;

        else if(temp <= 25)
            g.ghost[i].mode = chase;

        else if(temp <= 30)
            g.ghost[i].mode = scatter;

        else if(temp <= 57)
            g.ghost[i].mode = chase;

        else if(temp <= 62)
            g.ghost[i].mode = scatter;

        else if(temp <= 82)
            g.ghost[i].mode = chase;

        else if(temp <= 87)
            g.ghost[i].mode = scatter;

        else
            g.ghost[i].mode = chase;

    }
    return g;
}

/*--------------------------------------------------------FANTASMAS------------------------------------------------------------------------*/

t_game colisao_ghosts(t_game g) // Função das colisões dos fantasmas com o pacman
{
    int a;

    for(a = blinky; a <= clyde; a++) //Testar todos os fantasmas
    {
        /* Checa TODAS as possibilidades de colisão do pacman com os fantasmas */
        if((g.pacman.pos.y == g.ghost[a].pos.y && g.pacman.pos.x == g.ghost[a].pos.x) /*Mesma posicao pacman e fantasma*/ || (g.pacman.dir == left && g.ghost[a].dir == right && g.pacman.pos.x == g.ghost[a].pos.x - 1 && g.pacman.pos.y == g.ghost[a].pos.y) /*Direcoes opostas*/ || (g.pacman.dir == up && g.ghost[a].dir == down && g.pacman.pos.x == g.ghost[a].pos.x && g.pacman.pos.y == g.ghost[a].pos.y - 1) || (g.pacman.dir == right && g.ghost[a].dir == left && g.pacman.pos.x == g.ghost[a].pos.x + 1 && g.pacman.pos.y == g.ghost[a].pos.y) || (g.pacman.dir == down && g.ghost[a].dir == up && g.pacman.pos.x == g.ghost[a].pos.x && g.pacman.pos.y == g.ghost[a].pos.y + 1) || ( g.pacman.pos.x == g.ghost[a].pos.x && g.pacman.pos.y == g.ghost[a].pos.y && g.pacman.dir == g.ghost[a].dir))
        {
            switch(a)
            {
                case blinky:

                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))

                    {
                        usleep(500000);
                        g.pacman.life--; //Reduz a vida do pacman
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17; //Pacman volta pra posição inicial
                        g.pacman.pos.x = 9;
                        g.pacman.premove = esq; //Altera o premove dos fantasmas

                        g.ghost[blinky].pos.y = 7; //Todos os fantasmas retornam pra posição inicial, se o pacman morrer
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;

                        break;

                    }
                    else
                        if(g.ghost[a].mode == afraid) //Fantasmas voltam pra posicao inicial quando morrem
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 7;
                            g.ghost[a].pos.x = 9;
                            g.ghost[a].mode = scatter;
                            break;
                        }
                        else
                            continue;

                case pinky:

                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.premove = esq;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }

                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 9;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }

                        else
                            continue;

                case inky:

                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.premove = esq;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }

                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 10;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }

                        else
                            continue;

                case clyde:

                    if((g.ghost[a].mode == scatter) || (g.ghost[a].mode == chase))
                    {
                        usleep(500000);
                        g.pacman.life--;
                        g.lab[17][9] = ' ';
                        g.pacman.pos.y = 17;
                        g.pacman.pos.x = 9;
                        g.pacman.premove = esq;
                        g.ghost[blinky].pos.y = 7;
                        g.ghost[blinky].pos.x = 9;
                        g.ghost[pinky].pos.y = 9;
                        g.ghost[pinky].pos.x = 10;
                        g.ghost[inky].pos.y = 10;
                        g.ghost[inky].pos.x = 10;
                        g.ghost[clyde].pos.y = 11;
                        g.ghost[clyde].pos.x = 10;
                        break;
                    }

                    else
                        if(g.ghost[a].mode == afraid)
                        {
                            g.pacman.score += 750;
                            g.ghost[a].pos.y = 11;
                            g.ghost[a].pos.x = 10;
                            g.ghost[a].mode = scatter;
                            break;
                        }

                        else
                            continue;
            }
        }
    }
    return g;
}

t_game ghost_mode(t_game g) // Os 4 modos que os fantasmas podem ficar
{
    int i;
    float dx, dy;


    for(i = blinky; i <= clyde; i++)
    {

        switch(i)
        {
            case(blinky):
            {
                if(g.ghost[i].mode == chase)
                {
                    g.ghost[i].starget.y = g.pacman.pos.y;
                    g.ghost[i].starget.x = g.pacman.pos.x;
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 19;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }


            case(pinky):
            {
                //sair da casa dos fantasmas
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10 && (g.tempo.timeNow - g.tempo.timeIni >= 4 || g.pacman.pelota == 7)) //Faz os fantasmas rodarem dentro da casinha, ate atingir a condicao de saida
                {
                    g.ghost[i].pos.y--;
                    continue;
                }

                if(g.ghost[i].pos.y == 7 && g.ghost[i].pos.x == 10 && g.ghost[i].pos.x <= 12 && (g.tempo.timeNow - g.tempo.timeIni >= 4 || g.pacman.pelota == 7)) //Faz os fantasmas rodarem dentro da casinha, ate atingir a condicao de saida
                {
                    g.ghost[i].pos.x++;
                    continue;
                }


                if(g.ghost[i].mode == scatter) //Define o alvo do fantasma na casinha
                {
                    g.ghost[i].starget.y = 0;
                    g.ghost[i].starget.x = 0;
                }

                if(g.ghost[i].mode == chase) //Define o alvo do fantasma no pacman
                {
                    if(g.pacman.dir == up)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + 4;

                        if(g.ghost[i].starget.y > 22)
                            g.ghost[i].starget.y = 22;

                        else if(g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                    if(g.pacman.dir == down)
                    {
                        g.ghost[i].starget.y = g.pacman.pos.y + 4;

                        if(g.ghost[i].starget.y > 22)
                            g.ghost[i].starget.y = 22;

                        else if(g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                    if(g.pacman.dir == left)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x + 4;

                        if(g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if(g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;
                    }
                    if(g.pacman.dir == right)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x + 4;

                        if(g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if(g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;
                    }
                }
                if(g.ghost[i].mode == dead) //Retorna o fantasma para a posicao inicial apos morrer
                {
                    g.ghost[i].pos.y = 9;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == afraid) //Define a movimentacao dos fantasmas para aleatorio
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }
            case(clyde):
            {
                /* Sair da casa dos fantasmas */
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10 && (g.tempo.timeNow - g.tempo.timeIni >= 12 || g.pacman.pelota == 32)) //Faz os fantasmas rodarem dentro da casinha, ate atingir a condicao de saida
                {
                    g.ghost[i].pos.y--;
                    continue;
                }


                if(g.ghost[i].mode == chase)
                {
                    dy = g.pacman.pos.y - g.ghost[i].pos.y;
                    dx = g.pacman.pos.x - g.ghost[i].pos.x;

                    if((dy + dx) >= 8)
                    {
                        g.ghost[i].starget.x = g.pacman.pos.x;
                        g.ghost[i].starget.y = g.pacman.pos.y;
                    }

                    else
                    {
                        g.ghost[i].starget.y = 22;
                        g.ghost[i].starget.x = 0;
                    }
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 0;
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 11;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }

                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 20;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }



            case(inky):
            {
                //sair da casa dos fantasmas
                if(g.ghost[i].pos.y > 7 && g.ghost[i].pos.y <= 11 && g.ghost[i].pos.x == 10 && (g.tempo.timeNow - g.tempo.timeIni >= 8 || g.pacman.pelota == 7)) //Faz os fantasmas rodarem dentro da casinha, ate atingir a condicao de saida
                {
                    g.ghost[i].pos.y--;
                    continue;
                }
                if(g.ghost[i].pos.y == 7 && g.ghost[i].pos.x == 10 && g.ghost[i].pos.x <= 13 && (g.tempo.timeNow - g.tempo.timeIni >= 8 || g.pacman.pelota == 7))
                {
                    g.ghost[i].pos.x++;
                    continue;
                }
                if(g.ghost[i].mode == scatter)
                {
                    g.ghost[i].starget.y = 22;
                    g.ghost[i].starget.x = 19;
                }
                if(g.ghost[i].mode == chase)
                {
                    if (g.pacman.dir == right) //Muda o alvo de acordo com a posicao do pacman e do blinky e do pacman
                    {
                        g.ghost[i].starget.x = ((g.pacman.pos.x + 2) - g.ghost[blinky].pos.x) * 2;
                        g.ghost[i].starget.y = ((g.pacman.pos.y + 2) - g.ghost[blinky].pos.y) * 2;

                        if (g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if (g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;

                        if (g.ghost[i].starget.y > 22)
                            g.ghost[i].starget.y = 22;

                        else if (g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                    else if (g.pacman.dir == left)
                    {
                        g.ghost[i].starget.x = ((g.pacman.pos.x - 2) - g.ghost[blinky].pos.x) * 2;
                        g.ghost[i].starget.y = (g.pacman.pos.y - g.ghost[blinky].pos.y) * 2;

                        if (g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if (g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;

                        if (g.ghost[i].starget.y > 22)
                            g.ghost[i].starget.y = 22;

                        else if (g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                    else if (g.pacman.dir == up)
                    {
                        g.ghost[i].starget.x = (g.pacman.pos.x - g.ghost[blinky].pos.x) * 2;
                        g.ghost[i].starget.y = ((g.pacman.pos.y - 2) - g.ghost[blinky].pos.y) * 2;

                        if (g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if (g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;

                        if (g.ghost[i].starget.y > 22)
                            g.ghost[i].starget.y = 22;

                        else if (g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                    else if (g.pacman.dir == down)
                    {
                        g.ghost[i].starget.x = (g.pacman.pos.x - g.ghost[blinky].pos.x) * 2;
                        g.ghost[i].starget.y = ((g.pacman.pos.y + 2) - g.ghost[blinky].pos.y) * 2;

                        if (g.ghost[i].starget.x > 19)
                            g.ghost[i].starget.x = 19;

                        else if (g.ghost[i].starget.x < 0)
                            g.ghost[i].starget.x = 0;

                        if (g.ghost[i].starget.y > 22)
                            g.ghost[inky].starget.y = 22;

                        else if (g.ghost[i].starget.y < 0)
                            g.ghost[i].starget.y = 0;
                    }
                }
                if(g.ghost[i].mode == dead)
                {
                    g.ghost[i].pos.y = 10;
                    g.ghost[i].pos.x = 10;
                    g.ghost[i].mode = chase;
                    continue;
                }
                if(g.ghost[i].mode == afraid)
                {
                    g.ghost[i].starget.y = rand() % 22;
                    g.ghost[i].starget.x = rand() % 20;
                }
                break;
            }
        }

        //Portal de teleporte dos fantasmas
        if(g.ghost[i].pos.x == 0 && g.ghost[i].pos.y == 10) //Esquerda-direita
            g.ghost[i].pos.x = 18, g.ghost[i].pos.y = 10;
        if(g.ghost[i].pos.x == 19 && g.ghost[i].pos.y == 10) //Direita-esquerda
            g.ghost[i].pos.x = 1, g.ghost[i].pos.y = 10;

        g = ghostsIA(g, i); //Funcao que chama a analise do mapa pelos fantasmas
    }
    return g;
}

t_game blinky_move(t_game g) //FUNCAO DE MOVIMENTACAO DO BLINKY
{
    int px = 0, py = 0;

    if (g.ghost[blinky].mode == scatter || g.ghost[blinky].mode == chase || g.ghost[blinky].mode == afraid)
    {
        if(g.ghost[blinky].dir == right)
        {
            if (g.ghost[blinky].pos.x > g.ghost[blinky].starget.x) //Caso o blinky esteja mais a direita do alvo, ja que ele nao pode dar meia volta, faz o retorno
            {
                if (g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
                {
                    g.ghost[blinky].dir = up;
                    py -= 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
                {
                    g.ghost[blinky].dir = down;
                    py += 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
                    px += 1;
            }
            else if(g.ghost[blinky].pos.x < g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
            {
                px += 1;
            }
            else if (g.ghost[blinky].pos.y > g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
            {
                g.ghost[blinky].dir = up;
                py -= 1;
            }
            else if (g.ghost[blinky].pos.y < g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
            {
                g.ghost[blinky].dir = down;
                py += 1;
            }
        }
        else if(g.ghost[blinky].dir == left)
        {
            if (g.ghost[blinky].pos.x < g.ghost[blinky].starget.x) //Caso o blinky esteja mais a direita do alvo, ja que ele nao pode dar meia volta, faz o retorno
            {
                if (g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
                {
                    g.ghost[blinky].dir = up;
                    py -= 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
                {
                    g.ghost[blinky].dir = down;
                    py += 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
                    px -= 1;
            }
            else if(g.ghost[blinky].pos.x > g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
            {
                px -= 1;
            }
            else if (g.ghost[blinky].pos.y > g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
            {
                g.ghost[blinky].dir = up;
                py -= 1;
            }
            else if(g.ghost[blinky].pos.y < g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
            {
                g.ghost[blinky].dir = down;
                py += 1;
            }
        }
        else if(g.ghost[blinky].dir == down)
        {
            if (g.ghost[blinky].pos.y > g.ghost[blinky].starget.y) //Se o blinky estiver mais a baixo do alvo, ja que ele n pode dar meia volta, ele faz o retorno
            {
                if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
                {
                    g.ghost[blinky].dir = left;
                    px -= 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
                {
                    g.ghost[blinky].dir = right;
                    px += 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
                    py += 1;
            }
            else if(g.ghost[blinky].pos.y < g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '#' && g.lab[g.ghost[blinky].pos.y + 1][g.ghost[blinky].pos.x] != '-')
            {
                py += 1;
            }
            else if (g.ghost[blinky].pos.x < g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
            {
                g.ghost[blinky].dir = right;
                px += 1;
            }
            else if (g.ghost[blinky].pos.x > g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
            {
                g.ghost[blinky].dir = left;
                px -= 1;
            }
        }

        else if(g.ghost[blinky].dir == up)
        {
            if (g.ghost[blinky].pos.y < g.ghost[blinky].starget.y) //Se o blinky estiver mais a baixo do alvo, ja que ele n pode dar meia volta, ele faz o retorno
            {
                if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
                {
                    g.ghost[blinky].dir = left;
                    px -= 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
                {
                    g.ghost[blinky].dir = right;
                    px += 1;
                }
                else if (g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
                    py -= 1;
            }
            if (g.ghost[blinky].pos.y > g.ghost[blinky].starget.y && g.lab[g.ghost[blinky].pos.y - 1][g.ghost[blinky].pos.x] != '#')
            {
                py -= 1;
            }
            else if (g.ghost[blinky].pos.x < g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x + 1] != '#')
            {
                g.ghost[blinky].dir = right;
                px += 1;
            }
            else if (g.ghost[blinky].pos.x > g.ghost[blinky].starget.x && g.lab[g.ghost[blinky].pos.y][g.ghost[blinky].pos.x - 1] != '#')
            {
                g.ghost[blinky].dir = left;
                px -= 1;
            }
        }
    }
    // Aplica a nova posicao no blinky
    g.ghost[blinky].pos.x += px;
    g.ghost[blinky].pos.y += py;

    return g;
}

t_game pinky_move(t_game g) //FUNCAO DE MOVIMENTACAO DO PINKY
{
    int temp = g.tempo.timeNow - g.tempo.timeIni; //Declara a variavel tempo

    if (temp > 4) //Pinky so sai da casa se tiver nessas condicoes
    {
        if (g.ghost[pinky].mode == scatter || g.ghost[pinky].mode == chase || g.ghost[pinky].mode == afraid) //Caso o inky esteja no modo scatter
        {
            if (g.ghost[pinky].dir == right) //Caso o inky esteja de virado para a direita
            {
                if (g.ghost[pinky].pos.x > g.ghost[pinky].starget.x) //Caso o inky esteja mais a direita do alvo, ja que ele nao pode dar meia volta, faz o retorno
                {
                    if (g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#')
                    {
                        g.ghost[pinky].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-')
                    {
                        g.ghost[pinky].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#')
                        px += 1;
                }
                else if (g.ghost[pinky].pos.x < g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda do alvo, ele segue reto
                    px += 1;

                else if (g.ghost[pinky].pos.y > g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#') //Se o inky estiver mais a baixo do alvo, ele sobe
                {
                    g.ghost[pinky].dir = up;
                    py -= 1;
                }
                else if (g.ghost[pinky].pos.y < g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-') //Se o inky estiver mais a cima do alvo, ele desce
                {
                    g.ghost[pinky].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[pinky].dir == left) //Caso o inky esteja olhando para a esquerda
            {
                if (g.ghost[pinky].pos.x < g.ghost[pinky].starget.x) //Se o inky estiver mais a esquerda do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#')
                    {
                        g.ghost[pinky].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-')
                    {
                        g.ghost[pinky].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#')
                        px -= 1;
                }
                else if (g.ghost[pinky].pos.x > g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#') //Se o inky estiver mais a direita do alvo, ele segue reto
                    px -= 1;

                else if (g.ghost[pinky].pos.y > g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#') //Se o inky estiver mais a baixo do alvo, ele sobe
                {
                    g.ghost[pinky].dir = up;
                    py -= 1;
                }
                else if (g.ghost[pinky].pos.y < g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-') //Se o inky estiver mais a cima do alvo, ele desce
                {
                    g.ghost[pinky].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[pinky].dir == down) //Caso o inky esteja olhando para baixo
            {
                if (g.ghost[pinky].pos.y > g.ghost[pinky].starget.y) //Se o inky estiver mais a baixo do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#')
                    {
                        g.ghost[pinky].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#')
                    {
                        g.ghost[pinky].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-')
                        py += 1;
                }
                else if (g.ghost[pinky].pos.y < g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '#' && g.lab[g.ghost[pinky].pos.y + 1][g.ghost[pinky].pos.x] != '-') //Se o inke estiver mais a cima do alvo, ele segue reto
                    py += 1;

                else if (g.ghost[pinky].pos.x < g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda do alvo, ele vai para direira
                {
                    g.ghost[pinky].dir = right;
                    px += 1;
                }
                else if (g.ghost[pinky].pos.x > g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#') //Se o inky estiver mais a direita do alvo, ele vaipara a esquerda
                {
                    g.ghost[pinky].dir = left;
                    px -= 1;
                }
            }
            else if (g.ghost[pinky].dir == up) //Caso o inky esteja olhando para cima
            {
                if (g.ghost[pinky].pos.y < g.ghost[pinky].starget.y) //Se ele estiver mais a cima do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#')
                    {
                        g.ghost[pinky].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#')
                    {
                        g.ghost[pinky].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#')
                        py -= 1;
                }
                else if (g.ghost[pinky].pos.y > g.ghost[pinky].starget.y && g.lab[g.ghost[pinky].pos.y - 1][g.ghost[pinky].pos.x] != '#') //Se o inky estiver mais a baixo, ele segue reto
                    py -= 1;

                else if (g.ghost[pinky].pos.x < g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda, ele vai para direita
                {
                    g.ghost[pinky].dir = right;
                    px += 1;
                }
                else if (g.ghost[pinky].pos.x > g.ghost[pinky].starget.x && g.lab[g.ghost[pinky].pos.y][g.ghost[pinky].pos.x - 1] != '#') //Se o inky estiver mais a direita, ele vai para a esquerda
                {
                    g.ghost[pinky].dir = left;
                    px -= 1;
                }
            }
        }
        g.ghost[pinky].pos.x += px;
        g.ghost[pinky].pos.y += py;
    }
    return g;
}
t_game inky_move(t_game g) //FUNCAO DE MOVIMENTACAO DO INKY
{
    int temp = g.tempo.timeNow - g.tempo.timeIni; //Varavel temp recebe a valor do tempo, padronizado em todo o codigo
    int px = 0, py = 0; //Foi criada dias variaveis, para simplificar o codigo. Elas serao atribuidas a posicao do inky no final da funcao

    /* if (g.pacman.pelota == 17 || temp == 8) //Quando o pacman comer 17 pelotas ou o tempo chegar em 8s o inky sair da casinha */
    /* { */
        /* g.ghost[inky].pos.x = 10; */
        /* g.ghost[inky].pos.y = 7; */
    /* } */
    if (temp > 7)
    {
        if (g.ghost[inky].mode == scatter || g.ghost[inky].mode == chase || g.ghost[inky].mode == afraid) //Caso o inky esteja no modo scatter
        {
            if (g.ghost[inky].dir == right) //Caso o inky esteja de virado para a direita
            {
                if (g.ghost[inky].pos.x > g.ghost[inky].starget.x) //Caso o inky esteja mais a direita do alvo, ja que ele nao pode dar meia volta, faz o retorno
                {
                    if (g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#')
                    {
                        g.ghost[inky].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-')
                    {
                        g.ghost[inky].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#')
                        px += 1;
                }
                else if (g.ghost[inky].pos.x < g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda do alvo, ele segue reto
                    px += 1;

                else if (g.ghost[inky].pos.y > g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#') //Se o inky estiver mais a baixo do alvo, ele sobe
                {
                    g.ghost[inky].dir = up;
                    py -= 1;
                }
                else if (g.ghost[inky].pos.y < g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-') //Se o inky estiver mais a cima do alvo, ele desce
                {
                    g.ghost[inky].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[inky].dir == left) //Caso o inky esteja olhando para a esquerda
            {
                if (g.ghost[inky].pos.x < g.ghost[inky].starget.x) //Se o inky estiver mais a esquerda do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#')
                    {
                        g.ghost[inky].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-')
                    {
                        g.ghost[inky].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#')
                        px -= 1;
                }
                else if (g.ghost[inky].pos.x > g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#') //Se o inky estiver mais a direita do alvo, ele segue reto
                    px -= 1;

                else if (g.ghost[inky].pos.y > g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#') //Se o inky estiver mais a baixo do alvo, ele sobe
                {
                    g.ghost[inky].dir = up;
                    py -= 1;
                }
                else if (g.ghost[inky].pos.y < g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-') //Se o inky estiver mais a cima do alvo, ele desce
                {
                    g.ghost[inky].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[inky].dir == down) //Caso o inky esteja olhando para baixo
            {
                if (g.ghost[inky].pos.y > g.ghost[inky].starget.y) //Se o inky estiver mais a baixo do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#')
                    {
                        g.ghost[inky].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#')
                    {
                        g.ghost[inky].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-')
                        py += 1;
                }
                else if (g.ghost[inky].pos.y < g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '#' && g.lab[g.ghost[inky].pos.y + 1][g.ghost[inky].pos.x] != '-') //Se o inke estiver mais a cima do alvo, ele segue reto
                    py += 1;

                else if (g.ghost[inky].pos.x < g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda do alvo, ele vai para direira
                {
                    g.ghost[inky].dir = right;
                    px += 1;
                }
                else if (g.ghost[inky].pos.x > g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#') //Se o inky estiver mais a direita do alvo, ele vaipara a esquerda
                {
                    g.ghost[inky].dir = left;
                    px -= 1;
                }
            }
            else if (g.ghost[inky].dir == up) //Caso o inky esteja olhando para cima
            {
                if (g.ghost[inky].pos.y < g.ghost[inky].starget.y) //Se ele estiver mais a cima do alvo, ja que ele n pode dar meia volta, ele faz o retorno
                {
                    if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#')
                    {
                        g.ghost[inky].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#')
                    {
                        g.ghost[inky].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#')
                        py -= 1;
                }
                else if (g.ghost[inky].pos.y > g.ghost[inky].starget.y && g.lab[g.ghost[inky].pos.y - 1][g.ghost[inky].pos.x] != '#') //Se o inky estiver mais a baixo, ele segue reto
                    py -= 1;

                else if (g.ghost[inky].pos.x < g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x + 1] != '#') //Se o inky estiver mais a esquerda, ele vai para direita
                {
                    g.ghost[inky].dir = right;
                    px += 1;
                }
                else if (g.ghost[inky].pos.x > g.ghost[inky].starget.x && g.lab[g.ghost[inky].pos.y][g.ghost[inky].pos.x - 1] != '#') //Se o inky estiver mais a direita, ele vai para a esquerda
                {
                    g.ghost[inky].dir = left;
                    px -= 1;
                }
            }
        }
        g.ghost[inky].pos.x += px;
        g.ghost[inky].pos.y += py;
    }
    return g;
}


t_game clyde_move(t_game g) //FUNCAO DE MOVIMENTACAO DO CLYDE
{
    int temp = g.tempo.timeNow - g.tempo.timeIni;//função para o tempo ser calculado nos fantasmas
    int px = 0, py = 0;//
    if(temp > 12)//parametro para o clyde sair da casinha
    {
        if (g.ghost[clyde].mode == chase || g.ghost[clyde].mode == scatter || g.ghost[clyde].mode == afraid)
        {
            if (g.ghost[clyde].dir == right)
            {
                if (g.ghost[clyde].pos.x > g.ghost[clyde].starget.x)
                {
                    if (g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                    {
                        g.ghost[clyde].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                    {
                        g.ghost[clyde].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                        px += 1;
                }
                else if (g.ghost[clyde].pos.x < g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                    px += 1;

                else if (g.ghost[clyde].pos.y > g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                {
                    g.ghost[clyde].dir = up;
                    py -= 1;
                }
                else if (g.ghost[clyde].pos.y < g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                {
                    g.ghost[clyde].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[clyde].dir == left)
            {
                if (g.ghost[clyde].pos.x < g.ghost[clyde].starget.x)
                {
                    if (g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                    {
                        g.ghost[clyde].dir = up;
                        py -= 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                    {
                        g.ghost[clyde].dir = down;
                        py += 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                        px -= 1;
                }
                else if (g.ghost[clyde].pos.x > g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                    px -= 1;

                else if (g.ghost[clyde].pos.y > g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                {
                    g.ghost[clyde].dir = up;
                    py -= 1;
                }
                else if (g.ghost[clyde].pos.y < g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                {
                    g.ghost[clyde].dir = down;
                    py += 1;
                }
            }
            else if (g.ghost[clyde].dir == down)
            {
                if (g.ghost[clyde].pos.y > g.ghost[clyde].starget.y)
                {
                    if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                    {
                        g.ghost[clyde].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                    {
                        g.ghost[clyde].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                        py += 1;
                }
                else if (g.ghost[clyde].pos.y < g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '#' && g.lab[g.ghost[clyde].pos.y + 1][g.ghost[clyde].pos.x] != '-')
                    py += 1;

                else if (g.ghost[clyde].pos.x < g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                {
                    g.ghost[clyde].dir = right;
                    px += 1;
                }
                else if (g.ghost[clyde].pos.x > g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                {
                    g.ghost[clyde].dir = left;
                    px -= 1;
                }
            }
            else if (g.ghost[clyde].dir == up)
            {
                if (g.ghost[clyde].pos.y < g.ghost[clyde].starget.y)
                {
                    if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                    {
                        g.ghost[clyde].dir = left;
                        px -= 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                    {
                        g.ghost[clyde].dir = right;
                        px += 1;
                    }
                    else if (g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                        py -= 1;
                }
                else if (g.ghost[clyde].pos.y > g.ghost[clyde].starget.y && g.lab[g.ghost[clyde].pos.y - 1][g.ghost[clyde].pos.x] != '#')
                    py -= 1;

                else if (g.ghost[clyde].pos.x < g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x + 1] != '#')
                {
                    g.ghost[clyde].dir = right;
                    px += 1;
                }
                else if (g.ghost[clyde].pos.x > g.ghost[clyde].starget.x && g.lab[g.ghost[clyde].pos.y][g.ghost[clyde].pos.x - 1] != '#')
                {
                    g.ghost[clyde].dir = left;
                    px -= 1;
                }

                if((g.ghost[clyde].pos.x - g.pacman.pos.x > 8) || (g.ghost[clyde].pos.y - g.pacman.pos.y > 8))
                {
                    g.ghost[clyde].starget.x = g.pacman.pos.x;
                    g.ghost[clyde].starget.y = g.pacman.pos.y;
                }
            }
        }
    }
    g.ghost[clyde].pos.x += px;
    g.ghost[clyde].pos.y += py;

    return g;
}



/* --------------------------------------------------------------------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */

/*-------------------------------------------------------------DESIGN----------------------------------------------------------------------*/

void printlab(t_game g)
{
    IFDEBUG("printlab()");

    int y, f;

    clear(); // * clear the screen *

    for(y = 0; y < LABL; y++)
        printw("%s\n", g.lab[y]);

    color_map(g);
    attron(COLOR_PAIR(6));
    mvprintw(1, 22, " |------PLACAR------| ");
    mvprintw(2, 22, "  Vidas:   %d         ", g.pacman.life); //Mostra quantas vidas o pacman tem
    mvprintw(3, 22, "  Pontuacao: %d       ", g.pacman.score); //Mostra a pontuacao em tempo real
    mvprintw(4, 22, " |------------------| ");

    /*mvprintw(9, 22, "  TimeAfraid : %d       ", g.tempo.timeAfraid); //DEBUG DO TEMPO NO MODO AFRAID
    mvprintw(10, 22, "  TimeNow : %d       ", g.tempo.timeNow); //DEBUG DO TEMPO ATUAL
    mvprintw(11, 22, "  TimePlayed : %d       ", g.tempo.timeIni); //DEBUG DO TEMPO AFRAID

    if (g.ghost[inky].mode == chase) //DEBUG QUE TESTA O MODO DOS FANTASMAS
        mvprintw(14, 22, "  Ghost_Chase");
    else if(g.ghost[inky].mode == scatter)
        mvprintw(15, 22, " Ghost_Scatter ");
    else
        mvprintw(16, 22, " Ghost_Afraid "); */


    curs_set(FALSE);
    for(f = blinky; f <= clyde; f++) /* blinky, pinky, inky and clyde */
        mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f, NULL);

    mvprintw(g.pacman.pos.y, g.pacman.pos.x, "@");

    /* ------------------------------------------------------------------------------------------------------------------------*/
    for(int f = blinky; f <= clyde; f++) //Determina as CORES dos fantasmas
    {

        if(f == blinky) //Blinky -- Vermelho
        {
            if(g.ghost[f].mode != afraid)
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "B");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 1, NULL);
            }

            else //Modo afraid -- Azul
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "B");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
            }
        }

        if(f == pinky) //Pinky -- Rosa
        {
            if(g.ghost[f].mode != afraid)
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "P");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 2, NULL);
            }

            else //Modo afraid -- Azul
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "P");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
            }
        }
        if(f == inky) //Inky -- Azul
        {
            if(g.ghost[f].mode != afraid)
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "I");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 3, NULL);
            }

            else //Modo afraid -- Azul
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "I");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
            }
        }
        if(f == clyde) //Verde
        {
            if(g.ghost[f].mode != afraid)
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "C");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 4, NULL);
            }

            else //Modo afraid -- Azul
            {
                mvprintw(g.ghost[f].pos.y, g.ghost[f].pos.x, "C");
                mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, 5, NULL);
            }

        }
    }
    mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);
    refresh();
}

void menu() //Menu da tela inicial
{
    initscr();
    clear();
    noecho();
    curs_set(FALSE);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    attron(COLOR_PAIR(3));
    mvprintw(rows / 2 - 1, (cols - 13) / 2, "1. Iniciar Jogo");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(2));
    mvprintw(rows / 2 + 0, (cols - 13) / 2, "2. Tutorial");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    mvprintw(rows / 2 + 1, (cols - 13) / 2, "3. Sobre");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(5));
    mvprintw(rows / 2 + 2, (cols - 13) / 2, "4. Sair");
    attroff(COLOR_PAIR(5));

    mvhline(0, 0, '-', cols);
    mvhline(rows - 1, 0, '-', cols);
    mvvline(0, 0, '|', rows);
    mvvline(0, cols - 1, '|', rows);

    mvprintw(0, (cols - 15) / 2, "Version 1.0");

    mvprintw(rows / 2 - 9, (cols - 40) / 2, " _____ _____ _____ _____ _____ _____ _____");
    mvprintw(rows / 2 - 8, (cols - 40) / 2, "|  |  |  _  |   __|     |     |  _  |   | |");
    mvprintw(rows / 2 - 7, (cols - 40) / 2, "|  |  |   __|   __|   --| | | |     | | | |");
    mvprintw(rows / 2 - 6, (cols - 40) / 2, "|_____|__|  |_____|_____|_|_|_|__|__|_|___|");

    attron(COLOR_PAIR(1));
    mvprintw(rows / 2 - 11, (cols + 70) / 2, "         .........");
    mvprintw(rows / 2 - 10, (cols + 70) / 2, "      ................");
    mvprintw(rows / 2 - 9, (cols + 70) / 2,  "   .....................");
    mvprintw(rows / 2 - 8, (cols + 70) / 2,  "  ........................");
    mvprintw(rows / 2 - 7, (cols + 70) / 2,  " .......................");
    mvprintw(rows / 2 - 6, (cols + 70) / 2,  " ....................");
    mvprintw(rows / 2 - 5, (cols + 70) / 2,  " ................");
    mvprintw(rows / 2 - 4, (cols + 70) / 2,  " ...............");
    mvprintw(rows / 2 - 3, (cols + 70) / 2,  " ................");
    mvprintw(rows / 2 - 2, (cols + 70) / 2,  " ....................");
    mvprintw(rows / 2 - 1, (cols + 70) / 2,  "  ......................");
    mvprintw(rows / 2 + 0, (cols + 70) / 2,  "   .......................");
    mvprintw(rows / 2 + 1, (cols + 70) / 2,  "     .....................");
    mvprintw(rows / 2 + 2, (cols + 70) / 2,  "      .................");
    mvprintw(rows / 2 + 3, (cols + 70) / 2,  "        ...........");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(rows / 2 - 11, (cols - 135) / 2, "           ++++++++++++++++");
    mvprintw(rows / 2 - 10, (cols - 135) / 2, "        ++++++++++++++++++++");
    mvprintw(rows / 2 - 9, (cols - 135) / 2,  "      ++++++++++++++++++++++++");
    mvprintw(rows / 2 - 8, (cols - 135) / 2,  "     ++++++++++++++++++++++++++");
    mvprintw(rows / 2 - 7, (cols - 135) / 2,  "    ++++++++++++++++++++++++++++");
    mvprintw(rows / 2 - 6, (cols - 135) / 2,  "   ++++++++       ++++++      +++");
    mvprintw(rows / 2 - 5, (cols - 135) / 2,  "   +++++++     +++ ++++    +++ ++");
    mvprintw(rows / 2 - 4, (cols - 135) / 2,  "   +++++++     +++ ++++    +++ ++");
    mvprintw(rows / 2 - 3, (cols - 135) / 2,  "   +++++++        ++++++      +++");
    mvprintw(rows / 2 - 2, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 - 1, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 0, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 1, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 2, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 3, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 4, (cols - 135) / 2,  "   ++++++++++++++++++++++++++++++");
    mvprintw(rows / 2 + 5, (cols - 135) / 2,  "   ++++    +++++    ++++++   ++++");
    attroff(COLOR_PAIR(2));

    int escolha = getch();

    if (escolha == '1')
    {
        clear();
        upecman_init();
    }
    else if (escolha == '2')
    {
        clear();

        mvhline(0, 0, '-', cols);
        mvhline(rows - 1, 0, '-', cols);
        mvvline(0, 0, '|', rows);
        mvvline(0, cols - 1, '|', rows);

        mvprintw(7, 50,  "|------------------------------------TUTORIAL-------------------------------------|");
        mvprintw(8, 50,   "                                              ");
        mvprintw(9, 50,   "VIDAS:                                        ");
        mvprintw(10, 50,  "O PACMAN (@) TEM APENAS 3 VIDAS.              ");
        mvprintw(11, 50,  "AS VIDAS REDUZEM, CASO O PACMAN ENTRE EM CONTATO COM OS FANTASMAS, PERDE UMA VIDA");
        mvprintw(12, 50,  "SE AS VIDAS CHEGAREM A 0, O JOGO ACABA        ");
        mvprintw(14, 50,  "PONTUACAO:                                    ");
        mvprintw(15, 50,  "PELOTA '.' = 10 PONTOS                        ");
        mvprintw(16, 50,  "PASTILHAO 'o' = 50 PONTOS                     ");
        mvprintw(17, 50,  "CEREJA 500 PONTOS                             ");
        mvprintw(18, 50,  "FANTASMAS 'C, I, B, P' = 750 PONTOS           ");
        mvprintw(20, 50,  "OBJETIVO:                                     ");
        mvprintw(21, 50,  "COMER TODAS AS PELOTAS SEM SER PEGO PELOS FANTASMAS");
        mvprintw(23, 50,  "CONTROLES:                                    ");
        mvprintw(24, 50,  "SETAS PARA MOVIMENTO (KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT");
        mvprintw(25, 50,  "PARA SAIR DO JOGO, PRESSIONE 'Q'              ");
        mvprintw(26, 50, "|---------------------------------------------------------------------------------|");

        attron(COLOR_PAIR(2));
        mvprintw(28, 50, "PRESSIONE QUALQUER TECLA PARA VOLTAR");
        attroff(COLOR_PAIR(2));

        refresh();
        getch();
        menu();
    }
    else if (escolha == '3')
    {
        clear();

        mvhline(0, 0, '-', cols);
        mvhline(rows - 1, 0, '-', cols);
        mvvline(0, 0, '|', rows);
        mvvline(0, cols - 1, '|', rows);

        /*Creditos dos participantes*/
        mvprintw(7, 30,  "|----------------- PARTICIPANTES -------------------|");
        mvprintw(8, 30,   " -GABRIEL NOBREGA TOSCANO.");
        mvprintw(9, 30,   " -BRUNO SILVEIRA DE MELO.");
        mvprintw(10, 30,  " -ISABELA CAXIAS SEABRA DE ALBUQUERQUE.");
        mvprintw(11, 30,  " -JOSE LEANDRO MORAIS ALVES LUZ.");
        mvprintw(12, 30,  " -LETICIA MIRELLA LEMOS RAPOSO.");
        mvprintw(13, 30,  " -PEDRO DE OLIVEIRA NUNES DO REGO.");
        mvprintw(14, 30,  " -RICARDO TIMOTEO WANDERLEY.");
        mvprintw(15, 30,  " -SAVIO GIOVANI LINS DA SILVA.");
        mvprintw(16, 30, "|-------------------------------------------------|");
        mvprintw(18, 30, "|----------------- COORDENADOR -------------------|");
        mvprintw(19, 30, "  -PROF. DR. RUBEN CARLO BENANTE.");
        mvprintw(20, 30, "|-------------------------------------------------|");

        attron(COLOR_PAIR(2));
        mvprintw(22, 30, "PRESSIONE QUALQUER TECLA PARA VOLTAR");
        attroff(COLOR_PAIR(2));

        refresh();
        getch();
        menu();
    }
    else if (escolha == '4')
    {
        endwin();
        exit(EXIT_SUCCESS);
    }
    else
    {
        mvprintw(rows / 2 + 4, (cols - 23) / 2, "Opcao invalida. Tente novamente.");

        refresh();
        getch();
        menu();
    }
}

t_game derrota(t_game g)//Tela de derrota caso pacman morra
{
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));

        mvprintw(11, 30, " -----   -----  -----  -----   ---   -----   -----   |");
        mvprintw(12, 30, " |    .  |      |   |  |   |  |   |    |    |     |  |");
        mvprintw(13, 30, " |    .  |---   |---   |---   |   |    |    |     |  |");
        mvprintw(14, 30, " |   .   |      |   |  |   |  |   |    |    |-----|  |");
        mvprintw(15, 30, " ----    -----  |   |  |   |   ---     |    |     |  O");
        attroff(COLOR_PAIR(1));

        mvprintw(17,30, " PONTUACAO: %d     ", g.pacman.score); //Mostra a pontuacao final
        attron(COLOR_PAIR(1));
        mvprintw(18, 30, " ______________________________");
        mvprintw(19, 30, "|         GAMER OVER!!!        |");
        mvprintw(20, 30, "|------------------------------|");
        mvprintw(21, 30, "| Pressione 'y' para Reiniciar |");
        mvprintw(22, 30, "| Pressione 'n' para Sair.     |");
        mvprintw(23, 30, "|______________________________|");

        mvprintw(11, 100, "           ++++++++++++++++");
        mvprintw(12, 100, "        ++++++++++++++++++++");
        mvprintw(13, 100, "      ++++++++++++++++++++++++");
        mvprintw(14, 100, "     ++++++++++++++++++++++++++");
        mvprintw(15, 100, "    ++++++++++++++++++++++++++++");
        mvprintw(16, 100, "   ++++++++       ++++++      +++");
        mvprintw(17, 100, "   +++++++     +++ ++++    +++ ++");
        mvprintw(18, 100, "   +++++++     +++ ++++    +++ ++");
        mvprintw(19, 100, "   +++++++        ++++++      +++");
        mvprintw(20, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(21, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(22, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(23, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(24, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(25, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(26, 100, "   ++++++++++++++++++++++++++++++");
        mvprintw(27, 100, "   ++++    +++++    ++++++   ++++");
        attroff(COLOR_PAIR(1));
    return g;
}

t_game vitoria(t_game g) //Tela caso o pacman venca o jogo
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    mvprintw(11, 30, " |   |  O  -----   ---   -----   O   -----   |");
    mvprintw(12, 30, " |   |  |    |    |   |  |   |   |  |     |  |");
    mvprintw(13, 30, " |   |  |    |    |   |  |---    |  |     |  |");
    mvprintw(14, 30, " |   |  |    |    |   |  |   |   |  |-----|  |");
    mvprintw(15, 30, "  ---   |    |     ---   |   |   |  |     |  O");
    attroff(COLOR_PAIR(1));

    mvprintw(17,30, "           Pontuacao: %d     ", g.pacman.score); //Mostra a pontuacao final

    attron(COLOR_PAIR(4));
    mvprintw(18, 30, " ______________________________");
    mvprintw(19, 30, "|   PARABENS, VOCE GANHOU!!!   |");
    mvprintw(20, 30, "|------------------------------|");
    mvprintw(21, 30, "| Pressione 'y' para Reiniciar |");
    mvprintw(22, 30, "| Pressione 'n' para Sair.     |");
    mvprintw(23, 30, "|______________________________|");

    attron(COLOR_PAIR(6));
    mvprintw(11, 100, "         .........");
    mvprintw(12, 100,"      ................");
    mvprintw(13, 100, "   .....................");
    mvprintw(14, 100, "  ........................");
    mvprintw(15, 100, " .......................");
    mvprintw(16, 100, " ....................");
    mvprintw(17, 100, " ................");
    mvprintw(18, 100, " ...............");
    mvprintw(19, 100, " ................");
    mvprintw(20, 100, " ....................");
    mvprintw(21, 100, "  ......................");
    mvprintw(22, 100, "   .......................");
    mvprintw(23, 100,"    .....................");
    mvprintw(24, 100, "      .................");
    mvprintw(25, 100, "        ...........");
    attroff(COLOR_PAIR(6));
    return g;
}

void color_map(t_game g) //Pinta tudo relacionado ao mapa
{
    int i, j;

    for (i = 0; i < LABL; i++)
    {
        for(j = 0; j < LABC; j++)
        {
            if(g.lab[i][j] == '#') //Pinta as paredes do mapa
                mvchgat(i, j, 1, A_BOLD, 5, NULL);
            if(g.lab[i][j] == '%') //Pinta a cor da cereja
                mvchgat(i, j, 1, A_BOLD, 1, NULL);
            if(g.lab[i][j] == 'o') //Pinta o pastilhao
                mvchgat(i, j, 1, A_BOLD, 0, NULL);
            if(g.lab[i][j] == '.') //Pinta as pelotas
                mvchgat(i, j, 1, A_BOLD, 6, NULL);

        }
    }
}

//IGNOREM ESSE CÓDIGO!!!!!

int hipot(int py, int sty, int px, int stx) // funcao para calcular a hipotenusa quando necessaria
{
    return sqrt(pow(py - sty, 2) + pow(px - stx, 2));
}

t_game ghostsIA(t_game g, int i) // Inteligencia Artificial dos fantasmas
{

    int py, px, sty, stx; //Variaveis para facilitar a compreensao e reduzir o tamanho do codigo.
    py = g.ghost[i].pos.y;
    px = g.ghost[i].pos.x;
    sty = g.ghost[i].starget.y;
    stx = g.ghost[i].starget.x;

    float hip[4] = {0}; //Testa a hipotenusa calculada
    float c[4] = {0}; //Testa os possiveis caminhos
    int posicao;



    //armazena os dados das possiveis direcoes que o fantasma pode ir
    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != '#') && (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x + 1] != '-') && (g.ghost[i].dir != left))
    {
        c[0] = 1;
        hip[0] = hipot(py, sty, px + 1, stx);
    }


    if((g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != '#') && (g.lab[g.ghost[i].pos.y][g.ghost[i].pos.x - 1] != '-') && (g.ghost[i].dir != right))
    {
        c[1] = 1;
        hip[1] = hipot(py, sty, px - 1, stx);
    }


    if((g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '#') && (g.lab[g.ghost[i].pos.y + 1][g.ghost[i].pos.x] != '-') && (g.ghost[i].dir != up))
    {
        c[2] = 1;
        hip[2] = hipot(py + 1, sty, px, stx);
    }


    if((g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != '#') && (g.lab[g.ghost[i].pos.y - 1][g.ghost[i].pos.x] != '-') && (g.ghost[i].dir != down))
    {
        c[3] = 1;
        hip[3] = hipot(py - 1, sty, px, stx);
    }

    //calcula a melhor rota para poder andar, levando em consideracao a hipotenusa do fantasma em relacao a onde ele se encontra e seu lugar de preferencia
    if(c[0] == 1 && c[1] == 0 && c[2] == 0 && c[3] == 0)
        posicao = direita;

    if(c[0] == 0 && c[1] == 1 && c[2] == 0 && c[3] == 0)
        posicao = esquerda;

    if(c[0] == 0 && c[1] == 0 && c[2] == 1 && c[3] == 0)
        posicao = baixo;

    if(c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 1)
        posicao = cim;

    if(c[0] == 1 && c[1] == 1 && c[2] == 0 && c[3] == 0)
    {
        if(hip[0] < hip[1])
            posicao = direita;

        else
            posicao = esquerda;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 1 && c[3] == 0)
    {
        if(hip[0] < hip[2])
            posicao = direita;

        else
            posicao = baixo;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 0 && c[3] == 1)
    {
        if(hip[0] < hip[3])
            posicao = direita;

        else
            posicao = cim;
    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 1 && c[3] == 0)
    {
        if(hip[1] < hip[2])
            posicao = esquerda;

        else
            posicao = baixo;
    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 0 && c[3] == 1)
    {
        if(hip[1] < hip[2])
            posicao = esquerda;

        else
            posicao = cim;
    }

    if(c[0] == 0 && c[1] == 0 && c[2] == 1 && c[3] == 1)
    {
        if(hip[2] < hip[3])
            posicao = baixo;

        else
            posicao = cim;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 0)
    {
        if(hip[0] < hip[1] && hip[0] <= hip[2])
            posicao = direita;

        if(hip[1] < hip[2] && hip[0] <= hip[2])
            posicao = esquerda;

        else
            posicao = baixo;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 0 && c[3] == 1)
    {
        if(hip[0] < hip[1] && hip[0] < hip[3])
            posicao = direita;

        if(hip[1] < hip[3] && hip[1] < hip[0])
            posicao = esquerda;

        else
            posicao = cim;

    }

    if(c[0] == 0 && c[1] == 1 && c[2] == 1 && c[3] == 1)
    {
        if(hip[2] < hip[1] && hip[2] < hip[3])
            posicao = baixo;

        if(hip[1] < hip[2] && hip[1] < hip[3])
            posicao = esquerda;

        else
            posicao = cim;
    }

    if(c[0] == 1 && c[1] == 0 && c[2] == 1 && c[3] == 1)
    {
        if(hip[0] < hip[2] && hip[0] < hip[3])
            posicao = direita;

        if(hip[2] < hip[0] && hip[2] < hip[3])
            posicao = baixo;

        else
            posicao = cim;
    }

    if(c[0] == 1 && c[1] == 1 && c[2] == 1 && c[3] == 1)
    {
        if(hip[0] < hip[2] && hip[0] < hip[3] && hip[0] < hip[1])
            posicao = direita;

        if(hip[1] < hip[2] && hip[1] < hip[3] && hip[1] < hip[0])
            posicao = esquerda;

        if(hip[2] < hip[0] && hip[2] < hip[3] && hip[2] < hip[1])
            posicao = baixo;

        else
            posicao = cim;
    }


    switch(posicao) //Depois de checar as possibilidades, realiza o movimento real do fantasma
    {
        case(direita):
        {
            g.ghost[i].pos.x++;
            g.ghost[i].dir = right;
            break;
        }

        case(esquerda):
        {
            g.ghost[i].pos.x--;
            g.ghost[i].dir = left;
            break;
        }

        case(baixo):
        {
            g.ghost[i].pos.y++;
            g.ghost[i].dir = down;
            break;
        }

        case(cim):
        {
            g.ghost[i].pos.y--;
            g.ghost[i].dir = up;
            break;
        }

        default:
            break;
    }
    //Portal de teleporte dos fantasmas
    if(g.ghost[i].pos.x == 0 && g.ghost[i].pos.y == 10) //Esquerda-direita
        g.ghost[i].pos.x = 19, g.ghost[i].pos.y = 10;
    if(g.ghost[i].pos.x == 19 && g.ghost[i].pos.y == 10) //Direita-esquerda
        g.ghost[i].pos.x = 0, g.ghost[i].pos.y = 10;

    return g;

}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
