/*#include <iostream>
#include <omp.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
//#include <Objeto.h>
//Objetos en un vector para una canasta base

int main() {
    long i = 0;
    std::ifstream archivo("D:/Descargas/pd.csv");
    std::string linea;
    char delimitador = ';';
    std::getline(archivo, linea);
    //int num_cores = omp_get_num_procs();
    int num_cores = 12;


        if(std::getline(archivo, linea))
        {
            clock_t t;
            t = clock();

#pragma omp parallel sections num_threads(num_cores)  // cuantos hilos tiene el computador del usuario
            {

#pragma omp section // crea bloques de codigo y se ejecutan en paralelo
                {
                    while(std::getline(archivo,linea))
                    {
                        /*std::stringstream stream(linea);
                        std::string created, payment_fk, store_fk, seller, category, delivery_type, sku, quantity, name, amount; //variables
                        std::getline(stream, created, delimitador);
                        std::getline(stream, payment_fk, delimitador);
                        std::getline(stream, store_fk, delimitador);
                        std::getline(stream, seller, delimitador);
                        std::getline(stream, category, delimitador);
                        std::getline(stream, delivery_type, delimitador);
                        std::getline(stream, sku, delimitador);
                        std::getline(stream, quantity, delimitador);
                        std::getline(stream, name, delimitador);
                        std::getline(stream, amount, delimitador);


                        //imprimir
                        std::cout<<"========="<<std::endl;
                        std::cout<< created << std::endl;
                        std::cout<< payment_fk << std::endl;
                        std::cout<< store_fk << std::endl;
                        std::cout<< seller << std::endl;
                        std::cout<< category<< std::endl;
                        std::cout<< delivery_type << std::endl;
                        std::cout<< sku << std::endl;
                        std::cout<< quantity << std::endl;
                        std::cout<< name << std::endl;
                        std::cout<< amount << std::endl;

                        i++;
                    }
                    t = clock() -t;
                    std::cout<< "clock : "<< t <<std::endl;
                    std::cout<< "length : "<< i <<std::endl;
                    std::cout<< "total clock: " << clock() <<std::endl;
                }
                };
            }
        else
        {
            std::cerr << "Error al leer la primera linea del archivo."<< std::endl;
        }
    std::cout<<"Tu numero de Hilos es: "<<num_cores<<std::endl;
    archivo.close();
    return 0;
}
*/

#include <iostream>
#include <omp.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

int main() {
    long i = 0;
    std::ifstream archivo("D:/Descargas/pd.csv");
    std::string linea;
    char delimitador = ';';
    std::getline(archivo, linea); // Leer la primera línea (cabezera)
    //int num_cores = omp_get_num_procs();
     int num_cores = 6; // Puedes fijar esto si deseas un número fijo de hilos

    if (archivo.is_open()) {
        std::vector<std::string> lineas;

        // Leer todas las líneas del archivo y almacenarlas en un vector
        while (std::getline(archivo, linea)) {
            lineas.push_back(linea);
        }

        clock_t t;
        t = clock();

#pragma omp parallel for num_threads(num_cores) reduction(+:i) // Paralelizar el bucle for con reducción para contar las líneas procesadas
        for (size_t j = 0; j < lineas.size(); ++j) {
            std::stringstream stream(lineas[j]);
            std::string created, payment_fk, store_fk, seller, category, delivery_type, sku, quantity, name, amount; // Variables
            std::getline(stream, created, delimitador);
            std::getline(stream, payment_fk, delimitador);
            std::getline(stream, store_fk, delimitador);
            std::getline(stream, seller, delimitador);
            std::getline(stream, category, delimitador);
            std::getline(stream, delivery_type, delimitador);
            std::getline(stream, sku, delimitador);
            std::getline(stream, quantity, delimitador);
            std::getline(stream, name, delimitador);
            std::getline(stream, amount, delimitador);

            // Imprimir (opcional, descomentar si necesario)
            /*
            #pragma omp critical
            {
                std::cout << "=========" << std::endl;
                std::cout << created << std::endl;
                std::cout << payment_fk << std::endl;
                std::cout << store_fk << std::endl;
                std::cout << seller << std::endl;
                std::cout << category << std::endl;
                std::cout << delivery_type << std::endl;
                std::cout << sku << std::endl;
                std::cout << quantity << std::endl;
                std::cout << name << std::endl;
                std::cout << amount << std::endl;
            }
            */

            i++;
        }

        t = clock() - t;
        std::cout << "clock: " << t << std::endl;
        std::cout << "length: " << i << std::endl;

    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }

    std::cout << "Tu numero de Hilos es: " << num_cores << std::endl;
    archivo.close();
    return 0;
}
