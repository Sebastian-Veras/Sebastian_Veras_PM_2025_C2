#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

 // LA IMAAGEN QUE VALLA  A CONVERTIR SE DEBE DE LLAMAR "imagen" PARA QUE EL ARGUMENTO SEA VALIDO Y DEBE SER DE TIPO JPG O JPEG//

 char* entrada_de_archivo (const char* ruta_entrada){
 static char ruta_salida[570];
 char nombre_arch[256];
 char* nombre_primario_arch = strrchr(ruta_entrada, '/');

 if(!nombre_primario_arch) {
    nombre_primario_arch = strrchr(ruta_entrada, '//');
 }

 if (nombre_primario_arch) {
    strncpy(nombre_arch, nombre_primario_arch + 1, sizeof (nombre_arch) -1);
 }else {
 strncpy(nombre_arch, ruta_entrada, sizeof(nombre_arch) -1);
 }
 nombre_arch[sizeof(nombre_arch) - 1] = '\0';

char* dot = strrchr(nombre_arch, '.');
 if(dot &&  dot != nombre_arch){
    size_t log_base = dot - nombre_arch;
    strncpy(ruta_salida, nombre_arch, log_base);
    ruta_salida[log_base] = '\0';
    strcat(ruta_salida, "convertira_gris.jpg");
 }
 else{
    snprintf(ruta_salida, sizeof(ruta_salida), "%s_convertira_gris.jpg", nombre_arch);
 }
 return ruta_salida;
 }
 int main(int argc, char *argv[])
 {
     if (argc !=2)
     {
         fprintf(stderr, "Uso: %s <imagen.jpg>\n", argv[0]);
         return 1;
     }
     FILE *enarch = NULL;
     FILE *finarch = NULL;
     JSAMPARRAY entrada_fila_memoria_rgb;
     JSAMPARRAY salida_fila_memoria_gray;
     struct jpeg_decompress_struct cinfo_decompress;
     struct jpeg_compress_struct cinfo_compress;
     struct jpeg_error_mgr jerr_std_decompress;
     struct jpeg_error_mgr jerr_std_compress;
     JDIMENSION ancho, largo;
     int numero_canales;
     if ((enarch = fopen(argv[1], "rb")) ==NULL){
        fprintf(stderr, "Error: No se puede abrir el archivo de entrada '%s'\n",argv[1]);
        return 1;
     }
     cinfo_decompress.err = jpeg_std_error(&jerr_std_decompress);
     jpeg_create_decompress(&cinfo_decompress);
     jpeg_stdio_src(&cinfo_decompress, enarch);
     jpeg_read_header(&cinfo_decompress,TRUE);
     cinfo_decompress.out_color_space = JCS_RGB;
     jpeg_start_decompress(&cinfo_decompress);
     ancho = cinfo_decompress.output_width;
     largo = cinfo_decompress.output_height;
     numero_canales = cinfo_decompress.output_components;
     if(numero_canales !=3){
        fprintf(stderr, "Error: la imagen de entrada no es RGB (%d canales).\n", numero_canales);
        jpeg_destroy_decompress(&cinfo_decompress);
        fclose(enarch);
        return 1;
     }
     entrada_fila_memoria_rgb = (*cinfo_decompress.mem ->alloc_sarray)((j_common_ptr)&cinfo_decompress, JPOOL_IMAGE, ancho * numero_canales, 1);
     char* final_ruta_salida = entrada_de_archivo(argv[1]);
     printf("Procesado la imagen: %s -> %s\n", argv[1],final_ruta_salida);
     if((finarch = fopen(final_ruta_salida, "wb")) ==NULL)
     {
         fprintf(stderr, "Error: No se puede crear el archivo de salida '%s'\n", final_ruta_salida);
         jpeg_destroy_decompress(&cinfo_decompress);
         fclose(enarch);
         return 1;
     }
     cinfo_compress.err = jpeg_std_error(&jerr_std_compress);
     jpeg_create_compress(&cinfo_compress);
     jpeg_stdio_dest(&cinfo_compress, finarch);
     cinfo_compress.image_width = ancho;
     cinfo_compress.image_height = largo;
     cinfo_compress.in_color_space = JCS_GRAYSCALE;
     cinfo_compress.input_components = 1;
     jpeg_set_defaults(&cinfo_compress);
     jpeg_set_quality(&cinfo_compress,85,TRUE);
     salida_fila_memoria_gray = (*cinfo_compress.mem->alloc_sarray)((j_common_ptr)&cinfo_compress, JPOOL_IMAGE, ancho, 1);
     jpeg_start_compress(&cinfo_compress,TRUE);
     while (cinfo_decompress.output_scanline < cinfo_decompress.output_height){
        jpeg_read_scanlines(&cinfo_decompress, entrada_fila_memoria_rgb, 1);
        JSAMPROW fila_rgb = entrada_fila_memoria_rgb[0];
        JSAMPROW fila_gray = salida_fila_memoria_gray[0];
        for(JDIMENSION d = 0; d < ancho; d++)
        {
            JSAMPLE r = fila_rgb[d * 3];
            JSAMPLE g = fila_rgb[d * 3 +1];
            JSAMPLE b = fila_rgb[d * 3+2];
            unsigned int gray_val = (77 * r +150 * g + 29 * b)/ 256;
            if(gray_val > 255) gray_val = 255;
            fila_gray[d] = (JSAMPLE)gray_val;
        }
        jpeg_write_scanlines(&cinfo_compress, salida_fila_memoria_gray, 1);
     }
     jpeg_finish_decompress(&cinfo_decompress);
     jpeg_destroy_decompress(&cinfo_decompress);
     jpeg_finish_compress(&cinfo_compress);
     jpeg_destroy_compress(&cinfo_compress);
     fclose(enarch);
     fclose(finarch);
     printf("Conversion completada existosamente. La imagen fue guardada  como'%s'\n", final_ruta_salida);
     return 0;

 }
