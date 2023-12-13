#pragma once
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp> 
#include "Enemigos.h"
using namespace sf;

class Inocentes: public Enemigos
{
	Texture imag;
	Sprite inocente;

public:

	Inocentes();
	void dibujar(RenderWindow* wind);
	bool encima(float x, float y);
	void setpos(Vector2f pos);
	void recibirdisparo();
};

