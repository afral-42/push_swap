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
The cost of positioning the insertion node is cumulative as stack $B$ is emptied. In the **worst case**, the complexity is an arithmetic series that resolves as follows:

$$\text{Cost}_{2.1} = \sum_{k=2}^{n - 1} \frac{k}{2} = \frac{1}{4} (n^2 - n - 2)$$

For the **average case**, we assume the distance to the correct position is halved:

$$\text{Cost}_{2.1} = \sum_{k=2}^{n - 1} \frac{k}{4} = \frac{1}{8} (n^2 - n - 2 )$$

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

### Medium strategy: Bucket sort
#### Introduction
The bucket sort algorithm adapted for two stacks operates on the following principles:
- **Normalization (indexing)**: Since Buket Sort performs best with a uniform distribution, the initial stack is analysed without performing any **stack operation**. Each value is replaced by its *rank* (its relative position from $0$ to $n - 1$). This tranforms any input into a perfectly uniform distribution of integers, while preserving their relative order.
- **Bucket partitioning**: The stack is divided into $k$ virtual buckets. For each bucket $i$ (from $0$ to $k - 1$), we identify elements within the range $\left[ i \times \frac{n}{k}, (i + 1) \times \frac{n}{k} \right)$. These elements are pushed from the primary stack to the secondary stack, effectively pre-sorting the data in descending order.
- **Final sorting**: Once the elements are partitioned, each bucket is processed individually. A **selection sort** strategy (finding the highest value within the bucket) is applied to move the elements of each bucket back to the primary stack in their final, correct order.

#### Pseudo-code
```text

# Phase 0: Indexing

# Phase 1: Distribute elements into k buckets

FOR each bucket i from 0 to k - 1
    FOR each element in Stack A
        IF top of Stack A is within bucket i limits
            PUSH top of Stack A to Stack B
        ELSE
            ROTATE Stack A

# Stack B now contains elements grouped by bucket in descending order.
# Elements inside each bucket are unsorted.

# Phase 2: Rebuild sorted stack

WHILE Stack B is not empty
    Compute the index of the maximum element in Stack B 
    # Note: the maximum element is always part of the bucket
    # currently at the top of the stack.

    ROTATE Stack B using the shortest path (rb or rrb)
    PUSH top of Stack B to Stack A
```

#### Cost Breakdown
| Step | Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- | :--- |
| **1** | **Loop**: For each bucket $i$ from $0$ to $k - 1$ | $k$ | $k$ | $k$ |
| **1.1** | ROTATE $A$ and PUSH top of $A$ to $B$ if top of $A$ is within bucket $i$ limits $\left[ i \times \frac{n}{k}, (i + 1) \times \frac{n}{k} \right)$ | $\sum_{i=0}^{k - 1}{n - i \frac{n}{k}}$ (`ra` or `pb`) | $\sum_{i=0}^{k - 1}{n - i \frac{n}{k}}$ (`ra` or `pb`) | $\sum_{i=0}^{k - 1}{n - i \frac{n}{k}}$ (`ra` or `pb`) |
| **2** | **Loop :** While Stack $B$ is not empty | $n$  | $n$  | $n$ |
| **2.1** | Position max node on top of $B$ | $0$ | $k \cdot \sum_{i=1}^{\frac{n}{k}} \frac{i}{4}$ (`rb` or `rrb`) | $k \cdot \sum_{i=1}^{\frac{n}{k}} \frac{i}{2}$ (`rb` or `rrb`) |
| **2.2** | Push top of $B$ onto $A$ | $n$ (`pa`) | $n$ (`pa`) | $n$ (`pa`) |

#### Cost Analysis

##### Phase1: Bucket partitioning
The cost of positioning the insertion node is cumulative as stack $B$ is emptied. The cost is the same for all the cases as the algorithm assumes a random distribution of values within the stack and does not include any optimisation for sorted or nearly sorted stacks.

$$\text{Cost}_{P1} = \sum_{i=0}^{k - 1}{n - i \frac{n}{k}} = n \left( \frac{k - 1}{2} \right)$$

if $k$ is considered as function of n, this phase scales as $O(nk)$.

##### Phase2: Final sorting
For the **worst case** we assume that the number of rotations required to bring the maximum element to the top of the stack is equal to half of the current size of the bucket. The number of push is equal to the current size of stack $B$:

$$\text{Cost}_{P2} = n + k \cdot \sum_{i=1}^{\frac{n}{k}} \frac{i}{2} = \frac{1}{4k} n^2 + \frac{5}{4}n$$

$$
\text{Cost}_{P2} = n + k \cdot \sum_{i=1}^{\frac{n}{k}} \frac{i}{2} = \frac{1}{4k} n^2 + \frac{5}{4} n
$$
$$\frac{1}{2}$$
This results in a complexity of $O(n^2/k)$.


For the **average case** we assume that the number of rotations is halved. 
$$
\text{Cost}_{P2} = n + k \cdot \sum_{i=1}^{n/k} \frac{i}{2} = \frac{1}{8k} n^2 + \frac{9}{8} n
$$

This results in a complexity of $O(n^2/k)$.

For the **best case** we assume that the stack is already sorted in descending order, therefore no rotations are performed:

$$ \text{Cost}_{P2} = n = O(n) $$

#### Optimal Sizing of Buckets ($k$)

The total complexity $T(n, k)$ is the sum of both phases. We observe a clear trade-off:

* **Large Bucket ($k \to n$):** Phase 1 complexity increases toward $O(n2)$ as the number of buckets grows, increasing the number of rotations performed in Stack $A$, while Phase 2 decreases toward $O(n)$.
* **Small Bucket Count ($k \to 1$):** Phase 1 remains near $O(n)$, but Phase 2 complexity surges toward $O(n2)$ as the algorithm reverts to a standard insertion sort behavior on a single stack.

To find the optimal k, we balance the two dominant terms:

$$n \cdot k \approx \frac{n^2}{k} \implies k^2 \approx n \implies k = \sqrt{n}$$

### Conclusion
By setting the number of buckets to $\sqrt{n}$, the overall complexity for all cases (worst, average, and best) is optimized to $O(n\sqrt(n))$. While this does not reach the efficiency of $O(n \log n)$ algorithms, it represents a significant optimization over the $O(n2)$ baseline.

### Complex strategy: XXXXXXX

xxxxx


### Adaptative strategy: XXXXXX

xxxxx

## Resources
### Books
- Introduction to algorithms / Thomas H. Cormen, Charles E. Lierson, Ronald L. Rivest, Clifford Stein

### AI assistants
- Gemini 3 Flash: Assistance for redaction and formatting of `README.md`
