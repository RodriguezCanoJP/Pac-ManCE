#include <SFML/Graphics.hpp>

class Jugador{
protected:
    int health;
    sf::Texture texture; ///< textura del sprite
    sf::Sprite sprite; ///< objeto sprite
    int x; ///< posicion en el eje x
    int y; ///< posicion en el eje y
    int direction;

public:

    ///Constructor/Destructor
    Jugador();
    ~Jugador();

    /**
     * Actualiza la posicion de la nave del jugador
     * @param up cantidad de movimiento hacia arriba
     * @param down cantidad de movimiento hacia abajo
     */
    void update(int vel);

    /**
     * Retorna la posicion del jugador en el eje x
     * @return int x
     */
    int getX();

    /**
     * diminuye la vida del jugador
     */
    void getHit();

    /**
     * retorna un valor booleano que indica si la vida del jugador es igual o menor a cero
     * @return bool
     */
    bool isDead();

    /**
     * Retorna la posicion del jugador en el eje y
     * @return int y
     */
    int getY();

    /**
     * Retorna el sprite del objeto de jugador
     * @return Sprite sprite
     */
    void setSprite(int x, int y);

    sf::Sprite getSprite(); //retorna el sprite del jugador

};