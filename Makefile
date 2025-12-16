SRCS = \
	stack.c \
	linked_list.c

BUILD_DIRECTORY = build
OBJS := $(patsubst %.c, $(BUILD_DIRECTORY)/%.o, $(SRCS))
DEPS := $(patsubst %.c, $(BUILD_DIRECTORY)/%.d, $(SRCS))

TESTS_DIRECTORY = tests
TESTS_BUILD_DIRECTORY = $(TESTS_DIRECTORY)/build
TESTS := $(patsubst %.c, test_%, $(SRCS))
TESTS_FILES := $(patsubst %.c, test_%.c, $(SRCS))
TESTS_SRCS := $(addprefix $(TESTS_DIRECTORY)/, $(TESTS_FILES))
TESTS_OBJS := $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(patsubst %.c, $.o, $(TESTS_FILES)))
TESTS_DEPS := $(patsubst %.o, %.d, $(TESTS_OBJS))
TESTS_BIN := $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(TESTS))
TESTS_HELPERS_FILES = tests_helpers.c
TESTS_HELPERS_SRCS := $(addprefix $(TESTS_DIRECTORY)/, $(TESTS_HELPERS_FILES))
TESTS_HELPERS_OBJS = $(addprefix $(TESTS_BUILD_DIRECTORY)/, $(patsubst %.c, %.o, $(TESTS_HELPERS_FILES)))
TESTS_HELPERS_DEPS := $(patsubst %.o, %.d, $(TESTS_HELPER_OBJS))

CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -MMD -MP
CC += $(CFLAGS) $(CPPFLAGS)

.PHONY: all clean fclean re test memtest test_% memtest_%

all:
	@echo "To be implemented"

check:
	@echo $(TESTS_HELPERS_SRCS)
	@echo $(TESTS_HELPERS_OBJS)

$(BUILD_DIRECTORY)/%.o: %.c
	@mkdir -p $(BUILD_DIRECTORY)
	$(CC) -c $< -o $@

test: $(TESTS)

memtest: $(addprefix mem, $(TESTS))

test_%: $(TESTS_BUILD_DIRECTORY)/test_%
	@echo ⏳ Running $@...
	@./$< > /dev/null
	@echo ✅ $@ passed!

memtest_%: $(TESTS_BUILD_DIRECTORY)/test_%
	@echo ⏳ Running $@...
	@valgrind -q --error-exitcode=1 ./$< > /dev/null
	@echo ✅ $@ passed!

$(TESTS_BUILD_DIRECTORY)/test_%: $(TESTS_BUILD_DIRECTORY)/test_%.o $(TESTS_HELPERS_OBJS) $(OBJS)
	$(CC) $^ -o $@

$(TESTS_BUILD_DIRECTORY)/%.o: $(TESTS_DIRECTORY)/%.c
	@mkdir -p $(TESTS_BUILD_DIRECTORY)
	$(CC) -c $< -o $@

clean:
	rm -rfv $(BUILD_DIRECTORY) $(TESTS_BUILD_DIRECTORY)

fclean: clean
	rm -fv $(TESTS_BIN)

re: fclean all

-include $(DEPS) $(TESTS_DEPS)
