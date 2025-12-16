FILES = \
	data_structures/stack.c \
	data_structures/list.c \
	data_structures/operations.c
SRCS_DIRECTORY = srcs
BUILD_DIRECTORY = build
SRCS = $(addprefix $(SRCS_DIRECTORY)/, $(FILES))
OBJS := $(patsubst %.c, $(BUILD_DIRECTORY)/%.o, $(FILES))
DEPS := $(patsubst %.c, $(BUILD_DIRECTORY)/%.d, $(FILES))
HEADERS = stack.h

TESTS_DIRECTORY = tests
TESTS_BUILD_DIRECTORY = $(TESTS_DIRECTORY)/build
TESTS_FILES = \
			test_stack.c \
			test_operations.c \
			test_compute_disorder.c
TESTS := $(patsubst %.c, %, $(TESTS_FILES))
TESTS_SRCS := $(addprefix $(TESTS_DIRECTORY)/, $(TESTS_FILES))
TESTS_OBJS := $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(patsubst %.c, %.o, $(TESTS_FILES)))
TESTS_DEPS := $(patsubst %.o, %.d, $(TESTS_OBJS))
TESTS_BIN := $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(TESTS))
TESTS_HELPERS_FILES = tests_helpers.c
TESTS_HELPERS_SRCS := $(addprefix $(TESTS_DIRECTORY)/, $(TESTS_HELPERS_FILES))
TESTS_HELPERS_OBJS := $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(patsubst %.c, %.o, $(TESTS_HELPERS_FILES)))
TESTS_HELPERS_DEPS := $(patsubst %.o, %.d, $(TESTS_HELPER_OBJS))

CFLAGS += -Wall -Wextra -Werror -Iincludes
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re test memtest test_% memtest_%
.NOTINTERMEDIATE: $(TESTS_BIN) $(TESTS_OBJS) $(TESTS_HELPERS_OBJS) $(OBJS)

all:
	@echo "To be implemented"

check:
	echo $(OBJS)

$(BUILD_DIRECTORY)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

test: $(TESTS)

memtest: $(addprefix mem, $(TESTS))

test_%: $(TESTS_BUILD_DIRECTORY)/test_%
	@echo ⏳ Running $@...
	@./$< > /dev/null
	@echo ✅ $@ passed!

memtest_%: $(TESTS_BUILD_DIRECTORY)/test_%
	@echo ⏳ Running $@...
	@valgrind -q --leak-check=full --error-exitcode=1 ./$< > /dev/null
	@echo ✅ $@ passed!

$(TESTS_BUILD_DIRECTORY)/test_%: $(TESTS_BUILD_DIRECTORY)/test_%.o $(TESTS_HELPERS_OBJS) $(filter-out $(BUILD_DIRECTORY)/push_swap.o, $(OBJS))
	$(CC) -g $^ -o $@

$(TESTS_BUILD_DIRECTORY)/%.o: $(TESTS_DIRECTORY)/%.c
	@mkdir -p $(TESTS_BUILD_DIRECTORY)
	$(CC) -g -c $< -o $@

norm: $(SRCS)
	@echo ⏳ Running norminette...
	@norminette -R CheckForbiddenHeader $(SRCS) $(HEADERS)
	@echo ✅ Norminette passed!

clean:
	rm -rfv $(BUILD_DIRECTORY) $(TESTS_BUILD_DIRECTORY)

fclean: clean
	rm -fv $(TESTS_BIN)

re: fclean all

-include $(DEPS) $(TESTS_DEPS)
