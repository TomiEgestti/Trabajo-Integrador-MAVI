#include "Jugador.h"

Jugador::Jugador() {
	crosstex.loadFromFile("cross.png");
	crossprite.setTexture(crosstex);
	crossprite.setOrigin(crosstex.getSize().x / 2.0f, crosstex.getSize().y / 2.0f);
	crossprite.setScale(0.1, 0.1);
}

void Jugador::dibujar(RenderWindow* wind) {
	wind->draw(crossprite);
}

void Jugador::posicion(float x, float y) {
	crossprite.setPosition(x, y);
}

Vector2f Jugador::dondeesta() {
	return crossprite.getPosition();
}
