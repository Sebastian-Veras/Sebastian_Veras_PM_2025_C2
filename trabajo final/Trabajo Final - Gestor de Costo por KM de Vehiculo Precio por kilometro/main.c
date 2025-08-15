#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Arch_carro "carro.dat"
#define Archdatageneral "datosgeneral.dat"
#define maximocarro 200




typedef struct {
float precio_gasolina;
float precio_disel;
}data_generales;

 typedef  struct{
char Placa[8];
 char Marca[50];
 char Modelo[50];
 int año;
 char motor;
 char tipo_de_combustible[15];
 float km_por_gl_min_cuidad;
 float km_por_gl_max_carrectera;
 float costo_de_gomas;
 int vida_gomas;
 float costo_de_seguro;
 float costo_de_mantenimiento;
 float costo_del_vehiculo;
 int vida_util;
 float depresiacion;
 int kilometros_por_ano_promedio;
 int kilometro_matenimiento;
 int km_gomas;
}Carro;



void crearcarro();
int borrarcarro();
void modificarcarro();
void calcularviaje();
void modificacion_generales();
 void guarda_carro_archivo(const Carro carro[],int numero_carro);
 int carga_de_carro(Carro carro[]);
 void guardardatagenera (const data_generales *gd);
 void cargardatagenera ( data_generales *gd);
 void lista_carros();
 void menu_principal(int nivel_del_menu);
 int buscarplaca(const Carro carro[],int numero,const char *placa);
int validacionplaca(const Carro carro[], int numerocarro, char *placa);
void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



int buscarplaca(const Carro carro[], int numero, const char *placa)
{
    for(int y =0; y < numero; y++)
    if(strcmp(carro[y].Placa,placa) == 0)
    {
        return y;
    }
    return -1;
}

 int validacionplaca(const Carro carro[],int numerocarro, char *placa)
 {
     int longitud;
     int placa_encotrada;
     int valido;

     do{
        printf("Placa (6-8 Caracteres): ");
        scanf("%s",placa);
        limpiar_buffer();
        longitud = strlen(placa);
        placa_encotrada = buscarplaca(carro, numerocarro, placa);
        valido = 1;
        if(longitud < 6 || longitud > 8){
            printf("Placa debe des ser de 6 a 8 carateres ");
            valido = 0;
        }
         if (placa_encotrada != -1)
        {
            printf("Ya existe esta Placa\n");
            valido = 0;
        }
     }
     while (valido == 0);
    return 1;
 }




 int carga_de_carro(Carro carro[])
 {
     FILE *Archivo = fopen (Arch_carro, "rb");
     if (Archivo == NULL)
     {
         return 0;
     }
     int numero_carro= 0;
     while(fread(&carro[numero_carro], sizeof(Carro), 1, Archivo) == 1)
     {
         numero_carro++;
         if(numero_carro >= maximocarro){
            break;
         }
     }

                   fclose(Archivo);
                   return numero_carro;

 }

 void guarda_carro_archivo(const Carro carro[],int numero_carro)
 {
     FILE* archivo = fopen(Arch_carro, "wb");
     if ( archivo == NULL )
     {
         printf("No se pudo abrir el archivo para guadar.\n");
         return;
     }
 fwrite(carro, sizeof(Carro), numero_carro,archivo);
fclose(archivo);
 }
 void guardardatagenera(const data_generales *gd)
 {
     FILE *arch = fopen(Archdatageneral, "wb");
     if(arch == NULL)
     {
         printf("No se puede abrir el archivo ");
     }
     fwrite(gd,sizeof(data_generales),1,arch);
     fclose(arch);
 }
 void cargardatagenera(  data_generales *gd)
 {
     FILE *arch = fopen(Archdatageneral, "rb");
     if(arch == NULL)
     {
         gd->precio_gasolina = 272.50;
         gd ->precio_disel = 242.10;
         return;
     }
     fread(gd, sizeof (data_generales), 1,arch);
     fclose(arch);
 }
 void crearcarro()
 {
     Carro carro [maximocarro];
     int numerocarro = carga_de_carro(carro);
     if (numerocarro >= maximocarro)
     {
         printf("Limite de vehiculos alcanzados. \n");
         return;
     }
     Carro nuevocarro;
     printf("\n===Creacion de Nuevo Vehiculo==\n");
   validacionplaca(carro,numerocarro, nuevocarro.Placa);
     printf("Marca: ");
     scanf("%s", nuevocarro.Marca);
     limpiar_buffer();
     printf("Modelo: ");
     scanf("%s", nuevocarro.Modelo);
     limpiar_buffer();
     printf("Año:  ");
     scanf("%d", &nuevocarro.año);
     limpiar_buffer();
     printf(" Tipo de Motor (A,B,C,D): ");
     scanf("%c",&nuevocarro.motor);
     limpiar_buffer();
     printf("Tipo de Combustible (Gasolina/Gasoil): ");
     scanf("%s",nuevocarro.tipo_de_combustible);
     limpiar_buffer();
     printf("Km por galon en Carretera:  ");
     scanf("%f", &nuevocarro.km_por_gl_max_carrectera);
     limpiar_buffer();
     printf("Km por galon cuidad:  ");
     scanf("%f", &nuevocarro.km_por_gl_min_cuidad);
     limpiar_buffer();
     printf("Costo de seguro (Anualmente):  ");
     scanf("%f", &nuevocarro.costo_de_seguro);
     limpiar_buffer();
     printf("Km de Gomas: ");
     scanf("%d", &nuevocarro.km_gomas);
     limpiar_buffer();
     printf("Costo de Gomas: ");
     scanf("%f",&nuevocarro.costo_de_gomas);
     limpiar_buffer();
     printf("Costo de Mantenimiento:  ");
     scanf("%f", &nuevocarro.costo_de_mantenimiento);
     limpiar_buffer();
     printf("Km de Mantenimiento:  ");
     scanf("%d", &nuevocarro.kilometro_matenimiento);
     limpiar_buffer();
     printf("Costo del Vehiculo:  ");
     scanf("%f", &nuevocarro.costo_del_vehiculo);
     limpiar_buffer();
     printf("Vida Util (años):  ");
     scanf("%d",&nuevocarro.vida_util);
     limpiar_buffer();
     printf("Depreciacion anualmente:  ");
     scanf("%f", &nuevocarro.depresiacion);
     limpiar_buffer();
     printf("Km por año promedio:  ");
     scanf("%d", &nuevocarro.kilometros_por_ano_promedio);
     limpiar_buffer();
     carro[numerocarro] = nuevocarro;
     guarda_carro_archivo(carro,numerocarro + 1);
     printf("\n Vehiculo creado existosamente");


 }

 int borrarcarro()
 {
     Carro carro[maximocarro];
     int numerocarro = carga_de_carro(carro);
     char placaborrar[8];
     lista_carros();
     printf("\n====Borrar Vehiculo=====\n");
     printf("Ingrese la placa del Vehiculo a Borrar: ");
     scanf("%s",placaborrar);
     limpiar_buffer();
     int lista = buscarplaca(carro,numerocarro,placaborrar);
     if (lista != -1 )  {
         for (int y = lista; y <numerocarro -1; y++){
            carro[y] = carro[y+1];
         }
         guarda_carro_archivo(carro,numerocarro - 1);
         printf("Vehiculo con placa %s borrado existosamente.\n",placaborrar);
         return 1;
     }
     else {
        printf("No se encuetra ningun vehiculo con placa %s.\n", placaborrar);
        return 0;
     }

 }
 void modificarcarro()
  {Carro carro[maximocarro];
     int nuemrocarro = carga_de_carro(carro);
     char placamodificar [8];
     lista_carros();
     printf("\n==Modificar Vehiculo==\n");
     printf("Ingrese la placa del Vehiculo a modificar: ");
     scanf("%s", placamodificar);
     limpiar_buffer();
     int lista = buscarplaca(carro,nuemrocarro,placamodificar);
     if (lista !=-1)
   {
    int opcion;
    do{
        printf("\nVehiculo  enecontrado. Seleccione el campo a modificar:\n");
        printf("1. Marca: %s\n", carro[lista].Marca);
        printf("2. Modelo: %s\n", carro[lista].Modelo);
        printf("3. Año: %d\n", carro[lista].año);
        printf("4. Tipo de Motor: %c\n", carro[lista].motor);
        printf("5. Tipo de Combustible: %s\n", carro[lista].tipo_de_combustible);
        printf("6.Km de Gomas: %d\n",carro[lista].km_gomas);
        printf("7. Costo de Gomas: %.2f\n", carro[lista].costo_de_gomas);
        printf("8. Km por Galon en Carretera: %.2f\n",carro[lista].km_por_gl_max_carrectera);
        printf("9. Km por Galon en Cuidad: %.2f\n", carro[lista].km_por_gl_min_cuidad);
        printf("10. Costo del seguro anual: %.2f\n",carro[lista].costo_de_seguro);
        printf("11.Kilometros para Mantenimiento: %d\n", carro[lista].kilometro_matenimiento);
        printf("12. Precio de Mantenimiento: %.2f\n", carro[lista].costo_de_mantenimiento);
        printf("13. Precio del Vehiculo: %.2f\n", carro[lista].costo_del_vehiculo);
        printf("14.Vida Util (Anualmente): %d\n", carro[lista].vida_util);
        printf("15. Deprecicion anual: %.2f\n", carro[lista].depresiacion);
        printf("16. Kilometros de promedio por año: %d\n ", carro[lista].kilometros_por_ano_promedio);
        printf("0. Guardar cambios y salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        limpiar_buffer();


        switch(opcion){
    case 1:
        printf("Nueva Marca: ");
        scanf("%s",carro[lista].Marca);
        limpiar_buffer();
        break;
    case 2:
        printf("Nuevo Modelo: ");
        scanf("%s", carro[lista].Modelo);
        limpiar_buffer();
        break;

    case 3:
        printf("Nuevo Año: ");
        scanf("%d", &carro[lista].año);
        limpiar_buffer();
        break;

    case 4:
        printf("Nuevo Tipo de Motor:  ");
        scanf("%c", &carro[lista].motor);
        limpiar_buffer();
        break;

    case 5:
        printf("Nuevo Tipo de Combustible (Gasolina/Gasoil): ");
        scanf("%s", carro[lista].tipo_de_combustible);
        limpiar_buffer();
        break;
    case 6:
        printf("Nuevos Km de Gomas: ");
        scanf("%d", &carro[lista].km_gomas);
        limpiar_buffer();
        break;

    case 7:
        printf("Nuevo Costo de Gomas: ");
        scanf("%f", &carro[lista].costo_de_gomas);
        limpiar_buffer();
        break;
    case 8:
        printf("Nuevos Km por Galon en Carretera: ");
        scanf("%f", &carro[lista].km_por_gl_max_carrectera);
        limpiar_buffer();
        break;

    case 9:
        printf("Nuevos Km por Galon en Cuidad: ");
        scanf("%f", &carro[lista].km_por_gl_min_cuidad);
        limpiar_buffer();
        break;

    case 10:
        printf("Nuevos Costo de Seguro Anual: ");
        scanf("%f", &carro[lista].costo_de_seguro );
        limpiar_buffer();
        break;

    case 11:
        printf("Nuevos Km de Manteniemiento: ");
        scanf("%d", &carro[lista].kilometro_matenimiento);
        limpiar_buffer();
        break;

    case 12:
        printf("Nuevo Precio de Mantenimiento: ");
        scanf("%f", &carro[lista].costo_de_mantenimiento);
        limpiar_buffer();
        break;

    case 13:
        printf("Nuevo Precio del Vehiculo: ");
        scanf("%f", &carro[lista].costo_del_vehiculo);
        limpiar_buffer();
        break;

    case 14:
        printf("Nuevo Vida Util (años): ");
        scanf("%d", &carro[lista].vida_util );
        limpiar_buffer();
        break;

    case 15:
        printf("Nueva Deprecicion anualmente: ");
        scanf("%f", &carro[lista].depresiacion);
        limpiar_buffer();
        break;

    case 16:
        printf("Nuevos km Promedio por año:");
        scanf("%d", &carro[lista].kilometros_por_ano_promedio);
        limpiar_buffer();
        break;

    case 0:
        printf("Guardando cambios.....\n");
        break;

    default:
        printf("Opcion invalida. Intente de nuevo.\n");
        }
        if (opcion !=0){
            printf("\nCambios realizados. ¿Desea realizar otra modificacion a otro campo?\n");

        }
    }while (opcion !=0);
    guarda_carro_archivo(carro, nuemrocarro);
    printf("Vehiculo modificado Corretamente.\n");

     }
     else {
        printf("No se encotro ningun vehiculo con esa placa");
     }
 }
 void lista_carros()
 {
     Carro carro[maximocarro];
     int numerocarros = carga_de_carro(carro);
     if (numerocarros == 0)
     {
         printf("\n No hay Vehiculos disponibles.\n");
         return;
     }
     printf("\n=====Lista de Vehiculos=====\n");
     for(int y =0; y < numerocarros; y++)
     {
       printf("Carro %d: Placa: %s | Marca: %s | Modelo: %s | Motor %c\n",
              y +1, carro[y].Placa, carro[y].Marca, carro[y].Modelo, carro[y].motor);
     }

 }

 void modificacion_generales()
 {
     data_generales gd;
     printf("\n======= Actualizacion de los  Datos Generales (Combustibles - Precios )==\n");
     printf("Introduzca el precio actual de la Gasolina: ");
     scanf("%f", &gd.precio_gasolina);
     limpiar_buffer();
     printf("Introduzca el precio actual del gasoil:");
     scanf("%f", &gd.precio_disel);
     limpiar_buffer();
     guardardatagenera(&gd);
     printf("Precios actualizados Correctamente\n");
 }
 void calcularviaje()
 {
     Carro carro[maximocarro];
     int numero = carga_de_carro(carro);
     data_generales gd;
     cargardatagenera(&gd);
     char placa_seleccionada[8];
     float km_viaje, porcentaje_cuidad;
     int lista_carro;
     if (numero == 0 )
     {
         printf("\n No hay carros registrados, Para hacer calculos de viaje. Registre uno primero.\n");
         return;
     }
     lista_carros();
     printf("Ingrese la Placa de su vehiculo para el viaje:  ");
     scanf("%s", placa_seleccionada);
     limpiar_buffer();

    lista_carro = buscarplaca(carro,numero,placa_seleccionada);
     if(lista_carro == -1)
{
    printf("Vehiculo no encontrado.\n ");
    return;
}
printf("Ingrese los kilometros totales del viaje: ");
scanf("%f", &km_viaje);
limpiar_buffer();
printf("Ingrese el porcentaje de kilometros en cuidad (0-100):");
scanf("%f", &porcentaje_cuidad);
float km_cuidad= km_viaje *(porcentaje_cuidad / 100.0);
float km_carrectera = km_viaje - km_cuidad;
float precio_seguro = carro[lista_carro].costo_de_seguro/carro[lista_carro].kilometros_por_ano_promedio;
float precio_gomas = (float)carro[lista_carro].costo_de_gomas/carro[lista_carro].km_gomas;
float precio_mantenimiento = carro[lista_carro].costo_de_mantenimiento / (float)carro[lista_carro].kilometro_matenimiento;
float precio_depreciacion = carro[lista_carro].depresiacion / carro[lista_carro].kilometros_por_ano_promedio;
float galones_en_carretera = km_carrectera / carro[lista_carro].km_por_gl_max_carrectera;
float galones_en_cuidad = km_cuidad /carro[lista_carro].km_por_gl_min_cuidad;
float costo_combustible_x_galon = (strcmp(carro[lista_carro].tipo_de_combustible,"Gasolina") == 0) ?  gd.precio_gasolina : gd.precio_disel;
float costo_combsutible_viaje = (galones_en_carretera + galones_en_cuidad) * costo_combustible_x_galon;
float costo_gomas_viaje = precio_gomas * km_viaje;
float costo_seguro_viaje = precio_seguro * km_viaje;
float costo_mantenimiento_viaje = precio_mantenimiento * km_viaje;
float costo_deprecicion_viaje = precio_depreciacion * km_viaje;
float costo_total_viaje =  costo_gomas_viaje + costo_combsutible_viaje + costo_seguro_viaje + costo_deprecicion_viaje +costo_mantenimiento_viaje;
float costo_por_km = costo_total_viaje /km_viaje ;


printf("\n=====Calculo del Viaje=====\n");
printf("||Vehiculo:  %s %s (%s)", carro[lista_carro].Marca, carro[lista_carro].Modelo,carro[lista_carro].Placa);
printf("||Kilometraje total del viaje: %.2f km\n",km_viaje);
printf("||Porcentaje en cuidad: %.2f%%\n", porcentaje_cuidad);
printf("                                                                     ");
printf("\n||=====Desglose del Viaje=====\n");
printf("||Gasto de Seguro: %.2f\n", costo_seguro_viaje);
printf("||Gasto  de Mantenimiento; %.2f\n",costo_mantenimiento_viaje);
printf("||Gasto de Gomas: %.2f \n", costo_gomas_viaje);
printf("||Gasto de Combustible: %.2f\n", costo_combsutible_viaje );
printf("||Gasto  de Depreciación: %.2f\n", costo_deprecicion_viaje);
printf("||Gasto x kilometro: %.2f\n", costo_por_km);
printf("||Gasto Total del Viaje: %.2f\n", costo_total_viaje);
 }

void menu_principal(int numero_del_nivel)
{
    int opc;
    if(numero_del_nivel == 1)
    {
    printf("\n======Sistema de Administracion de Gastos de Vehiculo x KM=====\n");
    printf("||1. Administracion de los Vehiculos\n");
    printf("||2. Administracion de los Datos Genericos\n");
    printf("||3. Calculo del Viaje\n");
    printf("||4. Salir\n");
    printf("====================================================\n");
    printf("Ingrese una Opcion Valida: ");
    scanf("%d", &opc);
    limpiar_buffer();
    switch (opc)
    {
    case 1:
        menu_principal(2);
        break;
    case 2:
        modificacion_generales();
        menu_principal(1);
        break;
    case 3:
        calcularviaje();
        menu_principal(1);
        break;
    case 4:
        printf("Fin del Programa......\n");
        exit(0);
        break;

    default:
        printf("Opcion no valida. Reintente otra vez.\n");
        menu_principal(1);
        break;
    }
}
    else if (numero_del_nivel == 2){
        printf("\n========== Administrador  de Carros =====\n");
        printf("|| 1. Crear Vehiculo\n");
        printf("|| 2. Borrar Vehiculos\n");
        printf("|| 3. Modificar Vehiculo\n");
        printf("|| 4. Lista de Vehiculos.\n");
        printf("|| 5.Volver al Menu Principal\n");
        printf("|| 6. Salir\n");
        printf("Ingrese una opcion para ejecuciòn: ");
        scanf("%d", &opc);
        limpiar_buffer();
        switch (opc)
        {
        case 1:
            crearcarro();
            break;
        case 2:
            borrarcarro();
            break;
        case 3:
            modificarcarro();
            break;
        case 4 :
           lista_carros();
           break;
        case 5:
            menu_principal(1);
            return;
         case 6:
             printf("Fin del Programa..........\n");
             exit(0);

        default:
            printf("Opción Invalida\n");
        }
    }menu_principal(2);

    }


int main()
{
menu_principal(1);
return 0;
}








