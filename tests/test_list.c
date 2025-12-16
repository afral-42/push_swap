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

int	main(void)
{
	test_lstnew();
	test_lstadd_front();
}
