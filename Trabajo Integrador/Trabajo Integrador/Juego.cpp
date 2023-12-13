#include "Juego.h"

Juego::Juego() {
	wind = new RenderWindow(VideoMode(800, 600), "Bang!");
	player = new Jugador();
	std::vector<Enemigos> enemigos;
	std::vector<Inocentes> inocentes;
	wind->setMouseCursorVisible(false);
	imagen.loadFromFile("fondo.png");
	fondo.setTexture(imagen);
	fondo.setScale(0.8, 0.8);
	vidas = 3;
	derrotados = 0;
	fuente.loadFromFile("Roboto.ttf");
	texto1.setFont(fuente);
	texto2.setFont(fuente);
	enemigosmatados.setFont(fuente);
	contador.setFont(fuente);
	texto1.setString("Vidas: ");
	texto1.setPosition(60, 480);
	texto2.setPosition(150, 480);
	enemigosmatados.setString("Enemigos vencidos: ");
	enemigosmatados.setPosition(60, 520);
	contador.setPosition(330, 520);
}

void Juego::loop() {
	Clock reloj;
	Time tiempotransc;
	while ((wind->isOpen()) && (vidas > 0) && (derrotados < 10)) {
		eventos();
		actualizar();
		dibujar();
	}
	if (vidas == 0) {
		pierde();
	}
	else {
		gana();
	}
}

Vector2f Juego::posiciones(int num) {
	Vector2f* posiciones;
	posiciones = new Vector2f[6];
	posiciones[0].x = 100; posiciones[0].y = 100;
	posiciones[1].x = 100; posiciones[1].y = 240;
	posiciones[2].x = 500; posiciones[2].y = 300;
	posiciones[3].x = 300; posiciones[3].y = 200;
	posiciones[4].x = 520; posiciones[4].y = 110;
	posiciones[5].x = 530; posiciones[5].y = 200;
	return posiciones[num];
}

void Juego::ponerenpant() {
	if (enemigoActual || inocenteActual) {
		if (enemigoActual && enemigoActual->estavivo()) {
			enemigoActual->derribar();
			vidas--;
		}else if (inocenteActual && inocenteActual->estavivo()) {
			inocenteActual->derribar();
		}

		enemigoActual = nullptr;
		inocenteActual = nullptr;
	}
	if (rand() % 2 == 1) {
		enemigoActual = std::make_unique<Enemigos>();
	}
	else {
	    inocenteActual = std::make_unique<Inocentes>();
	}
	int randpos = rand() % 6;
	if (enemigoActual) {
		enemigoActual->setpos(posiciones(randpos));
	}
	else {
		inocenteActual->setpos(posiciones(randpos));
	}
}


void Juego::actualizar() {
	Vector2i mousepos = Mouse::getPosition(*wind);
	player->posicion(mousepos.x, mousepos.y);
	actualizarvidas();
	if (reloj.getElapsedTime().asSeconds() >= 1.0) {
		ponerenpant();
		reloj.restart();
	}
	
}

void Juego::eventos() {
	Event eve;
	while (wind->pollEvent(eve)) {
		switch (eve.type) {
		case Event::Closed:
			wind->close();
			break;

		case Event::MouseButtonPressed:
			if (eve.mouseButton.button == Mouse::Button::Left) {
				disparar();
				break;
			}
		}
	}
}

void Juego::dibujar(){
	wind->clear();
	wind->draw(fondo);
	wind->draw(texto1);
	wind->draw(texto2);
	wind->draw(enemigosmatados);
	wind->draw(contador);
	if (enemigoActual) {
		enemigoActual->dibujar(wind);
	}else if (inocenteActual) {
		inocenteActual->dibujar(wind);
	}
	player->dibujar(wind);
	wind->display();
}

void Juego::disparar() {
	Vector2f posijug = player->dondeesta();

	if (enemigoActual && enemigoActual->encima(posijug.x, posijug.y)) {
		enemigoActual->recibirdisparo();
		enemigoActual = nullptr;
		derrotados++;
	}
	else if (inocenteActual && inocenteActual->encima(posijug.x, posijug.y)) {
		inocenteActual->recibirdisparo();
		inocenteActual = nullptr;
		vidas--;
	}
};

void Juego::actualizarvidas() {
	char vid[3];
	_itoa_s(vidas, vid, 10);
	texto2.setString(vid);

	char enem[100];
	_itoa_s(derrotados, enem, 10);
	contador.setString(enem);
}

void Juego::pierde() {
	gameover.setFont(fuente);
	press.setFont(fuente);
	gameover.setString("Game Over");
	press.setString("Presione una tecla para cerrar");
	press.setPosition(200, 330);
	gameover.setPosition(320, 230);
	wind->clear();
	wind->draw(gameover);
	wind->draw(press);
	wind->display();
	Event eve;
	while (true) {
		while (wind->pollEvent(eve)) {
  			if (eve.type == sf::Event::Closed) {
				wind->close();
			}
			else if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Space) {
				wind->close();
				return; 
			}
		}
	}
}

void Juego::gana() {
	ganaste.setFont(fuente);
	ganaste.setString("Ganaste!");
	press.setFont(fuente);
	press.setString("Presione una tecla para cerrar");
	press.setPosition(200, 330);
	ganaste.setPosition(320, 230);
	wind->clear();
	wind->draw(ganaste);
	wind->draw(press);
	wind->display();
	Event eve;
	while (true) {
		while (wind->pollEvent(eve)) {
			if (eve.type == sf::Event::Closed) {
				wind->close();
			}
			else if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Space) {
				wind->close();
				return;
			}
		}
	}
}

Juego::~Juego() {
	delete wind;
	delete player;
}