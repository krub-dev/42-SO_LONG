<h1 align="center">
  <img src="https://iili.io/2mYDEmu.png" alt="so long header krub" width="1200" height="auto" style="align: bottom;"> 
</h1>

## Descripción

Proyecto que tiene como objetivo crear un juego 2D utilizando la librería **MLX42**. Se debe diseñar un sistema en el que el jugador pueda moverse por un mapa, recolectar objetos y llegar a la salida cumpliendo ciertas condiciones.

🇬🇧 [Read in English](README_EN.md)

<img alt="krub wannabe icon" src="https://iili.io/2maloV1.png">

## Estructura del Proyecto

### Makefile

- Reglas: `all`, `clean`, `fclean`, `re`.
- No debe relinkear los archivos en ningún caso.

## Archivos de Funciones

- `so_long.c`: Función principal del programa.
- `level.c`: Manejo del mapa y sus características.
- `check_level.c`: Validación del nivel, asegurando que cumple las reglas.
- `check_path.c`: Implementación de **Flood Fill** para verificar si hay un camino válido.
- `game.c`: Inicialización del juego y manejo del bucle principal.
- `game_utils.c`: Funciones auxiliares relacionadas con la configuración de pantalla.
- `displayPlayer.c`: Carga y renderizado del sprite del jugador.
- `displayEnv.c`: Renderizado del fondo y los bordes del mapa.
- `displayCollectibles.c`: Manejo y visualización de los objetos coleccionables.
- `displayExit.c`: Manejo y visualización de la salida.
- `playerController.c`: Control del personaje, detección de entradas del usuario.
- `interactions.c`: Detección de colisiones y validación de movimientos.
- `error_exit_free.c`: Manejo de errores y liberación de memoria.

## Reglas del Juego

- El jugador debe recolectar todos los objetos (`C`) para poder salir (`E`).
- Movimiento con **WASD** o teclas de dirección.
- No se pueden atravesar paredes (`1`).
- El número de movimientos se muestra en la terminal y en pantalla para el bonus.

## Librerías y Funciones Permitidas

- **Funciones autorizadas**: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`.
- **MiniLibX/MLX42**: Uso obligatorio para gráficos y renderizado.
- **Libft**: Permitida para funciones auxiliares.
- **Math Library (-lm)**: Permitida.

## Algoritmo de Validación del Mapa

Se usa el algoritmo **Flood Fill/DFS** para verificar que el jugador pueda alcanzar la salida recogiendo todos los coleccionables. Utiliza recursividad. Este método garantiza que el nivel sea jugable antes de iniciar el juego.

## Bonus

- Implementación de enemigos/trampas que pueden hacer perder al jugador.
- Animaciones de sprites para mejorar la experiencia visual.
- Mostrar el contador de movimientos en pantalla en lugar de la terminal.

<img alt="krub wannabe screenshot game" src="https://iili.io/2maY6bI.png">

## Consideraciones Finales

Este proyecto ha sido una gran introducción al desarrollo de videojuegos en 2D. Además de aplicar **MLX42**, se ha trabajado en la validación de mapas, la optimización de gráficos y la interacción con el usuario.

Se ha priorizado el diseño antes de la implementación, permitiendo un desarrollo más estructurado y eficiente. También he tenido que ajustar las espectativas a los tiempos, al deadline. En el futuro, es posible que el proyecto evolucione o se adapte a otros motores gráficos como **Godot** o **Unity**.
