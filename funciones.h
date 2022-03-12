#include <linux/slab.h>

struct sNode {
    char data;
    struct sNode* next;
};


void agregar(struct sNode** top_ref, int new_data)
{
   
    struct sNode* new_node
        = (struct sNode*)kmalloc(sizeof(struct sNode),GFP_KERNEL);
 
   
    new_node->data = new_data;
 
    new_node->next = (*top_ref);

    (*top_ref) = new_node;
}


int sacar(struct sNode** top_ref)
{
    char res;
    struct sNode* top;
 
    // If stack is empty then error
    if (*top_ref == NULL) {
        return -1;
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        kfree(top);
        return res;
    }
}

long pareja(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
