#include <assert.h>
#include "tests.h"

void	test_lstnew(void)
{
	int		a;
	t_list	*lst;

	a = 1;
	lst = lstnew(a);
	assert(lst->prev == NULL);
	assert(lst->next == NULL);
	assert(lst->data == 1);
	free_lst(lst);
}

void	test_lstadd_front(void)
{
	int		a;
	int		b;
	int		c;
	t_list	*lst;
	t_list	*lst_b;
	t_list	*lst_c;

	a = 1;
	b = 2;
	c = 3;
	lst = lstnew(a);
	lst_b = lstnew(b);
	lst_c = lstnew(c);
	lstadd_front(&lst, lst_b);
	lstadd_front(&lst, lst_c);
	assert(lst->data == 3);
	assert(lst->prev == NULL);
	assert(lst->next->data == 2);
	assert(lst->next->prev == lst);
	assert(lst->next->next->data == 1);
	assert(lst->next->next->prev == lst->next);
	free_lst(lst);
}

void	test_lst_rotate(void)
{
	t_list	*lst;

	lst = generate_list(1);
	lst_rotate(&lst);
	assert(lst->data == 1);
	assert(lst->next == NULL);
	assert(lst->prev == NULL);
	free_lst(lst);
	lst = generate_list(2);
	lst_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 1);
	free_lst(lst);
	lst = generate_list(3);
	lst_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 3);
	assert(lst->next->next->data == 1);
	free_lst(lst);
	lst = generate_list(4);
	lst_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 3);
	assert(lst->next->next->data == 4);
	assert(lst->next->next->next->data == 1);
	free_lst(lst);
}

void	test_lst_reverse_rotate(void)
{
	t_list	*lst;

	lst = generate_list(1);
	lst_reverse_rotate(&lst);
	assert(lst->data == 1);
	assert(lst->next == NULL);
	assert(lst->prev == NULL);
	free_lst(lst);
	lst = generate_list(2);
	lst_reverse_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 1);
	free_lst(lst);
	lst = generate_list(3);
	lst_reverse_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 3);
	assert(lst->next->data == 1);
	assert(lst->next->next->data == 2);
	free_lst(lst);
	lst = generate_list(4);
	lst_reverse_rotate(&lst);
	check_list_integrity(lst);
	assert(lst->data == 4);
	assert(lst->next->data == 1);
	assert(lst->next->next->data == 2);
	assert(lst->next->next->next->data == 3);
	free_lst(lst);
}

void	test_lst_swap_head_nodes(void)
{
	t_list	*lst;

	lst = generate_list(1);
	lst_swap_head_nodes(&lst);
	assert(lst->data == 1);
	assert(lst->next == NULL);
	assert(lst->prev == NULL);
	free_lst(lst);
	lst = generate_list(2);
	lst_swap_head_nodes(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 1);
	free_lst(lst);
	lst = generate_list(3);
	lst_swap_head_nodes(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 1);
	assert(lst->next->next->data == 3);
	free_lst(lst);
	lst = generate_list(4);
	lst_swap_head_nodes(&lst);
	check_list_integrity(lst);
	assert(lst->data == 2);
	assert(lst->next->data == 1);
	assert(lst->next->next->data == 3);
	assert(lst->next->next->next->data == 4);
	free_lst(lst);
}

int	main(void)
{
	test_lstnew();
	test_lstadd_front();
	test_lst_rotate();
	test_lst_reverse_rotate();
	test_lst_swap_head_nodes();
}
