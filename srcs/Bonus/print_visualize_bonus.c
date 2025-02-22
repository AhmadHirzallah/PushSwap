#include "pushswap_bonus.h"
#include "../mandatory/all_headers.h"
#include "ft_printf.h"

/* ************************************************************************** */
/* Bonus Helper: Print the headers for two stacks                          */
/* ************************************************************************** */
void bonus_print_headers(char *na, char *nb)
{
    ft_printf("   %-8s     |   %-8s   \n", na, nb);
    ft_printf("----------------------------\n");
}

/* ************************************************************************** */
/* Bonus Helper: Print one row from two bonus stacks                         */
/* ************************************************************************** */
void bonus_print_stack_row(t_dlist_node *ca, t_dlist_node *cb)
{
    int va;
    int vb;

    va = 0;
    if (ca != NULL)
    {
        va = ca->data->as_int;
    }
    vb = 0;
    if (cb != NULL)
    {
        vb = cb->data->as_int;
    }
    ft_printf("|  %3d  |  <->  |  %3d  |\n", va, vb);
}

/* ************************************************************************** */
/* Bonus Helper: Update the current pointers for bonus stacks                */
/* ************************************************************************** */
void bonus_update_currents(t_dlist_node **ca, t_dlist_node **cb, 
                           t_dlist_node *ha, t_dlist_node *hb)
{
    if (*ca != NULL)
    {
        if ((*ca)->next == ha)
            *ca = NULL;
        else
            *ca = (*ca)->next;
    }
    if (*cb != NULL)
    {
        if ((*cb)->next == hb)
            *cb = NULL;
        else
            *cb = (*cb)->next;
    }
}

/* ************************************************************************** */
/* Bonus Visualizer: Print two bonus stacks side-by-side                     */
/* ************************************************************************** */
void bonus_print_visual_2dstacks(t_d_stack *a, char *na, t_d_stack *b, char *nb)
{
    t_dlist_node *ca;
    t_dlist_node *cb;
    t_dlist_node *ha;
    t_dlist_node *hb;

    ca = NULL;
    if (a != NULL)
        ca = a->head;
    cb = NULL;
    if (b != NULL)
        cb = b->head;
    ha = ca;
    hb = cb;
    bonus_print_headers(na, nb);
    while (ca != NULL || cb != NULL)
    {
        bonus_print_stack_row(ca, cb);
        bonus_update_currents(&ca, &cb, ha, hb);
    }
    if (a != NULL)
        ft_printf("Stack %s size: (%ld)\n", na, a->size);
    if (b != NULL)
        ft_printf("Stack %s size: (%ld)\n", nb, b->size);
}
