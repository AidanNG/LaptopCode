
#include "undoRedo.h"
undoRedo::undoRedo() {
    re = new stack;
    un = new stack;
}
undoRedo::~undoRedo() {
    while(!(un->empty())){
        un->pop();
    }
    while(!(re->empty())){
        re->pop();
    }
}
void undoRedo::addCommand(command *newCommand) {
    un->push(newCommand);
}
void undoRedo::undo() {
    if(!(un->empty())){
        command* topEntry = un->top();
        topEntry->unExecute();
        re->push(topEntry);
        un->pop();

    }
}
void undoRedo::redo(){
    if(!(re->empty())){
        command* topEntry = re->top();
        topEntry->execute();
        un->push(topEntry);
        re->pop();

    }
}


