#include "Enemigos.h"

Enemigos::Enemigos() {
	marciano.loadFromFile("enemigo.png");
	enemy.setTexture(marciano);
	enemy.setScale((0.4f / 2), (0.4f / 2));
	vive = true;
	visible = false;
	tiempovis = 3;
}

bool Enemigos::estavivo() {
	return vive;
}

void Enemigos::vivos(bool valor) {
	vive = valor;
}

void Enemigos::recibirdisparo() {
	derribar();
}

bool Enemigos::encima(float x, float y) {
	FloatRect bounds = enemy.getGlobalBounds();
	return bounds.contains(x, y);
}

void Enemigos::derribar() {
	vive = false;
}

void Enemigos::dibujar(RenderWindow* wind) {
	if (vive) {
		wind->draw(enemy);
	}
}

int Enemigos::randompos() {
	int random = rand() % 6;
	return random;
}


bool Enemigos::aparece() {
	visible = true;
	return visible;
}

bool Enemigos::desaparece() {
	visible = false;
	return visible;
}

void Enemigos::setpos(Vector2f pos) {
	enemy.setPosition(pos.x, pos.y);
}

