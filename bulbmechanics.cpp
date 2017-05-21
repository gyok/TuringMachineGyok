#include "bulbmechanics.h"

struct lane * addelem(lane *lane_base, char* letter)
{
  struct lane *temp, *p;
  temp = new lane;
  p = lane_base->next; // сохранение указателя на следующий узел
  lane_base->next = temp; // предыдущий узел указывает на создаваемый
  temp->current_letter = letter; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lane_base; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  return(temp);
}


struct instruction{
    char* let_prev;
    char* let_next;
    Bulb* next_bulb;
    char move_in;
};

int MachineTuring::step(){
    instruction *curr_instruction;
    curr_instruction = new instruction;
    int result = 4;
    int i;

    for (i = 0; i < this->currentBulb->instructions_count; i++){
        if (this->currentBulb->instructions[i].let_prev == this->laneTuring->current_letter){
            *curr_instruction = this->currentBulb->instructions[i];
            result = 3;
        }
    }

    this->laneTuring->current_letter = curr_instruction->let_next;
    this->currentBulb = curr_instruction->next_bulb;
    if (curr_instruction->move_in == 'L'){
        this->laneTuring = this->laneTuring->prev;
        result = 0;
    }
    else if (curr_instruction->move_in == 'R'){
        this->laneTuring = this->laneTuring->next;
        result = 0;
    }
    else if (curr_instruction->move_in == 'S'){
        result = 1;
    }
    else {
        result = 2;
    }

    return result;
}

Bulb::Bulb(){

}

Bulb::~Bulb(){

}

bulbMechanics::bulbMechanics()
{

}
