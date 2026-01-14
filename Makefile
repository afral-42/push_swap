NAME = push_swap
FILES = \
	data_structures/stack.c \
	data_structures/list.c \
	data_structures/list_utils.c \
	data_structures/operations.c \
	data_structures/operations_push.c \
	data_structures/operations_rotate.c \
	data_structures/operations_reverse_rotate.c \
	data_structures/operations_swap.c \
	data_structures/ops_counter.c \
	algorithms/insertion_sort.c \
	algorithms/selection_sort.c \
	algorithms/insertion_sort_utils.c \
	algorithms/algo_utils.c \
	algorithms/bucket_sort.c \
	algorithms/radix_sort.c \
	algorithms/quick_sort.c \
	algorithms/quick_sort_utils.c \
	algorithms/merge_sort.c \
	algorithms/stack_linearisation.c \
	parsing/parsing_utils.c \
	parsing/parsing.c \
	parsing/ft_putdouble_fd.c \
	parsing/bench_display.c \
	parsing/split_args_utils.c \
	parsing/split_args.c \
	push_swap.c

SRCS_DIR = srcs
BUILD_DIR = build
SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIR)/%.d, $(FILES))

LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF_FILE = libftprintf.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_FILE)

TESTS_DIR = tests
TESTS_BUILD_DIR = $(TESTS_DIR)/build
TESTS_FILES = \
			test_stack.c \
			test_list.c \
			test_operations.c \
			test_compute_disorder.c \
			test_get_insertion_index.c \
			test_insertion.c \
			test_bucket.c \
			test_radix.c \
			test_selection.c \
			test_merge.c \
			test_quick.c
TESTS := $(patsubst %.c, %, $(TESTS_FILES))
TESTS_SRCS := $(addprefix $(TESTS_DIR)/, $(TESTS_FILES))
TESTS_OBJS := $(addprefix $(TESTS_BUILD_DIR)/, $(patsubst %.c, %.o, $(TESTS_FILES)))
TESTS_DEPS := $(patsubst %.o, %.d, $(TESTS_OBJS))
TESTS_BIN := $(addprefix $(TESTS_BUILD_DIR)/, $(TESTS))
TESTS_HELPERS_FILES = tests_helpers.c
TESTS_HELPERS_SRCS := $(addprefix $(TESTS_DIR)/, $(TESTS_HELPERS_FILES))
TESTS_HELPERS_OBJS := $(addprefix $(TESTS_BUILD_DIR)/, $(patsubst %.c, %.o, $(TESTS_HELPERS_FILES)))
TESTS_HELPERS_DEPS := $(patsubst %.o, %.d, $(TESTS_HELPER_OBJS))

INCLUDES_DIR = includes

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES_DIR)
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re test memtest test_% memtest_% debug
.NOTINTERMEDIATE: $(TESTS_BIN) $(TESTS_OBJS) $(TESTS_HELPERS_OBJS) $(OBJS)

all: $(NAME)

debug: CFLAGS += -g -O0 -DDEBUG
debug: fclean $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $^ -o $@ 

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

check:
	echo $(OBJS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

test: $(TESTS)

memtest: $(addprefix mem, $(TESTS))

test_%: $(TESTS_BUILD_DIR)/test_%
	@echo ⏳ Running $@...
	@./$< > /dev/null
	@echo ✅ $@ passed!

memtest_%: $(TESTS_BUILD_DIR)/test_%
	@echo ⏳ Running $@...
	@valgrind -q --leak-check=full --error-exitcode=1 ./$< > /dev/null
	@echo ✅ $@ passed!

$(TESTS_BUILD_DIR)/test_%: $(TESTS_BUILD_DIR)/test_%.o $(TESTS_HELPERS_OBJS) $(filter-out $(BUILD_DIR)/push_swap.o, $(OBJS)) $(LIBFTPRINTF)
	$(CC) -g $^ -o $@

$(TESTS_BUILD_DIR)/%.o: $(TESTS_DIR)/%.c
	@mkdir -p $(TESTS_BUILD_DIR)
	$(CC) -g -c $< -o $@

norm: $(SRCS)
	@echo ⏳ Running norminette...
	@norminette -R CheckForbiddenHeader $(SRCS_DIR) $(INCLUDES_DIR) $(LIBFTPRINTF_DIR)
	@echo ✅ Norminette passed!

clean:
	rm -rfv $(BUILD_DIR) $(TESTS_BUILD_DIR)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -fv $(TESTS_BIN)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

-include $(DEPS) $(TESTS_DEPS)
