#include <iostream>
#include <string>

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
void MenuJuego();

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
    Jugadores *jugadores[JugadoresMax] = {nullptr}; //Cambio para que aun no apunte a nada
    int a;

    do
    {
    MenuInterativo();
    std::cout << "-";
    std::cin >> a;

    switch (a)
    {
    case 1: {
        RegistrarJugadores(jugadores);
        JugadoresRegistrados(jugadores);
        MenuJuego();
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
} while (a != 4 && a != 1);

// Liberar memoria de los jugadores
 for (int i = 0; i < JugadoresMax; i++) {
        delete jugadores[i];
    }

return 0;
}

void MenuJuego(){
    int opcion = 0;
std :: cout << "--------Apuestas--------\n";
std :: cout << "> 1.... Pleno\n";
std :: cout << "> 2.... Dividida\n";
std :: cout << "> 3.... Calle\n";
std :: cout << "> 4.... Esquina\n";
std :: cout << "> 5.... Linea\n";
std :: cout << "> 6.... Rojo o Negro\n";
std :: cout << "> 7.... Par o impar\n";
std :: cout << "> 8.... Mitades\n";
std :: cout << "> 9.... Docenas\n";
std:: cout << "Seleccione una opcion: ";
std::cin >> opcion;
switch (opcion)
{
case 1:
    
    break;
case 2:

    break;
case 3:

    break;
case 4:

    break;
case 5:

    break;
case 6:

    break;
case 7:

    break;
case 8:

    break;
case 9:

    break;

default:
    break;
}
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

    for (int i = 0; i <+ JugadoresMax && jugadores[i] != nullptr; i++) //Para que el bucle for verifique que haya un jugador registrado. 
    {
        const char* color = colores[i % 6];  
        std::cout << color;  // Aplicar el color
        std::cout << jugadores[i]->nombre_jugador << " saldo: $" << jugadores[i]->monedero << "\n"  << "\033[0m\n"; ;
    
    }
    std::cout << '\n';
}
