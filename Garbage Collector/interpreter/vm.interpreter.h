#define STACK_MAX_SIZE 256
#define IGCT 8

// Identify defined object type
typedef enum {
    INT,
    TWIN // Can store to objects
} ObjectType;


typedef struct sObject {
    // Object type
    ObjectType type;

    // Field to mark objects that have references
    unsigned char marked;

    // Ptr on next object
    struct sObject *next;

    // Object value: integer or twin
    union {
        int value;

        struct {
            struct sObject *head;
            struct sObject *tail;
        };
    };
} Object;


/**
 * Stack Based Virtual Machine
 */

// Create Virtual Memory
typedef struct {
    Object *stack[STACK_MAX_SIZE];
    int stackSize;

    Object *firstObject;

    int numObjects;

    int maxObjects;
} VM;

// Stack operations

void push(VM *vm, Object *value) {
    vm->stack[vm->stackSize++] = value;
}


Object *pop(VM *vm) {
    return vm->stack[--vm->stackSize];
}

// /Stack operations

// Init Virtual Machine
VM *newVM() {
    VM *vm = (VM *) malloc(sizeof(VM));
    vm->stackSize = 0;
    vm->firstObject = NULL;
    vm->numObjects = 0;
    vm->maxObjects = IGCT;
    return vm;
}