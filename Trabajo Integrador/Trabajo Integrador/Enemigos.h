#pragma once
#include <SFML/Window.hpp>  
#include <SFML/Graphics.hpp> 
using namespace sf;

class Enemigos
{
protected:

	Texture marciano;
	Sprite enemy;
	bool vive;
	bool visible;
	Clock reloj;
	float tiempovis;

public:

	Enemigos();
	void vivos(bool valor);
	bool aparece();
	bool desaparece();
	int randompos();
	bool estavivo();
	virtual bool encima(float x, float y);
	void derribar();
	virtual void recibirdisparo();
	virtual void dibujar(RenderWindow* wind);
	virtual void setpos(Vector2f pos);
};

