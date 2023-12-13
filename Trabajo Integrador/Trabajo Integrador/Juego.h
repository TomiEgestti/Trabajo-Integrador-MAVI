#pragma once
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp> 
#include "Jugador.h"
#include "Enemigos.h"
#include "Inocentes.h"
using namespace sf;

class Juego
{
	RenderWindow* wind;
	Jugador* player;
	Texture imagen;
	Sprite fondo;	
	Font fuente;
	Clock reloj;
	std::unique_ptr<Enemigos> enemigoActual;
	std::unique_ptr<Inocentes> inocenteActual;
	Text texto1, texto2;
	Text enemigosmatados, contador;
	Text gameover, ganaste, press;
	int vidas, derrotados;


public:

	Juego();
	~Juego();
	Vector2f posiciones(int num);
	void loop();
	void eventos();
	void actualizar();
	void dibujar();
	void disparar();
	void actualizarvidas();
	void ponerenpant();
	void pierde();
	void gana();
};

