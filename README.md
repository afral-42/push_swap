*This project has been created as part of the 42 curriculum by [ abounoua, arebilla ].*

# Push_swap

## Description

**push_swap** is a performance-oriented algorithmic project that requires sorting a stack of integers under strict constraints. The primary challenge lies in achieving a sorted state using a restricted instruction set while minimizing the total number of operations.

The system operates with two stacks:
* **Stack A**: Initially contains a set of unsorted, unique integers.
* **Stack B**: A secondary stack, initially empty.

The goal is to sort all integers in Stack A in ascending order by applying a sequence of predefined operations:
* **Swap** (`sa`, `sb`, `ss`): Exchanges the first two elements at the top of the stack.
* **Push** (`pa`, `pb`): Transfers the top element from one stack to the top of the other.
* **Rotate** (`ra`, `rb`, `rr`): Shifts all elements upward; the top element moves to the bottom.
* **Reverse Rotate** (`rra`, `rrb`, `rrr`): Shifts all elements downward; the bottom element moves to the top.

The success of the project is measured by the efficiency of the sorting algorithm, aiming for the lowest number of instructions to pass the evaluation thresholds.

## Technical Stack
* **Language:** C
* **Compiler:** `clang`
* **Build System:** Makefile

## Instructions

### Compilation
The project uses a standard **Makefile**. To build the executable, run:

```bash
make
```
Available rules: `all`, `clean`, `fclean`, `re`, `test`.

### Usage
```
./push_swap [stack_a] [STRATEGY] [OPTIONS]

Strategies:
  --simple      Force O(n²) algorithm.
  --medium      Force O(n√n) algorithm.
  --complex     Force O(n log n) algorithm.
  --adaptive    (Default) Automatically selects strategy based on disorder.

Options:
  --bench       Benchmark mode: display stats to stderr after sorting.
                (Disorder %, strategy name, complexity, and operation counts).

Examples:
  ./push_swap "3 1 2"
  ./push_swap "100 5 42 0" --complex --bench
  ARG="4 67 3"; ./push_swap "$ARG"
```

## Algorithms analysis

### Simple strategy: insertion sort adaptation
#### Introduction
The insertion sort algorithm adapted for two stacks (**Stack A** and **Stack B**) operates by isolating elements and reinserting them in their correct relative order. The logic follows a three-phase execution:

1.  **Initial Transfer:** Elements are moved from Stack $A$ to Stack $B$ to prepare for the sorted re-insertion.
2.  **Sorted Insertion:** The algorithm iterates through Stack $B$. For each element, it calculates the optimal number of rotations (`ra` or `rra`) required to bring the correct insertion point to the top of Stack $A$. Once the spot is ready, the element is pushed back onto Stack $A$.
3.  **Final Alignment:** After all elements are moved back to Stack $A$, a final rotation is performed to ensure the smallest element is at the top, completing the ascending sort.


#### Pseudo-code
```text
# Phase 1: Preparation
WHILE (size(Stack A) > 1):
    PUSH top of A to B (pb)

# Phase 2: Sorted insertion
WHILE (Stack B is NOT empty):
    # Determine the shortest path (rotations) 
    # to reach the correct insertion position in A
    insertion_index = get_insertion_index(stack A, top of B)
    
    ROTATE Stack A (ra or rra) based on insertion_index
    PUSH top of B to A (pa)

# Phase 3: Final Adjustment
min_index = get_min_index(Stack A)
ROTATE Stack A (ra or rra) to bring min_index to top
```

#### Cost Breakdown
| Step | Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Transfer $n - 1$ elements from Stack $A$ to Stack $B$ | $n - 1$ (`pb`) | $n - 1$ (`pb`) | $n - 1$ (`pb`) |
| **2** | **Loop :** While Stack $B$ is not empty | $n - 1$  | $n - 1$  | $n - 1$ |
| **2.1** | Position insertion node on top of $A$ | $0$ | $\sum_{k=2}^{n - 1} \frac{k}{4}$ (`ra` or `rra`) | $\sum_{k=2}^{n - 1} \frac{k}{2}$ (`ra` or `rra`) |
| **2.2** | Push top of $B$ onto $A$ | $n - 1$ (`pa`) | $n - 1$ (`pa`) | $n - 1$ (`pa`) |
| **3** | Finalize: Move smallest node to top of $A$ | $0$ | $\frac{n}{4}$ (`ra` or `rra`) | $\frac{n}{2}$ (`ra` or `rra`) |

#### Cost Analysis

##### Position Insertion (Step 2.1)
The cost of positioning the insertion node is cumulative as stack $B$ is emptied. In the **worst case**, the complexity follows the arithmetic series:

$$\text{Cost}_{2.1} = \sum_{k=2}^{n - 1} \frac{k}{2} = \frac{1}{2} \left( \frac{n(n+1)}{2} \right) - \frac{n}{2} - \frac{1}{2} = \frac{1}{4} (n^2 - n - 2)$$

For the **average case**, we assume the distance to the correct position is halved:

$$\text{Cost}_{2.1} = \sum_{k=2}^{n - 1} \frac{k}{4} = \frac{1}{4} \left( \frac{n(n+1)}{2} \right) - \frac{n}{4} - \frac{1}{4} = \frac{1}{8} (n^2 - n - 2 )$$

For the **best case**, we assume that the stack $A$ is already correctly positionned therefore there is no need to rotate the stack before proceeding to the insertion. The cost is $0$.

##### Total Cost
Given the cost of each step, the sum of the cost for each case in terms of number of operations performed is for the **worst case**:

$$\text{Total cost} = \frac{1}{4}(n^2 + 9n - 10)$$

For the **average case**:

$$\text{Total cost} = \frac{1}{8}(n^2 + 17n - 18)$$


For the **best case**:

$$\text{Total cost} = 2n - 2$$

##### Numerical estimate in number of operations performed:

| n |  Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- |
| **10** | $18$ | $31$ | $45$ |
| **100** | $198$ | $1460$ | $2722$ |
| **500** | $998$ | $32310$ | $63622$ |


#### Complexity Analysis

##### Time Complexity Analysis
Given the quadratic nature of the summation in Step 2.1, in order to evaluate the time complexity, we can omit the low order terms and the of the equation and the constant factors. the overall time complexity of the algorithm is:

* **Worst Case:** $O(n^2)$
* **Average Case:** $O(n^2)$
* **Best Case:** $O(n)$ (When the stacks is already sorted)

##### Space complexity

Given the requirements of the exercise, the space required to execute the algorithm is $2n$: 2 stacks of size $n$ are required to store and manipulate the data. 
* **Space complexity - *all cases*:** $O(n)$

#### Conclusion on Performance

The provided analysis demonstrates that this stack-based insertion sort is a **quadratic-time algorithm** ( $O(n^2)$ ) in both average and worst-case scenarios. Its performance is heavily dictated by the cost of rotations required to find the correct insertion index in Stack $A$.

While the algorithm is highly efficient for very small datasets (typically $n \leq 10$), the cost grows quadratically as $n$ increases. As shown in the numerical estimates, the operation count for $n=500$ exceeds 60,000, making it significantly less efficient than $O(n \log n)$ alternatives for large-scale data.

#### Optimal Use Cases

Despite its $O(n^2)$ complexity, this algorithm is optimal or highly suitable in the following contexts:

1.  **Small Data Sets:** Due to its low constant factors, it outperforms complex algorithms that require recursive calls or heavy partitioning logic when $n$ is very small.
2.  **Nearly Sorted Data:** If the input is already partially ordered, the number of rotations in the insertion step decreases significantly, moving the performance closer to the $O(n)$ best-case scenario.

### Medium strategy: XXXXXXX

xxxxx


### Complex strategy: Quick Sort

#### Introduction
Quick sort is a powerful sorting algorithm rooted in the **Divide and Conquer** paradigm. This approach focuses on breaking down a complex problem into smaller, more manageable sub-problems until they reach a state that can be solved directly.

In this implementation adapted for stacks (stack A and stack B), the *divide* phase is handled by the `partition_a` and `partition_b` functions.
- **Divide**: the algorithm calculate the median valie to split the current partition into two equal sub-partitions. Elements are moved betweeen from one stack to another based on their position relative to the median. Upper elements are moved to stack $A$ while lower elements are moved to stack $B$.
- **Conquer**: When a partition is reduced to a size of 3 or fewer, the `process_base_case_a` or `process_base_case_b` functions are triggered. This hard-coded logic solves the smallest sub-problems by manually handling all possible combinations for a stack of 3 elements.

The process follows a recursive cycle:
- **Partioning:** The data is split into *upper* and *lower* partitions, according to the mediane value. The "lower" partition is moved at the top of stack $B$, while the *upper* partition is moved at the top of stack $A$.
- **Recursive calls**: the `quicksort_a` function calls itself to handle the sorting of the upper partition, then calls `quicksort_b` to handle the sorting of the lower partition. `quicksort_b` handle the sorting of the **lower** partition by partitioning it into 2 sub-partitions, and recursively calling `quicksort_a` and `quicksort_b`.
- **Convergence**: Each recursive call moves the stack $A$ towards a fully sorted state. The recursion unwinds once the base cases are met. On stack $A$, the elements are sorted in ascending order, while on stack $B$ the elements are sorted in descending order, then pushed on stack $A$, hence being reverted in ascending order during the process.


#### Pseudo-code
```text

PROCESS_BASE_CASE(S)
    # hard coded sorting of the 3 top elements of the stack S

PARTITION_A_AND_PUSH_B(SOURCE, DEST, partition_size)
    # calculate the median value in order to ensure that the partition is split
    # in to 2 sub-partitions of equal size
    mediane = calculate_mediane_value

    FOR i = 1 to partition_size
        # push lower elements on B (lower partition)
        if (SOURCE == A AND top of SOURCE <  mediane)
            PUSH top of A to B

        # or push upper elements on A (lower partition)
        else if (SOURCE == B AND top of SOURCE >= mediane)
            PUSH top of B to A

        # put lower elements at the back of A (lower partition) 
        # or upper elements at the back of B (upper partition)
        else
            ROTATE SOURCE

    # put back upper or lower elements on top of the source stack
    FOR i = 1 to upper_partition_size
        REVERSE_ROTATE SOURCE

    return lower_partition_size, upper_partition_size

QUICKSORT_A(partition_size)
    if (partition_size <= 3)
        # partition A and push lower partition elements to B
        PROCESS_BASE_CASE(A)
    else
        lower_partition_size, upper_partition_size = PARTITION_AND_PUSH(A, B, partition_size)
        QUICKSORT_A(upper_partition_size)
        QUICKSORT_B(lower_partition_size)

QUICKSORT_B(partition_size)
    if (partition_size <= 3)
        PROCESS_BASE_CASE(B)
    else
        # partition B and push upper partition elements to A
        lower_partition_size, upper_partition_size = PARTITION_AND_PUSH(B, A partition_size)
        QUICKSORT_A(upper_partition_size)
        QUICKSORT_B(lower_partition_size)
```

#### Cost Breakdown

##### Base case processing
The base case handles the sorting of the top 3 elements of the stack in a maximum of 5 operations. For the sorting of the stack $B$, 3 additional pushes are required to move to elements to stack $A$ after sorting. The running time for this function is bounded and independent of the original size of stack $A$, thefore we consider it as constant time

$$ \text{T}_{Base Case} = O(1) $$

##### Partitioning processing

`partition_a` and `partition_b` procedures follow the same process:

| Step | Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Loop**: FOR $i$ = 1 to *partition_size* | $n$ | $n$ | $n$ |
| **1.1** | ROTATE or PUSH the top element of the stack | $n$ (`ra` or `rb` or `pa` or `pb` | $n$ (`ra` or `rb` or `pa` or `pb` | $n$ (`ra` or `rb` or `pa` or `pb` |
| **1.2** | REVERSE ROTATE to bring back the lower or upper partition to the top of the stack | $\frac{n}{2}$ (`rra` or `rrb`) | $\frac{n}{2}$ (`rra` or `rrb`) | $\frac{n}{2}$ (`rra` or `rrb`) |

For all cases, the running time of the partitioning is:
$$ \text{T}_{Partitioning} = \frac{3}{2}n = O(n)$$

##### Recursive calls processing

The running time of the recursive `quicksort_a` and `quicksort_b` functions can be expressed as follows:
$$ \text{T}_{quicksortA}(n) = \text{T}_{quicksortA}\left(\frac{n}{2}\right) + \text{T}_{quicksortB}\left(\frac{n}{2}\right)+ \text{T}_{Partitioning} $$
$$ \text{T}_{quicksortB}(n) = \text{T}_{quicksortA}\left(\frac{n}{2}\right) + \text{T}_{quicksortB}\left(\frac{n}{2}\right) + \text{T}_{Partitioning} $$

The expression can be simplified as follows
$$ \text{T}_{quicksort}(n) = 2\text{T}_{quicksort}\left(\frac{n}{2}\right) + 2\text{T}_{Partitioning} $$

##### Overall time complexity

The time complexity can be expresses as follows:

For $n <= 3$ :
$$ T(n) = O(1) $$
Else:
$$ \text{T}(n) = 2\text{T}\left(\frac{n}{2}\right) + O(n)$$
This equation resolves in:
$$ T(n) = O(n \log n) $$

#### Conclusion on performance

This implementation of Quick Sort Swap offers a significant performance boost over basic algorithms like Selection Sort or Bucket Sort. By achieving an average time complexity of $O(n \log n)$, it drastically reduces the number of operations required for large datasets. 

#### Optimal use cases
This Quick Sort algorithm is most effective for large sets of numbers (100 to 500+ elements) where the $O(n\log n)$ efficiency outweighs the constant overhead of stack manipulation. However, for small sets or data sets with low disorder, simpler algorithms are often more optimal as they avoid the recursive overhead and the extra rotations required by the partitioning process.

### Adaptative strategy: XXXXXX

xxxxx

## Resources
### Books
- Introduction to algorithms / Thomas H. Cormen, Charles E. Lierson, Ronald L. Rivest, Clifford Stein

### AI assistants
- Gemini 3 Flash: Assistance for redaction and formatting of `README.md`
