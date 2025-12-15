#include "../stack.h"
#include "assert.h"


void	test_lstnew(void)
{
	void	*a;
	t_list	*lst;

	a = malloc(sizeof(void *));
	lst = lstnew(a);
	assert(lst->prev == NULL);
	assert(lst->next == NULL);
	assert(lst->data == a);
	free_lst(lst, &free);
}

void	test_lstadd_front(void)
{
	void	*a;
	void	*b;
	void	*c;
	t_list	*lst;
	t_list	*lst_b;
	t_list	*lst_c;

	a = malloc(sizeof(void *));
	b = malloc(sizeof(void *));
	c = malloc(sizeof(void *));
	lst = lstnew(a);
	lst_b = lstnew(b);
	lst_c = lstnew(c);
	lstadd_front(&lst, lst_b);
	lstadd_front(&lst, lst_c);
	assert(lst->data == c);
	assert(lst->prev == NULL);
	assert(lst->next->data == b);
	assert(lst->next->prev == lst);
	assert(lst->next->next->data == a);
	assert(lst->next->next->prev == lst->next);
	free_lst(lst, &free);
}

void	test_lst_rotate(void)
{

}

int	main(void)
{
	test_lstnew();
	test_lstadd_front();
}
