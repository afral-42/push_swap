<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- README.md                                          :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2026/01/07 17:44:30 by arebilla          #+#    #+#            -->
<!-- Updated: 2026/01/07 17:54:24 by arebilla         ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

### Insertion sort

#### Cost Breakdown
| Step | Operation | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- | :--- |
| **1** | Transfer Stack $A$ to Stack $B$ | $n$ | $n$ | $n$ |
| **2** | **Loop :** While Stack $B$ is not empty | ($n$)  | ($n$)  | ($n$) |
| **2.1** | Position insertion node on top of $A$ | $0$ | $\sum_{k=1}^{n} \frac{k}{4}$ | $\sum_{k=1}^{n} \frac{k}{2}$ |
| **2.2** | Push top of $B$ onto $A$ | $n$ | $n$ | $n$ |
| **3** | Finalize: Move smallest node to top | $0$ | $\frac{n}{4}$ | $\frac{n}{2}$ |

---
#### Cost Analysis

#### 1. Position Insertion (Step 2.1)
The cost of positioning the insertion node is cumulative as stack $B$ is emptied. In the worst case, the complexity follows the arithmetic series:

$$\text{Cost}_{2.1} = \sum_{k=1}^{n} \frac{k}{2} = \frac{1}{2} \left( \frac{n(n+1)}{2} \right) = \frac{n^2 + n}{4}$$

For the average case, we assume the distance to the correct position is halved:

$$\text{Cost}_{2.1} = \sum_{k=1}^{n} \frac{k}{4} = \frac{1}{4} \left( \frac{n(n+1)}{2} \right) = \frac{n^2 + n}{8}$$

#### 2. Total Complexity
Given the quadratic nature of the summation in Step 2.1, the overall time complexity of the algorithm is:

* **Worst Case:** $O(n^2)$
* **Average Case:** $O(n^2)$
* **Best Case:** $O(n)$ (When the stacks is already sorted)
