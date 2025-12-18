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

void	test_lstcheck_duplicate(void)
{
	t_list	*lst;
	t_list	*lst_b;
	t_list	*lst_c;
	t_list	*lst_d;

	lst = lstnew(1);
	lst_b = lstnew(2);
	lst_c = lstnew(3);
	lst_d = lstnew(10);

	lstadd_front(&lst, lstnew(2));
	lstadd_front(&lst, lstnew(3));
	lstadd_front(&lst, lstnew(4));
	lstadd_front(&lst, lstnew(5));
	lstadd_front(&lst, lstnew(6));
	lstadd_front(&lst, lstnew(7));
	lstadd_front(&lst, lstnew(8));

	lstadd_front(&lst_b, lstnew(10));
	lstadd_front(&lst_b, lstnew(3));
	lstadd_front(&lst_b, lstnew(-6));
	lstadd_front(&lst_b, lstnew(1));
	lstadd_front(&lst_b, lstnew(2));
	lstadd_front(&lst_b, lstnew(7));
	lstadd_front(&lst_b, lstnew(4));

	lstadd_front(&lst_c, lstnew(4));
	lstadd_front(&lst_c, lstnew(-25454));
	lstadd_front(&lst_c, lstnew(1485512));
	lstadd_front(&lst_c, lstnew(951));
	lstadd_front(&lst_c, lstnew(-92122));
	lstadd_front(&lst_c, lstnew(0));
	lstadd_front(&lst_c, lstnew(4));
	lstadd_front(&lst_c, lstnew(5225));
	lstadd_front(&lst_c, lstnew(91));
	lstadd_front(&lst_c, lstnew(78));
	lstadd_front(&lst_c, lstnew(20));
	lstadd_front(&lst_c, lstnew(15200));
	lstadd_front(&lst_c, lstnew(321));


	lstadd_front(&lst_d, lstnew(9));
	lstadd_front(&lst_d, lstnew(7));
	lstadd_front(&lst_d, lstnew(6));
	lstadd_front(&lst_d, lstnew(5));
	lstadd_front(&lst_d, lstnew(4));
	lstadd_front(&lst_d, lstnew(3));
	lstadd_front(&lst_d, lstnew(2));
	lstadd_front(&lst_d, lstnew(1));

	assert(lstcheck_duplicate(lst) == 0);
	assert(lstcheck_duplicate(lst_b) == 1);
	assert(lstcheck_duplicate(lst_c) == 1);
	assert(lstcheck_duplicate(lst_d) == 0);

	free_lst(lst);
	free_lst(lst_b);
	free_lst(lst_c);
	free_lst(lst_d);
}

int	main(void)
{
	test_lstnew();
	test_lstadd_front();
	test_lstcheck_duplicate();
}
