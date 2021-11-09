#ifndef DEF_H
#define DEF_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>
#include "llist.h"


#define TRUE 1
#define FALSE 0

#define PORT 50000
#define BACKLOG 128

#define SYMBOL_SIZE 3

#define USERS_FILE "utenti.txt"
#define USER_EVENTS_FILE "eventi.txt"
#define GAMES_FOLDER "./Partite"

#define SIGNUP 1
#define SIGNUP_SUCCESS "0\n"
#define USER_ALREADY_EXISTS "1\n"

#define LOGIN 2
#define LOGIN_SUCCESS "0\n"
#define USER_DOESNT_EXIST "1\n"
#define WRONG_PASSWORD "2\n"
#define USER_ALREADY_CONNECTED "3\n"

#define VIEW_ACTIVE_USERS 3
#define LOOK_FOR_MATCH 4

#define STOP_LOOKING_FOR_MATCH 5
#define START_MATCH "0\n"
#define LEAVE_QUEUE "1\n"

#define GAME_ACTION 6
#define ACTIVE_PLAYER_AND_TIME "1"
#define SUCCESSFUL_ATTACK "2"
#define FAILED_ATTACK "3"
#define MOVE_ON_OWN_SQUARE "4"
#define MOVE_ON_FREE_SQUARE "5"
#define TIME_ENDED "6\n"
#define TIME_ENDEND_PIPE_MESSAGE_WRITE "T"
#define TIME_ENDED_PIPE_MESSAGE_READ 'T'

#define LEAVE_MATCH 7
#define MATCH_LEFT "0\n"
#define MATCH_LEFT_PIPE_MESSAGE_WRITE "X"
#define MATCH_LEFT_PIPE_MESSAGE_READ 'X'

#define LOGOUT 8

#define TIMER_SECONDS 30



typedef unsigned long ulong;

typedef char Symbol[SYMBOL_SIZE];

typedef struct Client {
    // Rappresenta un Client e le relative informazioni
    ulong id;
    char nickname[32];
    int socket;
    int pipe[2];
    int activeGame;
    int positionInArrayOfPlayers;
    pthread_t thread;
} Client;

typedef struct Player {
    // Rappresenta un giocatore di una partita (che sarà sempre associato a un client)
    Client* client;
    Symbol symbol;
    int territories;
    int x;
    int y;
} Player;

typedef struct Game {
    // Rappresenta una partita
    ulong id;
    pthread_t thread;
    pthread_mutex_t nullPlayerLock;
    pthread_mutex_t gameFileLock;
    Symbol** grid;
    Player** players;
    Player* activePlayer;
    int file;
} Game;

#endif
