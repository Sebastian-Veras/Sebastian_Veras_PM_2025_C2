#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>

typedef enum{
CASILLA = 0,
PEON,
CABALLO,
ALFIL,
TORRE,
REINA,
REY
}TipoPieza;

typedef enum{
SIN_COLOR = 0,
BLANCO,
NEGRO
}ColorPieza;

typedef struct{
TipoPieza tipo;
ColorPieza color;
}Pieza;


typedef struct{
int fila_origen,columna_origen;
int fila_destino,columna_destino;
}Movimiento;


#define TAMANO_TABLERO 8

Pieza tablero[TAMANO_TABLERO][TAMANO_TABLERO];


void inicializar_tablero();
void imprimir_tablero();
Pieza obtener_pieza_en(int f, int c);
void establecer_pieza_en(int f, int c, Pieza pieza);
bool parsear_coordenada(const char *cadena_coord, int *fila_ptr,int*columna_ptr);
bool obtener_movimiento_jugador(ColorPieza color_jugador_actual, Movimiento *movimiento_salida,char *error_msg_buffer,int buffer_size);
bool es_casilla_valida(int f, int c);
bool es_casilla_atacada(int fila, int columna,ColorPieza color_atacante);
bool encontrar_posicion_rey(ColorPieza color_rey,int*fila_rey,int*columna_rey);
bool esta_rey_en_jaque(ColorPieza color_rey);
bool rey_estaria_en_jaque_despues_de_movimiento(Movimiento m,ColorPieza color_jugador_actual);
bool es_movimiento_peon_legal(Movimiento m, ColorPieza color,char*error_msg_buffer,int buffer_size);
bool es_movimiento_torre_legal(Movimiento m,char *error_msg_buffer,int buffer_size);
bool es_movimiento_caballo_legal(Movimiento m, char*error_msg_buffer,int buffer_size);
bool es_movimiento_alfil_legal(Movimiento m,char*error_msg_buffer,int buffer_size);
bool es_moviemiento_reina_legal(Movimiento m, char*error_msg_buffer,int buffer_size);
bool es_movimiento_rey_legal(Movimiento m,char*error_msg_buffer,int buffer_size);
bool es_movimiento_legal(Movimiento m,ColorPieza color_jugador_actual,char*error_msg_buffer,int buffer_size);
void realizar_movimiento(Movimiento m);
bool puede_jugador_hacer_movimiento_legal(ColorPieza color_jugador);
bool verificar_fin_juego(ColorPieza color_jugador_actual);


void inicializar_tablero()
{
    for (int f = 0; f<TAMANO_TABLERO; f++ )
    {
        for(int c = 0;c <TAMANO_TABLERO; c++){
            tablero[f][c].tipo = CASILLA;
            tablero[f][c].color = SIN_COLOR;
        }
    }

    for (int c =0; c<TAMANO_TABLERO; c++){
        tablero[1][c] = (Pieza){PEON,BLANCO};
        tablero[6][c] = (Pieza){PEON, NEGRO};
    }

    tablero [0][0] = (Pieza){TORRE, BLANCO};
    tablero[0][1] = (Pieza){CABALLO,BLANCO};
    tablero [0][2] = (Pieza){ALFIL, BLANCO};
    tablero [0][3] = (Pieza){REINA, BLANCO};
    tablero [0][4] = (Pieza){REY, BLANCO};
    tablero [0][5] = (Pieza){ALFIL, BLANCO};
    tablero [0][6] = (Pieza){CABALLO, BLANCO};
    tablero [0][7] =(Pieza){TORRE, BLANCO};

    tablero [7][0] = (Pieza){TORRE,NEGRO};
    tablero [7][1] = (Pieza){CABALLO,NEGRO};
    tablero [7][2] = (Pieza){ALFIL,NEGRO};
    tablero [7][3] = (Pieza){REINA,NEGRO};
    tablero [7][4] = (Pieza){REY,NEGRO};
    tablero [7][5] = (Pieza){ALFIL,NEGRO};
    tablero [7][6] = (Pieza){CABALLO,NEGRO};
    tablero [7][7] = (Pieza){TORRE,NEGRO};
}

void imprimir_tablero()
    {
        printf("\n  a b c d e f g h\n");
        printf(" ------------------\n");



        for (int f = TAMANO_TABLERO -1;f>=0; f--){
            printf("%d|", f + 1);

        for (int c = 0;c <TAMANO_TABLERO; c++)
        {
            char*caracter_pieza = " ";

        switch (tablero[f][c].tipo){
            case PEON: caracter_pieza = (tablero[f][c].color == BLANCO)? "♙ " : "♟ "; break;
            case CABALLO: caracter_pieza = (tablero[f][c].color == BLANCO)? "♘ " : "♞ "; break;
            case ALFIL:  caracter_pieza = (tablero[f][c].color == BLANCO)? "♗ " : "♝ "; break;
            case TORRE: caracter_pieza = (tablero[f][c].color == BLANCO)?"♖ " : "♜ "; break;
            case REINA: caracter_pieza = (tablero[f][c].color == BLANCO)?"♕ " : "♛ ";break;
            case REY: caracter_pieza =(tablero[f][c].color == BLANCO)?"♔ " : "♚ ";break;
            case CASILLA: caracter_pieza = "  "; break;
            default:             caracter_pieza = "??";break;
            }
            printf("%s",caracter_pieza);

        }
        printf("|%d\n",f +1);
    }
    printf(" -----------------\n");
    printf("  a b c d e f g h\n\n");
}

Pieza obtener_pieza_en(int f,int c)
{
    return tablero[f][c];
}

void establecer_pieza_en(int f, int c, Pieza pieza)
{
    tablero [f][c] = pieza;
}

bool parsear_coordenada(const char*cadena_coord, int*fila_ptr,int*columna_ptr)
{
    if (cadena_coord == NULL || strlen(cadena_coord) !=2){
        return false;
    }
    char caracter_columna = tolower(cadena_coord[0]);
    char caracter_fila = cadena_coord[1];

    if (!isalpha(caracter_columna) || caracter_columna < 'a' || caracter_columna > 'h')
    {
        return false;
    }
    if (!isdigit(caracter_fila) || caracter_fila < '1' ||  caracter_fila > '8')
    {
        return false;
    }
    *columna_ptr = caracter_columna - 'a';
    *fila_ptr = (caracter_fila - '1');


    return true;
}




bool obtener_movimiento_jugador(ColorPieza color_jugador_actual, Movimiento *movimiento_salida, char*error_msg_buffer,int buffer_size)
{
    char buffer_entrada[10];
    char cadena_origen[3];
    char cadena_destino[3];


    snprintf(error_msg_buffer,buffer_size, "");

    printf("Jugador de color %s. Introduce tu movimiento de inicio y destino (ej.'a2 a3' o salir):",
           (color_jugador_actual == BLANCO)? "Blanco":"Negro");

    if (fgets(buffer_entrada, sizeof(buffer_entrada),stdin) == NULL)
    {
        printf("Error al leer la entrada. \n");
        return false;
    }
    buffer_entrada[strcspn(buffer_entrada, "\n")] = 0;

    if(strcmp(buffer_entrada, "salir") == 0)
    {
        exit(0);
    }

    if (sscanf(buffer_entrada, "%2s %2s",cadena_origen,cadena_destino) != 2)
    {
        printf("Formato de movimiento incorrecto. Usa 'col_origen, fila_origen, col_destino, fila_destino' (ej. a2 a3)\n");
        return false;
    }
  if (!parsear_coordenada(cadena_origen, &movimiento_salida->fila_origen, &movimiento_salida->columna_origen))
  {
      printf("Coordenada de origen '%s' incorrecta.\n", cadena_origen);
      return false;
  }
  if (!parsear_coordenada(cadena_destino, &movimiento_salida->fila_destino,&movimiento_salida->columna_destino))
  {
      printf("Coordenadas de destino '%s' incorrectas. \n",cadena_destino);
      return false;
  }
  error_msg_buffer[0] = '\0';
  return true;

}


bool es_casilla_valida(int f, int c)
{
return (f >= 0 && f< TAMANO_TABLERO && c >= 0 && c < TAMANO_TABLERO);
}

bool encontrar_posicion_rey(ColorPieza color_rey, int *fila_rey, int *columna_rey)
{
    for(int f = 0; f < TAMANO_TABLERO; f++ )
    {for (int c = 0; c <TAMANO_TABLERO; c++){
            Pieza p = obtener_pieza_en(f,c);
            if (p.tipo == REY && p.color == color_rey)
            {
                *fila_rey = f;
                *columna_rey = c;
                return true;
            }
        }
    }
    return false;
}

bool es_casilla_atacada(int fila, int columna, ColorPieza color_atacante)
{
    int movimientos_caballo [8][2] = {{-2,-1},{-2,1},{-1,2}, {1,-2}, {1,2},{2,-1},{2,1}};
    for (int i = 0; i < 8; i++){
        int f = fila + movimientos_caballo [i][0];
        int c = columna + movimientos_caballo [i][1];
        if (es_casilla_valida(f,c) && obtener_pieza_en(f,c).tipo == CABALLO && obtener_pieza_en(f,c).color == color_atacante){
            return true;
        }
    }


    if (color_atacante == BLANCO)
    {
        if (es_casilla_valida(fila - 1, columna - 1 ) && obtener_pieza_en(fila -1,columna - 1).tipo == PEON && obtener_pieza_en(fila - 1, columna - 1).color == BLANCO) return true;
        if (es_casilla_valida(fila - 1, columna + 1) && obtener_pieza_en(fila -1, columna + 1).tipo == PEON && obtener_pieza_en(fila - 1, columna + 1).color == BLANCO) return true;
    }
    else {
        if (es_casilla_valida(fila + 1, columna -1) && obtener_pieza_en(fila + 1, columna -1).tipo == PEON && obtener_pieza_en(fila + 1, columna -1).color == NEGRO)return true;
        if(es_casilla_valida(fila + 1,columna +1) && obtener_pieza_en(fila + 1, columna + 1 ).tipo == PEON && obtener_pieza_en(fila + 1, columna + 1).color == NEGRO) return true;
    }

    int movimientos_rey[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i = 0; i < 8;  i++){
    int f = fila + movimientos_rey[i][0];
    int c = columna + movimientos_rey[i][1];
    if (es_casilla_valida(f,c) && obtener_pieza_en(f,c).tipo == REY && obtener_pieza_en(f,c).color == color_atacante){
        return true;
    }
    }
    int direcciones_rectas[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    for (int i = 0; i < 4; i++)
    {
        for (int paso = 1; paso < TAMANO_TABLERO; paso++)
        {
            int f = fila + direcciones_rectas[i][0] * paso;
            int c = columna +direcciones_rectas[i][1] * paso;
            if (!es_casilla_valida(f,c)) break;
            Pieza p = obtener_pieza_en(f,c);
            if (p.tipo != CASILLA){
                if (p.color == color_atacante && (p.tipo == TORRE || p.tipo == REINA)) return true;
                break;
            }
        }
    }

    int direcciones_diag [4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
    for (int i = 0; i < 4; i ++ )
    {
        for(int paso = 1; paso < TAMANO_TABLERO; paso ++){
        int f = fila + direcciones_diag[i][0] * paso;
        int c = columna + direcciones_diag[i][1] * paso;
        if (!es_casilla_valida(f,c))break;
        Pieza p = obtener_pieza_en(f,c);
        if (p.tipo != CASILLA){
        if (p.color == color_atacante && (p.tipo == ALFIL || p.tipo == REINA)) return true;

        }
    }
}
return false;
}

bool esta_rey_en_jaque(ColorPieza color_rey)
{
    int fila_rey, columna_rey;
    if (!encontrar_posicion_rey(color_rey, &fila_rey, &columna_rey))
    {
        fprintf(stderr, "Error: Rey de color %d no encontrado en el tablero.\n", color_rey);
        return false;
    }
    ColorPieza color_oponente = (color_rey == BLANCO)?NEGRO:BLANCO;
    return es_casilla_atacada(fila_rey,columna_rey, color_oponente);
}

bool rey_estaria_en_jaque_despues_de_movimiento(Movimiento m, ColorPieza color_jugador_actual)
{
    Pieza tablero_original[TAMANO_TABLERO][TAMANO_TABLERO];
    for (int f = 0; f < TAMANO_TABLERO; f++){
        for (int c = 0; c < TAMANO_TABLERO; c++){
            tablero_original[f][c] = tablero[f][c];
        }
    }

    Pieza pieza_movida = obtener_pieza_en(m.fila_origen,m.columna_origen);
    establecer_pieza_en(m.fila_destino,m.columna_destino,pieza_movida);
    establecer_pieza_en(m.fila_origen, m.columna_origen, (Pieza){CASILLA,SIN_COLOR});

 bool en_jaque = esta_rey_en_jaque(color_jugador_actual);

 for(int f = 0; f<TAMANO_TABLERO; f++)
 {
     for (int c = 0; c < TAMANO_TABLERO; c++){
        tablero[f][c] = tablero_original[f][c];

     }
 }
return en_jaque;


}


bool es_movimiento_peon_legal(Movimiento m, ColorPieza color, char *error_msg_buffer, int buffer_size)
{
    int df = m.fila_destino - m.fila_origen;
    int dc = m.columna_destino - m.columna_origen;
    Pieza pieza_destino = obtener_pieza_en(m.fila_destino,m.columna_destino);

    if(pieza_destino.tipo != CASILLA && pieza_destino.color == color){
        snprintf(error_msg_buffer,buffer_size, "Movimiento de peon no permitido.");
        return false;

    }


    if (color == BLANCO)
    {

        if (dc == 1 && dc == 0)
        {
            if (pieza_destino.tipo == CASILLA)
            {
                return true;
            }
        }
        else if (df == 2 && dc == 0 && m.fila_origen ==1 )
        {
            if (pieza_destino.tipo == CASILLA)
            {
                return true;
            }
        }
        else if (df == 1 && abs (dc) == 1)
        {
            if (pieza_destino.tipo !=CASILLA && pieza_destino.color == NEGRO)
            {
                return true;
            }
        }
    }

else{
        if(dc == 0 && df == -1)
        {
            if (pieza_destino.tipo == CASILLA)return true;

        }
        else if (df == -2 && dc == 0  && m.fila_origen == 6){
                if (pieza_destino.tipo == CASILLA && obtener_pieza_en(m.fila_origen - 1, m.columna_origen).tipo == CASILLA);
                {


                    return true;
            }

        }

       else if  (df == -1 && abs(dc) == 1)
        {
            if (pieza_destino.tipo != CASILLA && pieza_destino.color == BLANCO)
            {return true;}
        }
    }
     snprintf(error_msg_buffer,buffer_size,"Movimiento de Peon no permitido por las reglas del juego");
    return false;
}







bool es_movimiento_torre_legal(Movimiento m, char * error_msg_buffer, int buffer_size)
{
    int df = m.fila_destino - m.fila_origen;
    int dc = m.columna_destino - m.columna_origen;

    if (df != 0 && dc != 0) return false;

    if (df == 0)
    {
        int inicio_ruta_c = (m.columna_origen < m.columna_destino)? m.columna_origen:m.columna_destino;
        int fin_ruta_c = (m.columna_origen <m.columna_destino)? m.columna_destino:m.columna_origen;
        for (int c = inicio_ruta_c + 1; c < fin_ruta_c; c++)
        {
            if(obtener_pieza_en(m.fila_origen,c).tipo !=CASILLA){
                snprintf(error_msg_buffer,buffer_size, "Movimiento de  Torre bloqueado horizontalmente");
                return false;
            }
        }

    }else {
       int inicio_ruta_f = (m.fila_origen < m.fila_destino)? m.fila_origen: m.fila_destino;
       int fin_ruta_f = (m.fila_origen < m.fila_destino)? m.fila_destino : m.fila_origen;
       for (int f = inicio_ruta_f + 1; f<fin_ruta_f;f++)
       {
           if (obtener_pieza_en(f, m.columna_origen).tipo !=CASILLA){
            snprintf(error_msg_buffer,buffer_size,"Movimiento de Torre bloqueado verticalmente");
            return false;
           }
       }
    }
    return true;
}


bool es_movimiento_caballo_legal(Movimiento m, char *error_msg_buffer, int buffer_size)
{
int df = abs(m.fila_destino - m.fila_origen);
int dc = abs(m.columna_destino - m.columna_origen);


if (!((df == 2 && dc ==1 )||(df == 1 && dc == 2)))
{

snprintf(error_msg_buffer,buffer_size,"Movimiento de Caballo no tiene de 'L' ");
return false;
}
return true;

}



bool es_movimiento_alfil_legal(Movimiento m, char *error_msg_buffer, int buffer_size)
{
    int df = m.fila_destino - m.fila_origen;
    int dc = m.columna_destino - m.columna_origen;

    if (abs(df) !=abs(dc))
    {
        snprintf(error_msg_buffer,buffer_size,"Movimiento de Alfil no es diagonal.");
        return false;
    }

    int dir_f = (df > 0)?1:-1;
    int dir_c = (dc > 0)? 1:-1;


    for (int paso = 1; paso < abs(df); paso++ )
    {
        if (obtener_pieza_en(m.fila_origen + paso*dir_f,m.columna_origen + paso *dir_c).tipo !=CASILLA)
        {
            snprintf(error_msg_buffer,buffer_size, "Movimiento de Alfil bloqueado diagonalmente");
            return false;
        }
    }
    return true;
}

bool es_moviemiento_reina_legal(Movimiento m, char*error_msg_buffer,int buffer_size)
{
   int df = m.fila_destino - m.fila_origen;
   int dc = m.columna_destino - m.columna_origen;

   if ((df == 0 && dc !=0) || (df !=0 && dc == 0))
   {
       return es_movimiento_torre_legal(m,error_msg_buffer,buffer_size);
   }
   else if (abs(df) == abs (dc))
   {
       return es_movimiento_alfil_legal(m,error_msg_buffer,buffer_size);
   }
   else {
    snprintf(error_msg_buffer,buffer_size, "Movimiento de la reina no es valido (ni recto ni diagonal).");
    return false;
   }
}
//mm//


bool es_movimiento_rey_legal(Movimiento m, char *error_msg_buffer, int buffer_size)
{
    int df = abs(m.fila_destino - m.fila_origen);
    int dc = abs(m.columna_destino - m.columna_origen);

    if(df > 1 || dc > 1){
        snprintf(error_msg_buffer,buffer_size, "Movimiento de Rey excede una casilla");
        return false;
    }
    return true;
}
bool es_movimiento_legal(Movimiento m, ColorPieza color_jugador_actual, char *error_msg_buffer, int buffer_size)
{
    if (!es_casilla_valida(m.fila_origen,m.columna_origen) || !es_casilla_valida(m.fila_destino, m.columna_destino))
    {
        if (error_msg_buffer !=NULL && buffer_size > 0)
        {
            snprintf(error_msg_buffer,buffer_size,"Error: Coordenadas fuera del tablero");
            return false;
        }
    }
    Pieza pieza_origen = obtener_pieza_en(m.fila_origen, m.columna_origen);
    Pieza pieza_destino = obtener_pieza_en(m.fila_destino,m.columna_destino);

    if(pieza_origen.tipo == CASILLA)
    {
        snprintf(error_msg_buffer,buffer_size,"Error: No hay pieza en la casilla de origen (%c%d). \n",
        'a' + m.columna_origen,m.fila_origen + 1);
        return false;
    }
    if (pieza_origen.color != color_jugador_actual)
    {
        snprintf(error_msg_buffer,buffer_size, "Error: La pieza en la casilla de origen (%c%d) no es tuya. \n",
        'a' + m.columna_origen,m.fila_origen + 1);
        return false;

    }

    if (pieza_destino.tipo !=CASILLA && pieza_destino.color == color_jugador_actual)
    {
        snprintf(error_msg_buffer,buffer_size, "Error: No puedes capturar tu propia pieza en la casilla de destino (%c%d). \n",
        'a' +m.columna_destino, m.fila_destino + 1);
        return false;
    }

    bool movimiento_pieza_ok = false;
    switch (pieza_origen.tipo)
    {
        case PEON: movimiento_pieza_ok = es_movimiento_peon_legal(m, color_jugador_actual,error_msg_buffer,buffer_size); break;
        case TORRE: movimiento_pieza_ok = es_movimiento_torre_legal(m,error_msg_buffer,buffer_size);break;
        case CABALLO: movimiento_pieza_ok = es_movimiento_caballo_legal(m, error_msg_buffer,buffer_size);break;
        case ALFIL: movimiento_pieza_ok = es_movimiento_alfil_legal(m,error_msg_buffer,buffer_size);break;
        case REINA: movimiento_pieza_ok = es_moviemiento_reina_legal(m, error_msg_buffer,buffer_size); break;
        case REY: movimiento_pieza_ok = es_movimiento_rey_legal(m, error_msg_buffer,buffer_size);break;
        case CASILLA:
            snprintf(error_msg_buffer,buffer_size, "Error interno: La casilla esta vacia tiene erorres internos");
            movimiento_pieza_ok = false; break;
    }

    if(!movimiento_pieza_ok)
    {
        return false;
    }
    if(rey_estaria_en_jaque_despues_de_movimiento(m,color_jugador_actual))
    {

    snprintf(error_msg_buffer,buffer_size,"Este movimiento deja a tu rey en jaque: (%c%d a %c%d)\n",
    'a'  + m.columna_origen,m.fila_origen + 1, 'a' + m.columna_destino, m.fila_destino + 1);
    return false;

    }

    return true;
}

void realizar_movimiento(Movimiento m)
{
    establecer_pieza_en(m.fila_destino,m.columna_destino,obtener_pieza_en(m.fila_origen,m.columna_origen));
    establecer_pieza_en(m.fila_origen,m.columna_origen, (Pieza){CASILLA,SIN_COLOR});

}

bool puede_jugador_hacer_movimiento_legal(ColorPieza color_jugador)
{
    char temp_error_buffer[512];

    for (int f_origen = 0; f_origen < TAMANO_TABLERO; f_origen++){
        for (int c_origen = 0; c_origen < TAMANO_TABLERO; c_origen ++){
            Pieza pieza_actual = obtener_pieza_en(f_origen,c_origen);

            if (pieza_actual.color != color_jugador){
                continue;
            }

            for(int f_destino = 0; f_destino < TAMANO_TABLERO; f_destino++)
            {
                for(int c_destino = 0; c_destino < TAMANO_TABLERO; c_destino++)
                {
                    Movimiento movimiento_potencial = {f_origen,c_origen,f_destino,c_destino};
                    if(es_movimiento_legal(movimiento_potencial, color_jugador,temp_error_buffer,sizeof(temp_error_buffer))){
                        return true;
                    }
                }
            }

        }
    }
    return false;
}


bool verificar_fin_juego(ColorPieza color_jugador_actual){
if(!puede_jugador_hacer_movimiento_legal(color_jugador_actual))
{
    if(esta_rey_en_jaque(color_jugador_actual)){
        printf("\n!!! JAQUE MATE  !!!\n");
        printf("Ganan las %s \n.", (color_jugador_actual == BLANCO)? "Negras": "Blancas");
    }
    else {
        printf("\n !!! EMPATE POR AHOGADO !!!\n");
        printf("El jugador %s no tiene movimientos legales pero no esta en jaque. \n", (color_jugador_actual == BLANCO)?"Blanco": "Negro");
    }
    return true;
}
return false;
}

int main() {
setlocale(LC_ALL,"");
printf("--- Juego de Ajedrez - Por Turnos ---\n");
printf("Introduce movimiento en formato'a2 a4'. Escribe 'salir' para terminar. \n");


inicializar_tablero();
ColorPieza jugador_actual = BLANCO;

bool juego_terminado = false;
char ultimo_error_msg[256];

while (!juego_terminado){
    imprimir_tablero();

    Movimiento movimiento_jugador;
    bool movimiento_ajedrez_valido = false;

 while (!movimiento_ajedrez_valido)
 {
     if(!obtener_movimiento_jugador(jugador_actual, &movimiento_jugador,ultimo_error_msg,sizeof(ultimo_error_msg)))
     {
         printf("Error %s \n", ultimo_error_msg);
         continue;
     }
     if (es_movimiento_legal(movimiento_jugador,jugador_actual,ultimo_error_msg,sizeof(ultimo_error_msg)))
     {
         movimiento_ajedrez_valido = true;
     }
     else {
        printf("Error %s\n",ultimo_error_msg);
        continue;
     }
 }

realizar_movimiento(movimiento_jugador);

ColorPieza siguiente_jugador = (jugador_actual == BLANCO) ? NEGRO:BLANCO;
juego_terminado = verificar_fin_juego(siguiente_jugador);


if(!juego_terminado)
{
    if(esta_rey_en_jaque(siguiente_jugador))
    {
        printf("!!!Jaque al rey %s !!!\n",(siguiente_jugador == BLANCO)? "Blanco": "Negro");
    }
    jugador_actual = siguiente_jugador;
}
}
printf("\n --- Fin del juego ----\n");
return 0;






}
