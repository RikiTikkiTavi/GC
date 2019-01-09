// Marks object if not marked
void mark(Object *object) {
    if (object->marked) return;

    object->marked = 1;

    if (object->type == TWIN) {
        mark(object->head);
        mark(object->tail);
    }
}

// Marks reachable objects
void markAll(VM *vm) {
    for (int i = 0; i < vm->stackSize; i++) {
        mark(vm->stack[i]);
    }
}

// Frees object if not marked (so unreachable) (objects that have been pop)
void markspeep(VM *vm) {
    // Creates pointer on objects pointer and assigns pointer on vm.firstObject
    Object **object = &vm->firstObject;
    // While objects pointer is not NULL
    while (*object) {

        // If object is not marked
        if (!(*object)->marked) {

            // Copy objects pointer to unreached
            Object *unreached = *object;

            // Assign to objects pointer new value = pointer on next object in LinkedList
            *object = unreached->next;
            free(unreached);

            // Decrease number of Objects in virtual memory
            vm->numObjects--;
        } else {
            // Mark object as unmarked
            (*object)->marked = 0;
            // object = pointer on next objects pointer
            object = &(*object)->next;
        }
    }
}

void gc(VM *vm) {
    int numObjects = vm->numObjects;

    markAll(vm);
    markspeep(vm);

    vm->maxObjects = vm->numObjects * 2;

    printf("Collected %d objects, %d left.\n", numObjects - vm->numObjects, vm->numObjects);
}