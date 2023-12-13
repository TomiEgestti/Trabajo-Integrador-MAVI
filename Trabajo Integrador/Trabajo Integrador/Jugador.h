#pragma once
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp> 
using namespace sf;

class Jugador
{
		Texture crosstex;
		Sprite crossprite;

	public:

		Jugador();
		void dibujar(RenderWindow* wind);
		void posicion(float x, float y);
		Vector2f dondeesta();
	};

