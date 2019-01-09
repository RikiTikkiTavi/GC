void objectPrint(Object *object) {
    switch (object->type) {
        case INT:
            printf("%d", object->value);
            break;

        case TWIN:
            printf("(");
            objectPrint(object->head);
            printf(", ");
            objectPrint(object->tail);
            printf(")");
            break;
    }
}

void freeVM(VM *vm) {
    vm->stackSize = 0;
    gc(vm);
    free(vm);
}
