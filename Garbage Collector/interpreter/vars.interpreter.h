// Create new object
Object *newObject(VM *vm, ObjectType type) {
    if (vm->numObjects == vm->maxObjects) gc(vm);

    Object *object = (Object *) malloc(sizeof(Object));
    object->type = type;
    object->next = vm->firstObject;
    vm->firstObject = object;
    object->marked = 0;

    vm->numObjects++;

    return object;
}

void pushInt(VM *vm, int intValue) {
    Object *object = newObject(vm, INT);
    object->value = intValue;

    push(vm, object);
}

Object *pushPair(VM *vm) {
    Object *object = newObject(vm, TWIN);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm, object);
    return object;
}