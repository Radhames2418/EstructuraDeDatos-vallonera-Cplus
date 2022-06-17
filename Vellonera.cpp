#include "Vellonera.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Vellonera::Vellonera() : _repetir(false), _primera(NULL), _ultima(NULL), _actual(NULL)
{
}

void Vellonera::Agregar(Cancion *cancion)
{
    /*IMPLEMENTAR ESTE METODO PARA AGREGAR NUEVA CANCIÓN  LA VELLONERA*/
    if (_primera != NULL)
    {
        _ultima->SetSiguiente(cancion);
        _ultima = cancion;
        OrdenarCanciones();
    }
    else
    {
        _primera = cancion;
        _ultima = _primera;
    }
}

void Vellonera::OrdenarCanciones()
{
    /*IMPLEMENTAR ESTE METODO PARA ORDERNAR LAS CANCIONES DE MENOR A MAYOR (SEGUN SU DURACION)*/

    Cancion *primero = _primera;
    Cancion *auxiliar = NULL;

    while (primero->GetSiguiente() != NULL)
    {

        auxiliar = primero->GetSiguiente();

        while (auxiliar != NULL)
        {

            if (primero->GetDuracion().GetTiempoTotal() > auxiliar->GetDuracion().GetTiempoTotal())
            {

                string NombreAltista = primero->GetArtista();
                string NombreCancion = primero->GetTitulo();
                tiempo duracionPrimero = primero->GetDuracion();
                tiempo duracionAux = auxiliar->GetDuracion();

                primero->SetArtista(auxiliar->GetArtista());
                primero->SetTitulo(auxiliar->GetTitulo());
                primero->SetDuracion(duracionAux);

                auxiliar->SetArtista(NombreAltista);
                auxiliar->SetTitulo(NombreCancion);
                auxiliar->SetDuracion(duracionPrimero);
            }

            auxiliar = auxiliar->GetSiguiente();
        }

        primero = primero->GetSiguiente();
    }
}

void Vellonera::CancionSiguiente()
{
    /*IMPLEMENTAR ESTE MÉTODO PARA AVANZAR A LA SIGUIENTE CANCION (Ver puntero _actual)*/

    if (_primera != NULL && _ultima != NULL)
    {

        if (_actual == NULL)
        {
            _actual = _primera;
            Cancion *siguiente = _actual->GetSiguiente();
        }
        else
        {
            Cancion *siguiente = _actual->GetSiguiente();
            if (siguiente == NULL && _repetir == true)
            {
                _actual = _primera;
            }
            else if (siguiente == NULL && _repetir == false)
            {
            }
            else
            {
                _actual = siguiente;
            }
        }
    }
}

void Vellonera::CancionAnterior()
{

    if (_primera != NULL && _ultima != NULL)
    {

        if (_actual == NULL)
        {
            _actual = _primera;
            Cancion *anterior = _actual->GetAnterior();
        }
        else
        {
            Cancion *anterior = _actual->GetAnterior();
            if (anterior == NULL && _repetir == true)
            {
                _actual = _ultima;
            }
            else if (anterior == NULL && _repetir == false)
            {
            }
            else
            {
                _actual = anterior;
            }
        }
    }
}

bool Vellonera::Eliminar(int indice)
{
    int contador = -1;
    Cancion *canacion_eliminar = _primera;

    while (canacion_eliminar != NULL)
    {
        Cancion *siguiente = canacion_eliminar->GetSiguiente();
        contador++;

        if (contador == indice)
        {

            Cancion *auxiliar = canacion_eliminar;

            if (_primera == canacion_eliminar)
            {
                _primera = siguiente;
            }
            else
            {
                _ultima->SetSiguiente(siguiente);
            }

            delete auxiliar;

            return true;
        }

        _ultima = canacion_eliminar;
        canacion_eliminar = siguiente;
    }

    if (contador <= indice || contador >= indice)
    {
        return false;
    }
}
