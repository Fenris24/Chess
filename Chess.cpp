#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
bool chess = 1;
int chessNr[8][8] =
{
    { -9,-10,-11,-12,-13,-14,-15,-16},
    { -1, -2, -3, -4, -5, -6, -7, -8},
    {  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0,  0,  0,  0,  0,  0},
    {  1,  2,  3,  4,  5,  6,  7,  8},
    {  9, 10, 11, 12, 13, 14, 15, 16}
};
//Piece identifiers
void identl(char box[2], int &x, int &y)
{
    int lenght = 1;
    while(lenght != -1)
    {
        switch(box[lenght])
        {
            case 'a':
            y = 0;
            break;

            case 'b':
            y = 1;
            break;

            case 'c':
            y = 2;
            break;

            case 'd':
            y = 3;
            break;

            case 'e':
            y = 4;
            break;

            case 'f':
            y = 5;
            break;

            case 'g':
            y = 6;
            break;

            case 'h':
            y = 7;
            break;

            case '1':
            x = 7;
            break;

            case '2':
            x = 6;
            break;

            case '3':
            x = 5;
            break;

            case '4':
            x = 4;
            break;

            case '5':
            x = 3;
            break;

            case '6':
            x = 2;
            break;

            case '7':
            x = 1;
            break;

            case '8':
            x = 0;
            break;
        }
        lenght --;
    }
}
int identp(char pezzo[3])
{
    int nrp = 100;
    if(strcmp(pezzo,"P1") == 0)
    nrp = 1;
    if(strcmp(pezzo,"P2") == 0)
    nrp = 2;
    if(strcmp(pezzo,"P3") == 0)
    nrp = 3;
    if(strcmp(pezzo,"P4") == 0)
    nrp = 4;
    if(strcmp(pezzo,"P5") == 0)
    nrp = 5;
    if(strcmp(pezzo,"P6") == 0)
    nrp = 6;
    if(strcmp(pezzo,"P7") == 0)
    nrp = 7;
    if(strcmp(pezzo,"P8") == 0)
    nrp = 8;
    if(strcmp(pezzo,"R1") == 0)
    nrp = 9;
    if(strcmp(pezzo,"K1") == 0)
    nrp = 10;
    if(strcmp(pezzo,"B1") == 0)
    nrp = 11;
    if(strcmp(pezzo,"Qu") == 0)
    nrp = 12;
    if(strcmp(pezzo,"Ki") == 0)
    nrp = 13;
    if(strcmp(pezzo,"B2") == 0)
    nrp = 14;
    if(strcmp(pezzo,"K2") == 0)
    nrp = 15;
    if(strcmp(pezzo,"R2") == 0)
    nrp = 16;
    return nrp;
}
void findpiece(int pieceh, int &xi, int &yj)
{
    for(int i = 0; i <= 7; i ++)
        for(int j = 0; j <= 7; j ++)
    {
        if(pieceh == chessNr[i][j])
            {
                xi = i;
                yj = j;
                break;
            }
    }
}
bool piecexist(int pieceh)
{
    for(int i = 0; i <= 7; i ++)
        for(int j = 0; j <= 7; j ++)
            if(pieceh == chessNr[i][j])
                return 1;
    return 0;
}
//Table
void tablepiece(int x)
{
    switch(x)
    {
        case -16:
        cout << "r2";
        break;
        case -15:
        cout << "k2";
        break;
        case -14:
        cout << "b2";
        break;
        case -13:
        cout << "ki";
        break;
        case -12:
        cout << "qu";
        break;
        case -11:
        cout << "b1";
        break;
        case -10:
        cout << "k1";
        break;
        case -9:
        cout << "r1";
        break;
        case -8:
        cout << "p8";
        break;
        case -7:
        cout << "p7";
        break;
        case -6:
        cout << "p6";
        break;
        case -5:
        cout << "p5";
        break;
        case -4:
        cout << "p4";
        break;
        case -3:
        cout << "p3";
        break;
        case -2:
        cout << "p2";
        break;
        case -1:
        cout << "p1";
        break;
        case 0:
        cout << "  ";
        break;
        case 1:
        cout << "P1";
        break;
        case 2:
        cout << "P2";
        break;
        case 3:
        cout << "P3";
        break;
        case 4:
        cout << "P4";
        break;
        case 5:
        cout << "P5";
        break;
        case 6:
        cout << "P6";
        break;
        case 7:
        cout << "P7";
        break;
        case 8:
        cout << "P8";
        break;
        case 9:
        cout << "R1";
        break;
        case 10:
        cout << "K1";
        break;
        case 11:
        cout << "B1";
        break;
        case 12:
        cout << "Qu";
        break;
        case 13:
        cout << "Ki";
        break;
        case 14:
        cout << "B2";
        break;
        case 15:
        cout << "K2";
        break;
        case 16:
        cout << "R2";
        break;
    }
}
void chesstable()
{
    for(int i = 0; i <= 7; i ++)
    {
        cout << 8 - i << " |";
        for(int j = 0; j <= 7; j ++)
        {
            tablepiece(chessNr[i][j]);
            cout << "|";
        }
        cout << endl;
        if(i == 2)
            cout << "  -------------------------         Write 'Surrend' in 'Choose the piece' to end the game";
        else if(i == 3)
            cout << "  -------------------------         Write 'Change' in 'Insert move' to choose a new piece (1 availability)  ";
        else
            cout << "  -------------------------";
        cout << endl;
    }
    cout << "   ";
    char c;
    for (c = 'a'; c <= 'h'; c ++)
        cout << c << "  ";
}
//Verifiers of validity
bool vrook(int px, int py, int cx, int cy)
{
    if(px == cx && py > cy)
    {
        int m = py;
        while(m != cy)
        {
            m --;
            if(m == cy)
                return 1;
            if(chessNr[px][m] != 0)
                return 0;
        }
    }
    if(px == cx && py < cy)
    {
        int m = py;
        while(m != cy)
        {
            m ++;
            if(m == cy)
                return 1;
            if(chessNr[px][m] != 0)
                return 0;
        }
    }
    if(py == cy && px < cx)
    {
        int m = px;
        while(m != cx)
        {
            m ++;
            if(m == cx)
                return 1;
            if(chessNr[m][py] != 0)
                return 0;
        }
    }
    if(py == cy && px > cx)
    {
        int m = px;
        while(m != cx)
        {
            m --;
            if(m == cx)
                return 1;
            if(chessNr[m][py] != 0)
                return 0;
        }
    }
    return 0;
}
bool vbishop(int px, int py, int cx, int cy)
{
    if(px < cx && py < cy)
    {
        int m = px, n = py;
        while(m < cx && n < cy)
        {
            m ++;
            n ++;
            if(m == cx && n == cy)
                return 1;
            if(chessNr[m][n] != 0)
                return 0;
        }
    }
    if(px < cx && py > cy)
    {
        int m = px, n = py;
        while(m < cx && n > cy)
        {
            m ++;
            n --;
            if(m == cx && n == cy)
                return 1;
            if(chessNr[m][n] != 0)
                return 0;
        }
    }
    if(px > cx && py > cy)
    {
        int m = px, n = py;
        while(m > cx && n > cy)
        {
            m --;
            n --;
            if(m == cx && n == cy)
                return 1;
            if(chessNr[m][n] != 0)
                return 0;
        }
    }
    if(px > cx && py < cy)
    {
        int m = px, n = py;
        while(m > cx && n < cy)
        {
            m --;
            n ++;
            if(m == cx && n == cy)
                return 1;
            if(chessNr[m][n] != 0)
                return 0;
        }
    }
    return 0;
}
bool vknight(int px, int py, int cx, int cy)
{
    if(px + 2 == cx && py + 1 == cy)
        return 1;
    if(px + 2 == cx && py - 1 == cy)
        return 1;
    if(px - 2 == cx && py + 1 == cy)
        return 1;
    if(px - 2 == cx && py - 1 == cy)
        return 1;
    if(px + 1 == cx && py + 2 == cy)
        return 1;
    if(px + 1 == cx && py - 2 == cy)
        return 1;
    if(px - 1 == cx && py + 2 == cy)
        return 1;
    if(px - 1 == cx && py - 2 == cy)
        return 1;
    return 0;
}
bool vking(int px, int py, int cx, int cy)
{
    bool a = 0, b = 0, c = 0;
    if(((px - cx == 1) || (px - cx == -1)) && (py - cy == 0))
        a = 1;
    if(((py - cy == 1) || (py - cy == -1)) && (px - cx == 0))
        b = 1;
    if(((px - cx == 1) || (px - cx == -1)) && ((py - cy == 1) || (py - cy == -1)))
        c = 1;
    if(a == 1 || b == 1 || c == 1)
        return 1;
    return 0;
}
bool validity(int nrpiece, int px, int py, int cx, int cy)
{
    //pawn
    if(nrpiece <= 8 && px == 6 && (cx == px - 1 || cx == px - 2) && cy == py && chessNr[cx][cy] < 1)
    {
        return 1;
    }
    if(nrpiece <= 8 && cx == px - 1 && cy == py && chessNr[cx][cy] < 1)
    {
        return 1;
    }
    if(nrpiece <= 8 && (cx == px - 1 && (cy == py - 1 || cy == py + 1)) && chessNr[cx][cy] < 0)
    {
        return 1;
    }
    if(nrpiece <= 8 && ((chessNr[px][py - 1] < 0) || (chessNr[px][py + 1] < 0)) && ((chessNr[px - 1][py - 1] == 0) || (chessNr[px - 1][py + 1] == 0)) && ((cx == px - 1) && ((cy == py - 1) || (cy == py + 1))))
    {
        chessNr[cx + 1][cy] = 0;
        return 1;
    }
    //rook
    if((nrpiece == 9 || nrpiece == 16) && ((cx != px && cy == py) || (cx == px && cy != py)) && vrook(px, py, cx, cy) == 1 && chessNr[cx][cy] < 1)
    {
        return 1;
    }
    //knight
    if((nrpiece == 10 || nrpiece == 15) && vknight(px, py, cx, cy) == 1 && chessNr[cx][cy] < 1)
    {
        return 1;
    }
    //bishop
    if((nrpiece == 11 || nrpiece == 14) && (((px + py == cx + cy) && (px != cx && py != cy)) || ((px - cx) == (py - cy))) && vbishop(px, py, cx, cy) == 1 && chessNr[cx][cy] < 1)
    {
        return 1;
    }
    //queen
    if(nrpiece == 12 && (vrook(px, py, cx, cy) == 1 || vbishop(px, py, cx, cy) == 1) && chessNr[cx][cy] < 1)
        return 1;
    //king
    if(nrpiece == 13 && vking(px, py, cx, cy) == 1 && chessNr[cx][cy] < 1)
        return 1;
    return 0;
}
bool validityR(int r, int ui, int uj, int vi, int vj)
{
    //pawn
    if(r <= 8 && ui == 1 && (vi == ui + 1 || vi == ui + 2) && vj == uj && chessNr[vi][vj] >= 0)
    {
        return 1;
    }
    if(r <= 8 && vi == ui + 1 && vj == uj && chessNr[vi][vj] >= 0)
    {
        return 1;
    }
    if(r <= 8 && (vi == ui + 1 && (vj == uj - 1 || vj == uj + 1)) && chessNr[vi][vj] > 0)
    {
        return 1;
    }
    if(r <= 8 && ((chessNr[ui][uj - 1] > 0) || (chessNr[ui][uj + 1] > 0)) && ((chessNr[ui + 1][uj - 1] == 0) || (chessNr[ui + 1][uj + 1] == 0)) && ((vi == ui + 1) && ((vj == uj - 1) || (vj == uj + 1))))
    {
        chessNr[vi + 1][vj] = 0;
        return 1;
    }
    //rook
    if((r == 9 || r == 16) && ((vi != ui && vj == uj) || (vi == ui && vj != uj)) && vrook(ui, uj, vi, vj) == 1 && chessNr[vi][vj] >= 0)
    {
        return 1;
    }
    //knight
    if((r == 10 || r == 15) && vknight(ui, uj, vi, vj) == 1 && chessNr[vi][vj] >= 0)
    {
        return 1;
    }
    //bishop
    if((r == 11 || r == 14) && (((ui + uj == vi + vj) && (ui != vi && uj != vj)) || ((ui - vi) == (uj - vj))) && vbishop(ui, uj, vi, vj) == 1 && chessNr[vi][vj] >= 0)
    {
        return 1;
    }
    //queen
    if(r == 12 && (vrook(ui, uj, vi, vj) == 1 || vbishop(ui, uj, vi, vj) == 1) && chessNr[vi][vj] >= 0)
        return 1;
    //king
    if(r == 13 && vking(ui, uj, vi, vj) == 1 && chessNr[vi][vj] >= 0)
        return 1;
    return 0;
}
void player()
{
    int ai, aj, bi, bj;
    int nrpiece;
    bool pk = 0, one = 1;
    char pezzo[8], casella[8];
    cout << endl;
    cout << endl;
    while(one)
    {
    if(pk == 0)
    {
        cout << "Choose the piece: ";
        cin >> pezzo;
        if(strcmp(pezzo, "Surrend") == 0)
        {
            chess = 0;
            break;
        }
        nrpiece = identp(pezzo);
    }
    if(nrpiece == 100)
    {
        cout << "Choose a valid piece.";
        cout << endl;
    }
    else
    {
        pk = 1;
        cout << "Insert move: ";
        cin >> casella;
        if(strcmp(casella, "Change") == 0)
        {
            cout << "Choose a new piece: ";
            cin >> pezzo;
            nrpiece = identp(pezzo);
            if(nrpiece == 100)
            {
                cout << "Choose a valid piece.";
            }
            cout << "Insert move: ";
            cin >> casella;
        }
        findpiece(nrpiece, ai, aj);
        identl(casella, bi, bj);
        if(validity(nrpiece, ai, aj, bi, bj) == 0)
        {
            cout << "Insert a valid move" << endl;
        }
        else
        {
            one = 0;
            chessNr[bi][bj] = chessNr[ai][aj];
            chessNr[ai][aj] = 0;
        }
    }
    }
}
void computer()
{
    int r, r1, r2, t = 0;
    int ui, uj, vi, vj;
    bool ok = 1;
    srand(time(NULL));
    r = rand() % 16 + 1;
    while(piecexist(r) == 0)
        r = rand() % 16 + 1;
    findpiece(-r, ui, uj);
    while(ok)
    {
        r1 = rand() % 7;
        r2 = rand() % 7;
        t ++;
        if(chessNr[r1][r2] >= 0 && validityR(r, ui, uj, r1, r2) == 1)
        {
            ok = 0;
            vi = r1;
            vj = r2;
        }
        if(t == 100)
        {
            t = 0;
            r = rand() % 16 + 1;
            findpiece(-r, ui, uj);
        }
    }
    if(validityR(r, ui, uj, vi, vj) == 1)
    {
        chessNr[vi][vj] = chessNr[ui][uj];
        chessNr[ui][uj] = 0;
    }
}
int main()
{
    while(chess)
    {
        system("CLS");
        chesstable();
        player();
        if(chess == 0)
            break;
        system("CLS");
        chesstable();
        computer();
        system("CLS");
        chesstable();
        if(piecexist(13) == 0 || piecexist(-13) == 0)
            chess = 0;
    }
    return 0;
}
