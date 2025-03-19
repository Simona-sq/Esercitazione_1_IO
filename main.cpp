#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <typeinfo>

int main()
{
    // Lettura da file_input e scrittura su file_output
    std::string input_filename = "./data.txt";
    std::string output_filename = "./result.txt";

    std::ifstream ifs(input_filename); // gestisco il file di input
    std::ofstream ofs(output_filename); // gestisco il file di output

	//Controllo apertura di file
    if (!(ifs.is_open() && ofs.is_open())) 
    {
        std::cerr << "Errore: impossibile aprire uno dei file!" << std::endl;
        return 1;
    }
    
	// Legge il file riga per riga
    std::string line;
    double somma = 0.0;
    int counter = 0;
    while (std::getline(ifs, line)) // finchè non finisce il file che stai leggendo
        {
            double value = std::stod(line); // converto "line" (stringa) in "value" (double)
            double value_t = -1.0 + (value-1.0)*(3.0/4.0); // trasformo l'intervallo da [1,5] a [-1,2]

            // aggiorno somma e counter
            somma += value_t;
            counter +=1;

            // calcolo  la media
            double media_parziale = somma/counter;
            ofs << std::scientific << std::setprecision(16) << media_parziale << std::endl;
        }
    ifs.close();
    ofs.close();
}