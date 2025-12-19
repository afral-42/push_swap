#### Insertion sort


$$\begin{array}{r l}
1. & \textbf{while } A.\text{size} > 0 \\
2. & \quad rotation\_count \gets 0 \\
3. & \quad \textbf{while } A.\text{top} > B.\text{top} \\
4. & \quad\quad \text{rotate}(B) \\
5. & \quad\quad rotation\_count \gets rotation\_count + 1 \\
6. & \quad \textbf{end while} \\
7. & \quad \text{push}(A) \\
8. & \quad \textbf{while } rotation\_count > 0 \\
9. & \quad\quad \text{rotate}(B) \\
10. & \quad\quad rotation\_count \gets rotation\_count - 1 \\
11. & \quad \textbf{end while} \\
12. & \textbf{end while} \\
   & \\
13. & \textbf{while } B.\text{size} > 0 \\
14. & \quad \text{push}(A) \\
15. & \textbf{end while}
\end{array}$$

End.
