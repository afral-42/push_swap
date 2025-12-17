NAME = libftprintf.a
SRCS = \
			 ft_printf.c \
			 ft_vprintf.c \
			 parsers.c \
			 parsers_helpers1.c \
			 format_value.c \
			 format_value_helpers1.c \
			 format_value_helpers2.c \
			 prefix.c \
			 specifiers.c \
			 ft_putnbr_base.c
SRCS_BONUS = \
			 ft_printf.c \
			 ft_vprintf_bonus.c \
			 parsers_bonus.c \
			 parsers_helpers1_bonus.c \
			 parsers_helpers2_bonus.c \
			 format_value_bonus.c \
			 format_value_helpers1_bonus.c \
			 format_value_helpers2_bonus.c \
			 left_pad_bonus.c \
			 right_pad_bonus.c \
			 pad_helpers1_bonus.c \
			 pad_helpers2_bonus.c \
			 prefix_bonus.c \
			 specifiers_bonus.c \
			 ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
DEPS = $(SRCS:.c=.d)
DEPS_BONUS = $(SRCS_BONUS:.c=.d)
LIBFT_DIR = libft
LIBFT_FILE = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP
INCLUDES = -I$(LIBFT_DIR)
CC += $(INCLUDES)
AR = ar rcs

.PHONY: all clean fclean re bonus

all:
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT_FILE)
	$(MAKE) $(NAME)

bonus:
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT_FILE)
	$(MAKE) $(NAME) -e OBJS="$(OBJS_BONUS)"

$(NAME): $(LIBFT) $(OBJS) Makefile
	cp $< $@
	$(AR) $@ $(OBJS)

clean:
	rm -fv $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -fv $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS) $(DEPS_BONUS)
