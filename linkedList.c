#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define type char*
typedef struct node node;

struct node{
    node *prox;
    type data;
};

typedef struct node_sentinel_head{
    int size;
    node *prox;
}head;


void init_head(head *h){
    h->size = 0;
    h->prox = NULL;
}

int is_empty(head* h){
    return h->prox == NULL;
}

void init_empty_node(node *n){
    n->prox = NULL;
    n->data = NULL;
}

void init_node(node *n, int w_size){
    n->prox = NULL;
    n->data = (type)malloc(w_size * sizeof(type));
}

void insert_at_first(head* head, node* node){
    node->prox = head->prox;
    head->prox = node;
}

void  add_sorted_node(head* head, type data){

    node* new_ = (node*)malloc(sizeof(node));
    if(new_ == NULL){
        exit(1);
        printf("Sem memoria irmao!\n");
    }

    head->size += 1;
    new_->data = data;
    if(head->size == 1 || strcmp(data, head->prox->data) < 0){
        insert_at_first(head,new_);
    }else{

        node *nav = head->prox;
        while(nav->prox != NULL && strcmp(data, nav->prox->data) > 0){
            nav = nav->prox;
        }
        new_->prox = nav->prox;
        nav->prox = new_;


    }
}

void remove_element(head* head, type data){
    if(is_empty(head))
        exit(0);
    if(strcmp(head->prox->data, data) == 0){
        node* garb = head->prox;
        head->prox = head->prox->prox;
        garb->prox = NULL;
        free(garb);
    }else{ //element to be removed, is not the first one
        node* nav = head->prox;
        while(nav->prox != NULL && strcmp(nav->prox->data, data) != 0){
            nav = nav->prox;
        }
        if(nav->prox == NULL){
            printf("Nao achei o que queria apagar!\n");
        }else{
            node* garb = nav->prox;
            nav->prox = garb->prox;
            garb->prox = NULL;
            free(garb);
        }
    }
}

void navigate_through(head* head){
    node* nav = head->prox;
    //printf("Cabeça %p -> %p\n", (void*)head, (void*)head->prox);

    while(nav != NULL){
        /*printf("%s em %p  -> ", nav->data, (void*)nav);
        if(nav->prox != NULL)
            printf("prox: %p\n", (void*)nav->prox);
        else
            printf("prox eh null\n");*/
        printf("%s\n", nav->data);
        nav = nav->prox;
    }
}

int main(void){
    head h;
    init_head(&h);
    add_sorted_node(&h, "Oi");
    add_sorted_node(&h, "Abacate!");
    add_sorted_node(&h, "Felicidade");
    add_sorted_node(&h, "Aaaaaadeucerto");
    navigate_through(&h);
    remove_element(&h, "Oi");
    printf("Apaguei o \"Oi\"\n");
    navigate_through(&h);
    printf("Cabeça %p -> %p\n", (void*)&h, (void*)h.prox);

    remove_element(&h, "Abacate!");
    printf("Apaguei o \"Abacate\"\n");
    navigate_through(&h);
    printf("Cabeça %p -> %p\n", (void*)&h, (void*)h.prox);

    remove_element(&h, "Aaaaaadeucerto");
    printf("Apaguei o \"Aaaaaadeucerto\"\n");
    navigate_through(&h);
    printf("Cabeça %p -> %p\n", (void*)&h, (void*)h.prox);

    remove_element(&h, "Felicidade");
    printf("Apaguei o \"Felicidade\"\n");

    navigate_through(&h);
    printf("Cabeça %p -> %p\n", (void*)&h, (void*)h.prox);

    return 0;
}
