import pygame
from random import randint
import math

pygame.init()

pantalla = pygame.display.set_mode( (800, 600) )

#* Carga de imagenes
icono = pygame.image.load("rocket.png")
jugador = pygame.image.load("rocket_prota.png")

space = pygame.image.load("space.jpg")
laser = pygame.image.load("laser.png")

# Inicialización de jugador
jugador_x = 368
jugador_y = 536
jugador_cambio_x = 0

# inicialización del alien
numero_enemigos = 7

alien = []
alien_x = []
alien_y = []
alien_cambio_y = []
alien_cambio_x = []

for i in range(numero_enemigos):
    alien.append(pygame.image.load("alien.png"))
    alien_x.append(randint(0, 736))
    alien_y.append(randint(0, 364))
    alien_cambio_x.append(0.3)
    alien_cambio_y.append(40)



# Configuracion del laser
laser_x = 0
laser_y = 500
laser_cambio_y = 0.5
laser_visible = False

def disparo_laser(x, y):
    global laser_visible
    laser_visible = True
    pantalla.blit(laser, (x,y))

pygame.display.set_caption("Invasión Alien")
pygame.display.set_icon(icono)

def jugador_pos(x, y):
    pantalla.blit(jugador, (x, y))
    
def alien_pos (x, y, i):
    pantalla.blit(alien[i], (x, y))

#* Funciones Generales
def esta_en_colision(x1, y1, x2, y2): 
    distancia = math.sqrt( math.pow((x2 - x1), 2) + math.pow( (y2 - y1), 2) )
    if distancia < 30:
        return True
    else:
        return False

#* Main Game Loop
ejecutando = True
while ejecutando:
    pantalla.blit(space, (0,0))
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            ejecutando = False
        if evento.type == pygame.KEYDOWN:
            if evento.key == pygame.K_LEFT:
                jugador_cambio_x = -0.2
            if evento.key == pygame.K_RIGHT:
                jugador_cambio_x = 0.2
            if evento.key == pygame.K_SPACE:
                if not laser_visible:
                    laser_x = jugador_x + 5
                disparo_laser(laser_x, laser_y)
        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT or evento.key == pygame.K_RIGHT:
                jugador_cambio_x = 0
    jugador_x += jugador_cambio_x 
    if jugador_x < 0:
        jugador_x = 0
    if jugador_x > 736:
        jugador_x = 736
    jugador_pos(jugador_x, jugador_y)
    
    # Actualización del Alien
    for i in range(numero_enemigos):
        alien_x[i] += alien_cambio_x[i]
        if alien_x[i] < 0:
            alien_cambio_x[i] = 0.3
            alien_y[i] += alien_cambio_y[i]
        if alien_x[i] > 736:
            alien_cambio_x[i] = -0.3
            alien_y[i] += alien_cambio_y[i]
        alien_x[i] += alien_cambio_x[i]         # Actualzamos individualemete la posición
        # Colisiones
        # Movemos el chequeo de colisiones al for para un chequeo individual
        if esta_en_colision(alien_x[i],alien_y[i], laser_x, laser_y):
            laser_y = 500
            laser_visible = False
            alien_x[i] = randint(0,736)        # Actualizamos las coliciones a las listas
            alien_y[i] = randint(0, 300)
        alien_pos(alien_x[i], alien_y[i], i )
    
    # Actualización del laser
    if laser_visible:
        disparo_laser(laser_x, laser_y)
        laser_y -= laser_cambio_y
        
    
    
    pygame.display.update()