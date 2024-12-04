import pygame
from random import randint

pygame.init()

pantalla = pygame.display.set_mode( (800, 600) )

#* Carga de imagenes
icono = pygame.image.load("rocket.png")
jugador = pygame.image.load("rocket_prota.png")
alien = pygame.image.load("alien.png")
space = pygame.image.load("space.jpg")
laser = pygame.image.load("laser.png")

# Inicialización de jugador
jugador_x = 368
jugador_y = 536
jugador_cambio_x = 0

# inicialización del alien
alien_x = randint(0, 736)
alien_y = randint(0, 364)
alien_cambio = 0.3
alien_cambio_y = 40

# Configuracion del laser
laser_x = 0
laser_y = 0

pygame.display.set_caption("Invasión Alien")
pygame.display.set_icon(icono)

def jugador_pos(x, y):
    pantalla.blit(jugador, (x, y))
    
def alien_pos(x, y):
    pantalla.blit(alien, (x, y))


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
        if evento.type == pygame.KEYUP:
            if evento.key == pygame.K_LEFT or evento.key == pygame.K_RIGHT:
                jugador_cambio_x = 0
    jugador_x += jugador_cambio_x 
    if jugador_x < 0:
        jugador_x = 0
    if jugador_x > 736:
        jugador_x = 736
    jugador_pos(jugador_x, jugador_y)
    alien_x += alien_cambio
    if alien_x < 0:
        alien_cambio = 0.3
        alien_y += alien_cambio_y
    if alien_x > 736:
        alien_cambio = -0.3
        alien_y += alien_cambio_y
    alien_pos(alien_x, alien_y)
    pygame.display.update()