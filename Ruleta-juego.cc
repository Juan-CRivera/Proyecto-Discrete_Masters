#include <iostream>

const int JugadoresMax = 6;


struct Jugadores
{
    std::string nombre_jugador;
    float monedero;
    int JugadoresActuales = 0;
};

// Declaración de funciones
void MenuInterativo();
void RegistrarJugadores(Jugadores *jugadores[]);
void JugadoresRegistrados(Jugadores *jugadores[]);

// Colores ANSI para los jugadores
const char* colores[] =
 {
    "\033[31m",  // Rojo
    "\033[32m",  // Verde
    "\033[33m",  // Amarillo (Dorado)
    "\033[34m",  // Azul
    "\033[35m",  // Magenta
    "\033[36m"   // Cian
};

int main() {
    Jugadores *jugadores[JugadoresMax];

    MenuInterativo();
    int a;
    std::cout << "-";
    std::cin >> a;

    switch (a)
    {
    case 1: {
        RegistrarJugadores(jugadores);
        JugadoresRegistrados(jugadores);
        break;
    }
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    return 0;
}

void MenuInterativo()
{
    std::cout << "\n";
    std::cout << "\033[33m\033[1m > 1.....Iniciar juego \033[0m\n";  
    std::cout << "\033[32m\033[1m > 2.....Ver fondos de la cartera \033[0m\n"; 
    std::cout << "\033[34m\033[1m > 3.....Historial de las apuestas y resultados \033[0m\n";  
    std::cout << "\033[31m\033[1m > 4.....Salir \033[0m\n";  
}

void RegistrarJugadores(Jugadores *jugadores[]) {
    int a;

    do {
        std::cout << "Ingresa la cantidad de jugadores que desean jugar (maximo " << JugadoresMax << "): ";
        std::cin >> a;
        std::cin.ignore(); 

        if (a > JugadoresMax) {
            std::cout << "Solo se pueden registrar " << JugadoresMax << " jugadores. Intentalo de nuevo.\n";
        }
    } while (a > JugadoresMax); 

    std::cout << '\n';

    for (int i = 0; i < a; i++) {
        jugadores[i] = new Jugadores;
        std::cout << "Jugador " << i + 1 << "\n";
        std::cout << "Nombre del jugador: ";
        std::getline(std::cin, jugadores[i]->nombre_jugador); 
        std::cout << "Monedero inicial: $";
        std::cin >> jugadores[i]->monedero;
        std::cin.ignore(); 
        std::cout << "\n";
        jugadores[i]->JugadoresActuales++;
    }
}

void JugadoresRegistrados(Jugadores *jugadores[]) {
    std::cout << '\n';
    std::cout << "Lista de jugadores registrados:\n\n";

    for (int i = 0; i <+ JugadoresMax; i++) {
      
        const char* color = colores[i % 6];  
        std::cout << color;  // Aplicar el color
        std::cout << jugadores[i]->nombre_jugador << " saldo: $" << jugadores[i]->monedero << "\n"  << "\033[0m\n"; ;
    
    }
    std::cout << '\n';
}
