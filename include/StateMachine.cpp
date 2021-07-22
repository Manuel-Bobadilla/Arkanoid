//
// Created by Facundo Barafani on 9/5/21.
//

#include "StateMachine.h"

void StateMachine::addState(StateRef newState, bool isReplacing) {
    this->_isAdding = true;
    this->_isReplacing = isReplacing;

    this->_newState = std::move(newState);
}

void StateMachine::removeState() {
    this->_isRemoving = true;
}

void StateMachine::processStateChanges() {
    // En caso de que se este borrando un estado y la pila de estados
    // no sea vacia se saca un elemento de la pila
    if (this->_isRemoving && !this->_states.empty()){
        this->_states.pop();
    // Se revisa nuevamente si la pila esta vacia una vez que se removio el anterior
        // en caso de que no sea vacia el elemento que quedo arriba en la pila es el
        // estado que se corre
        if (!this->_states.empty()){
            this->_states.top()->resume();
        }
        // Indicamos que se termino de borrar un estado
        this->_isRemoving = false;
    }
    //En caso de que estemos anñadiendo tenemos dos opciones:
    if (this->_isAdding) {
        if (!this->_states.empty()) {
            // En caso de que se esta reemplazando sacamos el elemento que esta actualmente
            // en la pila y luego ponemos el nuevo
            if (this->_isReplacing) {
                this->_states.pop();
            } else {
                // En caso contrario no se saca el elemento sino que se pasa unicamente
                this->_states.top()->pause();
            }
        }
        this->_states.push(std::move(this->_newState));
        this->_states.top()->init();
        //Indicamos que se termino de agregar un estado
        this->_isAdding = false;
    }
}

StateRef &StateMachine::getActiveState(){
    return this->_states.top();
}