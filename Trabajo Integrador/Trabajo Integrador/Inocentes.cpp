#include "Inocentes.h"

Inocentes::Inocentes() {
	imag.loadFromFile("inocente.png");
	inocente.setTexture(imag);
	inocente.setScale((0.4f / 2), (0.4f / 2));
	visible = false;
	vive = true;
	tiempovis = 1.5;
}

void Inocentes::dibujar(RenderWindow* wind){
	wind->draw(inocente);

}

bool Inocentes::encima(float x, float y) {
	FloatRect bounds = inocente.getGlobalBounds();
	return bounds.contains(x, y);
}

void Inocentes::setpos(Vector2f pos) {
	inocente.setPosition(pos.x, pos.y);
}

void Inocentes::recibirdisparo(){
	derribar();
}