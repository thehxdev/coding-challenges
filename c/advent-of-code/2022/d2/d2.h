#ifndef AOC_D2_H
#define AOC_D2_H


/*
 * Both of the problems of day 2 solved with nested switch-case statements
 */


enum RoundStatScore {
    LOSE = 0,
    DRAW = 3,
    WIN  = 6,
};


enum HandScore {
    ROCK = 1,
    PAPER,
    SCISSORS,
};


// first challenge of day 2
int player_score(char opponent, char player) {
    /* Player:
     * X -> rock
     * Y -> paper
     * Z -> scissors
     * ----------------
     * Opponent:
     * A -> rock
     * B -> paper
     * C -> scissors
     */
    enum RoundStatScore rs;
    enum HandScore hs;

    switch(opponent) {
        case 'A': // Opponent played rock
            switch(player) {
                case 'X': hs = ROCK; rs = DRAW; break;
                case 'Y': hs = PAPER; rs = WIN; break;
                case 'Z': hs = SCISSORS; rs = LOSE; break;
                default: hs = 0; rs = 0;
            } break;

        case 'B': // Opponent played paper
            switch(player) {
                case 'X': hs = ROCK; rs = LOSE; break;
                case 'Y': hs = PAPER; rs = DRAW; break;
                case 'Z': hs = SCISSORS; rs = WIN; break;
                default: hs = 0; rs = 0;
            } break;

        case 'C': // Opponent played scissors
            switch(player) {
                case 'X': hs = ROCK; rs = WIN; break;
                case 'Y': hs = PAPER; rs = LOSE; break;
                case 'Z': hs = SCISSORS; rs = DRAW; break;
                default: hs = 0; rs = 0;
            } break;

        default: hs = 0; rs = 0;
    }

    return hs + rs;
}


// second challenge of day 2
int round_score(char opponent, char result) {
    /* Result:
     * X -> Lose
     * Y -> Draw
     * Z -> Win
     * ----------------
     * Opponent:
     * A -> rock
     * B -> paper
     * C -> scissors
     */
    enum RoundStatScore rs;
    enum HandScore hs;

    switch(opponent) {
        case 'A': // Opponent played rock
            switch(result) {
                case 'X': hs = SCISSORS; rs = LOSE; break;
                case 'Y': hs = ROCK; rs = DRAW; break;
                case 'Z': hs = PAPER; rs = WIN; break;
                default: hs = 0; rs = 0;
            } break;

        case 'B': // Opponent played paper
            switch(result) {
                case 'X': hs = ROCK; rs = LOSE; break;
                case 'Y': hs = PAPER; rs = DRAW; break;
                case 'Z': hs = SCISSORS; rs = WIN; break;
                default: hs = 0; rs = 0;
            } break;

        case 'C': // Opponent played scissors
            switch(result) {
                case 'X': hs = PAPER; rs = LOSE; break;
                case 'Y': hs = SCISSORS; rs = DRAW; break;
                case 'Z': hs = ROCK; rs = WIN; break;
                default: hs = 0; rs = 0;
            } break;

        default: hs = 0; rs = 0;
    }

    return hs + rs;
}

#endif
