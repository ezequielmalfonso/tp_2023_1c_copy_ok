/*
 * memoriaUtils.c
 *
 *  Created on: 12 abr 2023
 *      Author: utnso
 */


#include "memoria_utils.h"

uint32_t puerto_escucha;
uint32_t tam_memoria;
uint32_t tam_segmento_0;
uint32_t cant_segmentos;
uint32_t retardo_memoria;
uint32_t retardo_compactacion;
char* algortimo_asignacion;

void* memoria;
t_list* tabla_de_segmentos;
t_segmento* segmento;


/*
 * Inicializacion de Estructuras administrativas de Memoria
 */

void inicializar_memoria(){

	tam_memoria 		 = configuracion->TAM_MEMORIA;
	tam_segmento_0 		 = configuracion->TAM_SEGMENTO_0;
	cant_segmentos 		 = configuracion->CANT_SEGMENTOS;
	retardo_memoria 	 = configuracion->RETARDO_MEMORIA;
	retardo_compactacion = configuracion->RETARDO_COMPACTACION;
	algortimo_asignacion = configuracion->ALGORITMO_ASIGNACION;

	// Creacion segmento 0
    segmento = malloc(sizeof(t_segmento));
    segmento->id_segmento      = 0;
    segmento->direccion_base   = 0;
    segmento->tamanio_segmento = configuracion->TAM_SEGMENTO_0;

	log_info(logger,"Algoritmo %s configurado", configuracion->ALGORITMO_ASIGNACION);
	log_info(logger,"Segmento 0 (Compartido) creado: Id: %d - Dir Base: %d - Tamanio: %d", segmento->id_segmento, segmento->direccion_base, segmento->tamanio_segmento);

	tabla_de_segmentos = list_create();
	list_add(tabla_de_segmentos, segmento);

	memoria = malloc(configuracion->TAM_MEMORIA);
	//tabla_de_paginas = list_create();


}

